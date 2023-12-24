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

#ifndef __NESTINGNG_ENHANCEDIEEE8021QENCAP_H_
#define __NESTINGNG_ENHANCEDIEEE8021QENCAP_H_

#include <omnetpp.h>

#include "inet/linklayer/ieee8021q/Ieee8021qHeader_m.h"
#include "inet/linklayer/ethernet/EtherFrame_m.h"
#include "inet/common/packet/Packet.h"

using namespace omnetpp;
using namespace inet;

namespace nesting {

class EnhancedIeee8021qEncap : public cSimpleModule
{
protected:
    const char *vlanTagType = nullptr;
    std::vector<int> inboundVlanIdFilter;
    std::map<int, int> inboundVlanIdMap;
    std::vector<int> outboundVlanIdFilter;
    std::map<int, int> outboundVlanIdMap;
    bool tagTcpTraffic;

protected:
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *message) override;

    virtual Ieee8021qHeader *findVlanTag(const Ptr<EthernetMacHeader>& ethernetMacHeader);
    virtual Ieee8021qHeader *addVlanTag(const Ptr<EthernetMacHeader>& ethernetMacHeader);
    virtual Ieee8021qHeader *removeVlanTag(const Ptr<EthernetMacHeader>& ethernetMacHeader);
    virtual void parseParameters(const char *filterParameterName, const char *mapParameterName, std::vector<int>& vlanIdFilter, std::map<int, int>& vlanIdMap);
    virtual void processPacket(Packet *packet, std::vector<int>& vlanIdFilter, std::map<int, int>& vlanIdMap, cGate *gate);
};

} //namespace

#endif
