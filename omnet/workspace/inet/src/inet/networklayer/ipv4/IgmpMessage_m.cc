//
// Generated file, do not edit! Created by nedtool 5.6 from inet/networklayer/ipv4/IgmpMessage.msg.
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
#include "IgmpMessage_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::IgmpType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::IgmpType"));
    e->insert(IGMP_MEMBERSHIP_QUERY, "IGMP_MEMBERSHIP_QUERY");
    e->insert(IGMPV1_MEMBERSHIP_REPORT, "IGMPV1_MEMBERSHIP_REPORT");
    e->insert(IGMPV2_MEMBERSHIP_REPORT, "IGMPV2_MEMBERSHIP_REPORT");
    e->insert(IGMPV2_LEAVE_GROUP, "IGMPV2_LEAVE_GROUP");
    e->insert(IGMPV3_MEMBERSHIP_REPORT, "IGMPV3_MEMBERSHIP_REPORT");
)

Register_Class(IgmpMessage)

IgmpMessage::IgmpMessage() : ::inet::FieldsChunk()
{
}

IgmpMessage::IgmpMessage(const IgmpMessage& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

IgmpMessage::~IgmpMessage()
{
}

IgmpMessage& IgmpMessage::operator=(const IgmpMessage& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void IgmpMessage::copy(const IgmpMessage& other)
{
    this->type = other.type;
    this->crc = other.crc;
    this->crcMode = other.crcMode;
}

void IgmpMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->crc);
    doParsimPacking(b,this->crcMode);
}

void IgmpMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->crc);
    doParsimUnpacking(b,this->crcMode);
}

inet::IgmpType IgmpMessage::getType() const
{
    return this->type;
}

void IgmpMessage::setType(inet::IgmpType type)
{
    handleChange();
    this->type = type;
}

uint16_t IgmpMessage::getCrc() const
{
    return this->crc;
}

void IgmpMessage::setCrc(uint16_t crc)
{
    handleChange();
    this->crc = crc;
}

inet::CrcMode IgmpMessage::getCrcMode() const
{
    return this->crcMode;
}

void IgmpMessage::setCrcMode(inet::CrcMode crcMode)
{
    handleChange();
    this->crcMode = crcMode;
}

class IgmpMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_crc,
        FIELD_crcMode,
    };
  public:
    IgmpMessageDescriptor();
    virtual ~IgmpMessageDescriptor();

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

Register_ClassDescriptor(IgmpMessageDescriptor)

IgmpMessageDescriptor::IgmpMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::IgmpMessage)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

IgmpMessageDescriptor::~IgmpMessageDescriptor()
{
    delete[] propertynames;
}

bool IgmpMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IgmpMessage *>(obj)!=nullptr;
}

const char **IgmpMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IgmpMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IgmpMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int IgmpMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_crc
        0,    // FIELD_crcMode
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *IgmpMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "crc",
        "crcMode",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int IgmpMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crc") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crcMode") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IgmpMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::IgmpType",    // FIELD_type
        "uint16_t",    // FIELD_crc
        "inet::CrcMode",    // FIELD_crcMode
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **IgmpMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *IgmpMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::IgmpType";
            return nullptr;
        case FIELD_crcMode:
            if (!strcmp(propertyname, "enum")) return "inet::CrcMode";
            return nullptr;
        default: return nullptr;
    }
}

int IgmpMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IgmpMessage *pp = (IgmpMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IgmpMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IgmpMessage *pp = (IgmpMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IgmpMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IgmpMessage *pp = (IgmpMessage *)object; (void)pp;
    switch (field) {
        case FIELD_type: return enum2string(pp->getType(), "inet::IgmpType");
        case FIELD_crc: return ulong2string(pp->getCrc());
        case FIELD_crcMode: return enum2string(pp->getCrcMode(), "inet::CrcMode");
        default: return "";
    }
}

bool IgmpMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IgmpMessage *pp = (IgmpMessage *)object; (void)pp;
    switch (field) {
        case FIELD_type: pp->setType((inet::IgmpType)string2enum(value, "inet::IgmpType")); return true;
        case FIELD_crc: pp->setCrc(string2ulong(value)); return true;
        default: return false;
    }
}

const char *IgmpMessageDescriptor::getFieldStructName(int field) const
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

void *IgmpMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IgmpMessage *pp = (IgmpMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(IgmpQuery)

IgmpQuery::IgmpQuery() : ::inet::IgmpMessage()
{
    this->setType(IGMP_MEMBERSHIP_QUERY);

}

IgmpQuery::IgmpQuery(const IgmpQuery& other) : ::inet::IgmpMessage(other)
{
    copy(other);
}

IgmpQuery::~IgmpQuery()
{
}

IgmpQuery& IgmpQuery::operator=(const IgmpQuery& other)
{
    if (this == &other) return *this;
    ::inet::IgmpMessage::operator=(other);
    copy(other);
    return *this;
}

void IgmpQuery::copy(const IgmpQuery& other)
{
    this->groupAddress = other.groupAddress;
}

void IgmpQuery::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IgmpMessage::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
}

void IgmpQuery::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IgmpMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
}

const Ipv4Address& IgmpQuery::getGroupAddress() const
{
    return this->groupAddress;
}

void IgmpQuery::setGroupAddress(const Ipv4Address& groupAddress)
{
    handleChange();
    this->groupAddress = groupAddress;
}

class IgmpQueryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_groupAddress,
    };
  public:
    IgmpQueryDescriptor();
    virtual ~IgmpQueryDescriptor();

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

Register_ClassDescriptor(IgmpQueryDescriptor)

IgmpQueryDescriptor::IgmpQueryDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::IgmpQuery)), "inet::IgmpMessage")
{
    propertynames = nullptr;
}

IgmpQueryDescriptor::~IgmpQueryDescriptor()
{
    delete[] propertynames;
}

bool IgmpQueryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IgmpQuery *>(obj)!=nullptr;
}

const char **IgmpQueryDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IgmpQueryDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IgmpQueryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IgmpQueryDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_groupAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *IgmpQueryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int IgmpQueryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "groupAddress") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IgmpQueryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_groupAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **IgmpQueryDescriptor::getFieldPropertyNames(int field) const
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

const char *IgmpQueryDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IgmpQueryDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IgmpQuery *pp = (IgmpQuery *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IgmpQueryDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IgmpQuery *pp = (IgmpQuery *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IgmpQueryDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IgmpQuery *pp = (IgmpQuery *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return pp->getGroupAddress().str();
        default: return "";
    }
}

bool IgmpQueryDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IgmpQuery *pp = (IgmpQuery *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IgmpQueryDescriptor::getFieldStructName(int field) const
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

void *IgmpQueryDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IgmpQuery *pp = (IgmpQuery *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return toVoidPtr(&pp->getGroupAddress()); break;
        default: return nullptr;
    }
}

Register_Class(Igmpv1Query)

Igmpv1Query::Igmpv1Query() : ::inet::IgmpQuery()
{
    this->setChunkLength(B(8));
}

Igmpv1Query::Igmpv1Query(const Igmpv1Query& other) : ::inet::IgmpQuery(other)
{
    copy(other);
}

Igmpv1Query::~Igmpv1Query()
{
}

Igmpv1Query& Igmpv1Query::operator=(const Igmpv1Query& other)
{
    if (this == &other) return *this;
    ::inet::IgmpQuery::operator=(other);
    copy(other);
    return *this;
}

void Igmpv1Query::copy(const Igmpv1Query& other)
{
}

void Igmpv1Query::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IgmpQuery::parsimPack(b);
}

void Igmpv1Query::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IgmpQuery::parsimUnpack(b);
}

class Igmpv1QueryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Igmpv1QueryDescriptor();
    virtual ~Igmpv1QueryDescriptor();

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

Register_ClassDescriptor(Igmpv1QueryDescriptor)

Igmpv1QueryDescriptor::Igmpv1QueryDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Igmpv1Query)), "inet::IgmpQuery")
{
    propertynames = nullptr;
}

Igmpv1QueryDescriptor::~Igmpv1QueryDescriptor()
{
    delete[] propertynames;
}

bool Igmpv1QueryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Igmpv1Query *>(obj)!=nullptr;
}

const char **Igmpv1QueryDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Igmpv1QueryDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Igmpv1QueryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Igmpv1QueryDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Igmpv1QueryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Igmpv1QueryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Igmpv1QueryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Igmpv1QueryDescriptor::getFieldPropertyNames(int field) const
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

const char *Igmpv1QueryDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Igmpv1QueryDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Igmpv1Query *pp = (Igmpv1Query *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Igmpv1QueryDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv1Query *pp = (Igmpv1Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Igmpv1QueryDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv1Query *pp = (Igmpv1Query *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Igmpv1QueryDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Igmpv1Query *pp = (Igmpv1Query *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Igmpv1QueryDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Igmpv1QueryDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Igmpv1Query *pp = (Igmpv1Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Igmpv1Report)

Igmpv1Report::Igmpv1Report() : ::inet::IgmpMessage()
{
    this->setChunkLength(B(8));
    this->setType(IGMPV1_MEMBERSHIP_REPORT);

}

Igmpv1Report::Igmpv1Report(const Igmpv1Report& other) : ::inet::IgmpMessage(other)
{
    copy(other);
}

Igmpv1Report::~Igmpv1Report()
{
}

Igmpv1Report& Igmpv1Report::operator=(const Igmpv1Report& other)
{
    if (this == &other) return *this;
    ::inet::IgmpMessage::operator=(other);
    copy(other);
    return *this;
}

void Igmpv1Report::copy(const Igmpv1Report& other)
{
    this->groupAddress = other.groupAddress;
}

void Igmpv1Report::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IgmpMessage::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
}

void Igmpv1Report::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IgmpMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
}

const Ipv4Address& Igmpv1Report::getGroupAddress() const
{
    return this->groupAddress;
}

void Igmpv1Report::setGroupAddress(const Ipv4Address& groupAddress)
{
    handleChange();
    this->groupAddress = groupAddress;
}

class Igmpv1ReportDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_groupAddress,
    };
  public:
    Igmpv1ReportDescriptor();
    virtual ~Igmpv1ReportDescriptor();

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

Register_ClassDescriptor(Igmpv1ReportDescriptor)

Igmpv1ReportDescriptor::Igmpv1ReportDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Igmpv1Report)), "inet::IgmpMessage")
{
    propertynames = nullptr;
}

Igmpv1ReportDescriptor::~Igmpv1ReportDescriptor()
{
    delete[] propertynames;
}

bool Igmpv1ReportDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Igmpv1Report *>(obj)!=nullptr;
}

const char **Igmpv1ReportDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Igmpv1ReportDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Igmpv1ReportDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Igmpv1ReportDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_groupAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Igmpv1ReportDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Igmpv1ReportDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "groupAddress") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Igmpv1ReportDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_groupAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Igmpv1ReportDescriptor::getFieldPropertyNames(int field) const
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

const char *Igmpv1ReportDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Igmpv1ReportDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Igmpv1Report *pp = (Igmpv1Report *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Igmpv1ReportDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv1Report *pp = (Igmpv1Report *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Igmpv1ReportDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv1Report *pp = (Igmpv1Report *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return pp->getGroupAddress().str();
        default: return "";
    }
}

bool Igmpv1ReportDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Igmpv1Report *pp = (Igmpv1Report *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Igmpv1ReportDescriptor::getFieldStructName(int field) const
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

void *Igmpv1ReportDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Igmpv1Report *pp = (Igmpv1Report *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return toVoidPtr(&pp->getGroupAddress()); break;
        default: return nullptr;
    }
}

Register_Class(Igmpv2Query)

Igmpv2Query::Igmpv2Query() : ::inet::IgmpQuery()
{
    this->setChunkLength(B(8));

}

Igmpv2Query::Igmpv2Query(const Igmpv2Query& other) : ::inet::IgmpQuery(other)
{
    copy(other);
}

Igmpv2Query::~Igmpv2Query()
{
}

Igmpv2Query& Igmpv2Query::operator=(const Igmpv2Query& other)
{
    if (this == &other) return *this;
    ::inet::IgmpQuery::operator=(other);
    copy(other);
    return *this;
}

void Igmpv2Query::copy(const Igmpv2Query& other)
{
    this->maxRespTime = other.maxRespTime;
}

void Igmpv2Query::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IgmpQuery::parsimPack(b);
    doParsimPacking(b,this->maxRespTime);
}

void Igmpv2Query::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IgmpQuery::parsimUnpack(b);
    doParsimUnpacking(b,this->maxRespTime);
}

omnetpp::simtime_t Igmpv2Query::getMaxRespTime() const
{
    return this->maxRespTime;
}

void Igmpv2Query::setMaxRespTime(omnetpp::simtime_t maxRespTime)
{
    handleChange();
    this->maxRespTime = maxRespTime;
}

class Igmpv2QueryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_maxRespTime,
    };
  public:
    Igmpv2QueryDescriptor();
    virtual ~Igmpv2QueryDescriptor();

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

Register_ClassDescriptor(Igmpv2QueryDescriptor)

Igmpv2QueryDescriptor::Igmpv2QueryDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Igmpv2Query)), "inet::IgmpQuery")
{
    propertynames = nullptr;
}

Igmpv2QueryDescriptor::~Igmpv2QueryDescriptor()
{
    delete[] propertynames;
}

bool Igmpv2QueryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Igmpv2Query *>(obj)!=nullptr;
}

const char **Igmpv2QueryDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Igmpv2QueryDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Igmpv2QueryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Igmpv2QueryDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_maxRespTime
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Igmpv2QueryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "maxRespTime",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Igmpv2QueryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "maxRespTime") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Igmpv2QueryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::simtime_t",    // FIELD_maxRespTime
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Igmpv2QueryDescriptor::getFieldPropertyNames(int field) const
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

const char *Igmpv2QueryDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Igmpv2QueryDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Query *pp = (Igmpv2Query *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Igmpv2QueryDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Query *pp = (Igmpv2Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Igmpv2QueryDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Query *pp = (Igmpv2Query *)object; (void)pp;
    switch (field) {
        case FIELD_maxRespTime: return simtime2string(pp->getMaxRespTime());
        default: return "";
    }
}

bool Igmpv2QueryDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Query *pp = (Igmpv2Query *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Igmpv2QueryDescriptor::getFieldStructName(int field) const
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

void *Igmpv2QueryDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Query *pp = (Igmpv2Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Igmpv2Report)

Igmpv2Report::Igmpv2Report() : ::inet::IgmpMessage()
{
    this->setChunkLength(B(8));
    this->setType(IGMPV2_MEMBERSHIP_REPORT);

}

Igmpv2Report::Igmpv2Report(const Igmpv2Report& other) : ::inet::IgmpMessage(other)
{
    copy(other);
}

Igmpv2Report::~Igmpv2Report()
{
}

Igmpv2Report& Igmpv2Report::operator=(const Igmpv2Report& other)
{
    if (this == &other) return *this;
    ::inet::IgmpMessage::operator=(other);
    copy(other);
    return *this;
}

void Igmpv2Report::copy(const Igmpv2Report& other)
{
    this->groupAddress = other.groupAddress;
}

void Igmpv2Report::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IgmpMessage::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
}

void Igmpv2Report::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IgmpMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
}

const Ipv4Address& Igmpv2Report::getGroupAddress() const
{
    return this->groupAddress;
}

void Igmpv2Report::setGroupAddress(const Ipv4Address& groupAddress)
{
    handleChange();
    this->groupAddress = groupAddress;
}

class Igmpv2ReportDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_groupAddress,
    };
  public:
    Igmpv2ReportDescriptor();
    virtual ~Igmpv2ReportDescriptor();

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

Register_ClassDescriptor(Igmpv2ReportDescriptor)

Igmpv2ReportDescriptor::Igmpv2ReportDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Igmpv2Report)), "inet::IgmpMessage")
{
    propertynames = nullptr;
}

Igmpv2ReportDescriptor::~Igmpv2ReportDescriptor()
{
    delete[] propertynames;
}

bool Igmpv2ReportDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Igmpv2Report *>(obj)!=nullptr;
}

const char **Igmpv2ReportDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Igmpv2ReportDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Igmpv2ReportDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Igmpv2ReportDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_groupAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Igmpv2ReportDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Igmpv2ReportDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "groupAddress") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Igmpv2ReportDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_groupAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Igmpv2ReportDescriptor::getFieldPropertyNames(int field) const
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

const char *Igmpv2ReportDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Igmpv2ReportDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Report *pp = (Igmpv2Report *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Igmpv2ReportDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Report *pp = (Igmpv2Report *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Igmpv2ReportDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Report *pp = (Igmpv2Report *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return pp->getGroupAddress().str();
        default: return "";
    }
}

bool Igmpv2ReportDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Report *pp = (Igmpv2Report *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Igmpv2ReportDescriptor::getFieldStructName(int field) const
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

void *Igmpv2ReportDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Report *pp = (Igmpv2Report *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return toVoidPtr(&pp->getGroupAddress()); break;
        default: return nullptr;
    }
}

Register_Class(Igmpv2Leave)

Igmpv2Leave::Igmpv2Leave() : ::inet::IgmpMessage()
{
    this->setChunkLength(B(8));
    this->setType(IGMPV2_LEAVE_GROUP);

}

Igmpv2Leave::Igmpv2Leave(const Igmpv2Leave& other) : ::inet::IgmpMessage(other)
{
    copy(other);
}

Igmpv2Leave::~Igmpv2Leave()
{
}

Igmpv2Leave& Igmpv2Leave::operator=(const Igmpv2Leave& other)
{
    if (this == &other) return *this;
    ::inet::IgmpMessage::operator=(other);
    copy(other);
    return *this;
}

void Igmpv2Leave::copy(const Igmpv2Leave& other)
{
    this->groupAddress = other.groupAddress;
}

void Igmpv2Leave::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IgmpMessage::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
}

void Igmpv2Leave::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IgmpMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
}

const Ipv4Address& Igmpv2Leave::getGroupAddress() const
{
    return this->groupAddress;
}

void Igmpv2Leave::setGroupAddress(const Ipv4Address& groupAddress)
{
    handleChange();
    this->groupAddress = groupAddress;
}

class Igmpv2LeaveDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_groupAddress,
    };
  public:
    Igmpv2LeaveDescriptor();
    virtual ~Igmpv2LeaveDescriptor();

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

Register_ClassDescriptor(Igmpv2LeaveDescriptor)

Igmpv2LeaveDescriptor::Igmpv2LeaveDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Igmpv2Leave)), "inet::IgmpMessage")
{
    propertynames = nullptr;
}

Igmpv2LeaveDescriptor::~Igmpv2LeaveDescriptor()
{
    delete[] propertynames;
}

bool Igmpv2LeaveDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Igmpv2Leave *>(obj)!=nullptr;
}

const char **Igmpv2LeaveDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Igmpv2LeaveDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Igmpv2LeaveDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Igmpv2LeaveDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_groupAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Igmpv2LeaveDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Igmpv2LeaveDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "groupAddress") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Igmpv2LeaveDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_groupAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Igmpv2LeaveDescriptor::getFieldPropertyNames(int field) const
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

const char *Igmpv2LeaveDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Igmpv2LeaveDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Leave *pp = (Igmpv2Leave *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Igmpv2LeaveDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Leave *pp = (Igmpv2Leave *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Igmpv2LeaveDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Leave *pp = (Igmpv2Leave *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return pp->getGroupAddress().str();
        default: return "";
    }
}

bool Igmpv2LeaveDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Leave *pp = (Igmpv2Leave *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Igmpv2LeaveDescriptor::getFieldStructName(int field) const
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

void *Igmpv2LeaveDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Igmpv2Leave *pp = (Igmpv2Leave *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return toVoidPtr(&pp->getGroupAddress()); break;
        default: return nullptr;
    }
}

Register_Class(Igmpv3Query)

Igmpv3Query::Igmpv3Query() : ::inet::Igmpv2Query()
{
}

Igmpv3Query::Igmpv3Query(const Igmpv3Query& other) : ::inet::Igmpv2Query(other)
{
    copy(other);
}

Igmpv3Query::~Igmpv3Query()
{
}

Igmpv3Query& Igmpv3Query::operator=(const Igmpv3Query& other)
{
    if (this == &other) return *this;
    ::inet::Igmpv2Query::operator=(other);
    copy(other);
    return *this;
}

void Igmpv3Query::copy(const Igmpv3Query& other)
{
    this->suppressRouterProc = other.suppressRouterProc;
    this->robustnessVariable = other.robustnessVariable;
    this->queryIntervalCode = other.queryIntervalCode;
    this->sourceList = other.sourceList;
}

void Igmpv3Query::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Igmpv2Query::parsimPack(b);
    doParsimPacking(b,this->suppressRouterProc);
    doParsimPacking(b,this->robustnessVariable);
    doParsimPacking(b,this->queryIntervalCode);
    doParsimPacking(b,this->sourceList);
}

void Igmpv3Query::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Igmpv2Query::parsimUnpack(b);
    doParsimUnpacking(b,this->suppressRouterProc);
    doParsimUnpacking(b,this->robustnessVariable);
    doParsimUnpacking(b,this->queryIntervalCode);
    doParsimUnpacking(b,this->sourceList);
}

bool Igmpv3Query::getSuppressRouterProc() const
{
    return this->suppressRouterProc;
}

void Igmpv3Query::setSuppressRouterProc(bool suppressRouterProc)
{
    handleChange();
    this->suppressRouterProc = suppressRouterProc;
}

unsigned char Igmpv3Query::getRobustnessVariable() const
{
    return this->robustnessVariable;
}

void Igmpv3Query::setRobustnessVariable(unsigned char robustnessVariable)
{
    handleChange();
    this->robustnessVariable = robustnessVariable;
}

unsigned char Igmpv3Query::getQueryIntervalCode() const
{
    return this->queryIntervalCode;
}

void Igmpv3Query::setQueryIntervalCode(unsigned char queryIntervalCode)
{
    handleChange();
    this->queryIntervalCode = queryIntervalCode;
}

const Ipv4AddressVector& Igmpv3Query::getSourceList() const
{
    return this->sourceList;
}

void Igmpv3Query::setSourceList(const Ipv4AddressVector& sourceList)
{
    handleChange();
    this->sourceList = sourceList;
}

class Igmpv3QueryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_suppressRouterProc,
        FIELD_robustnessVariable,
        FIELD_queryIntervalCode,
        FIELD_sourceList,
    };
  public:
    Igmpv3QueryDescriptor();
    virtual ~Igmpv3QueryDescriptor();

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

Register_ClassDescriptor(Igmpv3QueryDescriptor)

Igmpv3QueryDescriptor::Igmpv3QueryDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Igmpv3Query)), "inet::Igmpv2Query")
{
    propertynames = nullptr;
}

Igmpv3QueryDescriptor::~Igmpv3QueryDescriptor()
{
    delete[] propertynames;
}

bool Igmpv3QueryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Igmpv3Query *>(obj)!=nullptr;
}

const char **Igmpv3QueryDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Igmpv3QueryDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Igmpv3QueryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Igmpv3QueryDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_suppressRouterProc
        FD_ISEDITABLE,    // FIELD_robustnessVariable
        FD_ISEDITABLE,    // FIELD_queryIntervalCode
        FD_ISCOMPOUND,    // FIELD_sourceList
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Igmpv3QueryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "suppressRouterProc",
        "robustnessVariable",
        "queryIntervalCode",
        "sourceList",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Igmpv3QueryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "suppressRouterProc") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "robustnessVariable") == 0) return base+1;
    if (fieldName[0] == 'q' && strcmp(fieldName, "queryIntervalCode") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceList") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Igmpv3QueryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_suppressRouterProc
        "unsigned char",    // FIELD_robustnessVariable
        "unsigned char",    // FIELD_queryIntervalCode
        "inet::Ipv4AddressVector",    // FIELD_sourceList
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Igmpv3QueryDescriptor::getFieldPropertyNames(int field) const
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

const char *Igmpv3QueryDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Igmpv3QueryDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Igmpv3Query *pp = (Igmpv3Query *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Igmpv3QueryDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv3Query *pp = (Igmpv3Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Igmpv3QueryDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv3Query *pp = (Igmpv3Query *)object; (void)pp;
    switch (field) {
        case FIELD_suppressRouterProc: return bool2string(pp->getSuppressRouterProc());
        case FIELD_robustnessVariable: return ulong2string(pp->getRobustnessVariable());
        case FIELD_queryIntervalCode: return ulong2string(pp->getQueryIntervalCode());
        case FIELD_sourceList: {std::stringstream out; out << pp->getSourceList(); return out.str();}
        default: return "";
    }
}

bool Igmpv3QueryDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Igmpv3Query *pp = (Igmpv3Query *)object; (void)pp;
    switch (field) {
        case FIELD_suppressRouterProc: pp->setSuppressRouterProc(string2bool(value)); return true;
        case FIELD_robustnessVariable: pp->setRobustnessVariable(string2ulong(value)); return true;
        case FIELD_queryIntervalCode: pp->setQueryIntervalCode(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Igmpv3QueryDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_sourceList: return omnetpp::opp_typename(typeid(Ipv4AddressVector));
        default: return nullptr;
    };
}

void *Igmpv3QueryDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Igmpv3Query *pp = (Igmpv3Query *)object; (void)pp;
    switch (field) {
        case FIELD_sourceList: return toVoidPtr(&pp->getSourceList()); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::GroupRecordType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::GroupRecordType"));
    e->insert(MODE_IS_INCLUDE, "MODE_IS_INCLUDE");
    e->insert(MODE_IS_EXCLUDE, "MODE_IS_EXCLUDE");
    e->insert(CHANGE_TO_INCLUDE_MODE, "CHANGE_TO_INCLUDE_MODE");
    e->insert(CHANGE_TO_EXCLUDE_MODE, "CHANGE_TO_EXCLUDE_MODE");
    e->insert(ALLOW_NEW_SOURCES, "ALLOW_NEW_SOURCES");
    e->insert(BLOCK_OLD_SOURCE, "BLOCK_OLD_SOURCE");
)

GroupRecord::GroupRecord()
{
    this->recordType = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const GroupRecord& a)
{
    doParsimPacking(b,a.recordType);
    doParsimPacking(b,a.groupAddress);
    doParsimPacking(b,a.sourceList);
}

void __doUnpacking(omnetpp::cCommBuffer *b, GroupRecord& a)
{
    doParsimUnpacking(b,a.recordType);
    doParsimUnpacking(b,a.groupAddress);
    doParsimUnpacking(b,a.sourceList);
}

class GroupRecordDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_recordType,
        FIELD_groupAddress,
        FIELD_sourceList,
    };
  public:
    GroupRecordDescriptor();
    virtual ~GroupRecordDescriptor();

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

Register_ClassDescriptor(GroupRecordDescriptor)

GroupRecordDescriptor::GroupRecordDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::GroupRecord)), "")
{
    propertynames = nullptr;
}

GroupRecordDescriptor::~GroupRecordDescriptor()
{
    delete[] propertynames;
}

bool GroupRecordDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<GroupRecord *>(obj)!=nullptr;
}

const char **GroupRecordDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *GroupRecordDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int GroupRecordDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int GroupRecordDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_recordType
        0,    // FIELD_groupAddress
        FD_ISCOMPOUND,    // FIELD_sourceList
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *GroupRecordDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "recordType",
        "groupAddress",
        "sourceList",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int GroupRecordDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "recordType") == 0) return base+0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "groupAddress") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceList") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *GroupRecordDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_recordType
        "inet::Ipv4Address",    // FIELD_groupAddress
        "inet::Ipv4AddressVector",    // FIELD_sourceList
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **GroupRecordDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_recordType: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *GroupRecordDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_recordType:
            if (!strcmp(propertyname, "enum")) return "GroupRecordType";
            if (!strcmp(propertyname, "enum")) return "inet::GroupRecordType";
            return nullptr;
        default: return nullptr;
    }
}

int GroupRecordDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    GroupRecord *pp = (GroupRecord *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *GroupRecordDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    GroupRecord *pp = (GroupRecord *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string GroupRecordDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    GroupRecord *pp = (GroupRecord *)object; (void)pp;
    switch (field) {
        case FIELD_recordType: return enum2string(pp->recordType, "inet::GroupRecordType");
        case FIELD_groupAddress: return pp->groupAddress.str();
        case FIELD_sourceList: {std::stringstream out; out << pp->sourceList; return out.str();}
        default: return "";
    }
}

bool GroupRecordDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    GroupRecord *pp = (GroupRecord *)object; (void)pp;
    switch (field) {
        case FIELD_recordType: pp->recordType = (inet::GroupRecordType)string2enum(value, "inet::GroupRecordType"); return true;
        default: return false;
    }
}

const char *GroupRecordDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_sourceList: return omnetpp::opp_typename(typeid(Ipv4AddressVector));
        default: return nullptr;
    };
}

void *GroupRecordDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    GroupRecord *pp = (GroupRecord *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return toVoidPtr(&pp->groupAddress); break;
        case FIELD_sourceList: return toVoidPtr(&pp->sourceList); break;
        default: return nullptr;
    }
}

Register_Class(Igmpv3Report)

Igmpv3Report::Igmpv3Report() : ::inet::IgmpMessage()
{
    this->setType(IGMPV3_MEMBERSHIP_REPORT);

}

Igmpv3Report::Igmpv3Report(const Igmpv3Report& other) : ::inet::IgmpMessage(other)
{
    copy(other);
}

Igmpv3Report::~Igmpv3Report()
{
    delete [] this->groupRecord;
}

Igmpv3Report& Igmpv3Report::operator=(const Igmpv3Report& other)
{
    if (this == &other) return *this;
    ::inet::IgmpMessage::operator=(other);
    copy(other);
    return *this;
}

void Igmpv3Report::copy(const Igmpv3Report& other)
{
    delete [] this->groupRecord;
    this->groupRecord = (other.groupRecord_arraysize==0) ? nullptr : new GroupRecord[other.groupRecord_arraysize];
    groupRecord_arraysize = other.groupRecord_arraysize;
    for (size_t i = 0; i < groupRecord_arraysize; i++) {
        this->groupRecord[i] = other.groupRecord[i];
    }
}

void Igmpv3Report::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IgmpMessage::parsimPack(b);
    b->pack(groupRecord_arraysize);
    doParsimArrayPacking(b,this->groupRecord,groupRecord_arraysize);
}

void Igmpv3Report::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IgmpMessage::parsimUnpack(b);
    delete [] this->groupRecord;
    b->unpack(groupRecord_arraysize);
    if (groupRecord_arraysize == 0) {
        this->groupRecord = nullptr;
    } else {
        this->groupRecord = new GroupRecord[groupRecord_arraysize];
        doParsimArrayUnpacking(b,this->groupRecord,groupRecord_arraysize);
    }
}

size_t Igmpv3Report::getGroupRecordArraySize() const
{
    return groupRecord_arraysize;
}

const GroupRecord& Igmpv3Report::getGroupRecord(size_t k) const
{
    if (k >= groupRecord_arraysize) throw omnetpp::cRuntimeError("Array of size groupRecord_arraysize indexed by %lu", (unsigned long)k);
    return this->groupRecord[k];
}

void Igmpv3Report::setGroupRecordArraySize(size_t newSize)
{
    handleChange();
    GroupRecord *groupRecord2 = (newSize==0) ? nullptr : new GroupRecord[newSize];
    size_t minSize = groupRecord_arraysize < newSize ? groupRecord_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        groupRecord2[i] = this->groupRecord[i];
    delete [] this->groupRecord;
    this->groupRecord = groupRecord2;
    groupRecord_arraysize = newSize;
}

void Igmpv3Report::setGroupRecord(size_t k, const GroupRecord& groupRecord)
{
    if (k >= groupRecord_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->groupRecord[k] = groupRecord;
}

void Igmpv3Report::insertGroupRecord(size_t k, const GroupRecord& groupRecord)
{
    handleChange();
    if (k > groupRecord_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = groupRecord_arraysize + 1;
    GroupRecord *groupRecord2 = new GroupRecord[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        groupRecord2[i] = this->groupRecord[i];
    groupRecord2[k] = groupRecord;
    for (i = k + 1; i < newSize; i++)
        groupRecord2[i] = this->groupRecord[i-1];
    delete [] this->groupRecord;
    this->groupRecord = groupRecord2;
    groupRecord_arraysize = newSize;
}

void Igmpv3Report::insertGroupRecord(const GroupRecord& groupRecord)
{
    insertGroupRecord(groupRecord_arraysize, groupRecord);
}

void Igmpv3Report::eraseGroupRecord(size_t k)
{
    if (k >= groupRecord_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = groupRecord_arraysize - 1;
    GroupRecord *groupRecord2 = (newSize == 0) ? nullptr : new GroupRecord[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        groupRecord2[i] = this->groupRecord[i];
    for (i = k; i < newSize; i++)
        groupRecord2[i] = this->groupRecord[i+1];
    delete [] this->groupRecord;
    this->groupRecord = groupRecord2;
    groupRecord_arraysize = newSize;
}

class Igmpv3ReportDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_groupRecord,
    };
  public:
    Igmpv3ReportDescriptor();
    virtual ~Igmpv3ReportDescriptor();

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

Register_ClassDescriptor(Igmpv3ReportDescriptor)

Igmpv3ReportDescriptor::Igmpv3ReportDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Igmpv3Report)), "inet::IgmpMessage")
{
    propertynames = nullptr;
}

Igmpv3ReportDescriptor::~Igmpv3ReportDescriptor()
{
    delete[] propertynames;
}

bool Igmpv3ReportDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Igmpv3Report *>(obj)!=nullptr;
}

const char **Igmpv3ReportDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Igmpv3ReportDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Igmpv3ReportDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Igmpv3ReportDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_groupRecord
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Igmpv3ReportDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupRecord",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Igmpv3ReportDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "groupRecord") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Igmpv3ReportDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::GroupRecord",    // FIELD_groupRecord
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Igmpv3ReportDescriptor::getFieldPropertyNames(int field) const
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

const char *Igmpv3ReportDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Igmpv3ReportDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Igmpv3Report *pp = (Igmpv3Report *)object; (void)pp;
    switch (field) {
        case FIELD_groupRecord: return pp->getGroupRecordArraySize();
        default: return 0;
    }
}

const char *Igmpv3ReportDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv3Report *pp = (Igmpv3Report *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Igmpv3ReportDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Igmpv3Report *pp = (Igmpv3Report *)object; (void)pp;
    switch (field) {
        case FIELD_groupRecord: {std::stringstream out; out << pp->getGroupRecord(i); return out.str();}
        default: return "";
    }
}

bool Igmpv3ReportDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Igmpv3Report *pp = (Igmpv3Report *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Igmpv3ReportDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_groupRecord: return omnetpp::opp_typename(typeid(GroupRecord));
        default: return nullptr;
    };
}

void *Igmpv3ReportDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Igmpv3Report *pp = (Igmpv3Report *)object; (void)pp;
    switch (field) {
        case FIELD_groupRecord: return toVoidPtr(&pp->getGroupRecord(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

