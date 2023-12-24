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

#ifndef NESTING_COMMON_TIME_OSCILLATORBASE_H_
#define NESTING_COMMON_TIME_OSCILLATORBASE_H_

#include <omnetpp.h>

#include <list>
#include <cstdint>
#include <iostream>
#include <memory>
#include <set>
#include <functional>

#include "nesting/common/time/IOscillator.h"

using namespace omnetpp;

namespace nesting {

/** Implementation of an oscillator module without drift or jitter. */
class OscillatorBase : public cSimpleModule, public IOscillator
{
protected:
    class TickImpl : public Tick {
    protected:
        TickListener& listener;

        uint64_t tick;

        uint64_t kind;

        simtime_t globalSchedulingTime;
    public:
        TickImpl(TickListener& listener, uint64_t tick, uint64_t kind, simtime_t globalSchedulingTime);

        TickImpl(TickListener& listener, const Tick& tickEvent);

        virtual ~TickImpl();

        /** @copydoc Tick::getListener() */
        virtual TickListener& getListener() const;

        virtual void setListener(TickListener& listener);

        /** @copydoc Tick::getTick() */
        virtual uint64_t getTick() const override;

        virtual void setTick(uint64_t tick);

        /** @copydoc Tick::getKind() */
        virtual uint64_t getKind() const override;

        virtual void setKind(uint64_t kind);

        /** @copydoc Tick::getGlobalSchedulingTime() */
        virtual simtime_t getGlobalSchedulingTime() const override;

        virtual void setGlobalSchedulingTime(simtime_t globalSchedulingTime);

        bool operator<(const TickImpl& tickEvent) const;

        bool operator==(const TickImpl& tickEvent) const;

        bool operator!=(const TickImpl& tickEvent) const;
    };
protected:
    // Friend declarations
    friend std::ostream& operator<<(std::ostream& stream, const OscillatorBase::TickImpl* tickEvent);
    friend bool operator<(std::shared_ptr<OscillatorBase::TickImpl> left, std::shared_ptr<OscillatorBase::TickImpl> right);

    /** Flag that is set to true mid tick event. */
    bool tickEventNow;

    /** Tick rate of the oscillator module in seconds. */
    double frequency;

    /** Number/Index of last tick. */
    uint64_t lastTick;

    /** Global simulation time when the last tick event was scheduled. */
    simtime_t timeOfLastTick;

    /**
     * Event queue that contains the scheduled tick events. Events are kept in
     * order to allow the use of binary search for fast lookups.
     */
    std::list<std::shared_ptr<TickImpl>> scheduledEvents;

    std::set<ConfigListener*> configListeners;

    /** Used as self message to notify the component of the next tick event */
    cMessage tickMessage;
public:
    OscillatorBase();

    virtual ~OscillatorBase();

    /** @copydoc subscribeTick(TickListener&, uint64_t, uint64_t) */
    virtual std::shared_ptr<const Tick> subscribeTick(TickListener& listener, uint64_t idleTicks, uint64_t kind) override;

    virtual std::shared_ptr<const Tick> subscribeTick(TickListener& listener, uint64_t idleTicks) override;

    /** @copydoc unsubscribeTick() */
    virtual void unsubscribeTick(TickListener& listener, const Tick& tick) override;

    /** @copydoc unsubscribeTicks(IOscillatorListener*, uint64_t) */
    virtual void unsubscribeTicks(TickListener& listener, uint64_t kind) override;

    /** @copydoc unsubscribeTicks(IOscillatorListener*) */
    virtual void unsubscribeTicks(TickListener& listener) override;

    /** @copydoc isScheduled() */
    virtual bool isTickScheduled(TickListener& listener, const Tick& tickEvent) const override;

    /** @copydoc getFrequency() */
    virtual double getFrequency() const override;

    /** @copydoc setFrequency() */
    virtual void setFrequency(double frequency) override;

    /** @copydoc updateAndGetTickCount() */
    virtual uint64_t updateAndGetTickCount() override;

    /** @copydoc subscribeConfigChanges() */
    virtual void subscribeConfigChanges(ConfigListener& listener) override;

    /** @copydoc unsubscribeConfigChanges() */
    virtual void unsubscribeConfigChanges(ConfigListener& listener) override;
protected:
    virtual void initialize() override;

    virtual void finish() override;

    virtual void handleMessage(cMessage *msg) override;

    virtual simtime_t tickInterval() const;

    /**
     * Schedules a self-message so the component is notified about the next
     * event in the event-queue. Reschedules an already existent self-message
     * if required.
     *
     * This method should be called after every update to the event queue.
     */
    virtual void scheduleNextTick();

    virtual simtime_t globalTimeFromTick(uint64_t idleTicks) = 0;

    virtual uint64_t tickFromGlobalTime(simtime_t globalTime) = 0;
};

// Useful for logging oscillator ticks
std::ostream& operator<<(std::ostream& stream, const OscillatorBase::TickImpl* tickEvent);

// Used to keep oscillator ticks sorted
bool operator<(std::shared_ptr<OscillatorBase::TickImpl> left, std::shared_ptr<OscillatorBase::TickImpl> right);

} //namespace nesting

#endif
