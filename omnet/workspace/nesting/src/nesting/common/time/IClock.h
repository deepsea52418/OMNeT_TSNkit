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

#ifndef NESTING_COMMON_TIME_ICLOCK_H_
#define NESTING_COMMON_TIME_ICLOCK_H_

#include <omnetpp.h>

#include "nesting/common/time/IClockListener.h"

using namespace omnetpp;

namespace nesting {

class IClockListener;

/**
 * This class implements an abstract interface for a clock holding a local time
 * value. The time can be read or time changes can be subscribed.
 *
 * @see IClockListener
 * @deprecated Use the nesting::IClock2 module instead
 */
class IClock {
public:
    virtual ~IClock() {};

    /** Returns the clock's local time. */
    virtual simtime_t getTime() = 0;

    /** Return clockrate as a simtime object. */
    virtual simtime_t getClockRate() = 0;

    /**
     * Subscribe clock event. Calling this method is idempotent for the same
     * kind value.
     */
    virtual void subscribeTick(IClockListener* listener, unsigned idleTicks, short kind = 0) = 0;

    virtual void unsubscribeTicks(IClockListener* listener) = 0;
};

} // namespace nesting

#endif /* NESTING_COMMON_TIME_ICLOCK_H_ */
