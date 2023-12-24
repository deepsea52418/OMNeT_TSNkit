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

#include "nesting/ieee8021q/queue/transmissionSelectionAlgorithms/CreditBasedShaper.h"

namespace nesting {

Define_Module(CreditBasedShaper);

CreditBasedShaper::~CreditBasedShaper() {
    cancelEvent(&endSpendingCreditMessage);
    cancelEvent(&reachedZeroCreditMessage);
}

void CreditBasedShaper::initialize() {
    TSAlgorithm::initialize();

    // Initialize credit value
    credit = 0;
    WATCH(credit);

    // Initialize idle slope value
    idleSlopeFactor = par("idleSlopeFactor");
    WATCH(idleSlopeFactor);
    if (idleSlopeFactor <= 0 || idleSlopeFactor >= 1) {
        throw cRuntimeError(
                "Value of idleSlope for credit-based-shaper must be in the range (0,1)");
    }

    // Initialize state
    updateState(kIdle);
}

void CreditBasedShaper::handleMessage(cMessage* msg) {
    if (msg->isSelfMessage()) {
        if (msg == &endSpendingCreditMessage) {
            handleEndSpendingCreditEvent();
        } else if (msg == &reachedZeroCreditMessage) {
            handleZeroCreditReachedEvent();
        } else {
            TSAlgorithm::handleMessage(msg);
        }
    } else {
        Packet* packet = check_and_cast<Packet*>(msg);
        handleSendPacketEvent(packet);
        send(packet, "out");
    }
}

void CreditBasedShaper::refreshDisplay() const {
    char buf[80];
    sprintf(buf, "credit-based\ncredit: %d", static_cast<int>(credit));
    getDisplayString().setTagArg("t", 0, buf);
}

double CreditBasedShaper::getIdleSlope() {
    return idleSlopeFactor * getPortTransmitRate();
}

double CreditBasedShaper::getSendSlope() {
    return getPortTransmitRate() - getIdleSlope();
}

double CreditBasedShaper::getPortTransmitRate() {
    return mac->getTxRate();
}

double CreditBasedShaper::creditsForTime(double creditPerSecond,
        simtime_t time) {
    assert(creditPerSecond > 0);
    assert(time >= SimTime::ZERO);
    double timeInSeconds = time / SimTime(1, SIMTIME_S);
    return timeInSeconds * creditPerSecond;

}

simtime_t CreditBasedShaper::timeForCredits(double creditPerSecond,
        double credit) {
    assert(creditPerSecond > 0);
    assert(credit >= 0);

    double seconds = credit / creditPerSecond;
    return seconds * SimTime(1, SIMTIME_S);
}

simtime_t CreditBasedShaper::zeroCreditTime() {
    assert(credit < 0);
    return simTime() + timeForCredits(getIdleSlope(), 0 - credit);
}

simtime_t CreditBasedShaper::transmissionTime(Packet* packet) {
    
    /*
     * TODO!
     * Check whether hard-coded numbers are correct, or whether they can be replaced
     * by call to packet-method.
     * If applicable, replace remaining hard-coded number, e.g., in spendCredit() 
     * for reference, see IEEE Std. 802.3, Sec. 3.1.1 Packet format / Fig. 3.1
     * (p. 118 in 802.3-2018)
     */

    // Ieee8021q::getFinalEthernet2FrameBitLength(packet) is somehow wrong (1704B instead of correctly 1521B + 8B PHY + IFG)
    int lengthInBits = packet->getBitLength() + (21 + 8 + 12) * 8;
    simtime_t transmissionTime = timeForCredits(getPortTransmitRate(), lengthInBits);
    return transmissionTime;
}

void CreditBasedShaper::updateState(State newState) {
    state = newState;
    lastEventTimestamp = simTime();

    EV_DEBUG << getFullPath() << ": New state: [state=";
    switch (state) {
    case kIdle:
        EV_DEBUG << "idle";
        break;
    case kSpendCredit:
        EV_DEBUG << "spendCredit";
        break;
    case kEarnCredit:
        EV_DEBUG << "earnCredit";
        break;
    }
    EV_DEBUG << ",credit=" << credit << "]" << endl;
}

void CreditBasedShaper::spendCredit(Packet* packet) {
    double spendCredit = creditsForTime(getSendSlope(), transmissionTime(packet));
    credit -= spendCredit;

    EV_DEBUG << getFullPath() << ": Spending " << spendCredit << " credit for " << packet->getBitLength() << " bits payload." << endl;
    EV_WARN << getFullPath() << ": Spending " << spendCredit << " credit = "
        << packet->getByteLength() + (21 + 8 + 12) << "B / " << getSendSlope() << " slope" << endl;
}

void CreditBasedShaper::earnCredits(simtime_t time) {
    double earnedCredit = creditsForTime(getIdleSlope(), time);
    credit += earnedCredit;

    EV_DEBUG << getFullPath() << ": Earned " << earnedCredit << " credit." << endl;
    EV_WARN << getFullPath() << ": Earned " << earnedCredit << " credit = " << time << " time * " << getIdleSlope() << " slope" << endl;
}

void CreditBasedShaper::resetCredit() {
    credit = 0;

    EV_DEBUG << getFullPath() << ": Resetted credit." << endl;
}

bool CreditBasedShaper::isCreditPositive() {
    return credit >= 0.0;
}

bool CreditBasedShaper::isPacketReadyForTransmission() {
    uint64_t mtuSize = kEthernet2MaximumTransmissionUnitBitLength.get();
    return !queue->isEmpty(mtuSize);
}

void CreditBasedShaper::handleGateStateChangedEvent() {
    if (transmissionGate->isGateOpen()) {
        assert(state != kEarnCredit);
        EV_TRACE << getFullPath() << ": Handle gate opened event." << endl;
        if (state == kIdle && !isCreditPositive()) {
            EV_DEBUG << getFullPath() << ": Credit negative." << endl;
            EV_DEBUG << getFullPath() << ": Zero credit scheduled for " << zeroCreditTime() << "(+" << timeForCredits(getIdleSlope(), 0 - credit) << ")" << endl;
            updateState(kEarnCredit);
            scheduleAt(zeroCreditTime(), &reachedZeroCreditMessage);
            // if isPacketReadyForTransmission() handle in reachedZeroCredit
        }
        else if (state == kIdle && isPacketReadyForTransmission()) { // credit is positive
            updateState(kEarnCredit);
            // if isPacketReadyForTransmission() packet was already enqueued.
        }
    } else {
        EV_TRACE << getFullPath() << ": Handle gate closed event." << endl;
        if (state == kEarnCredit) {
            cancelEvent(&reachedZeroCreditMessage);
            earnCredits(simTime() - lastEventTimestamp);
            updateState(kIdle);
        }
    }
    // if kSpendCredit: do nothing, handle in handleEndSpendingCreditEvent
}

void CreditBasedShaper::handlePacketEnqueuedEvent() {
    assert(isPacketReadyForTransmission());

    EV_TRACE << getFullPath() << ": Handle packet enqueued event." << endl;

    if (state == kIdle && transmissionGate->isGateOpen()) { // queue was empty
        updateState(kEarnCredit);
        assert(isCreditPositive());
        transmissionGate->packetEnqueued();
    }
}

void CreditBasedShaper::handleSendPacketEvent(Packet* packet) {
    assert(state == kEarnCredit);
    assert(isCreditPositive());
    assert(!reachedZeroCreditMessage.isScheduled());

    EV_TRACE << getFullPath() << ": Handle send packet event." << endl;

    earnCredits(simTime() - lastEventTimestamp);
    updateState(kSpendCredit);
    spendCredit(packet);

    EV_DEBUG << getFullPath() << ": handleEndSpendingCreditEvent scheduled for " << simTime() + transmissionTime(packet) << "(+" << transmissionTime(packet) << ")" << endl;
    scheduleAt(simTime() + transmissionTime(packet), &endSpendingCreditMessage);
}

void CreditBasedShaper::handleEndSpendingCreditEvent() {
    assert(state == kSpendCredit);

    EV_TRACE << getFullPath() << ": Handle end spending credit event." << endl;

    if (!transmissionGate->isGateOpen()){
        EV_DEBUG << getFullPath() << ": Gate not open." << endl;
        updateState(kIdle);
    }
    else if (!isCreditPositive()){
        EV_DEBUG << getFullPath() << ": Credit negative." << endl;
        EV_DEBUG << getFullPath() << ": Zero credit scheduled for " << zeroCreditTime() << "(+" << timeForCredits(getIdleSlope(), 0 - credit) << ")" << endl;
        updateState(kEarnCredit);
        scheduleAt(zeroCreditTime(), &reachedZeroCreditMessage);
    }
    else if (!isPacketReadyForTransmission()) {
        EV_DEBUG << getFullPath() << ": Queue empty." << endl;
        updateState(kIdle);
        resetCredit();
    } 
    else { // open positive ready => send
        EV_DEBUG << getFullPath() << ": Ready to transmit." << endl;
        updateState(kEarnCredit);
        transmissionGate->packetEnqueued();
    }
}

void CreditBasedShaper::handleZeroCreditReachedEvent() {
    assert(state == kEarnCredit);
    assert(transmissionGate->isGateOpen());

    EV_TRACE << getFullPath() << ": Handle zero credit reached event." << endl;

    earnCredits(simTime() - lastEventTimestamp);
    EV_WARN << getFullPath() << ": credit " << credit << " isCreditPositive " << isCreditPositive() << endl;
    assert(credit >= - 0.1); // allowed rounding error
    resetCredit();

    if (isPacketReadyForTransmission()) {
        EV_DEBUG << getFullPath() << ": Ready to transmit." << endl;
        updateState(kEarnCredit);
        transmissionGate->packetEnqueued();
    }
    else { // queue empty
        EV_DEBUG << getFullPath() << ": Queue empty." << endl;
        updateState(kIdle);
        resetCredit();
    } 
}

bool CreditBasedShaper::isEmpty(uint64_t maxBits) {
    return !isCreditPositive() || queue->isEmpty(maxBits);
}

} // namespace nesting
