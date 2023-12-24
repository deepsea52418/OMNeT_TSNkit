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

#ifndef __NESTING_VETHERTRAFGENSCHED_H
#define __NESTING_VETHERTRAFGENSCHED_H

#include <omnetpp.h>

#include "nesting/common/schedule/HostSchedule.h"
#include "nesting/common/schedule/HostScheduleBuilder.h"
#include "nesting/common/time/IClock.h"

#include "inet/applications/ethernet/EtherTrafGen.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/InitStages.h"
#include "inet/common/packet/chunk/ByteCountChunk.h"
#include "inet/common/Protocol.h"
#include "inet/common/ProtocolTag_m.h"
#include "inet/common/TimeTag_m.h"

#include <memory>
#include <random>
#include <iostream>
#include <vector>
#include <tuple>

using namespace omnetpp;
using namespace inet;

namespace nesting {

/**
 * @deprecated
 * See the NED file for a detailed description
 */
class VlanEtherTrafGenSched: public cSimpleModule, public IClockListener {
protected:

    /** Current schedule. Is never null. */
    std::unique_ptr<HostSchedule<Ieee8021QCtrl>> currentSchedule;

    /**
     * Next schedule to load after the current schedule finishes it's cycle.
     * Can be null.
     */
    std::unique_ptr<HostSchedule<Ieee8021QCtrl>> nextSchedule;

    /** Index for the current entry in the schedule. */
    uint64_t indexSchedule = 0;

    IClock *clock;

    // receive statistics
    uint64_t TSNpacketsSent = 0;
    uint64_t packetsReceived = 0;
    simsignal_t sentPkSignal;
    simsignal_t rcvdPkSignal;
    simsignal_t sentPkTreeIdSignal;
    simsignal_t rcvdPkTreeIdSignal;

    /**
     * Keeps track of scheduled send events with their respective schedule index
     */
    std::map<cMessage*, uint64_t> sendEvents;

    /** Sequence numbers for every flow id. */
    std::map<uint64_t, uint64_t> flowIdSeqNums;

    cPar* jitter;

protected:
    virtual void initialize(int stage) override;
    virtual void sendPacket(uint64_t scheduleIndexTx);
    virtual void receivePacket(Packet *msg);
    virtual void handleMessage(cMessage *msg) override;
    virtual void sendDelayed(cMessage *msg);

    virtual int numInitStages() const override;
    virtual simtime_t scheduleNextTickEvent();
public:
    /**
     * Arbitrary L2 protocol from inet::ProtocolGroup::ethertype, so that the
     * EtherEncap module will encapsulate frames in Ethernet2 format.
     */
    static const Protocol* L2_PROTOCOL;

    virtual void tick(IClock *clock, short kind) override;

    ~VlanEtherTrafGenSched();

    /** Loads a new schedule into the gate controller. */
    virtual void loadScheduleOrDefault(cXMLElement* xml);
};

} // namespace nesting

#endif /* __NESTING_VETHERTRAFGENSCHED_H */
