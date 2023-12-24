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

import inet.node.inet.StandardHost;
import nesting.common.time.IClock;
import nesting.common.time.IClock2;
import nesting.common.time.IOscillator;
import nesting.linklayer.ethernet.EtherMacLegacySignalEmitter;

module NestingStandardHost extends StandardHost
{
    parameters:
        @display("i=device/pc2");
        **.clockModule = default(absPath(".clock"));
        **.gateController.clockModule = default(absPath(".legacyClock"));
        **.tGates[*].clockModule = default(absPath(".legacyClock"));
        **.oscillatorModule = default(absPath(".oscillator"));
        **.interfaceTableModule = default(absPath(".interfaceTable"));
        eth[*].typename = default("NestingEthernetInterface");
    submodules:
        oscillator: <default("IdealOscillator")> like IOscillator {
            @display("p=196,211;is=s");
        }
        clock: <default("RealtimeClock")> like IClock2 {
            @display("p=196,122;is=s");
        }
        legacySignals: EtherMacLegacySignalEmitter {
            @display("p=195.29999,296.09998;is=s");
        }
        legacyClock: <default("LegacyClock")> like IClock {
            @display("p=53,39;is=s");
        }
}
