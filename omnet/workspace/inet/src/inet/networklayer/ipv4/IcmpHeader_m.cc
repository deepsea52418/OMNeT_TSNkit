//
// Generated file, do not edit! Created by nedtool 5.6 from inet/networklayer/ipv4/IcmpHeader.msg.
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
#include "IcmpHeader_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::IcmpType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::IcmpType"));
    e->insert(ICMP_DESTINATION_UNREACHABLE, "ICMP_DESTINATION_UNREACHABLE");
    e->insert(ICMP_SOURCEQUENCH, "ICMP_SOURCEQUENCH");
    e->insert(ICMP_REDIRECT, "ICMP_REDIRECT");
    e->insert(ICMP_ECHO_REQUEST, "ICMP_ECHO_REQUEST");
    e->insert(ICMP_ROUTER_ADVERTISEMENT, "ICMP_ROUTER_ADVERTISEMENT");
    e->insert(ICMP_ROUTER_SOLICITATION, "ICMP_ROUTER_SOLICITATION");
    e->insert(ICMP_TIME_EXCEEDED, "ICMP_TIME_EXCEEDED");
    e->insert(ICMP_PARAMETER_PROBLEM, "ICMP_PARAMETER_PROBLEM");
    e->insert(ICMP_ECHO_REPLY, "ICMP_ECHO_REPLY");
    e->insert(ICMP_TIMESTAMP_REQUEST, "ICMP_TIMESTAMP_REQUEST");
    e->insert(ICMP_TIMESTAMP_REPLY, "ICMP_TIMESTAMP_REPLY");
    e->insert(ICMP_INFORMATION_REQUEST, "ICMP_INFORMATION_REQUEST");
    e->insert(ICMP_INFORMATION_REPLY, "ICMP_INFORMATION_REPLY");
    e->insert(ICMP_MASK_REQUEST, "ICMP_MASK_REQUEST");
    e->insert(ICMP_MASK_REPLY, "ICMP_MASK_REPLY");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::IcmpRedirectSubcodes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::IcmpRedirectSubcodes"));
    e->insert(ICMP_REDIRECT_NET, "ICMP_REDIRECT_NET");
    e->insert(ICMP_REDIRECT_HOST, "ICMP_REDIRECT_HOST");
    e->insert(ICMP_REDIRECT_TOSNET, "ICMP_REDIRECT_TOSNET");
    e->insert(ICMP_REDIRECT_TOSHOST, "ICMP_REDIRECT_TOSHOST");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::IcmpTimeExceededSubcodes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::IcmpTimeExceededSubcodes"));
    e->insert(ICMP_TIMXCEED_INTRANS, "ICMP_TIMXCEED_INTRANS");
    e->insert(ICMP_TIMXCEED_REASS, "ICMP_TIMXCEED_REASS");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::IcmpParameterProblemSubcodes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::IcmpParameterProblemSubcodes"));
    e->insert(ICMP_PARAMPROB_ERRATPTR, "ICMP_PARAMPROB_ERRATPTR");
    e->insert(ICMP_PARAMPROB_OPTABSENT, "ICMP_PARAMPROB_OPTABSENT");
    e->insert(ICMP_PARAMPROB_LENGTH, "ICMP_PARAMPROB_LENGTH");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::IcmpDestinationUnreachableCodes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::IcmpDestinationUnreachableCodes"));
    e->insert(ICMP_DU_NETWORK_UNREACHABLE, "ICMP_DU_NETWORK_UNREACHABLE");
    e->insert(ICMP_DU_HOST_UNREACHABLE, "ICMP_DU_HOST_UNREACHABLE");
    e->insert(ICMP_DU_PROTOCOL_UNREACHABLE, "ICMP_DU_PROTOCOL_UNREACHABLE");
    e->insert(ICMP_DU_PORT_UNREACHABLE, "ICMP_DU_PORT_UNREACHABLE");
    e->insert(ICMP_DU_FRAGMENTATION_NEEDED, "ICMP_DU_FRAGMENTATION_NEEDED");
    e->insert(ICMP_DU_SOURCE_ROUTE_FAILED, "ICMP_DU_SOURCE_ROUTE_FAILED");
    e->insert(ICMP_DU_DESTINATION_NETWORK_UNKNOWN, "ICMP_DU_DESTINATION_NETWORK_UNKNOWN");
    e->insert(ICMP_DU_DESTINATION_HOST_UNKNOWN, "ICMP_DU_DESTINATION_HOST_UNKNOWN");
    e->insert(ICMP_DU_SOURCE_HOST_ISOLATED, "ICMP_DU_SOURCE_HOST_ISOLATED");
    e->insert(ICMP_DU_NETWORK_PROHIBITED, "ICMP_DU_NETWORK_PROHIBITED");
    e->insert(ICMP_DU_HOST_PROHIBITED, "ICMP_DU_HOST_PROHIBITED");
    e->insert(ICMP_DU_NETWORK_UNREACHABLE_FOR_TYPE_OF_SERVICE, "ICMP_DU_NETWORK_UNREACHABLE_FOR_TYPE_OF_SERVICE");
    e->insert(ICMP_DU_HOST_UNREACHABLE_FOR_TYPE_OF_SERVICE, "ICMP_DU_HOST_UNREACHABLE_FOR_TYPE_OF_SERVICE");
    e->insert(ICMP_DU_COMMUNICATION_PROHIBITED, "ICMP_DU_COMMUNICATION_PROHIBITED");
    e->insert(ICMP_DU_HOST_PRECEDENCE_VIOLATION, "ICMP_DU_HOST_PRECEDENCE_VIOLATION");
    e->insert(ICMP_DU_PRECEDENCE_CUTOFF_IN_EFFECT, "ICMP_DU_PRECEDENCE_CUTOFF_IN_EFFECT");
    e->insert(ICMP_AODV_QUEUE_FULL, "ICMP_AODV_QUEUE_FULL");
)

Register_Class(IcmpHeader)

IcmpHeader::IcmpHeader() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(8));

}

IcmpHeader::IcmpHeader(const IcmpHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

IcmpHeader::~IcmpHeader()
{
}

IcmpHeader& IcmpHeader::operator=(const IcmpHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void IcmpHeader::copy(const IcmpHeader& other)
{
    this->type = other.type;
    this->code = other.code;
    this->chksum = other.chksum;
    this->crcMode = other.crcMode;
}

void IcmpHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->code);
    doParsimPacking(b,this->chksum);
    doParsimPacking(b,this->crcMode);
}

void IcmpHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->code);
    doParsimUnpacking(b,this->chksum);
    doParsimUnpacking(b,this->crcMode);
}

inet::IcmpType IcmpHeader::getType() const
{
    return this->type;
}

void IcmpHeader::setType(inet::IcmpType type)
{
    handleChange();
    this->type = type;
}

int IcmpHeader::getCode() const
{
    return this->code;
}

void IcmpHeader::setCode(int code)
{
    handleChange();
    this->code = code;
}

int IcmpHeader::getChksum() const
{
    return this->chksum;
}

void IcmpHeader::setChksum(int chksum)
{
    handleChange();
    this->chksum = chksum;
}

inet::CrcMode IcmpHeader::getCrcMode() const
{
    return this->crcMode;
}

void IcmpHeader::setCrcMode(inet::CrcMode crcMode)
{
    handleChange();
    this->crcMode = crcMode;
}

class IcmpHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_code,
        FIELD_chksum,
        FIELD_crcMode,
    };
  public:
    IcmpHeaderDescriptor();
    virtual ~IcmpHeaderDescriptor();

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

Register_ClassDescriptor(IcmpHeaderDescriptor)

IcmpHeaderDescriptor::IcmpHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::IcmpHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

IcmpHeaderDescriptor::~IcmpHeaderDescriptor()
{
    delete[] propertynames;
}

bool IcmpHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IcmpHeader *>(obj)!=nullptr;
}

const char **IcmpHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IcmpHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IcmpHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int IcmpHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_code
        FD_ISEDITABLE,    // FIELD_chksum
        0,    // FIELD_crcMode
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *IcmpHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "code",
        "chksum",
        "crcMode",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int IcmpHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "code") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "chksum") == 0) return base+2;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crcMode") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IcmpHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::IcmpType",    // FIELD_type
        "int",    // FIELD_code
        "int",    // FIELD_chksum
        "inet::CrcMode",    // FIELD_crcMode
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **IcmpHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *IcmpHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::IcmpType";
            return nullptr;
        case FIELD_crcMode:
            if (!strcmp(propertyname, "enum")) return "inet::CrcMode";
            return nullptr;
        default: return nullptr;
    }
}

int IcmpHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IcmpHeader *pp = (IcmpHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IcmpHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IcmpHeader *pp = (IcmpHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IcmpHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IcmpHeader *pp = (IcmpHeader *)object; (void)pp;
    switch (field) {
        case FIELD_type: return enum2string(pp->getType(), "inet::IcmpType");
        case FIELD_code: return long2string(pp->getCode());
        case FIELD_chksum: return long2string(pp->getChksum());
        case FIELD_crcMode: return enum2string(pp->getCrcMode(), "inet::CrcMode");
        default: return "";
    }
}

bool IcmpHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IcmpHeader *pp = (IcmpHeader *)object; (void)pp;
    switch (field) {
        case FIELD_type: pp->setType((inet::IcmpType)string2enum(value, "inet::IcmpType")); return true;
        case FIELD_code: pp->setCode(string2long(value)); return true;
        case FIELD_chksum: pp->setChksum(string2long(value)); return true;
        default: return false;
    }
}

const char *IcmpHeaderDescriptor::getFieldStructName(int field) const
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

void *IcmpHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IcmpHeader *pp = (IcmpHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(IcmpEchoRequest)

IcmpEchoRequest::IcmpEchoRequest() : ::inet::IcmpHeader()
{
    this->setType(ICMP_ECHO_REQUEST);
    this->setCode(0);

}

IcmpEchoRequest::IcmpEchoRequest(const IcmpEchoRequest& other) : ::inet::IcmpHeader(other)
{
    copy(other);
}

IcmpEchoRequest::~IcmpEchoRequest()
{
}

IcmpEchoRequest& IcmpEchoRequest::operator=(const IcmpEchoRequest& other)
{
    if (this == &other) return *this;
    ::inet::IcmpHeader::operator=(other);
    copy(other);
    return *this;
}

void IcmpEchoRequest::copy(const IcmpEchoRequest& other)
{
    this->identifier = other.identifier;
    this->seqNumber = other.seqNumber;
}

void IcmpEchoRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IcmpHeader::parsimPack(b);
    doParsimPacking(b,this->identifier);
    doParsimPacking(b,this->seqNumber);
}

void IcmpEchoRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IcmpHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->identifier);
    doParsimUnpacking(b,this->seqNumber);
}

int IcmpEchoRequest::getIdentifier() const
{
    return this->identifier;
}

void IcmpEchoRequest::setIdentifier(int identifier)
{
    handleChange();
    this->identifier = identifier;
}

int IcmpEchoRequest::getSeqNumber() const
{
    return this->seqNumber;
}

void IcmpEchoRequest::setSeqNumber(int seqNumber)
{
    handleChange();
    this->seqNumber = seqNumber;
}

class IcmpEchoRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_identifier,
        FIELD_seqNumber,
    };
  public:
    IcmpEchoRequestDescriptor();
    virtual ~IcmpEchoRequestDescriptor();

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

Register_ClassDescriptor(IcmpEchoRequestDescriptor)

IcmpEchoRequestDescriptor::IcmpEchoRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::IcmpEchoRequest)), "inet::IcmpHeader")
{
    propertynames = nullptr;
}

IcmpEchoRequestDescriptor::~IcmpEchoRequestDescriptor()
{
    delete[] propertynames;
}

bool IcmpEchoRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IcmpEchoRequest *>(obj)!=nullptr;
}

const char **IcmpEchoRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IcmpEchoRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IcmpEchoRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int IcmpEchoRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_identifier
        FD_ISEDITABLE,    // FIELD_seqNumber
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *IcmpEchoRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "identifier",
        "seqNumber",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int IcmpEchoRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "identifier") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "seqNumber") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IcmpEchoRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_identifier
        "int",    // FIELD_seqNumber
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **IcmpEchoRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *IcmpEchoRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IcmpEchoRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IcmpEchoRequest *pp = (IcmpEchoRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IcmpEchoRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IcmpEchoRequest *pp = (IcmpEchoRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IcmpEchoRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IcmpEchoRequest *pp = (IcmpEchoRequest *)object; (void)pp;
    switch (field) {
        case FIELD_identifier: return long2string(pp->getIdentifier());
        case FIELD_seqNumber: return long2string(pp->getSeqNumber());
        default: return "";
    }
}

bool IcmpEchoRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IcmpEchoRequest *pp = (IcmpEchoRequest *)object; (void)pp;
    switch (field) {
        case FIELD_identifier: pp->setIdentifier(string2long(value)); return true;
        case FIELD_seqNumber: pp->setSeqNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *IcmpEchoRequestDescriptor::getFieldStructName(int field) const
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

void *IcmpEchoRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IcmpEchoRequest *pp = (IcmpEchoRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(IcmpEchoReply)

IcmpEchoReply::IcmpEchoReply() : ::inet::IcmpHeader()
{
    this->setType(ICMP_ECHO_REPLY);
    this->setCode(0);

}

IcmpEchoReply::IcmpEchoReply(const IcmpEchoReply& other) : ::inet::IcmpHeader(other)
{
    copy(other);
}

IcmpEchoReply::~IcmpEchoReply()
{
}

IcmpEchoReply& IcmpEchoReply::operator=(const IcmpEchoReply& other)
{
    if (this == &other) return *this;
    ::inet::IcmpHeader::operator=(other);
    copy(other);
    return *this;
}

void IcmpEchoReply::copy(const IcmpEchoReply& other)
{
    this->identifier = other.identifier;
    this->seqNumber = other.seqNumber;
}

void IcmpEchoReply::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IcmpHeader::parsimPack(b);
    doParsimPacking(b,this->identifier);
    doParsimPacking(b,this->seqNumber);
}

void IcmpEchoReply::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IcmpHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->identifier);
    doParsimUnpacking(b,this->seqNumber);
}

int IcmpEchoReply::getIdentifier() const
{
    return this->identifier;
}

void IcmpEchoReply::setIdentifier(int identifier)
{
    handleChange();
    this->identifier = identifier;
}

int IcmpEchoReply::getSeqNumber() const
{
    return this->seqNumber;
}

void IcmpEchoReply::setSeqNumber(int seqNumber)
{
    handleChange();
    this->seqNumber = seqNumber;
}

class IcmpEchoReplyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_identifier,
        FIELD_seqNumber,
    };
  public:
    IcmpEchoReplyDescriptor();
    virtual ~IcmpEchoReplyDescriptor();

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

Register_ClassDescriptor(IcmpEchoReplyDescriptor)

IcmpEchoReplyDescriptor::IcmpEchoReplyDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::IcmpEchoReply)), "inet::IcmpHeader")
{
    propertynames = nullptr;
}

IcmpEchoReplyDescriptor::~IcmpEchoReplyDescriptor()
{
    delete[] propertynames;
}

bool IcmpEchoReplyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IcmpEchoReply *>(obj)!=nullptr;
}

const char **IcmpEchoReplyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IcmpEchoReplyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IcmpEchoReplyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int IcmpEchoReplyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_identifier
        FD_ISEDITABLE,    // FIELD_seqNumber
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *IcmpEchoReplyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "identifier",
        "seqNumber",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int IcmpEchoReplyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "identifier") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "seqNumber") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IcmpEchoReplyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_identifier
        "int",    // FIELD_seqNumber
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **IcmpEchoReplyDescriptor::getFieldPropertyNames(int field) const
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

const char *IcmpEchoReplyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IcmpEchoReplyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IcmpEchoReply *pp = (IcmpEchoReply *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IcmpEchoReplyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IcmpEchoReply *pp = (IcmpEchoReply *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IcmpEchoReplyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IcmpEchoReply *pp = (IcmpEchoReply *)object; (void)pp;
    switch (field) {
        case FIELD_identifier: return long2string(pp->getIdentifier());
        case FIELD_seqNumber: return long2string(pp->getSeqNumber());
        default: return "";
    }
}

bool IcmpEchoReplyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IcmpEchoReply *pp = (IcmpEchoReply *)object; (void)pp;
    switch (field) {
        case FIELD_identifier: pp->setIdentifier(string2long(value)); return true;
        case FIELD_seqNumber: pp->setSeqNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *IcmpEchoReplyDescriptor::getFieldStructName(int field) const
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

void *IcmpEchoReplyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IcmpEchoReply *pp = (IcmpEchoReply *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

