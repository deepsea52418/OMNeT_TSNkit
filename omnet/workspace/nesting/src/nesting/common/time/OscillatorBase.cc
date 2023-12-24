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

#include "nesting/common/time/OscillatorBase.h"

#include <algorithm>
#include <cmath>

namespace nesting {

OscillatorBase::OscillatorBase()
    : frequency(1.0)
    , lastTick(0)
    , timeOfLastTick(SimTime::ZERO)
    , tickEventNow(false)
    , tickMessage(cMessage("TickMessage"))
{
}

OscillatorBase::~OscillatorBase()
{
    cancelEvent(&tickMessage);
}

void OscillatorBase::initialize()
{
    frequency = par("frequency").doubleValue();
    if (frequency < 0) {
        throw cRuntimeError("Frequency parameter must be positive.");
    } else if (frequency == 0) {
        throw cRuntimeError("Frequency parameter must not be zero.");
    }

    WATCH(frequency);
    WATCH(lastTick);
    WATCH(timeOfLastTick);
    WATCH_LIST(scheduledEvents);
}

void OscillatorBase::finish()
{
}

void OscillatorBase::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        tickEventNow = true;

        // Invariant: There has to be at least one event to be scheduled now.
        // Otherwise the self-message shouldn't exist.
        assert(!scheduledEvents.empty());

        std::shared_ptr<OscillatorBase::TickImpl> tickEvent = scheduledEvents.front();
        scheduledEvents.pop_front();

        // Invariant: Monotonic increasing tick count
        assert(lastTick <= tickEvent->getTick());
        assert(timeOfLastTick <= simTime());

        // Update last tick
        if (lastTick < tickEvent->getTick()) {
            timeOfLastTick = simTime();
            lastTick = tickEvent->getTick();
        }

        // Notify listener
        tickEvent->getListener().onTick(*this, tickEvent);

        scheduleNextTick();

        tickEventNow = false;
    }
}

simtime_t OscillatorBase::tickInterval() const
{
    return SimTime(1, SIMTIME_S) / frequency;
}

void OscillatorBase::scheduleNextTick() {
    // Cancel current self message
    if (tickMessage.isScheduled()) {
        cancelEvent(&tickMessage);
    }

    // We only have to schedule the next tick if there exists a future event.
    if (!scheduledEvents.empty()) {
        std::shared_ptr<OscillatorBase::TickImpl>& nextTickEvent = scheduledEvents.front();

        uint64_t currentTick = updateAndGetTickCount();
        uint64_t nextScheduledTick = nextTickEvent->getTick();

        // Monotonic increasing ticks
        assert(nextScheduledTick >= currentTick);

        scheduleAt(nextTickEvent->getGlobalSchedulingTime(), &tickMessage);
    }
}

uint64_t OscillatorBase::updateAndGetTickCount()
{
    Enter_Method_Silent();

    uint64_t currentTick = tickFromGlobalTime(simTime());
    if (lastTick != currentTick) {
        assert(tickFromGlobalTime(globalTimeFromTick(currentTick)) == currentTick);
        uint64_t elapsedTicks = currentTick - lastTick;
        timeOfLastTick = globalTimeFromTick(currentTick);
        lastTick = currentTick;
    }

    // Postcondition: Monotonic increasing tick count
    assert(currentTick >= lastTick);

    return currentTick;
}

std::shared_ptr<const IOscillator::Tick> OscillatorBase::subscribeTick(IOscillator::TickListener& listener, uint64_t idleTicks, uint64_t kind)
{
    Enter_Method_Silent();

    // Calculate current tick count
    uint64_t currentTick = updateAndGetTickCount();

    // Create new tick event.
    uint64_t tick = currentTick + idleTicks;
    std::shared_ptr<OscillatorBase::TickImpl> tickEvent = std::make_shared<OscillatorBase::TickImpl>(
            listener,
            tick,
            kind,
            globalTimeFromTick(tick));

    // Find insert position of tick event with binary search.
    auto it = std::lower_bound(
            scheduledEvents.begin(),
            scheduledEvents.end(),
            tickEvent);

    // Insert tick event in event queue.
    if (it == scheduledEvents.end() || **it != *tickEvent) {
        scheduledEvents.insert(it, tickEvent);
    } else {
        tickEvent = *it;
    }

    scheduleNextTick();

    return tickEvent;
}

std::shared_ptr<const IOscillator::Tick> OscillatorBase::subscribeTick(IOscillator::TickListener& listener, uint64_t idleTicks)
{
    Enter_Method_Silent();
    return subscribeTick(listener, idleTicks, 0);
}

void OscillatorBase::unsubscribeTick(IOscillator::TickListener& listener, const IOscillator::Tick& tick)
{
    Enter_Method_Silent();

    std::shared_ptr<OscillatorBase::TickImpl> tickEvent = std::make_shared<OscillatorBase::TickImpl>(
        listener, 
        tick.getTick(), 
        tick.getKind(), 
        SimTime::ZERO);

    // Find tick event
    auto it = std::lower_bound(
            scheduledEvents.begin(),
            scheduledEvents.end(),
            tickEvent);

    // Remove tick event if it's present within the event queue
    if (it != scheduledEvents.end() && **it == *tickEvent) {
        scheduledEvents.erase(it);
    }

    scheduleNextTick();
}

void OscillatorBase::unsubscribeTicks(IOscillator::TickListener& listener, uint64_t kind)
{
    Enter_Method_Silent();
    auto removeCondition = [&](std::shared_ptr<OscillatorBase::TickImpl> tickEvent) {
        return &(tickEvent->getListener()) == &listener
                && tickEvent->getKind() == kind;
    };
    scheduledEvents.erase(
            std::remove_if(scheduledEvents.begin(), scheduledEvents.end(), removeCondition), 
            scheduledEvents.end());
    scheduleNextTick();
}

void OscillatorBase::unsubscribeTicks(IOscillator::TickListener& listener)
{
    Enter_Method_Silent();
    auto removeCondition = [&](std::shared_ptr<OscillatorBase::TickImpl> tickEvent) {
        return &(tickEvent->getListener()) == &listener;
    };
    scheduledEvents.erase(
            std::remove_if(scheduledEvents.begin(), scheduledEvents.end(), removeCondition), 
            scheduledEvents.end());
    scheduleNextTick();
}

bool OscillatorBase::isTickScheduled(IOscillator::TickListener& listener, const IOscillator::Tick& tickEvent) const
{
    Enter_Method_Silent();
    std::shared_ptr<OscillatorBase::TickImpl> tick = std::make_shared<OscillatorBase::TickImpl>(listener, tickEvent);
    auto it = std::lower_bound(
            scheduledEvents.begin(),
            scheduledEvents.end(),
            tick);
    return it != scheduledEvents.end() && **it == *tick;
}

double OscillatorBase::getFrequency() const
{
    Enter_Method_Silent();
    return frequency;
}

void OscillatorBase::setFrequency(double newFrequency)
{
    Enter_Method_Silent();
    
    // Update frequency
    double oldFrequency = this->frequency;
    this->frequency = newFrequency;

    // Update tick count
    updateAndGetTickCount();

    // Update scheduling times for each tick
    for (std::shared_ptr<OscillatorBase::TickImpl> tickEvent : scheduledEvents) {
        simtime_t updatedSchedulingTime = globalTimeFromTick(tickEvent->getTick());
        tickEvent->setGlobalSchedulingTime(updatedSchedulingTime);
    }

    // Reschedule next tick
    scheduleNextTick();

    // Notify config subscribers
    for (IOscillator::ConfigListener* listener : configListeners) {
        listener->onFrequencyChange(*this, oldFrequency, newFrequency);
    }
}

void OscillatorBase::subscribeConfigChanges(IOscillator::ConfigListener& listener)
{
    Enter_Method_Silent();
    configListeners.insert(&listener);
}

void OscillatorBase::unsubscribeConfigChanges(IOscillator::ConfigListener& listener)
{
    Enter_Method_Silent();
    configListeners.erase(&listener);
}

OscillatorBase::TickImpl::TickImpl(IOscillator::TickListener& listener, uint64_t tick, uint64_t kind, simtime_t globalSchedulingTime)
    : listener(listener)
    , tick(tick)
    , kind(kind)
    , globalSchedulingTime(globalSchedulingTime)
{
}

OscillatorBase::TickImpl::TickImpl(IOscillator::TickListener& listener, const IOscillator::Tick& tickEvent)
    : listener(listener)
    , tick(tickEvent.getTick())
    , kind(tickEvent.getKind())
    , globalSchedulingTime(tickEvent.getGlobalSchedulingTime())
{
}

OscillatorBase::TickImpl::~TickImpl()
{
}

IOscillator::TickListener& OscillatorBase::TickImpl::getListener() const
{
    return listener;
}

void OscillatorBase::TickImpl::setListener(IOscillator::TickListener& listener)
{
    this->listener = listener;
}

uint64_t OscillatorBase::TickImpl::getTick() const
{
    return tick;
}

void OscillatorBase::TickImpl::setTick(uint64_t tick)
{
    this->tick = tick;
}

uint64_t OscillatorBase::TickImpl::getKind() const
{
    return kind;
}

void OscillatorBase::TickImpl::setKind(uint64_t kind)
{
    this->kind = kind;
}

simtime_t OscillatorBase::TickImpl::getGlobalSchedulingTime() const
{
    return globalSchedulingTime;
}

void OscillatorBase::TickImpl::setGlobalSchedulingTime(simtime_t globalSchedulingTime)
{
    this->globalSchedulingTime = globalSchedulingTime;
}

bool OscillatorBase::TickImpl::operator<(const OscillatorBase::TickImpl& tickEvent) const
{
    if (this->tick < tickEvent.getTick()) {
        return true;
    } else if (this->tick == tickEvent.getTick()) {
        if (this->kind < tickEvent.getKind()) {
            return true;
        } else if (this->kind == tickEvent.getKind()) {
            return &(this->listener) < &(tickEvent.getListener());
        }
    }
    return false;
}

bool OscillatorBase::TickImpl::operator==(const OscillatorBase::TickImpl& tickEvent) const
{
    return &(this->listener) == &(tickEvent.listener)
            && this->tick == tickEvent.tick
            && this->kind == tickEvent.kind;
}

bool OscillatorBase::TickImpl::operator!=(const OscillatorBase::TickImpl& tickEvent) const
{
    return !(*this == tickEvent);
}

std::ostream& operator<<(std::ostream& stream, const OscillatorBase::TickImpl* tickEvent)
{
    stream << "TickEvent[tick=\"" << tickEvent->getTick()
            << "\",kind=\"" << tickEvent->getKind()
            << "\",listener=\"" << &(tickEvent->getListener()) << "\"]";
    return stream;
}

bool operator<(std::shared_ptr<OscillatorBase::TickImpl> left, std::shared_ptr<OscillatorBase::TickImpl> right)
{
    return *left < *right;
}

} //namespace
