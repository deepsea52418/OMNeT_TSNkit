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

#include "nesting/ieee8021q/relay/FilteringDatabase.h"

#include "inet/common/ModuleAccess.h"

#include <iostream>
#include <vector>
#include <sstream>

namespace nesting {

Define_Module(FilteringDatabase);

FilteringDatabase::FilteringDatabase()
{
    this->agingActive = false;
    this->agingThreshold = 0;
}

FilteringDatabase::FilteringDatabase(bool agingActive, simtime_t agingThreshold)
{
    this->agingActive = agingActive;
    this->agingThreshold = agingThreshold;
}

FilteringDatabase::~FilteringDatabase()
{
}

void FilteringDatabase::clearAdminFdb()
{
    adminFdb.clear();
}
void FilteringDatabase::initialize(int stage) {
    if (stage == INITSTAGE_LOCAL) {
        ifTable = check_and_cast<IInterfaceTable*>(getModuleByPath(par("interfaceTableModule")));
        WATCH_SET(blockedPorts);
    } else if (stage == INITSTAGE_LINK_LAYER) {
        cXMLElement* fdb = par("database");
        loadDatabase(fdb);
    }
}

int FilteringDatabase::numInitStages() const {
    return INITSTAGE_LINK_LAYER + 1;
}

void FilteringDatabase::loadDatabase(cXMLElement* xml) {
    std::string switchName = this->getModuleByPath(par("switchModule"))->getFullName();
    cXMLElement* fdb;
    //TODO this bool can probably be refactored to a nullptr check
    bool databaseFound = false;
    //try to extract the part of the filteringDatabase xml belonging to this module
    for (cXMLElement* host : xml->getChildren()) {
        if (host->hasAttributes() && host->getAttribute("id") == switchName) {
            fdb = host;
            databaseFound = true;
            break;
        }
    }

    //only continue if a filtering database was found for this switch
    if (!databaseFound) {
        return;
    }

    // Get static rules from XML file
    cXMLElement* staticRules = fdb->getFirstChildWithTag("static");

    if (staticRules != nullptr) {
        clearAdminFdb();

        cXMLElement* forwardingXml = staticRules->getFirstChildWithTag("forward");
        if (forwardingXml != nullptr) {
            this->parseEntries(forwardingXml);
        }

        cXMLElement* blockedPortsXml = staticRules->getFirstChildWithTag("blockedPorts");
        if (blockedPortsXml != nullptr) {
            this->parseBlockedPorts(blockedPortsXml);
        }
    }

    operFdb.swap(adminFdb);
    clearAdminFdb();
}

void FilteringDatabase::parseEntries(cXMLElement* xml) {
    // If present get rules from XML file
    if (xml == nullptr) {
        throw new cRuntimeError("Illegal xml input");
    }
    // Rules for individual addresses
    cXMLElementList individualAddresses = xml->getChildrenByTagName(
            "individualAddress");

    for (auto individualAddress : individualAddresses) {

        std::string macAddressStr = std::string(individualAddress->getAttribute("macAddress"));
        if (macAddressStr.empty()) {
            throw cRuntimeError(
                    "individualAddress tag in forwarding database XML must have an "
                            "macAddress attribute");
        }

        if (!individualAddress->getAttribute("port")) {
            throw cRuntimeError(
                    "individualAddress tag in forwarding database XML must have an "
                            "port attribute");
        }

        std::vector<int> interfaceIds;
        int port = atoi(individualAddress->getAttribute("port"));
        int interfaceId = ifTable->getInterface(port)->getInterfaceId();
        interfaceIds.insert(interfaceIds.begin(), 1, interfaceId);

        uint8_t vid = 0;
        if (individualAddress->getAttribute("vid"))
            vid = static_cast<uint8_t>(atoi(
                    individualAddress->getAttribute("vid")));

        // Create and insert entry for different individual address types
        if (vid == 0) {
            MacAddress macAddress;
            if (!macAddress.tryParse(macAddressStr.c_str())) {
                throw new cRuntimeError("Cannot parse invalid Mac address.");
            }
            adminFdb.insert({macAddress, std::pair<simtime_t, std::vector<int>>(0, interfaceIds)});
        } else {
            // TODO
            throw cRuntimeError(
                    "Individual address rules with VIDs aren't supported yet");
        }
    }

    // Rules for multicastAddresses
    cXMLElementList multicastAddresses = xml->getChildrenByTagName(
            "multicastAddress");
    for (auto multicastAddress : multicastAddresses) {
        std::string macAddressStr = std::string(
                multicastAddress->getAttribute("macAddress"));
        if (macAddressStr.empty()) {
            throw cRuntimeError(
                    "multicastAddress tag in forwarding database XML must have an "
                            "macAddress attribute");
        }

        if (!multicastAddress->getAttribute("ports")) {
            throw cRuntimeError(
                    "multicastAddress tag in forwarding database XML must have an "
                            "ports attribute");
        }
        std::string portsString = multicastAddress->getAttribute("ports");
        std::vector<int> ports;
        std::stringstream stream(portsString);
        while(1) {
           int n;
           stream >> n;
           if(!stream)
              break;
           ports.push_back(n);
        }

        std::vector<int> destInterfaces;
        for (int port : ports) {
            int interfaceId = ifTable->getInterface(port)->getInterfaceId();
            destInterfaces.push_back(interfaceId);
        }

        uint8_t vid = 0;
        if (multicastAddress->getAttribute("vid"))
            vid = static_cast<uint8_t>(atoi(
                    multicastAddress->getAttribute("vid")));

        // Create and insert entry for different individual address types
        if (vid == 0) {
            MacAddress macAddress;
            if (!macAddress.tryParse(macAddressStr.c_str())) {
                throw new cRuntimeError("Cannot parse invalid Mac address.");
            }
            if (!macAddress.isMulticast()) {
                throw new cRuntimeError(
                        "Mac address is not a Multicast address.");
            }
            adminFdb.insert({macAddress, std::pair<simtime_t, std::vector<int>>(0, destInterfaces)});
        } else {
            // TODO
            throw cRuntimeError(
                    "Multicast address rules with VIDs aren't supported yet");
        }
    }
}

void FilteringDatabase::parseBlockedPorts(cXMLElement* xml) {
    blockedPorts.clear();

    std::string portsString = xml->getAttribute("ports");
    std::stringstream stream(portsString);
    while(stream.good()) {
        std::string substring;
        std::getline(stream, substring, ',');
        blockedPorts.insert(atoi(substring.c_str()));
    }
}

void FilteringDatabase::handleMessage(cMessage *msg) {
    throw cRuntimeError("Must not receive messages.");
}

void FilteringDatabase::insert(MacAddress macAddress, simtime_t curTS, int interfaceId) {
    std::vector<int> tmp;
    tmp.insert(tmp.begin(), 1, interfaceId);
    operFdb[macAddress] = std::pair<simtime_t, std::vector<int>>(curTS, tmp);
}

int FilteringDatabase::getDestInterfaceId(MacAddress macAddress, simtime_t curTS) {
    simtime_t ts;
    std::vector<int> port;

    auto it = operFdb.find(macAddress);

    //is element available?
    if (it != operFdb.end()) {
        ts = it->second.first;
        port = it->second.second;
        // return if mac address belongs to multicast
        if (port.size() != 1) {
            return -1;
        }
        // static entries (ts == 0) do not age
        if (!agingActive || (ts == 0 || curTS - ts < agingThreshold)) {
            operFdb[macAddress] = std::pair<simtime_t, std::vector<int>>(curTS,
                    port);
            return port.at(0);
        } else {
            operFdb.erase(macAddress);
        }
    }

    return -1;
}

std::vector<int> FilteringDatabase::getDestInterfaceIds(MacAddress macAddress,
        simtime_t curTS) {
    simtime_t ts;
    std::vector<int> ports;

    if (!macAddress.isMulticast()) {
        throw cRuntimeError("Expected multicast MAC address!");
    }

    auto it = operFdb.find(macAddress);

    //is element available?
    if (it != operFdb.end()) {
        ts = it->second.first;
        ports = it->second.second;
        // static entries (ts == 0) do not age
        if (!agingActive || (ts == 0 || curTS - ts < agingThreshold)) {
            operFdb[macAddress] = std::pair<simtime_t, std::vector<int>>(curTS, ports);
            return ports;
        } else {
            operFdb.erase(macAddress);
        }

    }

    return ports;
}

bool FilteringDatabase::isInterfaceBlocked(int interfaceId)
{
    InterfaceEntry* interfaceEntry = ifTable->getInterfaceById(interfaceId);
    int portNumber = interfaceEntry->getIndex();
    return blockedPorts.find(portNumber) != blockedPorts.end();
}

} // namespace nesting
