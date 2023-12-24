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

#include "nesting/common/ResultFilters.h"
#include "nesting/common/FlowMetaTag_m.h"

#include "inet/common/packet/Packet.h"

using namespace inet;

namespace nesting {

Register_ResultFilter("flowId", FlowIdFilter);

void FlowIdFilter::receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details)
{
    if (auto packet = dynamic_cast<Packet*>(object)) {
        for (auto& region : packet->peekData()->getAllTags<FlowMetaTag>()) {
            fire(this, t, static_cast<unsigned long>(region.getTag()->getFlowId()), details);
        }
    }
}

Register_ResultFilter("seqNum", SeqNumFilter);

void SeqNumFilter::receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details)
{
    if (auto packet = dynamic_cast<Packet*>(object)) {
        for (auto& region : packet->peekData()->getAllTags<FlowMetaTag>()) {
            fire(this, t, static_cast<unsigned long>(region.getTag()->getSeqNum()), details);
        }
    }
}

} // namespace nesting
