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

#include "nesting/ieee8021q/queue/gating/TransmissionGate.h"

namespace nesting {

Define_Module(TransmissionGate);

TransmissionGate::~TransmissionGate() {
    cancelEvent(&requestPacketMsg);
    cancelEvent(&packetEnqueuedMsg);
    cancelEvent(&gateStateChangedMsg);
}

void TransmissionGate::initialize() {
    lengthAwareSchedulingEnabled = par("lengthAwareSchedulingEnabled");
    EV_DEBUG << getFullPath() << ": LengthAwareScheduling NED parameter is "
                    << lengthAwareSchedulingEnabled << endl;

    WATCH(gateOpen);

    // Initialize referenced modules
    gateController = getModuleFromPar<GateController>(
            par("gateControllerModule"), this);
    transmissionSelection = getModuleFromPar<TransmissionSelection>(
            par("transmissionSelectionModule"), this);
    tsAlgorithm = getModuleFromPar<TSAlgorithm>(
            par("transmissionSelectionAlgorithmModule"), this);

    clock = getModuleFromPar<IClock>(par("clockModule"), this);

    gateStateChangedSignal =
            registerSignal("gateStateChanged");
}

void TransmissionGate::handleMessage(cMessage* msg) {
    if (msg->isSelfMessage()) {
        if (msg == &gateStateChangedMsg) {
            handleGateStateChangedEvent();
        } else if (msg == &packetEnqueuedMsg) {
            handlePacketEnqueuedEvent();
        } else if (msg == &requestPacketMsg) {
            handleRequestPacketEvent();
        }
    } else {
        Packet* packet = check_and_cast<Packet *>(msg);
        EV_TRACE << getFullPath() << ": Sending packet '" << packet->getName()
                        << "' of size " << packet->getByteLength() << "B ("
                        << packet->getBitLength() << " bit) at time "
                        << clock->getTime().inUnit(SIMTIME_US) << endl;
        send(msg, "out");
    }
}

void TransmissionGate::refreshDisplay() const {
    char buf[80];
    sprintf(buf, "%s", gateOpen ? "opened" : "closed");
    getDisplayString().setTagArg("t", 0, buf);
}

void TransmissionGate::notifyPacketEnqueued() {
    transmissionSelection->packetEnqueued(this);
}

void TransmissionGate::notifyGateStateChanged() {
    tsAlgorithm->gateStateChanged();
}

void TransmissionGate::handleRequestPacketEvent() {
    EV_INFO << "Handle request-packet event." << endl;

    ASSERT(!isEmpty());
    tsAlgorithm->requestPacket(maxTransferableBits());
}

void TransmissionGate::handlePacketEnqueuedEvent() {
    EV_INFO << "Handle packet-enqueued event. Max " << maxTransferableBits()
            << "bit transferable at t=" << clock->getTime().inUnit(SIMTIME_US)
            << "us." << std::endl;

    if (gateOpen && (isExpressQueue() || !gateController->currentlyOnHold())) {
        transmissionSelection->packetEnqueued(this);
    }
}

void TransmissionGate::handleGateStateChangedEvent() {
    EV_INFO << "Gate state changed to " << (this->gateOpen ? "open" : "closed")
            << ". Max " << maxTransferableBits()
            << "bit transferable at t=" << clock->getTime().inUnit(SIMTIME_US)
            << "us." << std::endl;

    emit(gateStateChangedSignal, this->gateOpen);
    // Notify transmission-selection if packet has become ready for transmission
    if (gateOpen && !tsAlgorithm->isEmpty(maxTransferableBits())
            && (isExpressQueue() || !gateController->currentlyOnHold())) {
        transmissionSelection->packetEnqueued(this);
    }

    // Notify transmission-selection-algorithm about gate state change
    tsAlgorithm->gateStateChanged();
}

uint64_t TransmissionGate::maxTransferableBits() {
    if (lengthAwareSchedulingEnabled) {
        unsigned int maxbit = gateController->calculateMaxBit(getIndex());
        return maxbit;
    }
    return kEthernet2MaximumTransmissionUnitBitLength.get();
}

bool TransmissionGate::isGateOpen() {
    return gateOpen;
}

void TransmissionGate::setGateState(bool gateOpen, bool release) {
    Enter_Method_Silent("setGateState()");

    // Update state
    bool gateStateChanged = this->gateOpen != gateOpen;
    this->gateOpen = gateOpen;

    // Schedule gate-state-changed event
    if (gateStateChanged) {
        cancelEvent(&gateStateChangedMsg);
        scheduleAt(simTime(), &gateStateChangedMsg);
    } else if(release && gateOpen && !tsAlgorithm->isEmpty(maxTransferableBits()) && (isExpressQueue() || !gateController->currentlyOnHold())) {
        transmissionSelection->packetEnqueued(this);
    }
}

bool TransmissionGate::isEmpty() {
    return !isGateOpen()
            || (!isExpressQueue() && gateController->currentlyOnHold())
            || tsAlgorithm->isEmpty(maxTransferableBits());
}

void TransmissionGate::requestPacket() {
    Enter_Method("requestPacket()");

    cancelEvent(&requestPacketMsg);
    scheduleAt(simTime(), &requestPacketMsg);
}

void TransmissionGate::packetEnqueued() {
    Enter_Method("packetEnqueued()");

    cancelEvent(&packetEnqueuedMsg);
    scheduleAt(simTime(), &packetEnqueuedMsg);
}

bool TransmissionGate::isExpressQueue() {
    return tsAlgorithm->isExpressQueue();
}
}
//namespace nesting
