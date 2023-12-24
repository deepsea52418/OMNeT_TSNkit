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

package nesting.linklayer.ethernet;

//
// Subscribes to signals of MAC modules within the same compound module and
// translates them to legacy signals
//
simple EtherMacLegacySignalEmitter
{
	parameters:
	    @display("i=block/cogwheel");
	    @signal[receivedExpressFrame](type=long); // unique packet id
	    @signal[startTransmissionExpressFrameSignal](type=long); // unique packet id
	    @statistic[receivedExpressFrame](title="receivedExpressFrame"; record=vector; interpolationmode=none);
        @statistic[startTxExpressFrames](title="startTxExpressFrames"; source=startTransmissionExpressFrameSignal; record=vector; interpolationmode=none);    
}
