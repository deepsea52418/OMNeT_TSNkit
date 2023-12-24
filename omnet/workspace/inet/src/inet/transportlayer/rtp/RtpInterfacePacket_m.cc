//
// Generated file, do not edit! Created by nedtool 5.6 from inet/transportlayer/rtp/RtpInterfacePacket.msg.
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
#include "RtpInterfacePacket_m.h"

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
namespace rtp {

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::rtp::RtpIfpType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::rtp::RtpIfpType"));
    e->insert(RTP_IFP_ENTER_SESSION, "RTP_IFP_ENTER_SESSION");
    e->insert(RTP_IFP_SESSION_ENTERED, "RTP_IFP_SESSION_ENTERED");
    e->insert(RTP_IFP_CREATE_SENDER_MODULE, "RTP_IFP_CREATE_SENDER_MODULE");
    e->insert(RTP_IFP_SENDER_MODULE_CREATED, "RTP_IFP_SENDER_MODULE_CREATED");
    e->insert(RTP_IFP_DELETE_SENDER_MODULE, "RTP_IFP_DELETE_SENDER_MODULE");
    e->insert(RTP_IFP_SENDER_MODULE_DELETED, "RTP_IFP_SENDER_MODULE_DELETED");
    e->insert(RTP_IFP_SENDER_CONTROL, "RTP_IFP_SENDER_CONTROL");
    e->insert(RTP_IFP_SENDER_STATUS, "RTP_IFP_SENDER_STATUS");
    e->insert(RTP_IFP_LEAVE_SESSION, "RTP_IFP_LEAVE_SESSION");
    e->insert(RTP_IFP_SESSION_LEFT, "RTP_IFP_SESSION_LEFT");
)

Register_Class(RtpControlMsg)

RtpControlMsg::RtpControlMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

RtpControlMsg::RtpControlMsg(const RtpControlMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

RtpControlMsg::~RtpControlMsg()
{
}

RtpControlMsg& RtpControlMsg::operator=(const RtpControlMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void RtpControlMsg::copy(const RtpControlMsg& other)
{
}

void RtpControlMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
}

void RtpControlMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
}

class RtpControlMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    RtpControlMsgDescriptor();
    virtual ~RtpControlMsgDescriptor();

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

Register_ClassDescriptor(RtpControlMsgDescriptor)

RtpControlMsgDescriptor::RtpControlMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpControlMsg)), "omnetpp::cMessage")
{
    propertynames = nullptr;
}

RtpControlMsgDescriptor::~RtpControlMsgDescriptor()
{
    delete[] propertynames;
}

bool RtpControlMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpControlMsg *>(obj)!=nullptr;
}

const char **RtpControlMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpControlMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpControlMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RtpControlMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RtpControlMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RtpControlMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpControlMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RtpControlMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpControlMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtpControlMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpControlMsg *pp = (RtpControlMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpControlMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpControlMsg *pp = (RtpControlMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpControlMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpControlMsg *pp = (RtpControlMsg *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RtpControlMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpControlMsg *pp = (RtpControlMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RtpControlMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RtpControlMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpControlMsg *pp = (RtpControlMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtpControlInfo)

RtpControlInfo::RtpControlInfo() : ::omnetpp::cObject()
{
}

RtpControlInfo::RtpControlInfo(const RtpControlInfo& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

RtpControlInfo::~RtpControlInfo()
{
}

RtpControlInfo& RtpControlInfo::operator=(const RtpControlInfo& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void RtpControlInfo::copy(const RtpControlInfo& other)
{
    this->type = other.type;
}

void RtpControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->type);
}

void RtpControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->type);
}

inet::rtp::RtpIfpType RtpControlInfo::getType() const
{
    return this->type;
}

void RtpControlInfo::setType(inet::rtp::RtpIfpType type)
{
    this->type = type;
}

class RtpControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
    };
  public:
    RtpControlInfoDescriptor();
    virtual ~RtpControlInfoDescriptor();

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

Register_ClassDescriptor(RtpControlInfoDescriptor)

RtpControlInfoDescriptor::RtpControlInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpControlInfo)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

RtpControlInfoDescriptor::~RtpControlInfoDescriptor()
{
    delete[] propertynames;
}

bool RtpControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpControlInfo *>(obj)!=nullptr;
}

const char **RtpControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpControlInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RtpControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *RtpControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int RtpControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::rtp::RtpIfpType",    // FIELD_type
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **RtpControlInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::rtp::RtpIfpType";
            return nullptr;
        default: return nullptr;
    }
}

int RtpControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpControlInfo *pp = (RtpControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpControlInfo *pp = (RtpControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpControlInfo *pp = (RtpControlInfo *)object; (void)pp;
    switch (field) {
        case FIELD_type: return enum2string(pp->getType(), "inet::rtp::RtpIfpType");
        default: return "";
    }
}

bool RtpControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpControlInfo *pp = (RtpControlInfo *)object; (void)pp;
    switch (field) {
        case FIELD_type: pp->setType((inet::rtp::RtpIfpType)string2enum(value, "inet::rtp::RtpIfpType")); return true;
        default: return false;
    }
}

const char *RtpControlInfoDescriptor::getFieldStructName(int field) const
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

void *RtpControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpControlInfo *pp = (RtpControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtpSessionControlInfo)

RtpSessionControlInfo::RtpSessionControlInfo() : ::inet::rtp::RtpControlInfo()
{
}

RtpSessionControlInfo::RtpSessionControlInfo(const RtpSessionControlInfo& other) : ::inet::rtp::RtpControlInfo(other)
{
    copy(other);
}

RtpSessionControlInfo::~RtpSessionControlInfo()
{
}

RtpSessionControlInfo& RtpSessionControlInfo::operator=(const RtpSessionControlInfo& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtpControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RtpSessionControlInfo::copy(const RtpSessionControlInfo& other)
{
    this->ssrc = other.ssrc;
}

void RtpSessionControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtpControlInfo::parsimPack(b);
    doParsimPacking(b,this->ssrc);
}

void RtpSessionControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtpControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->ssrc);
}

uint32_t RtpSessionControlInfo::getSsrc() const
{
    return this->ssrc;
}

void RtpSessionControlInfo::setSsrc(uint32_t ssrc)
{
    this->ssrc = ssrc;
}

class RtpSessionControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_ssrc,
    };
  public:
    RtpSessionControlInfoDescriptor();
    virtual ~RtpSessionControlInfoDescriptor();

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

Register_ClassDescriptor(RtpSessionControlInfoDescriptor)

RtpSessionControlInfoDescriptor::RtpSessionControlInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpSessionControlInfo)), "inet::rtp::RtpControlInfo")
{
    propertynames = nullptr;
}

RtpSessionControlInfoDescriptor::~RtpSessionControlInfoDescriptor()
{
    delete[] propertynames;
}

bool RtpSessionControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpSessionControlInfo *>(obj)!=nullptr;
}

const char **RtpSessionControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpSessionControlInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpSessionControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RtpSessionControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ssrc
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *RtpSessionControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ssrc",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int RtpSessionControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "ssrc") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpSessionControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_ssrc
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **RtpSessionControlInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpSessionControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtpSessionControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpSessionControlInfo *pp = (RtpSessionControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpSessionControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpSessionControlInfo *pp = (RtpSessionControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpSessionControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpSessionControlInfo *pp = (RtpSessionControlInfo *)object; (void)pp;
    switch (field) {
        case FIELD_ssrc: return ulong2string(pp->getSsrc());
        default: return "";
    }
}

bool RtpSessionControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpSessionControlInfo *pp = (RtpSessionControlInfo *)object; (void)pp;
    switch (field) {
        case FIELD_ssrc: pp->setSsrc(string2ulong(value)); return true;
        default: return false;
    }
}

const char *RtpSessionControlInfoDescriptor::getFieldStructName(int field) const
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

void *RtpSessionControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpSessionControlInfo *pp = (RtpSessionControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtpCiEnterSession)

RtpCiEnterSession::RtpCiEnterSession() : ::inet::rtp::RtpControlInfo()
{
    this->setType(RTP_IFP_ENTER_SESSION);

}

RtpCiEnterSession::RtpCiEnterSession(const RtpCiEnterSession& other) : ::inet::rtp::RtpControlInfo(other)
{
    copy(other);
}

RtpCiEnterSession::~RtpCiEnterSession()
{
}

RtpCiEnterSession& RtpCiEnterSession::operator=(const RtpCiEnterSession& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtpControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RtpCiEnterSession::copy(const RtpCiEnterSession& other)
{
    this->commonName = other.commonName;
    this->profileName = other.profileName;
    this->bandwidth = other.bandwidth;
    this->destinationAddress = other.destinationAddress;
    this->port = other.port;
}

void RtpCiEnterSession::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtpControlInfo::parsimPack(b);
    doParsimPacking(b,this->commonName);
    doParsimPacking(b,this->profileName);
    doParsimPacking(b,this->bandwidth);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->port);
}

void RtpCiEnterSession::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtpControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->commonName);
    doParsimUnpacking(b,this->profileName);
    doParsimUnpacking(b,this->bandwidth);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->port);
}

const char * RtpCiEnterSession::getCommonName() const
{
    return this->commonName.c_str();
}

void RtpCiEnterSession::setCommonName(const char * commonName)
{
    this->commonName = commonName;
}

const char * RtpCiEnterSession::getProfileName() const
{
    return this->profileName.c_str();
}

void RtpCiEnterSession::setProfileName(const char * profileName)
{
    this->profileName = profileName;
}

int RtpCiEnterSession::getBandwidth() const
{
    return this->bandwidth;
}

void RtpCiEnterSession::setBandwidth(int bandwidth)
{
    this->bandwidth = bandwidth;
}

const Ipv4Address& RtpCiEnterSession::getDestinationAddress() const
{
    return this->destinationAddress;
}

void RtpCiEnterSession::setDestinationAddress(const Ipv4Address& destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

int RtpCiEnterSession::getPort() const
{
    return this->port;
}

void RtpCiEnterSession::setPort(int port)
{
    this->port = port;
}

class RtpCiEnterSessionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_commonName,
        FIELD_profileName,
        FIELD_bandwidth,
        FIELD_destinationAddress,
        FIELD_port,
    };
  public:
    RtpCiEnterSessionDescriptor();
    virtual ~RtpCiEnterSessionDescriptor();

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

Register_ClassDescriptor(RtpCiEnterSessionDescriptor)

RtpCiEnterSessionDescriptor::RtpCiEnterSessionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpCiEnterSession)), "inet::rtp::RtpControlInfo")
{
    propertynames = nullptr;
}

RtpCiEnterSessionDescriptor::~RtpCiEnterSessionDescriptor()
{
    delete[] propertynames;
}

bool RtpCiEnterSessionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpCiEnterSession *>(obj)!=nullptr;
}

const char **RtpCiEnterSessionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpCiEnterSessionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpCiEnterSessionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int RtpCiEnterSessionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_commonName
        FD_ISEDITABLE,    // FIELD_profileName
        FD_ISEDITABLE,    // FIELD_bandwidth
        0,    // FIELD_destinationAddress
        FD_ISEDITABLE,    // FIELD_port
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *RtpCiEnterSessionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "commonName",
        "profileName",
        "bandwidth",
        "destinationAddress",
        "port",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int RtpCiEnterSessionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "commonName") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "profileName") == 0) return base+1;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bandwidth") == 0) return base+2;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinationAddress") == 0) return base+3;
    if (fieldName[0] == 'p' && strcmp(fieldName, "port") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpCiEnterSessionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_commonName
        "string",    // FIELD_profileName
        "int",    // FIELD_bandwidth
        "inet::Ipv4Address",    // FIELD_destinationAddress
        "int",    // FIELD_port
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **RtpCiEnterSessionDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpCiEnterSessionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtpCiEnterSessionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpCiEnterSession *pp = (RtpCiEnterSession *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpCiEnterSessionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiEnterSession *pp = (RtpCiEnterSession *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpCiEnterSessionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiEnterSession *pp = (RtpCiEnterSession *)object; (void)pp;
    switch (field) {
        case FIELD_commonName: return oppstring2string(pp->getCommonName());
        case FIELD_profileName: return oppstring2string(pp->getProfileName());
        case FIELD_bandwidth: return long2string(pp->getBandwidth());
        case FIELD_destinationAddress: return pp->getDestinationAddress().str();
        case FIELD_port: return long2string(pp->getPort());
        default: return "";
    }
}

bool RtpCiEnterSessionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpCiEnterSession *pp = (RtpCiEnterSession *)object; (void)pp;
    switch (field) {
        case FIELD_commonName: pp->setCommonName((value)); return true;
        case FIELD_profileName: pp->setProfileName((value)); return true;
        case FIELD_bandwidth: pp->setBandwidth(string2long(value)); return true;
        case FIELD_port: pp->setPort(string2long(value)); return true;
        default: return false;
    }
}

const char *RtpCiEnterSessionDescriptor::getFieldStructName(int field) const
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

void *RtpCiEnterSessionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpCiEnterSession *pp = (RtpCiEnterSession *)object; (void)pp;
    switch (field) {
        case FIELD_destinationAddress: return toVoidPtr(&pp->getDestinationAddress()); break;
        default: return nullptr;
    }
}

Register_Class(RtpCiSessionEntered)

RtpCiSessionEntered::RtpCiSessionEntered() : ::inet::rtp::RtpSessionControlInfo()
{
    this->setType(RTP_IFP_SESSION_ENTERED);
}

RtpCiSessionEntered::RtpCiSessionEntered(const RtpCiSessionEntered& other) : ::inet::rtp::RtpSessionControlInfo(other)
{
    copy(other);
}

RtpCiSessionEntered::~RtpCiSessionEntered()
{
}

RtpCiSessionEntered& RtpCiSessionEntered::operator=(const RtpCiSessionEntered& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtpSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RtpCiSessionEntered::copy(const RtpCiSessionEntered& other)
{
}

void RtpCiSessionEntered::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtpSessionControlInfo::parsimPack(b);
}

void RtpCiSessionEntered::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtpSessionControlInfo::parsimUnpack(b);
}

class RtpCiSessionEnteredDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    RtpCiSessionEnteredDescriptor();
    virtual ~RtpCiSessionEnteredDescriptor();

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

Register_ClassDescriptor(RtpCiSessionEnteredDescriptor)

RtpCiSessionEnteredDescriptor::RtpCiSessionEnteredDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpCiSessionEntered)), "inet::rtp::RtpSessionControlInfo")
{
    propertynames = nullptr;
}

RtpCiSessionEnteredDescriptor::~RtpCiSessionEnteredDescriptor()
{
    delete[] propertynames;
}

bool RtpCiSessionEnteredDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpCiSessionEntered *>(obj)!=nullptr;
}

const char **RtpCiSessionEnteredDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpCiSessionEnteredDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpCiSessionEnteredDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RtpCiSessionEnteredDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RtpCiSessionEnteredDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RtpCiSessionEnteredDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpCiSessionEnteredDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RtpCiSessionEnteredDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpCiSessionEnteredDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtpCiSessionEnteredDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpCiSessionEntered *pp = (RtpCiSessionEntered *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpCiSessionEnteredDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSessionEntered *pp = (RtpCiSessionEntered *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpCiSessionEnteredDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSessionEntered *pp = (RtpCiSessionEntered *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RtpCiSessionEnteredDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpCiSessionEntered *pp = (RtpCiSessionEntered *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RtpCiSessionEnteredDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RtpCiSessionEnteredDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSessionEntered *pp = (RtpCiSessionEntered *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtpCiSenderControl)

RtpCiSenderControl::RtpCiSenderControl() : ::inet::rtp::RtpSessionControlInfo()
{
    this->setType(RTP_IFP_SENDER_CONTROL);

}

RtpCiSenderControl::RtpCiSenderControl(const RtpCiSenderControl& other) : ::inet::rtp::RtpSessionControlInfo(other)
{
    copy(other);
}

RtpCiSenderControl::~RtpCiSenderControl()
{
}

RtpCiSenderControl& RtpCiSenderControl::operator=(const RtpCiSenderControl& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtpSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RtpCiSenderControl::copy(const RtpCiSenderControl& other)
{
    this->command = other.command;
    this->commandParameter1 = other.commandParameter1;
    this->commandParameter2 = other.commandParameter2;
}

void RtpCiSenderControl::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtpSessionControlInfo::parsimPack(b);
    doParsimPacking(b,this->command);
    doParsimPacking(b,this->commandParameter1);
    doParsimPacking(b,this->commandParameter2);
}

void RtpCiSenderControl::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtpSessionControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->command);
    doParsimUnpacking(b,this->commandParameter1);
    doParsimUnpacking(b,this->commandParameter2);
}

inet::rtp::RtpSenderControlMessageCommands RtpCiSenderControl::getCommand() const
{
    return this->command;
}

void RtpCiSenderControl::setCommand(inet::rtp::RtpSenderControlMessageCommands command)
{
    this->command = command;
}

float RtpCiSenderControl::getCommandParameter1() const
{
    return this->commandParameter1;
}

void RtpCiSenderControl::setCommandParameter1(float commandParameter1)
{
    this->commandParameter1 = commandParameter1;
}

float RtpCiSenderControl::getCommandParameter2() const
{
    return this->commandParameter2;
}

void RtpCiSenderControl::setCommandParameter2(float commandParameter2)
{
    this->commandParameter2 = commandParameter2;
}

class RtpCiSenderControlDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_command,
        FIELD_commandParameter1,
        FIELD_commandParameter2,
    };
  public:
    RtpCiSenderControlDescriptor();
    virtual ~RtpCiSenderControlDescriptor();

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

Register_ClassDescriptor(RtpCiSenderControlDescriptor)

RtpCiSenderControlDescriptor::RtpCiSenderControlDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpCiSenderControl)), "inet::rtp::RtpSessionControlInfo")
{
    propertynames = nullptr;
}

RtpCiSenderControlDescriptor::~RtpCiSenderControlDescriptor()
{
    delete[] propertynames;
}

bool RtpCiSenderControlDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpCiSenderControl *>(obj)!=nullptr;
}

const char **RtpCiSenderControlDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpCiSenderControlDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpCiSenderControlDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int RtpCiSenderControlDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_command
        FD_ISEDITABLE,    // FIELD_commandParameter1
        FD_ISEDITABLE,    // FIELD_commandParameter2
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *RtpCiSenderControlDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "command",
        "commandParameter1",
        "commandParameter2",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int RtpCiSenderControlDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "command") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "commandParameter1") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "commandParameter2") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpCiSenderControlDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::rtp::RtpSenderControlMessageCommands",    // FIELD_command
        "float",    // FIELD_commandParameter1
        "float",    // FIELD_commandParameter2
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **RtpCiSenderControlDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_command: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *RtpCiSenderControlDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_command:
            if (!strcmp(propertyname, "enum")) return "inet::rtp::RtpSenderControlMessageCommands";
            return nullptr;
        default: return nullptr;
    }
}

int RtpCiSenderControlDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderControl *pp = (RtpCiSenderControl *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpCiSenderControlDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderControl *pp = (RtpCiSenderControl *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpCiSenderControlDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderControl *pp = (RtpCiSenderControl *)object; (void)pp;
    switch (field) {
        case FIELD_command: return enum2string(pp->getCommand(), "inet::rtp::RtpSenderControlMessageCommands");
        case FIELD_commandParameter1: return double2string(pp->getCommandParameter1());
        case FIELD_commandParameter2: return double2string(pp->getCommandParameter2());
        default: return "";
    }
}

bool RtpCiSenderControlDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderControl *pp = (RtpCiSenderControl *)object; (void)pp;
    switch (field) {
        case FIELD_commandParameter1: pp->setCommandParameter1(string2double(value)); return true;
        case FIELD_commandParameter2: pp->setCommandParameter2(string2double(value)); return true;
        default: return false;
    }
}

const char *RtpCiSenderControlDescriptor::getFieldStructName(int field) const
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

void *RtpCiSenderControlDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderControl *pp = (RtpCiSenderControl *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtpCiSenderStatus)

RtpCiSenderStatus::RtpCiSenderStatus() : ::inet::rtp::RtpSessionControlInfo()
{
    this->setType(RTP_IFP_SENDER_STATUS);

}

RtpCiSenderStatus::RtpCiSenderStatus(const RtpCiSenderStatus& other) : ::inet::rtp::RtpSessionControlInfo(other)
{
    copy(other);
}

RtpCiSenderStatus::~RtpCiSenderStatus()
{
}

RtpCiSenderStatus& RtpCiSenderStatus::operator=(const RtpCiSenderStatus& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtpSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RtpCiSenderStatus::copy(const RtpCiSenderStatus& other)
{
    this->status = other.status;
    this->timeStamp = other.timeStamp;
}

void RtpCiSenderStatus::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtpSessionControlInfo::parsimPack(b);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->timeStamp);
}

void RtpCiSenderStatus::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtpSessionControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->timeStamp);
}

inet::rtp::RtpSenderStatus RtpCiSenderStatus::getStatus() const
{
    return this->status;
}

void RtpCiSenderStatus::setStatus(inet::rtp::RtpSenderStatus status)
{
    this->status = status;
}

uint32_t RtpCiSenderStatus::getTimeStamp() const
{
    return this->timeStamp;
}

void RtpCiSenderStatus::setTimeStamp(uint32_t timeStamp)
{
    this->timeStamp = timeStamp;
}

class RtpCiSenderStatusDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_status,
        FIELD_timeStamp,
    };
  public:
    RtpCiSenderStatusDescriptor();
    virtual ~RtpCiSenderStatusDescriptor();

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

Register_ClassDescriptor(RtpCiSenderStatusDescriptor)

RtpCiSenderStatusDescriptor::RtpCiSenderStatusDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpCiSenderStatus)), "inet::rtp::RtpSessionControlInfo")
{
    propertynames = nullptr;
}

RtpCiSenderStatusDescriptor::~RtpCiSenderStatusDescriptor()
{
    delete[] propertynames;
}

bool RtpCiSenderStatusDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpCiSenderStatus *>(obj)!=nullptr;
}

const char **RtpCiSenderStatusDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpCiSenderStatusDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpCiSenderStatusDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int RtpCiSenderStatusDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_status
        FD_ISEDITABLE,    // FIELD_timeStamp
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *RtpCiSenderStatusDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
        "timeStamp",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int RtpCiSenderStatusDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "status") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "timeStamp") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpCiSenderStatusDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::rtp::RtpSenderStatus",    // FIELD_status
        "uint32",    // FIELD_timeStamp
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **RtpCiSenderStatusDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *RtpCiSenderStatusDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyname, "enum")) return "inet::rtp::RtpSenderStatus";
            return nullptr;
        default: return nullptr;
    }
}

int RtpCiSenderStatusDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderStatus *pp = (RtpCiSenderStatus *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpCiSenderStatusDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderStatus *pp = (RtpCiSenderStatus *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpCiSenderStatusDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderStatus *pp = (RtpCiSenderStatus *)object; (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "inet::rtp::RtpSenderStatus");
        case FIELD_timeStamp: return ulong2string(pp->getTimeStamp());
        default: return "";
    }
}

bool RtpCiSenderStatusDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderStatus *pp = (RtpCiSenderStatus *)object; (void)pp;
    switch (field) {
        case FIELD_timeStamp: pp->setTimeStamp(string2ulong(value)); return true;
        default: return false;
    }
}

const char *RtpCiSenderStatusDescriptor::getFieldStructName(int field) const
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

void *RtpCiSenderStatusDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderStatus *pp = (RtpCiSenderStatus *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtpCiLeaveSession)

RtpCiLeaveSession::RtpCiLeaveSession() : ::inet::rtp::RtpControlInfo()
{
    this->setType(RTP_IFP_LEAVE_SESSION);
}

RtpCiLeaveSession::RtpCiLeaveSession(const RtpCiLeaveSession& other) : ::inet::rtp::RtpControlInfo(other)
{
    copy(other);
}

RtpCiLeaveSession::~RtpCiLeaveSession()
{
}

RtpCiLeaveSession& RtpCiLeaveSession::operator=(const RtpCiLeaveSession& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtpControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RtpCiLeaveSession::copy(const RtpCiLeaveSession& other)
{
}

void RtpCiLeaveSession::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtpControlInfo::parsimPack(b);
}

void RtpCiLeaveSession::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtpControlInfo::parsimUnpack(b);
}

class RtpCiLeaveSessionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    RtpCiLeaveSessionDescriptor();
    virtual ~RtpCiLeaveSessionDescriptor();

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

Register_ClassDescriptor(RtpCiLeaveSessionDescriptor)

RtpCiLeaveSessionDescriptor::RtpCiLeaveSessionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpCiLeaveSession)), "inet::rtp::RtpControlInfo")
{
    propertynames = nullptr;
}

RtpCiLeaveSessionDescriptor::~RtpCiLeaveSessionDescriptor()
{
    delete[] propertynames;
}

bool RtpCiLeaveSessionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpCiLeaveSession *>(obj)!=nullptr;
}

const char **RtpCiLeaveSessionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpCiLeaveSessionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpCiLeaveSessionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RtpCiLeaveSessionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RtpCiLeaveSessionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RtpCiLeaveSessionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpCiLeaveSessionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RtpCiLeaveSessionDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpCiLeaveSessionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtpCiLeaveSessionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpCiLeaveSession *pp = (RtpCiLeaveSession *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpCiLeaveSessionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiLeaveSession *pp = (RtpCiLeaveSession *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpCiLeaveSessionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiLeaveSession *pp = (RtpCiLeaveSession *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RtpCiLeaveSessionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpCiLeaveSession *pp = (RtpCiLeaveSession *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RtpCiLeaveSessionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RtpCiLeaveSessionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpCiLeaveSession *pp = (RtpCiLeaveSession *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtpCiSessionLeft)

RtpCiSessionLeft::RtpCiSessionLeft() : ::inet::rtp::RtpControlInfo()
{
    this->setType(RTP_IFP_SESSION_LEFT);
}

RtpCiSessionLeft::RtpCiSessionLeft(const RtpCiSessionLeft& other) : ::inet::rtp::RtpControlInfo(other)
{
    copy(other);
}

RtpCiSessionLeft::~RtpCiSessionLeft()
{
}

RtpCiSessionLeft& RtpCiSessionLeft::operator=(const RtpCiSessionLeft& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtpControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RtpCiSessionLeft::copy(const RtpCiSessionLeft& other)
{
}

void RtpCiSessionLeft::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtpControlInfo::parsimPack(b);
}

void RtpCiSessionLeft::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtpControlInfo::parsimUnpack(b);
}

class RtpCiSessionLeftDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    RtpCiSessionLeftDescriptor();
    virtual ~RtpCiSessionLeftDescriptor();

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

Register_ClassDescriptor(RtpCiSessionLeftDescriptor)

RtpCiSessionLeftDescriptor::RtpCiSessionLeftDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpCiSessionLeft)), "inet::rtp::RtpControlInfo")
{
    propertynames = nullptr;
}

RtpCiSessionLeftDescriptor::~RtpCiSessionLeftDescriptor()
{
    delete[] propertynames;
}

bool RtpCiSessionLeftDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpCiSessionLeft *>(obj)!=nullptr;
}

const char **RtpCiSessionLeftDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpCiSessionLeftDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpCiSessionLeftDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RtpCiSessionLeftDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RtpCiSessionLeftDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RtpCiSessionLeftDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpCiSessionLeftDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RtpCiSessionLeftDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpCiSessionLeftDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtpCiSessionLeftDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpCiSessionLeft *pp = (RtpCiSessionLeft *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpCiSessionLeftDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSessionLeft *pp = (RtpCiSessionLeft *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpCiSessionLeftDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSessionLeft *pp = (RtpCiSessionLeft *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RtpCiSessionLeftDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpCiSessionLeft *pp = (RtpCiSessionLeft *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RtpCiSessionLeftDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RtpCiSessionLeftDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSessionLeft *pp = (RtpCiSessionLeft *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtpCiCreateSenderModule)

RtpCiCreateSenderModule::RtpCiCreateSenderModule() : ::inet::rtp::RtpSessionControlInfo()
{
    this->setType(RTP_IFP_CREATE_SENDER_MODULE);

}

RtpCiCreateSenderModule::RtpCiCreateSenderModule(const RtpCiCreateSenderModule& other) : ::inet::rtp::RtpSessionControlInfo(other)
{
    copy(other);
}

RtpCiCreateSenderModule::~RtpCiCreateSenderModule()
{
}

RtpCiCreateSenderModule& RtpCiCreateSenderModule::operator=(const RtpCiCreateSenderModule& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtpSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RtpCiCreateSenderModule::copy(const RtpCiCreateSenderModule& other)
{
    this->payloadType = other.payloadType;
    this->fileName = other.fileName;
}

void RtpCiCreateSenderModule::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtpSessionControlInfo::parsimPack(b);
    doParsimPacking(b,this->payloadType);
    doParsimPacking(b,this->fileName);
}

void RtpCiCreateSenderModule::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtpSessionControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->payloadType);
    doParsimUnpacking(b,this->fileName);
}

int RtpCiCreateSenderModule::getPayloadType() const
{
    return this->payloadType;
}

void RtpCiCreateSenderModule::setPayloadType(int payloadType)
{
    this->payloadType = payloadType;
}

const char * RtpCiCreateSenderModule::getFileName() const
{
    return this->fileName.c_str();
}

void RtpCiCreateSenderModule::setFileName(const char * fileName)
{
    this->fileName = fileName;
}

class RtpCiCreateSenderModuleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_payloadType,
        FIELD_fileName,
    };
  public:
    RtpCiCreateSenderModuleDescriptor();
    virtual ~RtpCiCreateSenderModuleDescriptor();

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

Register_ClassDescriptor(RtpCiCreateSenderModuleDescriptor)

RtpCiCreateSenderModuleDescriptor::RtpCiCreateSenderModuleDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpCiCreateSenderModule)), "inet::rtp::RtpSessionControlInfo")
{
    propertynames = nullptr;
}

RtpCiCreateSenderModuleDescriptor::~RtpCiCreateSenderModuleDescriptor()
{
    delete[] propertynames;
}

bool RtpCiCreateSenderModuleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpCiCreateSenderModule *>(obj)!=nullptr;
}

const char **RtpCiCreateSenderModuleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpCiCreateSenderModuleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpCiCreateSenderModuleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int RtpCiCreateSenderModuleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_payloadType
        FD_ISEDITABLE,    // FIELD_fileName
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *RtpCiCreateSenderModuleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "payloadType",
        "fileName",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int RtpCiCreateSenderModuleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "payloadType") == 0) return base+0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fileName") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpCiCreateSenderModuleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_payloadType
        "string",    // FIELD_fileName
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **RtpCiCreateSenderModuleDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpCiCreateSenderModuleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtpCiCreateSenderModuleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpCiCreateSenderModule *pp = (RtpCiCreateSenderModule *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpCiCreateSenderModuleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiCreateSenderModule *pp = (RtpCiCreateSenderModule *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpCiCreateSenderModuleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiCreateSenderModule *pp = (RtpCiCreateSenderModule *)object; (void)pp;
    switch (field) {
        case FIELD_payloadType: return long2string(pp->getPayloadType());
        case FIELD_fileName: return oppstring2string(pp->getFileName());
        default: return "";
    }
}

bool RtpCiCreateSenderModuleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpCiCreateSenderModule *pp = (RtpCiCreateSenderModule *)object; (void)pp;
    switch (field) {
        case FIELD_payloadType: pp->setPayloadType(string2long(value)); return true;
        case FIELD_fileName: pp->setFileName((value)); return true;
        default: return false;
    }
}

const char *RtpCiCreateSenderModuleDescriptor::getFieldStructName(int field) const
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

void *RtpCiCreateSenderModuleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpCiCreateSenderModule *pp = (RtpCiCreateSenderModule *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtpCiSenderModuleCreated)

RtpCiSenderModuleCreated::RtpCiSenderModuleCreated() : ::inet::rtp::RtpSessionControlInfo()
{
    this->setType(RTP_IFP_SENDER_MODULE_CREATED);
}

RtpCiSenderModuleCreated::RtpCiSenderModuleCreated(const RtpCiSenderModuleCreated& other) : ::inet::rtp::RtpSessionControlInfo(other)
{
    copy(other);
}

RtpCiSenderModuleCreated::~RtpCiSenderModuleCreated()
{
}

RtpCiSenderModuleCreated& RtpCiSenderModuleCreated::operator=(const RtpCiSenderModuleCreated& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtpSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RtpCiSenderModuleCreated::copy(const RtpCiSenderModuleCreated& other)
{
}

void RtpCiSenderModuleCreated::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtpSessionControlInfo::parsimPack(b);
}

void RtpCiSenderModuleCreated::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtpSessionControlInfo::parsimUnpack(b);
}

class RtpCiSenderModuleCreatedDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    RtpCiSenderModuleCreatedDescriptor();
    virtual ~RtpCiSenderModuleCreatedDescriptor();

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

Register_ClassDescriptor(RtpCiSenderModuleCreatedDescriptor)

RtpCiSenderModuleCreatedDescriptor::RtpCiSenderModuleCreatedDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpCiSenderModuleCreated)), "inet::rtp::RtpSessionControlInfo")
{
    propertynames = nullptr;
}

RtpCiSenderModuleCreatedDescriptor::~RtpCiSenderModuleCreatedDescriptor()
{
    delete[] propertynames;
}

bool RtpCiSenderModuleCreatedDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpCiSenderModuleCreated *>(obj)!=nullptr;
}

const char **RtpCiSenderModuleCreatedDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpCiSenderModuleCreatedDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpCiSenderModuleCreatedDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RtpCiSenderModuleCreatedDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RtpCiSenderModuleCreatedDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RtpCiSenderModuleCreatedDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpCiSenderModuleCreatedDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RtpCiSenderModuleCreatedDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpCiSenderModuleCreatedDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtpCiSenderModuleCreatedDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderModuleCreated *pp = (RtpCiSenderModuleCreated *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpCiSenderModuleCreatedDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderModuleCreated *pp = (RtpCiSenderModuleCreated *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpCiSenderModuleCreatedDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderModuleCreated *pp = (RtpCiSenderModuleCreated *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RtpCiSenderModuleCreatedDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderModuleCreated *pp = (RtpCiSenderModuleCreated *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RtpCiSenderModuleCreatedDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RtpCiSenderModuleCreatedDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderModuleCreated *pp = (RtpCiSenderModuleCreated *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtpCiDeleteSenderModule)

RtpCiDeleteSenderModule::RtpCiDeleteSenderModule() : ::inet::rtp::RtpSessionControlInfo()
{
    this->setType(RTP_IFP_DELETE_SENDER_MODULE);
}

RtpCiDeleteSenderModule::RtpCiDeleteSenderModule(const RtpCiDeleteSenderModule& other) : ::inet::rtp::RtpSessionControlInfo(other)
{
    copy(other);
}

RtpCiDeleteSenderModule::~RtpCiDeleteSenderModule()
{
}

RtpCiDeleteSenderModule& RtpCiDeleteSenderModule::operator=(const RtpCiDeleteSenderModule& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtpSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RtpCiDeleteSenderModule::copy(const RtpCiDeleteSenderModule& other)
{
}

void RtpCiDeleteSenderModule::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtpSessionControlInfo::parsimPack(b);
}

void RtpCiDeleteSenderModule::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtpSessionControlInfo::parsimUnpack(b);
}

class RtpCiDeleteSenderModuleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    RtpCiDeleteSenderModuleDescriptor();
    virtual ~RtpCiDeleteSenderModuleDescriptor();

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

Register_ClassDescriptor(RtpCiDeleteSenderModuleDescriptor)

RtpCiDeleteSenderModuleDescriptor::RtpCiDeleteSenderModuleDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpCiDeleteSenderModule)), "inet::rtp::RtpSessionControlInfo")
{
    propertynames = nullptr;
}

RtpCiDeleteSenderModuleDescriptor::~RtpCiDeleteSenderModuleDescriptor()
{
    delete[] propertynames;
}

bool RtpCiDeleteSenderModuleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpCiDeleteSenderModule *>(obj)!=nullptr;
}

const char **RtpCiDeleteSenderModuleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpCiDeleteSenderModuleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpCiDeleteSenderModuleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RtpCiDeleteSenderModuleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RtpCiDeleteSenderModuleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RtpCiDeleteSenderModuleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpCiDeleteSenderModuleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RtpCiDeleteSenderModuleDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpCiDeleteSenderModuleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtpCiDeleteSenderModuleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpCiDeleteSenderModule *pp = (RtpCiDeleteSenderModule *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpCiDeleteSenderModuleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiDeleteSenderModule *pp = (RtpCiDeleteSenderModule *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpCiDeleteSenderModuleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiDeleteSenderModule *pp = (RtpCiDeleteSenderModule *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RtpCiDeleteSenderModuleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpCiDeleteSenderModule *pp = (RtpCiDeleteSenderModule *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RtpCiDeleteSenderModuleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RtpCiDeleteSenderModuleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpCiDeleteSenderModule *pp = (RtpCiDeleteSenderModule *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtpCiSenderModuleDeleted)

RtpCiSenderModuleDeleted::RtpCiSenderModuleDeleted() : ::inet::rtp::RtpSessionControlInfo()
{
    this->setType(RTP_IFP_SENDER_MODULE_DELETED);
}

RtpCiSenderModuleDeleted::RtpCiSenderModuleDeleted(const RtpCiSenderModuleDeleted& other) : ::inet::rtp::RtpSessionControlInfo(other)
{
    copy(other);
}

RtpCiSenderModuleDeleted::~RtpCiSenderModuleDeleted()
{
}

RtpCiSenderModuleDeleted& RtpCiSenderModuleDeleted::operator=(const RtpCiSenderModuleDeleted& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtpSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RtpCiSenderModuleDeleted::copy(const RtpCiSenderModuleDeleted& other)
{
}

void RtpCiSenderModuleDeleted::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtpSessionControlInfo::parsimPack(b);
}

void RtpCiSenderModuleDeleted::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtpSessionControlInfo::parsimUnpack(b);
}

class RtpCiSenderModuleDeletedDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    RtpCiSenderModuleDeletedDescriptor();
    virtual ~RtpCiSenderModuleDeletedDescriptor();

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

Register_ClassDescriptor(RtpCiSenderModuleDeletedDescriptor)

RtpCiSenderModuleDeletedDescriptor::RtpCiSenderModuleDeletedDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpCiSenderModuleDeleted)), "inet::rtp::RtpSessionControlInfo")
{
    propertynames = nullptr;
}

RtpCiSenderModuleDeletedDescriptor::~RtpCiSenderModuleDeletedDescriptor()
{
    delete[] propertynames;
}

bool RtpCiSenderModuleDeletedDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpCiSenderModuleDeleted *>(obj)!=nullptr;
}

const char **RtpCiSenderModuleDeletedDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpCiSenderModuleDeletedDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpCiSenderModuleDeletedDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RtpCiSenderModuleDeletedDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RtpCiSenderModuleDeletedDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RtpCiSenderModuleDeletedDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpCiSenderModuleDeletedDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RtpCiSenderModuleDeletedDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpCiSenderModuleDeletedDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtpCiSenderModuleDeletedDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderModuleDeleted *pp = (RtpCiSenderModuleDeleted *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpCiSenderModuleDeletedDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderModuleDeleted *pp = (RtpCiSenderModuleDeleted *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpCiSenderModuleDeletedDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderModuleDeleted *pp = (RtpCiSenderModuleDeleted *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RtpCiSenderModuleDeletedDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderModuleDeleted *pp = (RtpCiSenderModuleDeleted *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RtpCiSenderModuleDeletedDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RtpCiSenderModuleDeletedDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpCiSenderModuleDeleted *pp = (RtpCiSenderModuleDeleted *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace rtp
} // namespace inet

