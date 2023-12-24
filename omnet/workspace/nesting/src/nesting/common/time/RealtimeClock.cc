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

#include "nesting/common/time/RealtimeClock.h"

#include <cmath>
#include <algorithm>

namespace nesting {

Define_Module(RealtimeClock);

RealtimeClock::RealtimeClock()
    : oscillator(nullptr)
    , localTime(SimTime(0.0))
    , nextTick(nullptr)
    , driftRate(0.0)
    , lastTick(0)
{
}

RealtimeClock::~RealtimeClock()
{
}

void RealtimeClock::initialize()
{
    oscillator = getModuleFromPar<IOscillator>(par("oscillatorModule"), this);
    oscillator->subscribeConfigChanges(*this);
    lastTick = oscillator->updateAndGetTickCount();

    WATCH(localTime);
    WATCH(driftRate);
    WATCH(lastTick);
    WATCH_LIST(scheduledEvents);
}

void RealtimeClock::scheduleNextTimestamp()
{
    // Cancel next tick.
    if (nextTick != nullptr) {
        oscillator->unsubscribeTick(*this, *nextTick);
        nextTick = nullptr;
    }

    // We only have to schedule the next timestamp if the event queue isn't empty
    if (!scheduledEvents.empty() && !isStopped()) {
        std::shared_ptr<TimestampImpl>& nextTimestamp = scheduledEvents.front();
        simtime_t idleTime = nextTimestamp->getLocalTime() - updateAndGetLocalTime();
        // We have to round up to the next highest tick
        uint64_t idleTicks = static_cast<uint64_t>(std::ceil(idleTime / timeIncrementPerTick()));
        nextTick = oscillator->subscribeTick(*this, idleTicks);
    }
}

simtime_t RealtimeClock::timeIncrementPerTick() const
{
    return SimTime(1, SIMTIME_S) / (oscillator->getFrequency() + driftRate);
}

std::shared_ptr<const IClock2::Timestamp> RealtimeClock::subscribeDelta(IClock2::TimestampListener& listener, simtime_t delta, uint64_t kind)
{
    Enter_Method_Silent();
    simtime_t currentTime = updateAndGetLocalTime();
    simtime_t eventTime = currentTime + delta;
    return subscribeTimestamp(listener, eventTime, kind);
}

std::shared_ptr<const IClock2::Timestamp> RealtimeClock::subscribeTimestamp(IClock2::TimestampListener& listener, simtime_t eventTime, uint64_t kind)
{
    Enter_Method_Silent();
    std::shared_ptr<TimestampImpl> event = std::make_shared<TimestampImpl>(listener, eventTime, kind);
    std::list<std::shared_ptr<TimestampImpl>>::iterator it = std::lower_bound(scheduledEvents.begin(), scheduledEvents.end(), event);
    if (it == scheduledEvents.end() || **it != *event) {
        scheduledEvents.insert(it, event);
    } else {
        event = *it;
    }
    scheduleNextTimestamp();
    return event;
}

void RealtimeClock::unsubscribeTimestamp(IClock2::TimestampListener& listener, const IClock2::Timestamp& timestamp)
{
    Enter_Method_Silent();
    std::shared_ptr<TimestampImpl> event = std::make_shared<TimestampImpl>(listener, timestamp.getLocalTime(), timestamp.getKind());
    std::list<std::shared_ptr<TimestampImpl>>::iterator it = std::lower_bound(scheduledEvents.begin(), scheduledEvents.end(), event);

    if (it != scheduledEvents.end() && **it == *event) {
        scheduledEvents.erase(it);
    }

    scheduleNextTimestamp();
}

void RealtimeClock::subscribeConfigChanges(IClock2::ConfigListener& listener)
{
    Enter_Method_Silent();
    configListeners.insert(&listener);
}

void RealtimeClock::unsubscribeConfigChanges(IClock2::ConfigListener& listener)
{
    Enter_Method_Silent();
    configListeners.erase(&listener);
}

simtime_t RealtimeClock::updateAndGetLocalTime()
{
    Enter_Method_Silent();
    uint64_t elapsedTicks = oscillator->updateAndGetTickCount() - lastTick;
    localTime += elapsedTicks * timeIncrementPerTick();
    lastTick += elapsedTicks;
    return localTime;
}

void RealtimeClock::setLocalTime(simtime_t newTime)
{
    Enter_Method_Silent();

    // Update time
    simtime_t oldTime = localTime;
    localTime = newTime;

    // If the new local time is in the future, then we have to fast forward all
    // events that are scheduled before the new time value.
    if (oldTime < localTime) {
        auto bound = std::upper_bound(
                scheduledEvents.begin(), 
                scheduledEvents.end(), 
                localTime,
                [](simtime_t time, std::shared_ptr<TimestampImpl> event) {
                    return time < event->getLocalTime();
                });
        // Notify listeners
        for (auto it = scheduledEvents.begin(); it != bound; it++) {
            std::shared_ptr<TimestampImpl> event = *it;
            event->getListener().onTimestamp(*this, event);
        }
        // Remove events
        scheduledEvents.erase(scheduledEvents.begin(), bound);
    }

    // Notify config listeners
    for (IClock2::ConfigListener* listener : configListeners) {
        listener->onPhaseJump(*this, oldTime, newTime);
    }
}

double RealtimeClock::getClockRate() const
{
    Enter_Method_Silent();
    return oscillator->getFrequency();
}

void RealtimeClock::setClockRate(double clockRate)
{
    Enter_Method_Silent();
    oscillator->setFrequency(clockRate);
}

double RealtimeClock::getDriftRate() const
{
    Enter_Method_Silent();
    return driftRate;
}

void RealtimeClock::setDriftRate(double driftRate)
{
    Enter_Method_Silent();

    // Update drift rate
    double oldDriftRate = this->driftRate;
    this->driftRate = driftRate;

    // Reschedule next event
    scheduleNextTimestamp();

    // Notify listeners
    for (IClock2::ConfigListener* listener : configListeners) {
        listener->onDriftRateChange(*this, oldDriftRate, driftRate);
    }
}

bool RealtimeClock::isStopped()
{
    Enter_Method_Silent();
    return oscillator->getFrequency() + driftRate < minEffectiveClockRate;
}

void RealtimeClock::onTick(IOscillator& oscillator, std::shared_ptr<const IOscillator::Tick> tick)
{
    Enter_Method("tick");

    // Precondition: There should be at least one scheduled event. Otherwise
    // this method shouldn't have been triggered.
    assert(!scheduledEvents.empty());

    // Invariant
    assert(&oscillator == this->oscillator);

    // Pop next event from queue
    std::shared_ptr<TimestampImpl> currentEvent = scheduledEvents.front();
    scheduledEvents.pop_front();

    // Invariant: There must not be any timestamp event scheduled with
    // timestamp in the past.
    assert(localTime <= currentEvent->getLocalTime());

    // Update local time
    updateAndGetLocalTime();

    scheduleNextTimestamp();

    // Notify listener
    currentEvent->getListener().onTimestamp(*this, currentEvent);
}

void RealtimeClock::onFrequencyChange(IOscillator& oscillator, double oldFrequency, double newFrequency)
{
    Enter_Method_Silent();
    
    // Reschedule next event
    scheduleNextTimestamp();

    // Notify listeners
    for (IClock2::ConfigListener* listener : configListeners) {
        listener->onClockRateChange(*this, oldFrequency, newFrequency);
    }
}

RealtimeClock::TimestampImpl::TimestampImpl(IClock2::TimestampListener& listener, simtime_t localTime, uint64_t kind)
    : listener(listener)
    , localTime(localTime)
    , kind(kind)
{
}

simtime_t RealtimeClock::TimestampImpl::getLocalTime() const
{
    return localTime;
}

uint64_t RealtimeClock::TimestampImpl::getKind() const
{
    return kind;
}

IClock2::TimestampListener& RealtimeClock::TimestampImpl::getListener() const
{
    return listener;
}

bool RealtimeClock::TimestampImpl::operator==(const TimestampImpl& other) const
{
    return this->localTime == other.localTime
            && this->kind == other.kind
            && &(this->listener) == &(other.listener);
}

bool RealtimeClock::TimestampImpl::operator!=(const TimestampImpl& other) const
{
    return !(*this == other);
}

bool RealtimeClock::TimestampImpl::operator<(const TimestampImpl& other) const
{
    if (this->localTime < other.localTime) {
        return true;
    } else if (this->localTime == other.localTime) {
        if (this->kind < other.kind) {
            return true;
        } else if (this->kind == other.kind) {
            return &(this->listener) < &(other.listener);
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& stream, const RealtimeClock::TimestampImpl* timestamp)
{
    return stream << "Timestamp[localTime=" << timestamp->getLocalTime() 
            << ", kind=" << timestamp->getKind() 
            << ", listener=" << &(timestamp->getListener()) << "]";
}

bool operator<(std::shared_ptr<RealtimeClock::TimestampImpl> left, std::shared_ptr<RealtimeClock::TimestampImpl> right)
{
    return *left < *right;
}

} //namespace
