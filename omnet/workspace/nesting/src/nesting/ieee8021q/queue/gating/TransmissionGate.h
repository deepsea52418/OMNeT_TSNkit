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

#ifndef __MAIN_TRANSMISSIONGATE_H_
#define __MAIN_TRANSMISSIONGATE_H_

#include <omnetpp.h>
#include <list>
#include <algorithm>

#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/ethernet/EtherMacFullDuplex.h"
#include "inet/common/packet/Packet.h"

#include "nesting/common/time/IClock.h"
#include "nesting/ieee8021q/queue/TransmissionSelection.h"
#include "nesting/ieee8021q/queue/transmissionSelectionAlgorithms/TSAlgorithm.h"
#include "nesting/ieee8021q/queue/gating/GateController.h"
#include "nesting/ieee8021q/queue/framePreemption/IPreemptableQueue.h"

using namespace omnetpp;

namespace nesting {

class GateController;
class TransmissionSelection;
class TSAlgorithm;

/**
 * See the NED file for a detailed description
 */
class TransmissionGate: public cSimpleModule, public IPreemptableQueue {
private:
    /**
     * Reference to the gate-controller module.
     */
    GateController* gateController;

    /**
     * Reference to the transmission-selection module. Packet-enqueued events
     * are signaled to this module whenever a packet becomes ready for
     * transmission.
     */
    TransmissionSelection* transmissionSelection;

    /**
     * Reference to the transmission-selection-algorithm-module which is the
     * input module where packets are requested from.
     */
    TSAlgorithm* tsAlgorithm;

    /**
     * Clock reference, needed to get the current time
     */
    IClock* clock;

    /**
     * If length-aware-scheduling is disabled, the transmission gate module
     * will only request packets up to ethernet2 MTU size from the input module,
     * which means every packet ready for transmission is fine.
     *
     * If length-aware-scheduling is enabled, the maximum size of requested
     * packet is equivalent on how many bits will fit through the gate before
     * it will close.
     */
    bool lengthAwareSchedulingEnabled;

    /**
     * Open state of gate. If the gate is open, packets can go through this
     * module. Otherwise they can't.
     */
    bool gateOpen = true;

    /**
     * Self-message to trigger internal request-packet event.
     */
    cMessage requestPacketMsg = cMessage("requestPacket");

    /**
     * Self-message to trigger internal packet-enqueued event.
     */
    cMessage packetEnqueuedMsg = cMessage("packetEnqueued");

    /**
     * Self-message to trigger internal gate-state-changed event.
     */
    cMessage gateStateChangedMsg = cMessage("gateStateChanged");

protected:

    simsignal_t gateStateChangedSignal;

    /*
     * @see cSimpleModule::initialize()
     */
    virtual void initialize() override;

    /**
     * @see cSimpleModule::handleMessage(cMessage*)
     */
    virtual void handleMessage(cMessage* msg) override;
    /**
     * @see cSimpleModule::refreshDisplay()
     */
    virtual void refreshDisplay() const override;

    /**
     * Notifies the output module (transmission-selection), that a packet
     * became ready for transmission.
     */
    virtual void notifyPacketEnqueued();

    /**
     * Notifies the input module (transmission-selection-algorithm), that the
     * gate-open state changed.
     */
    virtual void notifyGateStateChanged();

    virtual void handleRequestPacketEvent();

    virtual void handlePacketEnqueuedEvent();

    virtual void handleGateStateChangedEvent();

    /**
     * Calculates the maximum amount of transferable bits until the gate
     * closes. If length-aware-scheduling is disabled, ethernet2 MTU size is
     * returned.
     */
    virtual uint64_t maxTransferableBits();
public:
    ~TransmissionGate();

    /**
     * Returns true if gate is opened, false otherwise.
     */
    virtual bool isGateOpen();

    /**
     * Sets new gate state.
     */
    virtual void setGateState(bool gateOpen, bool release);

    /**
     * Tells if the gate is empty from a queuing perspective.
     */
    virtual bool isEmpty();

    /**
     * Requests a packet from this module. If a packet is requested even tough
     * there is no packet ready for transmission, an error is thrown.
     */
    virtual void requestPacket();

    /**
     * Notifies the transmission-gate, that a packet got ready for transmission
     * on the input module.
     */
    virtual void packetEnqueued();

    virtual bool isExpressQueue();
};

} // namespace nesting

#endif
