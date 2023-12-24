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

#include "nesting/linklayer/ethernet/EtherMacLegacySignalEmitter.h"
#include "nesting/linklayer/framePreemption/EtherMACFullDuplexPreemptable.h"

#include "inet/common/Simsignals.h"
#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/ethernet/EtherMacBase.h"

#include <iostream>

using namespace inet;

namespace nesting {

Define_Module(EtherMacLegacySignalEmitter);

simsignal_t EtherMacLegacySignalEmitter::startTransmissionExpressFrameSignal = registerSignal("startTransmissionExpressFrameSignal");
simsignal_t EtherMacLegacySignalEmitter::receivedExpressFrame = registerSignal("receivedExpressFrame");

void EtherMacLegacySignalEmitter::initialize(int stage)
{
    if (stage == INITSTAGE_LOCAL) {
        this->getParentModule()->subscribe(packetReceivedFromUpperSignal, this);
        this->getParentModule()->subscribe(packetReceivedFromLowerSignal, this);
    }
}

void EtherMacLegacySignalEmitter::handleMessage(cMessage *msg)
{
    throw cRuntimeError("This module can't handle messages.");
}

void EtherMacLegacySignalEmitter::receiveSignal(cComponent *source, simsignal_t signalId, cObject *obj, cObject *details)
{
    if (dynamic_cast<EtherMacBase*>(source) != nullptr && dynamic_cast<EtherMACFullDuplexPreemptable*>(source) == nullptr) {
        Packet* packet = check_and_cast<Packet*>(obj);
        if (signalId == packetReceivedFromUpperSignal) {
            emit(startTransmissionExpressFrameSignal, packet->getTreeId());
        } else if (signalId == packetReceivedFromLowerSignal) {
            emit(receivedExpressFrame, packet->getTreeId());
        }
    }
}

} //namespace
