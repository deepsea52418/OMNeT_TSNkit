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

#include "nesting/ieee8021q/queue/transmissionSelectionAlgorithms/StrictPriority.h"

namespace nesting {

Define_Module(StrictPriority);

void StrictPriority::refreshDisplay() const {
    char buf[80];
    sprintf(buf, "strict-priority");
    getDisplayString().setTagArg("t", 0, buf);
}

} // namespace nesting
