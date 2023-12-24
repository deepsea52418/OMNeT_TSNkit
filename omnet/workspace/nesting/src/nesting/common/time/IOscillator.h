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

#ifndef NESTING_COMMON_TIME_IOSCILLATOR_H_
#define NESTING_COMMON_TIME_IOSCILLATOR_H_

#include <cstdint>
#include <memory>

#include <omnetpp.h>

using namespace omnetpp;

namespace nesting {

/** Interface for oscillator implementations. */
class IOscillator {
public:
    // Forward declarations
    class Tick;
    class TickListener;
    class ConfigListener;

    virtual ~IOscillator() {};

    /**
     * Subscribes a tick event for a given listener. The kind value can be used
     * to create inverse mappings of oscillator ticks within subscribers.
     */
    virtual std::shared_ptr<const IOscillator::Tick> subscribeTick(IOscillator::TickListener& listener, uint64_t idleTicks, uint64_t kind) = 0;

    /**
     * Same as IOscillator::subscribeTick(IOscillator::TickListener&, uint64_t,
     * uint64_t) except that the kind value is set to 0.
     */
    virtual std::shared_ptr<const IOscillator::Tick> subscribeTick(IOscillator::TickListener& listener, uint64_t idleTicks) = 0;

    /**
     * Unsubscribes a listener from a tick event.
     */
    virtual void unsubscribeTick(IOscillator::TickListener& listener, const Tick& tick) = 0;

    /**
     * Unsubscribes a listener from all tick events of a certain kind value.
     */
    virtual void unsubscribeTicks(IOscillator::TickListener& listener, uint64_t kind) = 0;

    /**
     * Unsubscribes all ticks scheduled for a given listener.
     */
    virtual void unsubscribeTicks(IOscillator::TickListener& listener) = 0;

    virtual void subscribeConfigChanges(IOscillator::ConfigListener& listener) = 0;

    virtual void unsubscribeConfigChanges(IOscillator::ConfigListener& listener) = 0;

    /**
     * Returns true if a given tick event is scheduled for a given listener.
     */
    virtual bool isTickScheduled(IOscillator::TickListener& listener, const Tick& tick) const = 0;

    /**
     * Returns the frequency of the oscillator module.
     *
     * @return Oscillator frequency in Hz.
     */
    virtual double getFrequency() const = 0;

    /**
     * Adjusts the frequency of the oscillator. Calling causes a rescheduling
     * of future tick events.
     *
     * @param frequency New oscillator frequency in Hz.
     */
    virtual void setFrequency(double frequency) = 0;

    /**
     * Updates the internal state (tick counter) and returns its value. This
     * method can't be constant because of potential stochastic
     * implementations.
     */
    virtual uint64_t updateAndGetTickCount() = 0;
public:
    /** Interface for oscillator ticks. */
    class Tick {
    public:
        virtual ~Tick() {};

        virtual uint64_t getTick() const = 0;

        virtual uint64_t getKind() const = 0;

        /** Global simulation time when the tick event will be scheduled. */
        virtual simtime_t getGlobalSchedulingTime() const = 0;
    };

    /** Interface for listeners subscribing tick events. */
    class TickListener {
    public:
        virtual ~TickListener() {};

        virtual void onTick(IOscillator& oscillator, std::shared_ptr<const IOscillator::Tick> tick) = 0;
    };

    /** Interface for listeners subscribing to config changes. */
    class ConfigListener {
    public:
        virtual ~ConfigListener() {};

        virtual void onFrequencyChange(IOscillator& oscillator, double oldFrequency, double newFrequency) = 0;
    };
};

} // namespace nesting

#endif /* NESTING_COMMON_TIME_IOSCILLATOR_H_ */
