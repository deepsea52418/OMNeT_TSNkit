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

package nesting.node.nesting;

import inet.linklayer.ethernet.EthernetInterface;
import inet.linklayer.contract.IEthernetInterface;

module NestingEthernetInterface extends EthernetInterface like IEthernetInterface {
    parameters:
        @display("p=232,283,row,150;q=txQueue");
        encap.typename = "EtherEncap";
        qEncap.typename = "EnhancedIeee8021qEncap";
        mac.typename = "EtherMACFullDuplexPreemptable";
        mac.mtu = 1500B;
        queue.typename = "Queuing";
        queue.tsAlgorithms[*].macModule = absPath(".mac");
    	queue.gateController.macModule = absPath(".mac");
    	queue.numberOfQueues = default(1);
}