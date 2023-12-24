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

#include "nesting/ieee8021q/queue/transmissionSelectionAlgorithms/TSAlgorithm.h"

namespace nesting {

Define_Module(TSAlgorithm);

TSAlgorithm::~TSAlgorithm() {
    cancelEvent(&requestPacketMsg);
    cancelEvent(&packetEnqueuedMsg);
    cancelEvent(&gateStateChangedMsg);
}

void TSAlgorithm::initialize() {
    cModule* macModule = getModuleFromPar<cModule>(par("macModule"), this);
    mac = check_and_cast<EtherMacBase*>(macModule);
    queue = getModuleFromPar<LengthAwareQueue>(par("queueModule"), this);
    transmissionGate = getModuleFromPar<TransmissionGate>(par("gateModule"),
            this);
}

void TSAlgorithm::handleMessage(cMessage* msg) {
    if (msg->isSelfMessage()) {
        if (msg == &packetEnqueuedMsg) {
            handlePacketEnqueuedEvent();
        } else if (msg == &gateStateChangedMsg) {
            handleGateStateChangedEvent();
        } else if (msg == &requestPacketMsg) {
            handleRequestPacketEvent(maxTransmittableBits);
        }
    } else {
        send(msg, "out");
    }
}

void TSAlgorithm::handlePacketEnqueuedEvent() {
    EV_TRACE << getFullPath()
                    << ": Handle packet-enqueued event (without bit parameter)."
                    << endl;

    transmissionGate->packetEnqueued();
}

void TSAlgorithm::handleGateStateChangedEvent() {
    // Empty method
}

void TSAlgorithm::handleRequestPacketEvent(uint64_t maxBits) {
    EV_TRACE << getFullPath() << ": Handle request-packet event (" << maxBits
                    << " bits)." << endl;

    queue->requestPacket(maxBits);
}

void TSAlgorithm::gateStateChanged() {
    Enter_Method("gateStateChanged()");
    cancelEvent(&gateStateChangedMsg);
    scheduleAt(simTime(), &gateStateChangedMsg);
}

void TSAlgorithm::packetEnqueued() {
    Enter_Method("packetEnqueued()");
    cancelEvent(&packetEnqueuedMsg);
    scheduleAt(simTime(), &packetEnqueuedMsg);
}

bool TSAlgorithm::isEmpty(uint64_t maxBits) {
    return queue->isEmpty(maxBits);
}

void TSAlgorithm::requestPacket(uint64_t maxBits) {
    Enter_Method("requestPacket(maxBits)");
    ASSERT(!isEmpty(maxBits));
    cancelEvent(&requestPacketMsg);
    maxTransmittableBits = maxBits;
    scheduleAt(simTime(), &requestPacketMsg);
}
bool TSAlgorithm::isExpressQueue() {
    return queue->isExpressQueue();
}
}
/* namespace nesting */
