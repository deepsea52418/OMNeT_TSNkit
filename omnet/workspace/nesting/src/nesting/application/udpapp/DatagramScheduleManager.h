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

#ifndef NESTING_APPLICATION_UDPAPP_DATAGRAMSCHEDULEMANAGER_H_
#define NESTING_APPLICATION_UDPAPP_DATAGRAMSCHEDULEMANAGER_H_

#include <omnetpp.h>

#include "nesting/common/schedule/ScheduleManager.h"
#include "nesting/application/udpapp/SendDatagramEvent.h"

//#include <optional>

using namespace omnetpp;

namespace nesting {

class DatagramScheduleManager : public ScheduleManager<SendDatagramEvent>
{
protected:
    /** @copydoc Schedule::initialAdminState() */
    virtual const SendDatagramEvent initialAdminState() const override;

    /** @copydoc Schedule::initialAdminSchedule() */
    virtual std::unique_ptr<Schedule<SendDatagramEvent>> initialAdminSchedule() const override;

    virtual int numInitStages() const override;

    virtual void initialize(int stage) override;

    virtual void notifyStateChanged(const SendDatagramEvent& oldState, const SendDatagramEvent& newState) override;
};

} // namespace nesting

#endif
