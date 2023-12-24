//
// Generated file, do not edit! Created by nedtool 5.6 from inet/networklayer/ipv6/Ipv6ExtensionHeaders.msg.
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
#include "Ipv6ExtensionHeaders_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Ipv6TlvOptionTypes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Ipv6TlvOptionTypes"));
    e->insert(IPv6TLVOPTION_NOP1, "IPv6TLVOPTION_NOP1");
    e->insert(IPv6TLVOPTION_NOPN, "IPv6TLVOPTION_NOPN");
    e->insert(IPv6TLVOPTION_TLV_GPSR, "IPv6TLVOPTION_TLV_GPSR");
)

Register_Class(Ipv6HopByHopOptionsHeader)

Ipv6HopByHopOptionsHeader::Ipv6HopByHopOptionsHeader() : ::inet::Ipv6ExtensionHeader()
{
    this->setExtensionType(IP_PROT_IPv6EXT_HOP);

}

Ipv6HopByHopOptionsHeader::Ipv6HopByHopOptionsHeader(const Ipv6HopByHopOptionsHeader& other) : ::inet::Ipv6ExtensionHeader(other)
{
    copy(other);
}

Ipv6HopByHopOptionsHeader::~Ipv6HopByHopOptionsHeader()
{
}

Ipv6HopByHopOptionsHeader& Ipv6HopByHopOptionsHeader::operator=(const Ipv6HopByHopOptionsHeader& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6ExtensionHeader::operator=(other);
    copy(other);
    return *this;
}

void Ipv6HopByHopOptionsHeader::copy(const Ipv6HopByHopOptionsHeader& other)
{
    this->tlvOptions = other.tlvOptions;
}

void Ipv6HopByHopOptionsHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6ExtensionHeader::parsimPack(b);
    doParsimPacking(b,this->tlvOptions);
}

void Ipv6HopByHopOptionsHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6ExtensionHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->tlvOptions);
}

const TlvOptions& Ipv6HopByHopOptionsHeader::getTlvOptions() const
{
    return this->tlvOptions;
}

void Ipv6HopByHopOptionsHeader::setTlvOptions(const TlvOptions& tlvOptions)
{
    this->tlvOptions = tlvOptions;
}

class Ipv6HopByHopOptionsHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tlvOptions,
    };
  public:
    Ipv6HopByHopOptionsHeaderDescriptor();
    virtual ~Ipv6HopByHopOptionsHeaderDescriptor();

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

Register_ClassDescriptor(Ipv6HopByHopOptionsHeaderDescriptor)

Ipv6HopByHopOptionsHeaderDescriptor::Ipv6HopByHopOptionsHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6HopByHopOptionsHeader)), "inet::Ipv6ExtensionHeader")
{
    propertynames = nullptr;
}

Ipv6HopByHopOptionsHeaderDescriptor::~Ipv6HopByHopOptionsHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ipv6HopByHopOptionsHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6HopByHopOptionsHeader *>(obj)!=nullptr;
}

const char **Ipv6HopByHopOptionsHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6HopByHopOptionsHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6HopByHopOptionsHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ipv6HopByHopOptionsHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_tlvOptions
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6HopByHopOptionsHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tlvOptions",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ipv6HopByHopOptionsHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tlvOptions") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6HopByHopOptionsHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::TlvOptions",    // FIELD_tlvOptions
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6HopByHopOptionsHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv6HopByHopOptionsHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv6HopByHopOptionsHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6HopByHopOptionsHeader *pp = (Ipv6HopByHopOptionsHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6HopByHopOptionsHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6HopByHopOptionsHeader *pp = (Ipv6HopByHopOptionsHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6HopByHopOptionsHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6HopByHopOptionsHeader *pp = (Ipv6HopByHopOptionsHeader *)object; (void)pp;
    switch (field) {
        case FIELD_tlvOptions: {std::stringstream out; out << pp->getTlvOptions(); return out.str();}
        default: return "";
    }
}

bool Ipv6HopByHopOptionsHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6HopByHopOptionsHeader *pp = (Ipv6HopByHopOptionsHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv6HopByHopOptionsHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_tlvOptions: return omnetpp::opp_typename(typeid(TlvOptions));
        default: return nullptr;
    };
}

void *Ipv6HopByHopOptionsHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6HopByHopOptionsHeader *pp = (Ipv6HopByHopOptionsHeader *)object; (void)pp;
    switch (field) {
        case FIELD_tlvOptions: return toVoidPtr(&pp->getTlvOptions()); break;
        default: return nullptr;
    }
}

Register_Class(Ipv6RoutingHeader)

Ipv6RoutingHeader::Ipv6RoutingHeader() : ::inet::Ipv6ExtensionHeader()
{
    this->setExtensionType(IP_PROT_IPv6EXT_ROUTING);
    this->setByteLength(B(8));

}

Ipv6RoutingHeader::Ipv6RoutingHeader(const Ipv6RoutingHeader& other) : ::inet::Ipv6ExtensionHeader(other)
{
    copy(other);
}

Ipv6RoutingHeader::~Ipv6RoutingHeader()
{
    delete [] this->address;
}

Ipv6RoutingHeader& Ipv6RoutingHeader::operator=(const Ipv6RoutingHeader& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6ExtensionHeader::operator=(other);
    copy(other);
    return *this;
}

void Ipv6RoutingHeader::copy(const Ipv6RoutingHeader& other)
{
    this->routingType = other.routingType;
    this->segmentsLeft = other.segmentsLeft;
    delete [] this->address;
    this->address = (other.address_arraysize==0) ? nullptr : new Ipv6Address[other.address_arraysize];
    address_arraysize = other.address_arraysize;
    for (size_t i = 0; i < address_arraysize; i++) {
        this->address[i] = other.address[i];
    }
}

void Ipv6RoutingHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6ExtensionHeader::parsimPack(b);
    doParsimPacking(b,this->routingType);
    doParsimPacking(b,this->segmentsLeft);
    b->pack(address_arraysize);
    doParsimArrayPacking(b,this->address,address_arraysize);
}

void Ipv6RoutingHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6ExtensionHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->routingType);
    doParsimUnpacking(b,this->segmentsLeft);
    delete [] this->address;
    b->unpack(address_arraysize);
    if (address_arraysize == 0) {
        this->address = nullptr;
    } else {
        this->address = new Ipv6Address[address_arraysize];
        doParsimArrayUnpacking(b,this->address,address_arraysize);
    }
}

uint8_t Ipv6RoutingHeader::getRoutingType() const
{
    return this->routingType;
}

void Ipv6RoutingHeader::setRoutingType(uint8_t routingType)
{
    this->routingType = routingType;
}

uint8_t Ipv6RoutingHeader::getSegmentsLeft() const
{
    return this->segmentsLeft;
}

void Ipv6RoutingHeader::setSegmentsLeft(uint8_t segmentsLeft)
{
    this->segmentsLeft = segmentsLeft;
}

size_t Ipv6RoutingHeader::getAddressArraySize() const
{
    return address_arraysize;
}

const Ipv6Address& Ipv6RoutingHeader::getAddress(size_t k) const
{
    if (k >= address_arraysize) throw omnetpp::cRuntimeError("Array of size address_arraysize indexed by %lu", (unsigned long)k);
    return this->address[k];
}

void Ipv6RoutingHeader::setAddressArraySize(size_t newSize)
{
    Ipv6Address *address2 = (newSize==0) ? nullptr : new Ipv6Address[newSize];
    size_t minSize = address_arraysize < newSize ? address_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        address2[i] = this->address[i];
    delete [] this->address;
    this->address = address2;
    address_arraysize = newSize;
}

void Ipv6RoutingHeader::setAddress(size_t k, const Ipv6Address& address)
{
    if (k >= address_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->address[k] = address;
}

void Ipv6RoutingHeader::insertAddress(size_t k, const Ipv6Address& address)
{
    if (k > address_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = address_arraysize + 1;
    Ipv6Address *address2 = new Ipv6Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        address2[i] = this->address[i];
    address2[k] = address;
    for (i = k + 1; i < newSize; i++)
        address2[i] = this->address[i-1];
    delete [] this->address;
    this->address = address2;
    address_arraysize = newSize;
}

void Ipv6RoutingHeader::insertAddress(const Ipv6Address& address)
{
    insertAddress(address_arraysize, address);
}

void Ipv6RoutingHeader::eraseAddress(size_t k)
{
    if (k >= address_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = address_arraysize - 1;
    Ipv6Address *address2 = (newSize == 0) ? nullptr : new Ipv6Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        address2[i] = this->address[i];
    for (i = k; i < newSize; i++)
        address2[i] = this->address[i+1];
    delete [] this->address;
    this->address = address2;
    address_arraysize = newSize;
}

class Ipv6RoutingHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_routingType,
        FIELD_segmentsLeft,
        FIELD_address,
    };
  public:
    Ipv6RoutingHeaderDescriptor();
    virtual ~Ipv6RoutingHeaderDescriptor();

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

Register_ClassDescriptor(Ipv6RoutingHeaderDescriptor)

Ipv6RoutingHeaderDescriptor::Ipv6RoutingHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6RoutingHeader)), "inet::Ipv6ExtensionHeader")
{
    propertynames = nullptr;
}

Ipv6RoutingHeaderDescriptor::~Ipv6RoutingHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ipv6RoutingHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6RoutingHeader *>(obj)!=nullptr;
}

const char **Ipv6RoutingHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6RoutingHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6RoutingHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ipv6RoutingHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_routingType
        FD_ISEDITABLE,    // FIELD_segmentsLeft
        FD_ISARRAY,    // FIELD_address
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6RoutingHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "routingType",
        "segmentsLeft",
        "address",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ipv6RoutingHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "routingType") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "segmentsLeft") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "address") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6RoutingHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8",    // FIELD_routingType
        "uint8",    // FIELD_segmentsLeft
        "inet::Ipv6Address",    // FIELD_address
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6RoutingHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv6RoutingHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv6RoutingHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6RoutingHeader *pp = (Ipv6RoutingHeader *)object; (void)pp;
    switch (field) {
        case FIELD_address: return pp->getAddressArraySize();
        default: return 0;
    }
}

const char *Ipv6RoutingHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6RoutingHeader *pp = (Ipv6RoutingHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6RoutingHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6RoutingHeader *pp = (Ipv6RoutingHeader *)object; (void)pp;
    switch (field) {
        case FIELD_routingType: return ulong2string(pp->getRoutingType());
        case FIELD_segmentsLeft: return ulong2string(pp->getSegmentsLeft());
        case FIELD_address: return pp->getAddress(i).str();
        default: return "";
    }
}

bool Ipv6RoutingHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6RoutingHeader *pp = (Ipv6RoutingHeader *)object; (void)pp;
    switch (field) {
        case FIELD_routingType: pp->setRoutingType(string2ulong(value)); return true;
        case FIELD_segmentsLeft: pp->setSegmentsLeft(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ipv6RoutingHeaderDescriptor::getFieldStructName(int field) const
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

void *Ipv6RoutingHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6RoutingHeader *pp = (Ipv6RoutingHeader *)object; (void)pp;
    switch (field) {
        case FIELD_address: return toVoidPtr(&pp->getAddress(i)); break;
        default: return nullptr;
    }
}

Register_Class(Ipv6FragmentHeader)

Ipv6FragmentHeader::Ipv6FragmentHeader() : ::inet::Ipv6ExtensionHeader()
{
    this->setExtensionType(IP_PROT_IPv6EXT_FRAGMENT);
    this->setByteLength(IPv6_FRAGMENT_HEADER_LENGTH);

}

Ipv6FragmentHeader::Ipv6FragmentHeader(const Ipv6FragmentHeader& other) : ::inet::Ipv6ExtensionHeader(other)
{
    copy(other);
}

Ipv6FragmentHeader::~Ipv6FragmentHeader()
{
}

Ipv6FragmentHeader& Ipv6FragmentHeader::operator=(const Ipv6FragmentHeader& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6ExtensionHeader::operator=(other);
    copy(other);
    return *this;
}

void Ipv6FragmentHeader::copy(const Ipv6FragmentHeader& other)
{
    this->fragmentOffset = other.fragmentOffset;
    this->identification = other.identification;
    this->moreFragments = other.moreFragments;
}

void Ipv6FragmentHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6ExtensionHeader::parsimPack(b);
    doParsimPacking(b,this->fragmentOffset);
    doParsimPacking(b,this->identification);
    doParsimPacking(b,this->moreFragments);
}

void Ipv6FragmentHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6ExtensionHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->fragmentOffset);
    doParsimUnpacking(b,this->identification);
    doParsimUnpacking(b,this->moreFragments);
}

unsigned short Ipv6FragmentHeader::getFragmentOffset() const
{
    return this->fragmentOffset;
}

void Ipv6FragmentHeader::setFragmentOffset(unsigned short fragmentOffset)
{
    this->fragmentOffset = fragmentOffset;
}

unsigned int Ipv6FragmentHeader::getIdentification() const
{
    return this->identification;
}

void Ipv6FragmentHeader::setIdentification(unsigned int identification)
{
    this->identification = identification;
}

bool Ipv6FragmentHeader::getMoreFragments() const
{
    return this->moreFragments;
}

void Ipv6FragmentHeader::setMoreFragments(bool moreFragments)
{
    this->moreFragments = moreFragments;
}

class Ipv6FragmentHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_fragmentOffset,
        FIELD_identification,
        FIELD_moreFragments,
    };
  public:
    Ipv6FragmentHeaderDescriptor();
    virtual ~Ipv6FragmentHeaderDescriptor();

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

Register_ClassDescriptor(Ipv6FragmentHeaderDescriptor)

Ipv6FragmentHeaderDescriptor::Ipv6FragmentHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6FragmentHeader)), "inet::Ipv6ExtensionHeader")
{
    propertynames = nullptr;
}

Ipv6FragmentHeaderDescriptor::~Ipv6FragmentHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ipv6FragmentHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6FragmentHeader *>(obj)!=nullptr;
}

const char **Ipv6FragmentHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6FragmentHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6FragmentHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ipv6FragmentHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_fragmentOffset
        FD_ISEDITABLE,    // FIELD_identification
        FD_ISEDITABLE,    // FIELD_moreFragments
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6FragmentHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fragmentOffset",
        "identification",
        "moreFragments",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ipv6FragmentHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fragmentOffset") == 0) return base+0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "identification") == 0) return base+1;
    if (fieldName[0] == 'm' && strcmp(fieldName, "moreFragments") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6FragmentHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_fragmentOffset
        "unsigned int",    // FIELD_identification
        "bool",    // FIELD_moreFragments
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6FragmentHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv6FragmentHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv6FragmentHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6FragmentHeader *pp = (Ipv6FragmentHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6FragmentHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6FragmentHeader *pp = (Ipv6FragmentHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6FragmentHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6FragmentHeader *pp = (Ipv6FragmentHeader *)object; (void)pp;
    switch (field) {
        case FIELD_fragmentOffset: return ulong2string(pp->getFragmentOffset());
        case FIELD_identification: return ulong2string(pp->getIdentification());
        case FIELD_moreFragments: return bool2string(pp->getMoreFragments());
        default: return "";
    }
}

bool Ipv6FragmentHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6FragmentHeader *pp = (Ipv6FragmentHeader *)object; (void)pp;
    switch (field) {
        case FIELD_fragmentOffset: pp->setFragmentOffset(string2ulong(value)); return true;
        case FIELD_identification: pp->setIdentification(string2ulong(value)); return true;
        case FIELD_moreFragments: pp->setMoreFragments(string2bool(value)); return true;
        default: return false;
    }
}

const char *Ipv6FragmentHeaderDescriptor::getFieldStructName(int field) const
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

void *Ipv6FragmentHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6FragmentHeader *pp = (Ipv6FragmentHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv6DestinationOptionsHeader)

Ipv6DestinationOptionsHeader::Ipv6DestinationOptionsHeader() : ::inet::Ipv6ExtensionHeader()
{
    this->setExtensionType(IP_PROT_IPv6EXT_DEST);
    this->setByteLength(B(8));

}

Ipv6DestinationOptionsHeader::Ipv6DestinationOptionsHeader(const Ipv6DestinationOptionsHeader& other) : ::inet::Ipv6ExtensionHeader(other)
{
    copy(other);
}

Ipv6DestinationOptionsHeader::~Ipv6DestinationOptionsHeader()
{
}

Ipv6DestinationOptionsHeader& Ipv6DestinationOptionsHeader::operator=(const Ipv6DestinationOptionsHeader& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6ExtensionHeader::operator=(other);
    copy(other);
    return *this;
}

void Ipv6DestinationOptionsHeader::copy(const Ipv6DestinationOptionsHeader& other)
{
    this->tlvOptions = other.tlvOptions;
}

void Ipv6DestinationOptionsHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6ExtensionHeader::parsimPack(b);
    doParsimPacking(b,this->tlvOptions);
}

void Ipv6DestinationOptionsHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6ExtensionHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->tlvOptions);
}

const TlvOptions& Ipv6DestinationOptionsHeader::getTlvOptions() const
{
    return this->tlvOptions;
}

void Ipv6DestinationOptionsHeader::setTlvOptions(const TlvOptions& tlvOptions)
{
    this->tlvOptions = tlvOptions;
}

class Ipv6DestinationOptionsHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tlvOptions,
    };
  public:
    Ipv6DestinationOptionsHeaderDescriptor();
    virtual ~Ipv6DestinationOptionsHeaderDescriptor();

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

Register_ClassDescriptor(Ipv6DestinationOptionsHeaderDescriptor)

Ipv6DestinationOptionsHeaderDescriptor::Ipv6DestinationOptionsHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6DestinationOptionsHeader)), "inet::Ipv6ExtensionHeader")
{
    propertynames = nullptr;
}

Ipv6DestinationOptionsHeaderDescriptor::~Ipv6DestinationOptionsHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ipv6DestinationOptionsHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6DestinationOptionsHeader *>(obj)!=nullptr;
}

const char **Ipv6DestinationOptionsHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6DestinationOptionsHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6DestinationOptionsHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ipv6DestinationOptionsHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_tlvOptions
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6DestinationOptionsHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tlvOptions",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ipv6DestinationOptionsHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tlvOptions") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6DestinationOptionsHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::TlvOptions",    // FIELD_tlvOptions
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6DestinationOptionsHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv6DestinationOptionsHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv6DestinationOptionsHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6DestinationOptionsHeader *pp = (Ipv6DestinationOptionsHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6DestinationOptionsHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6DestinationOptionsHeader *pp = (Ipv6DestinationOptionsHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6DestinationOptionsHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6DestinationOptionsHeader *pp = (Ipv6DestinationOptionsHeader *)object; (void)pp;
    switch (field) {
        case FIELD_tlvOptions: {std::stringstream out; out << pp->getTlvOptions(); return out.str();}
        default: return "";
    }
}

bool Ipv6DestinationOptionsHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6DestinationOptionsHeader *pp = (Ipv6DestinationOptionsHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv6DestinationOptionsHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_tlvOptions: return omnetpp::opp_typename(typeid(TlvOptions));
        default: return nullptr;
    };
}

void *Ipv6DestinationOptionsHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6DestinationOptionsHeader *pp = (Ipv6DestinationOptionsHeader *)object; (void)pp;
    switch (field) {
        case FIELD_tlvOptions: return toVoidPtr(&pp->getTlvOptions()); break;
        default: return nullptr;
    }
}

Register_Class(Ipv6AuthenticationHeader)

Ipv6AuthenticationHeader::Ipv6AuthenticationHeader() : ::inet::Ipv6ExtensionHeader()
{
    this->setExtensionType(IP_PROT_IPv6EXT_AUTH);
    this->setByteLength(B(8));
}

Ipv6AuthenticationHeader::Ipv6AuthenticationHeader(const Ipv6AuthenticationHeader& other) : ::inet::Ipv6ExtensionHeader(other)
{
    copy(other);
}

Ipv6AuthenticationHeader::~Ipv6AuthenticationHeader()
{
}

Ipv6AuthenticationHeader& Ipv6AuthenticationHeader::operator=(const Ipv6AuthenticationHeader& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6ExtensionHeader::operator=(other);
    copy(other);
    return *this;
}

void Ipv6AuthenticationHeader::copy(const Ipv6AuthenticationHeader& other)
{
}

void Ipv6AuthenticationHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6ExtensionHeader::parsimPack(b);
}

void Ipv6AuthenticationHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6ExtensionHeader::parsimUnpack(b);
}

class Ipv6AuthenticationHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ipv6AuthenticationHeaderDescriptor();
    virtual ~Ipv6AuthenticationHeaderDescriptor();

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

Register_ClassDescriptor(Ipv6AuthenticationHeaderDescriptor)

Ipv6AuthenticationHeaderDescriptor::Ipv6AuthenticationHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6AuthenticationHeader)), "inet::Ipv6ExtensionHeader")
{
    propertynames = nullptr;
}

Ipv6AuthenticationHeaderDescriptor::~Ipv6AuthenticationHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ipv6AuthenticationHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6AuthenticationHeader *>(obj)!=nullptr;
}

const char **Ipv6AuthenticationHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6AuthenticationHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6AuthenticationHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ipv6AuthenticationHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ipv6AuthenticationHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ipv6AuthenticationHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6AuthenticationHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ipv6AuthenticationHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv6AuthenticationHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv6AuthenticationHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6AuthenticationHeader *pp = (Ipv6AuthenticationHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6AuthenticationHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6AuthenticationHeader *pp = (Ipv6AuthenticationHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6AuthenticationHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6AuthenticationHeader *pp = (Ipv6AuthenticationHeader *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ipv6AuthenticationHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6AuthenticationHeader *pp = (Ipv6AuthenticationHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv6AuthenticationHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ipv6AuthenticationHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6AuthenticationHeader *pp = (Ipv6AuthenticationHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv6EncapsulatingSecurityPayloadHeader)

Ipv6EncapsulatingSecurityPayloadHeader::Ipv6EncapsulatingSecurityPayloadHeader() : ::inet::Ipv6ExtensionHeader()
{
    this->setExtensionType(IP_PROT_IPv6EXT_ESP);
    this->setByteLength(B(8));
}

Ipv6EncapsulatingSecurityPayloadHeader::Ipv6EncapsulatingSecurityPayloadHeader(const Ipv6EncapsulatingSecurityPayloadHeader& other) : ::inet::Ipv6ExtensionHeader(other)
{
    copy(other);
}

Ipv6EncapsulatingSecurityPayloadHeader::~Ipv6EncapsulatingSecurityPayloadHeader()
{
}

Ipv6EncapsulatingSecurityPayloadHeader& Ipv6EncapsulatingSecurityPayloadHeader::operator=(const Ipv6EncapsulatingSecurityPayloadHeader& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6ExtensionHeader::operator=(other);
    copy(other);
    return *this;
}

void Ipv6EncapsulatingSecurityPayloadHeader::copy(const Ipv6EncapsulatingSecurityPayloadHeader& other)
{
}

void Ipv6EncapsulatingSecurityPayloadHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6ExtensionHeader::parsimPack(b);
}

void Ipv6EncapsulatingSecurityPayloadHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6ExtensionHeader::parsimUnpack(b);
}

class Ipv6EncapsulatingSecurityPayloadHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ipv6EncapsulatingSecurityPayloadHeaderDescriptor();
    virtual ~Ipv6EncapsulatingSecurityPayloadHeaderDescriptor();

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

Register_ClassDescriptor(Ipv6EncapsulatingSecurityPayloadHeaderDescriptor)

Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::Ipv6EncapsulatingSecurityPayloadHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6EncapsulatingSecurityPayloadHeader)), "inet::Ipv6ExtensionHeader")
{
    propertynames = nullptr;
}

Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::~Ipv6EncapsulatingSecurityPayloadHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6EncapsulatingSecurityPayloadHeader *>(obj)!=nullptr;
}

const char **Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6EncapsulatingSecurityPayloadHeader *pp = (Ipv6EncapsulatingSecurityPayloadHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6EncapsulatingSecurityPayloadHeader *pp = (Ipv6EncapsulatingSecurityPayloadHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6EncapsulatingSecurityPayloadHeader *pp = (Ipv6EncapsulatingSecurityPayloadHeader *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6EncapsulatingSecurityPayloadHeader *pp = (Ipv6EncapsulatingSecurityPayloadHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ipv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6EncapsulatingSecurityPayloadHeader *pp = (Ipv6EncapsulatingSecurityPayloadHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

