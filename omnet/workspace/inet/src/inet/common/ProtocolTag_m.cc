//
// Generated file, do not edit! Created by nedtool 5.6 from inet/common/ProtocolTag.msg.
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
#include "ProtocolTag_m.h"

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

class ChunkPtrDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_content,
    };
  public:
    ChunkPtrDescriptor();
    virtual ~ChunkPtrDescriptor();

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

Register_ClassDescriptor(ChunkPtrDescriptor)

ChunkPtrDescriptor::ChunkPtrDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ChunkPtr)), "")
{
    propertynames = nullptr;
}

ChunkPtrDescriptor::~ChunkPtrDescriptor()
{
    delete[] propertynames;
}

bool ChunkPtrDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ChunkPtr *>(obj)!=nullptr;
}

const char **ChunkPtrDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ChunkPtrDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ChunkPtrDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int ChunkPtrDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_content
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *ChunkPtrDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "content",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int ChunkPtrDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "content") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ChunkPtrDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Chunk",    // FIELD_content
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **ChunkPtrDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_content: {
            static const char *names[] = { "getter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *ChunkPtrDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_content:
            if (!strcmp(propertyname, "getter")) return "get";
            return nullptr;
        default: return nullptr;
    }
}

int ChunkPtrDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ChunkPtr *pp = (ChunkPtr *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ChunkPtrDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ChunkPtr *pp = (ChunkPtr *)object; (void)pp;
    switch (field) {
        case FIELD_content: { const Chunk * value = pp->get(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string ChunkPtrDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ChunkPtr *pp = (ChunkPtr *)object; (void)pp;
    switch (field) {
        case FIELD_content: {std::stringstream out; out << pp->get(); return out.str();}
        default: return "";
    }
}

bool ChunkPtrDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ChunkPtr *pp = (ChunkPtr *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *ChunkPtrDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_content: return omnetpp::opp_typename(typeid(Chunk));
        default: return nullptr;
    };
}

void *ChunkPtrDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ChunkPtr *pp = (ChunkPtr *)object; (void)pp;
    switch (field) {
        case FIELD_content: return toVoidPtr(pp->get()); break;
        default: return nullptr;
    }
}

Register_Class(ProtocolTagBase)

ProtocolTagBase::ProtocolTagBase() : ::inet::TagBase()
{
}

ProtocolTagBase::ProtocolTagBase(const ProtocolTagBase& other) : ::inet::TagBase(other)
{
    copy(other);
}

ProtocolTagBase::~ProtocolTagBase()
{
}

ProtocolTagBase& ProtocolTagBase::operator=(const ProtocolTagBase& other)
{
    if (this == &other) return *this;
    ::inet::TagBase::operator=(other);
    copy(other);
    return *this;
}

void ProtocolTagBase::copy(const ProtocolTagBase& other)
{
    this->protocol = other.protocol;
}

void ProtocolTagBase::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TagBase::parsimPack(b);
    doParsimPacking(b,this->protocol);
}

void ProtocolTagBase::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->protocol);
}

const Protocol * ProtocolTagBase::getProtocol() const
{
    return this->protocol;
}

void ProtocolTagBase::setProtocol(const Protocol * protocol)
{
    this->protocol = protocol;
}

class ProtocolTagBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_protocol,
    };
  public:
    ProtocolTagBaseDescriptor();
    virtual ~ProtocolTagBaseDescriptor();

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

Register_ClassDescriptor(ProtocolTagBaseDescriptor)

ProtocolTagBaseDescriptor::ProtocolTagBaseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ProtocolTagBase)), "inet::TagBase")
{
    propertynames = nullptr;
}

ProtocolTagBaseDescriptor::~ProtocolTagBaseDescriptor()
{
    delete[] propertynames;
}

bool ProtocolTagBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ProtocolTagBase *>(obj)!=nullptr;
}

const char **ProtocolTagBaseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ProtocolTagBaseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ProtocolTagBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int ProtocolTagBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER,    // FIELD_protocol
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *ProtocolTagBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "protocol",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int ProtocolTagBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "protocol") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ProtocolTagBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Protocol",    // FIELD_protocol
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **ProtocolTagBaseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_protocol: {
            static const char *names[] = { "toString",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *ProtocolTagBaseDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_protocol:
            if (!strcmp(propertyname, "toString")) return "->str()";
            return nullptr;
        default: return nullptr;
    }
}

int ProtocolTagBaseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ProtocolTagBase *pp = (ProtocolTagBase *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ProtocolTagBaseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ProtocolTagBase *pp = (ProtocolTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_protocol: { const Protocol * value = pp->getProtocol(); return omnetpp::opp_typename(typeid(*const_cast<Protocol *>(value))); }
        default: return nullptr;
    }
}

std::string ProtocolTagBaseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ProtocolTagBase *pp = (ProtocolTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_protocol: return pp->getProtocol()->str();
        default: return "";
    }
}

bool ProtocolTagBaseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ProtocolTagBase *pp = (ProtocolTagBase *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *ProtocolTagBaseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_protocol: return omnetpp::opp_typename(typeid(Protocol));
        default: return nullptr;
    };
}

void *ProtocolTagBaseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ProtocolTagBase *pp = (ProtocolTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_protocol: return toVoidPtr(pp->getProtocol()); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ServicePrimitive");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ServicePrimitive"));
    e->insert(SP_REQUEST, "SP_REQUEST");
    e->insert(SP_INDICATION, "SP_INDICATION");
    e->insert(SP_RESPONSE, "SP_RESPONSE");
    e->insert(SP_CONFIRM, "SP_CONFIRM");
)

Register_Class(DispatchProtocolReq)

DispatchProtocolReq::DispatchProtocolReq() : ::inet::ProtocolTagBase()
{
}

DispatchProtocolReq::DispatchProtocolReq(const DispatchProtocolReq& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

DispatchProtocolReq::~DispatchProtocolReq()
{
}

DispatchProtocolReq& DispatchProtocolReq::operator=(const DispatchProtocolReq& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void DispatchProtocolReq::copy(const DispatchProtocolReq& other)
{
    this->servicePrimitive = other.servicePrimitive;
}

void DispatchProtocolReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
    doParsimPacking(b,this->servicePrimitive);
}

void DispatchProtocolReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->servicePrimitive);
}

inet::ServicePrimitive DispatchProtocolReq::getServicePrimitive() const
{
    return this->servicePrimitive;
}

void DispatchProtocolReq::setServicePrimitive(inet::ServicePrimitive servicePrimitive)
{
    this->servicePrimitive = servicePrimitive;
}

class DispatchProtocolReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_servicePrimitive,
    };
  public:
    DispatchProtocolReqDescriptor();
    virtual ~DispatchProtocolReqDescriptor();

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

Register_ClassDescriptor(DispatchProtocolReqDescriptor)

DispatchProtocolReqDescriptor::DispatchProtocolReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::DispatchProtocolReq)), "inet::ProtocolTagBase")
{
    propertynames = nullptr;
}

DispatchProtocolReqDescriptor::~DispatchProtocolReqDescriptor()
{
    delete[] propertynames;
}

bool DispatchProtocolReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DispatchProtocolReq *>(obj)!=nullptr;
}

const char **DispatchProtocolReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DispatchProtocolReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DispatchProtocolReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int DispatchProtocolReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_servicePrimitive
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *DispatchProtocolReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "servicePrimitive",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int DispatchProtocolReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "servicePrimitive") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DispatchProtocolReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ServicePrimitive",    // FIELD_servicePrimitive
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **DispatchProtocolReqDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_servicePrimitive: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *DispatchProtocolReqDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_servicePrimitive:
            if (!strcmp(propertyname, "enum")) return "inet::ServicePrimitive";
            return nullptr;
        default: return nullptr;
    }
}

int DispatchProtocolReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DispatchProtocolReq *pp = (DispatchProtocolReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *DispatchProtocolReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DispatchProtocolReq *pp = (DispatchProtocolReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DispatchProtocolReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DispatchProtocolReq *pp = (DispatchProtocolReq *)object; (void)pp;
    switch (field) {
        case FIELD_servicePrimitive: return enum2string(pp->getServicePrimitive(), "inet::ServicePrimitive");
        default: return "";
    }
}

bool DispatchProtocolReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DispatchProtocolReq *pp = (DispatchProtocolReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *DispatchProtocolReqDescriptor::getFieldStructName(int field) const
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

void *DispatchProtocolReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DispatchProtocolReq *pp = (DispatchProtocolReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(DispatchProtocolInd)

DispatchProtocolInd::DispatchProtocolInd() : ::inet::ProtocolTagBase()
{
}

DispatchProtocolInd::DispatchProtocolInd(const DispatchProtocolInd& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

DispatchProtocolInd::~DispatchProtocolInd()
{
}

DispatchProtocolInd& DispatchProtocolInd::operator=(const DispatchProtocolInd& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void DispatchProtocolInd::copy(const DispatchProtocolInd& other)
{
}

void DispatchProtocolInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
}

void DispatchProtocolInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
}

class DispatchProtocolIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    DispatchProtocolIndDescriptor();
    virtual ~DispatchProtocolIndDescriptor();

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

Register_ClassDescriptor(DispatchProtocolIndDescriptor)

DispatchProtocolIndDescriptor::DispatchProtocolIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::DispatchProtocolInd)), "inet::ProtocolTagBase")
{
    propertynames = nullptr;
}

DispatchProtocolIndDescriptor::~DispatchProtocolIndDescriptor()
{
    delete[] propertynames;
}

bool DispatchProtocolIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DispatchProtocolInd *>(obj)!=nullptr;
}

const char **DispatchProtocolIndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DispatchProtocolIndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DispatchProtocolIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int DispatchProtocolIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *DispatchProtocolIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int DispatchProtocolIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DispatchProtocolIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **DispatchProtocolIndDescriptor::getFieldPropertyNames(int field) const
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

const char *DispatchProtocolIndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int DispatchProtocolIndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DispatchProtocolInd *pp = (DispatchProtocolInd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *DispatchProtocolIndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DispatchProtocolInd *pp = (DispatchProtocolInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DispatchProtocolIndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DispatchProtocolInd *pp = (DispatchProtocolInd *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool DispatchProtocolIndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DispatchProtocolInd *pp = (DispatchProtocolInd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *DispatchProtocolIndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *DispatchProtocolIndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DispatchProtocolInd *pp = (DispatchProtocolInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(PacketProtocolTag)

PacketProtocolTag::PacketProtocolTag() : ::inet::ProtocolTagBase()
{
}

PacketProtocolTag::PacketProtocolTag(const PacketProtocolTag& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

PacketProtocolTag::~PacketProtocolTag()
{
}

PacketProtocolTag& PacketProtocolTag::operator=(const PacketProtocolTag& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void PacketProtocolTag::copy(const PacketProtocolTag& other)
{
}

void PacketProtocolTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
}

void PacketProtocolTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
}

class PacketProtocolTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    PacketProtocolTagDescriptor();
    virtual ~PacketProtocolTagDescriptor();

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

Register_ClassDescriptor(PacketProtocolTagDescriptor)

PacketProtocolTagDescriptor::PacketProtocolTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PacketProtocolTag)), "inet::ProtocolTagBase")
{
    propertynames = nullptr;
}

PacketProtocolTagDescriptor::~PacketProtocolTagDescriptor()
{
    delete[] propertynames;
}

bool PacketProtocolTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PacketProtocolTag *>(obj)!=nullptr;
}

const char **PacketProtocolTagDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PacketProtocolTagDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PacketProtocolTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int PacketProtocolTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *PacketProtocolTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int PacketProtocolTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PacketProtocolTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **PacketProtocolTagDescriptor::getFieldPropertyNames(int field) const
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

const char *PacketProtocolTagDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PacketProtocolTagDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PacketProtocolTag *pp = (PacketProtocolTag *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PacketProtocolTagDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PacketProtocolTag *pp = (PacketProtocolTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PacketProtocolTagDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PacketProtocolTag *pp = (PacketProtocolTag *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool PacketProtocolTagDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PacketProtocolTag *pp = (PacketProtocolTag *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *PacketProtocolTagDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *PacketProtocolTagDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PacketProtocolTag *pp = (PacketProtocolTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TransportProtocolReq)

TransportProtocolReq::TransportProtocolReq() : ::inet::ProtocolTagBase()
{
}

TransportProtocolReq::TransportProtocolReq(const TransportProtocolReq& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

TransportProtocolReq::~TransportProtocolReq()
{
}

TransportProtocolReq& TransportProtocolReq::operator=(const TransportProtocolReq& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void TransportProtocolReq::copy(const TransportProtocolReq& other)
{
}

void TransportProtocolReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
}

void TransportProtocolReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
}

class TransportProtocolReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    TransportProtocolReqDescriptor();
    virtual ~TransportProtocolReqDescriptor();

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

Register_ClassDescriptor(TransportProtocolReqDescriptor)

TransportProtocolReqDescriptor::TransportProtocolReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TransportProtocolReq)), "inet::ProtocolTagBase")
{
    propertynames = nullptr;
}

TransportProtocolReqDescriptor::~TransportProtocolReqDescriptor()
{
    delete[] propertynames;
}

bool TransportProtocolReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TransportProtocolReq *>(obj)!=nullptr;
}

const char **TransportProtocolReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TransportProtocolReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TransportProtocolReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int TransportProtocolReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *TransportProtocolReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int TransportProtocolReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TransportProtocolReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **TransportProtocolReqDescriptor::getFieldPropertyNames(int field) const
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

const char *TransportProtocolReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TransportProtocolReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TransportProtocolReq *pp = (TransportProtocolReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TransportProtocolReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TransportProtocolReq *pp = (TransportProtocolReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TransportProtocolReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TransportProtocolReq *pp = (TransportProtocolReq *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool TransportProtocolReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TransportProtocolReq *pp = (TransportProtocolReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TransportProtocolReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *TransportProtocolReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TransportProtocolReq *pp = (TransportProtocolReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TransportProtocolInd)

TransportProtocolInd::TransportProtocolInd() : ::inet::ProtocolTagBase()
{
}

TransportProtocolInd::TransportProtocolInd(const TransportProtocolInd& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

TransportProtocolInd::~TransportProtocolInd()
{
}

TransportProtocolInd& TransportProtocolInd::operator=(const TransportProtocolInd& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void TransportProtocolInd::copy(const TransportProtocolInd& other)
{
    this->transportProtocolHeader = other.transportProtocolHeader;
}

void TransportProtocolInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
    doParsimPacking(b,this->transportProtocolHeader);
}

void TransportProtocolInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->transportProtocolHeader);
}

const ChunkPtr& TransportProtocolInd::getTransportProtocolHeader() const
{
    return this->transportProtocolHeader;
}

void TransportProtocolInd::setTransportProtocolHeader(const ChunkPtr& transportProtocolHeader)
{
    this->transportProtocolHeader = transportProtocolHeader;
}

class TransportProtocolIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_transportProtocolHeader,
    };
  public:
    TransportProtocolIndDescriptor();
    virtual ~TransportProtocolIndDescriptor();

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

Register_ClassDescriptor(TransportProtocolIndDescriptor)

TransportProtocolIndDescriptor::TransportProtocolIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TransportProtocolInd)), "inet::ProtocolTagBase")
{
    propertynames = nullptr;
}

TransportProtocolIndDescriptor::~TransportProtocolIndDescriptor()
{
    delete[] propertynames;
}

bool TransportProtocolIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TransportProtocolInd *>(obj)!=nullptr;
}

const char **TransportProtocolIndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TransportProtocolIndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TransportProtocolIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int TransportProtocolIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_transportProtocolHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *TransportProtocolIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "transportProtocolHeader",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int TransportProtocolIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "transportProtocolHeader") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TransportProtocolIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ChunkPtr",    // FIELD_transportProtocolHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **TransportProtocolIndDescriptor::getFieldPropertyNames(int field) const
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

const char *TransportProtocolIndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TransportProtocolIndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TransportProtocolInd *pp = (TransportProtocolInd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TransportProtocolIndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TransportProtocolInd *pp = (TransportProtocolInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TransportProtocolIndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TransportProtocolInd *pp = (TransportProtocolInd *)object; (void)pp;
    switch (field) {
        case FIELD_transportProtocolHeader: {std::stringstream out; out << pp->getTransportProtocolHeader(); return out.str();}
        default: return "";
    }
}

bool TransportProtocolIndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TransportProtocolInd *pp = (TransportProtocolInd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TransportProtocolIndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_transportProtocolHeader: return omnetpp::opp_typename(typeid(ChunkPtr));
        default: return nullptr;
    };
}

void *TransportProtocolIndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TransportProtocolInd *pp = (TransportProtocolInd *)object; (void)pp;
    switch (field) {
        case FIELD_transportProtocolHeader: return toVoidPtr(&pp->getTransportProtocolHeader()); break;
        default: return nullptr;
    }
}

Register_Class(NetworkProtocolReq)

NetworkProtocolReq::NetworkProtocolReq() : ::inet::ProtocolTagBase()
{
}

NetworkProtocolReq::NetworkProtocolReq(const NetworkProtocolReq& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

NetworkProtocolReq::~NetworkProtocolReq()
{
}

NetworkProtocolReq& NetworkProtocolReq::operator=(const NetworkProtocolReq& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void NetworkProtocolReq::copy(const NetworkProtocolReq& other)
{
}

void NetworkProtocolReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
}

void NetworkProtocolReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
}

class NetworkProtocolReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    NetworkProtocolReqDescriptor();
    virtual ~NetworkProtocolReqDescriptor();

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

Register_ClassDescriptor(NetworkProtocolReqDescriptor)

NetworkProtocolReqDescriptor::NetworkProtocolReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::NetworkProtocolReq)), "inet::ProtocolTagBase")
{
    propertynames = nullptr;
}

NetworkProtocolReqDescriptor::~NetworkProtocolReqDescriptor()
{
    delete[] propertynames;
}

bool NetworkProtocolReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetworkProtocolReq *>(obj)!=nullptr;
}

const char **NetworkProtocolReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetworkProtocolReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetworkProtocolReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int NetworkProtocolReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *NetworkProtocolReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int NetworkProtocolReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetworkProtocolReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **NetworkProtocolReqDescriptor::getFieldPropertyNames(int field) const
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

const char *NetworkProtocolReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NetworkProtocolReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetworkProtocolReq *pp = (NetworkProtocolReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetworkProtocolReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetworkProtocolReq *pp = (NetworkProtocolReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetworkProtocolReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetworkProtocolReq *pp = (NetworkProtocolReq *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool NetworkProtocolReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetworkProtocolReq *pp = (NetworkProtocolReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NetworkProtocolReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *NetworkProtocolReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetworkProtocolReq *pp = (NetworkProtocolReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetworkProtocolInd)

NetworkProtocolInd::NetworkProtocolInd() : ::inet::ProtocolTagBase()
{
}

NetworkProtocolInd::NetworkProtocolInd(const NetworkProtocolInd& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

NetworkProtocolInd::~NetworkProtocolInd()
{
}

NetworkProtocolInd& NetworkProtocolInd::operator=(const NetworkProtocolInd& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void NetworkProtocolInd::copy(const NetworkProtocolInd& other)
{
    this->networkProtocolHeader = other.networkProtocolHeader;
}

void NetworkProtocolInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
    doParsimPacking(b,this->networkProtocolHeader);
}

void NetworkProtocolInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->networkProtocolHeader);
}

const ChunkPtr& NetworkProtocolInd::getNetworkProtocolHeader() const
{
    return this->networkProtocolHeader;
}

void NetworkProtocolInd::setNetworkProtocolHeader(const ChunkPtr& networkProtocolHeader)
{
    this->networkProtocolHeader = networkProtocolHeader;
}

class NetworkProtocolIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_networkProtocolHeader,
    };
  public:
    NetworkProtocolIndDescriptor();
    virtual ~NetworkProtocolIndDescriptor();

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

Register_ClassDescriptor(NetworkProtocolIndDescriptor)

NetworkProtocolIndDescriptor::NetworkProtocolIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::NetworkProtocolInd)), "inet::ProtocolTagBase")
{
    propertynames = nullptr;
}

NetworkProtocolIndDescriptor::~NetworkProtocolIndDescriptor()
{
    delete[] propertynames;
}

bool NetworkProtocolIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetworkProtocolInd *>(obj)!=nullptr;
}

const char **NetworkProtocolIndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetworkProtocolIndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetworkProtocolIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int NetworkProtocolIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_networkProtocolHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *NetworkProtocolIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkProtocolHeader",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int NetworkProtocolIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "networkProtocolHeader") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetworkProtocolIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ChunkPtr",    // FIELD_networkProtocolHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **NetworkProtocolIndDescriptor::getFieldPropertyNames(int field) const
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

const char *NetworkProtocolIndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NetworkProtocolIndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetworkProtocolInd *pp = (NetworkProtocolInd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetworkProtocolIndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetworkProtocolInd *pp = (NetworkProtocolInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetworkProtocolIndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetworkProtocolInd *pp = (NetworkProtocolInd *)object; (void)pp;
    switch (field) {
        case FIELD_networkProtocolHeader: {std::stringstream out; out << pp->getNetworkProtocolHeader(); return out.str();}
        default: return "";
    }
}

bool NetworkProtocolIndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetworkProtocolInd *pp = (NetworkProtocolInd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NetworkProtocolIndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_networkProtocolHeader: return omnetpp::opp_typename(typeid(ChunkPtr));
        default: return nullptr;
    };
}

void *NetworkProtocolIndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetworkProtocolInd *pp = (NetworkProtocolInd *)object; (void)pp;
    switch (field) {
        case FIELD_networkProtocolHeader: return toVoidPtr(&pp->getNetworkProtocolHeader()); break;
        default: return nullptr;
    }
}

Register_Class(MacProtocolReq)

MacProtocolReq::MacProtocolReq() : ::inet::ProtocolTagBase()
{
}

MacProtocolReq::MacProtocolReq(const MacProtocolReq& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

MacProtocolReq::~MacProtocolReq()
{
}

MacProtocolReq& MacProtocolReq::operator=(const MacProtocolReq& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void MacProtocolReq::copy(const MacProtocolReq& other)
{
}

void MacProtocolReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
}

void MacProtocolReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
}

class MacProtocolReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    MacProtocolReqDescriptor();
    virtual ~MacProtocolReqDescriptor();

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

Register_ClassDescriptor(MacProtocolReqDescriptor)

MacProtocolReqDescriptor::MacProtocolReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::MacProtocolReq)), "inet::ProtocolTagBase")
{
    propertynames = nullptr;
}

MacProtocolReqDescriptor::~MacProtocolReqDescriptor()
{
    delete[] propertynames;
}

bool MacProtocolReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MacProtocolReq *>(obj)!=nullptr;
}

const char **MacProtocolReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MacProtocolReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MacProtocolReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int MacProtocolReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *MacProtocolReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int MacProtocolReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MacProtocolReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **MacProtocolReqDescriptor::getFieldPropertyNames(int field) const
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

const char *MacProtocolReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int MacProtocolReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MacProtocolReq *pp = (MacProtocolReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MacProtocolReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MacProtocolReq *pp = (MacProtocolReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MacProtocolReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MacProtocolReq *pp = (MacProtocolReq *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool MacProtocolReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MacProtocolReq *pp = (MacProtocolReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MacProtocolReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *MacProtocolReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MacProtocolReq *pp = (MacProtocolReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(MacProtocolInd)

MacProtocolInd::MacProtocolInd() : ::inet::ProtocolTagBase()
{
}

MacProtocolInd::MacProtocolInd(const MacProtocolInd& other) : ::inet::ProtocolTagBase(other)
{
    copy(other);
}

MacProtocolInd::~MacProtocolInd()
{
}

MacProtocolInd& MacProtocolInd::operator=(const MacProtocolInd& other)
{
    if (this == &other) return *this;
    ::inet::ProtocolTagBase::operator=(other);
    copy(other);
    return *this;
}

void MacProtocolInd::copy(const MacProtocolInd& other)
{
    this->macProtocolHeader = other.macProtocolHeader;
}

void MacProtocolInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ProtocolTagBase::parsimPack(b);
    doParsimPacking(b,this->macProtocolHeader);
}

void MacProtocolInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ProtocolTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->macProtocolHeader);
}

const ChunkPtr& MacProtocolInd::getMacProtocolHeader() const
{
    return this->macProtocolHeader;
}

void MacProtocolInd::setMacProtocolHeader(const ChunkPtr& macProtocolHeader)
{
    this->macProtocolHeader = macProtocolHeader;
}

class MacProtocolIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_macProtocolHeader,
    };
  public:
    MacProtocolIndDescriptor();
    virtual ~MacProtocolIndDescriptor();

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

Register_ClassDescriptor(MacProtocolIndDescriptor)

MacProtocolIndDescriptor::MacProtocolIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::MacProtocolInd)), "inet::ProtocolTagBase")
{
    propertynames = nullptr;
}

MacProtocolIndDescriptor::~MacProtocolIndDescriptor()
{
    delete[] propertynames;
}

bool MacProtocolIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MacProtocolInd *>(obj)!=nullptr;
}

const char **MacProtocolIndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MacProtocolIndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MacProtocolIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int MacProtocolIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_macProtocolHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MacProtocolIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "macProtocolHeader",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MacProtocolIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "macProtocolHeader") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MacProtocolIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ChunkPtr",    // FIELD_macProtocolHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MacProtocolIndDescriptor::getFieldPropertyNames(int field) const
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

const char *MacProtocolIndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int MacProtocolIndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MacProtocolInd *pp = (MacProtocolInd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MacProtocolIndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MacProtocolInd *pp = (MacProtocolInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MacProtocolIndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MacProtocolInd *pp = (MacProtocolInd *)object; (void)pp;
    switch (field) {
        case FIELD_macProtocolHeader: {std::stringstream out; out << pp->getMacProtocolHeader(); return out.str();}
        default: return "";
    }
}

bool MacProtocolIndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MacProtocolInd *pp = (MacProtocolInd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MacProtocolIndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_macProtocolHeader: return omnetpp::opp_typename(typeid(ChunkPtr));
        default: return nullptr;
    };
}

void *MacProtocolIndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MacProtocolInd *pp = (MacProtocolInd *)object; (void)pp;
    switch (field) {
        case FIELD_macProtocolHeader: return toVoidPtr(&pp->getMacProtocolHeader()); break;
        default: return nullptr;
    }
}

} // namespace inet

