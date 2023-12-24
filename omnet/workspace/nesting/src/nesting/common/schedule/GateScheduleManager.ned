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

package nesting.common.schedule;

simple GateScheduleManager
{
    parameters:
        @display("i=block/table2");
        string clockModule; // Path to clock module implementing IClock2 interface
        bool gateEnabled = default(false); // If gateEnabled is true, then operGateStates will be set from the current schedule (operSchedule).
        string initialAdminGateStates = default("11111111"); // Default bitvector (8bit) for operGateStates if gateEnabled is false.
        xml initialAdminSchedule = default(xml("<schedule CycleTime=\"1h\"><entry GateStates=\"11111111\" TimeInterval=\"1h\"/></schedule>")); // schedule that will be loaded initially if gateEnabled is true.
}
