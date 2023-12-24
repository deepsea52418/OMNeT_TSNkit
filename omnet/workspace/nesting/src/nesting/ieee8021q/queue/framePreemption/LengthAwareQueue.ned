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

package nesting.ieee8021q.queue.framePreemption;

//
// Queue with fixed capacity and ability to consider packet sizes for length-
// aware-scheduling.
//
// This module must be connected (not necessarely direct) to a ~TSAlgorithm
// module the ouput port.
//
// @see ~TSAlgorithm
//
simple LengthAwareQueue
{
    parameters:
        int bufferCapacity @unit(bit) = default(100*1500*8b); // Buffer can hold up to 100 MTU size packets
        string queueName = default("l2queue"); // Name of the inner cQueue object, used in the 'q' tag of the display string
        bool expressQueue = default(true);
        string transmissionSelectionAlgorithmModule; // Path to the ~TSAlgorithm module
        @display("i=block/queue");
        @class(LengthAwareQueue);
        @signal[rcvdPk](type=long); // type=unique packet id
        @signal[enqueuePk](type=long); // type=unique packet id
        @signal[dequeuePk](type=long); // type=unique packet id
        @signal[dropPkByQueue](type=long); // type=unique packet id
        @signal[queueingTime](type=simtime_t; unit=s);
        @signal[queueLength](type=long);
        @statistic[enqueuePk](record=vector; interpolationmode=none);
        @statistic[dequeuePk](record=vector; interpolationmode=none);
        @statistic[rcvdPk](title="received packets"; record=count,vector; interpolationmode=none);
        @statistic[dropPk](title="dropped packets"; source=dropPkByQueue; record=count,vector; interpolationmode=none);
        @statistic[queueingTime](title="queueing time"; record=histogram,vector; interpolationmode=none);
        @statistic[queueLength](title="queue length"; record=max,timeavg,vector; interpolationmode=sample-hold);
        bool verbose = default(false);
    gates:
        input in;
        output out;
}
