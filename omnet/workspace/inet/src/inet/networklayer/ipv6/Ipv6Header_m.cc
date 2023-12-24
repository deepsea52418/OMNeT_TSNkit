//
// Generated file, do not edit! Created by nedtool 5.6 from inet/networklayer/ipv6/Ipv6Header.msg.
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
#include "Ipv6Header_m.h"

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

Register_Class(Ipv6ExtensionHeader)

Ipv6ExtensionHeader::Ipv6ExtensionHeader() : ::omnetpp::cObject()
{
}

Ipv6ExtensionHeader::Ipv6ExtensionHeader(const Ipv6ExtensionHeader& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

Ipv6ExtensionHeader::~Ipv6ExtensionHeader()
{
}

Ipv6ExtensionHeader& Ipv6ExtensionHeader::operator=(const Ipv6ExtensionHeader& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Ipv6ExtensionHeader::copy(const Ipv6ExtensionHeader& other)
{
    this->extensionType = other.extensionType;
    this->byteLength = other.byteLength;
}

void Ipv6ExtensionHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->extensionType);
    doParsimPacking(b,this->byteLength);
}

void Ipv6ExtensionHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->extensionType);
    doParsimUnpacking(b,this->byteLength);
}

short Ipv6ExtensionHeader::getExtensionType() const
{
    return this->extensionType;
}

void Ipv6ExtensionHeader::setExtensionType(short extensionType)
{
    this->extensionType = extensionType;
}

B Ipv6ExtensionHeader::getByteLength() const
{
    return this->byteLength;
}

void Ipv6ExtensionHeader::setByteLength(B byteLength)
{
    this->byteLength = byteLength;
}

class Ipv6ExtensionHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_extensionType,
        FIELD_byteLength,
    };
  public:
    Ipv6ExtensionHeaderDescriptor();
    virtual ~Ipv6ExtensionHeaderDescriptor();

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

Register_ClassDescriptor(Ipv6ExtensionHeaderDescriptor)

Ipv6ExtensionHeaderDescriptor::Ipv6ExtensionHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6ExtensionHeader)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ipv6ExtensionHeaderDescriptor::~Ipv6ExtensionHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ipv6ExtensionHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6ExtensionHeader *>(obj)!=nullptr;
}

const char **Ipv6ExtensionHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6ExtensionHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6ExtensionHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ipv6ExtensionHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_extensionType
        FD_ISEDITABLE,    // FIELD_byteLength
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6ExtensionHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "extensionType",
        "byteLength",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ipv6ExtensionHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'e' && strcmp(fieldName, "extensionType") == 0) return base+0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "byteLength") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6ExtensionHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_extensionType
        "inet::B",    // FIELD_byteLength
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6ExtensionHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv6ExtensionHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv6ExtensionHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtensionHeader *pp = (Ipv6ExtensionHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6ExtensionHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtensionHeader *pp = (Ipv6ExtensionHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6ExtensionHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtensionHeader *pp = (Ipv6ExtensionHeader *)object; (void)pp;
    switch (field) {
        case FIELD_extensionType: return long2string(pp->getExtensionType());
        case FIELD_byteLength: return unit2string(pp->getByteLength());
        default: return "";
    }
}

bool Ipv6ExtensionHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtensionHeader *pp = (Ipv6ExtensionHeader *)object; (void)pp;
    switch (field) {
        case FIELD_extensionType: pp->setExtensionType(string2long(value)); return true;
        case FIELD_byteLength: pp->setByteLength(B(string2long(value))); return true;
        default: return false;
    }
}

const char *Ipv6ExtensionHeaderDescriptor::getFieldStructName(int field) const
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

void *Ipv6ExtensionHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6ExtensionHeader *pp = (Ipv6ExtensionHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ipv6Header)

Ipv6Header::Ipv6Header() : ::inet::NetworkHeaderBase()
{
    this->setChunkLength(IPv6_HEADER_BYTES);

}

Ipv6Header::Ipv6Header(const Ipv6Header& other) : ::inet::NetworkHeaderBase(other)
{
    copy(other);
}

Ipv6Header::~Ipv6Header()
{
    for (size_t i = 0; i < extensionHeader_arraysize; i++)
        delete this->extensionHeader[i];
    delete [] this->extensionHeader;
}

Ipv6Header& Ipv6Header::operator=(const Ipv6Header& other)
{
    if (this == &other) return *this;
    ::inet::NetworkHeaderBase::operator=(other);
    copy(other);
    return *this;
}

void Ipv6Header::copy(const Ipv6Header& other)
{
    this->srcAddress = other.srcAddress;
    this->destAddress = other.destAddress;
    this->payloadLength = other.payloadLength;
    this->diffServCodePoint = other.diffServCodePoint;
    this->explicitCongestionNotification = other.explicitCongestionNotification;
    this->flowLabel = other.flowLabel;
    this->hopLimit = other.hopLimit;
    this->protocolId = other.protocolId;
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

void Ipv6Header::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::NetworkHeaderBase::parsimPack(b);
    doParsimPacking(b,this->srcAddress);
    doParsimPacking(b,this->destAddress);
    doParsimPacking(b,this->payloadLength);
    doParsimPacking(b,this->diffServCodePoint);
    doParsimPacking(b,this->explicitCongestionNotification);
    doParsimPacking(b,this->flowLabel);
    doParsimPacking(b,this->hopLimit);
    doParsimPacking(b,this->protocolId);
    b->pack(extensionHeader_arraysize);
    doParsimArrayPacking(b,this->extensionHeader,extensionHeader_arraysize);
}

void Ipv6Header::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::NetworkHeaderBase::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddress);
    doParsimUnpacking(b,this->destAddress);
    doParsimUnpacking(b,this->payloadLength);
    doParsimUnpacking(b,this->diffServCodePoint);
    doParsimUnpacking(b,this->explicitCongestionNotification);
    doParsimUnpacking(b,this->flowLabel);
    doParsimUnpacking(b,this->hopLimit);
    doParsimUnpacking(b,this->protocolId);
    delete [] this->extensionHeader;
    b->unpack(extensionHeader_arraysize);
    if (extensionHeader_arraysize == 0) {
        this->extensionHeader = nullptr;
    } else {
        this->extensionHeader = new Ipv6ExtensionHeader *[extensionHeader_arraysize];
        doParsimArrayUnpacking(b,this->extensionHeader,extensionHeader_arraysize);
    }
}

const Ipv6Address& Ipv6Header::getSrcAddress() const
{
    return this->srcAddress;
}

void Ipv6Header::setSrcAddress(const Ipv6Address& srcAddress)
{
    handleChange();
    this->srcAddress = srcAddress;
}

const Ipv6Address& Ipv6Header::getDestAddress() const
{
    return this->destAddress;
}

void Ipv6Header::setDestAddress(const Ipv6Address& destAddress)
{
    handleChange();
    this->destAddress = destAddress;
}

B Ipv6Header::getPayloadLength() const
{
    return this->payloadLength;
}

void Ipv6Header::setPayloadLength(B payloadLength)
{
    handleChange();
    this->payloadLength = payloadLength;
}

short Ipv6Header::getDiffServCodePoint() const
{
    return this->diffServCodePoint;
}

void Ipv6Header::setDiffServCodePoint(short diffServCodePoint)
{
    handleChange();
    this->diffServCodePoint = diffServCodePoint;
}

short Ipv6Header::getExplicitCongestionNotification() const
{
    return this->explicitCongestionNotification;
}

void Ipv6Header::setExplicitCongestionNotification(short explicitCongestionNotification)
{
    handleChange();
    this->explicitCongestionNotification = explicitCongestionNotification;
}

unsigned int Ipv6Header::getFlowLabel() const
{
    return this->flowLabel;
}

void Ipv6Header::setFlowLabel(unsigned int flowLabel)
{
    handleChange();
    this->flowLabel = flowLabel;
}

short Ipv6Header::getHopLimit() const
{
    return this->hopLimit;
}

void Ipv6Header::setHopLimit(short hopLimit)
{
    handleChange();
    this->hopLimit = hopLimit;
}

inet::IpProtocolId Ipv6Header::getProtocolId() const
{
    return this->protocolId;
}

void Ipv6Header::setProtocolId(inet::IpProtocolId protocolId)
{
    handleChange();
    this->protocolId = protocolId;
}

size_t Ipv6Header::getExtensionHeaderArraySize() const
{
    return extensionHeader_arraysize;
}

const Ipv6ExtensionHeader * Ipv6Header::getExtensionHeader(size_t k) const
{
    if (k >= extensionHeader_arraysize) throw omnetpp::cRuntimeError("Array of size extensionHeader_arraysize indexed by %lu", (unsigned long)k);
    return this->extensionHeader[k];
}

void Ipv6Header::setExtensionHeaderArraySize(size_t newSize)
{
    handleChange();
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

void Ipv6Header::setExtensionHeader(size_t k, Ipv6ExtensionHeader * extensionHeader)
{
    if (k >= extensionHeader_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    if (this->extensionHeader[k] != nullptr) throw omnetpp::cRuntimeError("setExtensionHeader(): a value is already set, remove it first with dropExtensionHeader()");
    this->extensionHeader[k] = extensionHeader;
}

Ipv6ExtensionHeader * Ipv6Header::dropExtensionHeader(size_t k)
{
    if (k >= extensionHeader_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    Ipv6ExtensionHeader * retval = this->extensionHeader[k];
    this->extensionHeader[k] = nullptr;
    return retval;
}

void Ipv6Header::insertExtensionHeader(size_t k, Ipv6ExtensionHeader * extensionHeader)
{
    handleChange();
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

void Ipv6Header::insertExtensionHeader(Ipv6ExtensionHeader * extensionHeader)
{
    insertExtensionHeader(extensionHeader_arraysize, extensionHeader);
}

void Ipv6Header::eraseExtensionHeader(size_t k)
{
    if (k >= extensionHeader_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
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

class Ipv6HeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_srcAddress,
        FIELD_destAddress,
        FIELD_payloadLength,
        FIELD_diffServCodePoint,
        FIELD_explicitCongestionNotification,
        FIELD_flowLabel,
        FIELD_hopLimit,
        FIELD_protocolId,
        FIELD_extensionHeader,
    };
  public:
    Ipv6HeaderDescriptor();
    virtual ~Ipv6HeaderDescriptor();

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

Register_ClassDescriptor(Ipv6HeaderDescriptor)

Ipv6HeaderDescriptor::Ipv6HeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6Header)), "inet::NetworkHeaderBase")
{
    propertynames = nullptr;
}

Ipv6HeaderDescriptor::~Ipv6HeaderDescriptor()
{
    delete[] propertynames;
}

bool Ipv6HeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6Header *>(obj)!=nullptr;
}

const char **Ipv6HeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6HeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6HeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ipv6HeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_srcAddress
        0,    // FIELD_destAddress
        FD_ISEDITABLE,    // FIELD_payloadLength
        FD_ISEDITABLE,    // FIELD_diffServCodePoint
        FD_ISEDITABLE,    // FIELD_explicitCongestionNotification
        FD_ISEDITABLE,    // FIELD_flowLabel
        FD_ISEDITABLE,    // FIELD_hopLimit
        0,    // FIELD_protocolId
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_extensionHeader
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6HeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddress",
        "destAddress",
        "payloadLength",
        "diffServCodePoint",
        "explicitCongestionNotification",
        "flowLabel",
        "hopLimit",
        "protocolId",
        "extensionHeader",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int Ipv6HeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "srcAddress") == 0) return base+0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destAddress") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "payloadLength") == 0) return base+2;
    if (fieldName[0] == 'd' && strcmp(fieldName, "diffServCodePoint") == 0) return base+3;
    if (fieldName[0] == 'e' && strcmp(fieldName, "explicitCongestionNotification") == 0) return base+4;
    if (fieldName[0] == 'f' && strcmp(fieldName, "flowLabel") == 0) return base+5;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hopLimit") == 0) return base+6;
    if (fieldName[0] == 'p' && strcmp(fieldName, "protocolId") == 0) return base+7;
    if (fieldName[0] == 'e' && strcmp(fieldName, "extensionHeader") == 0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6HeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv6Address",    // FIELD_srcAddress
        "inet::Ipv6Address",    // FIELD_destAddress
        "inet::B",    // FIELD_payloadLength
        "short",    // FIELD_diffServCodePoint
        "short",    // FIELD_explicitCongestionNotification
        "unsigned int",    // FIELD_flowLabel
        "short",    // FIELD_hopLimit
        "inet::IpProtocolId",    // FIELD_protocolId
        "inet::Ipv6ExtensionHeader",    // FIELD_extensionHeader
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6HeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_protocolId: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_extensionHeader: {
            static const char *names[] = { "owned",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ipv6HeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_protocolId:
            if (!strcmp(propertyname, "enum")) return "inet::IpProtocolId";
            return nullptr;
        case FIELD_extensionHeader:
            if (!strcmp(propertyname, "owned")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int Ipv6HeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6Header *pp = (Ipv6Header *)object; (void)pp;
    switch (field) {
        case FIELD_extensionHeader: return pp->getExtensionHeaderArraySize();
        default: return 0;
    }
}

const char *Ipv6HeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6Header *pp = (Ipv6Header *)object; (void)pp;
    switch (field) {
        case FIELD_extensionHeader: { const Ipv6ExtensionHeader * value = pp->getExtensionHeader(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string Ipv6HeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6Header *pp = (Ipv6Header *)object; (void)pp;
    switch (field) {
        case FIELD_srcAddress: return pp->getSrcAddress().str();
        case FIELD_destAddress: return pp->getDestAddress().str();
        case FIELD_payloadLength: return unit2string(pp->getPayloadLength());
        case FIELD_diffServCodePoint: return long2string(pp->getDiffServCodePoint());
        case FIELD_explicitCongestionNotification: return long2string(pp->getExplicitCongestionNotification());
        case FIELD_flowLabel: return ulong2string(pp->getFlowLabel());
        case FIELD_hopLimit: return long2string(pp->getHopLimit());
        case FIELD_protocolId: return enum2string(pp->getProtocolId(), "inet::IpProtocolId");
        case FIELD_extensionHeader: {std::stringstream out; out << pp->getExtensionHeader(i); return out.str();}
        default: return "";
    }
}

bool Ipv6HeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6Header *pp = (Ipv6Header *)object; (void)pp;
    switch (field) {
        case FIELD_payloadLength: pp->setPayloadLength(B(string2long(value))); return true;
        case FIELD_diffServCodePoint: pp->setDiffServCodePoint(string2long(value)); return true;
        case FIELD_explicitCongestionNotification: pp->setExplicitCongestionNotification(string2long(value)); return true;
        case FIELD_flowLabel: pp->setFlowLabel(string2ulong(value)); return true;
        case FIELD_hopLimit: pp->setHopLimit(string2long(value)); return true;
        default: return false;
    }
}

const char *Ipv6HeaderDescriptor::getFieldStructName(int field) const
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

void *Ipv6HeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6Header *pp = (Ipv6Header *)object; (void)pp;
    switch (field) {
        case FIELD_srcAddress: return toVoidPtr(&pp->getSrcAddress()); break;
        case FIELD_destAddress: return toVoidPtr(&pp->getDestAddress()); break;
        case FIELD_extensionHeader: return toVoidPtr(pp->getExtensionHeader(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

