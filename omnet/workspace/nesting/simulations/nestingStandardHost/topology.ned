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

package nesting.simulations.nestingStandardHost;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.ethernet.Eth1G;
import nesting.node.ethernet.VlanEtherSwitchPreemptable;
import nesting.node.nesting.NestingStandardHost;


network NestingStandardHostSim
{
    parameters:
        @display("bgb=448.53998,443.62");
    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("is=s;p=63,39");
        }
        n0: NestingStandardHost {
            parameters:
                @display("p=130.37999,104.96");
            gates:
                ethg[1];
        }
        n1: NestingStandardHost {
            parameters:
                @display("p=75.439995,136.94");
            gates:
                ethg[1];
        }
        n2: NestingStandardHost {
            parameters:
                @display("p=86.92,272.24");
            gates:
                ethg[1];
        }
        n3: NestingStandardHost {
            parameters:
                @display("p=378.84,259.12");
            gates:
                ethg[1];
        }
        n4: NestingStandardHost {
            parameters:
                @display("p=378.84,156.62");
            gates:
                ethg[1];
        }
        n5: VlanEtherSwitchPreemptable {
            parameters:
                @display("p=162.36,205.81999");
            gates:
                ethg[4];
        }
        n6: VlanEtherSwitchPreemptable {
            parameters:
                @display("p=285.36,205.81999");
            gates:
                ethg[3];
        }
    connections:
        n0.ethg[0] <--> Eth1G <--> n5.ethg[0];
        n1.ethg[0] <--> Eth1G <--> n5.ethg[1];
        n2.ethg[0] <--> Eth1G <--> n5.ethg[2];
        n3.ethg[0] <--> Eth1G <--> n6.ethg[1];
        n4.ethg[0] <--> Eth1G <--> n6.ethg[2];
        n5.ethg[3] <--> Eth1G <--> n6.ethg[0];
}
