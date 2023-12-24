//
// Generated file, do not edit! Created by nedtool 5.6 from inet/linklayer/ieee8021d/common/Ieee8021dBpdu.msg.
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
#include "Ieee8021dBpdu_m.h"

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

Register_Class(Bpdu)

Bpdu::Bpdu() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(35));

}

Bpdu::Bpdu(const Bpdu& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Bpdu::~Bpdu()
{
}

Bpdu& Bpdu::operator=(const Bpdu& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Bpdu::copy(const Bpdu& other)
{
    this->protocolIdentifier = other.protocolIdentifier;
    this->protocolVersionIdentifier = other.protocolVersionIdentifier;
    this->bpduType = other.bpduType;
    this->tcaFlag = other.tcaFlag;
    this->tcFlag = other.tcFlag;
    this->rootAddress = other.rootAddress;
    this->rootPriority = other.rootPriority;
    this->rootPathCost = other.rootPathCost;
    this->bridgeAddress = other.bridgeAddress;
    this->bridgePriority = other.bridgePriority;
    this->portNum = other.portNum;
    this->portPriority = other.portPriority;
    this->messageAge = other.messageAge;
    this->maxAge = other.maxAge;
    this->helloTime = other.helloTime;
    this->forwardDelay = other.forwardDelay;
}

void Bpdu::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->protocolIdentifier);
    doParsimPacking(b,this->protocolVersionIdentifier);
    doParsimPacking(b,this->bpduType);
    doParsimPacking(b,this->tcaFlag);
    doParsimPacking(b,this->tcFlag);
    doParsimPacking(b,this->rootAddress);
    doParsimPacking(b,this->rootPriority);
    doParsimPacking(b,this->rootPathCost);
    doParsimPacking(b,this->bridgeAddress);
    doParsimPacking(b,this->bridgePriority);
    doParsimPacking(b,this->portNum);
    doParsimPacking(b,this->portPriority);
    doParsimPacking(b,this->messageAge);
    doParsimPacking(b,this->maxAge);
    doParsimPacking(b,this->helloTime);
    doParsimPacking(b,this->forwardDelay);
}

void Bpdu::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->protocolIdentifier);
    doParsimUnpacking(b,this->protocolVersionIdentifier);
    doParsimUnpacking(b,this->bpduType);
    doParsimUnpacking(b,this->tcaFlag);
    doParsimUnpacking(b,this->tcFlag);
    doParsimUnpacking(b,this->rootAddress);
    doParsimUnpacking(b,this->rootPriority);
    doParsimUnpacking(b,this->rootPathCost);
    doParsimUnpacking(b,this->bridgeAddress);
    doParsimUnpacking(b,this->bridgePriority);
    doParsimUnpacking(b,this->portNum);
    doParsimUnpacking(b,this->portPriority);
    doParsimUnpacking(b,this->messageAge);
    doParsimUnpacking(b,this->maxAge);
    doParsimUnpacking(b,this->helloTime);
    doParsimUnpacking(b,this->forwardDelay);
}

unsigned int Bpdu::getProtocolIdentifier() const
{
    return this->protocolIdentifier;
}

void Bpdu::setProtocolIdentifier(unsigned int protocolIdentifier)
{
    handleChange();
    this->protocolIdentifier = protocolIdentifier;
}

unsigned int Bpdu::getProtocolVersionIdentifier() const
{
    return this->protocolVersionIdentifier;
}

void Bpdu::setProtocolVersionIdentifier(unsigned int protocolVersionIdentifier)
{
    handleChange();
    this->protocolVersionIdentifier = protocolVersionIdentifier;
}

unsigned int Bpdu::getBpduType() const
{
    return this->bpduType;
}

void Bpdu::setBpduType(unsigned int bpduType)
{
    handleChange();
    this->bpduType = bpduType;
}

bool Bpdu::getTcaFlag() const
{
    return this->tcaFlag;
}

void Bpdu::setTcaFlag(bool tcaFlag)
{
    handleChange();
    this->tcaFlag = tcaFlag;
}

bool Bpdu::getTcFlag() const
{
    return this->tcFlag;
}

void Bpdu::setTcFlag(bool tcFlag)
{
    handleChange();
    this->tcFlag = tcFlag;
}

const MacAddress& Bpdu::getRootAddress() const
{
    return this->rootAddress;
}

void Bpdu::setRootAddress(const MacAddress& rootAddress)
{
    handleChange();
    this->rootAddress = rootAddress;
}

unsigned int Bpdu::getRootPriority() const
{
    return this->rootPriority;
}

void Bpdu::setRootPriority(unsigned int rootPriority)
{
    handleChange();
    this->rootPriority = rootPriority;
}

unsigned int Bpdu::getRootPathCost() const
{
    return this->rootPathCost;
}

void Bpdu::setRootPathCost(unsigned int rootPathCost)
{
    handleChange();
    this->rootPathCost = rootPathCost;
}

const MacAddress& Bpdu::getBridgeAddress() const
{
    return this->bridgeAddress;
}

void Bpdu::setBridgeAddress(const MacAddress& bridgeAddress)
{
    handleChange();
    this->bridgeAddress = bridgeAddress;
}

unsigned int Bpdu::getBridgePriority() const
{
    return this->bridgePriority;
}

void Bpdu::setBridgePriority(unsigned int bridgePriority)
{
    handleChange();
    this->bridgePriority = bridgePriority;
}

unsigned int Bpdu::getPortNum() const
{
    return this->portNum;
}

void Bpdu::setPortNum(unsigned int portNum)
{
    handleChange();
    this->portNum = portNum;
}

unsigned int Bpdu::getPortPriority() const
{
    return this->portPriority;
}

void Bpdu::setPortPriority(unsigned int portPriority)
{
    handleChange();
    this->portPriority = portPriority;
}

omnetpp::simtime_t Bpdu::getMessageAge() const
{
    return this->messageAge;
}

void Bpdu::setMessageAge(omnetpp::simtime_t messageAge)
{
    handleChange();
    this->messageAge = messageAge;
}

omnetpp::simtime_t Bpdu::getMaxAge() const
{
    return this->maxAge;
}

void Bpdu::setMaxAge(omnetpp::simtime_t maxAge)
{
    handleChange();
    this->maxAge = maxAge;
}

omnetpp::simtime_t Bpdu::getHelloTime() const
{
    return this->helloTime;
}

void Bpdu::setHelloTime(omnetpp::simtime_t helloTime)
{
    handleChange();
    this->helloTime = helloTime;
}

omnetpp::simtime_t Bpdu::getForwardDelay() const
{
    return this->forwardDelay;
}

void Bpdu::setForwardDelay(omnetpp::simtime_t forwardDelay)
{
    handleChange();
    this->forwardDelay = forwardDelay;
}

class BpduDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_protocolIdentifier,
        FIELD_protocolVersionIdentifier,
        FIELD_bpduType,
        FIELD_tcaFlag,
        FIELD_tcFlag,
        FIELD_rootAddress,
        FIELD_rootPriority,
        FIELD_rootPathCost,
        FIELD_bridgeAddress,
        FIELD_bridgePriority,
        FIELD_portNum,
        FIELD_portPriority,
        FIELD_messageAge,
        FIELD_maxAge,
        FIELD_helloTime,
        FIELD_forwardDelay,
    };
  public:
    BpduDescriptor();
    virtual ~BpduDescriptor();

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

Register_ClassDescriptor(BpduDescriptor)

BpduDescriptor::BpduDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Bpdu)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

BpduDescriptor::~BpduDescriptor()
{
    delete[] propertynames;
}

bool BpduDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Bpdu *>(obj)!=nullptr;
}

const char **BpduDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BpduDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BpduDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 16+basedesc->getFieldCount() : 16;
}

unsigned int BpduDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_protocolIdentifier
        FD_ISEDITABLE,    // FIELD_protocolVersionIdentifier
        FD_ISEDITABLE,    // FIELD_bpduType
        FD_ISEDITABLE,    // FIELD_tcaFlag
        FD_ISEDITABLE,    // FIELD_tcFlag
        0,    // FIELD_rootAddress
        FD_ISEDITABLE,    // FIELD_rootPriority
        FD_ISEDITABLE,    // FIELD_rootPathCost
        0,    // FIELD_bridgeAddress
        FD_ISEDITABLE,    // FIELD_bridgePriority
        FD_ISEDITABLE,    // FIELD_portNum
        FD_ISEDITABLE,    // FIELD_portPriority
        0,    // FIELD_messageAge
        0,    // FIELD_maxAge
        0,    // FIELD_helloTime
        0,    // FIELD_forwardDelay
    };
    return (field >= 0 && field < 16) ? fieldTypeFlags[field] : 0;
}

const char *BpduDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "protocolIdentifier",
        "protocolVersionIdentifier",
        "bpduType",
        "tcaFlag",
        "tcFlag",
        "rootAddress",
        "rootPriority",
        "rootPathCost",
        "bridgeAddress",
        "bridgePriority",
        "portNum",
        "portPriority",
        "messageAge",
        "maxAge",
        "helloTime",
        "forwardDelay",
    };
    return (field >= 0 && field < 16) ? fieldNames[field] : nullptr;
}

int BpduDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "protocolIdentifier") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "protocolVersionIdentifier") == 0) return base+1;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bpduType") == 0) return base+2;
    if (fieldName[0] == 't' && strcmp(fieldName, "tcaFlag") == 0) return base+3;
    if (fieldName[0] == 't' && strcmp(fieldName, "tcFlag") == 0) return base+4;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rootAddress") == 0) return base+5;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rootPriority") == 0) return base+6;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rootPathCost") == 0) return base+7;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bridgeAddress") == 0) return base+8;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bridgePriority") == 0) return base+9;
    if (fieldName[0] == 'p' && strcmp(fieldName, "portNum") == 0) return base+10;
    if (fieldName[0] == 'p' && strcmp(fieldName, "portPriority") == 0) return base+11;
    if (fieldName[0] == 'm' && strcmp(fieldName, "messageAge") == 0) return base+12;
    if (fieldName[0] == 'm' && strcmp(fieldName, "maxAge") == 0) return base+13;
    if (fieldName[0] == 'h' && strcmp(fieldName, "helloTime") == 0) return base+14;
    if (fieldName[0] == 'f' && strcmp(fieldName, "forwardDelay") == 0) return base+15;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BpduDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_protocolIdentifier
        "unsigned int",    // FIELD_protocolVersionIdentifier
        "unsigned int",    // FIELD_bpduType
        "bool",    // FIELD_tcaFlag
        "bool",    // FIELD_tcFlag
        "inet::MacAddress",    // FIELD_rootAddress
        "unsigned int",    // FIELD_rootPriority
        "unsigned int",    // FIELD_rootPathCost
        "inet::MacAddress",    // FIELD_bridgeAddress
        "unsigned int",    // FIELD_bridgePriority
        "unsigned int",    // FIELD_portNum
        "unsigned int",    // FIELD_portPriority
        "omnetpp::simtime_t",    // FIELD_messageAge
        "omnetpp::simtime_t",    // FIELD_maxAge
        "omnetpp::simtime_t",    // FIELD_helloTime
        "omnetpp::simtime_t",    // FIELD_forwardDelay
    };
    return (field >= 0 && field < 16) ? fieldTypeStrings[field] : nullptr;
}

const char **BpduDescriptor::getFieldPropertyNames(int field) const
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

const char *BpduDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BpduDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Bpdu *pp = (Bpdu *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BpduDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Bpdu *pp = (Bpdu *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BpduDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Bpdu *pp = (Bpdu *)object; (void)pp;
    switch (field) {
        case FIELD_protocolIdentifier: return ulong2string(pp->getProtocolIdentifier());
        case FIELD_protocolVersionIdentifier: return ulong2string(pp->getProtocolVersionIdentifier());
        case FIELD_bpduType: return ulong2string(pp->getBpduType());
        case FIELD_tcaFlag: return bool2string(pp->getTcaFlag());
        case FIELD_tcFlag: return bool2string(pp->getTcFlag());
        case FIELD_rootAddress: return pp->getRootAddress().str();
        case FIELD_rootPriority: return ulong2string(pp->getRootPriority());
        case FIELD_rootPathCost: return ulong2string(pp->getRootPathCost());
        case FIELD_bridgeAddress: return pp->getBridgeAddress().str();
        case FIELD_bridgePriority: return ulong2string(pp->getBridgePriority());
        case FIELD_portNum: return ulong2string(pp->getPortNum());
        case FIELD_portPriority: return ulong2string(pp->getPortPriority());
        case FIELD_messageAge: return simtime2string(pp->getMessageAge());
        case FIELD_maxAge: return simtime2string(pp->getMaxAge());
        case FIELD_helloTime: return simtime2string(pp->getHelloTime());
        case FIELD_forwardDelay: return simtime2string(pp->getForwardDelay());
        default: return "";
    }
}

bool BpduDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Bpdu *pp = (Bpdu *)object; (void)pp;
    switch (field) {
        case FIELD_protocolIdentifier: pp->setProtocolIdentifier(string2ulong(value)); return true;
        case FIELD_protocolVersionIdentifier: pp->setProtocolVersionIdentifier(string2ulong(value)); return true;
        case FIELD_bpduType: pp->setBpduType(string2ulong(value)); return true;
        case FIELD_tcaFlag: pp->setTcaFlag(string2bool(value)); return true;
        case FIELD_tcFlag: pp->setTcFlag(string2bool(value)); return true;
        case FIELD_rootPriority: pp->setRootPriority(string2ulong(value)); return true;
        case FIELD_rootPathCost: pp->setRootPathCost(string2ulong(value)); return true;
        case FIELD_bridgePriority: pp->setBridgePriority(string2ulong(value)); return true;
        case FIELD_portNum: pp->setPortNum(string2ulong(value)); return true;
        case FIELD_portPriority: pp->setPortPriority(string2ulong(value)); return true;
        default: return false;
    }
}

const char *BpduDescriptor::getFieldStructName(int field) const
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

void *BpduDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Bpdu *pp = (Bpdu *)object; (void)pp;
    switch (field) {
        case FIELD_rootAddress: return toVoidPtr(&pp->getRootAddress()); break;
        case FIELD_bridgeAddress: return toVoidPtr(&pp->getBridgeAddress()); break;
        default: return nullptr;
    }
}

} // namespace inet

