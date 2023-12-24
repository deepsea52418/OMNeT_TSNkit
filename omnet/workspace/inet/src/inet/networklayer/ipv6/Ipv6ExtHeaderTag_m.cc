//
// Generated file, do not edit! Created by nedtool 5.6 from inet/networklayer/ipv6/Ipv6ExtHeaderTag.msg.
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
#include "Ipv6ExtHeaderTag_m.h"

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

Register_Class(Ipv6ExtHeaderTagBase)

Ipv6ExtHeaderTagBase::Ipv6ExtHeaderTagBase() : ::omnetpp::cObject()
{
}

Ipv6ExtHeaderTagBase::Ipv6ExtHeaderTagBase(const Ipv6ExtHeaderTagBase& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

Ipv6ExtHeaderTagBase::~Ipv6ExtHeaderTagBase()
{
    for (size_t i = 0; i < extensionHeader_arraysize; i++)
        delete this->extensionHeader[i];
    delete [] this->extensionHeader;
}

Ipv6ExtHeaderTagBase& Ipv6ExtHeaderTagBase::operator=(const Ipv6ExtHeaderTagBase& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Ipv6ExtHeaderTagBase::copy(const Ipv6ExtHeaderTagBase& other)
{
    for (size_t i = 0; i < extensionHeader_arraysize; i++)
        delete this->extensionHeader[i];
    delete [] this->extensionHeader;
    this->extensionHeader = (other.extensionHeader_arraysize==0) ? nullptr : new Ipv6ExtensionHeader *[other.extensionHeader_arraysize];
    extensionHeader_arraysize = other.extensionHeader_arraysize;
    for (size_t i = 0; i < extensionHeader_arraysize; i++) {
        this->extensionHeader[i] = other.extensionHeader[i];
        if (this->extensionHeader[i] != nullptr) {
            this->extensionHeader[i] = this->extensionHeader[i]->dup();
        }
    }
}

void Ipv6ExtHeaderTagBase::parsimPack(omnetpp::cCommBuffer *b) const
{
    b->pack(extensionHeader_arraysize);
    doParsimArrayPacking(b,this->extensionHeader,extensionHeader_arraysize);
}

void Ipv6ExtHeaderTagBase::parsimUnpack(omnetpp::cCommBuffer *b)
{
    delete [] this->extensionHeader;
    b->unpack(extensionHeader_arraysize);
    if (extensionHeader_arraysize == 0) {
        this->extensionHeader = nullptr;
    } else {
        this->extensionHeader = new Ipv6ExtensionHeader *[extensionHeader_arraysize];
        doParsimArrayUnpacking(b,this->extensionHeader,extensionHeader_arraysize);
    }
}

size_t Ipv6ExtHeaderTagBase::getExtensionHeaderArraySize() const
{
    return extensionHeader_arraysize;
}

const Ipv6ExtensionHeader * Ipv6ExtHeaderTagBase::getExtensionHeader(size_t k) const
{
    if (k >= extensionHeader_arraysize) throw omnetpp::cRuntimeError("Array of size extensionHeader_arraysize indexed by %lu", (unsigned long)k);
    return this->extensionHeader[k];
}

void Ipv6ExtHeaderTagBase::setExtensionHeaderArraySize(size_t newSize)
{
    Ipv6ExtensionHeader * *extensionHeader2 = (newSize==0) ? nullptr : new Ipv6ExtensionHeader *[newSize];
    size_t minSize = extensionHeader_arraysize < newSize ? extensionHeader_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        extensionHeader2[i] = this->extensionHeader[i];
    for (size_t i = minSize; i < newSize; i++)
        extensionHeader2[i] = nullptr;
    for (size_t i = newSize; i < extensionHeader_arraysize; i++)
        delete extensionHeader[i];
    delete [] this->extensionHeader;
    this->extensionHeader = extensionHeader2;
    extensionHeader_arraysize = newSize;
}

void Ipv6ExtHeaderTagBase::setExtensionHeader(size_t k, Ipv6ExtensionHeader * extensionHeader)
{
    if (k >= extensionHeader_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    if (this->extensionHeader[k] != nullptr) throw omnetpp::cRuntimeError("setExtensionHeader(): a value is already set, remove it first with dropExtensionHeader()");
    this->extensionHeader[k] = extensionHeader;
}

Ipv6ExtensionHeader * Ipv6ExtHeaderTagBase::dropExtensionHeader(size_t k)
{
    if (k >= extensionHeader_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    Ipv6ExtensionHeader * retval = this->extensionHeader[k];
    this->extensionHeader[k] = nullptr;
    return retval;
}

void Ipv6ExtHeaderTagBase::insertExtensionHeader(size_t k, Ipv6ExtensionHeader * extensionHeader)
{
    if (k > extensionHeader_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = extensionHeader_arraysize + 1;
    Ipv6ExtensionHeader * *extensionHeader2 = new Ipv6ExtensionHeader *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        extensionHeader2[i] = this->extensionHeader[i];
    extensionHeader2[k] = extensionHeader;
    for (i = k + 1; i < newSize; i++)
        extensionHeader2[i] = this->extensionHeader[i-1];
    delete [] this->extensionHeader;
    this->extensionHeader = extensionHeader2;
    extensionHeader_arraysize = newSize;
}

void Ipv6ExtHeaderTagBase::insertExtensionHeader(Ipv6ExtensionHeader * extensionHeader)
{
    insertExtensionHeader(extensionHeader_arraysize, extensionHeader);
}

void Ipv6ExtHeaderTagBase::eraseExtensionHeader(size_t k)
{
    if (k >= extensionHeader_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = extensionHeader_arraysize - 1;
    Ipv6ExtensionHeader * *extensionHeader2 = (newSize == 0) ? nullptr : new Ipv6ExtensionHeader *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        extensionHeader2[i] = this->extensionHeader[i];
    for (i = k; i < newSize; i++)
        extensionHeader2[i] = this->extensionHeader[i+1];
    delete this->extensionHeader[k];
    delete [] this->extensionHeader;
    this->extensionHeader = extensionHeader2;
    extensionHeader_arraysize = newSize;
}

class Ipv6ExtHeaderTagBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_extensionHeader,
    };
  public:
    Ipv6ExtHeaderTagBaseDescriptor();
    virtual ~Ipv6ExtHeaderTagBaseDescriptor();

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

Register_ClassDescriptor(Ipv6ExtHeaderTagBaseDescriptor)

Ipv6ExtHeaderTagBaseDescriptor::Ipv6ExtHeaderTagBaseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6ExtHeaderTagBase)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ipv6ExtHeaderTagBaseDescriptor::~Ipv6ExtHeaderTagBaseDescriptor()
{
    delete[] propertynames;
}

bool Ipv6ExtHeaderTagBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6ExtHeaderTagBase *>(obj)!=nullptr;
}

const char **Ipv6ExtHeaderTagBaseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6ExtHeaderTagBaseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6ExtHeaderTagBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ipv6ExtHeaderTagBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_extensionHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6ExtHeaderTagBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "extensionHeader",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ipv6ExtHeaderTagBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'e' && strcmp(fieldName, "extensionHeader") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6ExtHeaderTagBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv6ExtensionHeader",    // FIELD_extensionHeader
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6ExtHeaderTagBaseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_extensionHeader: {
            static const char *names[] = { "owned",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ipv6ExtHeaderTagBaseDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_extensionHeader:
            if (!strcmp(propertyname, "owned")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int Ipv6ExtHeaderTagBaseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderTagBase *pp = (Ipv6ExtHeaderTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_extensionHeader: return pp->getExtensionHeaderArraySize();
        default: return 0;
    }
}

const char *Ipv6ExtHeaderTagBaseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderTagBase *pp = (Ipv6ExtHeaderTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_extensionHeader: { const Ipv6ExtensionHeader * value = pp->getExtensionHeader(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string Ipv6ExtHeaderTagBaseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderTagBase *pp = (Ipv6ExtHeaderTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_extensionHeader: {std::stringstream out; out << pp->getExtensionHeader(i); return out.str();}
        default: return "";
    }
}

bool Ipv6ExtHeaderTagBaseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderTagBase *pp = (Ipv6ExtHeaderTagBase *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv6ExtHeaderTagBaseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_extensionHeader: return omnetpp::opp_typename(typeid(Ipv6ExtensionHeader));
        default: return nullptr;
    };
}

void *Ipv6ExtHeaderTagBaseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderTagBase *pp = (Ipv6ExtHeaderTagBase *)object; (void)pp;
    switch (field) {
        case FIELD_extensionHeader: return toVoidPtr(pp->getExtensionHeader(i)); break;
        default: return nullptr;
    }
}

Register_Class(Ipv6ExtHeaderReq)

Ipv6ExtHeaderReq::Ipv6ExtHeaderReq() : ::inet::Ipv6ExtHeaderTagBase()
{
}

Ipv6ExtHeaderReq::Ipv6ExtHeaderReq(const Ipv6ExtHeaderReq& other) : ::inet::Ipv6ExtHeaderTagBase(other)
{
    copy(other);
}

Ipv6ExtHeaderReq::~Ipv6ExtHeaderReq()
{
}

Ipv6ExtHeaderReq& Ipv6ExtHeaderReq::operator=(const Ipv6ExtHeaderReq& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6ExtHeaderTagBase::operator=(other);
    copy(other);
    return *this;
}

void Ipv6ExtHeaderReq::copy(const Ipv6ExtHeaderReq& other)
{
}

void Ipv6ExtHeaderReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6ExtHeaderTagBase::parsimPack(b);
}

void Ipv6ExtHeaderReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6ExtHeaderTagBase::parsimUnpack(b);
}

class Ipv6ExtHeaderReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ipv6ExtHeaderReqDescriptor();
    virtual ~Ipv6ExtHeaderReqDescriptor();

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

Register_ClassDescriptor(Ipv6ExtHeaderReqDescriptor)

Ipv6ExtHeaderReqDescriptor::Ipv6ExtHeaderReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6ExtHeaderReq)), "inet::Ipv6ExtHeaderTagBase")
{
    propertynames = nullptr;
}

Ipv6ExtHeaderReqDescriptor::~Ipv6ExtHeaderReqDescriptor()
{
    delete[] propertynames;
}

bool Ipv6ExtHeaderReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6ExtHeaderReq *>(obj)!=nullptr;
}

const char **Ipv6ExtHeaderReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6ExtHeaderReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6ExtHeaderReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ipv6ExtHeaderReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ipv6ExtHeaderReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ipv6ExtHeaderReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6ExtHeaderReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ipv6ExtHeaderReqDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv6ExtHeaderReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv6ExtHeaderReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderReq *pp = (Ipv6ExtHeaderReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6ExtHeaderReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderReq *pp = (Ipv6ExtHeaderReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6ExtHeaderReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderReq *pp = (Ipv6ExtHeaderReq *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ipv6ExtHeaderReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderReq *pp = (Ipv6ExtHeaderReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv6ExtHeaderReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ipv6ExtHeaderReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderReq *pp = (Ipv6ExtHeaderReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv6ExtHeaderInd)

Ipv6ExtHeaderInd::Ipv6ExtHeaderInd() : ::inet::Ipv6ExtHeaderTagBase()
{
}

Ipv6ExtHeaderInd::Ipv6ExtHeaderInd(const Ipv6ExtHeaderInd& other) : ::inet::Ipv6ExtHeaderTagBase(other)
{
    copy(other);
}

Ipv6ExtHeaderInd::~Ipv6ExtHeaderInd()
{
}

Ipv6ExtHeaderInd& Ipv6ExtHeaderInd::operator=(const Ipv6ExtHeaderInd& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6ExtHeaderTagBase::operator=(other);
    copy(other);
    return *this;
}

void Ipv6ExtHeaderInd::copy(const Ipv6ExtHeaderInd& other)
{
}

void Ipv6ExtHeaderInd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6ExtHeaderTagBase::parsimPack(b);
}

void Ipv6ExtHeaderInd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6ExtHeaderTagBase::parsimUnpack(b);
}

class Ipv6ExtHeaderIndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ipv6ExtHeaderIndDescriptor();
    virtual ~Ipv6ExtHeaderIndDescriptor();

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

Register_ClassDescriptor(Ipv6ExtHeaderIndDescriptor)

Ipv6ExtHeaderIndDescriptor::Ipv6ExtHeaderIndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6ExtHeaderInd)), "inet::Ipv6ExtHeaderTagBase")
{
    propertynames = nullptr;
}

Ipv6ExtHeaderIndDescriptor::~Ipv6ExtHeaderIndDescriptor()
{
    delete[] propertynames;
}

bool Ipv6ExtHeaderIndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6ExtHeaderInd *>(obj)!=nullptr;
}

const char **Ipv6ExtHeaderIndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6ExtHeaderIndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6ExtHeaderIndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ipv6ExtHeaderIndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ipv6ExtHeaderIndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ipv6ExtHeaderIndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6ExtHeaderIndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ipv6ExtHeaderIndDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv6ExtHeaderIndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv6ExtHeaderIndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderInd *pp = (Ipv6ExtHeaderInd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6ExtHeaderIndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderInd *pp = (Ipv6ExtHeaderInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6ExtHeaderIndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderInd *pp = (Ipv6ExtHeaderInd *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ipv6ExtHeaderIndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderInd *pp = (Ipv6ExtHeaderInd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv6ExtHeaderIndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ipv6ExtHeaderIndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtHeaderInd *pp = (Ipv6ExtHeaderInd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

