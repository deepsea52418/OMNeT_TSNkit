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

package nesting.ieee8021q.queue;

//
// Receives cPackets with attached Ieee8021QCtrl control information and
// sends those packets to a specific output port by mapping the packets pcp
// value to an out-gate index. For the mapping a default mapping table
// according to the Ieee802.1Q standard is used.
//
// @see ~Ieee8021QCtrl
//
simple QueuingFrames {
    parameters:
        @display("i=block/classifier");
        @class(QueuingFrames);
        string vlanTagType @enum("c","s") = default("c");
        bool verbose = default(false);
    gates:
        input in;
        output out[];
}
