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

package nesting.application.ethernet;

import inet.applications.ethernet.EtherTrafGen;


//
// @deprecated
//
// Traffic generator application for VLAN tagged ethernet frames. This
// module should be connected to a VLANEncap module and the VLANEncap
// module should be connected to an EtherEncap module to provide encap/decap
// functionality for VLAN Tag and Ethernet Header.
//
// This application module does not generate encapsulated packets but adds
// the necessary information, that other modules (EtherEncap, VLANEncap) can
// provide the necessary encapsulation/decapsulation. Therefore an
// Ieee8021QCtrl control information is added to packets.
//
// @see ~VLANEncap, ~EtherEncap, ~Ieee8021QCtrl
//
simple VlanEtherTrafGen extends EtherTrafGen
{
    parameters:
        @class(VlanEtherTrafGen);
        bool vlanTagEnabled = default(true);	// When true, the application's packets will be VLAN encapsulated by the VLANEncap module
        int pcp = default(0);					// PCP (Priority Code Point) value that is added to the packets control information
        bool dei = default(false);				// DEI (Drop Eligible Indicator) that is added to the packets control information
        int vid = default(1);					// VID (VLAN Identifier) value that is added to the packets control information
        bool verbose = default(false);
}
