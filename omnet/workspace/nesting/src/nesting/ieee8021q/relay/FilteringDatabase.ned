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

//
// This module is used to store filtering and forwarding rules for packet
// transmission used by modules like the ~RelayUnit.
//
// A initial configuration can be loaded by a XML file.
//
simple FilteringDatabase
{
    parameters:
	    @display("i=block/table2");
	    @class(FilteringDatabase);
	    xml database;
	    string switchModule = default("^"); // Path to the ~VlanEtherSwitch module
	    string clockModule = default("^.clock"); // Path to the ~IClock module.
	    string interfaceTableModule = default("^.interfaceTable"); // The path to the InterfaceTable module
	    bool verbose = default(false);
}
