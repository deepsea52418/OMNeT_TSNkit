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

#include "nesting/common/time/LegacyClock.h"

namespace nesting {

Define_Module(LegacyClock);

LegacyClock::LegacyClock()
    : oscillator(nullptr)
    , lastTick(0)
    , time(SimTime::ZERO)
{
}

void LegacyClock::initialize()
{
    oscillator = getModuleFromPar<IdealOscillator>(par("oscillatorModule"), this);
}

simtime_t LegacyClock::getTime()
{
    Enter_Method_Silent();
    uint64_t idleTicks = oscillator->updateAndGetTickCount() - lastTick;
    time += idleTicks * getClockRate();
    lastTick += idleTicks;
    return time;
}

simtime_t LegacyClock::getClockRate()
{
    Enter_Method_Silent();
    return SimTime(1, SIMTIME_S) / oscillator->getFrequency();
}

void LegacyClock::subscribeTick(IClockListener* listener, unsigned idleTicks, short kind)
{
    Enter_Method_Silent();
    auto tick = oscillator->subscribeTick(*this, idleTicks, kind);
    if (tickToListenerTable.find(tick) == tickToListenerTable.end()) {
        tickToListenerTable[tick] = std::unordered_set<IClockListener*>();
    }
    tickToListenerTable[tick].insert(listener);
}

void LegacyClock::unsubscribeTicks(IClockListener* listener)
{
    Enter_Method_Silent();
    for (auto it = tickToListenerTable.begin(); it != tickToListenerTable.end(); it++) {
        if (it->second.find(listener) != it->second.end()) {
            it->second.erase(listener);
            oscillator->unsubscribeTick(*this, *(it->first));
        }
    }
}

void LegacyClock::onTick(IOscillator& oscillator, std::shared_ptr<const IOscillator::Tick> tick)
{
    Enter_Method("tick");
    auto listeners = tickToListenerTable[tick];
    for (IClockListener* listener : listeners) {
        listener->tick(this, tick->getKind());
    }
    tickToListenerTable.erase(tick);
}

} // namespace nesting
