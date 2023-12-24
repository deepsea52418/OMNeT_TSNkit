//
// Generated file, do not edit! Created by nedtool 5.6 from inet/physicallayer/common/packetlevel/SignalTag.msg.
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
#include "SignalTag_m.h"

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

Register_Class(SignalTagBase)

SignalTagBase::SignalTagBase() : ::inet::TagBase()
{
}

SignalTagBase::SignalTagBase(const SignalTagBase& other) : ::inet::TagBase(other)
{
    copy(other);
}

SignalTagBase::~SignalTagBase()
{
}

SignalTagBase& SignalTagBase::operator=(const SignalTagBase& other)
{
    if (this == &other) return *this;
    ::inet::TagBase::operator=(other);
    copy(other);
    return *this;
}

void SignalTagBase::copy(const SignalTagBase& other)
{
}

void SignalTagBase::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TagBase::parsimPack(b);
}

void SignalTagBase::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TagBase::parsimUnpack(b);
}

class SignalTagBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    SignalTagBaseDescriptor();
    virtual ~SignalTagBaseDescriptor();

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

Register_ClassDescriptor(SignalTagBaseDescriptor)

SignalTagBaseDescriptor::SignalTagBaseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SignalTagBase)), "inet::TagBase")
{
    propertynames = nullptr;
}

SignalTagBaseDescriptor::~SignalTagBaseDescriptor()
{
    delete[] propertynames;
}

bool SignalTagBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SignalTagBase *>(obj)!=nullptr;
}

const char **SignalTagBaseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SignalTagBaseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SignalTagBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int SignalTagBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *SignalTagBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int SignalTagBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SignalTagBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **SignalTagBaseDescriptor::getFieldPropertyNames(int field) const
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

const char *SignalTagBaseDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SignalTagBaseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SignalTagBase *pp = (SignalTagBase *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SignalTagBaseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalTagBase *pp = (SignalTagBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SignalTagBaseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalTagBase *pp = (SignalTagBase *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SignalTagBaseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SignalTagBase *pp = (SignalTagBase *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SignalTagBaseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *SignalTagBaseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SignalTagBase *pp = (SignalTagBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SignalPowerTagBase)

SignalPowerTagBase::SignalPowerTagBase() : ::inet::SignalTagBase()
{
}

SignalPowerTagBase::SignalPowerTagBase(const SignalPowerTagBase& other) : ::inet::SignalTagBase(other)
{
    copy(other);
}

SignalPowerTagBase::~SignalPowerTagBase()
{
}

SignalPowerTagBase& SignalPowerTagBase::operator=(const SignalPowerTagBase& other)
{
    if (this == &other) return *this;
    ::inet::SignalTagBase::operator=(other);
    copy(other);
    return *this;
}

void SignalPowerTagBase::copy(const SignalPowerTagBase& other)
{
    this->power = other.power;
}

void SignalPowerTagBase::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignalTagBase::parsimPack(b);
    doParsimPacking(b,this->power);
}

void SignalPowerTagBase::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignalTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->power);
}

W SignalPowerTagBase::getPower() const
{
    return this->power;
}

void SignalPowerTagBase::setPower(W power)
{
    this->power = power;
}

class SignalPowerTagBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_power,
    };
  public:
    SignalPowerTagBaseDescriptor();
    virtual ~SignalPowerTagBaseDescriptor();

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

Register_ClassDescriptor(SignalPowerTagBaseDescriptor)

SignalPowerTagBaseDescriptor::SignalPowerTagBaseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SignalPowerTagBase)), "inet::SignalTagBase")
{
    propertynames = nullptr;
}

SignalPowerTagBaseDescriptor::~SignalPowerTagBaseDescriptor()
{
    delete[] propertynames;
}

bool SignalPowerTagBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SignalPowerTagBase *>(obj)!=nullptr;
}

const char **SignalPowerTagBaseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SignalPowerTagBaseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SignalPowerTagBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SignalPowerTagBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_power
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SignalPowerTagBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "power",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SignalPowerTagBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "power") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SignalPowerTagBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::W",    // FIELD_power
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SignalPowerTagBaseDescriptor::getFieldPropertyNames(int field) const
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

const char *SignalPowerTagBaseDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SignalPowerTagBaseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SignalPowerTagBase *pp = (SignalPowerTagBase *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SignalPowerTagBaseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalPowerTagBase *pp = (SignalPowerTagBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SignalPowerTagBaseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalPowerTagBase *pp = (SignalPowerTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_power: return unit2string(pp->getPower());
        default: return "";
    }
}

bool SignalPowerTagBaseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SignalPowerTagBase *pp = (SignalPowerTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_power: pp->setPower(W(string2double(value))); return true;
        default: return false;
    }
}

const char *SignalPowerTagBaseDescriptor::getFieldStructName(int field) const
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

void *SignalPowerTagBaseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SignalPowerTagBase *pp = (SignalPowerTagBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SignalPowerReq)

SignalPowerReq::SignalPowerReq() : ::inet::SignalPowerTagBase()
{
}

SignalPowerReq::SignalPowerReq(const SignalPowerReq& other) : ::inet::SignalPowerTagBase(other)
{
    copy(other);
}

SignalPowerReq::~SignalPowerReq()
{
}

SignalPowerReq& SignalPowerReq::operator=(const SignalPowerReq& other)
{
    if (this == &other) return *this;
    ::inet::SignalPowerTagBase::operator=(other);
    copy(other);
    return *this;
}

void SignalPowerReq::copy(const SignalPowerReq& other)
{
}

void SignalPowerReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignalPowerTagBase::parsimPack(b);
}

void SignalPowerReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignalPowerTagBase::parsimUnpack(b);
}

class SignalPowerReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    SignalPowerReqDescriptor();
    virtual ~SignalPowerReqDescriptor();

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

Register_ClassDescriptor(SignalPowerReqDescriptor)

SignalPowerReqDescriptor::SignalPowerReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SignalPowerReq)), "inet::SignalPowerTagBase")
{
    propertynames = nullptr;
}

SignalPowerReqDescriptor::~SignalPowerReqDescriptor()
{
    delete[] propertynames;
}

bool SignalPowerReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SignalPowerReq *>(obj)!=nullptr;
}

const char **SignalPowerReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SignalPowerReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SignalPowerReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int SignalPowerReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *SignalPowerReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int SignalPowerReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SignalPowerReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **SignalPowerReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SignalPowerReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SignalPowerReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SignalPowerReq *pp = (SignalPowerReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SignalPowerReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalPowerReq *pp = (SignalPowerReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SignalPowerReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalPowerReq *pp = (SignalPowerReq *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SignalPowerReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SignalPowerReq *pp = (SignalPowerReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SignalPowerReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *SignalPowerReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SignalPowerReq *pp = (SignalPowerReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SignalPowerInd)

SignalPowerInd::SignalPowerInd() : ::inet::SignalPowerTagBase()
{
}

SignalPowerInd::SignalPowerInd(const SignalPowerInd& other) : ::inet::SignalPowerTagBase(other)
{
    copy(other);
}

SignalPowerInd::~SignalPowerInd()
{
}

SignalPowerInd& SignalPowerInd::operator=(const SignalPowerInd& other)
{
    if (this == &other) return *this;
    ::inet::SignalPowerTagBase::operator=(other);
    copy(other);
    return *this;
}

void SignalPowerInd::copy(const SignalPowerInd& other)
{
}

void SignalPowerInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignalPowerTagBase::parsimPack(b);
}

void SignalPowerInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignalPowerTagBase::parsimUnpack(b);
}

class SignalPowerIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    SignalPowerIndDescriptor();
    virtual ~SignalPowerIndDescriptor();

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

Register_ClassDescriptor(SignalPowerIndDescriptor)

SignalPowerIndDescriptor::SignalPowerIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SignalPowerInd)), "inet::SignalPowerTagBase")
{
    propertynames = nullptr;
}

SignalPowerIndDescriptor::~SignalPowerIndDescriptor()
{
    delete[] propertynames;
}

bool SignalPowerIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SignalPowerInd *>(obj)!=nullptr;
}

const char **SignalPowerIndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SignalPowerIndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SignalPowerIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int SignalPowerIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *SignalPowerIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int SignalPowerIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SignalPowerIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **SignalPowerIndDescriptor::getFieldPropertyNames(int field) const
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

const char *SignalPowerIndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SignalPowerIndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SignalPowerInd *pp = (SignalPowerInd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SignalPowerIndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalPowerInd *pp = (SignalPowerInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SignalPowerIndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalPowerInd *pp = (SignalPowerInd *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SignalPowerIndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SignalPowerInd *pp = (SignalPowerInd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SignalPowerIndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *SignalPowerIndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SignalPowerInd *pp = (SignalPowerInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SignalBandTagBase)

SignalBandTagBase::SignalBandTagBase() : ::inet::SignalTagBase()
{
}

SignalBandTagBase::SignalBandTagBase(const SignalBandTagBase& other) : ::inet::SignalTagBase(other)
{
    copy(other);
}

SignalBandTagBase::~SignalBandTagBase()
{
}

SignalBandTagBase& SignalBandTagBase::operator=(const SignalBandTagBase& other)
{
    if (this == &other) return *this;
    ::inet::SignalTagBase::operator=(other);
    copy(other);
    return *this;
}

void SignalBandTagBase::copy(const SignalBandTagBase& other)
{
    this->carrierFrequency = other.carrierFrequency;
    this->bandwidth = other.bandwidth;
}

void SignalBandTagBase::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignalTagBase::parsimPack(b);
    doParsimPacking(b,this->carrierFrequency);
    doParsimPacking(b,this->bandwidth);
}

void SignalBandTagBase::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignalTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->carrierFrequency);
    doParsimUnpacking(b,this->bandwidth);
}

Hz SignalBandTagBase::getCarrierFrequency() const
{
    return this->carrierFrequency;
}

void SignalBandTagBase::setCarrierFrequency(Hz carrierFrequency)
{
    this->carrierFrequency = carrierFrequency;
}

Hz SignalBandTagBase::getBandwidth() const
{
    return this->bandwidth;
}

void SignalBandTagBase::setBandwidth(Hz bandwidth)
{
    this->bandwidth = bandwidth;
}

class SignalBandTagBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_carrierFrequency,
        FIELD_bandwidth,
    };
  public:
    SignalBandTagBaseDescriptor();
    virtual ~SignalBandTagBaseDescriptor();

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

Register_ClassDescriptor(SignalBandTagBaseDescriptor)

SignalBandTagBaseDescriptor::SignalBandTagBaseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SignalBandTagBase)), "inet::SignalTagBase")
{
    propertynames = nullptr;
}

SignalBandTagBaseDescriptor::~SignalBandTagBaseDescriptor()
{
    delete[] propertynames;
}

bool SignalBandTagBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SignalBandTagBase *>(obj)!=nullptr;
}

const char **SignalBandTagBaseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SignalBandTagBaseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SignalBandTagBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SignalBandTagBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_carrierFrequency
        FD_ISEDITABLE,    // FIELD_bandwidth
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *SignalBandTagBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "carrierFrequency",
        "bandwidth",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int SignalBandTagBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "carrierFrequency") == 0) return base+0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bandwidth") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SignalBandTagBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Hz",    // FIELD_carrierFrequency
        "inet::Hz",    // FIELD_bandwidth
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **SignalBandTagBaseDescriptor::getFieldPropertyNames(int field) const
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

const char *SignalBandTagBaseDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SignalBandTagBaseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SignalBandTagBase *pp = (SignalBandTagBase *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SignalBandTagBaseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalBandTagBase *pp = (SignalBandTagBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SignalBandTagBaseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalBandTagBase *pp = (SignalBandTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_carrierFrequency: return unit2string(pp->getCarrierFrequency());
        case FIELD_bandwidth: return unit2string(pp->getBandwidth());
        default: return "";
    }
}

bool SignalBandTagBaseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SignalBandTagBase *pp = (SignalBandTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_carrierFrequency: pp->setCarrierFrequency(Hz(string2double(value))); return true;
        case FIELD_bandwidth: pp->setBandwidth(Hz(string2double(value))); return true;
        default: return false;
    }
}

const char *SignalBandTagBaseDescriptor::getFieldStructName(int field) const
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

void *SignalBandTagBaseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SignalBandTagBase *pp = (SignalBandTagBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SignalBandReq)

SignalBandReq::SignalBandReq() : ::inet::SignalBandTagBase()
{
}

SignalBandReq::SignalBandReq(const SignalBandReq& other) : ::inet::SignalBandTagBase(other)
{
    copy(other);
}

SignalBandReq::~SignalBandReq()
{
}

SignalBandReq& SignalBandReq::operator=(const SignalBandReq& other)
{
    if (this == &other) return *this;
    ::inet::SignalBandTagBase::operator=(other);
    copy(other);
    return *this;
}

void SignalBandReq::copy(const SignalBandReq& other)
{
}

void SignalBandReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignalBandTagBase::parsimPack(b);
}

void SignalBandReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignalBandTagBase::parsimUnpack(b);
}

class SignalBandReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    SignalBandReqDescriptor();
    virtual ~SignalBandReqDescriptor();

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

Register_ClassDescriptor(SignalBandReqDescriptor)

SignalBandReqDescriptor::SignalBandReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SignalBandReq)), "inet::SignalBandTagBase")
{
    propertynames = nullptr;
}

SignalBandReqDescriptor::~SignalBandReqDescriptor()
{
    delete[] propertynames;
}

bool SignalBandReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SignalBandReq *>(obj)!=nullptr;
}

const char **SignalBandReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SignalBandReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SignalBandReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int SignalBandReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *SignalBandReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int SignalBandReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SignalBandReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **SignalBandReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SignalBandReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SignalBandReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SignalBandReq *pp = (SignalBandReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SignalBandReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalBandReq *pp = (SignalBandReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SignalBandReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalBandReq *pp = (SignalBandReq *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SignalBandReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SignalBandReq *pp = (SignalBandReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SignalBandReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *SignalBandReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SignalBandReq *pp = (SignalBandReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SignalBandInd)

SignalBandInd::SignalBandInd() : ::inet::SignalBandTagBase()
{
}

SignalBandInd::SignalBandInd(const SignalBandInd& other) : ::inet::SignalBandTagBase(other)
{
    copy(other);
}

SignalBandInd::~SignalBandInd()
{
}

SignalBandInd& SignalBandInd::operator=(const SignalBandInd& other)
{
    if (this == &other) return *this;
    ::inet::SignalBandTagBase::operator=(other);
    copy(other);
    return *this;
}

void SignalBandInd::copy(const SignalBandInd& other)
{
}

void SignalBandInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignalBandTagBase::parsimPack(b);
}

void SignalBandInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignalBandTagBase::parsimUnpack(b);
}

class SignalBandIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    SignalBandIndDescriptor();
    virtual ~SignalBandIndDescriptor();

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

Register_ClassDescriptor(SignalBandIndDescriptor)

SignalBandIndDescriptor::SignalBandIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SignalBandInd)), "inet::SignalBandTagBase")
{
    propertynames = nullptr;
}

SignalBandIndDescriptor::~SignalBandIndDescriptor()
{
    delete[] propertynames;
}

bool SignalBandIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SignalBandInd *>(obj)!=nullptr;
}

const char **SignalBandIndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SignalBandIndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SignalBandIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int SignalBandIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *SignalBandIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int SignalBandIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SignalBandIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **SignalBandIndDescriptor::getFieldPropertyNames(int field) const
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

const char *SignalBandIndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SignalBandIndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SignalBandInd *pp = (SignalBandInd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SignalBandIndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalBandInd *pp = (SignalBandInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SignalBandIndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalBandInd *pp = (SignalBandInd *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SignalBandIndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SignalBandInd *pp = (SignalBandInd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SignalBandIndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *SignalBandIndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SignalBandInd *pp = (SignalBandInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SignalBitrateTagBase)

SignalBitrateTagBase::SignalBitrateTagBase() : ::inet::SignalTagBase()
{
}

SignalBitrateTagBase::SignalBitrateTagBase(const SignalBitrateTagBase& other) : ::inet::SignalTagBase(other)
{
    copy(other);
}

SignalBitrateTagBase::~SignalBitrateTagBase()
{
}

SignalBitrateTagBase& SignalBitrateTagBase::operator=(const SignalBitrateTagBase& other)
{
    if (this == &other) return *this;
    ::inet::SignalTagBase::operator=(other);
    copy(other);
    return *this;
}

void SignalBitrateTagBase::copy(const SignalBitrateTagBase& other)
{
    this->preambleBitrate = other.preambleBitrate;
    this->headerBitrate = other.headerBitrate;
    this->dataBitrate = other.dataBitrate;
}

void SignalBitrateTagBase::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignalTagBase::parsimPack(b);
    doParsimPacking(b,this->preambleBitrate);
    doParsimPacking(b,this->headerBitrate);
    doParsimPacking(b,this->dataBitrate);
}

void SignalBitrateTagBase::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignalTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->preambleBitrate);
    doParsimUnpacking(b,this->headerBitrate);
    doParsimUnpacking(b,this->dataBitrate);
}

bps SignalBitrateTagBase::getPreambleBitrate() const
{
    return this->preambleBitrate;
}

void SignalBitrateTagBase::setPreambleBitrate(bps preambleBitrate)
{
    this->preambleBitrate = preambleBitrate;
}

bps SignalBitrateTagBase::getHeaderBitrate() const
{
    return this->headerBitrate;
}

void SignalBitrateTagBase::setHeaderBitrate(bps headerBitrate)
{
    this->headerBitrate = headerBitrate;
}

bps SignalBitrateTagBase::getDataBitrate() const
{
    return this->dataBitrate;
}

void SignalBitrateTagBase::setDataBitrate(bps dataBitrate)
{
    this->dataBitrate = dataBitrate;
}

class SignalBitrateTagBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_preambleBitrate,
        FIELD_headerBitrate,
        FIELD_dataBitrate,
    };
  public:
    SignalBitrateTagBaseDescriptor();
    virtual ~SignalBitrateTagBaseDescriptor();

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

Register_ClassDescriptor(SignalBitrateTagBaseDescriptor)

SignalBitrateTagBaseDescriptor::SignalBitrateTagBaseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SignalBitrateTagBase)), "inet::SignalTagBase")
{
    propertynames = nullptr;
}

SignalBitrateTagBaseDescriptor::~SignalBitrateTagBaseDescriptor()
{
    delete[] propertynames;
}

bool SignalBitrateTagBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SignalBitrateTagBase *>(obj)!=nullptr;
}

const char **SignalBitrateTagBaseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SignalBitrateTagBaseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SignalBitrateTagBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SignalBitrateTagBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_preambleBitrate
        FD_ISEDITABLE,    // FIELD_headerBitrate
        FD_ISEDITABLE,    // FIELD_dataBitrate
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SignalBitrateTagBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "preambleBitrate",
        "headerBitrate",
        "dataBitrate",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SignalBitrateTagBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "preambleBitrate") == 0) return base+0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "headerBitrate") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dataBitrate") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SignalBitrateTagBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bps",    // FIELD_preambleBitrate
        "inet::bps",    // FIELD_headerBitrate
        "inet::bps",    // FIELD_dataBitrate
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SignalBitrateTagBaseDescriptor::getFieldPropertyNames(int field) const
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

const char *SignalBitrateTagBaseDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SignalBitrateTagBaseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateTagBase *pp = (SignalBitrateTagBase *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SignalBitrateTagBaseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateTagBase *pp = (SignalBitrateTagBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SignalBitrateTagBaseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateTagBase *pp = (SignalBitrateTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_preambleBitrate: return unit2string(pp->getPreambleBitrate());
        case FIELD_headerBitrate: return unit2string(pp->getHeaderBitrate());
        case FIELD_dataBitrate: return unit2string(pp->getDataBitrate());
        default: return "";
    }
}

bool SignalBitrateTagBaseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateTagBase *pp = (SignalBitrateTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_preambleBitrate: pp->setPreambleBitrate(bps(string2double(value))); return true;
        case FIELD_headerBitrate: pp->setHeaderBitrate(bps(string2double(value))); return true;
        case FIELD_dataBitrate: pp->setDataBitrate(bps(string2double(value))); return true;
        default: return false;
    }
}

const char *SignalBitrateTagBaseDescriptor::getFieldStructName(int field) const
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

void *SignalBitrateTagBaseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateTagBase *pp = (SignalBitrateTagBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SignalBitrateReq)

SignalBitrateReq::SignalBitrateReq() : ::inet::SignalBitrateTagBase()
{
}

SignalBitrateReq::SignalBitrateReq(const SignalBitrateReq& other) : ::inet::SignalBitrateTagBase(other)
{
    copy(other);
}

SignalBitrateReq::~SignalBitrateReq()
{
}

SignalBitrateReq& SignalBitrateReq::operator=(const SignalBitrateReq& other)
{
    if (this == &other) return *this;
    ::inet::SignalBitrateTagBase::operator=(other);
    copy(other);
    return *this;
}

void SignalBitrateReq::copy(const SignalBitrateReq& other)
{
}

void SignalBitrateReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignalBitrateTagBase::parsimPack(b);
}

void SignalBitrateReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignalBitrateTagBase::parsimUnpack(b);
}

class SignalBitrateReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    SignalBitrateReqDescriptor();
    virtual ~SignalBitrateReqDescriptor();

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

Register_ClassDescriptor(SignalBitrateReqDescriptor)

SignalBitrateReqDescriptor::SignalBitrateReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SignalBitrateReq)), "inet::SignalBitrateTagBase")
{
    propertynames = nullptr;
}

SignalBitrateReqDescriptor::~SignalBitrateReqDescriptor()
{
    delete[] propertynames;
}

bool SignalBitrateReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SignalBitrateReq *>(obj)!=nullptr;
}

const char **SignalBitrateReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SignalBitrateReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SignalBitrateReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int SignalBitrateReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *SignalBitrateReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int SignalBitrateReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SignalBitrateReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **SignalBitrateReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SignalBitrateReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SignalBitrateReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateReq *pp = (SignalBitrateReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SignalBitrateReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateReq *pp = (SignalBitrateReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SignalBitrateReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateReq *pp = (SignalBitrateReq *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SignalBitrateReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateReq *pp = (SignalBitrateReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SignalBitrateReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *SignalBitrateReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateReq *pp = (SignalBitrateReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SignalBitrateInd)

SignalBitrateInd::SignalBitrateInd() : ::inet::SignalBitrateTagBase()
{
}

SignalBitrateInd::SignalBitrateInd(const SignalBitrateInd& other) : ::inet::SignalBitrateTagBase(other)
{
    copy(other);
}

SignalBitrateInd::~SignalBitrateInd()
{
}

SignalBitrateInd& SignalBitrateInd::operator=(const SignalBitrateInd& other)
{
    if (this == &other) return *this;
    ::inet::SignalBitrateTagBase::operator=(other);
    copy(other);
    return *this;
}

void SignalBitrateInd::copy(const SignalBitrateInd& other)
{
}

void SignalBitrateInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignalBitrateTagBase::parsimPack(b);
}

void SignalBitrateInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignalBitrateTagBase::parsimUnpack(b);
}

class SignalBitrateIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    SignalBitrateIndDescriptor();
    virtual ~SignalBitrateIndDescriptor();

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

Register_ClassDescriptor(SignalBitrateIndDescriptor)

SignalBitrateIndDescriptor::SignalBitrateIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SignalBitrateInd)), "inet::SignalBitrateTagBase")
{
    propertynames = nullptr;
}

SignalBitrateIndDescriptor::~SignalBitrateIndDescriptor()
{
    delete[] propertynames;
}

bool SignalBitrateIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SignalBitrateInd *>(obj)!=nullptr;
}

const char **SignalBitrateIndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SignalBitrateIndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SignalBitrateIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int SignalBitrateIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *SignalBitrateIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int SignalBitrateIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SignalBitrateIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **SignalBitrateIndDescriptor::getFieldPropertyNames(int field) const
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

const char *SignalBitrateIndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SignalBitrateIndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateInd *pp = (SignalBitrateInd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SignalBitrateIndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateInd *pp = (SignalBitrateInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SignalBitrateIndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateInd *pp = (SignalBitrateInd *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SignalBitrateIndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateInd *pp = (SignalBitrateInd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SignalBitrateIndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *SignalBitrateIndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SignalBitrateInd *pp = (SignalBitrateInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SnirInd)

SnirInd::SnirInd() : ::inet::SignalTagBase()
{
}

SnirInd::SnirInd(const SnirInd& other) : ::inet::SignalTagBase(other)
{
    copy(other);
}

SnirInd::~SnirInd()
{
}

SnirInd& SnirInd::operator=(const SnirInd& other)
{
    if (this == &other) return *this;
    ::inet::SignalTagBase::operator=(other);
    copy(other);
    return *this;
}

void SnirInd::copy(const SnirInd& other)
{
    this->minimumSnir = other.minimumSnir;
    this->maximumSnir = other.maximumSnir;
    this->averageSnir = other.averageSnir;
}

void SnirInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignalTagBase::parsimPack(b);
    doParsimPacking(b,this->minimumSnir);
    doParsimPacking(b,this->maximumSnir);
    doParsimPacking(b,this->averageSnir);
}

void SnirInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignalTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->minimumSnir);
    doParsimUnpacking(b,this->maximumSnir);
    doParsimUnpacking(b,this->averageSnir);
}

double SnirInd::getMinimumSnir() const
{
    return this->minimumSnir;
}

void SnirInd::setMinimumSnir(double minimumSnir)
{
    this->minimumSnir = minimumSnir;
}

double SnirInd::getMaximumSnir() const
{
    return this->maximumSnir;
}

void SnirInd::setMaximumSnir(double maximumSnir)
{
    this->maximumSnir = maximumSnir;
}

double SnirInd::getAverageSnir() const
{
    return this->averageSnir;
}

void SnirInd::setAverageSnir(double averageSnir)
{
    this->averageSnir = averageSnir;
}

class SnirIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_minimumSnir,
        FIELD_maximumSnir,
        FIELD_averageSnir,
    };
  public:
    SnirIndDescriptor();
    virtual ~SnirIndDescriptor();

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

Register_ClassDescriptor(SnirIndDescriptor)

SnirIndDescriptor::SnirIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SnirInd)), "inet::SignalTagBase")
{
    propertynames = nullptr;
}

SnirIndDescriptor::~SnirIndDescriptor()
{
    delete[] propertynames;
}

bool SnirIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SnirInd *>(obj)!=nullptr;
}

const char **SnirIndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SnirIndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SnirIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SnirIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_minimumSnir
        FD_ISEDITABLE,    // FIELD_maximumSnir
        FD_ISEDITABLE,    // FIELD_averageSnir
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SnirIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "minimumSnir",
        "maximumSnir",
        "averageSnir",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SnirIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "minimumSnir") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "maximumSnir") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "averageSnir") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SnirIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_minimumSnir
        "double",    // FIELD_maximumSnir
        "double",    // FIELD_averageSnir
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SnirIndDescriptor::getFieldPropertyNames(int field) const
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

const char *SnirIndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SnirIndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SnirInd *pp = (SnirInd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SnirIndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SnirInd *pp = (SnirInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SnirIndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SnirInd *pp = (SnirInd *)object; (void)pp;
    switch (field) {
        case FIELD_minimumSnir: return double2string(pp->getMinimumSnir());
        case FIELD_maximumSnir: return double2string(pp->getMaximumSnir());
        case FIELD_averageSnir: return double2string(pp->getAverageSnir());
        default: return "";
    }
}

bool SnirIndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SnirInd *pp = (SnirInd *)object; (void)pp;
    switch (field) {
        case FIELD_minimumSnir: pp->setMinimumSnir(string2double(value)); return true;
        case FIELD_maximumSnir: pp->setMaximumSnir(string2double(value)); return true;
        case FIELD_averageSnir: pp->setAverageSnir(string2double(value)); return true;
        default: return false;
    }
}

const char *SnirIndDescriptor::getFieldStructName(int field) const
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

void *SnirIndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SnirInd *pp = (SnirInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ErrorRateInd)

ErrorRateInd::ErrorRateInd() : ::inet::SignalTagBase()
{
}

ErrorRateInd::ErrorRateInd(const ErrorRateInd& other) : ::inet::SignalTagBase(other)
{
    copy(other);
}

ErrorRateInd::~ErrorRateInd()
{
}

ErrorRateInd& ErrorRateInd::operator=(const ErrorRateInd& other)
{
    if (this == &other) return *this;
    ::inet::SignalTagBase::operator=(other);
    copy(other);
    return *this;
}

void ErrorRateInd::copy(const ErrorRateInd& other)
{
    this->packetErrorRate = other.packetErrorRate;
    this->bitErrorRate = other.bitErrorRate;
    this->symbolErrorRate = other.symbolErrorRate;
}

void ErrorRateInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignalTagBase::parsimPack(b);
    doParsimPacking(b,this->packetErrorRate);
    doParsimPacking(b,this->bitErrorRate);
    doParsimPacking(b,this->symbolErrorRate);
}

void ErrorRateInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignalTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->packetErrorRate);
    doParsimUnpacking(b,this->bitErrorRate);
    doParsimUnpacking(b,this->symbolErrorRate);
}

double ErrorRateInd::getPacketErrorRate() const
{
    return this->packetErrorRate;
}

void ErrorRateInd::setPacketErrorRate(double packetErrorRate)
{
    this->packetErrorRate = packetErrorRate;
}

double ErrorRateInd::getBitErrorRate() const
{
    return this->bitErrorRate;
}

void ErrorRateInd::setBitErrorRate(double bitErrorRate)
{
    this->bitErrorRate = bitErrorRate;
}

double ErrorRateInd::getSymbolErrorRate() const
{
    return this->symbolErrorRate;
}

void ErrorRateInd::setSymbolErrorRate(double symbolErrorRate)
{
    this->symbolErrorRate = symbolErrorRate;
}

class ErrorRateIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_packetErrorRate,
        FIELD_bitErrorRate,
        FIELD_symbolErrorRate,
    };
  public:
    ErrorRateIndDescriptor();
    virtual ~ErrorRateIndDescriptor();

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

Register_ClassDescriptor(ErrorRateIndDescriptor)

ErrorRateIndDescriptor::ErrorRateIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ErrorRateInd)), "inet::SignalTagBase")
{
    propertynames = nullptr;
}

ErrorRateIndDescriptor::~ErrorRateIndDescriptor()
{
    delete[] propertynames;
}

bool ErrorRateIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ErrorRateInd *>(obj)!=nullptr;
}

const char **ErrorRateIndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ErrorRateIndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ErrorRateIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int ErrorRateIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_packetErrorRate
        FD_ISEDITABLE,    // FIELD_bitErrorRate
        FD_ISEDITABLE,    // FIELD_symbolErrorRate
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *ErrorRateIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetErrorRate",
        "bitErrorRate",
        "symbolErrorRate",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int ErrorRateIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "packetErrorRate") == 0) return base+0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bitErrorRate") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "symbolErrorRate") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ErrorRateIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_packetErrorRate
        "double",    // FIELD_bitErrorRate
        "double",    // FIELD_symbolErrorRate
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **ErrorRateIndDescriptor::getFieldPropertyNames(int field) const
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

const char *ErrorRateIndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int ErrorRateIndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ErrorRateInd *pp = (ErrorRateInd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ErrorRateIndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ErrorRateInd *pp = (ErrorRateInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ErrorRateIndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ErrorRateInd *pp = (ErrorRateInd *)object; (void)pp;
    switch (field) {
        case FIELD_packetErrorRate: return double2string(pp->getPacketErrorRate());
        case FIELD_bitErrorRate: return double2string(pp->getBitErrorRate());
        case FIELD_symbolErrorRate: return double2string(pp->getSymbolErrorRate());
        default: return "";
    }
}

bool ErrorRateIndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ErrorRateInd *pp = (ErrorRateInd *)object; (void)pp;
    switch (field) {
        case FIELD_packetErrorRate: pp->setPacketErrorRate(string2double(value)); return true;
        case FIELD_bitErrorRate: pp->setBitErrorRate(string2double(value)); return true;
        case FIELD_symbolErrorRate: pp->setSymbolErrorRate(string2double(value)); return true;
        default: return false;
    }
}

const char *ErrorRateIndDescriptor::getFieldStructName(int field) const
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

void *ErrorRateIndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ErrorRateInd *pp = (ErrorRateInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SignalTimeInd)

SignalTimeInd::SignalTimeInd() : ::inet::SignalTagBase()
{
}

SignalTimeInd::SignalTimeInd(const SignalTimeInd& other) : ::inet::SignalTagBase(other)
{
    copy(other);
}

SignalTimeInd::~SignalTimeInd()
{
}

SignalTimeInd& SignalTimeInd::operator=(const SignalTimeInd& other)
{
    if (this == &other) return *this;
    ::inet::SignalTagBase::operator=(other);
    copy(other);
    return *this;
}

void SignalTimeInd::copy(const SignalTimeInd& other)
{
    this->startTime = other.startTime;
    this->endTime = other.endTime;
}

void SignalTimeInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignalTagBase::parsimPack(b);
    doParsimPacking(b,this->startTime);
    doParsimPacking(b,this->endTime);
}

void SignalTimeInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignalTagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->startTime);
    doParsimUnpacking(b,this->endTime);
}

omnetpp::simtime_t SignalTimeInd::getStartTime() const
{
    return this->startTime;
}

void SignalTimeInd::setStartTime(omnetpp::simtime_t startTime)
{
    this->startTime = startTime;
}

omnetpp::simtime_t SignalTimeInd::getEndTime() const
{
    return this->endTime;
}

void SignalTimeInd::setEndTime(omnetpp::simtime_t endTime)
{
    this->endTime = endTime;
}

class SignalTimeIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_startTime,
        FIELD_endTime,
    };
  public:
    SignalTimeIndDescriptor();
    virtual ~SignalTimeIndDescriptor();

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

Register_ClassDescriptor(SignalTimeIndDescriptor)

SignalTimeIndDescriptor::SignalTimeIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SignalTimeInd)), "inet::SignalTagBase")
{
    propertynames = nullptr;
}

SignalTimeIndDescriptor::~SignalTimeIndDescriptor()
{
    delete[] propertynames;
}

bool SignalTimeIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SignalTimeInd *>(obj)!=nullptr;
}

const char **SignalTimeIndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SignalTimeIndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SignalTimeIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SignalTimeIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_startTime
        0,    // FIELD_endTime
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *SignalTimeIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "startTime",
        "endTime",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int SignalTimeIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "startTime") == 0) return base+0;
    if (fieldName[0] == 'e' && strcmp(fieldName, "endTime") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SignalTimeIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::simtime_t",    // FIELD_startTime
        "omnetpp::simtime_t",    // FIELD_endTime
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **SignalTimeIndDescriptor::getFieldPropertyNames(int field) const
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

const char *SignalTimeIndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SignalTimeIndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SignalTimeInd *pp = (SignalTimeInd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SignalTimeIndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalTimeInd *pp = (SignalTimeInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SignalTimeIndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignalTimeInd *pp = (SignalTimeInd *)object; (void)pp;
    switch (field) {
        case FIELD_startTime: return simtime2string(pp->getStartTime());
        case FIELD_endTime: return simtime2string(pp->getEndTime());
        default: return "";
    }
}

bool SignalTimeIndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SignalTimeInd *pp = (SignalTimeInd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SignalTimeIndDescriptor::getFieldStructName(int field) const
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

void *SignalTimeIndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SignalTimeInd *pp = (SignalTimeInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

