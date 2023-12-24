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
// This module implements the credit-based-shaper transmission selection
// algorithm according to the IEEE802.1Q standard and provides an
// implementation of the ~TSAlgorithm module.
//
// The ~CreditBasedShaper has an internal credit value. If this credit value
// is negative, this (queuing-)module is considered empty. Otherwise the
// isEmpty-state of the ~LengthAwareQueue on the input port is used instead.
//
// @see ~LengthAwareQueue, ~TransmissionGate, ~EtherMACFullDuplex, ~TSAlgorithm
//
simple CreditBasedShaper like TSAlgorithm
{
    parameters:
        @display("i=block/server");
        @class(CreditBasedShaper);
        string macModule; // Path to the fp module
        string gateModule; // Path to the transmission gate module
        string queueModule; // Path to the length-aware-queue module
        double idleSlopeFactor; // A number in the range (0,1). This value is multiplied to the port transmit rate.
        bool verbose = default(false);
    gates:
        input in;
        output out;
}
