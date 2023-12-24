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
// This module implements a priority scheduler scheduling the the queue
// components respectively the ~TransmissionGate modules behind it.
//
// Packets ready for transmission at the queue with the highest index are
// served first, then the packets at the lower priority queues, and finally 
// the ones in queue 0.
//
// On the input port, this module has to be connected (not necessarely direct)
// to a ~TransmissionGate vector module.
//
// This module implements the INET IPassiveQueue C++ interface so that the
// ~EtherMACFullDuplex module can request packets from it.
//
simple TransmissionSelection {
    parameters:
        @display("i=block/server");
        @class(TransmissionSelection);
        string transmissionGateVectorModule; // Path to the ~TransmissionGate vector module
        bool verbose = default(false);
    gates:
        input in[];
        output out;
}
