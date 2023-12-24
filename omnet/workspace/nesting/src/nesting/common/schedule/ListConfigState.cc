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

#include "nesting/common/schedule/ListConfigState.h"

namespace nesting {

std::ostream& operator<<(std::ostream& os, const ListConfigState& lcs)
{
    switch (lcs) {
    case ListConfigState::UNDEFINED:
        return os << "UNDEFINED";
    case ListConfigState::CONFIG_PENDING:
        return os << "CONFIG_PENDING";
    case ListConfigState::UPDATE_CONFIG:
        return os << "UPDATE_CONFIG";
    case ListConfigState::CONFIG_IDLE:
        return os << "CONFIG_IDLE";
    default:
        return os << "?";
    }
}

} // namespace nesting
