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

#ifndef NESTING_COMMON_SCHEDULE_SCHEDULEMANAGER_H_
#define NESTING_COMMON_SCHEDULE_SCHEDULEMANAGER_H_

#include "nesting/common/time/IClock2.h"
#include "nesting/common/schedule/Schedule.h"
#include "nesting/common/schedule/CycleTimerState.h"
#include "nesting/common/schedule/ListExecuteState.h"
#include "nesting/common/schedule/ListConfigState.h"

#include "inet/common/ModuleAccess.h"

#include <omnetpp.h>

#include <string>
#include <memory>
#include <set>

using namespace omnetpp;
using namespace inet;

namespace nesting {

template<typename T>
class ScheduleManager : public cSimpleModule, public IClock2::TimestampListener {
public:
    class IOperStateListener {
        friend ScheduleManager;
    public:
        virtual ~IOperStateListener() {};
    protected:
        virtual void onOperStateChange(const T& newState) {};
        virtual void onOperStateChange(const T& newState, const T& oldState) {};
    };
protected:
    /** Type values to associate timestamp events with state machines. */
    enum StateMachine { CYCLE_TIMER, LIST_EXECUTE, LIST_CONFIG };

    // Keep track of subscribed timestamp events for each state machine
    std::shared_ptr<const IClock2::Timestamp> nextCycleTimerTimestamp = nullptr;
    std::shared_ptr<const IClock2::Timestamp> nextListExecuteTimestamp = nullptr;
    std::shared_ptr<const IClock2::Timestamp> nextListConfigTimestamp = nullptr;

    // Self-messages used to update state machines.
    cMessage cycleTimerMsg = cMessage("updateCycleTimer");
    cMessage listExecuteMsg = cMessage("updateListExecute");
    cMessage listConfigMsg = cMessage("updateListConfig");

    /** Pointer to host's clock module. */
    IClock2* clock;

    /** If the GateManager isn't enabled no internal state transitions will take place. */
    bool enabled = true;

    // Default values
    T adminState;
    std::shared_ptr<const Schedule<T>> adminSchedule = nullptr;
    
    // Variables belonging to ListConfig state machine
    ListConfigState listConfigState = ListConfigState::UNDEFINED;
    ListConfigState nextListConfigState = ListConfigState::UNDEFINED;
    bool configPending = false;
    simtime_t configChangeTime = SimTime::ZERO;
    uint64_t configChangeErrorCounter = 0;
    std::shared_ptr<const Schedule<T>> operSchedule = nullptr;

    // Variables belonging to CycleTimer state machine
    CycleTimerState cycleTimerState = CycleTimerState::UNDEFINED;
    CycleTimerState nextCycleTimerState = CycleTimerState::UNDEFINED;
    simtime_t cycleStartTime = SimTime::ZERO;

    // Variables belonging to ListExecute state machine
    ListExecuteState listExecuteState = ListExecuteState::UNDEFINED;
    ListExecuteState nextListExecuteState = ListExecuteState::UNDEFINED;
    uint64_t listPointer = 0;
    simtime_t exitTimer = SimTime::ZERO;
    T operState;
    simtime_t timeInterval;

    // Variables shared between state machines
    bool configChange = false;
    bool cycleStart = false;
    bool newConfigCT = false;

    std::set<IOperStateListener*> listeners;
protected:
    virtual void initialize() override
    {
        clock = getModuleFromPar<IClock2>(par("clockModule"), this);

        adminState = initialAdminState();
        operState = initialAdminState();

        operSchedule = initialAdminSchedule();
        adminSchedule = initialAdminSchedule();

        // Variables
        WATCH(enabled);
        WATCH(adminSchedule);
        WATCH(operSchedule);
        WATCH(adminState);
        WATCH(operState);
        WATCH(listPointer);
        WATCH(timeInterval);
        WATCH(cycleStartTime);
        WATCH(configChangeTime);
        WATCH(configChangeErrorCounter);

        // State machines
        WATCH(cycleTimerState);
        WATCH(listExecuteState);
        WATCH(listConfigState);

        begin();
    }

    virtual void handleMessage(cMessage *msg) override
    {
        if (msg == &listConfigMsg) {
            updateListConfigState();
        } else if (msg == &listExecuteMsg) {
            updateListExecuteState();
        } else if (msg == &cycleTimerMsg) {
            updateCycleTimerState();
        } else {
            throw cRuntimeError("Can't handle this type of messages.");
        }
    }

    virtual void updateCycleTimerState()
    {
        // Cancel outdated timestamp events
        if (nextCycleTimerTimestamp != nullptr) {
            clock->unsubscribeTimestamp(*this, *nextCycleTimerTimestamp);
        }

        cycleTimerState = nextCycleTimerState;
        EV_DEBUG << "CycleTimerState transitioned to " << cycleTimerState << "." << std::endl;

        if (enabled) {
            if (cycleTimerState == CycleTimerState::CYCLE_IDLE) {
                setCycleStart(false);
                setNewConfigCT(false);
                nextCycleTimerState = CycleTimerState::SET_CYCLE_START_TIME;
                rescheduleAt(simTime(), &cycleTimerMsg);  
             } else if (cycleTimerState == CycleTimerState::SET_CYCLE_START_TIME) {
                setCycleStartTime();
                simtime_t idleTime = cycleStartTime - clock->updateAndGetLocalTime();
                nextCycleTimerState = CycleTimerState::START_CYCLE;
                nextCycleTimerTimestamp = clock->subscribeTimestamp(*this, cycleStartTime, CYCLE_TIMER);
            } else if (cycleTimerState == CycleTimerState::START_CYCLE) {
                setCycleStart(true);
                nextCycleTimerState = CycleTimerState::SET_CYCLE_START_TIME;
                simtime_t minClockResolution = SimTime(1, SIMTIME_S) / clock->getClockRate();
                nextCycleTimerTimestamp = clock->subscribeDelta(*this, minClockResolution, CYCLE_TIMER);
            }
        }
    }

    virtual void updateListExecuteState()
    {
        // Cancel outdated timestamp events
        if (nextListExecuteTimestamp != nullptr) {
            clock->unsubscribeTimestamp(*this, *nextListExecuteTimestamp);
        }

        listExecuteState = nextListExecuteState;
        EV_DEBUG << "ListExecuteState transitioned to " << listExecuteState << "." << std::endl;

        if (enabled) {
            if (listExecuteState == ListExecuteState::NEW_CYCLE) {
                setCycleStart(false);
                listPointer = 0;
                nextListExecuteState = ListExecuteState::EXECUTE_CYCLE;
                rescheduleAt(simTime(), &listExecuteMsg);
            } else if (listExecuteState == ListExecuteState::EXECUTE_CYCLE) {
                T oldState = operState;
                executeOperation();
                exitTimer = timeInterval;
                notifyStateChanged(oldState, operState);
                listPointer++;
                if (exitTimer <= SimTime::ZERO && listPointer < operSchedule->getControlListLength()) {
                    nextListExecuteState = ListExecuteState::EXECUTE_CYCLE;
                    rescheduleAt(simTime(), &listExecuteMsg);
                } else if (exitTimer > SimTime::ZERO && listPointer < operSchedule->getControlListLength()) {
                    nextListExecuteState = ListExecuteState::DELAY;
                    rescheduleAt(simTime(), &listExecuteMsg);
                } else {
                    assert(listPointer >= operSchedule->getControlListLength());
                    nextListExecuteState = ListExecuteState::END_OF_CYCLE;
                    rescheduleAt(simTime(), &listExecuteMsg);
                }
            } else if (listExecuteState == ListExecuteState::DELAY) {
                nextListExecuteState = ListExecuteState::EXECUTE_CYCLE;
                nextListExecuteTimestamp = clock->subscribeDelta(*this, exitTimer, LIST_EXECUTE);
            } else if (listExecuteState == ListExecuteState::INIT) {
                T oldState = operState;
                operState = adminState;
                notifyStateChanged(oldState, operState);
                exitTimer = SimTime::ZERO;
                listPointer = 0;
                nextListExecuteState = ListExecuteState::END_OF_CYCLE;
                rescheduleAt(simTime(), &listExecuteMsg);
            }
        }
    }

    virtual void updateListConfigState()
    {
        // Cancel outdated timestamp events
        if (nextListConfigTimestamp != nullptr) {
            clock->unsubscribeTimestamp(*this, *nextListConfigTimestamp);
        }

        listConfigState = nextListConfigState;
        EV_DEBUG << "ListConfigState transitioned to " << listConfigState << "." << std::endl;

        if (enabled) {
            if (listConfigState == ListConfigState::CONFIG_PENDING) {
                setConfigChange(false);
                setConfigChangeTime();
                configPending = true;
                nextListConfigState = ListConfigState::UPDATE_CONFIG;
                nextListConfigTimestamp = clock->subscribeTimestamp(*this, configChangeTime, LIST_CONFIG);
            } else if (listConfigState == ListConfigState::UPDATE_CONFIG) {
                operSchedule = adminSchedule;
                setNewConfigCT(true);
                nextListConfigState = ListConfigState::CONFIG_IDLE;
                rescheduleAt(simTime(), &listConfigMsg);
            } else if (listConfigState == ListConfigState::CONFIG_IDLE) {
                configPending = false;
            }
        }
    }

    virtual void begin()
    {
        nextCycleTimerState = CycleTimerState::CYCLE_IDLE;
        rescheduleAt(simTime(), &cycleTimerMsg);
        nextListExecuteState = ListExecuteState::INIT;
        rescheduleAt(simTime(), &listExecuteMsg);
        nextListConfigState = ListConfigState::CONFIG_IDLE;
        rescheduleAt(simTime(), &listConfigMsg);
    }

    virtual void setCycleStartTime()
    {
        assert(operSchedule != nullptr);

        simtime_t currentTime = clock->updateAndGetLocalTime();
        simtime_t operBaseTime = operSchedule->getBaseTime();
        simtime_t operCycleTime = operSchedule->getCycleTime();
        simtime_t operCycleTimeExtension = operSchedule->getCycleTimeExtension();

        // IEEE 802.1Q 8.6.9.1.1 case a)
        if (!configPending && operBaseTime >= currentTime) {
            cycleStartTime = operBaseTime;
        }
        // IEEE 802.1Q 8.6.9.1.1 case b)
        else if (!configPending && operBaseTime < currentTime) {
            uint64_t n = static_cast<uint64_t>(std::ceil((currentTime - operBaseTime) / operCycleTime));
            cycleStartTime = operBaseTime + n * operCycleTime;
        }
        // IEEE 802.1Q 8.6.9.1.1 case c)
        else if (configPending && configChangeTime > (currentTime + operCycleTime + operCycleTimeExtension)) {
            unsigned n = static_cast<uint64_t>(std::ceil((currentTime - operBaseTime) / operCycleTime));
            cycleStartTime = operBaseTime + n * operCycleTime;
        }
        // IEEE 802.1Q 8.6.9.1.1 case d)
        else if (configPending && configChangeTime <= (currentTime + operCycleTime + operCycleTimeExtension)) {
            cycleStartTime = configChangeTime;
        }

        assert(cycleStartTime >= currentTime);
    }

    virtual void setCycleStart(bool cycleStart)
    {
        this->cycleStart = cycleStart;
        if (cycleStart) {
            nextListExecuteState = ListExecuteState::NEW_CYCLE;
            rescheduleAt(simTime(), &listExecuteMsg);
        }
    }

    virtual void setNewConfigCT(bool newConfigCT)
    {
        this->newConfigCT = newConfigCT;
        if (newConfigCT) {
            nextCycleTimerState = CycleTimerState::CYCLE_IDLE;
            rescheduleAt(simTime(), &cycleTimerMsg);
        }
    }

    virtual void executeOperation()
    {
        if (operSchedule->getControlListLength() <= 0) {
            // If control list has no entries we have to fall back on default values.
            operState = adminState;
            timeInterval = operSchedule->getCycleTime();
        } else {
            assert(listPointer < operSchedule->getControlListLength());
            operState = operSchedule->getScheduledObject(listPointer);
            timeInterval = operSchedule->getTimeInterval(listPointer);
            // According to IEEE 802.1Qbv chapter 8.6.9.2.1 case a) time
            // interval values of zero will be set to one time unit.
            if (timeInterval <= SimTime::ZERO) {
                simtime_t minClockInterval = SimTime(1, SIMTIME_S) / clock->getClockRate();
                timeInterval = minClockInterval;
            }
        }
    }

    virtual void notifyStateChanged(const T& oldState, const T& newState)
    {
        for (auto listener : listeners) {
            listener->onOperStateChange(newState);
            listener->onOperStateChange(oldState, newState);
        }
    }

    virtual void setConfigChangeTime()
    {
        simtime_t currentTime = clock->updateAndGetLocalTime();
        simtime_t adminBaseTime = adminSchedule->getBaseTime();
        simtime_t adminCycleTime = adminSchedule->getCycleTime();

        // IEEE 802.1Q 8.6.9.3.1 case a)
        if (adminBaseTime >= currentTime) {
            configChangeTime = adminSchedule->getBaseTime();
        }
        // IEEE 802.1Q 8.6.9.3.1 case b)
        else if (adminBaseTime < currentTime && !enabled) {
            uint64_t n = static_cast<uint64_t>(std::ceil((currentTime - adminBaseTime) / adminCycleTime));
            configChangeTime = adminBaseTime + n * adminCycleTime;
        }
        // IEEE 802.1Q 8.6.9.3.1 case c)
        else if (adminBaseTime < currentTime && enabled) {
            configChangeErrorCounter++;
            uint64_t n = static_cast<uint64_t>(std::ceil((currentTime - adminBaseTime) / adminCycleTime));
            configChangeTime = adminBaseTime + n * adminCycleTime;
        }

        assert(configChangeTime >= currentTime);
    }

    virtual void rescheduleAt(simtime_t t, cMessage* msg)
    {
        if (msg->isScheduled()) {
            cancelEvent(msg);
        }
        scheduleAt(t, msg);
    }

    virtual const T initialAdminState() const = 0;

    virtual std::unique_ptr<Schedule<T>> initialAdminSchedule() const = 0;
public:
    virtual ~ScheduleManager() {
        cancelEvent(&cycleTimerMsg);
        cancelEvent(&listExecuteMsg);
        cancelEvent(&listConfigMsg);
    }

    virtual void setAdminState(T adminState)
    {
        this->adminState = adminState;
    }

    virtual const T& getAdminState() const
    {
        return this->adminState;
    }

    virtual const T& getOperState() const
    {
        return this->operState;
    }

    virtual void setAdminSchedule(std::unique_ptr<Schedule<T>> adminSchedule)
    {
        Enter_Method_Silent();

        // Schedule must not be nullptr.
        if (adminSchedule == nullptr) {
            throw cRuntimeError("adminSchedule must not be nullptr");
        }

        const simtime_t adminCycleTime = adminSchedule->getCycleTime();
        const simtime_t minClockResolution = SimTime(1, SIMTIME_S) / clock->getClockRate();

        // Cycle time must not be zero.
        if (adminCycleTime <= SimTime::ZERO) {
            throw cRuntimeError("Can't load schedule with cycle time of zero.");
        }
        // If cycle time is smaller than clock resolution it effectively has a
        // cycle time of zero which can lead to unexpected behaviour.
        if (adminCycleTime < minClockResolution) {
            EV_WARN << "AdminCycleTime is smaller than minimum clock resolution." << std::endl;
        }

        this->adminSchedule = std::move(adminSchedule);
    }

    virtual void setEnabled(bool enabled)
    {
        Enter_Method_Silent();
        this->enabled = enabled;
        if (!enabled) {
            nextCycleTimerState = CycleTimerState::CYCLE_IDLE;
            rescheduleAt(simTime(), &cycleTimerMsg);
            nextListExecuteState = ListExecuteState::INIT;
            rescheduleAt(simTime(), &listExecuteMsg);
            nextListConfigState = ListConfigState::CONFIG_IDLE;
            rescheduleAt(simTime(), &listConfigMsg);
        } else if (configChange && enabled) {
            nextListConfigState = ListConfigState::CONFIG_PENDING;
            rescheduleAt(simTime(), &listConfigMsg);
        }
    }

    virtual bool isEnabled()
    {
        return enabled;
    }

    virtual void setConfigChange(bool configChange)
    {
        Enter_Method_Silent();
        this->configChange = configChange;
        if (configChange && enabled) {
            nextListConfigState = ListConfigState::CONFIG_PENDING;
            rescheduleAt(simTime(), &listConfigMsg);
        }
    }

    virtual bool isConfigChange()
    {
        return configChange;
    }

    virtual uint64_t getConfigChangeErrorCounter()
    {
        return configChangeErrorCounter;
    }

    virtual void onTimestamp(IClock2& clock, std::shared_ptr<const IClock2::Timestamp> timestamp) override
    {
        Enter_Method("timestamp");
        switch (timestamp->getKind()) {
        case CYCLE_TIMER:
            rescheduleAt(simTime(), &cycleTimerMsg);
            break;
        case LIST_EXECUTE:
            rescheduleAt(simTime(), &listExecuteMsg);
            break;
        case LIST_CONFIG:
            rescheduleAt(simTime(), &listConfigMsg);
            break;
        default:
            throw cRuntimeError("Invalid timestamp event.");
        }
    }

    virtual void subscribeOperStateChanges(IOperStateListener& listener)
    {
        listeners.insert(&listener);
    }

    virtual void unsubscribeOperStateChanges(IOperStateListener& listener)
    {
        listeners.erase(&listener);
    }

    /**
     * Returns the current state of the CycleTimer state machine. Useful for
     * debugging or testing.
     */
    virtual CycleTimerState getCycleTimerState()
    {
        return cycleTimerState;
    }

    /**
     * Returns the current state of the ListExecute state machine. Useful for
     * debugging or testing.
     */
    virtual ListExecuteState getListExecuteState()
    {
        return listExecuteState;
    }

    /**
     * Returns the current state of the ListConfig state machine. Useful for
     * debugging or testing.
     */
    virtual ListConfigState getListConfigState()
    {
        return listConfigState;
    }
};

} // namespace nesting

#endif
