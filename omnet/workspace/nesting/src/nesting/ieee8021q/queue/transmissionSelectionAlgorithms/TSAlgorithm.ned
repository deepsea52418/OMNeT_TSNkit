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

package nesting.ieee8021q.queue.transmissionSelectionAlgorithms;

//
// This moduleinterface provides a stub for different transmission selection
// algorithms according to the IEEE802.1Q standard.
//
// Modules that implement this interface also have to extend the ~TSAlgorithm
// C++ class.
//
// This module has to be connected (not necessarely direct) to a
// ~LengthAwareQueue module on the input port and a ~TransmissionGate module on
// the output port.
//
// Modules conform to this interface act like a queue and provide a view on the
// ~LengthAwareQueue modules behind them by delegating isEmpty and
// packetRequest methods according to internal logic.
//
// @see ~CreditBasedShaper, ~StrictPriority, ~EtherMACFullDuplex
// @see ~TransmissionGate
//
moduleinterface TSAlgorithm
{
    parameters:
        @display("i=block/server");
        string macModule; // Path to the frame preemption module
        string gateModule; // Path to the transmission gate module
        string queueModule; // Path to the length-aware-queue module
    gates:
        input in;
        output out;
}
