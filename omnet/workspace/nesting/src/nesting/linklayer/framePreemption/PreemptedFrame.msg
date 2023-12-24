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

//
// Message class for PreemptedPackets. Preempted packets are represented by
// holding an internal reference to the complete packet and a sequence number
// to represent the packet ordering.
//

cplusplus {{
#include "inet/linklayer/ethernet/EtherPhyFrame_m.h"
#include <omnetpp.h>
#include <memory>
typedef inet::EthernetSignal* cFramePointer;
}}

class noncobject cFramePointer;

packet PreemptedFrame {
    @customize(true);
    unsigned int bytesInThisPart;
    unsigned int bytesSent;
    unsigned int bytesTotal;
	cFramePointer completeFrame;
}
