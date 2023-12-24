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

package nesting.ieee8021q.queue.gating;

//
// This module controls the state of multiple transmission gates according
// to the IEEE 802.1Qbv standard chapter 8.6.8.4.
//
// The module uses an internal schedule and an external clock component to
// determine gate states and gate changes.
//
// @see ~Clock, ~TransmissionGate
//
simple GateController
{
    parameters:
        @display("i=block/table");
        @class(GateController);
        string clockModule = default("^.^.^.clock");
        string switchModule = default("^.^.^");
        string networkInterfaceModule = default("^.^");
        string macModule;
        string transmissionGateVectorModule = default("^.tGates[0]");
        bool verbose = default(false);
        bool enableHoldAndRelease = default(true);
        xml initialSchedule = default(xml("<schedule cycleTime=\"1s\"><entry><length>1s</length><bitvector>11111111</bitvector></entry></schedule>"));
}
