//
// Generated file, do not edit! Created by nedtool 5.6 from inet/applications/httptools/common/HttpEventMessages.msg.
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
#include "HttpEventMessages_m.h"

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
namespace httptools {

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

Register_Class(HttpServerStatusUpdateMsg)

HttpServerStatusUpdateMsg::HttpServerStatusUpdateMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

HttpServerStatusUpdateMsg::HttpServerStatusUpdateMsg(const HttpServerStatusUpdateMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

HttpServerStatusUpdateMsg::~HttpServerStatusUpdateMsg()
{
}

HttpServerStatusUpdateMsg& HttpServerStatusUpdateMsg::operator=(const HttpServerStatusUpdateMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void HttpServerStatusUpdateMsg::copy(const HttpServerStatusUpdateMsg& other)
{
    this->www = other.www;
    this->setTime = other.setTime;
    this->eventKind = other.eventKind;
    this->pvalue = other.pvalue;
    this->pamortize = other.pamortize;
}

void HttpServerStatusUpdateMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->www);
    doParsimPacking(b,this->setTime);
    doParsimPacking(b,this->eventKind);
    doParsimPacking(b,this->pvalue);
    doParsimPacking(b,this->pamortize);
}

void HttpServerStatusUpdateMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->www);
    doParsimUnpacking(b,this->setTime);
    doParsimUnpacking(b,this->eventKind);
    doParsimUnpacking(b,this->pvalue);
    doParsimUnpacking(b,this->pamortize);
}

const char * HttpServerStatusUpdateMsg::getWww() const
{
    return this->www.c_str();
}

void HttpServerStatusUpdateMsg::setWww(const char * www)
{
    this->www = www;
}

omnetpp::simtime_t HttpServerStatusUpdateMsg::getSetTime() const
{
    return this->setTime;
}

void HttpServerStatusUpdateMsg::setSetTime(omnetpp::simtime_t setTime)
{
    this->setTime = setTime;
}

int HttpServerStatusUpdateMsg::getEventKind() const
{
    return this->eventKind;
}

void HttpServerStatusUpdateMsg::setEventKind(int eventKind)
{
    this->eventKind = eventKind;
}

double HttpServerStatusUpdateMsg::getPvalue() const
{
    return this->pvalue;
}

void HttpServerStatusUpdateMsg::setPvalue(double pvalue)
{
    this->pvalue = pvalue;
}

double HttpServerStatusUpdateMsg::getPamortize() const
{
    return this->pamortize;
}

void HttpServerStatusUpdateMsg::setPamortize(double pamortize)
{
    this->pamortize = pamortize;
}

class HttpServerStatusUpdateMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_www,
        FIELD_setTime,
        FIELD_eventKind,
        FIELD_pvalue,
        FIELD_pamortize,
    };
  public:
    HttpServerStatusUpdateMsgDescriptor();
    virtual ~HttpServerStatusUpdateMsgDescriptor();

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

Register_ClassDescriptor(HttpServerStatusUpdateMsgDescriptor)

HttpServerStatusUpdateMsgDescriptor::HttpServerStatusUpdateMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::httptools::HttpServerStatusUpdateMsg)), "omnetpp::cMessage")
{
    propertynames = nullptr;
}

HttpServerStatusUpdateMsgDescriptor::~HttpServerStatusUpdateMsgDescriptor()
{
    delete[] propertynames;
}

bool HttpServerStatusUpdateMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HttpServerStatusUpdateMsg *>(obj)!=nullptr;
}

const char **HttpServerStatusUpdateMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HttpServerStatusUpdateMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HttpServerStatusUpdateMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int HttpServerStatusUpdateMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_www
        0,    // FIELD_setTime
        FD_ISEDITABLE,    // FIELD_eventKind
        FD_ISEDITABLE,    // FIELD_pvalue
        FD_ISEDITABLE,    // FIELD_pamortize
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *HttpServerStatusUpdateMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "www",
        "setTime",
        "eventKind",
        "pvalue",
        "pamortize",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int HttpServerStatusUpdateMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'w' && strcmp(fieldName, "www") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "setTime") == 0) return base+1;
    if (fieldName[0] == 'e' && strcmp(fieldName, "eventKind") == 0) return base+2;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pvalue") == 0) return base+3;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pamortize") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HttpServerStatusUpdateMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_www
        "omnetpp::simtime_t",    // FIELD_setTime
        "int",    // FIELD_eventKind
        "double",    // FIELD_pvalue
        "double",    // FIELD_pamortize
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **HttpServerStatusUpdateMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *HttpServerStatusUpdateMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int HttpServerStatusUpdateMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    HttpServerStatusUpdateMsg *pp = (HttpServerStatusUpdateMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *HttpServerStatusUpdateMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HttpServerStatusUpdateMsg *pp = (HttpServerStatusUpdateMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HttpServerStatusUpdateMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HttpServerStatusUpdateMsg *pp = (HttpServerStatusUpdateMsg *)object; (void)pp;
    switch (field) {
        case FIELD_www: return oppstring2string(pp->getWww());
        case FIELD_setTime: return simtime2string(pp->getSetTime());
        case FIELD_eventKind: return long2string(pp->getEventKind());
        case FIELD_pvalue: return double2string(pp->getPvalue());
        case FIELD_pamortize: return double2string(pp->getPamortize());
        default: return "";
    }
}

bool HttpServerStatusUpdateMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    HttpServerStatusUpdateMsg *pp = (HttpServerStatusUpdateMsg *)object; (void)pp;
    switch (field) {
        case FIELD_www: pp->setWww((value)); return true;
        case FIELD_eventKind: pp->setEventKind(string2long(value)); return true;
        case FIELD_pvalue: pp->setPvalue(string2double(value)); return true;
        case FIELD_pamortize: pp->setPamortize(string2double(value)); return true;
        default: return false;
    }
}

const char *HttpServerStatusUpdateMsgDescriptor::getFieldStructName(int field) const
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

void *HttpServerStatusUpdateMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    HttpServerStatusUpdateMsg *pp = (HttpServerStatusUpdateMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace httptools
} // namespace inet

