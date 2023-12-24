//
// Generated file, do not edit! Created by nedtool 5.6 from inet/networklayer/ldp/LdpPacket.msg.
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
#include "LdpPacket_m.h"

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

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::LdpMessageTypes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::LdpMessageTypes"));
    e->insert(NOTIFICATION, "NOTIFICATION");
    e->insert(HELLO, "HELLO");
    e->insert(INITIALIZATION, "INITIALIZATION");
    e->insert(KEEP_ALIVE, "KEEP_ALIVE");
    e->insert(ADDRESS, "ADDRESS");
    e->insert(ADDRESS_WITHDRAW, "ADDRESS_WITHDRAW");
    e->insert(LABEL_MAPPING, "LABEL_MAPPING");
    e->insert(LABEL_REQUEST, "LABEL_REQUEST");
    e->insert(LABEL_WITHDRAW, "LABEL_WITHDRAW");
    e->insert(LABEL_RELEASE, "LABEL_RELEASE");
    e->insert(UNKNOWN, "UNKNOWN");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::LdpStatusTypes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::LdpStatusTypes"));
    e->insert(NO_ROUTE, "NO_ROUTE");
)

FecTlv::FecTlv()
{
    this->length = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const FecTlv& a)
{
    doParsimPacking(b,a.addr);
    doParsimPacking(b,a.length);
}

void __doUnpacking(omnetpp::cCommBuffer *b, FecTlv& a)
{
    doParsimUnpacking(b,a.addr);
    doParsimUnpacking(b,a.length);
}

class FecTlvDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_addr,
        FIELD_length,
    };
  public:
    FecTlvDescriptor();
    virtual ~FecTlvDescriptor();

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

Register_ClassDescriptor(FecTlvDescriptor)

FecTlvDescriptor::FecTlvDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::FecTlv)), "")
{
    propertynames = nullptr;
}

FecTlvDescriptor::~FecTlvDescriptor()
{
    delete[] propertynames;
}

bool FecTlvDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<FecTlv *>(obj)!=nullptr;
}

const char **FecTlvDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *FecTlvDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int FecTlvDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int FecTlvDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_addr
        FD_ISEDITABLE,    // FIELD_length
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *FecTlvDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "addr",
        "length",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int FecTlvDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "addr") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *FecTlvDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_addr
        "int",    // FIELD_length
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **FecTlvDescriptor::getFieldPropertyNames(int field) const
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

const char *FecTlvDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int FecTlvDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    FecTlv *pp = (FecTlv *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *FecTlvDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    FecTlv *pp = (FecTlv *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string FecTlvDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    FecTlv *pp = (FecTlv *)object; (void)pp;
    switch (field) {
        case FIELD_addr: return pp->addr.str();
        case FIELD_length: return long2string(pp->length);
        default: return "";
    }
}

bool FecTlvDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    FecTlv *pp = (FecTlv *)object; (void)pp;
    switch (field) {
        case FIELD_length: pp->length = string2long(value); return true;
        default: return false;
    }
}

const char *FecTlvDescriptor::getFieldStructName(int field) const
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

void *FecTlvDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    FecTlv *pp = (FecTlv *)object; (void)pp;
    switch (field) {
        case FIELD_addr: return toVoidPtr(&pp->addr); break;
        default: return nullptr;
    }
}

Register_Class(LdpPacket)

LdpPacket::LdpPacket() : ::inet::FieldsChunk()
{
}

LdpPacket::LdpPacket(const LdpPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

LdpPacket::~LdpPacket()
{
}

LdpPacket& LdpPacket::operator=(const LdpPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void LdpPacket::copy(const LdpPacket& other)
{
    this->type = other.type;
    this->senderAddress = other.senderAddress;
    this->receiverAddress = other.receiverAddress;
}

void LdpPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->senderAddress);
    doParsimPacking(b,this->receiverAddress);
}

void LdpPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->senderAddress);
    doParsimUnpacking(b,this->receiverAddress);
}

int LdpPacket::getType() const
{
    return this->type;
}

void LdpPacket::setType(int type)
{
    handleChange();
    this->type = type;
}

const Ipv4Address& LdpPacket::getSenderAddress() const
{
    return this->senderAddress;
}

void LdpPacket::setSenderAddress(const Ipv4Address& senderAddress)
{
    handleChange();
    this->senderAddress = senderAddress;
}

const Ipv4Address& LdpPacket::getReceiverAddress() const
{
    return this->receiverAddress;
}

void LdpPacket::setReceiverAddress(const Ipv4Address& receiverAddress)
{
    handleChange();
    this->receiverAddress = receiverAddress;
}

class LdpPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_senderAddress,
        FIELD_receiverAddress,
    };
  public:
    LdpPacketDescriptor();
    virtual ~LdpPacketDescriptor();

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

Register_ClassDescriptor(LdpPacketDescriptor)

LdpPacketDescriptor::LdpPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::LdpPacket)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

LdpPacketDescriptor::~LdpPacketDescriptor()
{
    delete[] propertynames;
}

bool LdpPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LdpPacket *>(obj)!=nullptr;
}

const char **LdpPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LdpPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LdpPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int LdpPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        0,    // FIELD_senderAddress
        0,    // FIELD_receiverAddress
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *LdpPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "senderAddress",
        "receiverAddress",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int LdpPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "senderAddress") == 0) return base+1;
    if (fieldName[0] == 'r' && strcmp(fieldName, "receiverAddress") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LdpPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_type
        "inet::Ipv4Address",    // FIELD_senderAddress
        "inet::Ipv4Address",    // FIELD_receiverAddress
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **LdpPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *LdpPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LdpPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LdpPacket *pp = (LdpPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LdpPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpPacket *pp = (LdpPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LdpPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpPacket *pp = (LdpPacket *)object; (void)pp;
    switch (field) {
        case FIELD_type: return long2string(pp->getType());
        case FIELD_senderAddress: return pp->getSenderAddress().str();
        case FIELD_receiverAddress: return pp->getReceiverAddress().str();
        default: return "";
    }
}

bool LdpPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LdpPacket *pp = (LdpPacket *)object; (void)pp;
    switch (field) {
        case FIELD_type: pp->setType(string2long(value)); return true;
        default: return false;
    }
}

const char *LdpPacketDescriptor::getFieldStructName(int field) const
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

void *LdpPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LdpPacket *pp = (LdpPacket *)object; (void)pp;
    switch (field) {
        case FIELD_senderAddress: return toVoidPtr(&pp->getSenderAddress()); break;
        case FIELD_receiverAddress: return toVoidPtr(&pp->getReceiverAddress()); break;
        default: return nullptr;
    }
}

Register_Class(LdpLabelMapping)

LdpLabelMapping::LdpLabelMapping() : ::inet::LdpPacket()
{
}

LdpLabelMapping::LdpLabelMapping(const LdpLabelMapping& other) : ::inet::LdpPacket(other)
{
    copy(other);
}

LdpLabelMapping::~LdpLabelMapping()
{
}

LdpLabelMapping& LdpLabelMapping::operator=(const LdpLabelMapping& other)
{
    if (this == &other) return *this;
    ::inet::LdpPacket::operator=(other);
    copy(other);
    return *this;
}

void LdpLabelMapping::copy(const LdpLabelMapping& other)
{
    this->fec = other.fec;
    this->label = other.label;
}

void LdpLabelMapping::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::LdpPacket::parsimPack(b);
    doParsimPacking(b,this->fec);
    doParsimPacking(b,this->label);
}

void LdpLabelMapping::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::LdpPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->fec);
    doParsimUnpacking(b,this->label);
}

const FecTlv& LdpLabelMapping::getFec() const
{
    return this->fec;
}

void LdpLabelMapping::setFec(const FecTlv& fec)
{
    handleChange();
    this->fec = fec;
}

int LdpLabelMapping::getLabel() const
{
    return this->label;
}

void LdpLabelMapping::setLabel(int label)
{
    handleChange();
    this->label = label;
}

class LdpLabelMappingDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_fec,
        FIELD_label,
    };
  public:
    LdpLabelMappingDescriptor();
    virtual ~LdpLabelMappingDescriptor();

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

Register_ClassDescriptor(LdpLabelMappingDescriptor)

LdpLabelMappingDescriptor::LdpLabelMappingDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::LdpLabelMapping)), "inet::LdpPacket")
{
    propertynames = nullptr;
}

LdpLabelMappingDescriptor::~LdpLabelMappingDescriptor()
{
    delete[] propertynames;
}

bool LdpLabelMappingDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LdpLabelMapping *>(obj)!=nullptr;
}

const char **LdpLabelMappingDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LdpLabelMappingDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LdpLabelMappingDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int LdpLabelMappingDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_fec
        FD_ISEDITABLE,    // FIELD_label
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *LdpLabelMappingDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fec",
        "label",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int LdpLabelMappingDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fec") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "label") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LdpLabelMappingDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::FecTlv",    // FIELD_fec
        "int",    // FIELD_label
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **LdpLabelMappingDescriptor::getFieldPropertyNames(int field) const
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

const char *LdpLabelMappingDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LdpLabelMappingDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LdpLabelMapping *pp = (LdpLabelMapping *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LdpLabelMappingDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpLabelMapping *pp = (LdpLabelMapping *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LdpLabelMappingDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpLabelMapping *pp = (LdpLabelMapping *)object; (void)pp;
    switch (field) {
        case FIELD_fec: {std::stringstream out; out << pp->getFec(); return out.str();}
        case FIELD_label: return long2string(pp->getLabel());
        default: return "";
    }
}

bool LdpLabelMappingDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LdpLabelMapping *pp = (LdpLabelMapping *)object; (void)pp;
    switch (field) {
        case FIELD_label: pp->setLabel(string2long(value)); return true;
        default: return false;
    }
}

const char *LdpLabelMappingDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_fec: return omnetpp::opp_typename(typeid(FecTlv));
        default: return nullptr;
    };
}

void *LdpLabelMappingDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LdpLabelMapping *pp = (LdpLabelMapping *)object; (void)pp;
    switch (field) {
        case FIELD_fec: return toVoidPtr(&pp->getFec()); break;
        default: return nullptr;
    }
}

Register_Class(LdpLabelRequest)

LdpLabelRequest::LdpLabelRequest() : ::inet::LdpPacket()
{
}

LdpLabelRequest::LdpLabelRequest(const LdpLabelRequest& other) : ::inet::LdpPacket(other)
{
    copy(other);
}

LdpLabelRequest::~LdpLabelRequest()
{
}

LdpLabelRequest& LdpLabelRequest::operator=(const LdpLabelRequest& other)
{
    if (this == &other) return *this;
    ::inet::LdpPacket::operator=(other);
    copy(other);
    return *this;
}

void LdpLabelRequest::copy(const LdpLabelRequest& other)
{
    this->fec = other.fec;
}

void LdpLabelRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::LdpPacket::parsimPack(b);
    doParsimPacking(b,this->fec);
}

void LdpLabelRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::LdpPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->fec);
}

const FecTlv& LdpLabelRequest::getFec() const
{
    return this->fec;
}

void LdpLabelRequest::setFec(const FecTlv& fec)
{
    handleChange();
    this->fec = fec;
}

class LdpLabelRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_fec,
    };
  public:
    LdpLabelRequestDescriptor();
    virtual ~LdpLabelRequestDescriptor();

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

Register_ClassDescriptor(LdpLabelRequestDescriptor)

LdpLabelRequestDescriptor::LdpLabelRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::LdpLabelRequest)), "inet::LdpPacket")
{
    propertynames = nullptr;
}

LdpLabelRequestDescriptor::~LdpLabelRequestDescriptor()
{
    delete[] propertynames;
}

bool LdpLabelRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LdpLabelRequest *>(obj)!=nullptr;
}

const char **LdpLabelRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LdpLabelRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LdpLabelRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int LdpLabelRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_fec
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *LdpLabelRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fec",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int LdpLabelRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fec") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LdpLabelRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::FecTlv",    // FIELD_fec
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **LdpLabelRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *LdpLabelRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LdpLabelRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LdpLabelRequest *pp = (LdpLabelRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LdpLabelRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpLabelRequest *pp = (LdpLabelRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LdpLabelRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpLabelRequest *pp = (LdpLabelRequest *)object; (void)pp;
    switch (field) {
        case FIELD_fec: {std::stringstream out; out << pp->getFec(); return out.str();}
        default: return "";
    }
}

bool LdpLabelRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LdpLabelRequest *pp = (LdpLabelRequest *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *LdpLabelRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_fec: return omnetpp::opp_typename(typeid(FecTlv));
        default: return nullptr;
    };
}

void *LdpLabelRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LdpLabelRequest *pp = (LdpLabelRequest *)object; (void)pp;
    switch (field) {
        case FIELD_fec: return toVoidPtr(&pp->getFec()); break;
        default: return nullptr;
    }
}

Register_Class(LdpHello)

LdpHello::LdpHello() : ::inet::LdpPacket()
{
}

LdpHello::LdpHello(const LdpHello& other) : ::inet::LdpPacket(other)
{
    copy(other);
}

LdpHello::~LdpHello()
{
}

LdpHello& LdpHello::operator=(const LdpHello& other)
{
    if (this == &other) return *this;
    ::inet::LdpPacket::operator=(other);
    copy(other);
    return *this;
}

void LdpHello::copy(const LdpHello& other)
{
    this->holdTime = other.holdTime;
    this->tbit = other.tbit;
    this->rbit = other.rbit;
}

void LdpHello::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::LdpPacket::parsimPack(b);
    doParsimPacking(b,this->holdTime);
    doParsimPacking(b,this->tbit);
    doParsimPacking(b,this->rbit);
}

void LdpHello::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::LdpPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->holdTime);
    doParsimUnpacking(b,this->tbit);
    doParsimUnpacking(b,this->rbit);
}

double LdpHello::getHoldTime() const
{
    return this->holdTime;
}

void LdpHello::setHoldTime(double holdTime)
{
    handleChange();
    this->holdTime = holdTime;
}

bool LdpHello::getTbit() const
{
    return this->tbit;
}

void LdpHello::setTbit(bool tbit)
{
    handleChange();
    this->tbit = tbit;
}

bool LdpHello::getRbit() const
{
    return this->rbit;
}

void LdpHello::setRbit(bool rbit)
{
    handleChange();
    this->rbit = rbit;
}

class LdpHelloDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_holdTime,
        FIELD_tbit,
        FIELD_rbit,
    };
  public:
    LdpHelloDescriptor();
    virtual ~LdpHelloDescriptor();

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

Register_ClassDescriptor(LdpHelloDescriptor)

LdpHelloDescriptor::LdpHelloDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::LdpHello)), "inet::LdpPacket")
{
    propertynames = nullptr;
}

LdpHelloDescriptor::~LdpHelloDescriptor()
{
    delete[] propertynames;
}

bool LdpHelloDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LdpHello *>(obj)!=nullptr;
}

const char **LdpHelloDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LdpHelloDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LdpHelloDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int LdpHelloDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_holdTime
        FD_ISEDITABLE,    // FIELD_tbit
        FD_ISEDITABLE,    // FIELD_rbit
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *LdpHelloDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "holdTime",
        "tbit",
        "rbit",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int LdpHelloDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "holdTime") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tbit") == 0) return base+1;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rbit") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LdpHelloDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_holdTime
        "bool",    // FIELD_tbit
        "bool",    // FIELD_rbit
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **LdpHelloDescriptor::getFieldPropertyNames(int field) const
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

const char *LdpHelloDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LdpHelloDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LdpHello *pp = (LdpHello *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LdpHelloDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpHello *pp = (LdpHello *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LdpHelloDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpHello *pp = (LdpHello *)object; (void)pp;
    switch (field) {
        case FIELD_holdTime: return double2string(pp->getHoldTime());
        case FIELD_tbit: return bool2string(pp->getTbit());
        case FIELD_rbit: return bool2string(pp->getRbit());
        default: return "";
    }
}

bool LdpHelloDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LdpHello *pp = (LdpHello *)object; (void)pp;
    switch (field) {
        case FIELD_holdTime: pp->setHoldTime(string2double(value)); return true;
        case FIELD_tbit: pp->setTbit(string2bool(value)); return true;
        case FIELD_rbit: pp->setRbit(string2bool(value)); return true;
        default: return false;
    }
}

const char *LdpHelloDescriptor::getFieldStructName(int field) const
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

void *LdpHelloDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LdpHello *pp = (LdpHello *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(LdpNotify)

LdpNotify::LdpNotify() : ::inet::LdpPacket()
{
}

LdpNotify::LdpNotify(const LdpNotify& other) : ::inet::LdpPacket(other)
{
    copy(other);
}

LdpNotify::~LdpNotify()
{
}

LdpNotify& LdpNotify::operator=(const LdpNotify& other)
{
    if (this == &other) return *this;
    ::inet::LdpPacket::operator=(other);
    copy(other);
    return *this;
}

void LdpNotify::copy(const LdpNotify& other)
{
    this->status = other.status;
    this->fec = other.fec;
}

void LdpNotify::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::LdpPacket::parsimPack(b);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->fec);
}

void LdpNotify::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::LdpPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->fec);
}

int LdpNotify::getStatus() const
{
    return this->status;
}

void LdpNotify::setStatus(int status)
{
    handleChange();
    this->status = status;
}

const FecTlv& LdpNotify::getFec() const
{
    return this->fec;
}

void LdpNotify::setFec(const FecTlv& fec)
{
    handleChange();
    this->fec = fec;
}

class LdpNotifyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_status,
        FIELD_fec,
    };
  public:
    LdpNotifyDescriptor();
    virtual ~LdpNotifyDescriptor();

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

Register_ClassDescriptor(LdpNotifyDescriptor)

LdpNotifyDescriptor::LdpNotifyDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::LdpNotify)), "inet::LdpPacket")
{
    propertynames = nullptr;
}

LdpNotifyDescriptor::~LdpNotifyDescriptor()
{
    delete[] propertynames;
}

bool LdpNotifyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LdpNotify *>(obj)!=nullptr;
}

const char **LdpNotifyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LdpNotifyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LdpNotifyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int LdpNotifyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_status
        FD_ISCOMPOUND,    // FIELD_fec
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *LdpNotifyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
        "fec",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int LdpNotifyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "status") == 0) return base+0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fec") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LdpNotifyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_status
        "inet::FecTlv",    // FIELD_fec
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **LdpNotifyDescriptor::getFieldPropertyNames(int field) const
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

const char *LdpNotifyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LdpNotifyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LdpNotify *pp = (LdpNotify *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LdpNotifyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpNotify *pp = (LdpNotify *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LdpNotifyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpNotify *pp = (LdpNotify *)object; (void)pp;
    switch (field) {
        case FIELD_status: return long2string(pp->getStatus());
        case FIELD_fec: {std::stringstream out; out << pp->getFec(); return out.str();}
        default: return "";
    }
}

bool LdpNotifyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LdpNotify *pp = (LdpNotify *)object; (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(string2long(value)); return true;
        default: return false;
    }
}

const char *LdpNotifyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_fec: return omnetpp::opp_typename(typeid(FecTlv));
        default: return nullptr;
    };
}

void *LdpNotifyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LdpNotify *pp = (LdpNotify *)object; (void)pp;
    switch (field) {
        case FIELD_fec: return toVoidPtr(&pp->getFec()); break;
        default: return nullptr;
    }
}

Register_Class(LdpIni)

LdpIni::LdpIni() : ::inet::LdpPacket()
{
}

LdpIni::LdpIni(const LdpIni& other) : ::inet::LdpPacket(other)
{
    copy(other);
}

LdpIni::~LdpIni()
{
}

LdpIni& LdpIni::operator=(const LdpIni& other)
{
    if (this == &other) return *this;
    ::inet::LdpPacket::operator=(other);
    copy(other);
    return *this;
}

void LdpIni::copy(const LdpIni& other)
{
    this->keepAliveTime = other.keepAliveTime;
    this->abit = other.abit;
    this->dbit = other.dbit;
    this->pvLim = other.pvLim;
    this->receiverLDPIdentifier = other.receiverLDPIdentifier;
}

void LdpIni::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::LdpPacket::parsimPack(b);
    doParsimPacking(b,this->keepAliveTime);
    doParsimPacking(b,this->abit);
    doParsimPacking(b,this->dbit);
    doParsimPacking(b,this->pvLim);
    doParsimPacking(b,this->receiverLDPIdentifier);
}

void LdpIni::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::LdpPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->keepAliveTime);
    doParsimUnpacking(b,this->abit);
    doParsimUnpacking(b,this->dbit);
    doParsimUnpacking(b,this->pvLim);
    doParsimUnpacking(b,this->receiverLDPIdentifier);
}

double LdpIni::getKeepAliveTime() const
{
    return this->keepAliveTime;
}

void LdpIni::setKeepAliveTime(double keepAliveTime)
{
    handleChange();
    this->keepAliveTime = keepAliveTime;
}

bool LdpIni::getAbit() const
{
    return this->abit;
}

void LdpIni::setAbit(bool abit)
{
    handleChange();
    this->abit = abit;
}

bool LdpIni::getDbit() const
{
    return this->dbit;
}

void LdpIni::setDbit(bool dbit)
{
    handleChange();
    this->dbit = dbit;
}

int LdpIni::getPvLim() const
{
    return this->pvLim;
}

void LdpIni::setPvLim(int pvLim)
{
    handleChange();
    this->pvLim = pvLim;
}

const char * LdpIni::getReceiverLDPIdentifier() const
{
    return this->receiverLDPIdentifier.c_str();
}

void LdpIni::setReceiverLDPIdentifier(const char * receiverLDPIdentifier)
{
    handleChange();
    this->receiverLDPIdentifier = receiverLDPIdentifier;
}

class LdpIniDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_keepAliveTime,
        FIELD_abit,
        FIELD_dbit,
        FIELD_pvLim,
        FIELD_receiverLDPIdentifier,
    };
  public:
    LdpIniDescriptor();
    virtual ~LdpIniDescriptor();

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

Register_ClassDescriptor(LdpIniDescriptor)

LdpIniDescriptor::LdpIniDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::LdpIni)), "inet::LdpPacket")
{
    propertynames = nullptr;
}

LdpIniDescriptor::~LdpIniDescriptor()
{
    delete[] propertynames;
}

bool LdpIniDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LdpIni *>(obj)!=nullptr;
}

const char **LdpIniDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LdpIniDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LdpIniDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int LdpIniDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_keepAliveTime
        FD_ISEDITABLE,    // FIELD_abit
        FD_ISEDITABLE,    // FIELD_dbit
        FD_ISEDITABLE,    // FIELD_pvLim
        FD_ISEDITABLE,    // FIELD_receiverLDPIdentifier
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *LdpIniDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "keepAliveTime",
        "abit",
        "dbit",
        "pvLim",
        "receiverLDPIdentifier",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int LdpIniDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'k' && strcmp(fieldName, "keepAliveTime") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "abit") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dbit") == 0) return base+2;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pvLim") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "receiverLDPIdentifier") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LdpIniDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_keepAliveTime
        "bool",    // FIELD_abit
        "bool",    // FIELD_dbit
        "int",    // FIELD_pvLim
        "string",    // FIELD_receiverLDPIdentifier
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **LdpIniDescriptor::getFieldPropertyNames(int field) const
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

const char *LdpIniDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LdpIniDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LdpIni *pp = (LdpIni *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LdpIniDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpIni *pp = (LdpIni *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LdpIniDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpIni *pp = (LdpIni *)object; (void)pp;
    switch (field) {
        case FIELD_keepAliveTime: return double2string(pp->getKeepAliveTime());
        case FIELD_abit: return bool2string(pp->getAbit());
        case FIELD_dbit: return bool2string(pp->getDbit());
        case FIELD_pvLim: return long2string(pp->getPvLim());
        case FIELD_receiverLDPIdentifier: return oppstring2string(pp->getReceiverLDPIdentifier());
        default: return "";
    }
}

bool LdpIniDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LdpIni *pp = (LdpIni *)object; (void)pp;
    switch (field) {
        case FIELD_keepAliveTime: pp->setKeepAliveTime(string2double(value)); return true;
        case FIELD_abit: pp->setAbit(string2bool(value)); return true;
        case FIELD_dbit: pp->setDbit(string2bool(value)); return true;
        case FIELD_pvLim: pp->setPvLim(string2long(value)); return true;
        case FIELD_receiverLDPIdentifier: pp->setReceiverLDPIdentifier((value)); return true;
        default: return false;
    }
}

const char *LdpIniDescriptor::getFieldStructName(int field) const
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

void *LdpIniDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LdpIni *pp = (LdpIni *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(LdpAddress)

LdpAddress::LdpAddress() : ::inet::LdpPacket()
{
}

LdpAddress::LdpAddress(const LdpAddress& other) : ::inet::LdpPacket(other)
{
    copy(other);
}

LdpAddress::~LdpAddress()
{
    delete [] this->addresses;
}

LdpAddress& LdpAddress::operator=(const LdpAddress& other)
{
    if (this == &other) return *this;
    ::inet::LdpPacket::operator=(other);
    copy(other);
    return *this;
}

void LdpAddress::copy(const LdpAddress& other)
{
    this->isWithdraw_ = other.isWithdraw_;
    this->family = other.family;
    delete [] this->addresses;
    this->addresses = (other.addresses_arraysize==0) ? nullptr : new omnetpp::opp_string[other.addresses_arraysize];
    addresses_arraysize = other.addresses_arraysize;
    for (size_t i = 0; i < addresses_arraysize; i++) {
        this->addresses[i] = other.addresses[i];
    }
}

void LdpAddress::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::LdpPacket::parsimPack(b);
    doParsimPacking(b,this->isWithdraw_);
    doParsimPacking(b,this->family);
    b->pack(addresses_arraysize);
    doParsimArrayPacking(b,this->addresses,addresses_arraysize);
}

void LdpAddress::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::LdpPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->isWithdraw_);
    doParsimUnpacking(b,this->family);
    delete [] this->addresses;
    b->unpack(addresses_arraysize);
    if (addresses_arraysize == 0) {
        this->addresses = nullptr;
    } else {
        this->addresses = new omnetpp::opp_string[addresses_arraysize];
        doParsimArrayUnpacking(b,this->addresses,addresses_arraysize);
    }
}

bool LdpAddress::isWithdraw() const
{
    return this->isWithdraw_;
}

void LdpAddress::setIsWithdraw(bool isWithdraw)
{
    handleChange();
    this->isWithdraw_ = isWithdraw;
}

const char * LdpAddress::getFamily() const
{
    return this->family.c_str();
}

void LdpAddress::setFamily(const char * family)
{
    handleChange();
    this->family = family;
}

size_t LdpAddress::getAddressesArraySize() const
{
    return addresses_arraysize;
}

const char * LdpAddress::getAddresses(size_t k) const
{
    if (k >= addresses_arraysize) throw omnetpp::cRuntimeError("Array of size addresses_arraysize indexed by %lu", (unsigned long)k);
    return this->addresses[k].c_str();
}

void LdpAddress::setAddressesArraySize(size_t newSize)
{
    handleChange();
    omnetpp::opp_string *addresses2 = (newSize==0) ? nullptr : new omnetpp::opp_string[newSize];
    size_t minSize = addresses_arraysize < newSize ? addresses_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        addresses2[i] = this->addresses[i];
    delete [] this->addresses;
    this->addresses = addresses2;
    addresses_arraysize = newSize;
}

void LdpAddress::setAddresses(size_t k, const char * addresses)
{
    if (k >= addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->addresses[k] = addresses;
}

void LdpAddress::insertAddresses(size_t k, const char * addresses)
{
    handleChange();
    if (k > addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = addresses_arraysize + 1;
    omnetpp::opp_string *addresses2 = new omnetpp::opp_string[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        addresses2[i] = this->addresses[i];
    addresses2[k] = addresses;
    for (i = k + 1; i < newSize; i++)
        addresses2[i] = this->addresses[i-1];
    delete [] this->addresses;
    this->addresses = addresses2;
    addresses_arraysize = newSize;
}

void LdpAddress::insertAddresses(const char * addresses)
{
    insertAddresses(addresses_arraysize, addresses);
}

void LdpAddress::eraseAddresses(size_t k)
{
    if (k >= addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = addresses_arraysize - 1;
    omnetpp::opp_string *addresses2 = (newSize == 0) ? nullptr : new omnetpp::opp_string[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        addresses2[i] = this->addresses[i];
    for (i = k; i < newSize; i++)
        addresses2[i] = this->addresses[i+1];
    delete [] this->addresses;
    this->addresses = addresses2;
    addresses_arraysize = newSize;
}

class LdpAddressDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_isWithdraw,
        FIELD_family,
        FIELD_addresses,
    };
  public:
    LdpAddressDescriptor();
    virtual ~LdpAddressDescriptor();

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

Register_ClassDescriptor(LdpAddressDescriptor)

LdpAddressDescriptor::LdpAddressDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::LdpAddress)), "inet::LdpPacket")
{
    propertynames = nullptr;
}

LdpAddressDescriptor::~LdpAddressDescriptor()
{
    delete[] propertynames;
}

bool LdpAddressDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LdpAddress *>(obj)!=nullptr;
}

const char **LdpAddressDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LdpAddressDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LdpAddressDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int LdpAddressDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_isWithdraw
        FD_ISEDITABLE,    // FIELD_family
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_addresses
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *LdpAddressDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "isWithdraw",
        "family",
        "addresses",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int LdpAddressDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "isWithdraw") == 0) return base+0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "family") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "addresses") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LdpAddressDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_isWithdraw
        "string",    // FIELD_family
        "string",    // FIELD_addresses
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **LdpAddressDescriptor::getFieldPropertyNames(int field) const
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

const char *LdpAddressDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LdpAddressDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LdpAddress *pp = (LdpAddress *)object; (void)pp;
    switch (field) {
        case FIELD_addresses: return pp->getAddressesArraySize();
        default: return 0;
    }
}

const char *LdpAddressDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpAddress *pp = (LdpAddress *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LdpAddressDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LdpAddress *pp = (LdpAddress *)object; (void)pp;
    switch (field) {
        case FIELD_isWithdraw: return bool2string(pp->isWithdraw());
        case FIELD_family: return oppstring2string(pp->getFamily());
        case FIELD_addresses: return oppstring2string(pp->getAddresses(i));
        default: return "";
    }
}

bool LdpAddressDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LdpAddress *pp = (LdpAddress *)object; (void)pp;
    switch (field) {
        case FIELD_isWithdraw: pp->setIsWithdraw(string2bool(value)); return true;
        case FIELD_family: pp->setFamily((value)); return true;
        case FIELD_addresses: pp->setAddresses(i,(value)); return true;
        default: return false;
    }
}

const char *LdpAddressDescriptor::getFieldStructName(int field) const
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

void *LdpAddressDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LdpAddress *pp = (LdpAddress *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

