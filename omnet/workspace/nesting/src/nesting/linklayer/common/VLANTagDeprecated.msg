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

cplusplus{{
#include "inet/common/TagBase_m.h"
}}

class noncobject inet::TagBase;

namespace nesting;

//
// @deprecated
//
class DeprecatedVLANTagBase extends inet::TagBase
{
    uint8_t pcp;    
    bool de;        
    short VID=0;
}

//
// @deprecated
// Determines VLAN 802.1Q parameters for an outgoing packet.
//
class VLANTagReq extends DeprecatedVLANTagBase
{
    
}

//
// @deprecated
// Specifies VLAN 802.1Q parameters for an incoming packet.
//
class VLANTagInd extends DeprecatedVLANTagBase
{
    
}