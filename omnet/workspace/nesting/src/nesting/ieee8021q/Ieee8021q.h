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

#ifndef NESTING_IEEE8021Q_IEEE8021Q_H_
#define NESTING_IEEE8021Q_IEEE8021Q_H_

#include <bitset>

#include "inet/common/packet/Packet.h"

#include "nesting/linklayer/common/VLANTagDeprecated_m.h"

namespace nesting {

const inet::B kEthernet2MinPayloadByteLength = inet::B(42);
const inet::b kEthernet2MinPayloadBitLength = inet::b(
        kEthernet2MinPayloadByteLength * 8);
const inet::B kEthernet2MaximumTransmissionUnitByteLength = inet::B(1500);
const inet::b kEthernet2MaximumTransmissionUnitBitLength = inet::b(
        kEthernet2MaximumTransmissionUnitByteLength * 8);

const inet::B kVLANTagByteLength = inet::B(4);
const inet::b kVLANTagBitLength = inet::b(kVLANTagByteLength * 8);

const int kDefaultPCPValue = 0;
const int kNumberOfPCPValues = 8;

const bool kDefaultDEIValue = false;

const int kMinValidVID = 1;
const int kMaxValidVID = 4094;
const int kDefaultVID = 1;

const int kMaxSupportedQueues = kNumberOfPCPValues;
const int kMinSupportedQueues = 1;

const int selfMessageSchedulingPriority = 1;

const inet::B kFramePreemptionMinFinalPayloadSize = inet::B(60);
// TODO make MinNonFinalPayloadSize a parameter
const inet::B kFramePreemptionMinNonFinalPayloadSize = inet::B(60); //or 124,188,252

const inet::B ETHER_MAC_FRAME_BYTES = inet::B(18);
const inet::B PREAMBLE_BYTES = inet::B(7);
const inet::B SFD_BYTES = inet::B(1);

const inet::b ETHER_MAC_FRAME_BITS = inet::b(ETHER_MAC_FRAME_BYTES * 8);
const inet::b PREAMBLE_BITS = inet::b(PREAMBLE_BYTES * 8);
const inet::b SFD_BITS = inet::b(SFD_BYTES * 8);
/**
 * Static class holding constants relevant to the IEEE 802.1Q standard.
 */
class Ieee8021q final {
public:
    /**
     * This method calculates the final packet size of a payload-packet after
     * going through the encapsulation processes of the lower layers of the
     * IEEE802.1Q switch.
     *
     * This method is meant as a temporary solution to calculate final packet
     * sizes for the functionality of some IEEE802.1Q relevant functionalities
     * like the credit based shaper. Changes to the LowerLayer-compound module
     * of the IEEE802.1Q ethernet switch can break the functionality of this
     * method.
     */
    static int getFinalEthernet2FrameBitLength(inet::Packet* packet) {

        // Add payload length
        inet::b bitLength = inet::b(packet->getBitLength());

        // Add q-tag length
        auto vlanTag = packet->findTag<VLANTagInd>();
        if (vlanTag) {
            bitLength += kVLANTagBitLength;
        }

        // Add MAC header length
        bitLength += nesting::ETHER_MAC_FRAME_BITS;

        // Add physical header length
        bitLength += nesting::PREAMBLE_BITS;
        bitLength += nesting::SFD_BITS;
        // TODO check Ethernet.h

        return bitLength.get();
    }
};

typedef std::bitset<static_cast<unsigned long>(kMaxSupportedQueues)> GateBitvector;

} // namespace nesting

#endif /* NESTING_IEEE8021Q_IEEE8021Q_H_ */
