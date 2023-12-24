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

#ifndef NESTING_COMMON_SCHEDULE_SCHEDULEFACTORY_H_
#define NESTING_COMMON_SCHEDULE_SCHEDULEFACTORY_H_

#include <omnetpp.h>

#include <algorithm>

#include "nesting/common/schedule/Schedule.h"
#include "nesting/ieee8021q/Ieee8021q.h"
#include "nesting/application/udpapp/SendDatagramEvent.h"

using namespace omnetpp;

namespace nesting {

/**
 * Utility class to build schedules from e.g. XML files.
 */
class ScheduleFactory final {
public:
    /**
     * Creates a schedule for containing bit vectors for transmission gates
     * from an XML file.
     *
     * TODO link to XML file specification
     */
    static Schedule<GateBitvector>* createGateBitvectorSchedule(cXMLElement *xml);

    static Schedule<GateBitvector>* createGateSchedule(cXMLElement *xml);

    /**
     * Creates a schedule containing one entry that opens all gates for the whole cycle duration
     */
    static Schedule<GateBitvector>* createDefaultBitvectorSchedule(cXMLElement *xml);

    static Schedule<SendDatagramEvent>* createDatagramSchedule(cXMLElement *xml);
private:
    static simtime_t getBaseTimeAttribute(cXMLElement* xml);

    static simtime_t getCycleTimeAttribute(cXMLElement* xml);

    static simtime_t getCycleTimeExtensionAttribute(cXMLElement* xml);

    static GateBitvector getGateBitvectorAttribute(cXMLElement* xml);

    static simtime_t getTimeIntervalAttribute(cXMLElement* xml);

    static L3Address getDestAddressAttribute(cXMLElement* xml);

    static uint64_t getDestPortAttribute(cXMLElement* xml);

    static uint64_t getPriorityCodePointAttribute(cXMLElement* xml);

    static bool getDropEligibleIndicatorAttribute(cXMLElement* xml);

    static uint64_t getVlanIdAttribute(cXMLElement* xml);

    static b getPayloadSizeAttribute(cXMLElement* xml);

    /**
     * Returns true if the given string value is either "true", "True", "1" and
     * false when it is "false", "False", "0". Otherwise an exception is thrown.
     */
    static bool parseBool(const char* cstring);
};

} // namespace nesting

#endif
