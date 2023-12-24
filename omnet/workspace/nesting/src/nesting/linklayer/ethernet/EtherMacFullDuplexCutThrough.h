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

#ifndef NESTING_LINKLAYER_ETHERNET_ETHERMACFULLDUPLEXCUTTHROUGH_H_
#define NESTING_LINKLAYER_ETHERNET_ETHERMACFULLDUPLEXCUTTHROUGH_H_

#include <omnetpp.h>

#include "inet/linklayer/ethernet/EtherMacFullDuplex.h"

using namespace omnetpp;
using namespace inet;

namespace nesting {

class EtherMacFullDuplexCutThrough : public EtherMacFullDuplex {
protected:
    bool cutThroughEnabled = true;
protected:
    virtual void initialize(int stage) override;
    virtual void processReceivedDataFrame(Packet* packet, const Ptr<const EthernetMacHeader>& frame) override;
public:
    virtual void receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj, cObject *details) override;
};

} // namespace nesting

#endif
