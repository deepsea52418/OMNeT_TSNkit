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
// This module implements a gating mechanism for queues behind it.
//
// This module has to be connected (not necessarely direct) to a
// ~TSAlgorithm module on the input port and a ~TransmissionSelection module on
// the outgoing port. 
// 
// The gate acts as queue itself and is considered empty if the current gate 
// state is "closed". Otherwise the isEmpty state of the ~TSAlgorithm module
// is used.
//
// @see ~TSAlgorithm, ~TransmissionSelection, ~IClock
//
simple TransmissionGate
{
    parameters:
        @display("i=block/source");
        @class(TransmissionGate);
        string gateControllerModule; // Path to the gate controller module
        string transmissionSelectionModule; // Path to the transmission selection module
        string transmissionSelectionAlgorithmModule; // Path to the transmission selection algorithm module
        string clockModule;
        bool lengthAwareSchedulingEnabled = default(true);
        bool verbose = default(false);
        @signal[gateStateChanged](type=bool);
        @statistic[gateStateChanged](title="gateStateChanged"; record=vector; interpolationmode=none);
    gates:
        input in;
        output out;
}
