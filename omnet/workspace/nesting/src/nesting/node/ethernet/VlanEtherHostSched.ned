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

package nesting.node.ethernet;

import inet.linklayer.contract.IEthernetInterface;
import inet.networklayer.common.InterfaceTable;
import nesting.application.ethernet.VlanEtherTrafGenSched;
import nesting.common.time.IClock;
import nesting.common.time.IOscillator;


//
// @deprecated
//
// Simple Host with the capability to send out frames according to a given schedule
//
// @see ~VlanEtherTrafGen
//
module VlanEtherHostSched
{
    parameters:
        string fcsMode @enum("declared","computed") = default("declared");
        @networkNode();
        @labels(node,ethernet-node);
        @display("i=device/pc2;bgb=385,371");
        *.fcsMode = fcsMode;
        **.clockModule = default(absPath(".legacyClock"));
        **.oscillatorModule = default(absPath(".oscillator"));
        **.interfaceTableModule = default(absPath(".interfaceTable"));
    gates:
        inout ethg @labels(EtherFrame-conn);
    submodules:
        trafGenSchedApp: VlanEtherTrafGenSched {
            @display("p=138,126");
        }
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=311,211;is=s");
        }
        oscillator: <default("IdealOscillator")> like IOscillator {
            @display("p=311,40;is=s");
        }
        legacyClock: <default("LegacyClock")> like IClock {
            @display("p=311,96;is=s");
        }
        eth: <default("EthernetInterface")> like IEthernetInterface {
            parameters:
                @display("p=232,283,row,150;q=txQueue");
                encap.typename = "EtherEncap";
                qEncap.typename = "EnhancedIeee8021qEncap";
                mac.typename = "EtherMACFullDuplexPreemptable";
                mac.mtu = 1500B;
                queue.typename = "Queuing";
                queue.tsAlgorithms[*].macModule = absPath(".mac");
            	queue.gateController.macModule = absPath(".mac");
            	queue.numberOfQueues = 1;
        }
    connections:
        trafGenSchedApp.out --> eth.upperLayerIn;
        eth.upperLayerOut --> trafGenSchedApp.in;

        eth.phys <--> ethg;
}
