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

#include "nesting/ieee8021q/relay/ForwardingRelayUnit.h"

#include "inet/common/IProtocolRegistrationListener.h"
#include "inet/linklayer/ethernet/EtherFrame_m.h"
#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/common/InterfaceTag_m.h"
#include "inet/linklayer/vlan/VlanTag_m.h"

#include <sstream>

namespace nesting {

Define_Module(ForwardingRelayUnit);

void ForwardingRelayUnit::initialize(int stage) {
    if (stage == INITSTAGE_LOCAL) {
        fdb = getModuleFromPar<FilteringDatabase>(par("filteringDatabaseModule"), this);
        ifTable = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);
        numberOfPorts = par("numberOfPorts");
    } else if (stage == INITSTAGE_LINK_LAYER) {
        registerService(Protocol::ethernetMac, nullptr, gate("ifIn"));
        registerProtocol(Protocol::ethernetMac, gate("ifOut"), nullptr);
    }
}

void ForwardingRelayUnit::handleMessage(cMessage *msg) {
    Packet* packet = check_and_cast<Packet*>(msg);
    const auto& frame = packet->peekAtFront<EthernetMacHeader>();
    int arrivalInterfaceId = packet->getTag<InterfaceInd>()->getInterfaceId();

    // Remove old service indications but keep packet protocol tag and add VLAN request
    auto oldPacketProtocolTag = packet->removeTag<PacketProtocolTag>();
    auto vlanInd = packet->removeTag<VlanInd>();
    packet->clearTags();
    auto newPacketProtocolTag = packet->addTag<PacketProtocolTag>();
    *newPacketProtocolTag = *oldPacketProtocolTag;
    auto vlanReq = packet->addTag<VlanReq>();
    vlanReq->setVlanId(vlanInd->getVlanId());
    delete oldPacketProtocolTag;

    packet->trim();

    // Distinguish between broadcast-, multicast- and unicast-ethernet frames
    if (frame->getDest().isBroadcast()) {
        processBroadcast(packet, arrivalInterfaceId);
    } else if (frame->getDest().isMulticast()) {
        processMulticast(packet, arrivalInterfaceId);
    } else {
        processUnicast(packet, arrivalInterfaceId);
    }
}

void ForwardingRelayUnit::processBroadcast(Packet* packet, int arrivalInterfaceId) {
    EV_INFO << "Broadcasting packet " << packet->getName() << std::endl;
    for (int interfacePos = 0; interfacePos < ifTable->getNumInterfaces(); interfacePos++) {
        InterfaceEntry* destInterface = ifTable->getInterface(interfacePos);
        int destInterfaceId = destInterface->getInterfaceId();
        if (destInterfaceId != arrivalInterfaceId && !fdb->isInterfaceBlocked(destInterfaceId)) {
            Packet* dupPacket = packet->dup();
            dupPacket->addTagIfAbsent<InterfaceReq>()->setInterfaceId(destInterfaceId);
            send(dupPacket, gate("ifOut"));
        }
    }
    delete packet;
}

void ForwardingRelayUnit::processMulticast(Packet* packet, int arrivalInterfaceId) {
    const auto& frame = packet->peekAtFront<EthernetMacHeader>();
    std::vector<int> destInterfaces = fdb->getDestInterfaceIds(frame->getDest(), simTime());

    if (destInterfaces.size() == 0) {
        EV_INFO << "No configured multicast forwarding entry found for packet "
                << packet->getName() << ". Falling back to broadcast!" << std::endl;
        processBroadcast(packet, arrivalInterfaceId);
    } else {
        std::ostringstream strBuffer;
        for (int interfaceIndex = 0; interfaceIndex < destInterfaces.size(); interfaceIndex++) {
            int destInterfaceId = destInterfaces[interfaceIndex];
            if (destInterfaceId != arrivalInterfaceId) {
                Packet* dupPacket = packet->dup();
                dupPacket->addTagIfAbsent<InterfaceReq>()->setInterfaceId(destInterfaceId);
                send(dupPacket, gate("ifOut"));
                if (interfaceIndex < destInterfaces.size() - 1) {
                    strBuffer << destInterfaceId << ", ";
                } else {
                    strBuffer << destInterfaceId;
                }
            }
        }
        EV_INFO << "Forwarding multicast packet " << packet->getName()
                << " to interfaces [" << strBuffer.str() << "]" << std::endl;
        delete packet;
    }
}

void ForwardingRelayUnit::processUnicast(Packet* packet, int arrivalInterfaceId) {
    //Learning MAC port mappings
    const auto& frame = packet->peekAtFront<EthernetMacHeader>();
    learn(frame->getSrc(), arrivalInterfaceId);
    int destInterfaceId = fdb->getDestInterfaceId(frame->getDest(), simTime());

    //Routing entry available or not?
    if (destInterfaceId == -1) {
        EV_INFO << "No unicast forwarding entry for packet " << packet->getName()
                << " found. Falling back to broadcast!" << std::endl;
        processBroadcast(packet, arrivalInterfaceId);
    } else {
        EV_INFO << "Forwarding unicast packet " << packet->getName()
                << " to interface " << destInterfaceId << std::endl;
        packet->addTagIfAbsent<InterfaceReq>()->setInterfaceId(destInterfaceId);
        send(packet, gate("ifOut"));
    }
}

void ForwardingRelayUnit::learn(MacAddress srcAddr, int arrivalInterfaceId)
{
    fdb->insert(srcAddr, simTime(), arrivalInterfaceId);
}

} // namespace nesting
