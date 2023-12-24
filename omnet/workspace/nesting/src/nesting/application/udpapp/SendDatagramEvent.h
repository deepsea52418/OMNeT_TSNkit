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

#ifndef NESTING_APPLICATION_UDPAPP_SENDDATAGRAMEVENT_H_
#define NESTING_APPLICATION_UDPAPP_SENDDATAGRAMEVENT_H_

#include <iostream>

#include "inet/networklayer/common/L3Address.h"
#include "inet/common/packet/Packet.h"

using namespace inet;

namespace nesting {

class SendDatagramEvent {
protected:
    L3Address destAddress;
    uint64_t destPort = 0;
    uint64_t priorityCodePoint = 1;
    bool dropEligible = false;
    uint64_t vlanId = 1;
    b payloadSize = B(0);
public:
    void setDestAddress(const L3Address& destAddress);
    const L3Address& getDestAddress() const;
    void setDestPort(uint64_t destPort);
    uint64_t getDestPort() const;
    void setPriorityCodePoint(uint64_t pcp);
    uint64_t getPriorityCodePoint() const;
    void setDropEligible(bool de);
    bool isDropEligible() const;
    void setVlanId(uint64_t vid);
    uint64_t getVlanId() const;
    void setPayloadSize(b payloadSize);
    b getPayloadSize() const;
};

std::ostream& operator<<(std::ostream& os, const SendDatagramEvent& datagramEvent);

} // namespace nesting

#endif
