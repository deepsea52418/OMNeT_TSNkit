//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "nesting/common/schedule/GateScheduleManager.h"
#include "nesting/common/schedule/ScheduleFactory.h"

namespace nesting {

Define_Module(GateScheduleManager);

GateScheduleManager::GateScheduleManager() {}

const GateBitvector GateScheduleManager::initialAdminState() const
{
    return GateBitvector(par("initialAdminGateStates").stringValue());
}

std::unique_ptr<Schedule<GateBitvector>> GateScheduleManager::initialAdminSchedule() const
{
    cXMLElement* xml = par("initialAdminSchedule");
    Schedule<GateBitvector>* scheduleRawPtr = ScheduleFactory::createGateSchedule(xml);
    std::unique_ptr<Schedule<GateBitvector>> schedule(scheduleRawPtr);
    schedule->normalize();
    return schedule;
}

void GateScheduleManager::setAdminSchedule(std::unique_ptr<Schedule<GateBitvector>> adminSchedule)
{
    // Schedules with no entries don't make sense.
    if (adminSchedule->getControlListLength() == 0) {
        EV_WARN << "Loading a schedule with controlListLenth of 0." << std::endl;
    }
    adminSchedule->normalize();
    ScheduleManager<GateBitvector>::setAdminSchedule(std::move(adminSchedule));
}

simtime_t GateScheduleManager::nextGateCloseEventInSchedule(uint64_t gateIndex, uint64_t listPointerStart,
        const Schedule<GateBitvector>& schedule) const
{
    // Precondition
    assert(schedule.isNormalized());
    assert(gateIndex >= 0 && gateIndex < 8);

    uint64_t controlListLength = schedule.getControlListLength();
    uint64_t cycleTime = schedule.getControlListLength();
    simtime_t sumTimeIntervals = schedule.getSumTimeIntervals();
    
    // Special case: Control list is empty.
    if (controlListLength == 0) {
        return SimTime::getMaxTime();
    }

    // Count gate open intervals.
    simtime_t timeUntilGateCloseEvent = SimTime::ZERO;
    bool wraparound = true;
    for (uint64_t listPointerOffset = 0; listPointerOffset < controlListLength; listPointerOffset++) {
        uint64_t listPointer = (listPointerStart + listPointerOffset) % controlListLength;
        GateBitvector gateBitvector = schedule.getScheduledObject(listPointer);
        simtime_t timeInterval = schedule.getTimeInterval(listPointer);
        if (gateBitvector.test(gateIndex)) {
            timeUntilGateCloseEvent += timeInterval;
        } else {
            wraparound = false;
            break;
        }
    }

    // Special case: Gate is opened in all GateVectors (wraparound) => gate is opened indefinitely.
    if (wraparound) {
        return SimTime::getMaxTime();
    }

    // Return aggregated gate open intervals
    return timeUntilGateCloseEvent;
}

simtime_t GateScheduleManager::nextGateCloseEvent(uint64_t gateIndex) const
{
    // Preconditions
    assert(gateIndex >= 0 && gateIndex < 8);
    assert(operSchedule->isNormalized());

    const simtime_t currentTime = clock->updateAndGetLocalTime();
    const uint64_t operControlListLength = operSchedule->getControlListLength();

    // If gating is disabled we only have to check the current operState and
    // neither the operSchedule or adminSchedule.
    if (!enabled) {
        return operState.test(gateIndex) ? SimTime::getMaxTime() : SimTime::ZERO;
    }

    simtime_t timeUntilGateCloseEvent = SimTime::ZERO;
    uint64_t lookaheadListPointer;

    // To determine how long the current operGateStates (operState) is valid we
    // have to consider the state of the ListExecute state machine.
    if (!operState.test(gateIndex)) {
        return SimTime::ZERO;
    } else {
        if (listExecuteState == ListExecuteState::INIT || listExecuteState == ListExecuteState::END_OF_CYCLE) {
            assert(cycleStartTime >= currentTime); // TODO: Is this always the case?
            timeUntilGateCloseEvent += cycleStartTime - currentTime;
            lookaheadListPointer = 0;
        } else if (listExecuteState == ListExecuteState::NEW_CYCLE) {
            lookaheadListPointer = 0;
        } else if (listExecuteState == ListExecuteState::EXECUTE_CYCLE) {
            assert(listPointer < operControlListLength);
            lookaheadListPointer = listPointer;
        } else if (listExecuteState == ListExecuteState::DELAY) {
            simtime_t timeOfNextExecuteCycleEvent = nextListExecuteTimestamp->getLocalTime();
            assert(timeOfNextExecuteCycleEvent >= currentTime);
            simtime_t remainingTimeInterval = timeOfNextExecuteCycleEvent - currentTime;
            timeUntilGateCloseEvent += remainingTimeInterval;
            lookaheadListPointer = listPointer % operControlListLength;
        } else {
            throw cRuntimeError("ListExecute state machine is in invalid state!");
        }
    }
    
    // After we evaluated the current operGateStates (operState), we have to
    // look at the future operGateStates by examining the operSchedule and
    // adminSchedule.
    if (!configPending) {
        simtime_t gateOpeningTime = nextGateCloseEventInSchedule(gateIndex, lookaheadListPointer, *operSchedule);
        // We can't just add the time because we have prevent overflows
        if (gateOpeningTime == SimTime::getMaxTime()) {
            timeUntilGateCloseEvent = SimTime::getMaxTime();
        } else {
            timeUntilGateCloseEvent += gateOpeningTime;
        }
    } else {
        // TODO: Implement lookahead in combination with schedule swaps. This
        // requires a deeper understanding of operCycleTimeExtension.
        throw cRuntimeError("Length-aware scheduling not implemented yet in combination with schedule swaps!");
    }

    return timeUntilGateCloseEvent;
}

} // namespace nesting
