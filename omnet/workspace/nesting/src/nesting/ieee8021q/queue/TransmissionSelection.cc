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

#include "nesting/ieee8021q/queue/TransmissionSelection.h"
#include "nesting/ieee8021q/queue/framePreemption/ExpressFrameTag_m.h"

#include "inet/common/packet/Packet.h"

namespace nesting {

Define_Module(TransmissionSelection);

TransmissionSelection::TransmissionSelection() {
    requestPacketMsg.setSchedulingPriority(selfMessageSchedulingPriority);
    packetEnqueuedMsg.setSchedulingPriority(selfMessageSchedulingPriority);
    WATCH(packetRequestedFromUs);
    WATCH(packetRequestedFromInputs);
}

TransmissionSelection::~TransmissionSelection() {
    cancelEvent(&requestPacketMsg);
    cancelEvent(&packetEnqueuedMsg);
}

void TransmissionSelection::initialize() {
    // Get transmission gate vector module
    TransmissionGate* tgModule = getModuleFromPar<TransmissionGate>(par("transmissionGateVectorModule"), this);
    // Iterate through all sibling modules
    auto it = cModule::SubmoduleIterator(tgModule->getParentModule());
    for (; !it.end(); it++) {
        cModule* subModule = *it;
        // If module belongs to transmission gate vector module, add it to
        // transmission-gate data-structure for easy access later on.
        if (subModule->isName(tgModule->getName())) {
            TransmissionGate* tg = check_and_cast<TransmissionGate*>(subModule);
            tGates.push_back(tg);
        }
    }
}

void TransmissionSelection::handleMessage(cMessage* msg) {
    if (msg->isSelfMessage()) {
        if (msg == &packetEnqueuedMsg) {
            handlePacketEnqueuedEvent();
        } else if (msg == &requestPacketMsg) {
            handleRequestPacketEvent();
        }
    } else {
        Packet* packet = check_and_cast<Packet*>(msg);

        int gateId = -1;
        for (unsigned int i = 0; i < tGates.size(); ++i) {
            if (packet->arrivedOn("in", i)) {
                gateId = i;
                break;
            }
        }
        TransmissionGate* transmissionGate = tGates.at(gateId);
        if (par("verbose")) {
            EV_DETAIL << getFullName() << ": msg arrived at gate: " << gateId
                             << " which is express: "
                             << transmissionGate->isExpressQueue() << endl;
        }
        ASSERT(packetRequestedFromUs);
        packetRequestedFromUs = false;

        // Tag frame from express queues
        if (transmissionGate->isExpressQueue()) {
            packet->addTagIfAbsent<ExpressFrameReq>();
        }
        
        send(packet, "out");
    }
}

void TransmissionSelection::refreshDisplay() const {
    char buf[80];
    sprintf(buf, "packetRequested: %s",
            packetRequestedFromUs ? "true" : "false");
    getDisplayString().setTagArg("t", 0, buf);
}

bool TransmissionSelection::schedulePacket() {
    //Try to request express packet
    for (auto it = tGates.rbegin(); it != tGates.rend(); it++) {
        TransmissionGate* transmissionGate = *it;
        if (transmissionGate->isExpressQueue()
                && !transmissionGate->isEmpty()) {
            transmissionGate->requestPacket();
            return true;
        }
    }
    //Try to request any packet
    for (auto it = tGates.rbegin(); it != tGates.rend(); it++) {
        TransmissionGate* transmissionGate = *it;
        if (!transmissionGate->isEmpty()) {
            transmissionGate->requestPacket();
            return true;
        }
    }
    return false;
}

void TransmissionSelection::handleRequestPacketEvent() {
    EV_TRACE << getFullPath() << ": Handle request-packet-event." << endl;

    // Precondition: The Mac module must not request more than one packet at a
    // time. This implies the Mac module can not operate in burst mode or the
    // like.
    if (packetRequestedFromUs) {
        throw cRuntimeError(
                "TransmissionSelection module only supports one packet request at a +"
                        "time.");
    }

    // Invariant: Internal packet request flags are false
    ASSERT(!packetRequestedFromUs && !packetRequestedFromInputs);

    packetRequestedFromUs = true;
    packetRequestedFromInputs = true;

    // Try to request a packet from inputs if possible
    bool success = schedulePacket();
    if (success) {
        packetRequestedFromInputs = false;
    }
}

void TransmissionSelection::handlePacketEnqueuedEvent() {
    EV_TRACE << getFullPath() << ": Handle packet-enqueued-event." << endl;

    if (packetRequestedFromInputs) {
        bool success = schedulePacket();
        if (success) {
            packetRequestedFromInputs = false;
        }
    } else if (!packetRequestedFromUs) {
        notifyPacketEnqueued();
    }
}

void TransmissionSelection::packetEnqueued(TransmissionGate* transmissionGate) {
    Enter_Method("packetEnqueued()");

    cancelEvent(&packetEnqueuedMsg);
    scheduleAt(simTime(), &packetEnqueuedMsg);
}

void TransmissionSelection::requestPacket() {
    Enter_Method("requestPacket()");

    cancelEvent(&requestPacketMsg);
    scheduleAt(simTime(), &requestPacketMsg);
}

int TransmissionSelection::getNumPendingRequests() {
    return packetRequestedFromUs ? 1 : 0;
}

bool TransmissionSelection::isEmpty() {
    for (auto transmissionGate : tGates) {
        if (!transmissionGate->isEmpty()) {
            return false;
        }
    }
    return true;
}

void TransmissionSelection::removePendingRequests() {
    packetRequestedFromUs = false;
    packetRequestedFromInputs = false;
}

void TransmissionSelection::clear() {
    throw cRuntimeError("Unsupported operation");
}

cMessage* TransmissionSelection::pop() {
    throw cRuntimeError("Unsupported operation");
}

void TransmissionSelection::addListener(IPassiveQueueListener *listener) {
    listeners.push_back(listener);
}

void TransmissionSelection::removeListener(IPassiveQueueListener *listener) {
    listeners.erase(std::remove(listeners.begin(), listeners.end(), listener),
            listeners.end());
}

void TransmissionSelection::notifyPacketEnqueued() {
    for (auto listener : listeners) {
        listener->packetEnqueued(this);
    }
}

bool TransmissionSelection::hasExpressPacketEnqueued() {
    for (auto transmissionGate : tGates) {
        if (transmissionGate->isExpressQueue()
                && !transmissionGate->isEmpty()) {
            return true;
        }
    }
    return false;
}

} // namespace nesting
