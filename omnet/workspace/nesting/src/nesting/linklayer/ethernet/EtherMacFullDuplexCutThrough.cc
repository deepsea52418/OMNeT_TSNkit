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

#include "nesting/linklayer/ethernet/EtherMacFullDuplexCutThrough.h"

#include "inet/common/Simsignals.h"
#include "inet/linklayer/ethernet/EtherPhyFrame_m.h"
#include "inet/linklayer/ethernet/EtherEncap.h"
#include "inet/linklayer/common/InterfaceTag_m.h"
#include "inet/networklayer/common/InterfaceEntry.h"

#include <iostream>

namespace nesting {

Define_Module(EtherMacFullDuplexCutThrough);

void EtherMacFullDuplexCutThrough::initialize(int stage)
{
    if (stage == INITSTAGE_LOCAL) {
        cutThroughEnabled = par("cutThrough");
        getSimulation()->getSystemModule()->subscribe(packetReceivedFromUpperSignal, this);
        getSimulation()->getSystemModule()->subscribe(packetSentToLowerSignal, this);
    }

    EtherMacFullDuplex::initialize(stage);
}

void EtherMacFullDuplexCutThrough::processReceivedDataFrame(Packet* packet, const Ptr<const EthernetMacHeader>& frame)
{
    if (cutThroughEnabled) {
        // statistics
        unsigned long curBytes = packet->getByteLength();
        numFramesReceivedOK++;
        numBytesReceivedOK += curBytes;
        emit(rxPkOkSignal, packet);

        // We probably don't need these tags, but someone might need them for statistics.
        packet->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(&Protocol::ethernetMac);
        packet->addTagIfAbsent<PacketProtocolTag>()->setProtocol(&Protocol::ethernetMac);
        if (interfaceEntry)
            packet->addTagIfAbsent<InterfaceInd>()->setInterfaceId(interfaceEntry->getInterfaceId());

        numFramesPassedToHL++;
        emit(packetSentToUpperSignal, packet);

        // Don't pass to higher layers, just delete packet if cut through switching is enabled.
        EV_INFO << "Completely received packet " << packet << ".\n";
        delete packet;
    } else {
        EtherMacFullDuplex::processReceivedDataFrame(packet, frame);
    }
}

void EtherMacFullDuplexCutThrough::receiveSignal(cComponent *source,
        simsignal_t signalId, cObject *obj, cObject *details)
{
    Enter_Method_Silent();

    if (cutThroughEnabled) {
        // Identify previous/connected MAC module.
        cModule* prevMacModule;
        {
            cGate* startGate = physInGate->getPathStartGate();
            cGate* endGate = physInGate->getPathEndGate();
            cGate* foreignPhysGate = (startGate == physInGate ? endGate : startGate);
            prevMacModule = foreignPhysGate->getOwnerModule();
        }

        // We are only interested in signals from the connected MAC module.
        if (source == prevMacModule) {
            // Determine propagation delay and packet in transmission
            cDatarateChannel* inputChannel = check_and_cast<cDatarateChannel*>(physInGate->findIncomingTransmissionChannel());
            simtime_t propagationDelay = inputChannel->getDelay();
            Packet* packetInTransmission = check_and_cast<Packet*>(obj);

            // Previous MAC started transmitted frame.
            if (signalId == packetReceivedFromUpperSignal) {
                Packet* packet = packetInTransmission->dup();

                // Add tags needed for further processing
                packet->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(&Protocol::ethernetMac);
                packet->addTagIfAbsent<PacketProtocolTag>()->setProtocol(&Protocol::ethernetMac);
                if (interfaceEntry)
                    packet->addTagIfAbsent<InterfaceInd>()->setInterfaceId(interfaceEntry->getInterfaceId());

                EV_INFO << "Sending " << packet << " to upper layer.\n";
                sendDelayed(packet, propagationDelay, "upperLayerOut");
            }
            // Previous MAC stopped transmitting frame.
            else if (signalId == packetSentToLowerSignal) {
                // TODO
            }
        }
    }

    EtherMacFullDuplex::receiveSignal(source, signalId, obj, details);
}

} // namespace nesting
