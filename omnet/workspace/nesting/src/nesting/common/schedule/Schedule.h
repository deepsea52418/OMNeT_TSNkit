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

#ifndef NESTING_COMMON_SCHEDULE_SCHEDULE_H_
#define NESTING_COMMON_SCHEDULE_SCHEDULE_H_

#include <vector>
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace omnetpp;

namespace nesting {

/**
 * A schedule is more or less a list consisting of tuples of scheduled objects
 * and time intervals. We call this the control list. There is also a cycle
 * time, base time and cycle time extension attribute associated with the
 * schedule.
 *
 * For more information about terminologies and context see chapters 8.6.8.4
 * and 8.6.9 of the IEEE802.1Q standard.
 *
 * If the sum of all time intervals for the entries in the control list exceeds
 * the cycle time, then for scheduling purposes only the entries must be
 * considered that fit within the cycle time and the last valid entry might be
 * shortened. Similarly, in schedules where the cycle time is shorter that the
 * sum of all time intervals, the last entry must be extended.
 */
template<typename T>
class Schedule {
    /** Tuple consisting of a time interval and a scheduled object. */
    struct ControlListEntry {
        simtime_t timeInterval;
        T scheduledObject;
    };
protected:
    /**
     * The control list contains tuples of time intervals and scheduled
     * objects.
     */
    std::vector<ControlListEntry> controlList;

    /**
     * The base time is considered when starting a schedule. Valid starting
     * points for a schedule are (baseTime + N * cycleTime) where N is a
     * positive integer.
     */
    simtime_t baseTime;

    /** Time period of one cycle. After each cycle the schedule is repeated. */
    simtime_t cycleTime;

    simtime_t cycleTimeExtension;

    /**
     * Sum of all time intervals from the control list. The IEEE802.1Q
     * standard explicitely specifies that this number can be different from
     * the cycle time.
     */
    simtime_t sumTimeIntervals;
public:
    virtual ~Schedule() {}

    Schedule()
        : baseTime(SimTime::ZERO)
        , cycleTime(SimTime::ZERO)
        , cycleTimeExtension(SimTime::ZERO)
        , sumTimeIntervals(SimTime::ZERO)
    {}

    virtual void setBaseTime(simtime_t baseTime) {
        this->baseTime = baseTime;
    }

    virtual simtime_t getBaseTime() const {
        return baseTime;
    }

    virtual void setCycleTime(simtime_t cycleTime) {
        this->cycleTime = cycleTime;
    }

    virtual simtime_t getCycleTime() const {
        return cycleTime;
    }

    virtual void setCycleTimeExtension(simtime_t cycleTimeExtension) {
        this->cycleTimeExtension = cycleTimeExtension;
    }

    virtual simtime_t getCycleTimeExtension() const {
        return cycleTimeExtension;
    }

    virtual unsigned getControlListLength() const {
        return controlList.size();
    }

    virtual const T& getScheduledObject(unsigned index) const {
        return controlList[index].scheduledObject;
    }

    virtual simtime_t getTimeInterval(unsigned index) const {
        return controlList[index].timeInterval;
    }

    virtual bool isEmpty() const {
        return controlList.empty();
    }

    virtual void addControlListEntry(simtime_t timeInterval, T scheduledObject) {
        if (timeInterval < SimTime::ZERO) {
            throw cRuntimeError("Control list entries only allow positive time intervals.");
        }
        sumTimeIntervals += timeInterval;
        ControlListEntry entry;
        entry.timeInterval = timeInterval;
        entry.scheduledObject = scheduledObject;
        controlList.push_back(entry);
    }

    /** Returns the sum of all time intervals from all entries. */
    virtual simtime_t getSumTimeIntervals() const {
        return sumTimeIntervals;
    }

    /**
     * Returns true if sumTimeIntervals is equal to cycleTime. Every schedule
     * can be transformed into a normalized schedule by (1) either extending
     * the last entry so that sumTimeIntervals is equal to cycleTime or (2) by
     * removing/shortening the last entries.
     *
     * @see Schedule::normalize()
     */
    virtual bool isNormalized() const
    {
        return sumTimeIntervals == cycleTime;
    }

    /**
     * Normalizes the schedule so that sumTimeIntervals is equal to cycleTime.
     * Therefore entries in controlList will be prolonged or
     * shortended/removed. A normalized schedule semantically stays the same,
     * but is easier to work with, because it might allow to get rid of some
     * special cases.
     */
    virtual void normalize()
    {
        // Case 1: Last entry has to be extended.
        if (sumTimeIntervals < cycleTime) {
            ControlListEntry& lastEntry = controlList[controlList.size() - 1];
            simtime_t timeIntervalExtension = cycleTime - sumTimeIntervals;
            lastEntry.timeInterval += timeIntervalExtension;
            sumTimeIntervals += timeIntervalExtension;
        }
        // Case 2: Entries have to be removed/shortened.
        else if (sumTimeIntervals > cycleTime) {
            simtime_t timeReduction = sumTimeIntervals - cycleTime;
            for (int i = controlList.size() - 1; i >= 0; i--) {
                ControlListEntry& lastEntry = controlList[i];
                // Remove entry
                if (lastEntry.timeInterval <= timeReduction) {
                    sumTimeIntervals -= lastEntry.timeInterval;
                    timeReduction -= lastEntry.timeInterval;
                    controlList.resize(i);
                    // We can stop if timeReduction is equal to zero.
                    if (timeReduction <= SimTime::ZERO) {
                        assert(timeReduction == SimTime::ZERO);
                        break;
                    }
                }
                // … or shorten it.
                else {
                    lastEntry.timeInterval -= timeReduction;
                    sumTimeIntervals -= timeReduction;
                    // timeReduction = SimTime::ZERO;
                    break;
                }
            }
        }

        // Postcondition: Schedule is normalized
        assert(isNormalized());
    }
};

// Overload stream operator for schedule objects.
template<typename T>
std::ostream& operator<<(std::ostream& stream, const Schedule<T>& schedule)
{
    return stream << "Schedule[baseTime=" << schedule.getBaseTime() 
            << ", cycleTime=" << schedule.getCycleTime()
            << ", cycleTimeExtension=" << schedule.getCycleTimeExtension()
            << ", controlListLength=" << schedule.getControlListLength()
            << ", sumTimeIntervals=" << schedule.getSumTimeIntervals() << "]";
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::shared_ptr<const Schedule<T>>& schedule)
{
    return os << *schedule;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Schedule<T>>& schedule)
{
    return os << *schedule;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::unique_ptr<const Schedule<T>>& schedule)
{
    return os << *schedule;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::unique_ptr<Schedule<T>>& schedule)
{
    return os << *schedule;
}

} // namespace nesting

#endif /* NESTING_COMMON_SCHEDULE_SCHEDULE_H_ */
