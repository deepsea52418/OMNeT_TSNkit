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

#include "nesting/application/udpapp/SendDatagramEvent.h"

namespace nesting {

void SendDatagramEvent::setDestAddress(const L3Address& destAddress)
{
    this->destAddress = destAddress;
}

const L3Address& SendDatagramEvent::getDestAddress() const
{
    return destAddress;
}

void SendDatagramEvent::setDestPort(uint64_t destPort)
{
    this->destPort = destPort;
}

uint64_t SendDatagramEvent::getDestPort() const
{
    return destPort;
}

void SendDatagramEvent::setPriorityCodePoint(uint64_t pcp)
{
    this->priorityCodePoint = pcp;
}

uint64_t SendDatagramEvent::getPriorityCodePoint() const
{
    return priorityCodePoint;
}

void SendDatagramEvent::setDropEligible(bool de)
{
    this->dropEligible = de;
}

bool SendDatagramEvent::isDropEligible() const
{
    return dropEligible;
}

void SendDatagramEvent::setVlanId(uint64_t vid)
{
    this->vlanId = vid;
}

uint64_t SendDatagramEvent::getVlanId() const
{
    return vlanId;
}

void SendDatagramEvent::setPayloadSize(b payloadSize)
{
    this->payloadSize = payloadSize;
}

b SendDatagramEvent::getPayloadSize() const
{
    return payloadSize;
}

std::ostream& operator<<(std::ostream& os, const SendDatagramEvent& datagramEvent)
{
    return os << "SendDatagramEvent[destAddress=" << datagramEvent.getDestAddress()
            << ", destPort=" << datagramEvent.getDestPort()
            << ", pcp=" << datagramEvent.getPriorityCodePoint()
            << ", de=" << datagramEvent.isDropEligible()
            << ", vid=" << datagramEvent.getVlanId()
            << ", payloadSize=" << datagramEvent.getPayloadSize() << "]";
}

} // namespace nesting
