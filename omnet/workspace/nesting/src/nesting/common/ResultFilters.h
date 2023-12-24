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

#ifndef NESTING_COMMON_RESULTFILTER_H_
#define NESTING_COMMON_RESULTFILTER_H_

#include <omnetpp.h>

using namespace omnetpp;

namespace nesting {

/** Filter that expects a Packet with a FlowMetaTag and outputs the flow id. */
class FlowIdFilter : public cObjectResultFilter
{
public:
    virtual void receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details) override;
};

/**
 * Filter that expects a Packet with a FlowMetaTag and outputs the sequence
 * number of the respective flow.
 */
class SeqNumFilter : public cObjectResultFilter
{
public:
    virtual void receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details) override;
};

} // namespace nesting

#endif