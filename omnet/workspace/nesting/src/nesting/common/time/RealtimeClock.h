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

#ifndef NESTING_COMMON_TIME_REALTIMECLOCK_H_
#define NESTING_COMMON_TIME_REALTIMECLOCK_H_

#include <omnetpp.h>

#include <list>
#include <set>
#include <iostream>

#include "inet/common/ModuleAccess.h"

#include "nesting/common/time/IClock2.h"
#include "nesting/common/time/IOscillator.h"

using namespace omnetpp;
using namespace inet;

namespace nesting {

/**
 * TODO - Generated class
 */
class RealtimeClock : public cSimpleModule, public IClock2, public IOscillator::TickListener, public IOscillator::ConfigListener
{
protected:
    class TimestampImpl : public IClock2::Timestamp
    {
    protected:
        simtime_t localTime;
        uint64_t kind;
        IClock2::TimestampListener& listener;
    public:
        TimestampImpl(IClock2::TimestampListener& listener, simtime_t localTime, uint64_t kind);
        virtual simtime_t getLocalTime() const override;
        virtual uint64_t getKind() const override;
        virtual IClock2::TimestampListener& getListener() const;
        bool operator==(const TimestampImpl& other) const;
        bool operator!=(const TimestampImpl& other) const;
        bool operator<(const TimestampImpl& other) const;
    };
protected:
    // Friend declarations
    friend std::ostream& operator<<(std::ostream& stream, const TimestampImpl* timestamp);
    friend bool operator<(std::shared_ptr<TimestampImpl> left, std::shared_ptr<TimestampImpl> right);

    IOscillator* oscillator;
    simtime_t localTime;
    uint64_t lastTick;
    double driftRate;
    std::set<IClock2::ConfigListener*> configListeners;
    std::list<std::shared_ptr<TimestampImpl>> scheduledEvents;
    std::shared_ptr<const IOscillator::Tick> nextTick;
    /** 
     * If the clockRate + driftRate is smaller than this threshold, the clock
     * is stopped instead of running really slow to prevent numeric errors.
     */
    const double minEffectiveClockRate = 1e-12;
protected:
    virtual void initialize();
    virtual void scheduleNextTimestamp();
    virtual simtime_t timeIncrementPerTick() const;
public:
    RealtimeClock();
    virtual ~RealtimeClock();
    virtual std::shared_ptr<const IClock2::Timestamp> subscribeDelta(IClock2::TimestampListener& listener, simtime_t delta, uint64_t kind = 0) override;
    virtual std::shared_ptr<const IClock2::Timestamp> subscribeTimestamp(IClock2::TimestampListener& listener, simtime_t time, uint64_t kind = 0) override;
    virtual void unsubscribeTimestamp(IClock2::TimestampListener& listener, const IClock2::Timestamp& timestamp) override;
    virtual void subscribeConfigChanges(IClock2::ConfigListener& listener) override;
    virtual void unsubscribeConfigChanges(IClock2::ConfigListener& listener) override;
    virtual simtime_t updateAndGetLocalTime() override;
    virtual void setLocalTime(simtime_t time) override;
    virtual double getClockRate() const override;
    virtual void setClockRate(double clockRate) override;
    virtual double getDriftRate() const override;
    virtual void setDriftRate(double driftRate) override;
    virtual void onTick(IOscillator& oscillator, std::shared_ptr<const IOscillator::Tick> tick) override;
    virtual void onFrequencyChange(IOscillator& oscillator, double oldFrequency, double newFrequency) override;
    virtual bool isStopped();
};

// Useful for debugging
std::ostream& operator<<(std::ostream& stream, const RealtimeClock::TimestampImpl* timestamp);

// Required to sort timestamp events
bool operator<(std::shared_ptr<RealtimeClock::TimestampImpl> left, std::shared_ptr<RealtimeClock::TimestampImpl> right);

} //namespace

#endif
