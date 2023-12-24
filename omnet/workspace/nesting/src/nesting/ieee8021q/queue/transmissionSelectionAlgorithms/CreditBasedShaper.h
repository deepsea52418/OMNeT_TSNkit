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

#ifndef __MAIN_CREDITBASEDSHAPER_H_
#define __MAIN_CREDITBASEDSHAPER_H_

#include <omnetpp.h>

#include "inet/common/ModuleAccess.h"
#include "inet/common/packet/Packet.h"

#include "nesting/ieee8021q/Ieee8021q.h"
#include "nesting/ieee8021q/queue/transmissionSelectionAlgorithms/TSAlgorithm.h"

using namespace omnetpp;

namespace nesting {

/**
 * See the NED file for a detailed description.
 */
class CreditBasedShaper: public TSAlgorithm {
protected:
    /**
     * Enumeration to represent the internal state of the credit-based-shaper
     * transmission selection algorithm. The state can be 
     * (1) earning credits: gate open AND (packet queued OR neg credit)
     * (2) spending credits: transmitting
     * (3) staying idle: no packet OR gate closed
     */
    enum State {
        kEarnCredit, kSpendCredit, kIdle
    };

    /**
     * The rate of change of credit as factor of the transmission rate of the
     * Mac module.
     */
    double idleSlopeFactor;

    /**
     * Credit balance.
     */
    double credit;

    /**
     * Internal state.
     */
    State state;

    /**
     * Time-stamp when the last state change was performed. This value is used
     * to calculate e.g. earned credits.
     */
    simtime_t lastEventTimestamp;

    /**
     * Self message used to signal the end of a credit spending period.
     */
    cMessage endSpendingCreditMessage = cMessage("endSpendingCredit");

    /**
     * Self message used to signal that zero credits are reached. This is
     * necessary because reaching a positive amount of credits can trigger a
     * packet-enqueued event subsequent queuing components.
     */
    cMessage reachedZeroCreditMessage = cMessage("reachedZeroCredit");

    /** @copydoc cSimpleModule::initialize() */
    virtual void initialize() override;

    /** @copydoc cSimpleModule::handleMessage(cMessage*) */
    virtual void handleMessage(cMessage* msg) override;

    /** @copydoc cSimpleModule::refreshDisplay() const */
    virtual void refreshDisplay() const override;

    /** This method calculates the idleSlope value in credits per second. */
    virtual double getIdleSlope();

    /** This method calculates the sendSlope value in credits per second. */
    virtual double getSendSlope();

    /**
     * This method returns the associated Mac port transmit rate in bits per
     * second.
     */
    virtual double getPortTransmitRate();

    /**
     * For a given credit rate per second and a given time interval, this
     * method calculates the associated amount of credits.
     *
     * @param creditPerSecond The rate of earned/spend credit in credits
     *                        per second. This value must be greater than
     *                        zero.
     * @param time            The time interval to calculate the earned/spend
     *                        credits for. This value must be greater or equal
     *                        than zero.
     * @return                The amount of credit earned/generated.
     */
    virtual double creditsForTime(double creditPerSecond, simtime_t time);

    /**
     * For a given credit earning/spending rate in credits per second and a
     * given amount of credits. This method calculates how long it takes to
     * spend/accumulate the amount of credit.
     *
     * @param creditPerSecond The rate of earned/spend credit in credits
     *                        per second. This value must be greater than
     *                        zero.
     * @param credit          The amount of credit to earn/spend.
     * @result                The time interval that is needed to earn/spend
     *                        the given amount of credit.
     */
    virtual simtime_t timeForCredits(double creditPerSecond, double credit);

    /**
     * Returns the time needed to earn enough credits to reach zero or rather a
     * positive amount of credit.
     */
    virtual simtime_t zeroCreditTime();

    /** Calculates the time needed to transmit a packet. */
    virtual simtime_t transmissionTime(Packet* packet);

    /** Transitions the module into a new state. */
    virtual void updateState(State newState);

    /** Spend the necessary amount of credit for a given packet to transmit. */
    virtual void spendCredit(Packet* packet);

    /** Earn the amount of credits respective to a given time interval. */
    virtual void earnCredits(simtime_t time);

    /** Resets credit to zero. */
    virtual void resetCredit();

    /** Returns true if credit is greater or equal to zero. */
    virtual bool isCreditPositive();

    /**
     * Returns true if a packet is ready for transmission on the input queue.
     */
    virtual bool isPacketReadyForTransmission();

    /**
     * Handle state changes and triggering events due to gate change events.
     */
    virtual void handleGateStateChangedEvent() override;

    /**
     * Handle state changes and triggering events after new packets to transmit
     * become available.
     */
    virtual void handlePacketEnqueuedEvent() override;

    /**
     * Handle state changes and triggering events due to transmitting packets.
     */
    virtual void handleSendPacketEvent(Packet* packet);

    /**
     * Handle state changes and triggering events after finishing spending
     * credit.
     */
    virtual void handleEndSpendingCreditEvent();

    /**
     * Handle state changes and triggering events after acquiring zero credits
     * and therefore becoming able to transmit packets.
     */
    virtual void handleZeroCreditReachedEvent();

public:
    ~CreditBasedShaper();

    virtual bool isEmpty(uint64_t maxBits) override;
};

} // namespace nesting

#endif
