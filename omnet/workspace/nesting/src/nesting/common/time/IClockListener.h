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

#ifndef NESTING_COMMON_TIME_ICLOCKLISTENER_H_
#define NESTING_COMMON_TIME_ICLOCKLISTENER_H_

#include "nesting/common/time/IClock.h"

namespace nesting {

class IClock;

/**
 * This class is an interface providing method stubs to allow subscribing clock
 * ticks by the the IClockInterface.
 *
 * @see IClock
 * @deprecated Use the nesting::IClock2 and nesting::IClock2Listener interfaces instead
 */
class IClockListener {
public:
    virtual ~IClockListener() {}

    /** Notifies a listener about a subscribed clock tick. */
    virtual void tick(IClock *clock, short kind) = 0;
};

} // namespace nesting

#endif /* NESTING_COMMON_TIME_ICLOCKLISTENER_H_ */
