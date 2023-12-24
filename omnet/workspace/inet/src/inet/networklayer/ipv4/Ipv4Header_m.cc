//
// Generated file, do not edit! Created by nedtool 5.6 from inet/networklayer/ipv4/Ipv4Header.msg.
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
#include "Ipv4Header_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Ipv4OptionClass");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Ipv4OptionClass"));
    e->insert(IPOPTION_CLASS_CONTROL, "IPOPTION_CLASS_CONTROL");
    e->insert(IPOPTION_CLASS_RESERVED, "IPOPTION_CLASS_RESERVED");
    e->insert(IPOPTION_CLASS_DEBUGGING, "IPOPTION_CLASS_DEBUGGING");
    e->insert(IPOPTION_CLASS_RESERVED2, "IPOPTION_CLASS_RESERVED2");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Ipv4OptionType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Ipv4OptionType"));
    e->insert(IPOPTION_END_OF_OPTIONS, "IPOPTION_END_OF_OPTIONS");
    e->insert(IPOPTION_NO_OPTION, "IPOPTION_NO_OPTION");
    e->insert(IPOPTION_STREAM_ID, "IPOPTION_STREAM_ID");
    e->insert(IPOPTION_TIMESTAMP, "IPOPTION_TIMESTAMP");
    e->insert(IPOPTION_SECURITY, "IPOPTION_SECURITY");
    e->insert(IPOPTION_LOOSE_SOURCE_ROUTING, "IPOPTION_LOOSE_SOURCE_ROUTING");
    e->insert(IPOPTION_RECORD_ROUTE, "IPOPTION_RECORD_ROUTE");
    e->insert(IPOPTION_STRICT_SOURCE_ROUTING, "IPOPTION_STRICT_SOURCE_ROUTING");
    e->insert(IPOPTION_ROUTER_ALERT, "IPOPTION_ROUTER_ALERT");
    e->insert(IPOPTION_TLV_GPSR, "IPOPTION_TLV_GPSR");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::TimestampFlag");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::TimestampFlag"));
    e->insert(IP_TIMESTAMP_TIMESTAMP_ONLY, "IP_TIMESTAMP_TIMESTAMP_ONLY");
    e->insert(IP_TIMESTAMP_WITH_ADDRESS, "IP_TIMESTAMP_WITH_ADDRESS");
    e->insert(IP_TIMESTAMP_SENDER_INIT_ADDRESS, "IP_TIMESTAMP_SENDER_INIT_ADDRESS");
)

Register_Class(Ipv4Option)

Ipv4Option::Ipv4Option() : ::inet::TlvOptionBase()
{
}

Ipv4Option::Ipv4Option(const Ipv4Option& other) : ::inet::TlvOptionBase(other)
{
    copy(other);
}

Ipv4Option::~Ipv4Option()
{
}

Ipv4Option& Ipv4Option::operator=(const Ipv4Option& other)
{
    if (this == &other) return *this;
    ::inet::TlvOptionBase::operator=(other);
    copy(other);
    return *this;
}

void Ipv4Option::copy(const Ipv4Option& other)
{
}

void Ipv4Option::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TlvOptionBase::parsimPack(b);
}

void Ipv4Option::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TlvOptionBase::parsimUnpack(b);
}

class Ipv4OptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ipv4OptionDescriptor();
    virtual ~Ipv4OptionDescriptor();

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

Register_ClassDescriptor(Ipv4OptionDescriptor)

Ipv4OptionDescriptor::Ipv4OptionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv4Option)), "inet::TlvOptionBase")
{
    propertynames = nullptr;
}

Ipv4OptionDescriptor::~Ipv4OptionDescriptor()
{
    delete[] propertynames;
}

bool Ipv4OptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv4Option *>(obj)!=nullptr;
}

const char **Ipv4OptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv4OptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv4OptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ipv4OptionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ipv4OptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ipv4OptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv4OptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ipv4OptionDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv4OptionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv4OptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv4Option *pp = (Ipv4Option *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv4OptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4Option *pp = (Ipv4Option *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv4OptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4Option *pp = (Ipv4Option *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ipv4OptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv4Option *pp = (Ipv4Option *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv4OptionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ipv4OptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv4Option *pp = (Ipv4Option *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv4OptionNop)

Ipv4OptionNop::Ipv4OptionNop() : ::inet::Ipv4Option()
{
    this->setType(IPOPTION_NO_OPTION);
    this->setLength(1);
}

Ipv4OptionNop::Ipv4OptionNop(const Ipv4OptionNop& other) : ::inet::Ipv4Option(other)
{
    copy(other);
}

Ipv4OptionNop::~Ipv4OptionNop()
{
}

Ipv4OptionNop& Ipv4OptionNop::operator=(const Ipv4OptionNop& other)
{
    if (this == &other) return *this;
    ::inet::Ipv4Option::operator=(other);
    copy(other);
    return *this;
}

void Ipv4OptionNop::copy(const Ipv4OptionNop& other)
{
}

void Ipv4OptionNop::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv4Option::parsimPack(b);
}

void Ipv4OptionNop::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv4Option::parsimUnpack(b);
}

class Ipv4OptionNopDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ipv4OptionNopDescriptor();
    virtual ~Ipv4OptionNopDescriptor();

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

Register_ClassDescriptor(Ipv4OptionNopDescriptor)

Ipv4OptionNopDescriptor::Ipv4OptionNopDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv4OptionNop)), "inet::Ipv4Option")
{
    propertynames = nullptr;
}

Ipv4OptionNopDescriptor::~Ipv4OptionNopDescriptor()
{
    delete[] propertynames;
}

bool Ipv4OptionNopDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv4OptionNop *>(obj)!=nullptr;
}

const char **Ipv4OptionNopDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv4OptionNopDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv4OptionNopDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ipv4OptionNopDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ipv4OptionNopDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ipv4OptionNopDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv4OptionNopDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ipv4OptionNopDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv4OptionNopDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv4OptionNopDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionNop *pp = (Ipv4OptionNop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv4OptionNopDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionNop *pp = (Ipv4OptionNop *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv4OptionNopDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionNop *pp = (Ipv4OptionNop *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ipv4OptionNopDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionNop *pp = (Ipv4OptionNop *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv4OptionNopDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ipv4OptionNopDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionNop *pp = (Ipv4OptionNop *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv4OptionEnd)

Ipv4OptionEnd::Ipv4OptionEnd() : ::inet::Ipv4Option()
{
    this->setType(IPOPTION_END_OF_OPTIONS);
    this->setLength(1);
}

Ipv4OptionEnd::Ipv4OptionEnd(const Ipv4OptionEnd& other) : ::inet::Ipv4Option(other)
{
    copy(other);
}

Ipv4OptionEnd::~Ipv4OptionEnd()
{
}

Ipv4OptionEnd& Ipv4OptionEnd::operator=(const Ipv4OptionEnd& other)
{
    if (this == &other) return *this;
    ::inet::Ipv4Option::operator=(other);
    copy(other);
    return *this;
}

void Ipv4OptionEnd::copy(const Ipv4OptionEnd& other)
{
}

void Ipv4OptionEnd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv4Option::parsimPack(b);
}

void Ipv4OptionEnd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv4Option::parsimUnpack(b);
}

class Ipv4OptionEndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ipv4OptionEndDescriptor();
    virtual ~Ipv4OptionEndDescriptor();

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

Register_ClassDescriptor(Ipv4OptionEndDescriptor)

Ipv4OptionEndDescriptor::Ipv4OptionEndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv4OptionEnd)), "inet::Ipv4Option")
{
    propertynames = nullptr;
}

Ipv4OptionEndDescriptor::~Ipv4OptionEndDescriptor()
{
    delete[] propertynames;
}

bool Ipv4OptionEndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv4OptionEnd *>(obj)!=nullptr;
}

const char **Ipv4OptionEndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv4OptionEndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv4OptionEndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ipv4OptionEndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ipv4OptionEndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ipv4OptionEndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv4OptionEndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ipv4OptionEndDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv4OptionEndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv4OptionEndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionEnd *pp = (Ipv4OptionEnd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv4OptionEndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionEnd *pp = (Ipv4OptionEnd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv4OptionEndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionEnd *pp = (Ipv4OptionEnd *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ipv4OptionEndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionEnd *pp = (Ipv4OptionEnd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv4OptionEndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ipv4OptionEndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionEnd *pp = (Ipv4OptionEnd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv4OptionRecordRoute)

Ipv4OptionRecordRoute::Ipv4OptionRecordRoute() : ::inet::Ipv4Option()
{
}

Ipv4OptionRecordRoute::Ipv4OptionRecordRoute(const Ipv4OptionRecordRoute& other) : ::inet::Ipv4Option(other)
{
    copy(other);
}

Ipv4OptionRecordRoute::~Ipv4OptionRecordRoute()
{
    delete [] this->recordAddress;
}

Ipv4OptionRecordRoute& Ipv4OptionRecordRoute::operator=(const Ipv4OptionRecordRoute& other)
{
    if (this == &other) return *this;
    ::inet::Ipv4Option::operator=(other);
    copy(other);
    return *this;
}

void Ipv4OptionRecordRoute::copy(const Ipv4OptionRecordRoute& other)
{
    this->nextAddressIdx = other.nextAddressIdx;
    delete [] this->recordAddress;
    this->recordAddress = (other.recordAddress_arraysize==0) ? nullptr : new Ipv4Address[other.recordAddress_arraysize];
    recordAddress_arraysize = other.recordAddress_arraysize;
    for (size_t i = 0; i < recordAddress_arraysize; i++) {
        this->recordAddress[i] = other.recordAddress[i];
    }
}

void Ipv4OptionRecordRoute::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv4Option::parsimPack(b);
    doParsimPacking(b,this->nextAddressIdx);
    b->pack(recordAddress_arraysize);
    doParsimArrayPacking(b,this->recordAddress,recordAddress_arraysize);
}

void Ipv4OptionRecordRoute::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv4Option::parsimUnpack(b);
    doParsimUnpacking(b,this->nextAddressIdx);
    delete [] this->recordAddress;
    b->unpack(recordAddress_arraysize);
    if (recordAddress_arraysize == 0) {
        this->recordAddress = nullptr;
    } else {
        this->recordAddress = new Ipv4Address[recordAddress_arraysize];
        doParsimArrayUnpacking(b,this->recordAddress,recordAddress_arraysize);
    }
}

short Ipv4OptionRecordRoute::getNextAddressIdx() const
{
    return this->nextAddressIdx;
}

void Ipv4OptionRecordRoute::setNextAddressIdx(short nextAddressIdx)
{
    this->nextAddressIdx = nextAddressIdx;
}

size_t Ipv4OptionRecordRoute::getRecordAddressArraySize() const
{
    return recordAddress_arraysize;
}

const Ipv4Address& Ipv4OptionRecordRoute::getRecordAddress(size_t k) const
{
    if (k >= recordAddress_arraysize) throw omnetpp::cRuntimeError("Array of size recordAddress_arraysize indexed by %lu", (unsigned long)k);
    return this->recordAddress[k];
}

void Ipv4OptionRecordRoute::setRecordAddressArraySize(size_t newSize)
{
    Ipv4Address *recordAddress2 = (newSize==0) ? nullptr : new Ipv4Address[newSize];
    size_t minSize = recordAddress_arraysize < newSize ? recordAddress_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        recordAddress2[i] = this->recordAddress[i];
    delete [] this->recordAddress;
    this->recordAddress = recordAddress2;
    recordAddress_arraysize = newSize;
}

void Ipv4OptionRecordRoute::setRecordAddress(size_t k, const Ipv4Address& recordAddress)
{
    if (k >= recordAddress_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->recordAddress[k] = recordAddress;
}

void Ipv4OptionRecordRoute::insertRecordAddress(size_t k, const Ipv4Address& recordAddress)
{
    if (k > recordAddress_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = recordAddress_arraysize + 1;
    Ipv4Address *recordAddress2 = new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        recordAddress2[i] = this->recordAddress[i];
    recordAddress2[k] = recordAddress;
    for (i = k + 1; i < newSize; i++)
        recordAddress2[i] = this->recordAddress[i-1];
    delete [] this->recordAddress;
    this->recordAddress = recordAddress2;
    recordAddress_arraysize = newSize;
}

void Ipv4OptionRecordRoute::insertRecordAddress(const Ipv4Address& recordAddress)
{
    insertRecordAddress(recordAddress_arraysize, recordAddress);
}

void Ipv4OptionRecordRoute::eraseRecordAddress(size_t k)
{
    if (k >= recordAddress_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = recordAddress_arraysize - 1;
    Ipv4Address *recordAddress2 = (newSize == 0) ? nullptr : new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        recordAddress2[i] = this->recordAddress[i];
    for (i = k; i < newSize; i++)
        recordAddress2[i] = this->recordAddress[i+1];
    delete [] this->recordAddress;
    this->recordAddress = recordAddress2;
    recordAddress_arraysize = newSize;
}

class Ipv4OptionRecordRouteDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_nextAddressIdx,
        FIELD_recordAddress,
    };
  public:
    Ipv4OptionRecordRouteDescriptor();
    virtual ~Ipv4OptionRecordRouteDescriptor();

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

Register_ClassDescriptor(Ipv4OptionRecordRouteDescriptor)

Ipv4OptionRecordRouteDescriptor::Ipv4OptionRecordRouteDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv4OptionRecordRoute)), "inet::Ipv4Option")
{
    propertynames = nullptr;
}

Ipv4OptionRecordRouteDescriptor::~Ipv4OptionRecordRouteDescriptor()
{
    delete[] propertynames;
}

bool Ipv4OptionRecordRouteDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv4OptionRecordRoute *>(obj)!=nullptr;
}

const char **Ipv4OptionRecordRouteDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv4OptionRecordRouteDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv4OptionRecordRouteDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ipv4OptionRecordRouteDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_nextAddressIdx
        FD_ISARRAY,    // FIELD_recordAddress
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ipv4OptionRecordRouteDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nextAddressIdx",
        "recordAddress",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ipv4OptionRecordRouteDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextAddressIdx") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "recordAddress") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv4OptionRecordRouteDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_nextAddressIdx
        "inet::Ipv4Address",    // FIELD_recordAddress
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv4OptionRecordRouteDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv4OptionRecordRouteDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv4OptionRecordRouteDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionRecordRoute *pp = (Ipv4OptionRecordRoute *)object; (void)pp;
    switch (field) {
        case FIELD_recordAddress: return pp->getRecordAddressArraySize();
        default: return 0;
    }
}

const char *Ipv4OptionRecordRouteDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionRecordRoute *pp = (Ipv4OptionRecordRoute *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv4OptionRecordRouteDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionRecordRoute *pp = (Ipv4OptionRecordRoute *)object; (void)pp;
    switch (field) {
        case FIELD_nextAddressIdx: return long2string(pp->getNextAddressIdx());
        case FIELD_recordAddress: return pp->getRecordAddress(i).str();
        default: return "";
    }
}

bool Ipv4OptionRecordRouteDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionRecordRoute *pp = (Ipv4OptionRecordRoute *)object; (void)pp;
    switch (field) {
        case FIELD_nextAddressIdx: pp->setNextAddressIdx(string2long(value)); return true;
        default: return false;
    }
}

const char *Ipv4OptionRecordRouteDescriptor::getFieldStructName(int field) const
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

void *Ipv4OptionRecordRouteDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionRecordRoute *pp = (Ipv4OptionRecordRoute *)object; (void)pp;
    switch (field) {
        case FIELD_recordAddress: return toVoidPtr(&pp->getRecordAddress(i)); break;
        default: return nullptr;
    }
}

Register_Class(Ipv4OptionTimestamp)

Ipv4OptionTimestamp::Ipv4OptionTimestamp() : ::inet::Ipv4Option()
{
    this->setType(IPOPTION_TIMESTAMP);

}

Ipv4OptionTimestamp::Ipv4OptionTimestamp(const Ipv4OptionTimestamp& other) : ::inet::Ipv4Option(other)
{
    copy(other);
}

Ipv4OptionTimestamp::~Ipv4OptionTimestamp()
{
    delete [] this->recordAddress;
    delete [] this->recordTimestamp;
}

Ipv4OptionTimestamp& Ipv4OptionTimestamp::operator=(const Ipv4OptionTimestamp& other)
{
    if (this == &other) return *this;
    ::inet::Ipv4Option::operator=(other);
    copy(other);
    return *this;
}

void Ipv4OptionTimestamp::copy(const Ipv4OptionTimestamp& other)
{
    this->flag = other.flag;
    this->overflow = other.overflow;
    this->nextIdx = other.nextIdx;
    delete [] this->recordAddress;
    this->recordAddress = (other.recordAddress_arraysize==0) ? nullptr : new Ipv4Address[other.recordAddress_arraysize];
    recordAddress_arraysize = other.recordAddress_arraysize;
    for (size_t i = 0; i < recordAddress_arraysize; i++) {
        this->recordAddress[i] = other.recordAddress[i];
    }
    delete [] this->recordTimestamp;
    this->recordTimestamp = (other.recordTimestamp_arraysize==0) ? nullptr : new omnetpp::simtime_t[other.recordTimestamp_arraysize];
    recordTimestamp_arraysize = other.recordTimestamp_arraysize;
    for (size_t i = 0; i < recordTimestamp_arraysize; i++) {
        this->recordTimestamp[i] = other.recordTimestamp[i];
    }
}

void Ipv4OptionTimestamp::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv4Option::parsimPack(b);
    doParsimPacking(b,this->flag);
    doParsimPacking(b,this->overflow);
    doParsimPacking(b,this->nextIdx);
    b->pack(recordAddress_arraysize);
    doParsimArrayPacking(b,this->recordAddress,recordAddress_arraysize);
    b->pack(recordTimestamp_arraysize);
    doParsimArrayPacking(b,this->recordTimestamp,recordTimestamp_arraysize);
}

void Ipv4OptionTimestamp::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv4Option::parsimUnpack(b);
    doParsimUnpacking(b,this->flag);
    doParsimUnpacking(b,this->overflow);
    doParsimUnpacking(b,this->nextIdx);
    delete [] this->recordAddress;
    b->unpack(recordAddress_arraysize);
    if (recordAddress_arraysize == 0) {
        this->recordAddress = nullptr;
    } else {
        this->recordAddress = new Ipv4Address[recordAddress_arraysize];
        doParsimArrayUnpacking(b,this->recordAddress,recordAddress_arraysize);
    }
    delete [] this->recordTimestamp;
    b->unpack(recordTimestamp_arraysize);
    if (recordTimestamp_arraysize == 0) {
        this->recordTimestamp = nullptr;
    } else {
        this->recordTimestamp = new omnetpp::simtime_t[recordTimestamp_arraysize];
        doParsimArrayUnpacking(b,this->recordTimestamp,recordTimestamp_arraysize);
    }
}

inet::TimestampFlag Ipv4OptionTimestamp::getFlag() const
{
    return this->flag;
}

void Ipv4OptionTimestamp::setFlag(inet::TimestampFlag flag)
{
    this->flag = flag;
}

short Ipv4OptionTimestamp::getOverflow() const
{
    return this->overflow;
}

void Ipv4OptionTimestamp::setOverflow(short overflow)
{
    this->overflow = overflow;
}

short Ipv4OptionTimestamp::getNextIdx() const
{
    return this->nextIdx;
}

void Ipv4OptionTimestamp::setNextIdx(short nextIdx)
{
    this->nextIdx = nextIdx;
}

size_t Ipv4OptionTimestamp::getRecordAddressArraySize() const
{
    return recordAddress_arraysize;
}

const Ipv4Address& Ipv4OptionTimestamp::getRecordAddress(size_t k) const
{
    if (k >= recordAddress_arraysize) throw omnetpp::cRuntimeError("Array of size recordAddress_arraysize indexed by %lu", (unsigned long)k);
    return this->recordAddress[k];
}

void Ipv4OptionTimestamp::setRecordAddressArraySize(size_t newSize)
{
    Ipv4Address *recordAddress2 = (newSize==0) ? nullptr : new Ipv4Address[newSize];
    size_t minSize = recordAddress_arraysize < newSize ? recordAddress_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        recordAddress2[i] = this->recordAddress[i];
    delete [] this->recordAddress;
    this->recordAddress = recordAddress2;
    recordAddress_arraysize = newSize;
}

void Ipv4OptionTimestamp::setRecordAddress(size_t k, const Ipv4Address& recordAddress)
{
    if (k >= recordAddress_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->recordAddress[k] = recordAddress;
}

void Ipv4OptionTimestamp::insertRecordAddress(size_t k, const Ipv4Address& recordAddress)
{
    if (k > recordAddress_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = recordAddress_arraysize + 1;
    Ipv4Address *recordAddress2 = new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        recordAddress2[i] = this->recordAddress[i];
    recordAddress2[k] = recordAddress;
    for (i = k + 1; i < newSize; i++)
        recordAddress2[i] = this->recordAddress[i-1];
    delete [] this->recordAddress;
    this->recordAddress = recordAddress2;
    recordAddress_arraysize = newSize;
}

void Ipv4OptionTimestamp::insertRecordAddress(const Ipv4Address& recordAddress)
{
    insertRecordAddress(recordAddress_arraysize, recordAddress);
}

void Ipv4OptionTimestamp::eraseRecordAddress(size_t k)
{
    if (k >= recordAddress_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = recordAddress_arraysize - 1;
    Ipv4Address *recordAddress2 = (newSize == 0) ? nullptr : new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        recordAddress2[i] = this->recordAddress[i];
    for (i = k; i < newSize; i++)
        recordAddress2[i] = this->recordAddress[i+1];
    delete [] this->recordAddress;
    this->recordAddress = recordAddress2;
    recordAddress_arraysize = newSize;
}

size_t Ipv4OptionTimestamp::getRecordTimestampArraySize() const
{
    return recordTimestamp_arraysize;
}

omnetpp::simtime_t Ipv4OptionTimestamp::getRecordTimestamp(size_t k) const
{
    if (k >= recordTimestamp_arraysize) throw omnetpp::cRuntimeError("Array of size recordTimestamp_arraysize indexed by %lu", (unsigned long)k);
    return this->recordTimestamp[k];
}

void Ipv4OptionTimestamp::setRecordTimestampArraySize(size_t newSize)
{
    omnetpp::simtime_t *recordTimestamp2 = (newSize==0) ? nullptr : new omnetpp::simtime_t[newSize];
    size_t minSize = recordTimestamp_arraysize < newSize ? recordTimestamp_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        recordTimestamp2[i] = this->recordTimestamp[i];
    for (size_t i = minSize; i < newSize; i++)
        recordTimestamp2[i] = SIMTIME_ZERO;
    delete [] this->recordTimestamp;
    this->recordTimestamp = recordTimestamp2;
    recordTimestamp_arraysize = newSize;
}

void Ipv4OptionTimestamp::setRecordTimestamp(size_t k, omnetpp::simtime_t recordTimestamp)
{
    if (k >= recordTimestamp_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->recordTimestamp[k] = recordTimestamp;
}

void Ipv4OptionTimestamp::insertRecordTimestamp(size_t k, omnetpp::simtime_t recordTimestamp)
{
    if (k > recordTimestamp_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = recordTimestamp_arraysize + 1;
    omnetpp::simtime_t *recordTimestamp2 = new omnetpp::simtime_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        recordTimestamp2[i] = this->recordTimestamp[i];
    recordTimestamp2[k] = recordTimestamp;
    for (i = k + 1; i < newSize; i++)
        recordTimestamp2[i] = this->recordTimestamp[i-1];
    delete [] this->recordTimestamp;
    this->recordTimestamp = recordTimestamp2;
    recordTimestamp_arraysize = newSize;
}

void Ipv4OptionTimestamp::insertRecordTimestamp(omnetpp::simtime_t recordTimestamp)
{
    insertRecordTimestamp(recordTimestamp_arraysize, recordTimestamp);
}

void Ipv4OptionTimestamp::eraseRecordTimestamp(size_t k)
{
    if (k >= recordTimestamp_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = recordTimestamp_arraysize - 1;
    omnetpp::simtime_t *recordTimestamp2 = (newSize == 0) ? nullptr : new omnetpp::simtime_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        recordTimestamp2[i] = this->recordTimestamp[i];
    for (i = k; i < newSize; i++)
        recordTimestamp2[i] = this->recordTimestamp[i+1];
    delete [] this->recordTimestamp;
    this->recordTimestamp = recordTimestamp2;
    recordTimestamp_arraysize = newSize;
}

class Ipv4OptionTimestampDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_flag,
        FIELD_overflow,
        FIELD_nextIdx,
        FIELD_recordAddress,
        FIELD_recordTimestamp,
    };
  public:
    Ipv4OptionTimestampDescriptor();
    virtual ~Ipv4OptionTimestampDescriptor();

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

Register_ClassDescriptor(Ipv4OptionTimestampDescriptor)

Ipv4OptionTimestampDescriptor::Ipv4OptionTimestampDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv4OptionTimestamp)), "inet::Ipv4Option")
{
    propertynames = nullptr;
}

Ipv4OptionTimestampDescriptor::~Ipv4OptionTimestampDescriptor()
{
    delete[] propertynames;
}

bool Ipv4OptionTimestampDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv4OptionTimestamp *>(obj)!=nullptr;
}

const char **Ipv4OptionTimestampDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv4OptionTimestampDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv4OptionTimestampDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int Ipv4OptionTimestampDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_flag
        FD_ISEDITABLE,    // FIELD_overflow
        FD_ISEDITABLE,    // FIELD_nextIdx
        FD_ISARRAY,    // FIELD_recordAddress
        FD_ISARRAY,    // FIELD_recordTimestamp
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *Ipv4OptionTimestampDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "flag",
        "overflow",
        "nextIdx",
        "recordAddress",
        "recordTimestamp",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int Ipv4OptionTimestampDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "flag") == 0) return base+0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "overflow") == 0) return base+1;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextIdx") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "recordAddress") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "recordTimestamp") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv4OptionTimestampDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::TimestampFlag",    // FIELD_flag
        "short",    // FIELD_overflow
        "short",    // FIELD_nextIdx
        "inet::Ipv4Address",    // FIELD_recordAddress
        "omnetpp::simtime_t",    // FIELD_recordTimestamp
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv4OptionTimestampDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_flag: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ipv4OptionTimestampDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_flag:
            if (!strcmp(propertyname, "enum")) return "inet::TimestampFlag";
            return nullptr;
        default: return nullptr;
    }
}

int Ipv4OptionTimestampDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionTimestamp *pp = (Ipv4OptionTimestamp *)object; (void)pp;
    switch (field) {
        case FIELD_recordAddress: return pp->getRecordAddressArraySize();
        case FIELD_recordTimestamp: return pp->getRecordTimestampArraySize();
        default: return 0;
    }
}

const char *Ipv4OptionTimestampDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionTimestamp *pp = (Ipv4OptionTimestamp *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv4OptionTimestampDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionTimestamp *pp = (Ipv4OptionTimestamp *)object; (void)pp;
    switch (field) {
        case FIELD_flag: return enum2string(pp->getFlag(), "inet::TimestampFlag");
        case FIELD_overflow: return long2string(pp->getOverflow());
        case FIELD_nextIdx: return long2string(pp->getNextIdx());
        case FIELD_recordAddress: return pp->getRecordAddress(i).str();
        case FIELD_recordTimestamp: return simtime2string(pp->getRecordTimestamp(i));
        default: return "";
    }
}

bool Ipv4OptionTimestampDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionTimestamp *pp = (Ipv4OptionTimestamp *)object; (void)pp;
    switch (field) {
        case FIELD_flag: pp->setFlag((inet::TimestampFlag)string2enum(value, "inet::TimestampFlag")); return true;
        case FIELD_overflow: pp->setOverflow(string2long(value)); return true;
        case FIELD_nextIdx: pp->setNextIdx(string2long(value)); return true;
        default: return false;
    }
}

const char *Ipv4OptionTimestampDescriptor::getFieldStructName(int field) const
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

void *Ipv4OptionTimestampDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionTimestamp *pp = (Ipv4OptionTimestamp *)object; (void)pp;
    switch (field) {
        case FIELD_recordAddress: return toVoidPtr(&pp->getRecordAddress(i)); break;
        default: return nullptr;
    }
}

Register_Class(Ipv4OptionStreamId)

Ipv4OptionStreamId::Ipv4OptionStreamId() : ::inet::Ipv4Option()
{
    this->setType(IPOPTION_STREAM_ID);
    this->setLength(4);

}

Ipv4OptionStreamId::Ipv4OptionStreamId(const Ipv4OptionStreamId& other) : ::inet::Ipv4Option(other)
{
    copy(other);
}

Ipv4OptionStreamId::~Ipv4OptionStreamId()
{
}

Ipv4OptionStreamId& Ipv4OptionStreamId::operator=(const Ipv4OptionStreamId& other)
{
    if (this == &other) return *this;
    ::inet::Ipv4Option::operator=(other);
    copy(other);
    return *this;
}

void Ipv4OptionStreamId::copy(const Ipv4OptionStreamId& other)
{
    this->streamId = other.streamId;
}

void Ipv4OptionStreamId::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv4Option::parsimPack(b);
    doParsimPacking(b,this->streamId);
}

void Ipv4OptionStreamId::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv4Option::parsimUnpack(b);
    doParsimUnpacking(b,this->streamId);
}

short Ipv4OptionStreamId::getStreamId() const
{
    return this->streamId;
}

void Ipv4OptionStreamId::setStreamId(short streamId)
{
    this->streamId = streamId;
}

class Ipv4OptionStreamIdDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_streamId,
    };
  public:
    Ipv4OptionStreamIdDescriptor();
    virtual ~Ipv4OptionStreamIdDescriptor();

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

Register_ClassDescriptor(Ipv4OptionStreamIdDescriptor)

Ipv4OptionStreamIdDescriptor::Ipv4OptionStreamIdDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv4OptionStreamId)), "inet::Ipv4Option")
{
    propertynames = nullptr;
}

Ipv4OptionStreamIdDescriptor::~Ipv4OptionStreamIdDescriptor()
{
    delete[] propertynames;
}

bool Ipv4OptionStreamIdDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv4OptionStreamId *>(obj)!=nullptr;
}

const char **Ipv4OptionStreamIdDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv4OptionStreamIdDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv4OptionStreamIdDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ipv4OptionStreamIdDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_streamId
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ipv4OptionStreamIdDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "streamId",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ipv4OptionStreamIdDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "streamId") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv4OptionStreamIdDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_streamId
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv4OptionStreamIdDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv4OptionStreamIdDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv4OptionStreamIdDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionStreamId *pp = (Ipv4OptionStreamId *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv4OptionStreamIdDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionStreamId *pp = (Ipv4OptionStreamId *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv4OptionStreamIdDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionStreamId *pp = (Ipv4OptionStreamId *)object; (void)pp;
    switch (field) {
        case FIELD_streamId: return long2string(pp->getStreamId());
        default: return "";
    }
}

bool Ipv4OptionStreamIdDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionStreamId *pp = (Ipv4OptionStreamId *)object; (void)pp;
    switch (field) {
        case FIELD_streamId: pp->setStreamId(string2long(value)); return true;
        default: return false;
    }
}

const char *Ipv4OptionStreamIdDescriptor::getFieldStructName(int field) const
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

void *Ipv4OptionStreamIdDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionStreamId *pp = (Ipv4OptionStreamId *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv4OptionUnknown)

Ipv4OptionUnknown::Ipv4OptionUnknown() : ::inet::Ipv4Option()
{
}

Ipv4OptionUnknown::Ipv4OptionUnknown(const Ipv4OptionUnknown& other) : ::inet::Ipv4Option(other)
{
    copy(other);
}

Ipv4OptionUnknown::~Ipv4OptionUnknown()
{
    delete [] this->bytes;
}

Ipv4OptionUnknown& Ipv4OptionUnknown::operator=(const Ipv4OptionUnknown& other)
{
    if (this == &other) return *this;
    ::inet::Ipv4Option::operator=(other);
    copy(other);
    return *this;
}

void Ipv4OptionUnknown::copy(const Ipv4OptionUnknown& other)
{
    delete [] this->bytes;
    this->bytes = (other.bytes_arraysize==0) ? nullptr : new uint8_t[other.bytes_arraysize];
    bytes_arraysize = other.bytes_arraysize;
    for (size_t i = 0; i < bytes_arraysize; i++) {
        this->bytes[i] = other.bytes[i];
    }
}

void Ipv4OptionUnknown::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv4Option::parsimPack(b);
    b->pack(bytes_arraysize);
    doParsimArrayPacking(b,this->bytes,bytes_arraysize);
}

void Ipv4OptionUnknown::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv4Option::parsimUnpack(b);
    delete [] this->bytes;
    b->unpack(bytes_arraysize);
    if (bytes_arraysize == 0) {
        this->bytes = nullptr;
    } else {
        this->bytes = new uint8_t[bytes_arraysize];
        doParsimArrayUnpacking(b,this->bytes,bytes_arraysize);
    }
}

size_t Ipv4OptionUnknown::getBytesArraySize() const
{
    return bytes_arraysize;
}

uint8_t Ipv4OptionUnknown::getBytes(size_t k) const
{
    if (k >= bytes_arraysize) throw omnetpp::cRuntimeError("Array of size bytes_arraysize indexed by %lu", (unsigned long)k);
    return this->bytes[k];
}

void Ipv4OptionUnknown::setBytesArraySize(size_t newSize)
{
    uint8_t *bytes2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = bytes_arraysize < newSize ? bytes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        bytes2[i] = this->bytes[i];
    for (size_t i = minSize; i < newSize; i++)
        bytes2[i] = 0;
    delete [] this->bytes;
    this->bytes = bytes2;
    bytes_arraysize = newSize;
}

void Ipv4OptionUnknown::setBytes(size_t k, uint8_t bytes)
{
    if (k >= bytes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->bytes[k] = bytes;
}

void Ipv4OptionUnknown::insertBytes(size_t k, uint8_t bytes)
{
    if (k > bytes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = bytes_arraysize + 1;
    uint8_t *bytes2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        bytes2[i] = this->bytes[i];
    bytes2[k] = bytes;
    for (i = k + 1; i < newSize; i++)
        bytes2[i] = this->bytes[i-1];
    delete [] this->bytes;
    this->bytes = bytes2;
    bytes_arraysize = newSize;
}

void Ipv4OptionUnknown::insertBytes(uint8_t bytes)
{
    insertBytes(bytes_arraysize, bytes);
}

void Ipv4OptionUnknown::eraseBytes(size_t k)
{
    if (k >= bytes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = bytes_arraysize - 1;
    uint8_t *bytes2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        bytes2[i] = this->bytes[i];
    for (i = k; i < newSize; i++)
        bytes2[i] = this->bytes[i+1];
    delete [] this->bytes;
    this->bytes = bytes2;
    bytes_arraysize = newSize;
}

class Ipv4OptionUnknownDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_bytes,
    };
  public:
    Ipv4OptionUnknownDescriptor();
    virtual ~Ipv4OptionUnknownDescriptor();

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

Register_ClassDescriptor(Ipv4OptionUnknownDescriptor)

Ipv4OptionUnknownDescriptor::Ipv4OptionUnknownDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv4OptionUnknown)), "inet::Ipv4Option")
{
    propertynames = nullptr;
}

Ipv4OptionUnknownDescriptor::~Ipv4OptionUnknownDescriptor()
{
    delete[] propertynames;
}

bool Ipv4OptionUnknownDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv4OptionUnknown *>(obj)!=nullptr;
}

const char **Ipv4OptionUnknownDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv4OptionUnknownDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv4OptionUnknownDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ipv4OptionUnknownDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_bytes
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ipv4OptionUnknownDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bytes",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ipv4OptionUnknownDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bytes") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv4OptionUnknownDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_bytes
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv4OptionUnknownDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv4OptionUnknownDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv4OptionUnknownDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionUnknown *pp = (Ipv4OptionUnknown *)object; (void)pp;
    switch (field) {
        case FIELD_bytes: return pp->getBytesArraySize();
        default: return 0;
    }
}

const char *Ipv4OptionUnknownDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionUnknown *pp = (Ipv4OptionUnknown *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv4OptionUnknownDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionUnknown *pp = (Ipv4OptionUnknown *)object; (void)pp;
    switch (field) {
        case FIELD_bytes: return ulong2string(pp->getBytes(i));
        default: return "";
    }
}

bool Ipv4OptionUnknownDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionUnknown *pp = (Ipv4OptionUnknown *)object; (void)pp;
    switch (field) {
        case FIELD_bytes: pp->setBytes(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ipv4OptionUnknownDescriptor::getFieldStructName(int field) const
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

void *Ipv4OptionUnknownDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv4OptionUnknown *pp = (Ipv4OptionUnknown *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv4Header)

Ipv4Header::Ipv4Header() : ::inet::NetworkHeaderBase()
{
    this->setChunkLength(IPv4_MIN_HEADER_LENGTH);

}

Ipv4Header::Ipv4Header(const Ipv4Header& other) : ::inet::NetworkHeaderBase(other)
{
    copy(other);
}

Ipv4Header::~Ipv4Header()
{
}

Ipv4Header& Ipv4Header::operator=(const Ipv4Header& other)
{
    if (this == &other) return *this;
    ::inet::NetworkHeaderBase::operator=(other);
    copy(other);
    return *this;
}

void Ipv4Header::copy(const Ipv4Header& other)
{
    this->version = other.version;
    this->headerLength = other.headerLength;
    this->srcAddress = other.srcAddress;
    this->destAddress = other.destAddress;
    this->crc = other.crc;
    this->crcMode = other.crcMode;
    this->protocolId = other.protocolId;
    this->timeToLive = other.timeToLive;
    this->identification = other.identification;
    this->moreFragments = other.moreFragments;
    this->dontFragment = other.dontFragment;
    this->fragmentOffset = other.fragmentOffset;
    this->totalLengthField = other.totalLengthField;
    this->diffServCodePoint = other.diffServCodePoint;
    this->explicitCongestionNotification = other.explicitCongestionNotification;
    this->options = other.options;
}

void Ipv4Header::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::NetworkHeaderBase::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->headerLength);
    doParsimPacking(b,this->srcAddress);
    doParsimPacking(b,this->destAddress);
    doParsimPacking(b,this->crc);
    doParsimPacking(b,this->crcMode);
    doParsimPacking(b,this->protocolId);
    doParsimPacking(b,this->timeToLive);
    doParsimPacking(b,this->identification);
    doParsimPacking(b,this->moreFragments);
    doParsimPacking(b,this->dontFragment);
    doParsimPacking(b,this->fragmentOffset);
    doParsimPacking(b,this->totalLengthField);
    doParsimPacking(b,this->diffServCodePoint);
    doParsimPacking(b,this->explicitCongestionNotification);
    doParsimPacking(b,this->options);
}

void Ipv4Header::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::NetworkHeaderBase::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->headerLength);
    doParsimUnpacking(b,this->srcAddress);
    doParsimUnpacking(b,this->destAddress);
    doParsimUnpacking(b,this->crc);
    doParsimUnpacking(b,this->crcMode);
    doParsimUnpacking(b,this->protocolId);
    doParsimUnpacking(b,this->timeToLive);
    doParsimUnpacking(b,this->identification);
    doParsimUnpacking(b,this->moreFragments);
    doParsimUnpacking(b,this->dontFragment);
    doParsimUnpacking(b,this->fragmentOffset);
    doParsimUnpacking(b,this->totalLengthField);
    doParsimUnpacking(b,this->diffServCodePoint);
    doParsimUnpacking(b,this->explicitCongestionNotification);
    doParsimUnpacking(b,this->options);
}

short Ipv4Header::getVersion() const
{
    return this->version;
}

void Ipv4Header::setVersion(short version)
{
    handleChange();
    this->version = version;
}

B Ipv4Header::getHeaderLength() const
{
    return this->headerLength;
}

void Ipv4Header::setHeaderLength(B headerLength)
{
    handleChange();
    this->headerLength = headerLength;
}

const Ipv4Address& Ipv4Header::getSrcAddress() const
{
    return this->srcAddress;
}

void Ipv4Header::setSrcAddress(const Ipv4Address& srcAddress)
{
    handleChange();
    this->srcAddress = srcAddress;
}

const Ipv4Address& Ipv4Header::getDestAddress() const
{
    return this->destAddress;
}

void Ipv4Header::setDestAddress(const Ipv4Address& destAddress)
{
    handleChange();
    this->destAddress = destAddress;
}

uint16_t Ipv4Header::getCrc() const
{
    return this->crc;
}

void Ipv4Header::setCrc(uint16_t crc)
{
    handleChange();
    this->crc = crc;
}

inet::CrcMode Ipv4Header::getCrcMode() const
{
    return this->crcMode;
}

void Ipv4Header::setCrcMode(inet::CrcMode crcMode)
{
    handleChange();
    this->crcMode = crcMode;
}

inet::IpProtocolId Ipv4Header::getProtocolId() const
{
    return this->protocolId;
}

void Ipv4Header::setProtocolId(inet::IpProtocolId protocolId)
{
    handleChange();
    this->protocolId = protocolId;
}

short Ipv4Header::getTimeToLive() const
{
    return this->timeToLive;
}

void Ipv4Header::setTimeToLive(short timeToLive)
{
    handleChange();
    this->timeToLive = timeToLive;
}

int Ipv4Header::getIdentification() const
{
    return this->identification;
}

void Ipv4Header::setIdentification(int identification)
{
    handleChange();
    this->identification = identification;
}

bool Ipv4Header::getMoreFragments() const
{
    return this->moreFragments;
}

void Ipv4Header::setMoreFragments(bool moreFragments)
{
    handleChange();
    this->moreFragments = moreFragments;
}

bool Ipv4Header::getDontFragment() const
{
    return this->dontFragment;
}

void Ipv4Header::setDontFragment(bool dontFragment)
{
    handleChange();
    this->dontFragment = dontFragment;
}

int Ipv4Header::getFragmentOffset() const
{
    return this->fragmentOffset;
}

void Ipv4Header::setFragmentOffset(int fragmentOffset)
{
    handleChange();
    this->fragmentOffset = fragmentOffset;
}

B Ipv4Header::getTotalLengthField() const
{
    return this->totalLengthField;
}

void Ipv4Header::setTotalLengthField(B totalLengthField)
{
    handleChange();
    this->totalLengthField = totalLengthField;
}

short Ipv4Header::getDiffServCodePoint() const
{
    return this->diffServCodePoint;
}

void Ipv4Header::setDiffServCodePoint(short diffServCodePoint)
{
    handleChange();
    this->diffServCodePoint = diffServCodePoint;
}

short Ipv4Header::getExplicitCongestionNotification() const
{
    return this->explicitCongestionNotification;
}

void Ipv4Header::setExplicitCongestionNotification(short explicitCongestionNotification)
{
    handleChange();
    this->explicitCongestionNotification = explicitCongestionNotification;
}

const TlvOptions& Ipv4Header::getOptions() const
{
    return this->options;
}

void Ipv4Header::setOptions(const TlvOptions& options)
{
    handleChange();
    this->options = options;
}

class Ipv4HeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_version,
        FIELD_headerLength,
        FIELD_srcAddress,
        FIELD_destAddress,
        FIELD_crc,
        FIELD_crcMode,
        FIELD_protocolId,
        FIELD_timeToLive,
        FIELD_identification,
        FIELD_moreFragments,
        FIELD_dontFragment,
        FIELD_fragmentOffset,
        FIELD_totalLengthField,
        FIELD_diffServCodePoint,
        FIELD_explicitCongestionNotification,
        FIELD_options,
    };
  public:
    Ipv4HeaderDescriptor();
    virtual ~Ipv4HeaderDescriptor();

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

Register_ClassDescriptor(Ipv4HeaderDescriptor)

Ipv4HeaderDescriptor::Ipv4HeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv4Header)), "inet::NetworkHeaderBase")
{
    propertynames = nullptr;
}

Ipv4HeaderDescriptor::~Ipv4HeaderDescriptor()
{
    delete[] propertynames;
}

bool Ipv4HeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv4Header *>(obj)!=nullptr;
}

const char **Ipv4HeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv4HeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv4HeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 16+basedesc->getFieldCount() : 16;
}

unsigned int Ipv4HeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_version
        FD_ISEDITABLE,    // FIELD_headerLength
        0,    // FIELD_srcAddress
        0,    // FIELD_destAddress
        FD_ISEDITABLE,    // FIELD_crc
        0,    // FIELD_crcMode
        0,    // FIELD_protocolId
        FD_ISEDITABLE,    // FIELD_timeToLive
        FD_ISEDITABLE,    // FIELD_identification
        FD_ISEDITABLE,    // FIELD_moreFragments
        FD_ISEDITABLE,    // FIELD_dontFragment
        FD_ISEDITABLE,    // FIELD_fragmentOffset
        FD_ISEDITABLE,    // FIELD_totalLengthField
        FD_ISEDITABLE,    // FIELD_diffServCodePoint
        FD_ISEDITABLE,    // FIELD_explicitCongestionNotification
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_options
    };
    return (field >= 0 && field < 16) ? fieldTypeFlags[field] : 0;
}

const char *Ipv4HeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "headerLength",
        "srcAddress",
        "destAddress",
        "crc",
        "crcMode",
        "protocolId",
        "timeToLive",
        "identification",
        "moreFragments",
        "dontFragment",
        "fragmentOffset",
        "totalLengthField",
        "diffServCodePoint",
        "explicitCongestionNotification",
        "options",
    };
    return (field >= 0 && field < 16) ? fieldNames[field] : nullptr;
}

int Ipv4HeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "version") == 0) return base+0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "headerLength") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "srcAddress") == 0) return base+2;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destAddress") == 0) return base+3;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crc") == 0) return base+4;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crcMode") == 0) return base+5;
    if (fieldName[0] == 'p' && strcmp(fieldName, "protocolId") == 0) return base+6;
    if (fieldName[0] == 't' && strcmp(fieldName, "timeToLive") == 0) return base+7;
    if (fieldName[0] == 'i' && strcmp(fieldName, "identification") == 0) return base+8;
    if (fieldName[0] == 'm' && strcmp(fieldName, "moreFragments") == 0) return base+9;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dontFragment") == 0) return base+10;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fragmentOffset") == 0) return base+11;
    if (fieldName[0] == 't' && strcmp(fieldName, "totalLengthField") == 0) return base+12;
    if (fieldName[0] == 'd' && strcmp(fieldName, "diffServCodePoint") == 0) return base+13;
    if (fieldName[0] == 'e' && strcmp(fieldName, "explicitCongestionNotification") == 0) return base+14;
    if (fieldName[0] == 'o' && strcmp(fieldName, "options") == 0) return base+15;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv4HeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_version
        "inet::B",    // FIELD_headerLength
        "inet::Ipv4Address",    // FIELD_srcAddress
        "inet::Ipv4Address",    // FIELD_destAddress
        "uint16_t",    // FIELD_crc
        "inet::CrcMode",    // FIELD_crcMode
        "inet::IpProtocolId",    // FIELD_protocolId
        "short",    // FIELD_timeToLive
        "int",    // FIELD_identification
        "bool",    // FIELD_moreFragments
        "bool",    // FIELD_dontFragment
        "int",    // FIELD_fragmentOffset
        "inet::B",    // FIELD_totalLengthField
        "short",    // FIELD_diffServCodePoint
        "short",    // FIELD_explicitCongestionNotification
        "inet::TlvOptions",    // FIELD_options
    };
    return (field >= 0 && field < 16) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv4HeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_crcMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_protocolId: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ipv4HeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_crcMode:
            if (!strcmp(propertyname, "enum")) return "inet::CrcMode";
            return nullptr;
        case FIELD_protocolId:
            if (!strcmp(propertyname, "enum")) return "inet::IpProtocolId";
            return nullptr;
        default: return nullptr;
    }
}

int Ipv4HeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv4Header *pp = (Ipv4Header *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv4HeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4Header *pp = (Ipv4Header *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv4HeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4Header *pp = (Ipv4Header *)object; (void)pp;
    switch (field) {
        case FIELD_version: return long2string(pp->getVersion());
        case FIELD_headerLength: return unit2string(pp->getHeaderLength());
        case FIELD_srcAddress: return pp->getSrcAddress().str();
        case FIELD_destAddress: return pp->getDestAddress().str();
        case FIELD_crc: return ulong2string(pp->getCrc());
        case FIELD_crcMode: return enum2string(pp->getCrcMode(), "inet::CrcMode");
        case FIELD_protocolId: return enum2string(pp->getProtocolId(), "inet::IpProtocolId");
        case FIELD_timeToLive: return long2string(pp->getTimeToLive());
        case FIELD_identification: return long2string(pp->getIdentification());
        case FIELD_moreFragments: return bool2string(pp->getMoreFragments());
        case FIELD_dontFragment: return bool2string(pp->getDontFragment());
        case FIELD_fragmentOffset: return long2string(pp->getFragmentOffset());
        case FIELD_totalLengthField: return unit2string(pp->getTotalLengthField());
        case FIELD_diffServCodePoint: return long2string(pp->getDiffServCodePoint());
        case FIELD_explicitCongestionNotification: return long2string(pp->getExplicitCongestionNotification());
        case FIELD_options: {std::stringstream out; out << pp->getOptions(); return out.str();}
        default: return "";
    }
}

bool Ipv4HeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv4Header *pp = (Ipv4Header *)object; (void)pp;
    switch (field) {
        case FIELD_version: pp->setVersion(string2long(value)); return true;
        case FIELD_headerLength: pp->setHeaderLength(B(string2long(value))); return true;
        case FIELD_crc: pp->setCrc(string2ulong(value)); return true;
        case FIELD_timeToLive: pp->setTimeToLive(string2long(value)); return true;
        case FIELD_identification: pp->setIdentification(string2long(value)); return true;
        case FIELD_moreFragments: pp->setMoreFragments(string2bool(value)); return true;
        case FIELD_dontFragment: pp->setDontFragment(string2bool(value)); return true;
        case FIELD_fragmentOffset: pp->setFragmentOffset(string2long(value)); return true;
        case FIELD_totalLengthField: pp->setTotalLengthField(B(string2long(value))); return true;
        case FIELD_diffServCodePoint: pp->setDiffServCodePoint(string2long(value)); return true;
        case FIELD_explicitCongestionNotification: pp->setExplicitCongestionNotification(string2long(value)); return true;
        default: return false;
    }
}

const char *Ipv4HeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options: return omnetpp::opp_typename(typeid(TlvOptions));
        default: return nullptr;
    };
}

void *Ipv4HeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv4Header *pp = (Ipv4Header *)object; (void)pp;
    switch (field) {
        case FIELD_srcAddress: return toVoidPtr(&pp->getSrcAddress()); break;
        case FIELD_destAddress: return toVoidPtr(&pp->getDestAddress()); break;
        case FIELD_options: return toVoidPtr(&pp->getOptions()); break;
        default: return nullptr;
    }
}

} // namespace inet

