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

package nesting.application.ethernet;

// @deprecated
simple VlanEtherTrafGenSched
{
    parameters:
        @display("i=block/app");
        xml initialSchedule = default(xml("<host><cycle>100ms</cycle></host>"));
        xml emptySchedule = default(xml("<host><cycle>100ms</cycle></host>"));
        string clockModule = default("^.clock");
        string hostModule = default("^");
        volatile double jitter @unit(s) = default(0s); // random time, for which transmission of packet can be delayed.

        @signal[sentPk](type=inet::Packet);
        @signal[rcvdPk](type=inet::Packet);
        @signal[sentPkTreeId](type=long);
        @signal[rcvdPkTreeId](type=long);

        @statistic[pktSent](title="num packets sent"; source=sentPk; record=count; interpolationmode=none);
        @statistic[pktSentFlowId](title="packet sent with flow id"; source="flowId(sentPk)"; record=vector; interpolationmode=none);
        @statistic[pktSentSeqNum](title="packet sent with sequence number"; source="seqNum(sentPk)"; record=vector; interpolationmode=none);
        @statistic[pktRcvd](title="num packets received"; source=rcvdPk; record=count; interpolationmode=none);
        @statistic[pktRcvdFlowId](title="flow id"; source="flowId(rcvdPk)"; record=vector; interpolationmode=none);
        @statistic[pktRcvdSeqNum](title="sequence number"; source="seqNum(rcvdPk)"; record=vector; interpolationmode=none);
        @statistic[pktRcvdDelay](title="end to end delay"; source="dataAge(rcvdPk)"; unit=s; record=histogram,vector,min,max; interpolationmode=none);
        @statistic[pktSentTreeId](title="packet sent with tree id"; source=sentPkTreeId; record=vector; interpolationmode=none);
        @statistic[pktRcvdTreeId](title="packet tree id"; source=rcvdPkTreeId; record=vector; interpolationmode=none);
    gates:
        input in;
        output out;
}
