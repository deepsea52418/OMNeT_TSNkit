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

#include "nesting/linklayer/framePreemption/EtherMACFullDuplexPreemptable.h"
#include "nesting/linklayer/framePreemption/PreemptedFrame.h"
#include "nesting/ieee8021q/queue/framePreemption/ExpressFrameTag_m.h"

#include "inet/common/queue/IPassiveQueue.h"
#include "inet/networklayer/common/InterfaceEntry.h"


namespace nesting {

Define_Module(EtherMACFullDuplexPreemptable);

simsignal_t EtherMACFullDuplexPreemptable::preemptCurrentFrameSignal =
        registerSignal("preemptCurrentFrameSignal");
simsignal_t EtherMACFullDuplexPreemptable::transmittedExpressFrameSignal =
        registerSignal("transmittedExpressFrameSignal");
simsignal_t EtherMACFullDuplexPreemptable::startTransmissionExpressFrameSignal =
        registerSignal("startTransmissionExpressFrameSignal");
simsignal_t EtherMACFullDuplexPreemptable::transmittedPreemptableFrameSignal =
        registerSignal("transmittedPreemptableFrameSignal");
simsignal_t EtherMACFullDuplexPreemptable::transmittedPreemptableFramePartSignal =
        registerSignal("transmittedPreemptableFramePartSignal");
simsignal_t EtherMACFullDuplexPreemptable::transmittedPreemptableNonFinalSignal =
        registerSignal("transmittedPreemptableNonFinalSignal");
simsignal_t EtherMACFullDuplexPreemptable::transmittedPreemptableFinalSignal =
        registerSignal("transmittedPreemptableFinalSignal");
simsignal_t EtherMACFullDuplexPreemptable::transmittedPreemptableFullSignal =
        registerSignal("transmittedPreemptableFullSignal");
simsignal_t EtherMACFullDuplexPreemptable::expressFrameEnqueuedWhileSendingPreemptableSignal =
        registerSignal("expressFrameEnqueuedWhileSendingPreemptableSignal");
simsignal_t EtherMACFullDuplexPreemptable::eMacDelay = registerSignal(
        "eMacDelay");
simsignal_t EtherMACFullDuplexPreemptable::pMacDelay = registerSignal(
        "pMacDelay");
simsignal_t EtherMACFullDuplexPreemptable::receivedExpressFrame =
        registerSignal("receivedExpressFrame");
simsignal_t EtherMACFullDuplexPreemptable::receivedPreemptableFrameFull =
        registerSignal("receivedPreemptableFrameFull");
simsignal_t EtherMACFullDuplexPreemptable::receivedExpressFrameFromUpper =
        registerSignal("receivedExpressFrameFromUpper");

EtherMACFullDuplexPreemptable::~EtherMACFullDuplexPreemptable() {
    cancelAndDelete(recheckForQueuedExpressFrameMsg);
    cancelAndDelete(preemptCurrentFrameMsg);

    delete receivedPreemptedFrame;
    delete currentPreemptableFrame;
    delete currentExpressFrame;
}

void EtherMACFullDuplexPreemptable::initialize(int stage) {
    EtherMacFullDuplex::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        cModule* queueModule = getModuleFromPar<cModule>(par("queueModule"), this);
        if (queueModule->isSimple()) {
            transmissionSelectionModule = getModuleFromPar<TransmissionSelection>(par("queueModule"), this);
        } else {
            std::string path = par("queueModule").stdstringValue() + std::string(".transmissionSelection");
            cModule* mod = getModuleByPath(path.c_str());
            transmissionSelectionModule = dynamic_cast<TransmissionSelection*>(mod);
            if (!transmissionSelectionModule) {
                throw cRuntimeError("Cannot cast queue module to transmission selection module");
            }
        }
        
        transmissionSelectionModule->addListener(this);
        preemptCurrentFrameMsg = new cMessage("preemptCurrentFrame");
    }
}

void EtherMACFullDuplexPreemptable::handleMessageWhenUp(cMessage *msg) {
    if (channelsDiffer) {
        readChannelParameters(true);
    }

    if (msg->isSelfMessage()) {
        handleSelfMessage(msg);
    } else if (msg->arrivedOn("upperLayerIn")) {
        handleUpperPacket(check_and_cast<Packet *>(msg));
    } else if (msg->getArrivalGate() == physInGate) {
        // from phys
        PreemptedFrame* pFrame = dynamic_cast<PreemptedFrame*>(msg);
        if (pFrame == nullptr) {
            // is express frame, send up
            EthernetSignal* tmp = check_and_cast<EthernetSignal*>(msg);
            // need to get encapsulated packet, in order to get the right packet id
            // getting tree id, because it doenn't get changed when packet is copied
            emit(receivedExpressFrame,
                    tmp->getEncapsulatedPacket()->getTreeId());
            processMsgFromNetwork(tmp);
        }
        // is preemptible frame
        else if (dynamic_cast<EthernetSignal*>(pFrame->getCompleteFrame())) {
            // if incoming frame is new frame, replace old preempted frame by new one
            if (receivedPreemptedFrame == nullptr
                    || strcmp(receivedPreemptedFrame->getName(),
                            pFrame->getCompleteFrame()->getName()) != 0) {
                delete receivedPreemptedFrame;
                receivedPreemptedFrame = pFrame->getCompleteFrame()->dup();
            }

            preemptedBytesReceived = pFrame->getBytesSent();
            //8 extra bytes for encapsulation with Preamble and SFD
            if (receivedPreemptedFrame->getByteLength()
                    == preemptedBytesReceived + 8) {
                //enough bytes from the preempted frame received -> send it up
                EthernetSignal* tmp = check_and_cast<EthernetSignal*>(
                        receivedPreemptedFrame);
                emit(receivedPreemptableFrameFull,
                        tmp->getEncapsulatedPacket()->getTreeId());
                processMsgFromNetwork(tmp);
                receivedPreemptedFrame = nullptr;
            }
            delete pFrame;
        } else
        // unknown packet
        {
            throw cRuntimeError("Packet received is of unknown type!");
        }
    } else {
        throw cRuntimeError("Message received from unknown gate!");
    }
}

void EtherMACFullDuplexPreemptable::handleSelfMessage(cMessage *msg) {
    EV_TRACE << "Self-message " << msg << " received" << endl;
    if (msg == endTxMsg)
        handleEndTxPeriod();
    else if (msg == endIFGMsg)
        handleEndIFGPeriod();
    else if (msg == endPauseMsg)
        handleEndPausePeriod();
    else if (strcmp(msg->getName(), "recheckForQueuedExpressFrame") == 0)
        checkForAndRequestExpressFrame();
    else if (msg == preemptCurrentFrameMsg)
        preemptCurrentFrame();
    else if (strcmp(msg->getName(), "holdRequest") == 0) {
        hold(SIMTIME_ZERO);
        delete msg;
    } else {
        throw cRuntimeError("Unknown self message received!");
    }
}

bool EtherMACFullDuplexPreemptable::isExpressFrame(Packet* packet) const
{
    return packet->findTag<ExpressFrameReq>() != nullptr;
}

void EtherMACFullDuplexPreemptable::handleUpperPacket(Packet* packet) {
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INET/BEGIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ASSERT(packet->getDataLength() >= MIN_ETHERNET_FRAME_BYTES);
    
    if (isExpressFrame(packet)) {
        pFrameArrivalTime = simTime();
    } else {
        eFrameArrivalTime = simTime();
        emit(receivedExpressFrameFromUpper, packet->getTreeId());
    }

    EV_INFO << "Received " << packet << " from upper layer." << endl;

    numFramesFromHL++;
    emit(packetReceivedFromUpperSignal, packet);

    auto frame = packet->peekAtFront<EthernetMacHeader>();
    if (frame->getDest().equals(getMacAddress())) {
        throw cRuntimeError(
                "logic error: frame %s from higher layer has local MAC address as dest (%s)",
                packet->getFullName(), frame->getDest().str().c_str());
    }

    if (packet->getDataLength() > MAX_ETHERNET_FRAME_BYTES) { //FIXME two MAX FRAME BYTES in specif...
        throw cRuntimeError(
                "packet from higher layer (%d bytes) exceeds maximum Ethernet frame size (%d)",
                (int) (packet->getByteLength()),
                B(MAX_ETHERNET_FRAME_BYTES).get());
    }

    if (!connected || disabled) {
        EV_WARN
                       << (!connected ?
                               "Interface is not connected" : "MAC is disabled")
                       << " -- dropping packet " << packet << endl;
        PacketDropDetails details;
        details.setReason(INTERFACE_DOWN);
        emit(packetDroppedSignal, packet->getTreeId(), &details);
        numDroppedPkFromHLIfaceDown++;
        delete packet;

        requestNextFrameFromExtQueue();
        return;
    }

    // fill in src address if not set
    if (frame->getSrc().isUnspecified()) {
        frame = nullptr; // drop shared ptr
        auto newFrame = packet->removeAtFront<EthernetMacHeader>();
        newFrame->setSrc(getMacAddress());
        packet->insertAtFront(newFrame);
        frame = newFrame;
        auto oldFcs = packet->removeAtBack<EthernetFcs>();
        EtherEncap::addFcs(packet, oldFcs->getFcsMode());
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INET/END~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if (isExpressFrame(packet) && recheckForQueuedExpressFrameMsg != nullptr
            && recheckForQueuedExpressFrameMsg->isScheduled()) {
        cancelAndDelete(recheckForQueuedExpressFrameMsg);
    }
    bool nowPreempting = false;
    // currently not transmitting express frame and this frame is express or preemptible frame
    if ((!transmittingExpressFrame && isExpressFrame(packet)) || txQueue.extQueue) {
        ASSERT(
                transmitState == TX_IDLE_STATE || transmitState == PAUSE_STATE
                        || (!transmittingExpressFrame && isExpressFrame(packet)));
        if (transmittingPreemptableFrame && isExpressFrame(packet)) {
            //An express frame arrived at the correct time to preempt a preemptable frame
            currentExpressFrame = packet;
            preemptCurrentFrame();
            nowPreempting = true;
        } else if (isExpressFrame(packet) && transmitState == WAIT_IFG_STATE) {
            //If an express frame arrives during the IFG, save it for later. Otherwise the assert in handleEndIFGPeriod() would fail
            currentExpressFrame = packet;
        } else {
            // preemptible frame arrived
            curTxFrame = packet;
        }
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INET/BEGIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    else {
        if (txQueue.innerQueue->isFull()) {
            throw cRuntimeError(
                    "txQueue length exceeds %d -- this is probably due to "
                            "a bogus app model generating excessive traffic "
                            "(or if this is normal, increase txQueueLimit!)",
                    txQueue.innerQueue->getQueueLimit());
        }
        // store frame and possibly begin transmitting
        EV_DETAIL << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS)
                         << "ns:" << " Frame " << frame
                         << " arrived from higher layers, enqueueing" << endl;
        txQueue.innerQueue->insertFrame(packet);

        if (!curTxFrame && !txQueue.innerQueue->isEmpty()
                && transmitState == TX_IDLE_STATE) {
            curTxFrame = (Packet *) txQueue.innerQueue->pop();
        }
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INET/END~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if (onHold && !isExpressFrame(packet) && !currentPreemptableFrame) {
        currentPreemptableFrame = curTxFrame;
        curTxFrame = nullptr;
    }
    if (transmitState == TX_IDLE_STATE && !nowPreempting) {
        startFrameTransmission();
    }
}

void EtherMACFullDuplexPreemptable::startFrameTransmission() {
    Enter_Method_Silent("startFrameTransmission()");
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INET/BEGIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ASSERT(curTxFrame);
    EV_DETAIL << "Transmitting a copy of frame " << curTxFrame << endl;

    Packet *frame = curTxFrame->dup();// note: we need to duplicate the frame because we emit a signal with it in endTxPeriod()
    const auto& hdr = frame->peekAtFront<EthernetMacHeader>();// note: we need to duplicate the frame because we emit a signal with it in endTxPeriod()
    ASSERT(hdr);
    ASSERT(!hdr->getSrc().isUnspecified());

    if (frame->getDataLength() < curEtherDescr->frameMinBytes) {
        auto oldFcs = frame->removeAtBack<EthernetFcs>();
        EtherEncap::addPaddingAndFcs(frame, oldFcs->getFcsMode(), curEtherDescr->frameMinBytes);
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INET/END~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ASSERT(!transmittingExpressFrame);
    ASSERT(!transmittingPreemptableFrame);
    EV_INFO << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS)
            << "ns:" << " Starting Transmission of " << frame << ". Express: " 
            << isExpressFrame(frame) << endl;
    
    //If frame preemption is disabled, treat all frames as express so they are properly displayed
    if (!par("enablePreemptingFrames") || isExpressFrame(frame)) {
        //Send frame out normally
        transmittingExpressFrame = true;
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INET/BEGIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // add preamble and SFD (Starting Frame Delimiter), then send out
        encapsulate(frame);

        // send
        EV_INFO << "Transmission of " << frame << " started.\n";
        auto oldPacketProtocolTag = frame->removeTag<PacketProtocolTag>();
        frame->clearTags();
        auto newPacketProtocolTag = frame->addTag<PacketProtocolTag>();
        *newPacketProtocolTag = *oldPacketProtocolTag;
        delete oldPacketProtocolTag;
        auto signal = new EthernetSignal(frame->getName());
        if (sendRawBytes) {
            signal->encapsulate(new Packet(frame->getName(), frame->peekAllAsBytes()));
            delete frame;
        }
        else {
            signal->encapsulate(frame);
        }
        send(signal, physOutGate);
        emit(eMacDelay, simTime() - eFrameArrivalTime);
        emit(startTransmissionExpressFrameSignal, curTxFrame->getTreeId());
        scheduleAt(transmissionChannel->getTransmissionFinishTime(), endTxMsg);
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INET/END~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    } else {
        // "Sending" preemptable frame
        // (block the link for the theoretical type and send zero-time frame later, indicating how many bytes were transferred)
        // Check if it is a new preemptable frame
        if (currentPreemptableFrame == nullptr || strcmp(currentPreemptableFrame->getName(), curTxFrame->getName())!=0) {
            // new frame, reset number of bytes sent
            preemptedBytesSent = 0;
            delete currentPreemptableFrame;
            // curTxFrame is deleted after every link transmission -> duplicate frame
            currentPreemptableFrame = curTxFrame->dup();
        }

        transmittingPreemptableFrame = true;
        preemptableTransmissionStart = simTime();
        // add preamble and SFD (Starting Frame Delimiter)
        encapsulate(frame);

        //Calculate number of bytes to theoretically send, including Preamble, SMD and FCS
        unsigned int preemptedPacketLength = frame->getByteLength() - preemptedBytesSent;
        cPacket* frameCopyToCalculateLength = new cPacket();
        frameCopyToCalculateLength->setByteLength(preemptedPacketLength);
        //Block link for the theoretically needed amount of time
        scheduleAt(simTime() + transmissionChannel->calculateDuration(frameCopyToCalculateLength), endTxMsg);
        emit(pMacDelay, simTime() - pFrameArrivalTime);
        delete frame;
        delete frameCopyToCalculateLength;
    }
    changeTransmissionState(TRANSMITTING_STATE);
}

void EtherMACFullDuplexPreemptable::getNextFrameFromQueue() {

    ASSERT(nullptr == curTxFrame);
    //Check if there is an express frame waiting to be sent after finishing preemption
    if (currentExpressFrame) {
        EV_DETAIL << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS)
                         << "ns:"
                         << " Queuing express frame now that preemption is finished."
                         << endl;
        curTxFrame = currentExpressFrame;
        currentExpressFrame = nullptr;
        //Check if a new express frame is available
    } else if (par("enablePreemptingFrames")
            && checkForAndRequestExpressFrame()) {
        return;
        //If there is a started preemptable frame, continue it
    } else if (!onHold && currentPreemptableFrame) {
        //Otherwise continue started preemptable frame if it existed
        curTxFrame = currentPreemptableFrame->dup();
        EV_DETAIL << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS)
                         << "ns:" << " Getting preempted frame " << curTxFrame
                         << " instead of one from the queue." << endl;
        //Otherwise ask queues like in the superclass
    } else if (txQueue.extQueue) {
        requestNextFrameFromExtQueue();
    } else if (txQueue.innerQueue && !txQueue.innerQueue->isEmpty()) {
        curTxFrame = static_cast<Packet *>(txQueue.innerQueue->pop());
    }

}

void EtherMACFullDuplexPreemptable::handleEndTxPeriod() {
    //TODO add other content from original method
    if (par("enablePreemptingFrames") && transmittingPreemptableFrame) {
        // A (part of a) preemptable frame was sent
        emit(transmittedPreemptableFramePartSignal,
                currentPreemptableFrame->getTreeId());
        bool beginningOfPreemptableFrame = (preemptedBytesSent == 0);
        // Update bytes sent so far for this preemptable frame
        unsigned int bytesSentInThisPart =
                (unsigned int) calculatePreemptedPayloadBytesSent(simTime(),
                        true);
        preemptedBytesSent += bytesSentInThisPart;
        /*
         * Encapsulation adds PREAMBLE 7B, SFD 1B, FCS 4B. This adds up to 12B. calculatePreemptedBytesSent subtracts 4B for FCS according to standard,
         * but includes PREAMBLE and SFD.
         * currentPreemptableFrame holds frame that is not encapsulated, therefore without PREAMBLE and SFD but with FCS.
         * Therefore, in order to be able to compare preemptedBytesSent to the stored packet length, the length of PREAMBLE and SFD need to be added
         * to stored packet length.
         *
         * If this framelet was the final framelet, or pFrame was transmitted without preemption, 4B that were subtracted by calculatePreemptedPayloadBytesSent
         * need to be added, because in this case, FCS is included in transmission.
         */
        if (preemptedBytesSent + 4
                == currentPreemptableFrame->getByteLength() + 8) {
            // 8B (PREAMBLE, SFD) need to be subtracted, 4B were already subtracted, therefore subtract 4B
            bytesSentInThisPart -= 4;
            //Add last checksum that is included in the encapped frame instead of the "mpacket"/frame preemption calculation
            preemptedBytesSent = currentPreemptableFrame->getByteLength();
            // final part was sent, therefore transmission is complete
            emit(transmittedPreemptableFrameSignal,
                    currentPreemptableFrame->getTreeId());
            if (beginningOfPreemptableFrame) {
                emit(transmittedPreemptableFullSignal,
                        currentPreemptableFrame->getTreeId());
            } else {
                emit(transmittedPreemptableFinalSignal,
                        currentPreemptableFrame->getTreeId());
            }
        } else {
            emit(transmittedPreemptableNonFinalSignal,
                    currentPreemptableFrame->getTreeId());
        }
        EV_INFO << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS)
                       << "ns:" << " PreemptedFrame " << currentPreemptableFrame
                       << " transmitted: " << bytesSentInThisPart << "B, "
                       << preemptedBytesSent << "/"
                       << currentPreemptableFrame->getByteLength() << "B"
                       << endl;
        // dup frame to create new zero msg
        Packet* currentPreemptableFrameCopy = currentPreemptableFrame->dup();
        // encapsulate frame properly, so that receiver mac can decapsulate
        encapsulate(currentPreemptableFrameCopy);
        auto oldPacketProtocolTag = currentPreemptableFrameCopy->removeTag<
                PacketProtocolTag>();
        currentPreemptableFrameCopy->clearTags();
        auto newPacketProtocolTag = currentPreemptableFrameCopy->addTag<
                PacketProtocolTag>();
        *newPacketProtocolTag = *oldPacketProtocolTag;
        delete oldPacketProtocolTag;
        auto signalCurrentPreemptableFrameCopy = new EthernetSignal(
                currentPreemptableFrameCopy->getName());
        signalCurrentPreemptableFrameCopy->encapsulate(
                currentPreemptableFrameCopy);
        PreemptedFrame* preemptedBytesSentMessage = new PreemptedFrame(
                signalCurrentPreemptableFrameCopy);
        // can't be deleted because reference is kept by PreemptedFrame msg
        // delete currentPreemptableFrameCopy;
        // bytes sent up until now
        preemptedBytesSentMessage->setBytesSent(preemptedBytesSent);
        // bytes to be sent in total
        preemptedBytesSentMessage->setBytesTotal(
                currentPreemptableFrame->getByteLength());
        // bytes sent in this framelet
        preemptedBytesSentMessage->setBytesInThisPart(bytesSentInThisPart);
        // set length to zero to not have transmission delay
        preemptedBytesSentMessage->setByteLength(0);
        send(preemptedBytesSentMessage, physOutGate);

        //If this was the final part of a preemptable frame, delete it
        if (preemptedBytesSent == currentPreemptableFrame->getByteLength()) {
            delete currentPreemptableFrame;
            currentPreemptableFrame = nullptr;
        }
    } else {
        EV_DETAIL << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS)
                         << "ns:" << " Express Frame " << curTxFrame
                         << " finished to transmit." << endl;
        //Can only be express frame, as it is the default if frame preemption is disabled
        emit(transmittedExpressFrameSignal, curTxFrame->getTreeId());
    }
    transmittingExpressFrame = false;
    transmittingPreemptableFrame = false;
    EtherMacFullDuplex::handleEndTxPeriod();
}

void EtherMACFullDuplexPreemptable::handleEndIFGPeriod() {

    ASSERT(nullptr == curTxFrame);
    if (transmitState != WAIT_IFG_STATE)
        throw cRuntimeError("Not in WAIT_IFG_STATE at the end of IFG period");

    // End of IFG period, okay to transmit
    EV_DETAIL << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS)
                     << "ns:" << " IFG elapsed" << endl;

    getNextFrameFromQueue();
    beginSendFrames();

}

bool EtherMACFullDuplexPreemptable::checkForAndRequestExpressFrame() {

    ASSERT(isPreemptionNowPossible());
    if (!transmittingExpressFrame && !transmissionSelectionModule->isEmpty()
            && transmissionSelectionModule->hasExpressPacketEnqueued()) {
        EV_INFO << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS)
                       << "ns:"
                       << " Currently not transmitting or preemption is possible: requesting express frame."
                       << endl;
        transmissionSelectionModule->requestPacket();
        return true;
    }
    return false;

}

void EtherMACFullDuplexPreemptable::preemptCurrentFrame() {

    ASSERT(transmittingPreemptableFrame);
    ASSERT(currentPreemptableFrame);
    ASSERT(!transmittingExpressFrame);
    ASSERT(isPreemptionNowPossible());

    cancelEvent(endTxMsg);

    emit(preemptCurrentFrameSignal, currentPreemptableFrame->getTreeId());

    EV_INFO << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS)
                   << "ns:" << " Preempting current frame "
                   << currentPreemptableFrame << endl;
    //"End" transmission after four bytes from now (to send preemptable frame-part checksum)
    scheduleAt(simTime() + calculateTransmissionDuration(4), endTxMsg);

}

int EtherMACFullDuplexPreemptable::calculatePreemptedPayloadBytesSent(
        simtime_t timeToCheck, bool sentCRC) {

    if (!transmittingPreemptableFrame) {
        return 0;
    }
    double transmitRate = getTxRate();
    ASSERT(transmitRate > 0);
    simtime_t timeElapsed = timeToCheck - preemptableTransmissionStart;
    int bytesTransmittedInTotal = (timeElapsed
            / (SimTime(1, SIMTIME_S) / transmitRate)) / 8;
    // this function gets called at two different times: when CRC has been sent at end of tx, or when checking if preemption is possible (CRC not sent yet)
    // , therefore CRC only needs to be subtracted when CRC has been sent
    if (sentCRC) {
        // subtract checksum (4B), spec. at 802.3 99.4.4
        bytesTransmittedInTotal -= 4;
    }
    if (bytesTransmittedInTotal < 0) {
        return 0;
    } else if (bytesTransmittedInTotal
            > currentPreemptableFrame->getByteLength() + 8) {
        // add 8 Bytes for Preamble and sfd
        throw cRuntimeError(
                "Supposedly transmitted more bytes than the frame's length.");
    }
    return bytesTransmittedInTotal;
}

simtime_t EtherMACFullDuplexPreemptable::isPreemptionLaterPossible() {

    if (isPreemptionNowPossible()) {
        return simTime();
    }
    int payloadBytesSentByNow = calculatePreemptedPayloadBytesSent(simTime(),
            false);
    int payloadBytesRemaining = currentPreemptableFrame->getByteLength()
            - payloadBytesSentByNow - preemptedBytesSent;
    // TODO Why payloadBytesRemaining >= NonFinal + - sentbynow + FinalPayloadSize??
    if (payloadBytesSentByNow < kFramePreemptionMinNonFinalPayloadSize.get()
            && payloadBytesRemaining
                    >= kFramePreemptionMinNonFinalPayloadSize.get() + 4
                            - payloadBytesSentByNow
                            + kFramePreemptionMinFinalPayloadSize.get()) {
        //Preemption not yet possible, but after a short time -> Need to wait to preempt
        int bytesToWait = (kFramePreemptionMinNonFinalPayloadSize.get()
                - payloadBytesSentByNow);
        return simTime() + calculateTransmissionDuration(bytesToWait);
    }
    //Too late to preempt this frame at all
    return SIMTIME_ZERO;

}

bool EtherMACFullDuplexPreemptable::isPreemptionNowPossible() {

    if (!par("enablePreemptingFrames") || !transmittingPreemptableFrame) {
        return true;
    } else if (transmittingExpressFrame) {
        return false;
    }
    int payloadBytesSent = calculatePreemptedPayloadBytesSent(simTime(), false);
    int payloadBytesRemaining = currentPreemptableFrame->getByteLength()
            - payloadBytesSent - preemptedBytesSent;
    if (payloadBytesRemaining < kFramePreemptionMinFinalPayloadSize.get()) {
        //Final fragment size would be too short -> Preemption forbidden
        return false;
    } else if (payloadBytesSent
            >= kFramePreemptionMinNonFinalPayloadSize.get()) {
        //Both the first part as well as the remaining part are large enough -> preemption possible at this time
        return true;
    }
    //Too late to preempt or too early
    return false;

}

simtime_t EtherMACFullDuplexPreemptable::calculateTransmissionDuration(
        int bytes) {

    double transmitRate = getTxRate();
    ASSERT(transmitRate > 0);
    simtime_t timeForOneBit = SimTime(1, SIMTIME_S) / transmitRate;
    return timeForOneBit * bytes * 8;

}

void EtherMACFullDuplexPreemptable::packetEnqueued(IPassiveQueue *queue) {

    Enter_Method("packetEnqueued()");
    if (transmittingPreemptableFrame && !transmittingExpressFrame && transmissionSelectionModule->hasExpressPacketEnqueued()) {
        emit(expressFrameEnqueuedWhileSendingPreemptableSignal, 0);
        std::string loggingPrefix = " Received express frame enqueued notification, ";
        if(isPreemptionNowPossible()) {
            //If direct sending is possible, request the frame
            EV_DETAIL << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS) << "ns:" << loggingPrefix << "Preemption is possible immediately, requesting frame." << endl;
            transmissionSelectionModule->requestPacket();
        } else {
            simtime_t nextPreemptionPossible = isPreemptionLaterPossible();
            if(!nextPreemptionPossible.isZero()) {
                //If preemption is only possible later, schedule frame request to that time
                EV_DETAIL << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS) << "ns:" << loggingPrefix << "Preemption is possible later, scheduling express frame request for later." << endl;
                cancelAndDelete(recheckForQueuedExpressFrameMsg);
                recheckForQueuedExpressFrameMsg = new cMessage("recheckForQueuedExpressFrame");
                scheduleAt(nextPreemptionPossible, recheckForQueuedExpressFrameMsg);
            } else {
                EV_DETAIL << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS) << "ns:" << loggingPrefix << "Preemption is not possible at all." << endl;
            }
        }
        //TODO think of last four bytes in 124 example
        //TODO test parameter functionality
        //Signals: Enter_Method oder originale mac davor, oder über super aufrufen, oder irgendwie ownen
    }

}

void EtherMACFullDuplexPreemptable::hold(simtime_t delay) {

    Enter_Method("hold()");
    if(par("enablePreemptingFrames")) {
        if(delay.isZero()) {
            //Execute hold request -> preempt current preemptable traffic, don't allow new one
            EV_INFO << getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS) << "ns:" << " Got hold request."<<endl;
            onHold = true;
            if (transmittingPreemptableFrame && isPreemptionNowPossible()) {
                //Preempt now if possible
                preemptCurrentFrame();
            } else if (transmittingPreemptableFrame) {
                //Preempt as soon as possible, if possible at all
                simtime_t nextPreemptionPossible = isPreemptionLaterPossible();
                if (!nextPreemptionPossible.isZero()) {
                    if(preemptCurrentFrameMsg->isScheduled()) {
                        cancelEvent(preemptCurrentFrameMsg);
                    }
                    scheduleAt(nextPreemptionPossible, preemptCurrentFrameMsg);
                    EV_INFO<<getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS) << "ns:" << " Scheduling preemption after first mPacket is large enough."<<endl;
                } else {
                    EV_INFO<<getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS) << "ns:" << " Preemption is not possible at all."<<endl;}
            } else if (transmitState == TX_IDLE_STATE) {
                //If no traffic is sent currently, request frame if needed
                EV_INFO<<getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS) << "ns:" << " No frame to transmit. Requesting express frame."<<endl;
                getNextFrameFromQueue();
            }
        } else {
            //Schedule hold on specified time
            EV_INFO<<getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS) << "ns:" << " Scheduling hold in "<<delay.inUnit(SIMTIME_US)<<"us."<<endl;
            scheduleAt(simTime() + delay, new cMessage("holdRequest", 1));
        }
    }

}

void EtherMACFullDuplexPreemptable::release() {

    Enter_Method("release()");
    if(par("enablePreemptingFrames")) {
        onHold = false;
        EV_INFO<<getFullPath() << " at t=" << simTime().inUnit(SIMTIME_NS) << "ns:" << " Got release request. Requesting frame."<<endl;
        //Clear pending requests from this module, otherwise
        transmissionSelectionModule->removePendingRequests();
        if(!transmittingExpressFrame) {
            // if release signaled during interframe gap, wait until IFG is over
            if(!endIFGMsg->isScheduled()) {
                //getNextFrameFromQueue() checks if preemptedFrame was in transmission
                getNextFrameFromQueue();
                beginSendFrames();
            }
        }
    }

}

simtime_t EtherMACFullDuplexPreemptable::getHoldAdvance() {

    Enter_Method_Silent("release()");
    //Calculate the hold advance i.e. the maximum delay needed before express traffic can flow after a preemption/hold event
    int bitsToWait = INTERFRAME_GAP_BITS.get() + kFramePreemptionMinNonFinalPayloadSize.get() + kFramePreemptionMinFinalPayloadSize.get() + 4;
    double transmitRate = getTxRate();
    ASSERT(transmitRate > 0);
    simtime_t timeForOneBit = SimTime(1, SIMTIME_S) / transmitRate;
    return timeForOneBit * bitsToWait;

}

bool EtherMACFullDuplexPreemptable::isOnHold() {

    Enter_Method_Silent("isOnHold()");
    return onHold;

}

void EtherMACFullDuplexPreemptable::refreshDisplay() const {
    // icon colouring
    const char *colour;
    if (transmitState == TRANSMITTING_STATE) {
        colour = "yellow";
    } else {
        colour = "";
    }
    char buf[200];
    const char* currentPreemptableFrameName =
            (nullptr == currentPreemptableFrame) ?
                    "nullptr" : currentPreemptableFrame->getName();
    const char* currentExpressFrameName =
            (nullptr == currentExpressFrame) ?
                    "nullptr" : currentExpressFrame->getName();
    sprintf(buf,
            "onHold: %s\ntransmittingExpressFrame: %s\ntransmittingPreemptableFrame: %s\ncurrentPreemptableFrame: %s\ncurrentExpressFrame: %s",
            onHold ? "true" : "false",
            transmittingExpressFrame ? "true" : "false",
            transmittingPreemptableFrame ? "true" : "false",
            currentPreemptableFrameName, currentExpressFrameName);
    getDisplayString().setTagArg("t", 0, buf);
    getDisplayString().setTagArg("i", 1, colour);
}

bool EtherMACFullDuplexPreemptable::isFramePreemptionEnabled() {
    return par("enablePreemptingFrames");
}

}
// namespace inet

