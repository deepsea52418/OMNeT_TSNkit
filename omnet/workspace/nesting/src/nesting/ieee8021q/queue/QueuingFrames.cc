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

#include "nesting/ieee8021q/queue/QueuingFrames.h"

#include <string>

#include "inet/common/packet/Packet.h"
#include "inet/linklayer/ethernet/EtherFrame_m.h"
#include "inet/linklayer/ieee8021q/Ieee8021qHeader_m.h"

namespace nesting {

Define_Module(QueuingFrames);

void QueuingFrames::initialize() {
    //Initialize the number of queues, which is equal to the number of "out"
    // vector gate. The default values is 8, if user has not specified it.
    numberOfQueues = gateSize("out");

    //Precondition: numberOfQueues must have a valid number, i.e <= number of
    // all possible pcp values.

    if (numberOfQueues > kNumberOfPCPValues || numberOfQueues < 1) {
        throw new cRuntimeError(
                "Invalid assignment of numberOfQueues. Number of queues should not "
                        "be bigger than the number of all possible pcp values!");
    }

    if (par("vlanTagType").stdstringValue() == "c") {
        vlanTagType = C_TAG;
    } else {
        assert(par("vlanTagType").stdstringValue() == "s");
        vlanTagType = S_TAG;
    }
}

void QueuingFrames::handleMessage(cMessage *msg) {
    inet::Packet *packet = check_and_cast<inet::Packet *>(msg);
    const auto& frame = packet->peekAtFront<inet::EthernetMacHeader>();

    const inet::Ieee8021qHeader* qHeader;
    if (vlanTagType == C_TAG) {
        qHeader = frame->getCTag();
    } else {
        qHeader = frame->getSTag();
    }

    int pcpValue;
    if (!qHeader) {
        pcpValue = kDefaultPCPValue;
    } else {
        pcpValue = qHeader->getPcp();
    }

    // Check whether the PCP value is correct.
    if (pcpValue > kNumberOfPCPValues) {
        throw new cRuntimeError(
                "Invalid assignment of PCP value. The value of PCP should not be "
                        "bigger than the number of supported queues.");
    }

    // Get the corresponding queue from the 2-dimensional matrix
    // standardTrafficClassMapping.
    int queueIndex =
            this->standardTrafficClassMapping[numberOfQueues - 1][pcpValue];

    // Get the corresponding gate and transmit the frame to it.
    EV_TRACE << getFullPath() << ": Sending packet '" << packet
                    << "' with pcp value '" << pcpValue << "' to queue "
                    << queueIndex << endl;

    cGate* outputGate = gate("out", queueIndex);
    send(msg, outputGate);
}

} // namespace nesting
