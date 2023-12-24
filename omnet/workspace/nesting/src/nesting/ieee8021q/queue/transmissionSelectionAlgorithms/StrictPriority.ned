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
// This module is an implementation of the ~TSAlgorithm module.
//
// isEmpty- and requestPacket- method calls are directly delegated from the
// ~TransmissionGate to the ~LengthAwareQueue module without adding any logic.
// Therefore this algorithm does not do anything except providing a simple
// default transmission-selection-algorithm that preserves the
// ~LengthAwareQueue module's characteristics.
//
// @see ~TransmissionGate, ~LengthAwareQueue, ~TSAlgorithm
//
simple StrictPriority like TSAlgorithm
{
    parameters:
        @display("i=block/server");
        @class(StrictPriority);
        string macModule; // Path to the fp module
        string gateModule; // Path to the transmission gate module
        string queueModule; // Path to the length-aware-queue module
        bool verbose = default(false);
    gates:
        input in;
        output out;
}
