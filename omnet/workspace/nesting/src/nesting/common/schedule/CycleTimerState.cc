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

#include "nesting/common/schedule/CycleTimerState.h"

namespace nesting {

std::ostream& operator<<(std::ostream& os, const CycleTimerState& cts)
{
    switch (cts) {
    case CycleTimerState::UNDEFINED:
        return os << "UNDEFINED";
    case CycleTimerState::CYCLE_IDLE:
        return os << "CYCLE_IDLE";
    case CycleTimerState::SET_CYCLE_START_TIME:
        return os << "SET_CYCLE_START_TIME";
    case CycleTimerState::START_CYCLE:
        return os << "START_CYCLE";
    default:
        return os << "?";
    }
}

} // namespace nesting
