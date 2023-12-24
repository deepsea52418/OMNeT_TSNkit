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

#include "nesting/common/schedule/ListExecuteState.h"

namespace nesting {

std::ostream& operator<<(std::ostream& os, const ListExecuteState& les)
{
    switch(les) {
    case ListExecuteState::UNDEFINED:
        return os << "UNDEFINED";
    case ListExecuteState::NEW_CYCLE:
        return os << "NEW_CYCLE";
    case ListExecuteState::INIT:
        return os << "INIT";
    case ListExecuteState::EXECUTE_CYCLE:
        return os << "EXECUTE_CYCLE";
    case ListExecuteState::DELAY:
        return os << "DELAY";
    case ListExecuteState::END_OF_CYCLE:
        return os << "END_OF_CYCLE";
    default:
        return os << "?";
    }
}

} // namespace nesting
