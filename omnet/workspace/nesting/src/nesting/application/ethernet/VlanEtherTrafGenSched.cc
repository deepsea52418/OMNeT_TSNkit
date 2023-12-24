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

#include "nesting/application/ethernet/VlanEtherTrafGenSched.h"
#include "nesting/linklayer/vlan/EnhancedVlanTag_m.h"
#include "nesting/common/FlowMetaTag_m.h"

#include "inet/common/ModuleAccess.h"
#include "inet/common/InitStages.h"
#include "inet/common/packet/chunk/ByteCountChunk.h"
#include "inet/common/Protocol.h"
#include "inet/common/ProtocolTag_m.h"
#include "inet/common/TimeTag_m.h"
#include "inet/common/IProtocolRegistrationListener.h"

#include <algorithm>
#include <string.h>

namespace nesting {

Define_Module(VlanEtherTrafGenSched);

const Protocol* VlanEtherTrafGenSched::L2_PROTOCOL = &Protocol::nextHopForwarding;

VlanEtherTrafGenSched::~VlanEtherTrafGenSched() {
    // Delete self-messages for not yet sent packets
    for (std::map<cMessage*, uint64_t>::iterator it = sendEvents.begin(); it != sendEvents.end(); it++) {
        cancelAndDelete(it->first);
    }
    sendEvents.clear();
}

void VlanEtherTrafGenSched::initialize(int stage) {
    if (stage == INITSTAGE_LOCAL) {
        // Signals
        sentPkSignal = registerSignal("sentPk");
        rcvdPkSignal = registerSignal("rcvdPk");
        sentPkTreeIdSignal = registerSignal("sentPkTreeId");
        rcvdPkTreeIdSignal = registerSignal("rcvdPkTreeId");

        jitter = &par("jitter");

        WATCH_MAP(flowIdSeqNums);

        // statistics
        TSNpacketsSent = packetsReceived = 0;
        WATCH(TSNpacketsSent);
        WATCH(packetsReceived);

        cModule* clockModule = getModuleFromPar<cModule>(par("clockModule"),
                this);
        clock = check_and_cast<IClock*>(clockModule);
    } else if (stage == INITSTAGE_LINK_LAYER) {
        //clock module reference from ned parameter

        currentSchedule = std::unique_ptr < HostSchedule
                < Ieee8021QCtrl >> (new HostSchedule<Ieee8021QCtrl>());
        cXMLElement* xml = par("initialSchedule").xmlValue();
        loadScheduleOrDefault(xml);

        currentSchedule = move(nextSchedule);
        nextSchedule.reset();

        clock->subscribeTick(this, scheduleNextTickEvent() / clock->getClockRate());

        registerService(*L2_PROTOCOL, nullptr, gate("in"));
        registerProtocol(*L2_PROTOCOL, gate("out"), nullptr);
    }
}

int VlanEtherTrafGenSched::numInitStages() const {
    return INITSTAGE_LINK_LAYER + 1;
}

void VlanEtherTrafGenSched::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        sendDelayed(msg);
    } else {
        receivePacket(check_and_cast<Packet *>(msg));
    }
}

void VlanEtherTrafGenSched::sendPacket(uint64_t scheduleIndexTx) {
    // get scheduled control data
    Ieee8021QCtrl header = currentSchedule->getScheduledObject(scheduleIndexTx % currentSchedule->size());

    // If no sequence number for flow exists create one
    if (flowIdSeqNums.find(header.flowId) == flowIdSeqNums.end()) {
        flowIdSeqNums[header.flowId] = 0;
    }

    // Get and increment sequence number
    uint64_t flowId = header.flowId;
    uint64_t seqNum = flowIdSeqNums[header.flowId];
    flowIdSeqNums[header.flowId]++;

    char msgname[40];
    sprintf(msgname, "pk-%d-%d-%d", getId(), flowId, seqNum);

    // create new packet
    Packet *datapacket = new Packet(msgname, IEEE802CTRL_DATA);
    long len = currentSchedule->getSize(scheduleIndexTx % currentSchedule->size());
    auto payload = makeShared<ByteCountChunk>(B(len));
    // set creation time
    auto timeTag = payload->addTag<CreationTimeTag>();
    timeTag->setCreationTime(simTime());

    datapacket->addTagIfAbsent<PacketProtocolTag>()->setProtocol(L2_PROTOCOL);

    // create mac control info
    auto macTag = datapacket->addTag<MacAddressReq>();
    macTag->setDestAddress(header.macTag.getDestAddress());
    // create VLAN control info
    auto vlanReq = datapacket->addTag<EnhancedVlanReq>();
    vlanReq->setPcp(header.q1Tag.getPcp());
    vlanReq->setDe(header.q1Tag.getDe());
    vlanReq->setVlanId(header.q1Tag.getVID());

    // Add flow id to packet meta information
    auto flowMetaTag = payload->addTagIfAbsent<FlowMetaTag>();
    flowMetaTag->setFlowId(header.flowId);
    flowMetaTag->setSeqNum(seqNum);

    datapacket->insertAtBack(payload);

    EV_TRACE << getFullPath() << ": Send TSN packet '" << datapacket->getName()
                    << "' at time " << clock->getTime().inUnit(SIMTIME_US)
                    << endl;

    send(datapacket, "out");
    TSNpacketsSent++;
    emit(sentPkSignal, datapacket);
    emit(sentPkTreeIdSignal, datapacket->getTreeId());
}

void VlanEtherTrafGenSched::receivePacket(Packet *pkt) {
    EV_TRACE << getFullPath() << ": Received packet '" << pkt->getName()
                    << "' with length " << pkt->getByteLength() << "B at time "
                    << clock->getTime().inUnit(SIMTIME_US) << endl;

    packetsReceived++;
    emit(rcvdPkSignal, pkt);
    emit(rcvdPkTreeIdSignal, pkt->getTreeId());
    delete pkt;
}

void VlanEtherTrafGenSched::tick(IClock *clock, short kind) {
    Enter_Method("tick()");
    // When the current schedule index is 0, this means that the current
    // schedule's cycle was not started or was just finished. Therefore in this
    // case a new schedule is loaded if available.
    if (indexSchedule == currentSchedule->size() ) {
        // Load new schedule and delete the old one.
        if (nextSchedule) {
            currentSchedule = move(nextSchedule);
            nextSchedule.reset();
        }
        indexSchedule = 0;
        clock->subscribeTick(this, scheduleNextTickEvent() / clock->getClockRate());

    }
    else {
        double delay = *jitter;
        cMessage* selfMessage = new cMessage();
        // save msg in vector
        sendEvents[selfMessage] = indexSchedule;
        indexSchedule++;
        scheduleAt(simTime() + delay, selfMessage);
        clock->subscribeTick(this, scheduleNextTickEvent() / clock->getClockRate());
    }
}

void VlanEtherTrafGenSched::sendDelayed(cMessage *msg) {
    sendPacket(sendEvents[msg]);

    assert(!msg->isScheduled()); // msg shouldn't be scheduled atm
    sendEvents.erase(msg);
    delete msg;
}

/* This method returns the timeinterval between
 * the last sent frame and the frame to be sent next */
simtime_t VlanEtherTrafGenSched::scheduleNextTickEvent() {
    if (currentSchedule->size() == 0) {
        return currentSchedule->getCycle();
    } else if (indexSchedule == currentSchedule->size()) {
        return currentSchedule->getCycle()
                - currentSchedule->getTime(indexSchedule - 1);
    } else if (indexSchedule % currentSchedule->size() == 0) {
        return currentSchedule->getTime(indexSchedule);
    } else {
        return currentSchedule->getTime(indexSchedule % currentSchedule->size())
                - currentSchedule->getTime(
                        indexSchedule % currentSchedule->size() - 1);
    }
}

void VlanEtherTrafGenSched::loadScheduleOrDefault(cXMLElement* xml) {
    std::string hostName = this->getModuleByPath(par("hostModule"))->getFullName();
    HostSchedule<Ieee8021QCtrl>* schedule;
    bool realScheduleFound = false;
    //try to extract the part of the schedule belonging to this host
    for (cXMLElement* hostxml : xml->getChildren()) {
        if (strcmp(hostxml->getTagName(), "defaultcycle") != 0
                && hostxml->getAttribute("name") == hostName) {
            schedule = HostScheduleBuilder::createHostScheduleFromXML(hostxml,
                    xml);

            EV_DEBUG << getFullPath() << ": Found schedule for name "
                            << hostName << endl;

            realScheduleFound = true;
            break;
        }
    }
    //load empty schedule if there is no part that affects this host in the schedule xml
    if (!realScheduleFound) {
        cXMLElement* defaultXml = par("emptySchedule").xmlValue();
        schedule = HostScheduleBuilder::createHostScheduleFromXML(defaultXml,
                xml);
    }
    std::unique_ptr<HostSchedule<Ieee8021QCtrl>> schedulePtr(schedule);

    nextSchedule.reset();
    nextSchedule = move(schedulePtr);

}

} // namespace nesting
