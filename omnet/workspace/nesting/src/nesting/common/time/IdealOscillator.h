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

#ifndef NESTING_COMMON_TIME_IDEALOSCILLATOR_H_
#define NESTING_COMMON_TIME_IDEALOSCILLATOR_H_

#include <omnetpp.h>

#include "nesting/common/time/OscillatorBase.h"

namespace nesting {

class IdealOscillator : public OscillatorBase {
    virtual simtime_t globalTimeFromTick(uint64_t idleTicks) override;
    virtual uint64_t tickFromGlobalTime(simtime_t globalTime) override;
};

} // namespace nesting

#endif
