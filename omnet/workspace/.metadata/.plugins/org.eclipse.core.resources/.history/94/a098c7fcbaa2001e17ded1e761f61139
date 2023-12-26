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

package nesting.simulations.examples;

import ned.DatarateChannel;
import nesting.node.ethernet.VlanEtherHostQ;
import nesting.node.ethernet.VlanEtherHostSched;
import nesting.node.ethernet.VlanEtherSwitchPreemptable;


network teach
{
    @display("bgb=761,327");
    types:
        channel C extends DatarateChannel
        {
            delay = 0s;
            datarate = 1Gbps;
        }
    submodules:
        switch0: VlanEtherSwitchPreemptable {
            parameters:
                @display("p=211,142");
            gates:
                ethg[4];
        }
        switch4: VlanEtherSwitchPreemptable {
            parameters:
                @display("p=303,142");
            gates:
                ethg[4];
        }
        workstation1: VlanEtherHostSched {
            @display("p=98,61");
        }
        workstation2: VlanEtherHostSched {
            @display("p=98,143");
        }
        workstation3: VlanEtherHostSched {
            @display("p=98,244");
        }
        workstation5: VlanEtherHostQ {
            @display("p=409,61");
        }
        workstation7: VlanEtherHostQ {
            @display("p=409,244");
        }
        workstation6: VlanEtherHostQ {
            @display("p=409,149");
        }
    connections:
        workstation1.ethg <--> C <--> switch0.ethg[0];
        workstation2.ethg <--> C <--> switch0.ethg[1];
        workstation3.ethg <--> C <--> switch0.ethg[2];
        
        switch0.ethg[3] <--> C <--> switch4.ethg[0];
        
        switch4.ethg[1] <--> C <--> workstation5.ethg;
        switch4.ethg[2] <--> C <--> workstation6.ethg;
        switch4.ethg[3] <--> C <--> workstation7.ethg;

}
