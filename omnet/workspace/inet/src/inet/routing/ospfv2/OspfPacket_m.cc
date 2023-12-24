//
// Generated file, do not edit! Created by nedtool 5.6 from inet/routing/ospfv2/OspfPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include "OspfPacket_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace {
template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)(static_cast<const omnetpp::cObject *>(t));
}

template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && !std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)dynamic_cast<const void *>(t);
}

template <class T> inline
typename std::enable_if<!std::is_polymorphic<T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)static_cast<const void *>(t);
}

}

namespace inet {
namespace ospf {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ospf::OspfPacketType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ospf::OspfPacketType"));
    e->insert(HELLO_PACKET, "HELLO_PACKET");
    e->insert(DATABASE_DESCRIPTION_PACKET, "DATABASE_DESCRIPTION_PACKET");
    e->insert(LINKSTATE_REQUEST_PACKET, "LINKSTATE_REQUEST_PACKET");
    e->insert(LINKSTATE_UPDATE_PACKET, "LINKSTATE_UPDATE_PACKET");
    e->insert(LINKSTATE_ACKNOWLEDGEMENT_PACKET, "LINKSTATE_ACKNOWLEDGEMENT_PACKET");
)

OspfOptions::OspfOptions()
{
    this->unused_1 = false;
    this->E_ExternalRoutingCapability = false;
    this->MC_MulticastForwarding = false;
    this->NP_Type7LSA = false;
    this->EA_ForwardExternalLSAs = false;
    this->DC_DemandCircuits = false;
    this->unused_2 = false;
    this->unused_3 = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const OspfOptions& a)
{
    doParsimPacking(b,a.unused_1);
    doParsimPacking(b,a.E_ExternalRoutingCapability);
    doParsimPacking(b,a.MC_MulticastForwarding);
    doParsimPacking(b,a.NP_Type7LSA);
    doParsimPacking(b,a.EA_ForwardExternalLSAs);
    doParsimPacking(b,a.DC_DemandCircuits);
    doParsimPacking(b,a.unused_2);
    doParsimPacking(b,a.unused_3);
}

void __doUnpacking(omnetpp::cCommBuffer *b, OspfOptions& a)
{
    doParsimUnpacking(b,a.unused_1);
    doParsimUnpacking(b,a.E_ExternalRoutingCapability);
    doParsimUnpacking(b,a.MC_MulticastForwarding);
    doParsimUnpacking(b,a.NP_Type7LSA);
    doParsimUnpacking(b,a.EA_ForwardExternalLSAs);
    doParsimUnpacking(b,a.DC_DemandCircuits);
    doParsimUnpacking(b,a.unused_2);
    doParsimUnpacking(b,a.unused_3);
}

class OspfOptionsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_unused_1,
        FIELD_E_ExternalRoutingCapability,
        FIELD_MC_MulticastForwarding,
        FIELD_NP_Type7LSA,
        FIELD_EA_ForwardExternalLSAs,
        FIELD_DC_DemandCircuits,
        FIELD_unused_2,
        FIELD_unused_3,
    };
  public:
    OspfOptionsDescriptor();
    virtual ~OspfOptionsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfOptionsDescriptor)

OspfOptionsDescriptor::OspfOptionsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfOptions)), "")
{
    propertynames = nullptr;
}

OspfOptionsDescriptor::~OspfOptionsDescriptor()
{
    delete[] propertynames;
}

bool OspfOptionsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfOptions *>(obj)!=nullptr;
}

const char **OspfOptionsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfOptionsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfOptionsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OspfOptionsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_unused_1
        FD_ISEDITABLE,    // FIELD_E_ExternalRoutingCapability
        FD_ISEDITABLE,    // FIELD_MC_MulticastForwarding
        FD_ISEDITABLE,    // FIELD_NP_Type7LSA
        FD_ISEDITABLE,    // FIELD_EA_ForwardExternalLSAs
        FD_ISEDITABLE,    // FIELD_DC_DemandCircuits
        FD_ISEDITABLE,    // FIELD_unused_2
        FD_ISEDITABLE,    // FIELD_unused_3
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *OspfOptionsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "unused_1",
        "E_ExternalRoutingCapability",
        "MC_MulticastForwarding",
        "NP_Type7LSA",
        "EA_ForwardExternalLSAs",
        "DC_DemandCircuits",
        "unused_2",
        "unused_3",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int OspfOptionsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unused_1") == 0) return base+0;
    if (fieldName[0] == 'E' && strcmp(fieldName, "E_ExternalRoutingCapability") == 0) return base+1;
    if (fieldName[0] == 'M' && strcmp(fieldName, "MC_MulticastForwarding") == 0) return base+2;
    if (fieldName[0] == 'N' && strcmp(fieldName, "NP_Type7LSA") == 0) return base+3;
    if (fieldName[0] == 'E' && strcmp(fieldName, "EA_ForwardExternalLSAs") == 0) return base+4;
    if (fieldName[0] == 'D' && strcmp(fieldName, "DC_DemandCircuits") == 0) return base+5;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unused_2") == 0) return base+6;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unused_3") == 0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfOptionsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_unused_1
        "bool",    // FIELD_E_ExternalRoutingCapability
        "bool",    // FIELD_MC_MulticastForwarding
        "bool",    // FIELD_NP_Type7LSA
        "bool",    // FIELD_EA_ForwardExternalLSAs
        "bool",    // FIELD_DC_DemandCircuits
        "bool",    // FIELD_unused_2
        "bool",    // FIELD_unused_3
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfOptionsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfOptionsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfOptionsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfOptions *pp = (OspfOptions *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *OspfOptionsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfOptions *pp = (OspfOptions *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfOptionsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfOptions *pp = (OspfOptions *)object; (void)pp;
    switch (field) {
        case FIELD_unused_1: return bool2string(pp->unused_1);
        case FIELD_E_ExternalRoutingCapability: return bool2string(pp->E_ExternalRoutingCapability);
        case FIELD_MC_MulticastForwarding: return bool2string(pp->MC_MulticastForwarding);
        case FIELD_NP_Type7LSA: return bool2string(pp->NP_Type7LSA);
        case FIELD_EA_ForwardExternalLSAs: return bool2string(pp->EA_ForwardExternalLSAs);
        case FIELD_DC_DemandCircuits: return bool2string(pp->DC_DemandCircuits);
        case FIELD_unused_2: return bool2string(pp->unused_2);
        case FIELD_unused_3: return bool2string(pp->unused_3);
        default: return "";
    }
}

bool OspfOptionsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfOptions *pp = (OspfOptions *)object; (void)pp;
    switch (field) {
        case FIELD_unused_1: pp->unused_1 = string2bool(value); return true;
        case FIELD_E_ExternalRoutingCapability: pp->E_ExternalRoutingCapability = string2bool(value); return true;
        case FIELD_MC_MulticastForwarding: pp->MC_MulticastForwarding = string2bool(value); return true;
        case FIELD_NP_Type7LSA: pp->NP_Type7LSA = string2bool(value); return true;
        case FIELD_EA_ForwardExternalLSAs: pp->EA_ForwardExternalLSAs = string2bool(value); return true;
        case FIELD_DC_DemandCircuits: pp->DC_DemandCircuits = string2bool(value); return true;
        case FIELD_unused_2: pp->unused_2 = string2bool(value); return true;
        case FIELD_unused_3: pp->unused_3 = string2bool(value); return true;
        default: return false;
    }
}

const char *OspfOptionsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *OspfOptionsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfOptions *pp = (OspfOptions *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(OspfPacket)

OspfPacket::OspfPacket() : ::inet::FieldsChunk()
{
}

OspfPacket::OspfPacket(const OspfPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

OspfPacket::~OspfPacket()
{
}

OspfPacket& OspfPacket::operator=(const OspfPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void OspfPacket::copy(const OspfPacket& other)
{
    this->version = other.version;
    this->type = other.type;
    this->routerID = other.routerID;
    this->areaID = other.areaID;
    this->crc = other.crc;
    this->crcMode = other.crcMode;
    this->authenticationType = other.authenticationType;
    for (size_t i = 0; i < 8; i++) {
        this->authentication[i] = other.authentication[i];
    }
}

void OspfPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->routerID);
    doParsimPacking(b,this->areaID);
    doParsimPacking(b,this->crc);
    doParsimPacking(b,this->crcMode);
    doParsimPacking(b,this->authenticationType);
    doParsimArrayPacking(b,this->authentication,8);
}

void OspfPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->routerID);
    doParsimUnpacking(b,this->areaID);
    doParsimUnpacking(b,this->crc);
    doParsimUnpacking(b,this->crcMode);
    doParsimUnpacking(b,this->authenticationType);
    doParsimArrayUnpacking(b,this->authentication,8);
}

char OspfPacket::getVersion() const
{
    return this->version;
}

void OspfPacket::setVersion(char version)
{
    handleChange();
    this->version = version;
}

inet::ospf::OspfPacketType OspfPacket::getType() const
{
    return this->type;
}

void OspfPacket::setType(inet::ospf::OspfPacketType type)
{
    handleChange();
    this->type = type;
}

const Ipv4Address& OspfPacket::getRouterID() const
{
    return this->routerID;
}

void OspfPacket::setRouterID(const Ipv4Address& routerID)
{
    handleChange();
    this->routerID = routerID;
}

const Ipv4Address& OspfPacket::getAreaID() const
{
    return this->areaID;
}

void OspfPacket::setAreaID(const Ipv4Address& areaID)
{
    handleChange();
    this->areaID = areaID;
}

uint16_t OspfPacket::getCrc() const
{
    return this->crc;
}

void OspfPacket::setCrc(uint16_t crc)
{
    handleChange();
    this->crc = crc;
}

inet::CrcMode OspfPacket::getCrcMode() const
{
    return this->crcMode;
}

void OspfPacket::setCrcMode(inet::CrcMode crcMode)
{
    handleChange();
    this->crcMode = crcMode;
}

short OspfPacket::getAuthenticationType() const
{
    return this->authenticationType;
}

void OspfPacket::setAuthenticationType(short authenticationType)
{
    handleChange();
    this->authenticationType = authenticationType;
}

size_t OspfPacket::getAuthenticationArraySize() const
{
    return 8;
}

char OspfPacket::getAuthentication(size_t k) const
{
    if (k >= 8) throw omnetpp::cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    return this->authentication[k];
}

void OspfPacket::setAuthentication(size_t k, char authentication)
{
    if (k >= 8) throw omnetpp::cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    handleChange();
    this->authentication[k] = authentication;
}

class OspfPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_version,
        FIELD_type,
        FIELD_routerID,
        FIELD_areaID,
        FIELD_crc,
        FIELD_crcMode,
        FIELD_authenticationType,
        FIELD_authentication,
    };
  public:
    OspfPacketDescriptor();
    virtual ~OspfPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfPacketDescriptor)

OspfPacketDescriptor::OspfPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfPacket)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

OspfPacketDescriptor::~OspfPacketDescriptor()
{
    delete[] propertynames;
}

bool OspfPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfPacket *>(obj)!=nullptr;
}

const char **OspfPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OspfPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_version
        0,    // FIELD_type
        0,    // FIELD_routerID
        0,    // FIELD_areaID
        FD_ISEDITABLE,    // FIELD_crc
        0,    // FIELD_crcMode
        FD_ISEDITABLE,    // FIELD_authenticationType
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_authentication
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *OspfPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "type",
        "routerID",
        "areaID",
        "crc",
        "crcMode",
        "authenticationType",
        "authentication",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int OspfPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "version") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+1;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routerID") == 0) return base+2;
    if (fieldName[0] == 'a' && strcmp(fieldName, "areaID") == 0) return base+3;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crc") == 0) return base+4;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crcMode") == 0) return base+5;
    if (fieldName[0] == 'a' && strcmp(fieldName, "authenticationType") == 0) return base+6;
    if (fieldName[0] == 'a' && strcmp(fieldName, "authentication") == 0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",    // FIELD_version
        "inet::ospf::OspfPacketType",    // FIELD_type
        "inet::Ipv4Address",    // FIELD_routerID
        "inet::Ipv4Address",    // FIELD_areaID
        "uint16_t",    // FIELD_crc
        "inet::CrcMode",    // FIELD_crcMode
        "short",    // FIELD_authenticationType
        "char",    // FIELD_authentication
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_crcMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *OspfPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::ospf::OspfPacketType";
            return nullptr;
        case FIELD_crcMode:
            if (!strcmp(propertyname, "enum")) return "inet::CrcMode";
            return nullptr;
        default: return nullptr;
    }
}

int OspfPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfPacket *pp = (OspfPacket *)object; (void)pp;
    switch (field) {
        case FIELD_authentication: return 8;
        default: return 0;
    }
}

const char *OspfPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfPacket *pp = (OspfPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfPacket *pp = (OspfPacket *)object; (void)pp;
    switch (field) {
        case FIELD_version: return long2string(pp->getVersion());
        case FIELD_type: return enum2string(pp->getType(), "inet::ospf::OspfPacketType");
        case FIELD_routerID: return pp->getRouterID().str();
        case FIELD_areaID: return pp->getAreaID().str();
        case FIELD_crc: return ulong2string(pp->getCrc());
        case FIELD_crcMode: return enum2string(pp->getCrcMode(), "inet::CrcMode");
        case FIELD_authenticationType: return long2string(pp->getAuthenticationType());
        case FIELD_authentication: return long2string(pp->getAuthentication(i));
        default: return "";
    }
}

bool OspfPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfPacket *pp = (OspfPacket *)object; (void)pp;
    switch (field) {
        case FIELD_version: pp->setVersion(string2long(value)); return true;
        case FIELD_crc: pp->setCrc(string2ulong(value)); return true;
        case FIELD_authenticationType: pp->setAuthenticationType(string2long(value)); return true;
        case FIELD_authentication: pp->setAuthentication(i,string2long(value)); return true;
        default: return false;
    }
}

const char *OspfPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *OspfPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfPacket *pp = (OspfPacket *)object; (void)pp;
    switch (field) {
        case FIELD_routerID: return toVoidPtr(&pp->getRouterID()); break;
        case FIELD_areaID: return toVoidPtr(&pp->getAreaID()); break;
        default: return nullptr;
    }
}

Register_Class(OspfHelloPacket)

OspfHelloPacket::OspfHelloPacket() : ::inet::ospf::OspfPacket()
{
}

OspfHelloPacket::OspfHelloPacket(const OspfHelloPacket& other) : ::inet::ospf::OspfPacket(other)
{
    copy(other);
}

OspfHelloPacket::~OspfHelloPacket()
{
    delete [] this->neighbor;
}

OspfHelloPacket& OspfHelloPacket::operator=(const OspfHelloPacket& other)
{
    if (this == &other) return *this;
    ::inet::ospf::OspfPacket::operator=(other);
    copy(other);
    return *this;
}

void OspfHelloPacket::copy(const OspfHelloPacket& other)
{
    this->networkMask = other.networkMask;
    this->helloInterval = other.helloInterval;
    this->options = other.options;
    this->routerPriority = other.routerPriority;
    this->routerDeadInterval = other.routerDeadInterval;
    this->designatedRouter = other.designatedRouter;
    this->backupDesignatedRouter = other.backupDesignatedRouter;
    delete [] this->neighbor;
    this->neighbor = (other.neighbor_arraysize==0) ? nullptr : new Ipv4Address[other.neighbor_arraysize];
    neighbor_arraysize = other.neighbor_arraysize;
    for (size_t i = 0; i < neighbor_arraysize; i++) {
        this->neighbor[i] = other.neighbor[i];
    }
}

void OspfHelloPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OspfPacket::parsimPack(b);
    doParsimPacking(b,this->networkMask);
    doParsimPacking(b,this->helloInterval);
    doParsimPacking(b,this->options);
    doParsimPacking(b,this->routerPriority);
    doParsimPacking(b,this->routerDeadInterval);
    doParsimPacking(b,this->designatedRouter);
    doParsimPacking(b,this->backupDesignatedRouter);
    b->pack(neighbor_arraysize);
    doParsimArrayPacking(b,this->neighbor,neighbor_arraysize);
}

void OspfHelloPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OspfPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->networkMask);
    doParsimUnpacking(b,this->helloInterval);
    doParsimUnpacking(b,this->options);
    doParsimUnpacking(b,this->routerPriority);
    doParsimUnpacking(b,this->routerDeadInterval);
    doParsimUnpacking(b,this->designatedRouter);
    doParsimUnpacking(b,this->backupDesignatedRouter);
    delete [] this->neighbor;
    b->unpack(neighbor_arraysize);
    if (neighbor_arraysize == 0) {
        this->neighbor = nullptr;
    } else {
        this->neighbor = new Ipv4Address[neighbor_arraysize];
        doParsimArrayUnpacking(b,this->neighbor,neighbor_arraysize);
    }
}

const Ipv4Address& OspfHelloPacket::getNetworkMask() const
{
    return this->networkMask;
}

void OspfHelloPacket::setNetworkMask(const Ipv4Address& networkMask)
{
    handleChange();
    this->networkMask = networkMask;
}

short OspfHelloPacket::getHelloInterval() const
{
    return this->helloInterval;
}

void OspfHelloPacket::setHelloInterval(short helloInterval)
{
    handleChange();
    this->helloInterval = helloInterval;
}

const OspfOptions& OspfHelloPacket::getOptions() const
{
    return this->options;
}

void OspfHelloPacket::setOptions(const OspfOptions& options)
{
    handleChange();
    this->options = options;
}

char OspfHelloPacket::getRouterPriority() const
{
    return this->routerPriority;
}

void OspfHelloPacket::setRouterPriority(char routerPriority)
{
    handleChange();
    this->routerPriority = routerPriority;
}

long OspfHelloPacket::getRouterDeadInterval() const
{
    return this->routerDeadInterval;
}

void OspfHelloPacket::setRouterDeadInterval(long routerDeadInterval)
{
    handleChange();
    this->routerDeadInterval = routerDeadInterval;
}

const Ipv4Address& OspfHelloPacket::getDesignatedRouter() const
{
    return this->designatedRouter;
}

void OspfHelloPacket::setDesignatedRouter(const Ipv4Address& designatedRouter)
{
    handleChange();
    this->designatedRouter = designatedRouter;
}

const Ipv4Address& OspfHelloPacket::getBackupDesignatedRouter() const
{
    return this->backupDesignatedRouter;
}

void OspfHelloPacket::setBackupDesignatedRouter(const Ipv4Address& backupDesignatedRouter)
{
    handleChange();
    this->backupDesignatedRouter = backupDesignatedRouter;
}

size_t OspfHelloPacket::getNeighborArraySize() const
{
    return neighbor_arraysize;
}

const Ipv4Address& OspfHelloPacket::getNeighbor(size_t k) const
{
    if (k >= neighbor_arraysize) throw omnetpp::cRuntimeError("Array of size neighbor_arraysize indexed by %lu", (unsigned long)k);
    return this->neighbor[k];
}

void OspfHelloPacket::setNeighborArraySize(size_t newSize)
{
    handleChange();
    Ipv4Address *neighbor2 = (newSize==0) ? nullptr : new Ipv4Address[newSize];
    size_t minSize = neighbor_arraysize < newSize ? neighbor_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        neighbor2[i] = this->neighbor[i];
    delete [] this->neighbor;
    this->neighbor = neighbor2;
    neighbor_arraysize = newSize;
}

void OspfHelloPacket::setNeighbor(size_t k, const Ipv4Address& neighbor)
{
    if (k >= neighbor_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->neighbor[k] = neighbor;
}

void OspfHelloPacket::insertNeighbor(size_t k, const Ipv4Address& neighbor)
{
    handleChange();
    if (k > neighbor_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = neighbor_arraysize + 1;
    Ipv4Address *neighbor2 = new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighbor2[i] = this->neighbor[i];
    neighbor2[k] = neighbor;
    for (i = k + 1; i < newSize; i++)
        neighbor2[i] = this->neighbor[i-1];
    delete [] this->neighbor;
    this->neighbor = neighbor2;
    neighbor_arraysize = newSize;
}

void OspfHelloPacket::insertNeighbor(const Ipv4Address& neighbor)
{
    insertNeighbor(neighbor_arraysize, neighbor);
}

void OspfHelloPacket::eraseNeighbor(size_t k)
{
    if (k >= neighbor_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = neighbor_arraysize - 1;
    Ipv4Address *neighbor2 = (newSize == 0) ? nullptr : new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighbor2[i] = this->neighbor[i];
    for (i = k; i < newSize; i++)
        neighbor2[i] = this->neighbor[i+1];
    delete [] this->neighbor;
    this->neighbor = neighbor2;
    neighbor_arraysize = newSize;
}

class OspfHelloPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_networkMask,
        FIELD_helloInterval,
        FIELD_options,
        FIELD_routerPriority,
        FIELD_routerDeadInterval,
        FIELD_designatedRouter,
        FIELD_backupDesignatedRouter,
        FIELD_neighbor,
    };
  public:
    OspfHelloPacketDescriptor();
    virtual ~OspfHelloPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfHelloPacketDescriptor)

OspfHelloPacketDescriptor::OspfHelloPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfHelloPacket)), "inet::ospf::OspfPacket")
{
    propertynames = nullptr;
}

OspfHelloPacketDescriptor::~OspfHelloPacketDescriptor()
{
    delete[] propertynames;
}

bool OspfHelloPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfHelloPacket *>(obj)!=nullptr;
}

const char **OspfHelloPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfHelloPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfHelloPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OspfHelloPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_networkMask
        FD_ISEDITABLE,    // FIELD_helloInterval
        FD_ISCOMPOUND,    // FIELD_options
        FD_ISEDITABLE,    // FIELD_routerPriority
        FD_ISEDITABLE,    // FIELD_routerDeadInterval
        0,    // FIELD_designatedRouter
        0,    // FIELD_backupDesignatedRouter
        FD_ISARRAY,    // FIELD_neighbor
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *OspfHelloPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkMask",
        "helloInterval",
        "options",
        "routerPriority",
        "routerDeadInterval",
        "designatedRouter",
        "backupDesignatedRouter",
        "neighbor",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int OspfHelloPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "networkMask") == 0) return base+0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "helloInterval") == 0) return base+1;
    if (fieldName[0] == 'o' && strcmp(fieldName, "options") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routerPriority") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routerDeadInterval") == 0) return base+4;
    if (fieldName[0] == 'd' && strcmp(fieldName, "designatedRouter") == 0) return base+5;
    if (fieldName[0] == 'b' && strcmp(fieldName, "backupDesignatedRouter") == 0) return base+6;
    if (fieldName[0] == 'n' && strcmp(fieldName, "neighbor") == 0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfHelloPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_networkMask
        "short",    // FIELD_helloInterval
        "inet::ospf::OspfOptions",    // FIELD_options
        "char",    // FIELD_routerPriority
        "long",    // FIELD_routerDeadInterval
        "inet::Ipv4Address",    // FIELD_designatedRouter
        "inet::Ipv4Address",    // FIELD_backupDesignatedRouter
        "inet::Ipv4Address",    // FIELD_neighbor
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfHelloPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfHelloPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfHelloPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfHelloPacket *pp = (OspfHelloPacket *)object; (void)pp;
    switch (field) {
        case FIELD_neighbor: return pp->getNeighborArraySize();
        default: return 0;
    }
}

const char *OspfHelloPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfHelloPacket *pp = (OspfHelloPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfHelloPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfHelloPacket *pp = (OspfHelloPacket *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return pp->getNetworkMask().str();
        case FIELD_helloInterval: return long2string(pp->getHelloInterval());
        case FIELD_options: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case FIELD_routerPriority: return long2string(pp->getRouterPriority());
        case FIELD_routerDeadInterval: return long2string(pp->getRouterDeadInterval());
        case FIELD_designatedRouter: return pp->getDesignatedRouter().str();
        case FIELD_backupDesignatedRouter: return pp->getBackupDesignatedRouter().str();
        case FIELD_neighbor: return pp->getNeighbor(i).str();
        default: return "";
    }
}

bool OspfHelloPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfHelloPacket *pp = (OspfHelloPacket *)object; (void)pp;
    switch (field) {
        case FIELD_helloInterval: pp->setHelloInterval(string2long(value)); return true;
        case FIELD_routerPriority: pp->setRouterPriority(string2long(value)); return true;
        case FIELD_routerDeadInterval: pp->setRouterDeadInterval(string2long(value)); return true;
        default: return false;
    }
}

const char *OspfHelloPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options: return omnetpp::opp_typename(typeid(OspfOptions));
        default: return nullptr;
    };
}

void *OspfHelloPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfHelloPacket *pp = (OspfHelloPacket *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return toVoidPtr(&pp->getNetworkMask()); break;
        case FIELD_options: return toVoidPtr(&pp->getOptions()); break;
        case FIELD_designatedRouter: return toVoidPtr(&pp->getDesignatedRouter()); break;
        case FIELD_backupDesignatedRouter: return toVoidPtr(&pp->getBackupDesignatedRouter()); break;
        case FIELD_neighbor: return toVoidPtr(&pp->getNeighbor(i)); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ospf::LsaType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ospf::LsaType"));
    e->insert(ROUTERLSA_TYPE, "ROUTERLSA_TYPE");
    e->insert(NETWORKLSA_TYPE, "NETWORKLSA_TYPE");
    e->insert(SUMMARYLSA_NETWORKS_TYPE, "SUMMARYLSA_NETWORKS_TYPE");
    e->insert(SUMMARYLSA_ASBOUNDARYROUTERS_TYPE, "SUMMARYLSA_ASBOUNDARYROUTERS_TYPE");
    e->insert(AS_EXTERNAL_LSA_TYPE, "AS_EXTERNAL_LSA_TYPE");
)

Register_Class(OspfLsaHeader)

OspfLsaHeader::OspfLsaHeader() : ::omnetpp::cObject()
{
}

OspfLsaHeader::OspfLsaHeader(const OspfLsaHeader& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

OspfLsaHeader::~OspfLsaHeader()
{
}

OspfLsaHeader& OspfLsaHeader::operator=(const OspfLsaHeader& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void OspfLsaHeader::copy(const OspfLsaHeader& other)
{
    this->lsAge = other.lsAge;
    this->lsOptions = other.lsOptions;
    this->lsType = other.lsType;
    this->linkStateID = other.linkStateID;
    this->advertisingRouter = other.advertisingRouter;
    this->lsSequenceNumber = other.lsSequenceNumber;
    this->lsCrc = other.lsCrc;
    this->lsaLength = other.lsaLength;
}

void OspfLsaHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->lsAge);
    doParsimPacking(b,this->lsOptions);
    doParsimPacking(b,this->lsType);
    doParsimPacking(b,this->linkStateID);
    doParsimPacking(b,this->advertisingRouter);
    doParsimPacking(b,this->lsSequenceNumber);
    doParsimPacking(b,this->lsCrc);
    doParsimPacking(b,this->lsaLength);
}

void OspfLsaHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->lsAge);
    doParsimUnpacking(b,this->lsOptions);
    doParsimUnpacking(b,this->lsType);
    doParsimUnpacking(b,this->linkStateID);
    doParsimUnpacking(b,this->advertisingRouter);
    doParsimUnpacking(b,this->lsSequenceNumber);
    doParsimUnpacking(b,this->lsCrc);
    doParsimUnpacking(b,this->lsaLength);
}

unsigned short OspfLsaHeader::getLsAge() const
{
    return this->lsAge;
}

void OspfLsaHeader::setLsAge(unsigned short lsAge)
{
    this->lsAge = lsAge;
}

const OspfOptions& OspfLsaHeader::getLsOptions() const
{
    return this->lsOptions;
}

void OspfLsaHeader::setLsOptions(const OspfOptions& lsOptions)
{
    this->lsOptions = lsOptions;
}

inet::ospf::LsaType OspfLsaHeader::getLsType() const
{
    return this->lsType;
}

void OspfLsaHeader::setLsType(inet::ospf::LsaType lsType)
{
    this->lsType = lsType;
}

const Ipv4Address& OspfLsaHeader::getLinkStateID() const
{
    return this->linkStateID;
}

void OspfLsaHeader::setLinkStateID(const Ipv4Address& linkStateID)
{
    this->linkStateID = linkStateID;
}

const Ipv4Address& OspfLsaHeader::getAdvertisingRouter() const
{
    return this->advertisingRouter;
}

void OspfLsaHeader::setAdvertisingRouter(const Ipv4Address& advertisingRouter)
{
    this->advertisingRouter = advertisingRouter;
}

long OspfLsaHeader::getLsSequenceNumber() const
{
    return this->lsSequenceNumber;
}

void OspfLsaHeader::setLsSequenceNumber(long lsSequenceNumber)
{
    this->lsSequenceNumber = lsSequenceNumber;
}

uint16_t OspfLsaHeader::getLsCrc() const
{
    return this->lsCrc;
}

void OspfLsaHeader::setLsCrc(uint16_t lsCrc)
{
    this->lsCrc = lsCrc;
}

unsigned short OspfLsaHeader::getLsaLength() const
{
    return this->lsaLength;
}

void OspfLsaHeader::setLsaLength(unsigned short lsaLength)
{
    this->lsaLength = lsaLength;
}

class OspfLsaHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_lsAge,
        FIELD_lsOptions,
        FIELD_lsType,
        FIELD_linkStateID,
        FIELD_advertisingRouter,
        FIELD_lsSequenceNumber,
        FIELD_lsCrc,
        FIELD_lsaLength,
    };
  public:
    OspfLsaHeaderDescriptor();
    virtual ~OspfLsaHeaderDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfLsaHeaderDescriptor)

OspfLsaHeaderDescriptor::OspfLsaHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfLsaHeader)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

OspfLsaHeaderDescriptor::~OspfLsaHeaderDescriptor()
{
    delete[] propertynames;
}

bool OspfLsaHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfLsaHeader *>(obj)!=nullptr;
}

const char **OspfLsaHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfLsaHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfLsaHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OspfLsaHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_lsAge
        FD_ISCOMPOUND,    // FIELD_lsOptions
        0,    // FIELD_lsType
        0,    // FIELD_linkStateID
        0,    // FIELD_advertisingRouter
        FD_ISEDITABLE,    // FIELD_lsSequenceNumber
        FD_ISEDITABLE,    // FIELD_lsCrc
        FD_ISEDITABLE,    // FIELD_lsaLength
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *OspfLsaHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsAge",
        "lsOptions",
        "lsType",
        "linkStateID",
        "advertisingRouter",
        "lsSequenceNumber",
        "lsCrc",
        "lsaLength",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int OspfLsaHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsAge") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsOptions") == 0) return base+1;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsType") == 0) return base+2;
    if (fieldName[0] == 'l' && strcmp(fieldName, "linkStateID") == 0) return base+3;
    if (fieldName[0] == 'a' && strcmp(fieldName, "advertisingRouter") == 0) return base+4;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsSequenceNumber") == 0) return base+5;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsCrc") == 0) return base+6;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsaLength") == 0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfLsaHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_lsAge
        "inet::ospf::OspfOptions",    // FIELD_lsOptions
        "inet::ospf::LsaType",    // FIELD_lsType
        "inet::Ipv4Address",    // FIELD_linkStateID
        "inet::Ipv4Address",    // FIELD_advertisingRouter
        "long",    // FIELD_lsSequenceNumber
        "uint16_t",    // FIELD_lsCrc
        "unsigned short",    // FIELD_lsaLength
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfLsaHeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_lsType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *OspfLsaHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_lsType:
            if (!strcmp(propertyname, "enum")) return "inet::ospf::LsaType";
            return nullptr;
        default: return nullptr;
    }
}

int OspfLsaHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfLsaHeader *pp = (OspfLsaHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *OspfLsaHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfLsaHeader *pp = (OspfLsaHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfLsaHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfLsaHeader *pp = (OspfLsaHeader *)object; (void)pp;
    switch (field) {
        case FIELD_lsAge: return ulong2string(pp->getLsAge());
        case FIELD_lsOptions: {std::stringstream out; out << pp->getLsOptions(); return out.str();}
        case FIELD_lsType: return enum2string(pp->getLsType(), "inet::ospf::LsaType");
        case FIELD_linkStateID: return pp->getLinkStateID().str();
        case FIELD_advertisingRouter: return pp->getAdvertisingRouter().str();
        case FIELD_lsSequenceNumber: return long2string(pp->getLsSequenceNumber());
        case FIELD_lsCrc: return ulong2string(pp->getLsCrc());
        case FIELD_lsaLength: return ulong2string(pp->getLsaLength());
        default: return "";
    }
}

bool OspfLsaHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfLsaHeader *pp = (OspfLsaHeader *)object; (void)pp;
    switch (field) {
        case FIELD_lsAge: pp->setLsAge(string2ulong(value)); return true;
        case FIELD_lsSequenceNumber: pp->setLsSequenceNumber(string2long(value)); return true;
        case FIELD_lsCrc: pp->setLsCrc(string2ulong(value)); return true;
        case FIELD_lsaLength: pp->setLsaLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfLsaHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_lsOptions: return omnetpp::opp_typename(typeid(OspfOptions));
        default: return nullptr;
    };
}

void *OspfLsaHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfLsaHeader *pp = (OspfLsaHeader *)object; (void)pp;
    switch (field) {
        case FIELD_lsOptions: return toVoidPtr(&pp->getLsOptions()); break;
        case FIELD_linkStateID: return toVoidPtr(&pp->getLinkStateID()); break;
        case FIELD_advertisingRouter: return toVoidPtr(&pp->getAdvertisingRouter()); break;
        default: return nullptr;
    }
}

Register_Class(OspfLsa)

OspfLsa::OspfLsa() : ::omnetpp::cObject()
{
}

OspfLsa::OspfLsa(const OspfLsa& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

OspfLsa::~OspfLsa()
{
}

OspfLsa& OspfLsa::operator=(const OspfLsa& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void OspfLsa::copy(const OspfLsa& other)
{
    this->header = other.header;
}

void OspfLsa::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->header);
}

void OspfLsa::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->header);
}

const OspfLsaHeader& OspfLsa::getHeader() const
{
    return this->header;
}

void OspfLsa::setHeader(const OspfLsaHeader& header)
{
    this->header = header;
}

class OspfLsaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_header,
    };
  public:
    OspfLsaDescriptor();
    virtual ~OspfLsaDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfLsaDescriptor)

OspfLsaDescriptor::OspfLsaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfLsa)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

OspfLsaDescriptor::~OspfLsaDescriptor()
{
    delete[] propertynames;
}

bool OspfLsaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfLsa *>(obj)!=nullptr;
}

const char **OspfLsaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfLsaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfLsaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int OspfLsaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_header
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *OspfLsaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "header",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int OspfLsaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "header") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfLsaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ospf::OspfLsaHeader",    // FIELD_header
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfLsaDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfLsaDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfLsaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfLsa *pp = (OspfLsa *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *OspfLsaDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfLsa *pp = (OspfLsa *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfLsaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfLsa *pp = (OspfLsa *)object; (void)pp;
    switch (field) {
        case FIELD_header: {std::stringstream out; out << pp->getHeader(); return out.str();}
        default: return "";
    }
}

bool OspfLsaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfLsa *pp = (OspfLsa *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OspfLsaDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_header: return omnetpp::opp_typename(typeid(OspfLsaHeader));
        default: return nullptr;
    };
}

void *OspfLsaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfLsa *pp = (OspfLsa *)object; (void)pp;
    switch (field) {
        case FIELD_header: return toVoidPtr(&pp->getHeader()); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ospf::LinkType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ospf::LinkType"));
    e->insert(POINTTOPOINT_LINK, "POINTTOPOINT_LINK");
    e->insert(TRANSIT_LINK, "TRANSIT_LINK");
    e->insert(STUB_LINK, "STUB_LINK");
    e->insert(VIRTUAL_LINK, "VIRTUAL_LINK");
)

TosData::TosData()
{
    this->tos = 0;
    for (size_t i = 0; i < 3; i++)
        this->tosMetric[i] = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const TosData& a)
{
    doParsimPacking(b,a.tos);
    doParsimArrayPacking(b,a.tosMetric,3);
}

void __doUnpacking(omnetpp::cCommBuffer *b, TosData& a)
{
    doParsimUnpacking(b,a.tos);
    doParsimArrayUnpacking(b,a.tosMetric,3);
}

class TosDataDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tos,
        FIELD_tosMetric,
    };
  public:
    TosDataDescriptor();
    virtual ~TosDataDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(TosDataDescriptor)

TosDataDescriptor::TosDataDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::TosData)), "")
{
    propertynames = nullptr;
}

TosDataDescriptor::~TosDataDescriptor()
{
    delete[] propertynames;
}

bool TosDataDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TosData *>(obj)!=nullptr;
}

const char **TosDataDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TosDataDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TosDataDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int TosDataDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_tos
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_tosMetric
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *TosDataDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tos",
        "tosMetric",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int TosDataDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tos") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tosMetric") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TosDataDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",    // FIELD_tos
        "unsigned char",    // FIELD_tosMetric
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **TosDataDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TosDataDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TosDataDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TosData *pp = (TosData *)object; (void)pp;
    switch (field) {
        case FIELD_tosMetric: return 3;
        default: return 0;
    }
}

const char *TosDataDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TosData *pp = (TosData *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TosDataDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TosData *pp = (TosData *)object; (void)pp;
    switch (field) {
        case FIELD_tos: return ulong2string(pp->tos);
        case FIELD_tosMetric: if (i >= 3) return "";
                return ulong2string(pp->tosMetric[i]);
        default: return "";
    }
}

bool TosDataDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TosData *pp = (TosData *)object; (void)pp;
    switch (field) {
        case FIELD_tos: pp->tos = string2ulong(value); return true;
        case FIELD_tosMetric: if (i >= 3) return "";
                pp->tosMetric[i] = string2ulong(value); return true;
        default: return false;
    }
}

const char *TosDataDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *TosDataDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TosData *pp = (TosData *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Link)

Link::Link() : ::omnetpp::cObject()
{
}

Link::Link(const Link& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

Link::~Link()
{
    delete [] this->tosData;
}

Link& Link::operator=(const Link& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Link::copy(const Link& other)
{
    this->linkID = other.linkID;
    this->linkData = other.linkData;
    this->type = other.type;
    this->numberOfTOS = other.numberOfTOS;
    this->linkCost = other.linkCost;
    delete [] this->tosData;
    this->tosData = (other.tosData_arraysize==0) ? nullptr : new TosData[other.tosData_arraysize];
    tosData_arraysize = other.tosData_arraysize;
    for (size_t i = 0; i < tosData_arraysize; i++) {
        this->tosData[i] = other.tosData[i];
    }
}

void Link::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->linkID);
    doParsimPacking(b,this->linkData);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->numberOfTOS);
    doParsimPacking(b,this->linkCost);
    b->pack(tosData_arraysize);
    doParsimArrayPacking(b,this->tosData,tosData_arraysize);
}

void Link::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->linkID);
    doParsimUnpacking(b,this->linkData);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->numberOfTOS);
    doParsimUnpacking(b,this->linkCost);
    delete [] this->tosData;
    b->unpack(tosData_arraysize);
    if (tosData_arraysize == 0) {
        this->tosData = nullptr;
    } else {
        this->tosData = new TosData[tosData_arraysize];
        doParsimArrayUnpacking(b,this->tosData,tosData_arraysize);
    }
}

const Ipv4Address& Link::getLinkID() const
{
    return this->linkID;
}

void Link::setLinkID(const Ipv4Address& linkID)
{
    this->linkID = linkID;
}

unsigned long Link::getLinkData() const
{
    return this->linkData;
}

void Link::setLinkData(unsigned long linkData)
{
    this->linkData = linkData;
}

inet::ospf::LinkType Link::getType() const
{
    return this->type;
}

void Link::setType(inet::ospf::LinkType type)
{
    this->type = type;
}

unsigned char Link::getNumberOfTOS() const
{
    return this->numberOfTOS;
}

void Link::setNumberOfTOS(unsigned char numberOfTOS)
{
    this->numberOfTOS = numberOfTOS;
}

unsigned long Link::getLinkCost() const
{
    return this->linkCost;
}

void Link::setLinkCost(unsigned long linkCost)
{
    this->linkCost = linkCost;
}

size_t Link::getTosDataArraySize() const
{
    return tosData_arraysize;
}

const TosData& Link::getTosData(size_t k) const
{
    if (k >= tosData_arraysize) throw omnetpp::cRuntimeError("Array of size tosData_arraysize indexed by %lu", (unsigned long)k);
    return this->tosData[k];
}

void Link::setTosDataArraySize(size_t newSize)
{
    TosData *tosData2 = (newSize==0) ? nullptr : new TosData[newSize];
    size_t minSize = tosData_arraysize < newSize ? tosData_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        tosData2[i] = this->tosData[i];
    delete [] this->tosData;
    this->tosData = tosData2;
    tosData_arraysize = newSize;
}

void Link::setTosData(size_t k, const TosData& tosData)
{
    if (k >= tosData_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->tosData[k] = tosData;
}

void Link::insertTosData(size_t k, const TosData& tosData)
{
    if (k > tosData_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = tosData_arraysize + 1;
    TosData *tosData2 = new TosData[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        tosData2[i] = this->tosData[i];
    tosData2[k] = tosData;
    for (i = k + 1; i < newSize; i++)
        tosData2[i] = this->tosData[i-1];
    delete [] this->tosData;
    this->tosData = tosData2;
    tosData_arraysize = newSize;
}

void Link::insertTosData(const TosData& tosData)
{
    insertTosData(tosData_arraysize, tosData);
}

void Link::eraseTosData(size_t k)
{
    if (k >= tosData_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = tosData_arraysize - 1;
    TosData *tosData2 = (newSize == 0) ? nullptr : new TosData[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        tosData2[i] = this->tosData[i];
    for (i = k; i < newSize; i++)
        tosData2[i] = this->tosData[i+1];
    delete [] this->tosData;
    this->tosData = tosData2;
    tosData_arraysize = newSize;
}

class LinkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_linkID,
        FIELD_linkData,
        FIELD_type,
        FIELD_numberOfTOS,
        FIELD_linkCost,
        FIELD_tosData,
    };
  public:
    LinkDescriptor();
    virtual ~LinkDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(LinkDescriptor)

LinkDescriptor::LinkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::Link)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

LinkDescriptor::~LinkDescriptor()
{
    delete[] propertynames;
}

bool LinkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Link *>(obj)!=nullptr;
}

const char **LinkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LinkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LinkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int LinkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_linkID
        FD_ISEDITABLE,    // FIELD_linkData
        0,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_numberOfTOS
        FD_ISEDITABLE,    // FIELD_linkCost
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_tosData
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *LinkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "linkID",
        "linkData",
        "type",
        "numberOfTOS",
        "linkCost",
        "tosData",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int LinkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "linkID") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "linkData") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+2;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numberOfTOS") == 0) return base+3;
    if (fieldName[0] == 'l' && strcmp(fieldName, "linkCost") == 0) return base+4;
    if (fieldName[0] == 't' && strcmp(fieldName, "tosData") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LinkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_linkID
        "unsigned long",    // FIELD_linkData
        "inet::ospf::LinkType",    // FIELD_type
        "unsigned char",    // FIELD_numberOfTOS
        "unsigned long",    // FIELD_linkCost
        "inet::ospf::TosData",    // FIELD_tosData
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **LinkDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *LinkDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::ospf::LinkType";
            return nullptr;
        default: return nullptr;
    }
}

int LinkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Link *pp = (Link *)object; (void)pp;
    switch (field) {
        case FIELD_tosData: return pp->getTosDataArraySize();
        default: return 0;
    }
}

const char *LinkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Link *pp = (Link *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LinkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Link *pp = (Link *)object; (void)pp;
    switch (field) {
        case FIELD_linkID: return pp->getLinkID().str();
        case FIELD_linkData: return ulong2string(pp->getLinkData());
        case FIELD_type: return enum2string(pp->getType(), "inet::ospf::LinkType");
        case FIELD_numberOfTOS: return ulong2string(pp->getNumberOfTOS());
        case FIELD_linkCost: return ulong2string(pp->getLinkCost());
        case FIELD_tosData: {std::stringstream out; out << pp->getTosData(i); return out.str();}
        default: return "";
    }
}

bool LinkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Link *pp = (Link *)object; (void)pp;
    switch (field) {
        case FIELD_linkData: pp->setLinkData(string2ulong(value)); return true;
        case FIELD_numberOfTOS: pp->setNumberOfTOS(string2ulong(value)); return true;
        case FIELD_linkCost: pp->setLinkCost(string2ulong(value)); return true;
        default: return false;
    }
}

const char *LinkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_tosData: return omnetpp::opp_typename(typeid(TosData));
        default: return nullptr;
    };
}

void *LinkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Link *pp = (Link *)object; (void)pp;
    switch (field) {
        case FIELD_linkID: return toVoidPtr(&pp->getLinkID()); break;
        case FIELD_tosData: return toVoidPtr(&pp->getTosData(i)); break;
        default: return nullptr;
    }
}

Register_Class(OspfRouterLsa)

OspfRouterLsa::OspfRouterLsa() : ::inet::ospf::OspfLsa()
{
}

OspfRouterLsa::OspfRouterLsa(const OspfRouterLsa& other) : ::inet::ospf::OspfLsa(other)
{
    copy(other);
}

OspfRouterLsa::~OspfRouterLsa()
{
    delete [] this->links;
}

OspfRouterLsa& OspfRouterLsa::operator=(const OspfRouterLsa& other)
{
    if (this == &other) return *this;
    ::inet::ospf::OspfLsa::operator=(other);
    copy(other);
    return *this;
}

void OspfRouterLsa::copy(const OspfRouterLsa& other)
{
    this->V_VirtualLinkEndpoint = other.V_VirtualLinkEndpoint;
    this->E_ASBoundaryRouter = other.E_ASBoundaryRouter;
    this->B_AreaBorderRouter = other.B_AreaBorderRouter;
    this->numberOfLinks = other.numberOfLinks;
    delete [] this->links;
    this->links = (other.links_arraysize==0) ? nullptr : new Link[other.links_arraysize];
    links_arraysize = other.links_arraysize;
    for (size_t i = 0; i < links_arraysize; i++) {
        this->links[i] = other.links[i];
    }
}

void OspfRouterLsa::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OspfLsa::parsimPack(b);
    doParsimPacking(b,this->V_VirtualLinkEndpoint);
    doParsimPacking(b,this->E_ASBoundaryRouter);
    doParsimPacking(b,this->B_AreaBorderRouter);
    doParsimPacking(b,this->numberOfLinks);
    b->pack(links_arraysize);
    doParsimArrayPacking(b,this->links,links_arraysize);
}

void OspfRouterLsa::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OspfLsa::parsimUnpack(b);
    doParsimUnpacking(b,this->V_VirtualLinkEndpoint);
    doParsimUnpacking(b,this->E_ASBoundaryRouter);
    doParsimUnpacking(b,this->B_AreaBorderRouter);
    doParsimUnpacking(b,this->numberOfLinks);
    delete [] this->links;
    b->unpack(links_arraysize);
    if (links_arraysize == 0) {
        this->links = nullptr;
    } else {
        this->links = new Link[links_arraysize];
        doParsimArrayUnpacking(b,this->links,links_arraysize);
    }
}

bool OspfRouterLsa::getV_VirtualLinkEndpoint() const
{
    return this->V_VirtualLinkEndpoint;
}

void OspfRouterLsa::setV_VirtualLinkEndpoint(bool V_VirtualLinkEndpoint)
{
    this->V_VirtualLinkEndpoint = V_VirtualLinkEndpoint;
}

bool OspfRouterLsa::getE_ASBoundaryRouter() const
{
    return this->E_ASBoundaryRouter;
}

void OspfRouterLsa::setE_ASBoundaryRouter(bool E_ASBoundaryRouter)
{
    this->E_ASBoundaryRouter = E_ASBoundaryRouter;
}

bool OspfRouterLsa::getB_AreaBorderRouter() const
{
    return this->B_AreaBorderRouter;
}

void OspfRouterLsa::setB_AreaBorderRouter(bool B_AreaBorderRouter)
{
    this->B_AreaBorderRouter = B_AreaBorderRouter;
}

unsigned short OspfRouterLsa::getNumberOfLinks() const
{
    return this->numberOfLinks;
}

void OspfRouterLsa::setNumberOfLinks(unsigned short numberOfLinks)
{
    this->numberOfLinks = numberOfLinks;
}

size_t OspfRouterLsa::getLinksArraySize() const
{
    return links_arraysize;
}

const Link& OspfRouterLsa::getLinks(size_t k) const
{
    if (k >= links_arraysize) throw omnetpp::cRuntimeError("Array of size links_arraysize indexed by %lu", (unsigned long)k);
    return this->links[k];
}

void OspfRouterLsa::setLinksArraySize(size_t newSize)
{
    Link *links2 = (newSize==0) ? nullptr : new Link[newSize];
    size_t minSize = links_arraysize < newSize ? links_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        links2[i] = this->links[i];
    delete [] this->links;
    this->links = links2;
    links_arraysize = newSize;
}

void OspfRouterLsa::setLinks(size_t k, const Link& links)
{
    if (k >= links_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->links[k] = links;
}

void OspfRouterLsa::insertLinks(size_t k, const Link& links)
{
    if (k > links_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = links_arraysize + 1;
    Link *links2 = new Link[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        links2[i] = this->links[i];
    links2[k] = links;
    for (i = k + 1; i < newSize; i++)
        links2[i] = this->links[i-1];
    delete [] this->links;
    this->links = links2;
    links_arraysize = newSize;
}

void OspfRouterLsa::insertLinks(const Link& links)
{
    insertLinks(links_arraysize, links);
}

void OspfRouterLsa::eraseLinks(size_t k)
{
    if (k >= links_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = links_arraysize - 1;
    Link *links2 = (newSize == 0) ? nullptr : new Link[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        links2[i] = this->links[i];
    for (i = k; i < newSize; i++)
        links2[i] = this->links[i+1];
    delete [] this->links;
    this->links = links2;
    links_arraysize = newSize;
}

class OspfRouterLsaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_V_VirtualLinkEndpoint,
        FIELD_E_ASBoundaryRouter,
        FIELD_B_AreaBorderRouter,
        FIELD_numberOfLinks,
        FIELD_links,
    };
  public:
    OspfRouterLsaDescriptor();
    virtual ~OspfRouterLsaDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfRouterLsaDescriptor)

OspfRouterLsaDescriptor::OspfRouterLsaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfRouterLsa)), "inet::ospf::OspfLsa")
{
    propertynames = nullptr;
}

OspfRouterLsaDescriptor::~OspfRouterLsaDescriptor()
{
    delete[] propertynames;
}

bool OspfRouterLsaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfRouterLsa *>(obj)!=nullptr;
}

const char **OspfRouterLsaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfRouterLsaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfRouterLsaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OspfRouterLsaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_V_VirtualLinkEndpoint
        FD_ISEDITABLE,    // FIELD_E_ASBoundaryRouter
        FD_ISEDITABLE,    // FIELD_B_AreaBorderRouter
        FD_ISEDITABLE,    // FIELD_numberOfLinks
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_links
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *OspfRouterLsaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "V_VirtualLinkEndpoint",
        "E_ASBoundaryRouter",
        "B_AreaBorderRouter",
        "numberOfLinks",
        "links",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int OspfRouterLsaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'V' && strcmp(fieldName, "V_VirtualLinkEndpoint") == 0) return base+0;
    if (fieldName[0] == 'E' && strcmp(fieldName, "E_ASBoundaryRouter") == 0) return base+1;
    if (fieldName[0] == 'B' && strcmp(fieldName, "B_AreaBorderRouter") == 0) return base+2;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numberOfLinks") == 0) return base+3;
    if (fieldName[0] == 'l' && strcmp(fieldName, "links") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfRouterLsaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_V_VirtualLinkEndpoint
        "bool",    // FIELD_E_ASBoundaryRouter
        "bool",    // FIELD_B_AreaBorderRouter
        "unsigned short",    // FIELD_numberOfLinks
        "inet::ospf::Link",    // FIELD_links
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfRouterLsaDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfRouterLsaDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfRouterLsaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfRouterLsa *pp = (OspfRouterLsa *)object; (void)pp;
    switch (field) {
        case FIELD_links: return pp->getLinksArraySize();
        default: return 0;
    }
}

const char *OspfRouterLsaDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfRouterLsa *pp = (OspfRouterLsa *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfRouterLsaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfRouterLsa *pp = (OspfRouterLsa *)object; (void)pp;
    switch (field) {
        case FIELD_V_VirtualLinkEndpoint: return bool2string(pp->getV_VirtualLinkEndpoint());
        case FIELD_E_ASBoundaryRouter: return bool2string(pp->getE_ASBoundaryRouter());
        case FIELD_B_AreaBorderRouter: return bool2string(pp->getB_AreaBorderRouter());
        case FIELD_numberOfLinks: return ulong2string(pp->getNumberOfLinks());
        case FIELD_links: {std::stringstream out; out << pp->getLinks(i); return out.str();}
        default: return "";
    }
}

bool OspfRouterLsaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfRouterLsa *pp = (OspfRouterLsa *)object; (void)pp;
    switch (field) {
        case FIELD_V_VirtualLinkEndpoint: pp->setV_VirtualLinkEndpoint(string2bool(value)); return true;
        case FIELD_E_ASBoundaryRouter: pp->setE_ASBoundaryRouter(string2bool(value)); return true;
        case FIELD_B_AreaBorderRouter: pp->setB_AreaBorderRouter(string2bool(value)); return true;
        case FIELD_numberOfLinks: pp->setNumberOfLinks(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfRouterLsaDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_links: return omnetpp::opp_typename(typeid(Link));
        default: return nullptr;
    };
}

void *OspfRouterLsaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfRouterLsa *pp = (OspfRouterLsa *)object; (void)pp;
    switch (field) {
        case FIELD_links: return toVoidPtr(&pp->getLinks(i)); break;
        default: return nullptr;
    }
}

Register_Class(OspfNetworkLsa)

OspfNetworkLsa::OspfNetworkLsa() : ::inet::ospf::OspfLsa()
{
}

OspfNetworkLsa::OspfNetworkLsa(const OspfNetworkLsa& other) : ::inet::ospf::OspfLsa(other)
{
    copy(other);
}

OspfNetworkLsa::~OspfNetworkLsa()
{
    delete [] this->attachedRouters;
}

OspfNetworkLsa& OspfNetworkLsa::operator=(const OspfNetworkLsa& other)
{
    if (this == &other) return *this;
    ::inet::ospf::OspfLsa::operator=(other);
    copy(other);
    return *this;
}

void OspfNetworkLsa::copy(const OspfNetworkLsa& other)
{
    this->networkMask = other.networkMask;
    delete [] this->attachedRouters;
    this->attachedRouters = (other.attachedRouters_arraysize==0) ? nullptr : new Ipv4Address[other.attachedRouters_arraysize];
    attachedRouters_arraysize = other.attachedRouters_arraysize;
    for (size_t i = 0; i < attachedRouters_arraysize; i++) {
        this->attachedRouters[i] = other.attachedRouters[i];
    }
}

void OspfNetworkLsa::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OspfLsa::parsimPack(b);
    doParsimPacking(b,this->networkMask);
    b->pack(attachedRouters_arraysize);
    doParsimArrayPacking(b,this->attachedRouters,attachedRouters_arraysize);
}

void OspfNetworkLsa::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OspfLsa::parsimUnpack(b);
    doParsimUnpacking(b,this->networkMask);
    delete [] this->attachedRouters;
    b->unpack(attachedRouters_arraysize);
    if (attachedRouters_arraysize == 0) {
        this->attachedRouters = nullptr;
    } else {
        this->attachedRouters = new Ipv4Address[attachedRouters_arraysize];
        doParsimArrayUnpacking(b,this->attachedRouters,attachedRouters_arraysize);
    }
}

const Ipv4Address& OspfNetworkLsa::getNetworkMask() const
{
    return this->networkMask;
}

void OspfNetworkLsa::setNetworkMask(const Ipv4Address& networkMask)
{
    this->networkMask = networkMask;
}

size_t OspfNetworkLsa::getAttachedRoutersArraySize() const
{
    return attachedRouters_arraysize;
}

const Ipv4Address& OspfNetworkLsa::getAttachedRouters(size_t k) const
{
    if (k >= attachedRouters_arraysize) throw omnetpp::cRuntimeError("Array of size attachedRouters_arraysize indexed by %lu", (unsigned long)k);
    return this->attachedRouters[k];
}

void OspfNetworkLsa::setAttachedRoutersArraySize(size_t newSize)
{
    Ipv4Address *attachedRouters2 = (newSize==0) ? nullptr : new Ipv4Address[newSize];
    size_t minSize = attachedRouters_arraysize < newSize ? attachedRouters_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        attachedRouters2[i] = this->attachedRouters[i];
    delete [] this->attachedRouters;
    this->attachedRouters = attachedRouters2;
    attachedRouters_arraysize = newSize;
}

void OspfNetworkLsa::setAttachedRouters(size_t k, const Ipv4Address& attachedRouters)
{
    if (k >= attachedRouters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->attachedRouters[k] = attachedRouters;
}

void OspfNetworkLsa::insertAttachedRouters(size_t k, const Ipv4Address& attachedRouters)
{
    if (k > attachedRouters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = attachedRouters_arraysize + 1;
    Ipv4Address *attachedRouters2 = new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        attachedRouters2[i] = this->attachedRouters[i];
    attachedRouters2[k] = attachedRouters;
    for (i = k + 1; i < newSize; i++)
        attachedRouters2[i] = this->attachedRouters[i-1];
    delete [] this->attachedRouters;
    this->attachedRouters = attachedRouters2;
    attachedRouters_arraysize = newSize;
}

void OspfNetworkLsa::insertAttachedRouters(const Ipv4Address& attachedRouters)
{
    insertAttachedRouters(attachedRouters_arraysize, attachedRouters);
}

void OspfNetworkLsa::eraseAttachedRouters(size_t k)
{
    if (k >= attachedRouters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = attachedRouters_arraysize - 1;
    Ipv4Address *attachedRouters2 = (newSize == 0) ? nullptr : new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        attachedRouters2[i] = this->attachedRouters[i];
    for (i = k; i < newSize; i++)
        attachedRouters2[i] = this->attachedRouters[i+1];
    delete [] this->attachedRouters;
    this->attachedRouters = attachedRouters2;
    attachedRouters_arraysize = newSize;
}

class OspfNetworkLsaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_networkMask,
        FIELD_attachedRouters,
    };
  public:
    OspfNetworkLsaDescriptor();
    virtual ~OspfNetworkLsaDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfNetworkLsaDescriptor)

OspfNetworkLsaDescriptor::OspfNetworkLsaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfNetworkLsa)), "inet::ospf::OspfLsa")
{
    propertynames = nullptr;
}

OspfNetworkLsaDescriptor::~OspfNetworkLsaDescriptor()
{
    delete[] propertynames;
}

bool OspfNetworkLsaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfNetworkLsa *>(obj)!=nullptr;
}

const char **OspfNetworkLsaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfNetworkLsaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfNetworkLsaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int OspfNetworkLsaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_networkMask
        FD_ISARRAY,    // FIELD_attachedRouters
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *OspfNetworkLsaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkMask",
        "attachedRouters",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int OspfNetworkLsaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "networkMask") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "attachedRouters") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfNetworkLsaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_networkMask
        "inet::Ipv4Address",    // FIELD_attachedRouters
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfNetworkLsaDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfNetworkLsaDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfNetworkLsaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfNetworkLsa *pp = (OspfNetworkLsa *)object; (void)pp;
    switch (field) {
        case FIELD_attachedRouters: return pp->getAttachedRoutersArraySize();
        default: return 0;
    }
}

const char *OspfNetworkLsaDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfNetworkLsa *pp = (OspfNetworkLsa *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfNetworkLsaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfNetworkLsa *pp = (OspfNetworkLsa *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return pp->getNetworkMask().str();
        case FIELD_attachedRouters: return pp->getAttachedRouters(i).str();
        default: return "";
    }
}

bool OspfNetworkLsaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfNetworkLsa *pp = (OspfNetworkLsa *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OspfNetworkLsaDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *OspfNetworkLsaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfNetworkLsa *pp = (OspfNetworkLsa *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return toVoidPtr(&pp->getNetworkMask()); break;
        case FIELD_attachedRouters: return toVoidPtr(&pp->getAttachedRouters(i)); break;
        default: return nullptr;
    }
}

Register_Class(OspfSummaryLsa)

OspfSummaryLsa::OspfSummaryLsa() : ::inet::ospf::OspfLsa()
{
}

OspfSummaryLsa::OspfSummaryLsa(const OspfSummaryLsa& other) : ::inet::ospf::OspfLsa(other)
{
    copy(other);
}

OspfSummaryLsa::~OspfSummaryLsa()
{
    delete [] this->tosData;
}

OspfSummaryLsa& OspfSummaryLsa::operator=(const OspfSummaryLsa& other)
{
    if (this == &other) return *this;
    ::inet::ospf::OspfLsa::operator=(other);
    copy(other);
    return *this;
}

void OspfSummaryLsa::copy(const OspfSummaryLsa& other)
{
    this->networkMask = other.networkMask;
    this->routeCost = other.routeCost;
    delete [] this->tosData;
    this->tosData = (other.tosData_arraysize==0) ? nullptr : new TosData[other.tosData_arraysize];
    tosData_arraysize = other.tosData_arraysize;
    for (size_t i = 0; i < tosData_arraysize; i++) {
        this->tosData[i] = other.tosData[i];
    }
}

void OspfSummaryLsa::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OspfLsa::parsimPack(b);
    doParsimPacking(b,this->networkMask);
    doParsimPacking(b,this->routeCost);
    b->pack(tosData_arraysize);
    doParsimArrayPacking(b,this->tosData,tosData_arraysize);
}

void OspfSummaryLsa::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OspfLsa::parsimUnpack(b);
    doParsimUnpacking(b,this->networkMask);
    doParsimUnpacking(b,this->routeCost);
    delete [] this->tosData;
    b->unpack(tosData_arraysize);
    if (tosData_arraysize == 0) {
        this->tosData = nullptr;
    } else {
        this->tosData = new TosData[tosData_arraysize];
        doParsimArrayUnpacking(b,this->tosData,tosData_arraysize);
    }
}

const Ipv4Address& OspfSummaryLsa::getNetworkMask() const
{
    return this->networkMask;
}

void OspfSummaryLsa::setNetworkMask(const Ipv4Address& networkMask)
{
    this->networkMask = networkMask;
}

unsigned long OspfSummaryLsa::getRouteCost() const
{
    return this->routeCost;
}

void OspfSummaryLsa::setRouteCost(unsigned long routeCost)
{
    this->routeCost = routeCost;
}

size_t OspfSummaryLsa::getTosDataArraySize() const
{
    return tosData_arraysize;
}

const TosData& OspfSummaryLsa::getTosData(size_t k) const
{
    if (k >= tosData_arraysize) throw omnetpp::cRuntimeError("Array of size tosData_arraysize indexed by %lu", (unsigned long)k);
    return this->tosData[k];
}

void OspfSummaryLsa::setTosDataArraySize(size_t newSize)
{
    TosData *tosData2 = (newSize==0) ? nullptr : new TosData[newSize];
    size_t minSize = tosData_arraysize < newSize ? tosData_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        tosData2[i] = this->tosData[i];
    delete [] this->tosData;
    this->tosData = tosData2;
    tosData_arraysize = newSize;
}

void OspfSummaryLsa::setTosData(size_t k, const TosData& tosData)
{
    if (k >= tosData_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->tosData[k] = tosData;
}

void OspfSummaryLsa::insertTosData(size_t k, const TosData& tosData)
{
    if (k > tosData_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = tosData_arraysize + 1;
    TosData *tosData2 = new TosData[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        tosData2[i] = this->tosData[i];
    tosData2[k] = tosData;
    for (i = k + 1; i < newSize; i++)
        tosData2[i] = this->tosData[i-1];
    delete [] this->tosData;
    this->tosData = tosData2;
    tosData_arraysize = newSize;
}

void OspfSummaryLsa::insertTosData(const TosData& tosData)
{
    insertTosData(tosData_arraysize, tosData);
}

void OspfSummaryLsa::eraseTosData(size_t k)
{
    if (k >= tosData_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = tosData_arraysize - 1;
    TosData *tosData2 = (newSize == 0) ? nullptr : new TosData[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        tosData2[i] = this->tosData[i];
    for (i = k; i < newSize; i++)
        tosData2[i] = this->tosData[i+1];
    delete [] this->tosData;
    this->tosData = tosData2;
    tosData_arraysize = newSize;
}

class OspfSummaryLsaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_networkMask,
        FIELD_routeCost,
        FIELD_tosData,
    };
  public:
    OspfSummaryLsaDescriptor();
    virtual ~OspfSummaryLsaDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfSummaryLsaDescriptor)

OspfSummaryLsaDescriptor::OspfSummaryLsaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfSummaryLsa)), "inet::ospf::OspfLsa")
{
    propertynames = nullptr;
}

OspfSummaryLsaDescriptor::~OspfSummaryLsaDescriptor()
{
    delete[] propertynames;
}

bool OspfSummaryLsaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfSummaryLsa *>(obj)!=nullptr;
}

const char **OspfSummaryLsaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfSummaryLsaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfSummaryLsaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int OspfSummaryLsaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_networkMask
        FD_ISEDITABLE,    // FIELD_routeCost
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_tosData
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *OspfSummaryLsaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkMask",
        "routeCost",
        "tosData",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int OspfSummaryLsaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "networkMask") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routeCost") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "tosData") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfSummaryLsaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_networkMask
        "unsigned long",    // FIELD_routeCost
        "inet::ospf::TosData",    // FIELD_tosData
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfSummaryLsaDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfSummaryLsaDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfSummaryLsaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfSummaryLsa *pp = (OspfSummaryLsa *)object; (void)pp;
    switch (field) {
        case FIELD_tosData: return pp->getTosDataArraySize();
        default: return 0;
    }
}

const char *OspfSummaryLsaDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfSummaryLsa *pp = (OspfSummaryLsa *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfSummaryLsaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfSummaryLsa *pp = (OspfSummaryLsa *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return pp->getNetworkMask().str();
        case FIELD_routeCost: return ulong2string(pp->getRouteCost());
        case FIELD_tosData: {std::stringstream out; out << pp->getTosData(i); return out.str();}
        default: return "";
    }
}

bool OspfSummaryLsaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfSummaryLsa *pp = (OspfSummaryLsa *)object; (void)pp;
    switch (field) {
        case FIELD_routeCost: pp->setRouteCost(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfSummaryLsaDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_tosData: return omnetpp::opp_typename(typeid(TosData));
        default: return nullptr;
    };
}

void *OspfSummaryLsaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfSummaryLsa *pp = (OspfSummaryLsa *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return toVoidPtr(&pp->getNetworkMask()); break;
        case FIELD_tosData: return toVoidPtr(&pp->getTosData(i)); break;
        default: return nullptr;
    }
}

ExternalTosInfo::ExternalTosInfo()
{
    this->E_ExternalMetricType = false;
    this->externalRouteTag = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const ExternalTosInfo& a)
{
    doParsimPacking(b,a.tosData);
    doParsimPacking(b,a.E_ExternalMetricType);
    doParsimPacking(b,a.forwardingAddress);
    doParsimPacking(b,a.externalRouteTag);
}

void __doUnpacking(omnetpp::cCommBuffer *b, ExternalTosInfo& a)
{
    doParsimUnpacking(b,a.tosData);
    doParsimUnpacking(b,a.E_ExternalMetricType);
    doParsimUnpacking(b,a.forwardingAddress);
    doParsimUnpacking(b,a.externalRouteTag);
}

class ExternalTosInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tosData,
        FIELD_E_ExternalMetricType,
        FIELD_forwardingAddress,
        FIELD_externalRouteTag,
    };
  public:
    ExternalTosInfoDescriptor();
    virtual ~ExternalTosInfoDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ExternalTosInfoDescriptor)

ExternalTosInfoDescriptor::ExternalTosInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::ExternalTosInfo)), "")
{
    propertynames = nullptr;
}

ExternalTosInfoDescriptor::~ExternalTosInfoDescriptor()
{
    delete[] propertynames;
}

bool ExternalTosInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ExternalTosInfo *>(obj)!=nullptr;
}

const char **ExternalTosInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ExternalTosInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ExternalTosInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int ExternalTosInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_tosData
        FD_ISEDITABLE,    // FIELD_E_ExternalMetricType
        0,    // FIELD_forwardingAddress
        FD_ISEDITABLE,    // FIELD_externalRouteTag
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *ExternalTosInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tosData",
        "E_ExternalMetricType",
        "forwardingAddress",
        "externalRouteTag",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int ExternalTosInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tosData") == 0) return base+0;
    if (fieldName[0] == 'E' && strcmp(fieldName, "E_ExternalMetricType") == 0) return base+1;
    if (fieldName[0] == 'f' && strcmp(fieldName, "forwardingAddress") == 0) return base+2;
    if (fieldName[0] == 'e' && strcmp(fieldName, "externalRouteTag") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ExternalTosInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ospf::TosData",    // FIELD_tosData
        "bool",    // FIELD_E_ExternalMetricType
        "inet::Ipv4Address",    // FIELD_forwardingAddress
        "long",    // FIELD_externalRouteTag
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **ExternalTosInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ExternalTosInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ExternalTosInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ExternalTosInfo *pp = (ExternalTosInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ExternalTosInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ExternalTosInfo *pp = (ExternalTosInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ExternalTosInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ExternalTosInfo *pp = (ExternalTosInfo *)object; (void)pp;
    switch (field) {
        case FIELD_tosData: {std::stringstream out; out << pp->tosData; return out.str();}
        case FIELD_E_ExternalMetricType: return bool2string(pp->E_ExternalMetricType);
        case FIELD_forwardingAddress: return pp->forwardingAddress.str();
        case FIELD_externalRouteTag: return long2string(pp->externalRouteTag);
        default: return "";
    }
}

bool ExternalTosInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ExternalTosInfo *pp = (ExternalTosInfo *)object; (void)pp;
    switch (field) {
        case FIELD_E_ExternalMetricType: pp->E_ExternalMetricType = string2bool(value); return true;
        case FIELD_externalRouteTag: pp->externalRouteTag = string2long(value); return true;
        default: return false;
    }
}

const char *ExternalTosInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_tosData: return omnetpp::opp_typename(typeid(TosData));
        default: return nullptr;
    };
}

void *ExternalTosInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ExternalTosInfo *pp = (ExternalTosInfo *)object; (void)pp;
    switch (field) {
        case FIELD_tosData: return toVoidPtr(&pp->tosData); break;
        case FIELD_forwardingAddress: return toVoidPtr(&pp->forwardingAddress); break;
        default: return nullptr;
    }
}

Register_Class(OspfAsExternalLsaContents)

OspfAsExternalLsaContents::OspfAsExternalLsaContents() : ::omnetpp::cObject()
{
}

OspfAsExternalLsaContents::OspfAsExternalLsaContents(const OspfAsExternalLsaContents& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

OspfAsExternalLsaContents::~OspfAsExternalLsaContents()
{
    delete [] this->externalTOSInfo;
}

OspfAsExternalLsaContents& OspfAsExternalLsaContents::operator=(const OspfAsExternalLsaContents& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void OspfAsExternalLsaContents::copy(const OspfAsExternalLsaContents& other)
{
    this->networkMask = other.networkMask;
    this->E_ExternalMetricType = other.E_ExternalMetricType;
    this->routeCost = other.routeCost;
    this->forwardingAddress = other.forwardingAddress;
    this->externalRouteTag = other.externalRouteTag;
    delete [] this->externalTOSInfo;
    this->externalTOSInfo = (other.externalTOSInfo_arraysize==0) ? nullptr : new ExternalTosInfo[other.externalTOSInfo_arraysize];
    externalTOSInfo_arraysize = other.externalTOSInfo_arraysize;
    for (size_t i = 0; i < externalTOSInfo_arraysize; i++) {
        this->externalTOSInfo[i] = other.externalTOSInfo[i];
    }
}

void OspfAsExternalLsaContents::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->networkMask);
    doParsimPacking(b,this->E_ExternalMetricType);
    doParsimPacking(b,this->routeCost);
    doParsimPacking(b,this->forwardingAddress);
    doParsimPacking(b,this->externalRouteTag);
    b->pack(externalTOSInfo_arraysize);
    doParsimArrayPacking(b,this->externalTOSInfo,externalTOSInfo_arraysize);
}

void OspfAsExternalLsaContents::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->networkMask);
    doParsimUnpacking(b,this->E_ExternalMetricType);
    doParsimUnpacking(b,this->routeCost);
    doParsimUnpacking(b,this->forwardingAddress);
    doParsimUnpacking(b,this->externalRouteTag);
    delete [] this->externalTOSInfo;
    b->unpack(externalTOSInfo_arraysize);
    if (externalTOSInfo_arraysize == 0) {
        this->externalTOSInfo = nullptr;
    } else {
        this->externalTOSInfo = new ExternalTosInfo[externalTOSInfo_arraysize];
        doParsimArrayUnpacking(b,this->externalTOSInfo,externalTOSInfo_arraysize);
    }
}

const Ipv4Address& OspfAsExternalLsaContents::getNetworkMask() const
{
    return this->networkMask;
}

void OspfAsExternalLsaContents::setNetworkMask(const Ipv4Address& networkMask)
{
    this->networkMask = networkMask;
}

bool OspfAsExternalLsaContents::getE_ExternalMetricType() const
{
    return this->E_ExternalMetricType;
}

void OspfAsExternalLsaContents::setE_ExternalMetricType(bool E_ExternalMetricType)
{
    this->E_ExternalMetricType = E_ExternalMetricType;
}

unsigned long OspfAsExternalLsaContents::getRouteCost() const
{
    return this->routeCost;
}

void OspfAsExternalLsaContents::setRouteCost(unsigned long routeCost)
{
    this->routeCost = routeCost;
}

const Ipv4Address& OspfAsExternalLsaContents::getForwardingAddress() const
{
    return this->forwardingAddress;
}

void OspfAsExternalLsaContents::setForwardingAddress(const Ipv4Address& forwardingAddress)
{
    this->forwardingAddress = forwardingAddress;
}

long OspfAsExternalLsaContents::getExternalRouteTag() const
{
    return this->externalRouteTag;
}

void OspfAsExternalLsaContents::setExternalRouteTag(long externalRouteTag)
{
    this->externalRouteTag = externalRouteTag;
}

size_t OspfAsExternalLsaContents::getExternalTOSInfoArraySize() const
{
    return externalTOSInfo_arraysize;
}

const ExternalTosInfo& OspfAsExternalLsaContents::getExternalTOSInfo(size_t k) const
{
    if (k >= externalTOSInfo_arraysize) throw omnetpp::cRuntimeError("Array of size externalTOSInfo_arraysize indexed by %lu", (unsigned long)k);
    return this->externalTOSInfo[k];
}

void OspfAsExternalLsaContents::setExternalTOSInfoArraySize(size_t newSize)
{
    ExternalTosInfo *externalTOSInfo2 = (newSize==0) ? nullptr : new ExternalTosInfo[newSize];
    size_t minSize = externalTOSInfo_arraysize < newSize ? externalTOSInfo_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        externalTOSInfo2[i] = this->externalTOSInfo[i];
    delete [] this->externalTOSInfo;
    this->externalTOSInfo = externalTOSInfo2;
    externalTOSInfo_arraysize = newSize;
}

void OspfAsExternalLsaContents::setExternalTOSInfo(size_t k, const ExternalTosInfo& externalTOSInfo)
{
    if (k >= externalTOSInfo_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->externalTOSInfo[k] = externalTOSInfo;
}

void OspfAsExternalLsaContents::insertExternalTOSInfo(size_t k, const ExternalTosInfo& externalTOSInfo)
{
    if (k > externalTOSInfo_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = externalTOSInfo_arraysize + 1;
    ExternalTosInfo *externalTOSInfo2 = new ExternalTosInfo[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        externalTOSInfo2[i] = this->externalTOSInfo[i];
    externalTOSInfo2[k] = externalTOSInfo;
    for (i = k + 1; i < newSize; i++)
        externalTOSInfo2[i] = this->externalTOSInfo[i-1];
    delete [] this->externalTOSInfo;
    this->externalTOSInfo = externalTOSInfo2;
    externalTOSInfo_arraysize = newSize;
}

void OspfAsExternalLsaContents::insertExternalTOSInfo(const ExternalTosInfo& externalTOSInfo)
{
    insertExternalTOSInfo(externalTOSInfo_arraysize, externalTOSInfo);
}

void OspfAsExternalLsaContents::eraseExternalTOSInfo(size_t k)
{
    if (k >= externalTOSInfo_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = externalTOSInfo_arraysize - 1;
    ExternalTosInfo *externalTOSInfo2 = (newSize == 0) ? nullptr : new ExternalTosInfo[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        externalTOSInfo2[i] = this->externalTOSInfo[i];
    for (i = k; i < newSize; i++)
        externalTOSInfo2[i] = this->externalTOSInfo[i+1];
    delete [] this->externalTOSInfo;
    this->externalTOSInfo = externalTOSInfo2;
    externalTOSInfo_arraysize = newSize;
}

class OspfAsExternalLsaContentsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_networkMask,
        FIELD_E_ExternalMetricType,
        FIELD_routeCost,
        FIELD_forwardingAddress,
        FIELD_externalRouteTag,
        FIELD_externalTOSInfo,
    };
  public:
    OspfAsExternalLsaContentsDescriptor();
    virtual ~OspfAsExternalLsaContentsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfAsExternalLsaContentsDescriptor)

OspfAsExternalLsaContentsDescriptor::OspfAsExternalLsaContentsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfAsExternalLsaContents)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

OspfAsExternalLsaContentsDescriptor::~OspfAsExternalLsaContentsDescriptor()
{
    delete[] propertynames;
}

bool OspfAsExternalLsaContentsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfAsExternalLsaContents *>(obj)!=nullptr;
}

const char **OspfAsExternalLsaContentsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfAsExternalLsaContentsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfAsExternalLsaContentsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int OspfAsExternalLsaContentsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_networkMask
        FD_ISEDITABLE,    // FIELD_E_ExternalMetricType
        FD_ISEDITABLE,    // FIELD_routeCost
        0,    // FIELD_forwardingAddress
        FD_ISEDITABLE,    // FIELD_externalRouteTag
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_externalTOSInfo
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *OspfAsExternalLsaContentsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkMask",
        "E_ExternalMetricType",
        "routeCost",
        "forwardingAddress",
        "externalRouteTag",
        "externalTOSInfo",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int OspfAsExternalLsaContentsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "networkMask") == 0) return base+0;
    if (fieldName[0] == 'E' && strcmp(fieldName, "E_ExternalMetricType") == 0) return base+1;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routeCost") == 0) return base+2;
    if (fieldName[0] == 'f' && strcmp(fieldName, "forwardingAddress") == 0) return base+3;
    if (fieldName[0] == 'e' && strcmp(fieldName, "externalRouteTag") == 0) return base+4;
    if (fieldName[0] == 'e' && strcmp(fieldName, "externalTOSInfo") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfAsExternalLsaContentsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_networkMask
        "bool",    // FIELD_E_ExternalMetricType
        "unsigned long",    // FIELD_routeCost
        "inet::Ipv4Address",    // FIELD_forwardingAddress
        "long",    // FIELD_externalRouteTag
        "inet::ospf::ExternalTosInfo",    // FIELD_externalTOSInfo
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfAsExternalLsaContentsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfAsExternalLsaContentsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfAsExternalLsaContentsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfAsExternalLsaContents *pp = (OspfAsExternalLsaContents *)object; (void)pp;
    switch (field) {
        case FIELD_externalTOSInfo: return pp->getExternalTOSInfoArraySize();
        default: return 0;
    }
}

const char *OspfAsExternalLsaContentsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfAsExternalLsaContents *pp = (OspfAsExternalLsaContents *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfAsExternalLsaContentsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfAsExternalLsaContents *pp = (OspfAsExternalLsaContents *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return pp->getNetworkMask().str();
        case FIELD_E_ExternalMetricType: return bool2string(pp->getE_ExternalMetricType());
        case FIELD_routeCost: return ulong2string(pp->getRouteCost());
        case FIELD_forwardingAddress: return pp->getForwardingAddress().str();
        case FIELD_externalRouteTag: return long2string(pp->getExternalRouteTag());
        case FIELD_externalTOSInfo: {std::stringstream out; out << pp->getExternalTOSInfo(i); return out.str();}
        default: return "";
    }
}

bool OspfAsExternalLsaContentsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfAsExternalLsaContents *pp = (OspfAsExternalLsaContents *)object; (void)pp;
    switch (field) {
        case FIELD_E_ExternalMetricType: pp->setE_ExternalMetricType(string2bool(value)); return true;
        case FIELD_routeCost: pp->setRouteCost(string2ulong(value)); return true;
        case FIELD_externalRouteTag: pp->setExternalRouteTag(string2long(value)); return true;
        default: return false;
    }
}

const char *OspfAsExternalLsaContentsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_externalTOSInfo: return omnetpp::opp_typename(typeid(ExternalTosInfo));
        default: return nullptr;
    };
}

void *OspfAsExternalLsaContentsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfAsExternalLsaContents *pp = (OspfAsExternalLsaContents *)object; (void)pp;
    switch (field) {
        case FIELD_networkMask: return toVoidPtr(&pp->getNetworkMask()); break;
        case FIELD_forwardingAddress: return toVoidPtr(&pp->getForwardingAddress()); break;
        case FIELD_externalTOSInfo: return toVoidPtr(&pp->getExternalTOSInfo(i)); break;
        default: return nullptr;
    }
}

Register_Class(OspfAsExternalLsa)

OspfAsExternalLsa::OspfAsExternalLsa() : ::inet::ospf::OspfLsa()
{
}

OspfAsExternalLsa::OspfAsExternalLsa(const OspfAsExternalLsa& other) : ::inet::ospf::OspfLsa(other)
{
    copy(other);
}

OspfAsExternalLsa::~OspfAsExternalLsa()
{
}

OspfAsExternalLsa& OspfAsExternalLsa::operator=(const OspfAsExternalLsa& other)
{
    if (this == &other) return *this;
    ::inet::ospf::OspfLsa::operator=(other);
    copy(other);
    return *this;
}

void OspfAsExternalLsa::copy(const OspfAsExternalLsa& other)
{
    this->contents = other.contents;
}

void OspfAsExternalLsa::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OspfLsa::parsimPack(b);
    doParsimPacking(b,this->contents);
}

void OspfAsExternalLsa::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OspfLsa::parsimUnpack(b);
    doParsimUnpacking(b,this->contents);
}

const OspfAsExternalLsaContents& OspfAsExternalLsa::getContents() const
{
    return this->contents;
}

void OspfAsExternalLsa::setContents(const OspfAsExternalLsaContents& contents)
{
    this->contents = contents;
}

class OspfAsExternalLsaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_contents,
    };
  public:
    OspfAsExternalLsaDescriptor();
    virtual ~OspfAsExternalLsaDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfAsExternalLsaDescriptor)

OspfAsExternalLsaDescriptor::OspfAsExternalLsaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfAsExternalLsa)), "inet::ospf::OspfLsa")
{
    propertynames = nullptr;
}

OspfAsExternalLsaDescriptor::~OspfAsExternalLsaDescriptor()
{
    delete[] propertynames;
}

bool OspfAsExternalLsaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfAsExternalLsa *>(obj)!=nullptr;
}

const char **OspfAsExternalLsaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfAsExternalLsaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfAsExternalLsaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int OspfAsExternalLsaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_contents
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *OspfAsExternalLsaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "contents",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int OspfAsExternalLsaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "contents") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfAsExternalLsaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ospf::OspfAsExternalLsaContents",    // FIELD_contents
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfAsExternalLsaDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfAsExternalLsaDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfAsExternalLsaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfAsExternalLsa *pp = (OspfAsExternalLsa *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *OspfAsExternalLsaDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfAsExternalLsa *pp = (OspfAsExternalLsa *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfAsExternalLsaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfAsExternalLsa *pp = (OspfAsExternalLsa *)object; (void)pp;
    switch (field) {
        case FIELD_contents: {std::stringstream out; out << pp->getContents(); return out.str();}
        default: return "";
    }
}

bool OspfAsExternalLsaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfAsExternalLsa *pp = (OspfAsExternalLsa *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OspfAsExternalLsaDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_contents: return omnetpp::opp_typename(typeid(OspfAsExternalLsaContents));
        default: return nullptr;
    };
}

void *OspfAsExternalLsaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfAsExternalLsa *pp = (OspfAsExternalLsa *)object; (void)pp;
    switch (field) {
        case FIELD_contents: return toVoidPtr(&pp->getContents()); break;
        default: return nullptr;
    }
}

OspfDdOptions::OspfDdOptions()
{
    this->unused_1 = false;
    this->unused_2 = false;
    this->unused_3 = false;
    this->unused_4 = false;
    this->unused_5 = false;
    this->I_Init = false;
    this->M_More = false;
    this->MS_MasterSlave = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const OspfDdOptions& a)
{
    doParsimPacking(b,a.unused_1);
    doParsimPacking(b,a.unused_2);
    doParsimPacking(b,a.unused_3);
    doParsimPacking(b,a.unused_4);
    doParsimPacking(b,a.unused_5);
    doParsimPacking(b,a.I_Init);
    doParsimPacking(b,a.M_More);
    doParsimPacking(b,a.MS_MasterSlave);
}

void __doUnpacking(omnetpp::cCommBuffer *b, OspfDdOptions& a)
{
    doParsimUnpacking(b,a.unused_1);
    doParsimUnpacking(b,a.unused_2);
    doParsimUnpacking(b,a.unused_3);
    doParsimUnpacking(b,a.unused_4);
    doParsimUnpacking(b,a.unused_5);
    doParsimUnpacking(b,a.I_Init);
    doParsimUnpacking(b,a.M_More);
    doParsimUnpacking(b,a.MS_MasterSlave);
}

class OspfDdOptionsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_unused_1,
        FIELD_unused_2,
        FIELD_unused_3,
        FIELD_unused_4,
        FIELD_unused_5,
        FIELD_I_Init,
        FIELD_M_More,
        FIELD_MS_MasterSlave,
    };
  public:
    OspfDdOptionsDescriptor();
    virtual ~OspfDdOptionsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfDdOptionsDescriptor)

OspfDdOptionsDescriptor::OspfDdOptionsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfDdOptions)), "")
{
    propertynames = nullptr;
}

OspfDdOptionsDescriptor::~OspfDdOptionsDescriptor()
{
    delete[] propertynames;
}

bool OspfDdOptionsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfDdOptions *>(obj)!=nullptr;
}

const char **OspfDdOptionsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfDdOptionsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfDdOptionsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OspfDdOptionsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_unused_1
        FD_ISEDITABLE,    // FIELD_unused_2
        FD_ISEDITABLE,    // FIELD_unused_3
        FD_ISEDITABLE,    // FIELD_unused_4
        FD_ISEDITABLE,    // FIELD_unused_5
        FD_ISEDITABLE,    // FIELD_I_Init
        FD_ISEDITABLE,    // FIELD_M_More
        FD_ISEDITABLE,    // FIELD_MS_MasterSlave
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *OspfDdOptionsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "unused_1",
        "unused_2",
        "unused_3",
        "unused_4",
        "unused_5",
        "I_Init",
        "M_More",
        "MS_MasterSlave",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int OspfDdOptionsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unused_1") == 0) return base+0;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unused_2") == 0) return base+1;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unused_3") == 0) return base+2;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unused_4") == 0) return base+3;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unused_5") == 0) return base+4;
    if (fieldName[0] == 'I' && strcmp(fieldName, "I_Init") == 0) return base+5;
    if (fieldName[0] == 'M' && strcmp(fieldName, "M_More") == 0) return base+6;
    if (fieldName[0] == 'M' && strcmp(fieldName, "MS_MasterSlave") == 0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfDdOptionsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_unused_1
        "bool",    // FIELD_unused_2
        "bool",    // FIELD_unused_3
        "bool",    // FIELD_unused_4
        "bool",    // FIELD_unused_5
        "bool",    // FIELD_I_Init
        "bool",    // FIELD_M_More
        "bool",    // FIELD_MS_MasterSlave
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfDdOptionsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfDdOptionsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfDdOptionsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfDdOptions *pp = (OspfDdOptions *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *OspfDdOptionsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfDdOptions *pp = (OspfDdOptions *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfDdOptionsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfDdOptions *pp = (OspfDdOptions *)object; (void)pp;
    switch (field) {
        case FIELD_unused_1: return bool2string(pp->unused_1);
        case FIELD_unused_2: return bool2string(pp->unused_2);
        case FIELD_unused_3: return bool2string(pp->unused_3);
        case FIELD_unused_4: return bool2string(pp->unused_4);
        case FIELD_unused_5: return bool2string(pp->unused_5);
        case FIELD_I_Init: return bool2string(pp->I_Init);
        case FIELD_M_More: return bool2string(pp->M_More);
        case FIELD_MS_MasterSlave: return bool2string(pp->MS_MasterSlave);
        default: return "";
    }
}

bool OspfDdOptionsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfDdOptions *pp = (OspfDdOptions *)object; (void)pp;
    switch (field) {
        case FIELD_unused_1: pp->unused_1 = string2bool(value); return true;
        case FIELD_unused_2: pp->unused_2 = string2bool(value); return true;
        case FIELD_unused_3: pp->unused_3 = string2bool(value); return true;
        case FIELD_unused_4: pp->unused_4 = string2bool(value); return true;
        case FIELD_unused_5: pp->unused_5 = string2bool(value); return true;
        case FIELD_I_Init: pp->I_Init = string2bool(value); return true;
        case FIELD_M_More: pp->M_More = string2bool(value); return true;
        case FIELD_MS_MasterSlave: pp->MS_MasterSlave = string2bool(value); return true;
        default: return false;
    }
}

const char *OspfDdOptionsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *OspfDdOptionsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfDdOptions *pp = (OspfDdOptions *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(OspfDatabaseDescriptionPacket)

OspfDatabaseDescriptionPacket::OspfDatabaseDescriptionPacket() : ::inet::ospf::OspfPacket()
{
}

OspfDatabaseDescriptionPacket::OspfDatabaseDescriptionPacket(const OspfDatabaseDescriptionPacket& other) : ::inet::ospf::OspfPacket(other)
{
    copy(other);
}

OspfDatabaseDescriptionPacket::~OspfDatabaseDescriptionPacket()
{
    delete [] this->lsaHeaders;
}

OspfDatabaseDescriptionPacket& OspfDatabaseDescriptionPacket::operator=(const OspfDatabaseDescriptionPacket& other)
{
    if (this == &other) return *this;
    ::inet::ospf::OspfPacket::operator=(other);
    copy(other);
    return *this;
}

void OspfDatabaseDescriptionPacket::copy(const OspfDatabaseDescriptionPacket& other)
{
    this->interfaceMTU = other.interfaceMTU;
    this->options = other.options;
    this->ddOptions = other.ddOptions;
    this->ddSequenceNumber = other.ddSequenceNumber;
    delete [] this->lsaHeaders;
    this->lsaHeaders = (other.lsaHeaders_arraysize==0) ? nullptr : new OspfLsaHeader[other.lsaHeaders_arraysize];
    lsaHeaders_arraysize = other.lsaHeaders_arraysize;
    for (size_t i = 0; i < lsaHeaders_arraysize; i++) {
        this->lsaHeaders[i] = other.lsaHeaders[i];
    }
}

void OspfDatabaseDescriptionPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OspfPacket::parsimPack(b);
    doParsimPacking(b,this->interfaceMTU);
    doParsimPacking(b,this->options);
    doParsimPacking(b,this->ddOptions);
    doParsimPacking(b,this->ddSequenceNumber);
    b->pack(lsaHeaders_arraysize);
    doParsimArrayPacking(b,this->lsaHeaders,lsaHeaders_arraysize);
}

void OspfDatabaseDescriptionPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OspfPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceMTU);
    doParsimUnpacking(b,this->options);
    doParsimUnpacking(b,this->ddOptions);
    doParsimUnpacking(b,this->ddSequenceNumber);
    delete [] this->lsaHeaders;
    b->unpack(lsaHeaders_arraysize);
    if (lsaHeaders_arraysize == 0) {
        this->lsaHeaders = nullptr;
    } else {
        this->lsaHeaders = new OspfLsaHeader[lsaHeaders_arraysize];
        doParsimArrayUnpacking(b,this->lsaHeaders,lsaHeaders_arraysize);
    }
}

unsigned short OspfDatabaseDescriptionPacket::getInterfaceMTU() const
{
    return this->interfaceMTU;
}

void OspfDatabaseDescriptionPacket::setInterfaceMTU(unsigned short interfaceMTU)
{
    handleChange();
    this->interfaceMTU = interfaceMTU;
}

const OspfOptions& OspfDatabaseDescriptionPacket::getOptions() const
{
    return this->options;
}

void OspfDatabaseDescriptionPacket::setOptions(const OspfOptions& options)
{
    handleChange();
    this->options = options;
}

const OspfDdOptions& OspfDatabaseDescriptionPacket::getDdOptions() const
{
    return this->ddOptions;
}

void OspfDatabaseDescriptionPacket::setDdOptions(const OspfDdOptions& ddOptions)
{
    handleChange();
    this->ddOptions = ddOptions;
}

unsigned long OspfDatabaseDescriptionPacket::getDdSequenceNumber() const
{
    return this->ddSequenceNumber;
}

void OspfDatabaseDescriptionPacket::setDdSequenceNumber(unsigned long ddSequenceNumber)
{
    handleChange();
    this->ddSequenceNumber = ddSequenceNumber;
}

size_t OspfDatabaseDescriptionPacket::getLsaHeadersArraySize() const
{
    return lsaHeaders_arraysize;
}

const OspfLsaHeader& OspfDatabaseDescriptionPacket::getLsaHeaders(size_t k) const
{
    if (k >= lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size lsaHeaders_arraysize indexed by %lu", (unsigned long)k);
    return this->lsaHeaders[k];
}

void OspfDatabaseDescriptionPacket::setLsaHeadersArraySize(size_t newSize)
{
    handleChange();
    OspfLsaHeader *lsaHeaders2 = (newSize==0) ? nullptr : new OspfLsaHeader[newSize];
    size_t minSize = lsaHeaders_arraysize < newSize ? lsaHeaders_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
    lsaHeaders_arraysize = newSize;
}

void OspfDatabaseDescriptionPacket::setLsaHeaders(size_t k, const OspfLsaHeader& lsaHeaders)
{
    if (k >= lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->lsaHeaders[k] = lsaHeaders;
}

void OspfDatabaseDescriptionPacket::insertLsaHeaders(size_t k, const OspfLsaHeader& lsaHeaders)
{
    handleChange();
    if (k > lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = lsaHeaders_arraysize + 1;
    OspfLsaHeader *lsaHeaders2 = new OspfLsaHeader[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    lsaHeaders2[k] = lsaHeaders;
    for (i = k + 1; i < newSize; i++)
        lsaHeaders2[i] = this->lsaHeaders[i-1];
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
    lsaHeaders_arraysize = newSize;
}

void OspfDatabaseDescriptionPacket::insertLsaHeaders(const OspfLsaHeader& lsaHeaders)
{
    insertLsaHeaders(lsaHeaders_arraysize, lsaHeaders);
}

void OspfDatabaseDescriptionPacket::eraseLsaHeaders(size_t k)
{
    if (k >= lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = lsaHeaders_arraysize - 1;
    OspfLsaHeader *lsaHeaders2 = (newSize == 0) ? nullptr : new OspfLsaHeader[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    for (i = k; i < newSize; i++)
        lsaHeaders2[i] = this->lsaHeaders[i+1];
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
    lsaHeaders_arraysize = newSize;
}

class OspfDatabaseDescriptionPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_interfaceMTU,
        FIELD_options,
        FIELD_ddOptions,
        FIELD_ddSequenceNumber,
        FIELD_lsaHeaders,
    };
  public:
    OspfDatabaseDescriptionPacketDescriptor();
    virtual ~OspfDatabaseDescriptionPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfDatabaseDescriptionPacketDescriptor)

OspfDatabaseDescriptionPacketDescriptor::OspfDatabaseDescriptionPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfDatabaseDescriptionPacket)), "inet::ospf::OspfPacket")
{
    propertynames = nullptr;
}

OspfDatabaseDescriptionPacketDescriptor::~OspfDatabaseDescriptionPacketDescriptor()
{
    delete[] propertynames;
}

bool OspfDatabaseDescriptionPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfDatabaseDescriptionPacket *>(obj)!=nullptr;
}

const char **OspfDatabaseDescriptionPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfDatabaseDescriptionPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfDatabaseDescriptionPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OspfDatabaseDescriptionPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_interfaceMTU
        FD_ISCOMPOUND,    // FIELD_options
        FD_ISCOMPOUND,    // FIELD_ddOptions
        FD_ISEDITABLE,    // FIELD_ddSequenceNumber
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_lsaHeaders
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *OspfDatabaseDescriptionPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceMTU",
        "options",
        "ddOptions",
        "ddSequenceNumber",
        "lsaHeaders",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int OspfDatabaseDescriptionPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interfaceMTU") == 0) return base+0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "options") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "ddOptions") == 0) return base+2;
    if (fieldName[0] == 'd' && strcmp(fieldName, "ddSequenceNumber") == 0) return base+3;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsaHeaders") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfDatabaseDescriptionPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_interfaceMTU
        "inet::ospf::OspfOptions",    // FIELD_options
        "inet::ospf::OspfDdOptions",    // FIELD_ddOptions
        "unsigned long",    // FIELD_ddSequenceNumber
        "inet::ospf::OspfLsaHeader",    // FIELD_lsaHeaders
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfDatabaseDescriptionPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfDatabaseDescriptionPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfDatabaseDescriptionPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfDatabaseDescriptionPacket *pp = (OspfDatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case FIELD_lsaHeaders: return pp->getLsaHeadersArraySize();
        default: return 0;
    }
}

const char *OspfDatabaseDescriptionPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfDatabaseDescriptionPacket *pp = (OspfDatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfDatabaseDescriptionPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfDatabaseDescriptionPacket *pp = (OspfDatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceMTU: return ulong2string(pp->getInterfaceMTU());
        case FIELD_options: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case FIELD_ddOptions: {std::stringstream out; out << pp->getDdOptions(); return out.str();}
        case FIELD_ddSequenceNumber: return ulong2string(pp->getDdSequenceNumber());
        case FIELD_lsaHeaders: {std::stringstream out; out << pp->getLsaHeaders(i); return out.str();}
        default: return "";
    }
}

bool OspfDatabaseDescriptionPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfDatabaseDescriptionPacket *pp = (OspfDatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceMTU: pp->setInterfaceMTU(string2ulong(value)); return true;
        case FIELD_ddSequenceNumber: pp->setDdSequenceNumber(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfDatabaseDescriptionPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options: return omnetpp::opp_typename(typeid(OspfOptions));
        case FIELD_ddOptions: return omnetpp::opp_typename(typeid(OspfDdOptions));
        case FIELD_lsaHeaders: return omnetpp::opp_typename(typeid(OspfLsaHeader));
        default: return nullptr;
    };
}

void *OspfDatabaseDescriptionPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfDatabaseDescriptionPacket *pp = (OspfDatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case FIELD_options: return toVoidPtr(&pp->getOptions()); break;
        case FIELD_ddOptions: return toVoidPtr(&pp->getDdOptions()); break;
        case FIELD_lsaHeaders: return toVoidPtr(&pp->getLsaHeaders(i)); break;
        default: return nullptr;
    }
}

LsaRequest::LsaRequest()
{
    this->lsType = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const LsaRequest& a)
{
    doParsimPacking(b,a.lsType);
    doParsimPacking(b,a.linkStateID);
    doParsimPacking(b,a.advertisingRouter);
}

void __doUnpacking(omnetpp::cCommBuffer *b, LsaRequest& a)
{
    doParsimUnpacking(b,a.lsType);
    doParsimUnpacking(b,a.linkStateID);
    doParsimUnpacking(b,a.advertisingRouter);
}

class LsaRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_lsType,
        FIELD_linkStateID,
        FIELD_advertisingRouter,
    };
  public:
    LsaRequestDescriptor();
    virtual ~LsaRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(LsaRequestDescriptor)

LsaRequestDescriptor::LsaRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::LsaRequest)), "")
{
    propertynames = nullptr;
}

LsaRequestDescriptor::~LsaRequestDescriptor()
{
    delete[] propertynames;
}

bool LsaRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LsaRequest *>(obj)!=nullptr;
}

const char **LsaRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LsaRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LsaRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int LsaRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_lsType
        0,    // FIELD_linkStateID
        0,    // FIELD_advertisingRouter
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *LsaRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsType",
        "linkStateID",
        "advertisingRouter",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int LsaRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsType") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "linkStateID") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "advertisingRouter") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LsaRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned long",    // FIELD_lsType
        "inet::Ipv4Address",    // FIELD_linkStateID
        "inet::Ipv4Address",    // FIELD_advertisingRouter
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **LsaRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *LsaRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int LsaRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LsaRequest *pp = (LsaRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LsaRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LsaRequest *pp = (LsaRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LsaRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LsaRequest *pp = (LsaRequest *)object; (void)pp;
    switch (field) {
        case FIELD_lsType: return ulong2string(pp->lsType);
        case FIELD_linkStateID: return pp->linkStateID.str();
        case FIELD_advertisingRouter: return pp->advertisingRouter.str();
        default: return "";
    }
}

bool LsaRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LsaRequest *pp = (LsaRequest *)object; (void)pp;
    switch (field) {
        case FIELD_lsType: pp->lsType = string2ulong(value); return true;
        default: return false;
    }
}

const char *LsaRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *LsaRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LsaRequest *pp = (LsaRequest *)object; (void)pp;
    switch (field) {
        case FIELD_linkStateID: return toVoidPtr(&pp->linkStateID); break;
        case FIELD_advertisingRouter: return toVoidPtr(&pp->advertisingRouter); break;
        default: return nullptr;
    }
}

Register_Class(OspfLinkStateRequestPacket)

OspfLinkStateRequestPacket::OspfLinkStateRequestPacket() : ::inet::ospf::OspfPacket()
{
}

OspfLinkStateRequestPacket::OspfLinkStateRequestPacket(const OspfLinkStateRequestPacket& other) : ::inet::ospf::OspfPacket(other)
{
    copy(other);
}

OspfLinkStateRequestPacket::~OspfLinkStateRequestPacket()
{
    delete [] this->requests;
}

OspfLinkStateRequestPacket& OspfLinkStateRequestPacket::operator=(const OspfLinkStateRequestPacket& other)
{
    if (this == &other) return *this;
    ::inet::ospf::OspfPacket::operator=(other);
    copy(other);
    return *this;
}

void OspfLinkStateRequestPacket::copy(const OspfLinkStateRequestPacket& other)
{
    delete [] this->requests;
    this->requests = (other.requests_arraysize==0) ? nullptr : new LsaRequest[other.requests_arraysize];
    requests_arraysize = other.requests_arraysize;
    for (size_t i = 0; i < requests_arraysize; i++) {
        this->requests[i] = other.requests[i];
    }
}

void OspfLinkStateRequestPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OspfPacket::parsimPack(b);
    b->pack(requests_arraysize);
    doParsimArrayPacking(b,this->requests,requests_arraysize);
}

void OspfLinkStateRequestPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OspfPacket::parsimUnpack(b);
    delete [] this->requests;
    b->unpack(requests_arraysize);
    if (requests_arraysize == 0) {
        this->requests = nullptr;
    } else {
        this->requests = new LsaRequest[requests_arraysize];
        doParsimArrayUnpacking(b,this->requests,requests_arraysize);
    }
}

size_t OspfLinkStateRequestPacket::getRequestsArraySize() const
{
    return requests_arraysize;
}

const LsaRequest& OspfLinkStateRequestPacket::getRequests(size_t k) const
{
    if (k >= requests_arraysize) throw omnetpp::cRuntimeError("Array of size requests_arraysize indexed by %lu", (unsigned long)k);
    return this->requests[k];
}

void OspfLinkStateRequestPacket::setRequestsArraySize(size_t newSize)
{
    handleChange();
    LsaRequest *requests2 = (newSize==0) ? nullptr : new LsaRequest[newSize];
    size_t minSize = requests_arraysize < newSize ? requests_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        requests2[i] = this->requests[i];
    delete [] this->requests;
    this->requests = requests2;
    requests_arraysize = newSize;
}

void OspfLinkStateRequestPacket::setRequests(size_t k, const LsaRequest& requests)
{
    if (k >= requests_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->requests[k] = requests;
}

void OspfLinkStateRequestPacket::insertRequests(size_t k, const LsaRequest& requests)
{
    handleChange();
    if (k > requests_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = requests_arraysize + 1;
    LsaRequest *requests2 = new LsaRequest[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        requests2[i] = this->requests[i];
    requests2[k] = requests;
    for (i = k + 1; i < newSize; i++)
        requests2[i] = this->requests[i-1];
    delete [] this->requests;
    this->requests = requests2;
    requests_arraysize = newSize;
}

void OspfLinkStateRequestPacket::insertRequests(const LsaRequest& requests)
{
    insertRequests(requests_arraysize, requests);
}

void OspfLinkStateRequestPacket::eraseRequests(size_t k)
{
    if (k >= requests_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = requests_arraysize - 1;
    LsaRequest *requests2 = (newSize == 0) ? nullptr : new LsaRequest[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        requests2[i] = this->requests[i];
    for (i = k; i < newSize; i++)
        requests2[i] = this->requests[i+1];
    delete [] this->requests;
    this->requests = requests2;
    requests_arraysize = newSize;
}

class OspfLinkStateRequestPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_requests,
    };
  public:
    OspfLinkStateRequestPacketDescriptor();
    virtual ~OspfLinkStateRequestPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfLinkStateRequestPacketDescriptor)

OspfLinkStateRequestPacketDescriptor::OspfLinkStateRequestPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfLinkStateRequestPacket)), "inet::ospf::OspfPacket")
{
    propertynames = nullptr;
}

OspfLinkStateRequestPacketDescriptor::~OspfLinkStateRequestPacketDescriptor()
{
    delete[] propertynames;
}

bool OspfLinkStateRequestPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfLinkStateRequestPacket *>(obj)!=nullptr;
}

const char **OspfLinkStateRequestPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfLinkStateRequestPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfLinkStateRequestPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int OspfLinkStateRequestPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_requests
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *OspfLinkStateRequestPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "requests",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int OspfLinkStateRequestPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "requests") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfLinkStateRequestPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ospf::LsaRequest",    // FIELD_requests
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfLinkStateRequestPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfLinkStateRequestPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfLinkStateRequestPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateRequestPacket *pp = (OspfLinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        case FIELD_requests: return pp->getRequestsArraySize();
        default: return 0;
    }
}

const char *OspfLinkStateRequestPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateRequestPacket *pp = (OspfLinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfLinkStateRequestPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateRequestPacket *pp = (OspfLinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        case FIELD_requests: {std::stringstream out; out << pp->getRequests(i); return out.str();}
        default: return "";
    }
}

bool OspfLinkStateRequestPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateRequestPacket *pp = (OspfLinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OspfLinkStateRequestPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_requests: return omnetpp::opp_typename(typeid(LsaRequest));
        default: return nullptr;
    };
}

void *OspfLinkStateRequestPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateRequestPacket *pp = (OspfLinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        case FIELD_requests: return toVoidPtr(&pp->getRequests(i)); break;
        default: return nullptr;
    }
}

Register_Class(OspfLinkStateUpdatePacket)

OspfLinkStateUpdatePacket::OspfLinkStateUpdatePacket() : ::inet::ospf::OspfPacket()
{
}

OspfLinkStateUpdatePacket::OspfLinkStateUpdatePacket(const OspfLinkStateUpdatePacket& other) : ::inet::ospf::OspfPacket(other)
{
    copy(other);
}

OspfLinkStateUpdatePacket::~OspfLinkStateUpdatePacket()
{
    delete [] this->routerLSAs;
    delete [] this->networkLSAs;
    delete [] this->summaryLSAs;
    delete [] this->asExternalLSAs;
}

OspfLinkStateUpdatePacket& OspfLinkStateUpdatePacket::operator=(const OspfLinkStateUpdatePacket& other)
{
    if (this == &other) return *this;
    ::inet::ospf::OspfPacket::operator=(other);
    copy(other);
    return *this;
}

void OspfLinkStateUpdatePacket::copy(const OspfLinkStateUpdatePacket& other)
{
    this->numberOfLSAs = other.numberOfLSAs;
    delete [] this->routerLSAs;
    this->routerLSAs = (other.routerLSAs_arraysize==0) ? nullptr : new OspfRouterLsa[other.routerLSAs_arraysize];
    routerLSAs_arraysize = other.routerLSAs_arraysize;
    for (size_t i = 0; i < routerLSAs_arraysize; i++) {
        this->routerLSAs[i] = other.routerLSAs[i];
    }
    delete [] this->networkLSAs;
    this->networkLSAs = (other.networkLSAs_arraysize==0) ? nullptr : new OspfNetworkLsa[other.networkLSAs_arraysize];
    networkLSAs_arraysize = other.networkLSAs_arraysize;
    for (size_t i = 0; i < networkLSAs_arraysize; i++) {
        this->networkLSAs[i] = other.networkLSAs[i];
    }
    delete [] this->summaryLSAs;
    this->summaryLSAs = (other.summaryLSAs_arraysize==0) ? nullptr : new OspfSummaryLsa[other.summaryLSAs_arraysize];
    summaryLSAs_arraysize = other.summaryLSAs_arraysize;
    for (size_t i = 0; i < summaryLSAs_arraysize; i++) {
        this->summaryLSAs[i] = other.summaryLSAs[i];
    }
    delete [] this->asExternalLSAs;
    this->asExternalLSAs = (other.asExternalLSAs_arraysize==0) ? nullptr : new OspfAsExternalLsa[other.asExternalLSAs_arraysize];
    asExternalLSAs_arraysize = other.asExternalLSAs_arraysize;
    for (size_t i = 0; i < asExternalLSAs_arraysize; i++) {
        this->asExternalLSAs[i] = other.asExternalLSAs[i];
    }
}

void OspfLinkStateUpdatePacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OspfPacket::parsimPack(b);
    doParsimPacking(b,this->numberOfLSAs);
    b->pack(routerLSAs_arraysize);
    doParsimArrayPacking(b,this->routerLSAs,routerLSAs_arraysize);
    b->pack(networkLSAs_arraysize);
    doParsimArrayPacking(b,this->networkLSAs,networkLSAs_arraysize);
    b->pack(summaryLSAs_arraysize);
    doParsimArrayPacking(b,this->summaryLSAs,summaryLSAs_arraysize);
    b->pack(asExternalLSAs_arraysize);
    doParsimArrayPacking(b,this->asExternalLSAs,asExternalLSAs_arraysize);
}

void OspfLinkStateUpdatePacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OspfPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->numberOfLSAs);
    delete [] this->routerLSAs;
    b->unpack(routerLSAs_arraysize);
    if (routerLSAs_arraysize == 0) {
        this->routerLSAs = nullptr;
    } else {
        this->routerLSAs = new OspfRouterLsa[routerLSAs_arraysize];
        doParsimArrayUnpacking(b,this->routerLSAs,routerLSAs_arraysize);
    }
    delete [] this->networkLSAs;
    b->unpack(networkLSAs_arraysize);
    if (networkLSAs_arraysize == 0) {
        this->networkLSAs = nullptr;
    } else {
        this->networkLSAs = new OspfNetworkLsa[networkLSAs_arraysize];
        doParsimArrayUnpacking(b,this->networkLSAs,networkLSAs_arraysize);
    }
    delete [] this->summaryLSAs;
    b->unpack(summaryLSAs_arraysize);
    if (summaryLSAs_arraysize == 0) {
        this->summaryLSAs = nullptr;
    } else {
        this->summaryLSAs = new OspfSummaryLsa[summaryLSAs_arraysize];
        doParsimArrayUnpacking(b,this->summaryLSAs,summaryLSAs_arraysize);
    }
    delete [] this->asExternalLSAs;
    b->unpack(asExternalLSAs_arraysize);
    if (asExternalLSAs_arraysize == 0) {
        this->asExternalLSAs = nullptr;
    } else {
        this->asExternalLSAs = new OspfAsExternalLsa[asExternalLSAs_arraysize];
        doParsimArrayUnpacking(b,this->asExternalLSAs,asExternalLSAs_arraysize);
    }
}

unsigned long OspfLinkStateUpdatePacket::getNumberOfLSAs() const
{
    return this->numberOfLSAs;
}

void OspfLinkStateUpdatePacket::setNumberOfLSAs(unsigned long numberOfLSAs)
{
    handleChange();
    this->numberOfLSAs = numberOfLSAs;
}

size_t OspfLinkStateUpdatePacket::getRouterLSAsArraySize() const
{
    return routerLSAs_arraysize;
}

const OspfRouterLsa& OspfLinkStateUpdatePacket::getRouterLSAs(size_t k) const
{
    if (k >= routerLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size routerLSAs_arraysize indexed by %lu", (unsigned long)k);
    return this->routerLSAs[k];
}

void OspfLinkStateUpdatePacket::setRouterLSAsArraySize(size_t newSize)
{
    handleChange();
    OspfRouterLsa *routerLSAs2 = (newSize==0) ? nullptr : new OspfRouterLsa[newSize];
    size_t minSize = routerLSAs_arraysize < newSize ? routerLSAs_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        routerLSAs2[i] = this->routerLSAs[i];
    delete [] this->routerLSAs;
    this->routerLSAs = routerLSAs2;
    routerLSAs_arraysize = newSize;
}

void OspfLinkStateUpdatePacket::setRouterLSAs(size_t k, const OspfRouterLsa& routerLSAs)
{
    if (k >= routerLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->routerLSAs[k] = routerLSAs;
}

void OspfLinkStateUpdatePacket::insertRouterLSAs(size_t k, const OspfRouterLsa& routerLSAs)
{
    handleChange();
    if (k > routerLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = routerLSAs_arraysize + 1;
    OspfRouterLsa *routerLSAs2 = new OspfRouterLsa[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        routerLSAs2[i] = this->routerLSAs[i];
    routerLSAs2[k] = routerLSAs;
    for (i = k + 1; i < newSize; i++)
        routerLSAs2[i] = this->routerLSAs[i-1];
    delete [] this->routerLSAs;
    this->routerLSAs = routerLSAs2;
    routerLSAs_arraysize = newSize;
}

void OspfLinkStateUpdatePacket::insertRouterLSAs(const OspfRouterLsa& routerLSAs)
{
    insertRouterLSAs(routerLSAs_arraysize, routerLSAs);
}

void OspfLinkStateUpdatePacket::eraseRouterLSAs(size_t k)
{
    if (k >= routerLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = routerLSAs_arraysize - 1;
    OspfRouterLsa *routerLSAs2 = (newSize == 0) ? nullptr : new OspfRouterLsa[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        routerLSAs2[i] = this->routerLSAs[i];
    for (i = k; i < newSize; i++)
        routerLSAs2[i] = this->routerLSAs[i+1];
    delete [] this->routerLSAs;
    this->routerLSAs = routerLSAs2;
    routerLSAs_arraysize = newSize;
}

size_t OspfLinkStateUpdatePacket::getNetworkLSAsArraySize() const
{
    return networkLSAs_arraysize;
}

const OspfNetworkLsa& OspfLinkStateUpdatePacket::getNetworkLSAs(size_t k) const
{
    if (k >= networkLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size networkLSAs_arraysize indexed by %lu", (unsigned long)k);
    return this->networkLSAs[k];
}

void OspfLinkStateUpdatePacket::setNetworkLSAsArraySize(size_t newSize)
{
    handleChange();
    OspfNetworkLsa *networkLSAs2 = (newSize==0) ? nullptr : new OspfNetworkLsa[newSize];
    size_t minSize = networkLSAs_arraysize < newSize ? networkLSAs_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        networkLSAs2[i] = this->networkLSAs[i];
    delete [] this->networkLSAs;
    this->networkLSAs = networkLSAs2;
    networkLSAs_arraysize = newSize;
}

void OspfLinkStateUpdatePacket::setNetworkLSAs(size_t k, const OspfNetworkLsa& networkLSAs)
{
    if (k >= networkLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->networkLSAs[k] = networkLSAs;
}

void OspfLinkStateUpdatePacket::insertNetworkLSAs(size_t k, const OspfNetworkLsa& networkLSAs)
{
    handleChange();
    if (k > networkLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = networkLSAs_arraysize + 1;
    OspfNetworkLsa *networkLSAs2 = new OspfNetworkLsa[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        networkLSAs2[i] = this->networkLSAs[i];
    networkLSAs2[k] = networkLSAs;
    for (i = k + 1; i < newSize; i++)
        networkLSAs2[i] = this->networkLSAs[i-1];
    delete [] this->networkLSAs;
    this->networkLSAs = networkLSAs2;
    networkLSAs_arraysize = newSize;
}

void OspfLinkStateUpdatePacket::insertNetworkLSAs(const OspfNetworkLsa& networkLSAs)
{
    insertNetworkLSAs(networkLSAs_arraysize, networkLSAs);
}

void OspfLinkStateUpdatePacket::eraseNetworkLSAs(size_t k)
{
    if (k >= networkLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = networkLSAs_arraysize - 1;
    OspfNetworkLsa *networkLSAs2 = (newSize == 0) ? nullptr : new OspfNetworkLsa[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        networkLSAs2[i] = this->networkLSAs[i];
    for (i = k; i < newSize; i++)
        networkLSAs2[i] = this->networkLSAs[i+1];
    delete [] this->networkLSAs;
    this->networkLSAs = networkLSAs2;
    networkLSAs_arraysize = newSize;
}

size_t OspfLinkStateUpdatePacket::getSummaryLSAsArraySize() const
{
    return summaryLSAs_arraysize;
}

const OspfSummaryLsa& OspfLinkStateUpdatePacket::getSummaryLSAs(size_t k) const
{
    if (k >= summaryLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size summaryLSAs_arraysize indexed by %lu", (unsigned long)k);
    return this->summaryLSAs[k];
}

void OspfLinkStateUpdatePacket::setSummaryLSAsArraySize(size_t newSize)
{
    handleChange();
    OspfSummaryLsa *summaryLSAs2 = (newSize==0) ? nullptr : new OspfSummaryLsa[newSize];
    size_t minSize = summaryLSAs_arraysize < newSize ? summaryLSAs_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        summaryLSAs2[i] = this->summaryLSAs[i];
    delete [] this->summaryLSAs;
    this->summaryLSAs = summaryLSAs2;
    summaryLSAs_arraysize = newSize;
}

void OspfLinkStateUpdatePacket::setSummaryLSAs(size_t k, const OspfSummaryLsa& summaryLSAs)
{
    if (k >= summaryLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->summaryLSAs[k] = summaryLSAs;
}

void OspfLinkStateUpdatePacket::insertSummaryLSAs(size_t k, const OspfSummaryLsa& summaryLSAs)
{
    handleChange();
    if (k > summaryLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = summaryLSAs_arraysize + 1;
    OspfSummaryLsa *summaryLSAs2 = new OspfSummaryLsa[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        summaryLSAs2[i] = this->summaryLSAs[i];
    summaryLSAs2[k] = summaryLSAs;
    for (i = k + 1; i < newSize; i++)
        summaryLSAs2[i] = this->summaryLSAs[i-1];
    delete [] this->summaryLSAs;
    this->summaryLSAs = summaryLSAs2;
    summaryLSAs_arraysize = newSize;
}

void OspfLinkStateUpdatePacket::insertSummaryLSAs(const OspfSummaryLsa& summaryLSAs)
{
    insertSummaryLSAs(summaryLSAs_arraysize, summaryLSAs);
}

void OspfLinkStateUpdatePacket::eraseSummaryLSAs(size_t k)
{
    if (k >= summaryLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = summaryLSAs_arraysize - 1;
    OspfSummaryLsa *summaryLSAs2 = (newSize == 0) ? nullptr : new OspfSummaryLsa[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        summaryLSAs2[i] = this->summaryLSAs[i];
    for (i = k; i < newSize; i++)
        summaryLSAs2[i] = this->summaryLSAs[i+1];
    delete [] this->summaryLSAs;
    this->summaryLSAs = summaryLSAs2;
    summaryLSAs_arraysize = newSize;
}

size_t OspfLinkStateUpdatePacket::getAsExternalLSAsArraySize() const
{
    return asExternalLSAs_arraysize;
}

const OspfAsExternalLsa& OspfLinkStateUpdatePacket::getAsExternalLSAs(size_t k) const
{
    if (k >= asExternalLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size asExternalLSAs_arraysize indexed by %lu", (unsigned long)k);
    return this->asExternalLSAs[k];
}

void OspfLinkStateUpdatePacket::setAsExternalLSAsArraySize(size_t newSize)
{
    handleChange();
    OspfAsExternalLsa *asExternalLSAs2 = (newSize==0) ? nullptr : new OspfAsExternalLsa[newSize];
    size_t minSize = asExternalLSAs_arraysize < newSize ? asExternalLSAs_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        asExternalLSAs2[i] = this->asExternalLSAs[i];
    delete [] this->asExternalLSAs;
    this->asExternalLSAs = asExternalLSAs2;
    asExternalLSAs_arraysize = newSize;
}

void OspfLinkStateUpdatePacket::setAsExternalLSAs(size_t k, const OspfAsExternalLsa& asExternalLSAs)
{
    if (k >= asExternalLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->asExternalLSAs[k] = asExternalLSAs;
}

void OspfLinkStateUpdatePacket::insertAsExternalLSAs(size_t k, const OspfAsExternalLsa& asExternalLSAs)
{
    handleChange();
    if (k > asExternalLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = asExternalLSAs_arraysize + 1;
    OspfAsExternalLsa *asExternalLSAs2 = new OspfAsExternalLsa[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        asExternalLSAs2[i] = this->asExternalLSAs[i];
    asExternalLSAs2[k] = asExternalLSAs;
    for (i = k + 1; i < newSize; i++)
        asExternalLSAs2[i] = this->asExternalLSAs[i-1];
    delete [] this->asExternalLSAs;
    this->asExternalLSAs = asExternalLSAs2;
    asExternalLSAs_arraysize = newSize;
}

void OspfLinkStateUpdatePacket::insertAsExternalLSAs(const OspfAsExternalLsa& asExternalLSAs)
{
    insertAsExternalLSAs(asExternalLSAs_arraysize, asExternalLSAs);
}

void OspfLinkStateUpdatePacket::eraseAsExternalLSAs(size_t k)
{
    if (k >= asExternalLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = asExternalLSAs_arraysize - 1;
    OspfAsExternalLsa *asExternalLSAs2 = (newSize == 0) ? nullptr : new OspfAsExternalLsa[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        asExternalLSAs2[i] = this->asExternalLSAs[i];
    for (i = k; i < newSize; i++)
        asExternalLSAs2[i] = this->asExternalLSAs[i+1];
    delete [] this->asExternalLSAs;
    this->asExternalLSAs = asExternalLSAs2;
    asExternalLSAs_arraysize = newSize;
}

class OspfLinkStateUpdatePacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_numberOfLSAs,
        FIELD_routerLSAs,
        FIELD_networkLSAs,
        FIELD_summaryLSAs,
        FIELD_asExternalLSAs,
    };
  public:
    OspfLinkStateUpdatePacketDescriptor();
    virtual ~OspfLinkStateUpdatePacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfLinkStateUpdatePacketDescriptor)

OspfLinkStateUpdatePacketDescriptor::OspfLinkStateUpdatePacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfLinkStateUpdatePacket)), "inet::ospf::OspfPacket")
{
    propertynames = nullptr;
}

OspfLinkStateUpdatePacketDescriptor::~OspfLinkStateUpdatePacketDescriptor()
{
    delete[] propertynames;
}

bool OspfLinkStateUpdatePacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfLinkStateUpdatePacket *>(obj)!=nullptr;
}

const char **OspfLinkStateUpdatePacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfLinkStateUpdatePacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfLinkStateUpdatePacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OspfLinkStateUpdatePacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_numberOfLSAs
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_routerLSAs
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_networkLSAs
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_summaryLSAs
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_asExternalLSAs
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *OspfLinkStateUpdatePacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "numberOfLSAs",
        "routerLSAs",
        "networkLSAs",
        "summaryLSAs",
        "asExternalLSAs",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int OspfLinkStateUpdatePacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numberOfLSAs") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routerLSAs") == 0) return base+1;
    if (fieldName[0] == 'n' && strcmp(fieldName, "networkLSAs") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "summaryLSAs") == 0) return base+3;
    if (fieldName[0] == 'a' && strcmp(fieldName, "asExternalLSAs") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfLinkStateUpdatePacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned long",    // FIELD_numberOfLSAs
        "inet::ospf::OspfRouterLsa",    // FIELD_routerLSAs
        "inet::ospf::OspfNetworkLsa",    // FIELD_networkLSAs
        "inet::ospf::OspfSummaryLsa",    // FIELD_summaryLSAs
        "inet::ospf::OspfAsExternalLsa",    // FIELD_asExternalLSAs
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfLinkStateUpdatePacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfLinkStateUpdatePacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfLinkStateUpdatePacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateUpdatePacket *pp = (OspfLinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case FIELD_routerLSAs: return pp->getRouterLSAsArraySize();
        case FIELD_networkLSAs: return pp->getNetworkLSAsArraySize();
        case FIELD_summaryLSAs: return pp->getSummaryLSAsArraySize();
        case FIELD_asExternalLSAs: return pp->getAsExternalLSAsArraySize();
        default: return 0;
    }
}

const char *OspfLinkStateUpdatePacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateUpdatePacket *pp = (OspfLinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfLinkStateUpdatePacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateUpdatePacket *pp = (OspfLinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case FIELD_numberOfLSAs: return ulong2string(pp->getNumberOfLSAs());
        case FIELD_routerLSAs: {std::stringstream out; out << pp->getRouterLSAs(i); return out.str();}
        case FIELD_networkLSAs: {std::stringstream out; out << pp->getNetworkLSAs(i); return out.str();}
        case FIELD_summaryLSAs: {std::stringstream out; out << pp->getSummaryLSAs(i); return out.str();}
        case FIELD_asExternalLSAs: {std::stringstream out; out << pp->getAsExternalLSAs(i); return out.str();}
        default: return "";
    }
}

bool OspfLinkStateUpdatePacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateUpdatePacket *pp = (OspfLinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case FIELD_numberOfLSAs: pp->setNumberOfLSAs(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfLinkStateUpdatePacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_routerLSAs: return omnetpp::opp_typename(typeid(OspfRouterLsa));
        case FIELD_networkLSAs: return omnetpp::opp_typename(typeid(OspfNetworkLsa));
        case FIELD_summaryLSAs: return omnetpp::opp_typename(typeid(OspfSummaryLsa));
        case FIELD_asExternalLSAs: return omnetpp::opp_typename(typeid(OspfAsExternalLsa));
        default: return nullptr;
    };
}

void *OspfLinkStateUpdatePacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateUpdatePacket *pp = (OspfLinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case FIELD_routerLSAs: return toVoidPtr(&pp->getRouterLSAs(i)); break;
        case FIELD_networkLSAs: return toVoidPtr(&pp->getNetworkLSAs(i)); break;
        case FIELD_summaryLSAs: return toVoidPtr(&pp->getSummaryLSAs(i)); break;
        case FIELD_asExternalLSAs: return toVoidPtr(&pp->getAsExternalLSAs(i)); break;
        default: return nullptr;
    }
}

Register_Class(OspfLinkStateAcknowledgementPacket)

OspfLinkStateAcknowledgementPacket::OspfLinkStateAcknowledgementPacket() : ::inet::ospf::OspfPacket()
{
}

OspfLinkStateAcknowledgementPacket::OspfLinkStateAcknowledgementPacket(const OspfLinkStateAcknowledgementPacket& other) : ::inet::ospf::OspfPacket(other)
{
    copy(other);
}

OspfLinkStateAcknowledgementPacket::~OspfLinkStateAcknowledgementPacket()
{
    delete [] this->lsaHeaders;
}

OspfLinkStateAcknowledgementPacket& OspfLinkStateAcknowledgementPacket::operator=(const OspfLinkStateAcknowledgementPacket& other)
{
    if (this == &other) return *this;
    ::inet::ospf::OspfPacket::operator=(other);
    copy(other);
    return *this;
}

void OspfLinkStateAcknowledgementPacket::copy(const OspfLinkStateAcknowledgementPacket& other)
{
    delete [] this->lsaHeaders;
    this->lsaHeaders = (other.lsaHeaders_arraysize==0) ? nullptr : new OspfLsaHeader[other.lsaHeaders_arraysize];
    lsaHeaders_arraysize = other.lsaHeaders_arraysize;
    for (size_t i = 0; i < lsaHeaders_arraysize; i++) {
        this->lsaHeaders[i] = other.lsaHeaders[i];
    }
}

void OspfLinkStateAcknowledgementPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OspfPacket::parsimPack(b);
    b->pack(lsaHeaders_arraysize);
    doParsimArrayPacking(b,this->lsaHeaders,lsaHeaders_arraysize);
}

void OspfLinkStateAcknowledgementPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OspfPacket::parsimUnpack(b);
    delete [] this->lsaHeaders;
    b->unpack(lsaHeaders_arraysize);
    if (lsaHeaders_arraysize == 0) {
        this->lsaHeaders = nullptr;
    } else {
        this->lsaHeaders = new OspfLsaHeader[lsaHeaders_arraysize];
        doParsimArrayUnpacking(b,this->lsaHeaders,lsaHeaders_arraysize);
    }
}

size_t OspfLinkStateAcknowledgementPacket::getLsaHeadersArraySize() const
{
    return lsaHeaders_arraysize;
}

const OspfLsaHeader& OspfLinkStateAcknowledgementPacket::getLsaHeaders(size_t k) const
{
    if (k >= lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size lsaHeaders_arraysize indexed by %lu", (unsigned long)k);
    return this->lsaHeaders[k];
}

void OspfLinkStateAcknowledgementPacket::setLsaHeadersArraySize(size_t newSize)
{
    handleChange();
    OspfLsaHeader *lsaHeaders2 = (newSize==0) ? nullptr : new OspfLsaHeader[newSize];
    size_t minSize = lsaHeaders_arraysize < newSize ? lsaHeaders_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
    lsaHeaders_arraysize = newSize;
}

void OspfLinkStateAcknowledgementPacket::setLsaHeaders(size_t k, const OspfLsaHeader& lsaHeaders)
{
    if (k >= lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->lsaHeaders[k] = lsaHeaders;
}

void OspfLinkStateAcknowledgementPacket::insertLsaHeaders(size_t k, const OspfLsaHeader& lsaHeaders)
{
    handleChange();
    if (k > lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = lsaHeaders_arraysize + 1;
    OspfLsaHeader *lsaHeaders2 = new OspfLsaHeader[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    lsaHeaders2[k] = lsaHeaders;
    for (i = k + 1; i < newSize; i++)
        lsaHeaders2[i] = this->lsaHeaders[i-1];
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
    lsaHeaders_arraysize = newSize;
}

void OspfLinkStateAcknowledgementPacket::insertLsaHeaders(const OspfLsaHeader& lsaHeaders)
{
    insertLsaHeaders(lsaHeaders_arraysize, lsaHeaders);
}

void OspfLinkStateAcknowledgementPacket::eraseLsaHeaders(size_t k)
{
    if (k >= lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = lsaHeaders_arraysize - 1;
    OspfLsaHeader *lsaHeaders2 = (newSize == 0) ? nullptr : new OspfLsaHeader[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    for (i = k; i < newSize; i++)
        lsaHeaders2[i] = this->lsaHeaders[i+1];
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
    lsaHeaders_arraysize = newSize;
}

class OspfLinkStateAcknowledgementPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_lsaHeaders,
    };
  public:
    OspfLinkStateAcknowledgementPacketDescriptor();
    virtual ~OspfLinkStateAcknowledgementPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OspfLinkStateAcknowledgementPacketDescriptor)

OspfLinkStateAcknowledgementPacketDescriptor::OspfLinkStateAcknowledgementPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ospf::OspfLinkStateAcknowledgementPacket)), "inet::ospf::OspfPacket")
{
    propertynames = nullptr;
}

OspfLinkStateAcknowledgementPacketDescriptor::~OspfLinkStateAcknowledgementPacketDescriptor()
{
    delete[] propertynames;
}

bool OspfLinkStateAcknowledgementPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OspfLinkStateAcknowledgementPacket *>(obj)!=nullptr;
}

const char **OspfLinkStateAcknowledgementPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OspfLinkStateAcknowledgementPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OspfLinkStateAcknowledgementPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int OspfLinkStateAcknowledgementPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_lsaHeaders
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *OspfLinkStateAcknowledgementPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsaHeaders",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int OspfLinkStateAcknowledgementPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lsaHeaders") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OspfLinkStateAcknowledgementPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ospf::OspfLsaHeader",    // FIELD_lsaHeaders
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **OspfLinkStateAcknowledgementPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OspfLinkStateAcknowledgementPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OspfLinkStateAcknowledgementPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateAcknowledgementPacket *pp = (OspfLinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        case FIELD_lsaHeaders: return pp->getLsaHeadersArraySize();
        default: return 0;
    }
}

const char *OspfLinkStateAcknowledgementPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateAcknowledgementPacket *pp = (OspfLinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OspfLinkStateAcknowledgementPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateAcknowledgementPacket *pp = (OspfLinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        case FIELD_lsaHeaders: {std::stringstream out; out << pp->getLsaHeaders(i); return out.str();}
        default: return "";
    }
}

bool OspfLinkStateAcknowledgementPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateAcknowledgementPacket *pp = (OspfLinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OspfLinkStateAcknowledgementPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_lsaHeaders: return omnetpp::opp_typename(typeid(OspfLsaHeader));
        default: return nullptr;
    };
}

void *OspfLinkStateAcknowledgementPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OspfLinkStateAcknowledgementPacket *pp = (OspfLinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        case FIELD_lsaHeaders: return toVoidPtr(&pp->getLsaHeaders(i)); break;
        default: return nullptr;
    }
}

} // namespace ospf
} // namespace inet

