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

#include "VlanRequester.h"

#include "inet/common/packet/Packet.h"
#include "nesting/linklayer/vlan/EnhancedVlanTag_m.h"

namespace nesting {

Define_Module(VlanRequester);

void VlanRequester::initialize()
{
    pcp = par("pcp");
}

void VlanRequester::handleMessage(cMessage *msg)
{
    if(msg->arrivedOn("upperLayerIn")) {
        if(msg->isPacket()) {
            inet::Packet *packet = check_and_cast<inet::Packet*>(msg);
            auto tag = packet->addTag<EnhancedVlanReq>();
            tag->setPcp(pcp);
            std::cout << "tag->setPcp(" << pcp << ")" << std::endl;
        }
        send(msg, "lowerLayerOut");
    } else {
        send(msg, "upperLayerOut");
    }
}

} //namespace
