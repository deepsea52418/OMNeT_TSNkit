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

package nesting.application.udpapp;

import inet.applications.contract.IApp;


module UdpScheduledTrafficApp like IApp
{
    parameters:
        @display("i=block/app;bgb=208,249");
        **.datagramScheduleManagerModule = default(absPath(".scheduleManager"));
    gates:
        input socketIn;
        output socketOut;
    submodules:
        trafficGenerator: UdpScheduledTrafficGenerator {
            @display("p=108,157");
        }
        scheduleManager: DatagramScheduleManager {
            @display("p=108,63;is=s");
        }
    connections:
        socketIn --> trafficGenerator.socketIn;
        trafficGenerator.socketOut --> socketOut;
}
