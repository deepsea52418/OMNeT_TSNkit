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

package nesting.linklayer.ieee8021q;

import inet.linklayer.ieee8021q.IIeee8021qEncap;


//
// TODO auto-generated module
//
simple EnhancedIeee8021qEncap like IIeee8021qEncap
{
    parameters:
        string vlanTagType @enum("c","s") = default("c");
        string inboundVlanIdFilter = default("");
        string inboundVlanIdMap = default("");
        string outboundVlanIdFilter = default("");
        string outboundVlanIdMap = default("");
        bool tagTcpTraffic = default(false); // When true tags TCP segments from upper layer with destination port mod 8
        @display("i=block/cogwheel");
        @signal[packetDropped](type=inet::Packet);
        @statistic[packetDropped](title="packet dropped"; source=packetDropped; record=count,sum(packetBytes),vector(packetBytes); interpolationmode=none);
    gates:
        input upperLayerIn;
        output upperLayerOut;
        input lowerLayerIn;
        output lowerLayerOut;
}
