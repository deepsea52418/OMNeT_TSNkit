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

#include "nesting/application/udpapp/UdpReactiveApp.h"

#include "inet/common/ModuleAccess.h"
#include "inet/networklayer/common/L3AddressTag_m.h"
#include "inet/transportlayer/common/L4PortTag_m.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo_m.h"
#include "inet/networklayer/common/FragmentationTag_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/common/TimeTag_m.h"
#include "inet/common/Ptr.h"
#include "inet/applications/base/ApplicationPacket_m.h"

namespace nesting {

Define_Module(UdpReactiveApp);

void UdpReactiveApp::initialize(int stage)
{
    ApplicationBase::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        destPort = par("destPort");
        dontFragment = par("dontFragment");
        packetName = par("packetName");

        // init statistics
        numSent = 0;
        numRcvd = 0;
        WATCH(numSent);
        WATCH(numRcvd);
    } else if (stage == INITSTAGE_APPLICATION_LAYER) {
        const char *destAddrs = par("destAddresses");
        cStringTokenizer tokenizer(destAddrs);
        const char *token;
        while ((token = tokenizer.nextToken()) != nullptr) {
            destAddressStr.push_back(token);
            L3Address result;
            L3AddressResolver().tryResolve(token, result);
            if (result.isUnspecified())
                EV_ERROR << "cannot resolve destination address: " << token << endl;
            destAddresses.push_back(result);
        }
    }
}

void UdpReactiveApp::handleMessageWhenUp(cMessage *msg)
{
    socket.processMessage(msg);
}

void UdpReactiveApp::socketDataArrived(UdpSocket *socket, Packet *pk)
{
    // statistics
    numRcvd++;
    emit(packetReceivedSignal, pk);
    delete pk;

    std::ostringstream str;
    str << packetName << "-" << numSent;
    Packet *response = new Packet(str.str().c_str());

    const auto& payload = makeShared<ApplicationPacket>();
    payload->setChunkLength(B(par("messageLength")));
    payload->setSequenceNumber(numSent);
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());
    response->insertAtBack(payload);;
    emit(packetSentSignal, response);

    if(dontFragment)
        response->addTagIfAbsent<FragmentationReq>()->setDontFragment(true);

    // send back
    socket->sendTo(response, chooseDestAddr(), destPort);
    numSent++;
}

void UdpReactiveApp::socketErrorArrived(UdpSocket *socket, Indication *indication)
{
    EV_WARN << "Ignoring UDP error report " << indication->getName() << endl;
    delete indication;
}

void UdpReactiveApp::socketClosed(UdpSocket *socket)
{
    if (operationalState == State::STOPPING_OPERATION)
        startActiveOperationExtraTimeOrFinish(par("stopOperationExtraTime"));
}

void UdpReactiveApp::refreshDisplay() const
{
    ApplicationBase::refreshDisplay();

    char buf[100];
    sprintf(buf, "rcvd: %d pks\nsent: %d pks", numRcvd, numSent);
    getDisplayString().setTagArg("t", 0, buf);
}

void UdpReactiveApp::finish()
{
    ApplicationBase::finish();
}

void UdpReactiveApp::handleStartOperation(LifecycleOperation *operation)
{
    socket.setOutputGate(gate("socketOut"));
    int localPort = par("localPort");
    socket.bind(localPort);
    MulticastGroupList mgl = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this)->collectMulticastGroups();
    socket.joinLocalMulticastGroups(mgl);
    socket.setCallback(this);
}

void UdpReactiveApp::handleStopOperation(LifecycleOperation *operation)
{
    socket.close();
    delayActiveOperationFinish(par("stopOperationTimeout"));
}

void UdpReactiveApp::handleCrashOperation(LifecycleOperation *operation)
{
    if (operation->getRootModule() != getContainingNode(this))     // closes socket when the application crashed only
        socket.destroy();         //TODO  in real operating systems, program crash detected by OS and OS closes sockets of crashed programs.
    socket.setCallback(nullptr);
}

L3Address UdpReactiveApp::chooseDestAddr()
{
    int k = intrand(destAddresses.size());
    if (destAddresses[k].isUnspecified() || destAddresses[k].isLinkLocal()) {
        L3AddressResolver().tryResolve(destAddressStr[k].c_str(), destAddresses[k]);
    }
    return destAddresses[k];
}

} // namespace nesting

