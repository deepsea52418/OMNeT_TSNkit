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

#ifndef __MAIN_TRANSMISSIONSELECTION_H_
#define __MAIN_TRANSMISSIONSELECTION_H_

#include <omnetpp.h>
#include <vector>
#include <algorithm>

#include "nesting/ieee8021q/queue/gating/TransmissionGate.h"

#include "inet/common/queue/IPassiveQueue.h"

using namespace omnetpp;
using namespace inet;

namespace nesting {

class TransmissionGate;

/**
 * See the NED file for a detailed description.
 */
class TransmissionSelection: public IPassiveQueue, public cSimpleModule {
protected:
    /**
     * This data-structure keeps references to the transmission-gates that
     * serve as input modules. The gate with the highest index is the highest
     * priority gate as well as the the gate with the lowest index is the one
     * with the lowest priority.
     */
    std::vector<TransmissionGate*> tGates;

    /**
     * This vector keeps references to listeners that are notified about
     * packet-enqueued-events. In the default case this should be the Mac
     * module.
     */
    std::vector<IPassiveQueueListener*> listeners;

    /**
     * This flag is set if a packet is requested from this module by the
     * requestPacket method and again set to false when a packet is send out
     * on the out-gate.
     */
    bool packetRequestedFromUs = false;

    /**
     * This flag is set if a packet is requested from one of the input modules
     * (TransmissionGates) and again set to false if a packet is received on
     * the in-gate.
     */
    bool packetRequestedFromInputs = false;

    /**
     * Set a lower scheduling priority for self-messages than the default
     * value of zero. It is important, that internal events when concurrently
     * scheduled with other events within the queuing network are handled in
     * the end, after all events and successor events that eventually trigger
     * a packetEnqueued-method call are handled.
     */
    int selfMessageSchedulingPriority = 1;

    /**
     * This message is used as a self-message to trigger a request-packet-
     * event after a packet is requested from this module.
     */
    cMessage requestPacketMsg = cMessage("requestPacket");

    /**
     * This message is used as a self-message to trigger packet-enqueued-events
     * due to a packet being enqueued in one of the input modules.
     */
    cMessage packetEnqueuedMsg = cMessage("packetEnqueued");

protected:
    /**
     * @see cSimpleModule::initialize()
     */
    virtual void initialize() override;

    /**
     * @see cSimpleModule::handleMessage(cMessage*)
     */
    virtual void handleMessage(cMessage* msg) override;

    /**
     * @see cSimpleModule::refreshDisplay() const
     */
    virtual void refreshDisplay() const override;

    /**
     * This method tries to request a packet from the highest priority input
     * module (transmission gate). If no packet is available for transmission,
     * no packet is requested.
     *
     * @return True if a packet was requested, false otherwise.
     */
    virtual bool schedulePacket();

    /**
     * This method handles a request-packet-event. This means possibly
     * requesting a packet from one of the input modules or if that is not
     * possible setting an internal flag to be able to respond to the packet
     * request at a later point in time.
     */
    virtual void handleRequestPacketEvent();

    /**
     * This method
     */
    virtual void handlePacketEnqueuedEvent();

    /**
     * Notifies listeners that a packet is became ready for transmission.
     */
    virtual void notifyPacketEnqueued();

public:
    TransmissionSelection();

    virtual ~TransmissionSelection();

    /**
     * This method is called by an transmission-gate-input-module to signal
     * that a packet became ready for transmission.
     */
    virtual void packetEnqueued(TransmissionGate* transmissioGate);

    /**
     * @see IPassiveQueue::requestPacket()
     */
    virtual void requestPacket() override;

    /**
     * @see IPassiveQueue::getNumPendingRequests()
     */
    virtual int getNumPendingRequests() override;

    /**
     * @see IPassiveQueue::isEmpty()
     */
    virtual bool isEmpty() override;

    /**
     * @see IPassiveQueue::clear()
     */
    virtual void clear() override;

    /**
     * @see IPassiveQueue::pop()
     */
    virtual cMessage *pop() override;

    /**
     * @see IPassiveQueue::addListener(IPassiveQueueListener*)
     */
    virtual void addListener(IPassiveQueueListener *listener) override;

    /**
     * @see IPassiveQueue::removeListener(IPassiveQueueListener*)
     */
    virtual void removeListener(IPassiveQueueListener *listener) override;

    virtual bool hasExpressPacketEnqueued();

    virtual void removePendingRequests();
};

} // namespace nesting

#endif
