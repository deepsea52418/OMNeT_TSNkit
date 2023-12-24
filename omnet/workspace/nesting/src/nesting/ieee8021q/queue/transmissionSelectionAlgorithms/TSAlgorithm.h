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

#ifndef NESTING_IEEE8021Q_QUEUE_TRANSMISSIONSELECTIONALGORITHMS_TSALGORITHM_H_
#define NESTING_IEEE8021Q_QUEUE_TRANSMISSIONSELECTIONALGORITHMS_TSALGORITHM_H_

#include "omnetpp.h"

#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/ethernet/EtherMacBase.h"

#include "nesting/ieee8021q/queue/gating/TransmissionGate.h"
#include "nesting/ieee8021q/queue/framePreemption/LengthAwareQueue.h"
#include "nesting/ieee8021q/queue/framePreemption/IPreemptableQueue.h"

using namespace omnetpp;
using namespace inet;

namespace nesting {

class TransmissionGate;
class LengthAwareQueue;

/**
 * See the NED file for a detailed description.
 */
class TSAlgorithm: public cSimpleModule, public IPreemptableQueue {
protected:
    /**
     * Reference to the Mac module.
     */
    EtherMacBase* mac;

    /**
     * Reference to the length-aware input queue module.
     */
    LengthAwareQueue* queue;

    /**
     * Reference to the transmission-gate module.
     */
    TransmissionGate* transmissionGate;

    cMessage packetEnqueuedMsg = cMessage("packetEnqueued");

    cMessage gateStateChangedMsg = cMessage("gateStateChanged");

    cMessage requestPacketMsg = cMessage("requestPacket");

    uint64_t maxTransmittableBits;
protected:
    /**
     * @see cMessage::initialize()
     */
    virtual void initialize() override;

    /**
     * @see cMessage::handleMessage(cMessage*)
     */
    virtual void handleMessage(cMessage* msg) override;

    virtual void handlePacketEnqueuedEvent();

    virtual void handleGateStateChangedEvent();

    virtual void handleRequestPacketEvent(uint64_t maxBits);

public:
    virtual ~TSAlgorithm();

    virtual void gateStateChanged();

    virtual void packetEnqueued();

    virtual bool isEmpty(uint64_t maxBits);

    virtual void requestPacket(uint64_t maxBits);

    virtual bool isExpressQueue();

};

} /* namespace nesting */

#endif /* NESTING_IEEE8021Q_QUEUE_TRANSMISSIONSELECTIONALGORITHMS_TSALGORITHM_H_ */
