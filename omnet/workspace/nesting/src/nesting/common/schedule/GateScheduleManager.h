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

#ifndef NESTING_COMMON_SCHEDULE_GATESCHEDULEMANAGER_H_
#define NESTING_COMMON_SCHEDULE_GATESCHEDULEMANAGER_H_

#include "nesting/common/schedule/ScheduleManager.h"
#include "nesting/common/schedule/Schedule.h"
#include "nesting/ieee8021q/Ieee8021q.h"

#include <memory>

namespace nesting {

/**
 * Important invariant: adminSchedule must always be normalized
 */
class GateScheduleManager : public ScheduleManager<GateBitvector> {
public:
    GateScheduleManager();
protected:
    /** @copydoc Schedule::initialAdminState() */
    virtual const GateBitvector initialAdminState() const override;

    /** @copydoc Schedule::initialAdminSchedule() */
    virtual std::unique_ptr<Schedule<GateBitvector>> initialAdminSchedule() const override;

    /**
     * Valid admin schedules must (1) not be nullptr, (2) have a cycleTime
     * greater than SimTime::ZERO and (3) be normalized.
     */
    virtual void setAdminSchedule(std::unique_ptr<Schedule<GateBitvector>> adminSchedule) override;

    /**
     * Returns the time interval after a gate will be closed, by eaxamining
     * a given schedule starting from the listPointerStart index. If the
     * controlListLength of the schedule is zero (the schedule is empty) this
     * method will return SimTime::getMaxTime(). This method will also return
     * SimTime::getMaxTime() if the gate specified by gateIndex will never be
     * closed.
     */
    virtual simtime_t nextGateCloseEventInSchedule(uint64_t gateIndex, uint64_t listPointerStart,
            const Schedule<GateBitvector>& schedule) const;
public:
    /**
     * Returns the time interval after a gate will be closed. If the gate is
     * closed at the beginning, this method will return SimTime::ZERO and if
     * the gate will never close, it will return SimTime::getMaxTime().
     */
    virtual simtime_t nextGateCloseEvent(uint64_t gateIndex) const;
};

} // namespace nesting

#endif
