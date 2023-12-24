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

import inet.common.queue.IOutputQueue;
import nesting.ieee8021q.queue.framePreemption.LengthAwareQueue;
import nesting.ieee8021q.queue.gating.GateController;
import nesting.ieee8021q.queue.gating.TransmissionGate;
import nesting.ieee8021q.queue.transmissionSelectionAlgorithms.TSAlgorithm;


//
// This module implements a queuing network providing scheduling of congested
// packets for a given output port according to the IEEE802.1Q standard,
// described in chapter 8.6.6 - 8.6.8.
//
// For every output port of an IEEE802.1Q conform switch an instance of this
// module is used the queue packets. 
//
// @see ~QueuingFrames, ~TransmissionGate, ~Schedule, ~TransmissionSelection
// @see ~TSAlgorithm, ~GateController, ~LengthAwareQueue
//
module Queuing like IOutputQueue
{
    parameters:
        @display("i=block/queue;bgb=1254,645");
        int numberOfQueues = default(8);
        string defaultTSA = "StrictPriority"; // Default transmission-selection-algorithm implementation
    gates:
        input in;
        output out;
    submodules:
        queuingFrames: QueuingFrames {
            @display("p=289,38");
        }
        queues[numberOfQueues]: LengthAwareQueue {
            @display("p=287.7675,161.9675,r,120;q=l2queue");
            transmissionSelectionAlgorithmModule = "^.tsAlgorithms[" + string(index) + "]";
        }
        tsAlgorithms[numberOfQueues]: <default(defaultTSA)> like TSAlgorithm {
            @display("p=287.7675,284.6225,r,120");
            gateModule = "^.tGates[" + string(index) + "]";
            queueModule = "^.queues[" + string(index) + "]";
        }
        tGates[numberOfQueues]: TransmissionGate {
            @display("p=287.7675,408.85,r,120");
            transmissionSelectionAlgorithmModule = "^.tsAlgorithms[" + string(index) + "]";
            transmissionSelectionModule = "^.transmissionSelection";
            gateControllerModule = "^.gateController";
        }
        transmissionSelection: TransmissionSelection {
            @display("p=287.7675,548.8025,r,120");
            transmissionGateVectorModule = "^.tGates[0]";
        }
        gateController: GateController {
            @display("p=71,38;is=s");
        }
    connections:
        in --> queuingFrames.in;
        for i=0..numberOfQueues-1 {
            queuingFrames.out++ --> queues[i].in;
            queues[i].out --> tsAlgorithms[i].in;
            tsAlgorithms[i].out --> tGates[i].in;
            tGates[i].out --> transmissionSelection.in++;
        }
        transmissionSelection.out --> out;
}
