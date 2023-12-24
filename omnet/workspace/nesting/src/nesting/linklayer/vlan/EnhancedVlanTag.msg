//
// Copyright (C) 2003 Andras Varga; CTIE, Monash University, Australia
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

cplusplus{{
#include "inet/linklayer/vlan/VlanTag_m.h"
}}

class noncobject inet::VlanTagBase;

namespace nesting;

//
// This is an abstract base class that should not be directly added as a tag.
//
class EnhancedVlanTagBase extends inet::VlanTagBase
{
    int pcp = 0;
    bool de = false;
}

//
// This request determines the vlan that should be used to send the packet.
// It may be present on a packet from the application to the mac protocol.
//
class EnhancedVlanReq extends EnhancedVlanTagBase
{
}

//
// This indication specifies the vlan that was used to receive the packet.
// It may be present on a packet from the mac protocol to the application.
//
class EnhancedVlanInd extends EnhancedVlanTagBase
{
}
