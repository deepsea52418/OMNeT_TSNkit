//
// Generated file, do not edit! Created by nedtool 5.6 from inet/networklayer/icmpv6/Icmpv6Header.msg.
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
#include "Icmpv6Header_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Icmpv6Type");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Icmpv6Type"));
    e->insert(ICMPv6_UNSPECIFIED, "ICMPv6_UNSPECIFIED");
    e->insert(ICMPv6_DESTINATION_UNREACHABLE, "ICMPv6_DESTINATION_UNREACHABLE");
    e->insert(ICMPv6_PACKET_TOO_BIG, "ICMPv6_PACKET_TOO_BIG");
    e->insert(ICMPv6_TIME_EXCEEDED, "ICMPv6_TIME_EXCEEDED");
    e->insert(ICMPv6_PARAMETER_PROBLEM, "ICMPv6_PARAMETER_PROBLEM");
    e->insert(ICMPv6_ECHO_REQUEST, "ICMPv6_ECHO_REQUEST");
    e->insert(ICMPv6_ECHO_REPLY, "ICMPv6_ECHO_REPLY");
    e->insert(ICMPv6_MLD_QUERY, "ICMPv6_MLD_QUERY");
    e->insert(ICMPv6_MLD_REPORT, "ICMPv6_MLD_REPORT");
    e->insert(ICMPv6_MLD_DONE, "ICMPv6_MLD_DONE");
    e->insert(ICMPv6_ROUTER_SOL, "ICMPv6_ROUTER_SOL");
    e->insert(ICMPv6_ROUTER_AD, "ICMPv6_ROUTER_AD");
    e->insert(ICMPv6_NEIGHBOUR_SOL, "ICMPv6_NEIGHBOUR_SOL");
    e->insert(ICMPv6_NEIGHBOUR_AD, "ICMPv6_NEIGHBOUR_AD");
    e->insert(ICMPv6_REDIRECT, "ICMPv6_REDIRECT");
    e->insert(ICMPv6_MLDv2_REPORT, "ICMPv6_MLDv2_REPORT");
    e->insert(ICMPv6_EXPERIMENTAL_MOBILITY, "ICMPv6_EXPERIMENTAL_MOBILITY");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Icmpv6DestUnav");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Icmpv6DestUnav"));
    e->insert(NO_ROUTE_TO_DEST, "NO_ROUTE_TO_DEST");
    e->insert(COMM_WITH_DEST_PROHIBITED, "COMM_WITH_DEST_PROHIBITED");
    e->insert(ADDRESS_UNREACHABLE, "ADDRESS_UNREACHABLE");
    e->insert(PORT_UNREACHABLE, "PORT_UNREACHABLE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Icmpv6TimeEx");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Icmpv6TimeEx"));
    e->insert(ND_HOP_LIMIT_EXCEEDED, "ND_HOP_LIMIT_EXCEEDED");
    e->insert(ND_FRAGMENT_REASSEMBLY_TIME, "ND_FRAGMENT_REASSEMBLY_TIME");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Icmpv6ParameterProblem");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Icmpv6ParameterProblem"));
    e->insert(ERROREOUS_HDR_FIELD, "ERROREOUS_HDR_FIELD");
    e->insert(UNRECOGNIZED_NEXT_HDR_TYPE, "UNRECOGNIZED_NEXT_HDR_TYPE");
    e->insert(UNRECOGNIZED_IPV6_OPTION, "UNRECOGNIZED_IPV6_OPTION");
)

Register_Class(Icmpv6Header)

Icmpv6Header::Icmpv6Header() : ::inet::FieldsChunk()
{
    this->setChunkLength(ICMPv6_HEADER_BYTES);

}

Icmpv6Header::Icmpv6Header(const Icmpv6Header& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Icmpv6Header::~Icmpv6Header()
{
}

Icmpv6Header& Icmpv6Header::operator=(const Icmpv6Header& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Icmpv6Header::copy(const Icmpv6Header& other)
{
    this->type = other.type;
    this->chksum = other.chksum;
    this->crcMode = other.crcMode;
}

void Icmpv6Header::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->chksum);
    doParsimPacking(b,this->crcMode);
}

void Icmpv6Header::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->chksum);
    doParsimUnpacking(b,this->crcMode);
}

inet::Icmpv6Type Icmpv6Header::getType() const
{
    return this->type;
}

void Icmpv6Header::setType(inet::Icmpv6Type type)
{
    handleChange();
    this->type = type;
}

int Icmpv6Header::getChksum() const
{
    return this->chksum;
}

void Icmpv6Header::setChksum(int chksum)
{
    handleChange();
    this->chksum = chksum;
}

inet::CrcMode Icmpv6Header::getCrcMode() const
{
    return this->crcMode;
}

void Icmpv6Header::setCrcMode(inet::CrcMode crcMode)
{
    handleChange();
    this->crcMode = crcMode;
}

class Icmpv6HeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_chksum,
        FIELD_crcMode,
    };
  public:
    Icmpv6HeaderDescriptor();
    virtual ~Icmpv6HeaderDescriptor();

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

Register_ClassDescriptor(Icmpv6HeaderDescriptor)

Icmpv6HeaderDescriptor::Icmpv6HeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Icmpv6Header)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Icmpv6HeaderDescriptor::~Icmpv6HeaderDescriptor()
{
    delete[] propertynames;
}

bool Icmpv6HeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Icmpv6Header *>(obj)!=nullptr;
}

const char **Icmpv6HeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Icmpv6HeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Icmpv6HeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Icmpv6HeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_chksum
        0,    // FIELD_crcMode
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Icmpv6HeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "chksum",
        "crcMode",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Icmpv6HeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "chksum") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crcMode") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Icmpv6HeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Icmpv6Type",    // FIELD_type
        "int",    // FIELD_chksum
        "inet::CrcMode",    // FIELD_crcMode
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Icmpv6HeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Icmpv6HeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::Icmpv6Type";
            return nullptr;
        case FIELD_crcMode:
            if (!strcmp(propertyname, "enum")) return "inet::CrcMode";
            return nullptr;
        default: return nullptr;
    }
}

int Icmpv6HeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Icmpv6Header *pp = (Icmpv6Header *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Icmpv6HeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6Header *pp = (Icmpv6Header *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Icmpv6HeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6Header *pp = (Icmpv6Header *)object; (void)pp;
    switch (field) {
        case FIELD_type: return enum2string(pp->getType(), "inet::Icmpv6Type");
        case FIELD_chksum: return long2string(pp->getChksum());
        case FIELD_crcMode: return enum2string(pp->getCrcMode(), "inet::CrcMode");
        default: return "";
    }
}

bool Icmpv6HeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Icmpv6Header *pp = (Icmpv6Header *)object; (void)pp;
    switch (field) {
        case FIELD_chksum: pp->setChksum(string2long(value)); return true;
        default: return false;
    }
}

const char *Icmpv6HeaderDescriptor::getFieldStructName(int field) const
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

void *Icmpv6HeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6Header *pp = (Icmpv6Header *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Icmpv6DestUnreachableMsg)

Icmpv6DestUnreachableMsg::Icmpv6DestUnreachableMsg() : ::inet::Icmpv6Header()
{
    this->setType(ICMPv6_DESTINATION_UNREACHABLE);

}

Icmpv6DestUnreachableMsg::Icmpv6DestUnreachableMsg(const Icmpv6DestUnreachableMsg& other) : ::inet::Icmpv6Header(other)
{
    copy(other);
}

Icmpv6DestUnreachableMsg::~Icmpv6DestUnreachableMsg()
{
}

Icmpv6DestUnreachableMsg& Icmpv6DestUnreachableMsg::operator=(const Icmpv6DestUnreachableMsg& other)
{
    if (this == &other) return *this;
    ::inet::Icmpv6Header::operator=(other);
    copy(other);
    return *this;
}

void Icmpv6DestUnreachableMsg::copy(const Icmpv6DestUnreachableMsg& other)
{
    this->code = other.code;
}

void Icmpv6DestUnreachableMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Icmpv6Header::parsimPack(b);
    doParsimPacking(b,this->code);
}

void Icmpv6DestUnreachableMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Icmpv6Header::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
}

inet::Icmpv6DestUnav Icmpv6DestUnreachableMsg::getCode() const
{
    return this->code;
}

void Icmpv6DestUnreachableMsg::setCode(inet::Icmpv6DestUnav code)
{
    handleChange();
    this->code = code;
}

class Icmpv6DestUnreachableMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_code,
    };
  public:
    Icmpv6DestUnreachableMsgDescriptor();
    virtual ~Icmpv6DestUnreachableMsgDescriptor();

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

Register_ClassDescriptor(Icmpv6DestUnreachableMsgDescriptor)

Icmpv6DestUnreachableMsgDescriptor::Icmpv6DestUnreachableMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Icmpv6DestUnreachableMsg)), "inet::Icmpv6Header")
{
    propertynames = nullptr;
}

Icmpv6DestUnreachableMsgDescriptor::~Icmpv6DestUnreachableMsgDescriptor()
{
    delete[] propertynames;
}

bool Icmpv6DestUnreachableMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Icmpv6DestUnreachableMsg *>(obj)!=nullptr;
}

const char **Icmpv6DestUnreachableMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Icmpv6DestUnreachableMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Icmpv6DestUnreachableMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Icmpv6DestUnreachableMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_code
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Icmpv6DestUnreachableMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Icmpv6DestUnreachableMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "code") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Icmpv6DestUnreachableMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Icmpv6DestUnav",    // FIELD_code
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Icmpv6DestUnreachableMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_code: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Icmpv6DestUnreachableMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_code:
            if (!strcmp(propertyname, "enum")) return "inet::Icmpv6DestUnav";
            return nullptr;
        default: return nullptr;
    }
}

int Icmpv6DestUnreachableMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Icmpv6DestUnreachableMsg *pp = (Icmpv6DestUnreachableMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Icmpv6DestUnreachableMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6DestUnreachableMsg *pp = (Icmpv6DestUnreachableMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Icmpv6DestUnreachableMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6DestUnreachableMsg *pp = (Icmpv6DestUnreachableMsg *)object; (void)pp;
    switch (field) {
        case FIELD_code: return enum2string(pp->getCode(), "inet::Icmpv6DestUnav");
        default: return "";
    }
}

bool Icmpv6DestUnreachableMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Icmpv6DestUnreachableMsg *pp = (Icmpv6DestUnreachableMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Icmpv6DestUnreachableMsgDescriptor::getFieldStructName(int field) const
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

void *Icmpv6DestUnreachableMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6DestUnreachableMsg *pp = (Icmpv6DestUnreachableMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Icmpv6PacketTooBigMsg)

Icmpv6PacketTooBigMsg::Icmpv6PacketTooBigMsg() : ::inet::Icmpv6Header()
{
    this->setType(ICMPv6_PACKET_TOO_BIG);

}

Icmpv6PacketTooBigMsg::Icmpv6PacketTooBigMsg(const Icmpv6PacketTooBigMsg& other) : ::inet::Icmpv6Header(other)
{
    copy(other);
}

Icmpv6PacketTooBigMsg::~Icmpv6PacketTooBigMsg()
{
}

Icmpv6PacketTooBigMsg& Icmpv6PacketTooBigMsg::operator=(const Icmpv6PacketTooBigMsg& other)
{
    if (this == &other) return *this;
    ::inet::Icmpv6Header::operator=(other);
    copy(other);
    return *this;
}

void Icmpv6PacketTooBigMsg::copy(const Icmpv6PacketTooBigMsg& other)
{
    this->code = other.code;
    this->MTU = other.MTU;
}

void Icmpv6PacketTooBigMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Icmpv6Header::parsimPack(b);
    doParsimPacking(b,this->code);
    doParsimPacking(b,this->MTU);
}

void Icmpv6PacketTooBigMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Icmpv6Header::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
    doParsimUnpacking(b,this->MTU);
}

int Icmpv6PacketTooBigMsg::getCode() const
{
    return this->code;
}

void Icmpv6PacketTooBigMsg::setCode(int code)
{
    handleChange();
    this->code = code;
}

int Icmpv6PacketTooBigMsg::getMTU() const
{
    return this->MTU;
}

void Icmpv6PacketTooBigMsg::setMTU(int MTU)
{
    handleChange();
    this->MTU = MTU;
}

class Icmpv6PacketTooBigMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_code,
        FIELD_MTU,
    };
  public:
    Icmpv6PacketTooBigMsgDescriptor();
    virtual ~Icmpv6PacketTooBigMsgDescriptor();

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

Register_ClassDescriptor(Icmpv6PacketTooBigMsgDescriptor)

Icmpv6PacketTooBigMsgDescriptor::Icmpv6PacketTooBigMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Icmpv6PacketTooBigMsg)), "inet::Icmpv6Header")
{
    propertynames = nullptr;
}

Icmpv6PacketTooBigMsgDescriptor::~Icmpv6PacketTooBigMsgDescriptor()
{
    delete[] propertynames;
}

bool Icmpv6PacketTooBigMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Icmpv6PacketTooBigMsg *>(obj)!=nullptr;
}

const char **Icmpv6PacketTooBigMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Icmpv6PacketTooBigMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Icmpv6PacketTooBigMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Icmpv6PacketTooBigMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_code
        FD_ISEDITABLE,    // FIELD_MTU
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Icmpv6PacketTooBigMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
        "MTU",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Icmpv6PacketTooBigMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "code") == 0) return base+0;
    if (fieldName[0] == 'M' && strcmp(fieldName, "MTU") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Icmpv6PacketTooBigMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_code
        "int",    // FIELD_MTU
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Icmpv6PacketTooBigMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *Icmpv6PacketTooBigMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Icmpv6PacketTooBigMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Icmpv6PacketTooBigMsg *pp = (Icmpv6PacketTooBigMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Icmpv6PacketTooBigMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6PacketTooBigMsg *pp = (Icmpv6PacketTooBigMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Icmpv6PacketTooBigMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6PacketTooBigMsg *pp = (Icmpv6PacketTooBigMsg *)object; (void)pp;
    switch (field) {
        case FIELD_code: return long2string(pp->getCode());
        case FIELD_MTU: return long2string(pp->getMTU());
        default: return "";
    }
}

bool Icmpv6PacketTooBigMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Icmpv6PacketTooBigMsg *pp = (Icmpv6PacketTooBigMsg *)object; (void)pp;
    switch (field) {
        case FIELD_code: pp->setCode(string2long(value)); return true;
        case FIELD_MTU: pp->setMTU(string2long(value)); return true;
        default: return false;
    }
}

const char *Icmpv6PacketTooBigMsgDescriptor::getFieldStructName(int field) const
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

void *Icmpv6PacketTooBigMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6PacketTooBigMsg *pp = (Icmpv6PacketTooBigMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Icmpv6TimeExceededMsg)

Icmpv6TimeExceededMsg::Icmpv6TimeExceededMsg() : ::inet::Icmpv6Header()
{
    this->setType(ICMPv6_TIME_EXCEEDED);

}

Icmpv6TimeExceededMsg::Icmpv6TimeExceededMsg(const Icmpv6TimeExceededMsg& other) : ::inet::Icmpv6Header(other)
{
    copy(other);
}

Icmpv6TimeExceededMsg::~Icmpv6TimeExceededMsg()
{
}

Icmpv6TimeExceededMsg& Icmpv6TimeExceededMsg::operator=(const Icmpv6TimeExceededMsg& other)
{
    if (this == &other) return *this;
    ::inet::Icmpv6Header::operator=(other);
    copy(other);
    return *this;
}

void Icmpv6TimeExceededMsg::copy(const Icmpv6TimeExceededMsg& other)
{
    this->code = other.code;
}

void Icmpv6TimeExceededMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Icmpv6Header::parsimPack(b);
    doParsimPacking(b,this->code);
}

void Icmpv6TimeExceededMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Icmpv6Header::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
}

inet::Icmpv6TimeEx Icmpv6TimeExceededMsg::getCode() const
{
    return this->code;
}

void Icmpv6TimeExceededMsg::setCode(inet::Icmpv6TimeEx code)
{
    handleChange();
    this->code = code;
}

class Icmpv6TimeExceededMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_code,
    };
  public:
    Icmpv6TimeExceededMsgDescriptor();
    virtual ~Icmpv6TimeExceededMsgDescriptor();

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

Register_ClassDescriptor(Icmpv6TimeExceededMsgDescriptor)

Icmpv6TimeExceededMsgDescriptor::Icmpv6TimeExceededMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Icmpv6TimeExceededMsg)), "inet::Icmpv6Header")
{
    propertynames = nullptr;
}

Icmpv6TimeExceededMsgDescriptor::~Icmpv6TimeExceededMsgDescriptor()
{
    delete[] propertynames;
}

bool Icmpv6TimeExceededMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Icmpv6TimeExceededMsg *>(obj)!=nullptr;
}

const char **Icmpv6TimeExceededMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Icmpv6TimeExceededMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Icmpv6TimeExceededMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Icmpv6TimeExceededMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_code
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Icmpv6TimeExceededMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Icmpv6TimeExceededMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "code") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Icmpv6TimeExceededMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Icmpv6TimeEx",    // FIELD_code
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Icmpv6TimeExceededMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_code: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Icmpv6TimeExceededMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_code:
            if (!strcmp(propertyname, "enum")) return "inet::Icmpv6TimeEx";
            return nullptr;
        default: return nullptr;
    }
}

int Icmpv6TimeExceededMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Icmpv6TimeExceededMsg *pp = (Icmpv6TimeExceededMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Icmpv6TimeExceededMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6TimeExceededMsg *pp = (Icmpv6TimeExceededMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Icmpv6TimeExceededMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6TimeExceededMsg *pp = (Icmpv6TimeExceededMsg *)object; (void)pp;
    switch (field) {
        case FIELD_code: return enum2string(pp->getCode(), "inet::Icmpv6TimeEx");
        default: return "";
    }
}

bool Icmpv6TimeExceededMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Icmpv6TimeExceededMsg *pp = (Icmpv6TimeExceededMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Icmpv6TimeExceededMsgDescriptor::getFieldStructName(int field) const
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

void *Icmpv6TimeExceededMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6TimeExceededMsg *pp = (Icmpv6TimeExceededMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Icmpv6ParamProblemMsg)

Icmpv6ParamProblemMsg::Icmpv6ParamProblemMsg() : ::inet::Icmpv6Header()
{
    this->setType(ICMPv6_PARAMETER_PROBLEM);

}

Icmpv6ParamProblemMsg::Icmpv6ParamProblemMsg(const Icmpv6ParamProblemMsg& other) : ::inet::Icmpv6Header(other)
{
    copy(other);
}

Icmpv6ParamProblemMsg::~Icmpv6ParamProblemMsg()
{
}

Icmpv6ParamProblemMsg& Icmpv6ParamProblemMsg::operator=(const Icmpv6ParamProblemMsg& other)
{
    if (this == &other) return *this;
    ::inet::Icmpv6Header::operator=(other);
    copy(other);
    return *this;
}

void Icmpv6ParamProblemMsg::copy(const Icmpv6ParamProblemMsg& other)
{
    this->code = other.code;
}

void Icmpv6ParamProblemMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Icmpv6Header::parsimPack(b);
    doParsimPacking(b,this->code);
}

void Icmpv6ParamProblemMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Icmpv6Header::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
}

inet::Icmpv6ParameterProblem Icmpv6ParamProblemMsg::getCode() const
{
    return this->code;
}

void Icmpv6ParamProblemMsg::setCode(inet::Icmpv6ParameterProblem code)
{
    handleChange();
    this->code = code;
}

class Icmpv6ParamProblemMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_code,
    };
  public:
    Icmpv6ParamProblemMsgDescriptor();
    virtual ~Icmpv6ParamProblemMsgDescriptor();

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

Register_ClassDescriptor(Icmpv6ParamProblemMsgDescriptor)

Icmpv6ParamProblemMsgDescriptor::Icmpv6ParamProblemMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Icmpv6ParamProblemMsg)), "inet::Icmpv6Header")
{
    propertynames = nullptr;
}

Icmpv6ParamProblemMsgDescriptor::~Icmpv6ParamProblemMsgDescriptor()
{
    delete[] propertynames;
}

bool Icmpv6ParamProblemMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Icmpv6ParamProblemMsg *>(obj)!=nullptr;
}

const char **Icmpv6ParamProblemMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Icmpv6ParamProblemMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Icmpv6ParamProblemMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Icmpv6ParamProblemMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_code
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Icmpv6ParamProblemMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Icmpv6ParamProblemMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "code") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Icmpv6ParamProblemMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Icmpv6ParameterProblem",    // FIELD_code
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Icmpv6ParamProblemMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_code: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Icmpv6ParamProblemMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_code:
            if (!strcmp(propertyname, "enum")) return "inet::Icmpv6ParameterProblem";
            return nullptr;
        default: return nullptr;
    }
}

int Icmpv6ParamProblemMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Icmpv6ParamProblemMsg *pp = (Icmpv6ParamProblemMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Icmpv6ParamProblemMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6ParamProblemMsg *pp = (Icmpv6ParamProblemMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Icmpv6ParamProblemMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6ParamProblemMsg *pp = (Icmpv6ParamProblemMsg *)object; (void)pp;
    switch (field) {
        case FIELD_code: return enum2string(pp->getCode(), "inet::Icmpv6ParameterProblem");
        default: return "";
    }
}

bool Icmpv6ParamProblemMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Icmpv6ParamProblemMsg *pp = (Icmpv6ParamProblemMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Icmpv6ParamProblemMsgDescriptor::getFieldStructName(int field) const
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

void *Icmpv6ParamProblemMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6ParamProblemMsg *pp = (Icmpv6ParamProblemMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Icmpv6EchoRequestMsg)

Icmpv6EchoRequestMsg::Icmpv6EchoRequestMsg() : ::inet::Icmpv6Header()
{
    this->setType(ICMPv6_ECHO_REQUEST);

}

Icmpv6EchoRequestMsg::Icmpv6EchoRequestMsg(const Icmpv6EchoRequestMsg& other) : ::inet::Icmpv6Header(other)
{
    copy(other);
}

Icmpv6EchoRequestMsg::~Icmpv6EchoRequestMsg()
{
}

Icmpv6EchoRequestMsg& Icmpv6EchoRequestMsg::operator=(const Icmpv6EchoRequestMsg& other)
{
    if (this == &other) return *this;
    ::inet::Icmpv6Header::operator=(other);
    copy(other);
    return *this;
}

void Icmpv6EchoRequestMsg::copy(const Icmpv6EchoRequestMsg& other)
{
    this->code = other.code;
    this->identifier = other.identifier;
    this->seqNumber = other.seqNumber;
}

void Icmpv6EchoRequestMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Icmpv6Header::parsimPack(b);
    doParsimPacking(b,this->code);
    doParsimPacking(b,this->identifier);
    doParsimPacking(b,this->seqNumber);
}

void Icmpv6EchoRequestMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Icmpv6Header::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
    doParsimUnpacking(b,this->identifier);
    doParsimUnpacking(b,this->seqNumber);
}

int Icmpv6EchoRequestMsg::getCode() const
{
    return this->code;
}

void Icmpv6EchoRequestMsg::setCode(int code)
{
    handleChange();
    this->code = code;
}

int Icmpv6EchoRequestMsg::getIdentifier() const
{
    return this->identifier;
}

void Icmpv6EchoRequestMsg::setIdentifier(int identifier)
{
    handleChange();
    this->identifier = identifier;
}

int Icmpv6EchoRequestMsg::getSeqNumber() const
{
    return this->seqNumber;
}

void Icmpv6EchoRequestMsg::setSeqNumber(int seqNumber)
{
    handleChange();
    this->seqNumber = seqNumber;
}

class Icmpv6EchoRequestMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_code,
        FIELD_identifier,
        FIELD_seqNumber,
    };
  public:
    Icmpv6EchoRequestMsgDescriptor();
    virtual ~Icmpv6EchoRequestMsgDescriptor();

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

Register_ClassDescriptor(Icmpv6EchoRequestMsgDescriptor)

Icmpv6EchoRequestMsgDescriptor::Icmpv6EchoRequestMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Icmpv6EchoRequestMsg)), "inet::Icmpv6Header")
{
    propertynames = nullptr;
}

Icmpv6EchoRequestMsgDescriptor::~Icmpv6EchoRequestMsgDescriptor()
{
    delete[] propertynames;
}

bool Icmpv6EchoRequestMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Icmpv6EchoRequestMsg *>(obj)!=nullptr;
}

const char **Icmpv6EchoRequestMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Icmpv6EchoRequestMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Icmpv6EchoRequestMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Icmpv6EchoRequestMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_code
        FD_ISEDITABLE,    // FIELD_identifier
        FD_ISEDITABLE,    // FIELD_seqNumber
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Icmpv6EchoRequestMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
        "identifier",
        "seqNumber",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Icmpv6EchoRequestMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "code") == 0) return base+0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "identifier") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "seqNumber") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Icmpv6EchoRequestMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_code
        "int",    // FIELD_identifier
        "int",    // FIELD_seqNumber
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Icmpv6EchoRequestMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *Icmpv6EchoRequestMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Icmpv6EchoRequestMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Icmpv6EchoRequestMsg *pp = (Icmpv6EchoRequestMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Icmpv6EchoRequestMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6EchoRequestMsg *pp = (Icmpv6EchoRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Icmpv6EchoRequestMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6EchoRequestMsg *pp = (Icmpv6EchoRequestMsg *)object; (void)pp;
    switch (field) {
        case FIELD_code: return long2string(pp->getCode());
        case FIELD_identifier: return long2string(pp->getIdentifier());
        case FIELD_seqNumber: return long2string(pp->getSeqNumber());
        default: return "";
    }
}

bool Icmpv6EchoRequestMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Icmpv6EchoRequestMsg *pp = (Icmpv6EchoRequestMsg *)object; (void)pp;
    switch (field) {
        case FIELD_code: pp->setCode(string2long(value)); return true;
        case FIELD_identifier: pp->setIdentifier(string2long(value)); return true;
        case FIELD_seqNumber: pp->setSeqNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Icmpv6EchoRequestMsgDescriptor::getFieldStructName(int field) const
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

void *Icmpv6EchoRequestMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6EchoRequestMsg *pp = (Icmpv6EchoRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Icmpv6EchoReplyMsg)

Icmpv6EchoReplyMsg::Icmpv6EchoReplyMsg() : ::inet::Icmpv6Header()
{
    this->setType(ICMPv6_ECHO_REPLY);

}

Icmpv6EchoReplyMsg::Icmpv6EchoReplyMsg(const Icmpv6EchoReplyMsg& other) : ::inet::Icmpv6Header(other)
{
    copy(other);
}

Icmpv6EchoReplyMsg::~Icmpv6EchoReplyMsg()
{
}

Icmpv6EchoReplyMsg& Icmpv6EchoReplyMsg::operator=(const Icmpv6EchoReplyMsg& other)
{
    if (this == &other) return *this;
    ::inet::Icmpv6Header::operator=(other);
    copy(other);
    return *this;
}

void Icmpv6EchoReplyMsg::copy(const Icmpv6EchoReplyMsg& other)
{
    this->code = other.code;
    this->identifier = other.identifier;
    this->seqNumber = other.seqNumber;
}

void Icmpv6EchoReplyMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Icmpv6Header::parsimPack(b);
    doParsimPacking(b,this->code);
    doParsimPacking(b,this->identifier);
    doParsimPacking(b,this->seqNumber);
}

void Icmpv6EchoReplyMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Icmpv6Header::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
    doParsimUnpacking(b,this->identifier);
    doParsimUnpacking(b,this->seqNumber);
}

int Icmpv6EchoReplyMsg::getCode() const
{
    return this->code;
}

void Icmpv6EchoReplyMsg::setCode(int code)
{
    handleChange();
    this->code = code;
}

int Icmpv6EchoReplyMsg::getIdentifier() const
{
    return this->identifier;
}

void Icmpv6EchoReplyMsg::setIdentifier(int identifier)
{
    handleChange();
    this->identifier = identifier;
}

int Icmpv6EchoReplyMsg::getSeqNumber() const
{
    return this->seqNumber;
}

void Icmpv6EchoReplyMsg::setSeqNumber(int seqNumber)
{
    handleChange();
    this->seqNumber = seqNumber;
}

class Icmpv6EchoReplyMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_code,
        FIELD_identifier,
        FIELD_seqNumber,
    };
  public:
    Icmpv6EchoReplyMsgDescriptor();
    virtual ~Icmpv6EchoReplyMsgDescriptor();

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

Register_ClassDescriptor(Icmpv6EchoReplyMsgDescriptor)

Icmpv6EchoReplyMsgDescriptor::Icmpv6EchoReplyMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Icmpv6EchoReplyMsg)), "inet::Icmpv6Header")
{
    propertynames = nullptr;
}

Icmpv6EchoReplyMsgDescriptor::~Icmpv6EchoReplyMsgDescriptor()
{
    delete[] propertynames;
}

bool Icmpv6EchoReplyMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Icmpv6EchoReplyMsg *>(obj)!=nullptr;
}

const char **Icmpv6EchoReplyMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Icmpv6EchoReplyMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Icmpv6EchoReplyMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Icmpv6EchoReplyMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_code
        FD_ISEDITABLE,    // FIELD_identifier
        FD_ISEDITABLE,    // FIELD_seqNumber
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Icmpv6EchoReplyMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
        "identifier",
        "seqNumber",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Icmpv6EchoReplyMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "code") == 0) return base+0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "identifier") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "seqNumber") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Icmpv6EchoReplyMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_code
        "int",    // FIELD_identifier
        "int",    // FIELD_seqNumber
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Icmpv6EchoReplyMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *Icmpv6EchoReplyMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Icmpv6EchoReplyMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Icmpv6EchoReplyMsg *pp = (Icmpv6EchoReplyMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Icmpv6EchoReplyMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6EchoReplyMsg *pp = (Icmpv6EchoReplyMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Icmpv6EchoReplyMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6EchoReplyMsg *pp = (Icmpv6EchoReplyMsg *)object; (void)pp;
    switch (field) {
        case FIELD_code: return long2string(pp->getCode());
        case FIELD_identifier: return long2string(pp->getIdentifier());
        case FIELD_seqNumber: return long2string(pp->getSeqNumber());
        default: return "";
    }
}

bool Icmpv6EchoReplyMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Icmpv6EchoReplyMsg *pp = (Icmpv6EchoReplyMsg *)object; (void)pp;
    switch (field) {
        case FIELD_code: pp->setCode(string2long(value)); return true;
        case FIELD_identifier: pp->setIdentifier(string2long(value)); return true;
        case FIELD_seqNumber: pp->setSeqNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Icmpv6EchoReplyMsgDescriptor::getFieldStructName(int field) const
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

void *Icmpv6EchoReplyMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Icmpv6EchoReplyMsg *pp = (Icmpv6EchoReplyMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

