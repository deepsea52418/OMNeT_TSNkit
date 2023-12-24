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

package nesting.ieee8021q.relay;

import inet.linklayer.contract.IMacRelayUnit;


//
// This implementation of the ~RelayUnit interface provides forwarding or
// filtering of frames according to provided information by a
// ~FilteringDatabase module.
//
// @see ~RelayUnit, ~FilteringDatabase
//
simple ForwardingRelayUnit like IMacRelayUnit
{
    parameters:
        @display("i=block/switch");
        @class(ForwardingRelayUnit);
        int numberOfPorts;
        string filteringDatabaseModule = default("^.filteringDatabase"); // Path to the ~FilteringDatabase module
        string interfaceTableModule = default("^.interfaceTable"); // The path to the InterfaceTable module
        string vlanTagType @enum("c","s") = default("c");
        bool verbose = default(false);
	gates:
   		input ifIn @labels(EtherFrame);
        output ifOut @labels(EtherFrame);
        input upperLayerIn;
        output upperLayerOut;
}
