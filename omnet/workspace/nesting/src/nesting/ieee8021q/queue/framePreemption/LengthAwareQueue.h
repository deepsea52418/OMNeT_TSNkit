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

#ifndef __MAIN_LENGTHAWAREQUEUE_H_
#define __MAIN_LENGTHAWAREQUEUE_H_

#include <omnetpp.h>
#include <list>

#include "inet/common/ModuleAccess.h"

#include "nesting/ieee8021q/Ieee8021q.h"
#include "nesting/ieee8021q/queue/transmissionSelectionAlgorithms/TSAlgorithm.h"
#include "nesting/ieee8021q/queue/framePreemption/IPreemptableQueue.h"

using namespace omnetpp;
using namespace inet;

namespace nesting {

class TSAlgorithm;

/**
 * See the NED file for a detailed description.
 */
class LengthAwareQueue: public cSimpleModule, public IPreemptableQueue {
protected:
    /**
     * Reference to transmission-selection-algorithm module
     */
    TSAlgorithm* tsAlgorithm;

    /**
     * Available buffer capacity in Bits.
     */
    long availableBufferCapacity;

    /**
     * True if frame preemption is enabled, false otherwise.
     */
    bool framePreemptionEnabled;

    bool expressQueue;

    long numPacketsReceived = 0;

    long numPacketsDropped = 0;

    long numPacketsEnqueued = 0;

    uint64_t maxTransmittableBits = 0;

    /**
     * Internal queue datastructure.
     */
    cQueue queue;

    /**
     * Output gate reference.
     */
    cGate *outGate;

    cMessage requestPacketMsg = cMessage("requestPacket");

    simsignal_t rcvdPkSignal;
    simsignal_t enqueuePkSignal;
    simsignal_t dequeuePkSignal;
    simsignal_t dropPkByQueueSignal;
    simsignal_t queueingTimeSignal;
    simsignal_t queueLengthSignal;

protected:
    virtual void initialize() override;

    virtual void handleMessage(cMessage* msg) override;

    virtual void enqueue(cPacket* packet);

    virtual cPacket* dequeue();

    virtual void handleRequestPacketEvent(uint64_t maxBits);

    virtual void handlePacketEnqueuedEvent(cPacket* packet);

public:
    virtual ~LengthAwareQueue();

    virtual bool isEmpty(uint64_t maxBits);

    virtual void requestPacket(uint64_t maxBits);

    virtual bool isExpressQueue();
};

} // namespace nesting

#endif
