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


network mytest
{
    @display("bgb=738,358");
    types:
        channel C extends DatarateChannel
        {
            delay = 0.1us;
            datarate = 1Gbps;
        }
    submodules:
        switchA: VlanEtherSwitchPreemptable {
            parameters:
                @display("p=188,127");
            gates:
                ethg[3];
        }
        switchB: VlanEtherSwitchPreemptable {
            parameters:
                @display("p=327,127");
            gates:
                ethg[3];
        }
        workstation1: VlanEtherHostSched {
            @display("p=79,128");
        }
        backupServer: VlanEtherHostQ {
            @display("p=556,128");
        }
        robotController: VlanEtherHostSched {
            @display("p=79,202");
        }
        roboticArm: VlanEtherHostSched {
            @display("p=556,202");
        }
        switchE: VlanEtherSwitchPreemptable {
            parameters:
                @display("p=327,201");
            gates:
                ethg[3];
        }
        switchD: VlanEtherSwitchPreemptable {
            parameters:
                @display("p=188,201");
            gates:
                ethg[3];
        }
        switchC: VlanEtherSwitchPreemptable {
            parameters:
                @display("p=440,127");
            gates:
                ethg[3];
        }
        switchF: VlanEtherSwitchPreemptable {
            parameters:
                @display("p=440,201");
            gates:
                ethg[3];
        }
    connections:
        robotController.ethg <--> C <--> switchD.ethg[0];
        workstation1.ethg <--> C <--> switchA.ethg[0];

        roboticArm.ethg <--> C <--> switchF.ethg[2];
        backupServer.ethg <--> C <--> switchC.ethg[2];

        switchA.ethg[2] <--> C <--> switchB.ethg[0];
        switchA.ethg[1] <--> C <--> switchD.ethg[1];
        switchE.ethg[0] <--> C <--> switchD.ethg[2];
        switchE.ethg[1] <--> C <--> switchB.ethg[1];
        switchE.ethg[2] <--> C <--> switchF.ethg[0];
        switchB.ethg[2] <--> C <--> switchC.ethg[0];
        switchC.ethg[1] <--> C <--> switchF.ethg[1];

}
