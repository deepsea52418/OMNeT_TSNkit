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

#ifndef NESTING_COMMON_TIME_LEGACYCLOCK_H_
#define NESTING_COMMON_TIME_LEGACYCLOCK_H_

#include <omnetpp.h>

#include <map>
#include <unordered_set>

#include "inet/common/ModuleAccess.h"

#include "nesting/common/time/IClock.h"
#include "nesting/common/time/IdealOscillator.h"

using namespace omnetpp;
using namespace inet;

namespace nesting {

/**
 * See the NED file for a detailed description
 * 
 * @deprecated Use nesting::RealtimeClock instead
 */
class LegacyClock: public cSimpleModule, public IClock, public IOscillator::TickListener {
protected:
    IdealOscillator* oscillator;

    uint64_t lastTick;

    simtime_t time;

    std::map<std::shared_ptr<const IOscillator::Tick>, std::unordered_set<IClockListener*>> tickToListenerTable;
protected:
    virtual void initialize() override;
public:
    LegacyClock();

    virtual ~LegacyClock() {};

    virtual simtime_t getTime() override;

    virtual simtime_t getClockRate() override;

    virtual void subscribeTick(IClockListener* listener, unsigned idleTicks, short kind = 0) override;

    virtual void unsubscribeTicks(IClockListener* listener) override;

    virtual void onTick(IOscillator& oscillator, std::shared_ptr<const IOscillator::Tick> tick) override;
};

} // namespace nesting

#endif
