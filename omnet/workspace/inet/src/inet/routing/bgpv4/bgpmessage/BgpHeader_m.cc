//
// Generated file, do not edit! Created by nedtool 5.6 from inet/routing/bgpv4/bgpmessage/BgpHeader.msg.
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
#include "BgpHeader_m.h"

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
namespace bgp {

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

Register_Class(BgpAsPathSegment)

BgpAsPathSegment::BgpAsPathSegment() : ::omnetpp::cObject()
{
}

BgpAsPathSegment::BgpAsPathSegment(const BgpAsPathSegment& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

BgpAsPathSegment::~BgpAsPathSegment()
{
    delete [] this->asValue;
}

BgpAsPathSegment& BgpAsPathSegment::operator=(const BgpAsPathSegment& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void BgpAsPathSegment::copy(const BgpAsPathSegment& other)
{
    this->type = other.type;
    this->length = other.length;
    delete [] this->asValue;
    this->asValue = (other.asValue_arraysize==0) ? nullptr : new unsigned short[other.asValue_arraysize];
    asValue_arraysize = other.asValue_arraysize;
    for (size_t i = 0; i < asValue_arraysize; i++) {
        this->asValue[i] = other.asValue[i];
    }
}

void BgpAsPathSegment::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->length);
    b->pack(asValue_arraysize);
    doParsimArrayPacking(b,this->asValue,asValue_arraysize);
}

void BgpAsPathSegment::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->length);
    delete [] this->asValue;
    b->unpack(asValue_arraysize);
    if (asValue_arraysize == 0) {
        this->asValue = nullptr;
    } else {
        this->asValue = new unsigned short[asValue_arraysize];
        doParsimArrayUnpacking(b,this->asValue,asValue_arraysize);
    }
}

inet::bgp::BgpPathSegmentType BgpAsPathSegment::getType() const
{
    return this->type;
}

void BgpAsPathSegment::setType(inet::bgp::BgpPathSegmentType type)
{
    this->type = type;
}

unsigned char BgpAsPathSegment::getLength() const
{
    return this->length;
}

void BgpAsPathSegment::setLength(unsigned char length)
{
    this->length = length;
}

size_t BgpAsPathSegment::getAsValueArraySize() const
{
    return asValue_arraysize;
}

unsigned short BgpAsPathSegment::getAsValue(size_t k) const
{
    if (k >= asValue_arraysize) throw omnetpp::cRuntimeError("Array of size asValue_arraysize indexed by %lu", (unsigned long)k);
    return this->asValue[k];
}

void BgpAsPathSegment::setAsValueArraySize(size_t newSize)
{
    unsigned short *asValue2 = (newSize==0) ? nullptr : new unsigned short[newSize];
    size_t minSize = asValue_arraysize < newSize ? asValue_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        asValue2[i] = this->asValue[i];
    for (size_t i = minSize; i < newSize; i++)
        asValue2[i] = 0;
    delete [] this->asValue;
    this->asValue = asValue2;
    asValue_arraysize = newSize;
}

void BgpAsPathSegment::setAsValue(size_t k, unsigned short asValue)
{
    if (k >= asValue_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->asValue[k] = asValue;
}

void BgpAsPathSegment::insertAsValue(size_t k, unsigned short asValue)
{
    if (k > asValue_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = asValue_arraysize + 1;
    unsigned short *asValue2 = new unsigned short[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        asValue2[i] = this->asValue[i];
    asValue2[k] = asValue;
    for (i = k + 1; i < newSize; i++)
        asValue2[i] = this->asValue[i-1];
    delete [] this->asValue;
    this->asValue = asValue2;
    asValue_arraysize = newSize;
}

void BgpAsPathSegment::insertAsValue(unsigned short asValue)
{
    insertAsValue(asValue_arraysize, asValue);
}

void BgpAsPathSegment::eraseAsValue(size_t k)
{
    if (k >= asValue_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = asValue_arraysize - 1;
    unsigned short *asValue2 = (newSize == 0) ? nullptr : new unsigned short[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        asValue2[i] = this->asValue[i];
    for (i = k; i < newSize; i++)
        asValue2[i] = this->asValue[i+1];
    delete [] this->asValue;
    this->asValue = asValue2;
    asValue_arraysize = newSize;
}

class BgpAsPathSegmentDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_length,
        FIELD_asValue,
    };
  public:
    BgpAsPathSegmentDescriptor();
    virtual ~BgpAsPathSegmentDescriptor();

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

Register_ClassDescriptor(BgpAsPathSegmentDescriptor)

BgpAsPathSegmentDescriptor::BgpAsPathSegmentDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpAsPathSegment)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

BgpAsPathSegmentDescriptor::~BgpAsPathSegmentDescriptor()
{
    delete[] propertynames;
}

bool BgpAsPathSegmentDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpAsPathSegment *>(obj)!=nullptr;
}

const char **BgpAsPathSegmentDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpAsPathSegmentDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpAsPathSegmentDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int BgpAsPathSegmentDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_length
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_asValue
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *BgpAsPathSegmentDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "length",
        "asValue",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int BgpAsPathSegmentDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "asValue") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpAsPathSegmentDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bgp::BgpPathSegmentType",    // FIELD_type
        "unsigned char",    // FIELD_length
        "unsigned short",    // FIELD_asValue
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpAsPathSegmentDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpAsPathSegmentDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::bgp::BgpPathSegmentType";
            return nullptr;
        default: return nullptr;
    }
}

int BgpAsPathSegmentDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpAsPathSegment *pp = (BgpAsPathSegment *)object; (void)pp;
    switch (field) {
        case FIELD_asValue: return pp->getAsValueArraySize();
        default: return 0;
    }
}

const char *BgpAsPathSegmentDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpAsPathSegment *pp = (BgpAsPathSegment *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpAsPathSegmentDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpAsPathSegment *pp = (BgpAsPathSegment *)object; (void)pp;
    switch (field) {
        case FIELD_type: return enum2string(pp->getType(), "inet::bgp::BgpPathSegmentType");
        case FIELD_length: return ulong2string(pp->getLength());
        case FIELD_asValue: return ulong2string(pp->getAsValue(i));
        default: return "";
    }
}

bool BgpAsPathSegmentDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpAsPathSegment *pp = (BgpAsPathSegment *)object; (void)pp;
    switch (field) {
        case FIELD_length: pp->setLength(string2ulong(value)); return true;
        case FIELD_asValue: pp->setAsValue(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *BgpAsPathSegmentDescriptor::getFieldStructName(int field) const
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

void *BgpAsPathSegmentDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpAsPathSegment *pp = (BgpAsPathSegment *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::bgp::BgpType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::bgp::BgpType"));
    e->insert(BGP_OPEN, "BGP_OPEN");
    e->insert(BGP_UPDATE, "BGP_UPDATE");
    e->insert(BGP_NOTIFICATION, "BGP_NOTIFICATION");
    e->insert(BGP_KEEPALIVE, "BGP_KEEPALIVE");
)

Register_Class(BgpHeader)

BgpHeader::BgpHeader() : ::inet::FieldsChunk()
{
    this->setChunkLength(BGP_HEADER_OCTETS);

}

BgpHeader::BgpHeader(const BgpHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

BgpHeader::~BgpHeader()
{
}

BgpHeader& BgpHeader::operator=(const BgpHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void BgpHeader::copy(const BgpHeader& other)
{
    this->type = other.type;
}

void BgpHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->type);
}

void BgpHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
}

inet::bgp::BgpType BgpHeader::getType() const
{
    return this->type;
}

void BgpHeader::setType(inet::bgp::BgpType type)
{
    handleChange();
    this->type = type;
}

class BgpHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
    };
  public:
    BgpHeaderDescriptor();
    virtual ~BgpHeaderDescriptor();

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

Register_ClassDescriptor(BgpHeaderDescriptor)

BgpHeaderDescriptor::BgpHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

BgpHeaderDescriptor::~BgpHeaderDescriptor()
{
    delete[] propertynames;
}

bool BgpHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpHeader *>(obj)!=nullptr;
}

const char **BgpHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BgpHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_type
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *BgpHeaderDescriptor::getFieldName(int field) const
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

int BgpHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bgp::BgpType",    // FIELD_type
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::bgp::BgpType";
            return nullptr;
        default: return nullptr;
    }
}

int BgpHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpHeader *pp = (BgpHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpHeader *pp = (BgpHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpHeader *pp = (BgpHeader *)object; (void)pp;
    switch (field) {
        case FIELD_type: return enum2string(pp->getType(), "inet::bgp::BgpType");
        default: return "";
    }
}

bool BgpHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpHeader *pp = (BgpHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BgpHeaderDescriptor::getFieldStructName(int field) const
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

void *BgpHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpHeader *pp = (BgpHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(BgpKeepAliveMessage)

BgpKeepAliveMessage::BgpKeepAliveMessage() : ::inet::bgp::BgpHeader()
{
    this->setType(BGP_KEEPALIVE);
}

BgpKeepAliveMessage::BgpKeepAliveMessage(const BgpKeepAliveMessage& other) : ::inet::bgp::BgpHeader(other)
{
    copy(other);
}

BgpKeepAliveMessage::~BgpKeepAliveMessage()
{
}

BgpKeepAliveMessage& BgpKeepAliveMessage::operator=(const BgpKeepAliveMessage& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpHeader::operator=(other);
    copy(other);
    return *this;
}

void BgpKeepAliveMessage::copy(const BgpKeepAliveMessage& other)
{
}

void BgpKeepAliveMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpHeader::parsimPack(b);
}

void BgpKeepAliveMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpHeader::parsimUnpack(b);
}

class BgpKeepAliveMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    BgpKeepAliveMessageDescriptor();
    virtual ~BgpKeepAliveMessageDescriptor();

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

Register_ClassDescriptor(BgpKeepAliveMessageDescriptor)

BgpKeepAliveMessageDescriptor::BgpKeepAliveMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpKeepAliveMessage)), "inet::bgp::BgpHeader")
{
    propertynames = nullptr;
}

BgpKeepAliveMessageDescriptor::~BgpKeepAliveMessageDescriptor()
{
    delete[] propertynames;
}

bool BgpKeepAliveMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpKeepAliveMessage *>(obj)!=nullptr;
}

const char **BgpKeepAliveMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpKeepAliveMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpKeepAliveMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int BgpKeepAliveMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *BgpKeepAliveMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int BgpKeepAliveMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpKeepAliveMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **BgpKeepAliveMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpKeepAliveMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpKeepAliveMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpKeepAliveMessage *pp = (BgpKeepAliveMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpKeepAliveMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpKeepAliveMessage *pp = (BgpKeepAliveMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpKeepAliveMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpKeepAliveMessage *pp = (BgpKeepAliveMessage *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool BgpKeepAliveMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpKeepAliveMessage *pp = (BgpKeepAliveMessage *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BgpKeepAliveMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *BgpKeepAliveMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpKeepAliveMessage *pp = (BgpKeepAliveMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

BgpParameterValues::BgpParameterValues()
{
    this->authCode = 0;
    this->authenticationData = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const BgpParameterValues& a)
{
    doParsimPacking(b,a.authCode);
    doParsimPacking(b,a.authenticationData);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BgpParameterValues& a)
{
    doParsimUnpacking(b,a.authCode);
    doParsimUnpacking(b,a.authenticationData);
}

class BgpParameterValuesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_authCode,
        FIELD_authenticationData,
    };
  public:
    BgpParameterValuesDescriptor();
    virtual ~BgpParameterValuesDescriptor();

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

Register_ClassDescriptor(BgpParameterValuesDescriptor)

BgpParameterValuesDescriptor::BgpParameterValuesDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpParameterValues)), "")
{
    propertynames = nullptr;
}

BgpParameterValuesDescriptor::~BgpParameterValuesDescriptor()
{
    delete[] propertynames;
}

bool BgpParameterValuesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpParameterValues *>(obj)!=nullptr;
}

const char **BgpParameterValuesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpParameterValuesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpParameterValuesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BgpParameterValuesDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_authCode
        FD_ISEDITABLE,    // FIELD_authenticationData
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *BgpParameterValuesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "authCode",
        "authenticationData",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int BgpParameterValuesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "authCode") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "authenticationData") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpParameterValuesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_authCode
        "long",    // FIELD_authenticationData
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpParameterValuesDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpParameterValuesDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpParameterValuesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpParameterValues *pp = (BgpParameterValues *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpParameterValuesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpParameterValues *pp = (BgpParameterValues *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpParameterValuesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpParameterValues *pp = (BgpParameterValues *)object; (void)pp;
    switch (field) {
        case FIELD_authCode: return long2string(pp->authCode);
        case FIELD_authenticationData: return long2string(pp->authenticationData);
        default: return "";
    }
}

bool BgpParameterValuesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpParameterValues *pp = (BgpParameterValues *)object; (void)pp;
    switch (field) {
        case FIELD_authCode: pp->authCode = string2long(value); return true;
        case FIELD_authenticationData: pp->authenticationData = string2long(value); return true;
        default: return false;
    }
}

const char *BgpParameterValuesDescriptor::getFieldStructName(int field) const
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

void *BgpParameterValuesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpParameterValues *pp = (BgpParameterValues *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

BgpOptionalParameters::BgpOptionalParameters()
{
    this->parameterType = 0;
    this->parameterLength = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const BgpOptionalParameters& a)
{
    doParsimPacking(b,a.parameterType);
    doParsimPacking(b,a.parameterLength);
    doParsimPacking(b,a.parameterValues);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BgpOptionalParameters& a)
{
    doParsimUnpacking(b,a.parameterType);
    doParsimUnpacking(b,a.parameterLength);
    doParsimUnpacking(b,a.parameterValues);
}

class BgpOptionalParametersDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_parameterType,
        FIELD_parameterLength,
        FIELD_parameterValues,
    };
  public:
    BgpOptionalParametersDescriptor();
    virtual ~BgpOptionalParametersDescriptor();

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

Register_ClassDescriptor(BgpOptionalParametersDescriptor)

BgpOptionalParametersDescriptor::BgpOptionalParametersDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpOptionalParameters)), "")
{
    propertynames = nullptr;
}

BgpOptionalParametersDescriptor::~BgpOptionalParametersDescriptor()
{
    delete[] propertynames;
}

bool BgpOptionalParametersDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpOptionalParameters *>(obj)!=nullptr;
}

const char **BgpOptionalParametersDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpOptionalParametersDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpOptionalParametersDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int BgpOptionalParametersDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_parameterType
        FD_ISEDITABLE,    // FIELD_parameterLength
        FD_ISCOMPOUND,    // FIELD_parameterValues
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *BgpOptionalParametersDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "parameterType",
        "parameterLength",
        "parameterValues",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int BgpOptionalParametersDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "parameterType") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "parameterLength") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "parameterValues") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpOptionalParametersDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_parameterType
        "unsigned short",    // FIELD_parameterLength
        "inet::bgp::BgpParameterValues",    // FIELD_parameterValues
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpOptionalParametersDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpOptionalParametersDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpOptionalParametersDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameters *pp = (BgpOptionalParameters *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpOptionalParametersDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameters *pp = (BgpOptionalParameters *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpOptionalParametersDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameters *pp = (BgpOptionalParameters *)object; (void)pp;
    switch (field) {
        case FIELD_parameterType: return long2string(pp->parameterType);
        case FIELD_parameterLength: return ulong2string(pp->parameterLength);
        case FIELD_parameterValues: {std::stringstream out; out << pp->parameterValues; return out.str();}
        default: return "";
    }
}

bool BgpOptionalParametersDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameters *pp = (BgpOptionalParameters *)object; (void)pp;
    switch (field) {
        case FIELD_parameterType: pp->parameterType = string2long(value); return true;
        case FIELD_parameterLength: pp->parameterLength = string2ulong(value); return true;
        default: return false;
    }
}

const char *BgpOptionalParametersDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_parameterValues: return omnetpp::opp_typename(typeid(BgpParameterValues));
        default: return nullptr;
    };
}

void *BgpOptionalParametersDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpOptionalParameters *pp = (BgpOptionalParameters *)object; (void)pp;
    switch (field) {
        case FIELD_parameterValues: return toVoidPtr(&pp->parameterValues); break;
        default: return nullptr;
    }
}

Register_Class(BgpOpenMessage)

BgpOpenMessage::BgpOpenMessage() : ::inet::bgp::BgpHeader()
{
    this->setType(BGP_OPEN);
    this->setChunkLength(BGP_HEADER_OCTETS + BGP_OPEN_OCTETS);

}

BgpOpenMessage::BgpOpenMessage(const BgpOpenMessage& other) : ::inet::bgp::BgpHeader(other)
{
    copy(other);
}

BgpOpenMessage::~BgpOpenMessage()
{
    delete [] this->optionalParameters;
}

BgpOpenMessage& BgpOpenMessage::operator=(const BgpOpenMessage& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpHeader::operator=(other);
    copy(other);
    return *this;
}

void BgpOpenMessage::copy(const BgpOpenMessage& other)
{
    this->version = other.version;
    this->myAS = other.myAS;
    this->holdTime = other.holdTime;
    this->BGPIdentifier = other.BGPIdentifier;
    delete [] this->optionalParameters;
    this->optionalParameters = (other.optionalParameters_arraysize==0) ? nullptr : new BgpOptionalParameters[other.optionalParameters_arraysize];
    optionalParameters_arraysize = other.optionalParameters_arraysize;
    for (size_t i = 0; i < optionalParameters_arraysize; i++) {
        this->optionalParameters[i] = other.optionalParameters[i];
    }
}

void BgpOpenMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpHeader::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->myAS);
    doParsimPacking(b,this->holdTime);
    doParsimPacking(b,this->BGPIdentifier);
    b->pack(optionalParameters_arraysize);
    doParsimArrayPacking(b,this->optionalParameters,optionalParameters_arraysize);
}

void BgpOpenMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->myAS);
    doParsimUnpacking(b,this->holdTime);
    doParsimUnpacking(b,this->BGPIdentifier);
    delete [] this->optionalParameters;
    b->unpack(optionalParameters_arraysize);
    if (optionalParameters_arraysize == 0) {
        this->optionalParameters = nullptr;
    } else {
        this->optionalParameters = new BgpOptionalParameters[optionalParameters_arraysize];
        doParsimArrayUnpacking(b,this->optionalParameters,optionalParameters_arraysize);
    }
}

char BgpOpenMessage::getVersion() const
{
    return this->version;
}

void BgpOpenMessage::setVersion(char version)
{
    handleChange();
    this->version = version;
}

unsigned short BgpOpenMessage::getMyAS() const
{
    return this->myAS;
}

void BgpOpenMessage::setMyAS(unsigned short myAS)
{
    handleChange();
    this->myAS = myAS;
}

omnetpp::simtime_t BgpOpenMessage::getHoldTime() const
{
    return this->holdTime;
}

void BgpOpenMessage::setHoldTime(omnetpp::simtime_t holdTime)
{
    handleChange();
    this->holdTime = holdTime;
}

const Ipv4Address& BgpOpenMessage::getBGPIdentifier() const
{
    return this->BGPIdentifier;
}

void BgpOpenMessage::setBGPIdentifier(const Ipv4Address& BGPIdentifier)
{
    handleChange();
    this->BGPIdentifier = BGPIdentifier;
}

size_t BgpOpenMessage::getOptionalParametersArraySize() const
{
    return optionalParameters_arraysize;
}

const BgpOptionalParameters& BgpOpenMessage::getOptionalParameters(size_t k) const
{
    if (k >= optionalParameters_arraysize) throw omnetpp::cRuntimeError("Array of size optionalParameters_arraysize indexed by %lu", (unsigned long)k);
    return this->optionalParameters[k];
}

void BgpOpenMessage::setOptionalParametersArraySize(size_t newSize)
{
    handleChange();
    BgpOptionalParameters *optionalParameters2 = (newSize==0) ? nullptr : new BgpOptionalParameters[newSize];
    size_t minSize = optionalParameters_arraysize < newSize ? optionalParameters_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        optionalParameters2[i] = this->optionalParameters[i];
    delete [] this->optionalParameters;
    this->optionalParameters = optionalParameters2;
    optionalParameters_arraysize = newSize;
}

void BgpOpenMessage::setOptionalParameters(size_t k, const BgpOptionalParameters& optionalParameters)
{
    if (k >= optionalParameters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->optionalParameters[k] = optionalParameters;
}

void BgpOpenMessage::insertOptionalParameters(size_t k, const BgpOptionalParameters& optionalParameters)
{
    handleChange();
    if (k > optionalParameters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = optionalParameters_arraysize + 1;
    BgpOptionalParameters *optionalParameters2 = new BgpOptionalParameters[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        optionalParameters2[i] = this->optionalParameters[i];
    optionalParameters2[k] = optionalParameters;
    for (i = k + 1; i < newSize; i++)
        optionalParameters2[i] = this->optionalParameters[i-1];
    delete [] this->optionalParameters;
    this->optionalParameters = optionalParameters2;
    optionalParameters_arraysize = newSize;
}

void BgpOpenMessage::insertOptionalParameters(const BgpOptionalParameters& optionalParameters)
{
    insertOptionalParameters(optionalParameters_arraysize, optionalParameters);
}

void BgpOpenMessage::eraseOptionalParameters(size_t k)
{
    if (k >= optionalParameters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = optionalParameters_arraysize - 1;
    BgpOptionalParameters *optionalParameters2 = (newSize == 0) ? nullptr : new BgpOptionalParameters[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        optionalParameters2[i] = this->optionalParameters[i];
    for (i = k; i < newSize; i++)
        optionalParameters2[i] = this->optionalParameters[i+1];
    delete [] this->optionalParameters;
    this->optionalParameters = optionalParameters2;
    optionalParameters_arraysize = newSize;
}

class BgpOpenMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_version,
        FIELD_myAS,
        FIELD_holdTime,
        FIELD_BGPIdentifier,
        FIELD_optionalParameters,
    };
  public:
    BgpOpenMessageDescriptor();
    virtual ~BgpOpenMessageDescriptor();

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

Register_ClassDescriptor(BgpOpenMessageDescriptor)

BgpOpenMessageDescriptor::BgpOpenMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpOpenMessage)), "inet::bgp::BgpHeader")
{
    propertynames = nullptr;
}

BgpOpenMessageDescriptor::~BgpOpenMessageDescriptor()
{
    delete[] propertynames;
}

bool BgpOpenMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpOpenMessage *>(obj)!=nullptr;
}

const char **BgpOpenMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpOpenMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpOpenMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int BgpOpenMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_version
        FD_ISEDITABLE,    // FIELD_myAS
        0,    // FIELD_holdTime
        0,    // FIELD_BGPIdentifier
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_optionalParameters
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *BgpOpenMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "myAS",
        "holdTime",
        "BGPIdentifier",
        "optionalParameters",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int BgpOpenMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "version") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "myAS") == 0) return base+1;
    if (fieldName[0] == 'h' && strcmp(fieldName, "holdTime") == 0) return base+2;
    if (fieldName[0] == 'B' && strcmp(fieldName, "BGPIdentifier") == 0) return base+3;
    if (fieldName[0] == 'o' && strcmp(fieldName, "optionalParameters") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpOpenMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",    // FIELD_version
        "unsigned short",    // FIELD_myAS
        "omnetpp::simtime_t",    // FIELD_holdTime
        "inet::Ipv4Address",    // FIELD_BGPIdentifier
        "inet::bgp::BgpOptionalParameters",    // FIELD_optionalParameters
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpOpenMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpOpenMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpOpenMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpOpenMessage *pp = (BgpOpenMessage *)object; (void)pp;
    switch (field) {
        case FIELD_optionalParameters: return pp->getOptionalParametersArraySize();
        default: return 0;
    }
}

const char *BgpOpenMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpOpenMessage *pp = (BgpOpenMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpOpenMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpOpenMessage *pp = (BgpOpenMessage *)object; (void)pp;
    switch (field) {
        case FIELD_version: return long2string(pp->getVersion());
        case FIELD_myAS: return ulong2string(pp->getMyAS());
        case FIELD_holdTime: return simtime2string(pp->getHoldTime());
        case FIELD_BGPIdentifier: return pp->getBGPIdentifier().str();
        case FIELD_optionalParameters: {std::stringstream out; out << pp->getOptionalParameters(i); return out.str();}
        default: return "";
    }
}

bool BgpOpenMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpOpenMessage *pp = (BgpOpenMessage *)object; (void)pp;
    switch (field) {
        case FIELD_version: pp->setVersion(string2long(value)); return true;
        case FIELD_myAS: pp->setMyAS(string2ulong(value)); return true;
        default: return false;
    }
}

const char *BgpOpenMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_optionalParameters: return omnetpp::opp_typename(typeid(BgpOptionalParameters));
        default: return nullptr;
    };
}

void *BgpOpenMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpOpenMessage *pp = (BgpOpenMessage *)object; (void)pp;
    switch (field) {
        case FIELD_BGPIdentifier: return toVoidPtr(&pp->getBGPIdentifier()); break;
        case FIELD_optionalParameters: return toVoidPtr(&pp->getOptionalParameters(i)); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::bgp::BgpUpdateAttributeTypeCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::bgp::BgpUpdateAttributeTypeCode"));
    e->insert(ORIGIN, "ORIGIN");
    e->insert(AS_PATH, "AS_PATH");
    e->insert(NEXT_HOP, "NEXT_HOP");
    e->insert(LOCAL_PREF, "LOCAL_PREF");
    e->insert(ATOMIC_AGGREGATE, "ATOMIC_AGGREGATE");
)

BgpUpdateAttributeFlags::BgpUpdateAttributeFlags()
{
    this->optionalBit = false;
    this->transitiveBit = false;
    this->partialBit = false;
    this->estendedLengthBit = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const BgpUpdateAttributeFlags& a)
{
    doParsimPacking(b,a.optionalBit);
    doParsimPacking(b,a.transitiveBit);
    doParsimPacking(b,a.partialBit);
    doParsimPacking(b,a.estendedLengthBit);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BgpUpdateAttributeFlags& a)
{
    doParsimUnpacking(b,a.optionalBit);
    doParsimUnpacking(b,a.transitiveBit);
    doParsimUnpacking(b,a.partialBit);
    doParsimUnpacking(b,a.estendedLengthBit);
}

class BgpUpdateAttributeFlagsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_optionalBit,
        FIELD_transitiveBit,
        FIELD_partialBit,
        FIELD_estendedLengthBit,
    };
  public:
    BgpUpdateAttributeFlagsDescriptor();
    virtual ~BgpUpdateAttributeFlagsDescriptor();

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

Register_ClassDescriptor(BgpUpdateAttributeFlagsDescriptor)

BgpUpdateAttributeFlagsDescriptor::BgpUpdateAttributeFlagsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdateAttributeFlags)), "")
{
    propertynames = nullptr;
}

BgpUpdateAttributeFlagsDescriptor::~BgpUpdateAttributeFlagsDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdateAttributeFlagsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdateAttributeFlags *>(obj)!=nullptr;
}

const char **BgpUpdateAttributeFlagsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdateAttributeFlagsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdateAttributeFlagsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int BgpUpdateAttributeFlagsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_optionalBit
        FD_ISEDITABLE,    // FIELD_transitiveBit
        FD_ISEDITABLE,    // FIELD_partialBit
        FD_ISEDITABLE,    // FIELD_estendedLengthBit
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdateAttributeFlagsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "optionalBit",
        "transitiveBit",
        "partialBit",
        "estendedLengthBit",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int BgpUpdateAttributeFlagsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "optionalBit") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "transitiveBit") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "partialBit") == 0) return base+2;
    if (fieldName[0] == 'e' && strcmp(fieldName, "estendedLengthBit") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdateAttributeFlagsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_optionalBit
        "bool",    // FIELD_transitiveBit
        "bool",    // FIELD_partialBit
        "bool",    // FIELD_estendedLengthBit
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdateAttributeFlagsDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdateAttributeFlagsDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdateAttributeFlagsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateAttributeFlags *pp = (BgpUpdateAttributeFlags *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpUpdateAttributeFlagsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateAttributeFlags *pp = (BgpUpdateAttributeFlags *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdateAttributeFlagsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateAttributeFlags *pp = (BgpUpdateAttributeFlags *)object; (void)pp;
    switch (field) {
        case FIELD_optionalBit: return bool2string(pp->optionalBit);
        case FIELD_transitiveBit: return bool2string(pp->transitiveBit);
        case FIELD_partialBit: return bool2string(pp->partialBit);
        case FIELD_estendedLengthBit: return bool2string(pp->estendedLengthBit);
        default: return "";
    }
}

bool BgpUpdateAttributeFlagsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateAttributeFlags *pp = (BgpUpdateAttributeFlags *)object; (void)pp;
    switch (field) {
        case FIELD_optionalBit: pp->optionalBit = string2bool(value); return true;
        case FIELD_transitiveBit: pp->transitiveBit = string2bool(value); return true;
        case FIELD_partialBit: pp->partialBit = string2bool(value); return true;
        case FIELD_estendedLengthBit: pp->estendedLengthBit = string2bool(value); return true;
        default: return false;
    }
}

const char *BgpUpdateAttributeFlagsDescriptor::getFieldStructName(int field) const
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

void *BgpUpdateAttributeFlagsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateAttributeFlags *pp = (BgpUpdateAttributeFlags *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

BgpUpdateAttributeType::BgpUpdateAttributeType()
{
    this->typeCode = static_cast<inet::bgp::BgpUpdateAttributeTypeCode>(-1);
}

void __doPacking(omnetpp::cCommBuffer *b, const BgpUpdateAttributeType& a)
{
    doParsimPacking(b,a.flags);
    doParsimPacking(b,a.typeCode);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BgpUpdateAttributeType& a)
{
    doParsimUnpacking(b,a.flags);
    doParsimUnpacking(b,a.typeCode);
}

class BgpUpdateAttributeTypeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_flags,
        FIELD_typeCode,
    };
  public:
    BgpUpdateAttributeTypeDescriptor();
    virtual ~BgpUpdateAttributeTypeDescriptor();

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

Register_ClassDescriptor(BgpUpdateAttributeTypeDescriptor)

BgpUpdateAttributeTypeDescriptor::BgpUpdateAttributeTypeDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdateAttributeType)), "")
{
    propertynames = nullptr;
}

BgpUpdateAttributeTypeDescriptor::~BgpUpdateAttributeTypeDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdateAttributeTypeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdateAttributeType *>(obj)!=nullptr;
}

const char **BgpUpdateAttributeTypeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdateAttributeTypeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdateAttributeTypeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BgpUpdateAttributeTypeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_flags
        0,    // FIELD_typeCode
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdateAttributeTypeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "flags",
        "typeCode",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int BgpUpdateAttributeTypeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "flags") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "typeCode") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdateAttributeTypeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bgp::BgpUpdateAttributeFlags",    // FIELD_flags
        "inet::bgp::BgpUpdateAttributeTypeCode",    // FIELD_typeCode
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdateAttributeTypeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_typeCode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *BgpUpdateAttributeTypeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_typeCode:
            if (!strcmp(propertyname, "enum")) return "inet::bgp::BgpUpdateAttributeTypeCode";
            return nullptr;
        default: return nullptr;
    }
}

int BgpUpdateAttributeTypeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateAttributeType *pp = (BgpUpdateAttributeType *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpUpdateAttributeTypeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateAttributeType *pp = (BgpUpdateAttributeType *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdateAttributeTypeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateAttributeType *pp = (BgpUpdateAttributeType *)object; (void)pp;
    switch (field) {
        case FIELD_flags: {std::stringstream out; out << pp->flags; return out.str();}
        case FIELD_typeCode: return enum2string(pp->typeCode, "inet::bgp::BgpUpdateAttributeTypeCode");
        default: return "";
    }
}

bool BgpUpdateAttributeTypeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateAttributeType *pp = (BgpUpdateAttributeType *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BgpUpdateAttributeTypeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_flags: return omnetpp::opp_typename(typeid(BgpUpdateAttributeFlags));
        default: return nullptr;
    };
}

void *BgpUpdateAttributeTypeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateAttributeType *pp = (BgpUpdateAttributeType *)object; (void)pp;
    switch (field) {
        case FIELD_flags: return toVoidPtr(&pp->flags); break;
        default: return nullptr;
    }
}

Register_Class(BgpUpdatePathAttributes)

BgpUpdatePathAttributes::BgpUpdatePathAttributes() : ::omnetpp::cObject()
{
}

BgpUpdatePathAttributes::BgpUpdatePathAttributes(const BgpUpdatePathAttributes& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

BgpUpdatePathAttributes::~BgpUpdatePathAttributes()
{
}

BgpUpdatePathAttributes& BgpUpdatePathAttributes::operator=(const BgpUpdatePathAttributes& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributes::copy(const BgpUpdatePathAttributes& other)
{
    this->type = other.type;
    this->length = other.length;
}

void BgpUpdatePathAttributes::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->length);
}

void BgpUpdatePathAttributes::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->length);
}

const BgpUpdateAttributeType& BgpUpdatePathAttributes::getType() const
{
    return this->type;
}

void BgpUpdatePathAttributes::setType(const BgpUpdateAttributeType& type)
{
    this->type = type;
}

unsigned short BgpUpdatePathAttributes::getLength() const
{
    return this->length;
}

void BgpUpdatePathAttributes::setLength(unsigned short length)
{
    this->length = length;
}

class BgpUpdatePathAttributesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_length,
    };
  public:
    BgpUpdatePathAttributesDescriptor();
    virtual ~BgpUpdatePathAttributesDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesDescriptor)

BgpUpdatePathAttributesDescriptor::BgpUpdatePathAttributesDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributes)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesDescriptor::~BgpUpdatePathAttributesDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributes *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BgpUpdatePathAttributesDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_length
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "length",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bgp::BgpUpdateAttributeType",    // FIELD_type
        "unsigned short",    // FIELD_length
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdatePathAttributesDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdatePathAttributesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributes *pp = (BgpUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpUpdatePathAttributesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributes *pp = (BgpUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributes *pp = (BgpUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        case FIELD_type: {std::stringstream out; out << pp->getType(); return out.str();}
        case FIELD_length: return ulong2string(pp->getLength());
        default: return "";
    }
}

bool BgpUpdatePathAttributesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributes *pp = (BgpUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        case FIELD_length: pp->setLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *BgpUpdatePathAttributesDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type: return omnetpp::opp_typename(typeid(BgpUpdateAttributeType));
        default: return nullptr;
    };
}

void *BgpUpdatePathAttributesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributes *pp = (BgpUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        case FIELD_type: return toVoidPtr(&pp->getType()); break;
        default: return nullptr;
    }
}

Register_Class(BgpUpdatePathAttributesOrigin)

BgpUpdatePathAttributesOrigin::BgpUpdatePathAttributesOrigin() : ::inet::bgp::BgpUpdatePathAttributes()
{
}

BgpUpdatePathAttributesOrigin::BgpUpdatePathAttributesOrigin(const BgpUpdatePathAttributesOrigin& other) : ::inet::bgp::BgpUpdatePathAttributes(other)
{
    copy(other);
}

BgpUpdatePathAttributesOrigin::~BgpUpdatePathAttributesOrigin()
{
}

BgpUpdatePathAttributesOrigin& BgpUpdatePathAttributesOrigin::operator=(const BgpUpdatePathAttributesOrigin& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributesOrigin::copy(const BgpUpdatePathAttributesOrigin& other)
{
    this->value = other.value;
}

void BgpUpdatePathAttributesOrigin::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->value);
}

void BgpUpdatePathAttributesOrigin::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

inet::bgp::BgpSessionType BgpUpdatePathAttributesOrigin::getValue() const
{
    return this->value;
}

void BgpUpdatePathAttributesOrigin::setValue(inet::bgp::BgpSessionType value)
{
    this->value = value;
}

class BgpUpdatePathAttributesOriginDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_value,
    };
  public:
    BgpUpdatePathAttributesOriginDescriptor();
    virtual ~BgpUpdatePathAttributesOriginDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesOriginDescriptor)

BgpUpdatePathAttributesOriginDescriptor::BgpUpdatePathAttributesOriginDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributesOrigin)), "inet::bgp::BgpUpdatePathAttributes")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesOriginDescriptor::~BgpUpdatePathAttributesOriginDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesOriginDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributesOrigin *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesOriginDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesOriginDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesOriginDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BgpUpdatePathAttributesOriginDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesOriginDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesOriginDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesOriginDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bgp::BgpSessionType",    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesOriginDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_value: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *BgpUpdatePathAttributesOriginDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_value:
            if (!strcmp(propertyname, "enum")) return "inet::bgp::BgpSessionType";
            return nullptr;
        default: return nullptr;
    }
}

int BgpUpdatePathAttributesOriginDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesOrigin *pp = (BgpUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpUpdatePathAttributesOriginDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesOrigin *pp = (BgpUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesOriginDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesOrigin *pp = (BgpUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        case FIELD_value: return enum2string(pp->getValue(), "inet::bgp::BgpSessionType");
        default: return "";
    }
}

bool BgpUpdatePathAttributesOriginDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesOrigin *pp = (BgpUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BgpUpdatePathAttributesOriginDescriptor::getFieldStructName(int field) const
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

void *BgpUpdatePathAttributesOriginDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesOrigin *pp = (BgpUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(BgpUpdatePathAttributesAsPath)

BgpUpdatePathAttributesAsPath::BgpUpdatePathAttributesAsPath() : ::inet::bgp::BgpUpdatePathAttributes()
{
}

BgpUpdatePathAttributesAsPath::BgpUpdatePathAttributesAsPath(const BgpUpdatePathAttributesAsPath& other) : ::inet::bgp::BgpUpdatePathAttributes(other)
{
    copy(other);
}

BgpUpdatePathAttributesAsPath::~BgpUpdatePathAttributesAsPath()
{
    delete [] this->value;
}

BgpUpdatePathAttributesAsPath& BgpUpdatePathAttributesAsPath::operator=(const BgpUpdatePathAttributesAsPath& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributesAsPath::copy(const BgpUpdatePathAttributesAsPath& other)
{
    delete [] this->value;
    this->value = (other.value_arraysize==0) ? nullptr : new BgpAsPathSegment[other.value_arraysize];
    value_arraysize = other.value_arraysize;
    for (size_t i = 0; i < value_arraysize; i++) {
        this->value[i] = other.value[i];
    }
}

void BgpUpdatePathAttributesAsPath::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimPack(b);
    b->pack(value_arraysize);
    doParsimArrayPacking(b,this->value,value_arraysize);
}

void BgpUpdatePathAttributesAsPath::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimUnpack(b);
    delete [] this->value;
    b->unpack(value_arraysize);
    if (value_arraysize == 0) {
        this->value = nullptr;
    } else {
        this->value = new BgpAsPathSegment[value_arraysize];
        doParsimArrayUnpacking(b,this->value,value_arraysize);
    }
}

size_t BgpUpdatePathAttributesAsPath::getValueArraySize() const
{
    return value_arraysize;
}

const BgpAsPathSegment& BgpUpdatePathAttributesAsPath::getValue(size_t k) const
{
    if (k >= value_arraysize) throw omnetpp::cRuntimeError("Array of size value_arraysize indexed by %lu", (unsigned long)k);
    return this->value[k];
}

void BgpUpdatePathAttributesAsPath::setValueArraySize(size_t newSize)
{
    BgpAsPathSegment *value2 = (newSize==0) ? nullptr : new BgpAsPathSegment[newSize];
    size_t minSize = value_arraysize < newSize ? value_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        value2[i] = this->value[i];
    delete [] this->value;
    this->value = value2;
    value_arraysize = newSize;
}

void BgpUpdatePathAttributesAsPath::setValue(size_t k, const BgpAsPathSegment& value)
{
    if (k >= value_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->value[k] = value;
}

void BgpUpdatePathAttributesAsPath::insertValue(size_t k, const BgpAsPathSegment& value)
{
    if (k > value_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = value_arraysize + 1;
    BgpAsPathSegment *value2 = new BgpAsPathSegment[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        value2[i] = this->value[i];
    value2[k] = value;
    for (i = k + 1; i < newSize; i++)
        value2[i] = this->value[i-1];
    delete [] this->value;
    this->value = value2;
    value_arraysize = newSize;
}

void BgpUpdatePathAttributesAsPath::insertValue(const BgpAsPathSegment& value)
{
    insertValue(value_arraysize, value);
}

void BgpUpdatePathAttributesAsPath::eraseValue(size_t k)
{
    if (k >= value_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = value_arraysize - 1;
    BgpAsPathSegment *value2 = (newSize == 0) ? nullptr : new BgpAsPathSegment[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        value2[i] = this->value[i];
    for (i = k; i < newSize; i++)
        value2[i] = this->value[i+1];
    delete [] this->value;
    this->value = value2;
    value_arraysize = newSize;
}

class BgpUpdatePathAttributesAsPathDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_value,
    };
  public:
    BgpUpdatePathAttributesAsPathDescriptor();
    virtual ~BgpUpdatePathAttributesAsPathDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesAsPathDescriptor)

BgpUpdatePathAttributesAsPathDescriptor::BgpUpdatePathAttributesAsPathDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributesAsPath)), "inet::bgp::BgpUpdatePathAttributes")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesAsPathDescriptor::~BgpUpdatePathAttributesAsPathDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesAsPathDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributesAsPath *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesAsPathDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesAsPathDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesAsPathDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BgpUpdatePathAttributesAsPathDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesAsPathDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesAsPathDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesAsPathDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bgp::BgpAsPathSegment",    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesAsPathDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdatePathAttributesAsPathDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdatePathAttributesAsPathDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAsPath *pp = (BgpUpdatePathAttributesAsPath *)object; (void)pp;
    switch (field) {
        case FIELD_value: return pp->getValueArraySize();
        default: return 0;
    }
}

const char *BgpUpdatePathAttributesAsPathDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAsPath *pp = (BgpUpdatePathAttributesAsPath *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesAsPathDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAsPath *pp = (BgpUpdatePathAttributesAsPath *)object; (void)pp;
    switch (field) {
        case FIELD_value: {std::stringstream out; out << pp->getValue(i); return out.str();}
        default: return "";
    }
}

bool BgpUpdatePathAttributesAsPathDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAsPath *pp = (BgpUpdatePathAttributesAsPath *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BgpUpdatePathAttributesAsPathDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_value: return omnetpp::opp_typename(typeid(BgpAsPathSegment));
        default: return nullptr;
    };
}

void *BgpUpdatePathAttributesAsPathDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAsPath *pp = (BgpUpdatePathAttributesAsPath *)object; (void)pp;
    switch (field) {
        case FIELD_value: return toVoidPtr(&pp->getValue(i)); break;
        default: return nullptr;
    }
}

Register_Class(BgpUpdatePathAttributesNextHop)

BgpUpdatePathAttributesNextHop::BgpUpdatePathAttributesNextHop() : ::inet::bgp::BgpUpdatePathAttributes()
{
}

BgpUpdatePathAttributesNextHop::BgpUpdatePathAttributesNextHop(const BgpUpdatePathAttributesNextHop& other) : ::inet::bgp::BgpUpdatePathAttributes(other)
{
    copy(other);
}

BgpUpdatePathAttributesNextHop::~BgpUpdatePathAttributesNextHop()
{
}

BgpUpdatePathAttributesNextHop& BgpUpdatePathAttributesNextHop::operator=(const BgpUpdatePathAttributesNextHop& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributesNextHop::copy(const BgpUpdatePathAttributesNextHop& other)
{
    this->value = other.value;
}

void BgpUpdatePathAttributesNextHop::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->value);
}

void BgpUpdatePathAttributesNextHop::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

const Ipv4Address& BgpUpdatePathAttributesNextHop::getValue() const
{
    return this->value;
}

void BgpUpdatePathAttributesNextHop::setValue(const Ipv4Address& value)
{
    this->value = value;
}

class BgpUpdatePathAttributesNextHopDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_value,
    };
  public:
    BgpUpdatePathAttributesNextHopDescriptor();
    virtual ~BgpUpdatePathAttributesNextHopDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesNextHopDescriptor)

BgpUpdatePathAttributesNextHopDescriptor::BgpUpdatePathAttributesNextHopDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributesNextHop)), "inet::bgp::BgpUpdatePathAttributes")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesNextHopDescriptor::~BgpUpdatePathAttributesNextHopDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesNextHopDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributesNextHop *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesNextHopDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesNextHopDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesNextHopDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BgpUpdatePathAttributesNextHopDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesNextHopDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesNextHopDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesNextHopDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesNextHopDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdatePathAttributesNextHopDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdatePathAttributesNextHopDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesNextHop *pp = (BgpUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpUpdatePathAttributesNextHopDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesNextHop *pp = (BgpUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesNextHopDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesNextHop *pp = (BgpUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        case FIELD_value: return pp->getValue().str();
        default: return "";
    }
}

bool BgpUpdatePathAttributesNextHopDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesNextHop *pp = (BgpUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BgpUpdatePathAttributesNextHopDescriptor::getFieldStructName(int field) const
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

void *BgpUpdatePathAttributesNextHopDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesNextHop *pp = (BgpUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        case FIELD_value: return toVoidPtr(&pp->getValue()); break;
        default: return nullptr;
    }
}

Register_Class(BgpUpdatePathAttributesLocalPref)

BgpUpdatePathAttributesLocalPref::BgpUpdatePathAttributesLocalPref() : ::inet::bgp::BgpUpdatePathAttributes()
{
}

BgpUpdatePathAttributesLocalPref::BgpUpdatePathAttributesLocalPref(const BgpUpdatePathAttributesLocalPref& other) : ::inet::bgp::BgpUpdatePathAttributes(other)
{
    copy(other);
}

BgpUpdatePathAttributesLocalPref::~BgpUpdatePathAttributesLocalPref()
{
}

BgpUpdatePathAttributesLocalPref& BgpUpdatePathAttributesLocalPref::operator=(const BgpUpdatePathAttributesLocalPref& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributesLocalPref::copy(const BgpUpdatePathAttributesLocalPref& other)
{
    this->value = other.value;
}

void BgpUpdatePathAttributesLocalPref::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->value);
}

void BgpUpdatePathAttributesLocalPref::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

unsigned int BgpUpdatePathAttributesLocalPref::getValue() const
{
    return this->value;
}

void BgpUpdatePathAttributesLocalPref::setValue(unsigned int value)
{
    this->value = value;
}

class BgpUpdatePathAttributesLocalPrefDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_value,
    };
  public:
    BgpUpdatePathAttributesLocalPrefDescriptor();
    virtual ~BgpUpdatePathAttributesLocalPrefDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesLocalPrefDescriptor)

BgpUpdatePathAttributesLocalPrefDescriptor::BgpUpdatePathAttributesLocalPrefDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributesLocalPref)), "inet::bgp::BgpUpdatePathAttributes")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesLocalPrefDescriptor::~BgpUpdatePathAttributesLocalPrefDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesLocalPrefDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributesLocalPref *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesLocalPrefDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesLocalPrefDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesLocalPrefDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BgpUpdatePathAttributesLocalPrefDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesLocalPrefDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesLocalPrefDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesLocalPrefDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesLocalPrefDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdatePathAttributesLocalPrefDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdatePathAttributesLocalPrefDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesLocalPref *pp = (BgpUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpUpdatePathAttributesLocalPrefDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesLocalPref *pp = (BgpUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesLocalPrefDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesLocalPref *pp = (BgpUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        case FIELD_value: return ulong2string(pp->getValue());
        default: return "";
    }
}

bool BgpUpdatePathAttributesLocalPrefDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesLocalPref *pp = (BgpUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        case FIELD_value: pp->setValue(string2ulong(value)); return true;
        default: return false;
    }
}

const char *BgpUpdatePathAttributesLocalPrefDescriptor::getFieldStructName(int field) const
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

void *BgpUpdatePathAttributesLocalPrefDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesLocalPref *pp = (BgpUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::bgp::BgpUpdateAtomicAggregateValues");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::bgp::BgpUpdateAtomicAggregateValues"));
    e->insert(NO_SPECIFIC_ROUTE, "NO_SPECIFIC_ROUTE");
    e->insert(SPECIFIC_ROUTE, "SPECIFIC_ROUTE");
)

Register_Class(BgpUpdatePathAttributesAtomicAggregate)

BgpUpdatePathAttributesAtomicAggregate::BgpUpdatePathAttributesAtomicAggregate() : ::inet::bgp::BgpUpdatePathAttributes()
{
}

BgpUpdatePathAttributesAtomicAggregate::BgpUpdatePathAttributesAtomicAggregate(const BgpUpdatePathAttributesAtomicAggregate& other) : ::inet::bgp::BgpUpdatePathAttributes(other)
{
    copy(other);
}

BgpUpdatePathAttributesAtomicAggregate::~BgpUpdatePathAttributesAtomicAggregate()
{
}

BgpUpdatePathAttributesAtomicAggregate& BgpUpdatePathAttributesAtomicAggregate::operator=(const BgpUpdatePathAttributesAtomicAggregate& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributesAtomicAggregate::copy(const BgpUpdatePathAttributesAtomicAggregate& other)
{
    this->value = other.value;
}

void BgpUpdatePathAttributesAtomicAggregate::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->value);
}

void BgpUpdatePathAttributesAtomicAggregate::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

inet::bgp::BgpUpdateAtomicAggregateValues BgpUpdatePathAttributesAtomicAggregate::getValue() const
{
    return this->value;
}

void BgpUpdatePathAttributesAtomicAggregate::setValue(inet::bgp::BgpUpdateAtomicAggregateValues value)
{
    this->value = value;
}

class BgpUpdatePathAttributesAtomicAggregateDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_value,
    };
  public:
    BgpUpdatePathAttributesAtomicAggregateDescriptor();
    virtual ~BgpUpdatePathAttributesAtomicAggregateDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributesAtomicAggregateDescriptor)

BgpUpdatePathAttributesAtomicAggregateDescriptor::BgpUpdatePathAttributesAtomicAggregateDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributesAtomicAggregate)), "inet::bgp::BgpUpdatePathAttributes")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributesAtomicAggregateDescriptor::~BgpUpdatePathAttributesAtomicAggregateDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributesAtomicAggregateDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributesAtomicAggregate *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributesAtomicAggregateDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributesAtomicAggregateDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributesAtomicAggregateDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bgp::BgpUpdateAtomicAggregateValues",    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_value: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_value:
            if (!strcmp(propertyname, "enum")) return "inet::bgp::BgpUpdateAtomicAggregateValues";
            return nullptr;
        default: return nullptr;
    }
}

int BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAtomicAggregate *pp = (BgpUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAtomicAggregate *pp = (BgpUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAtomicAggregate *pp = (BgpUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        case FIELD_value: return enum2string(pp->getValue(), "inet::bgp::BgpUpdateAtomicAggregateValues");
        default: return "";
    }
}

bool BgpUpdatePathAttributesAtomicAggregateDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAtomicAggregate *pp = (BgpUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldStructName(int field) const
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

void *BgpUpdatePathAttributesAtomicAggregateDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributesAtomicAggregate *pp = (BgpUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

BgpUpdateWithdrawnRoutes::BgpUpdateWithdrawnRoutes()
{
    this->length = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const BgpUpdateWithdrawnRoutes& a)
{
    doParsimPacking(b,a.length);
    doParsimPacking(b,a.prefix);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BgpUpdateWithdrawnRoutes& a)
{
    doParsimUnpacking(b,a.length);
    doParsimUnpacking(b,a.prefix);
}

class BgpUpdateWithdrawnRoutesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_length,
        FIELD_prefix,
    };
  public:
    BgpUpdateWithdrawnRoutesDescriptor();
    virtual ~BgpUpdateWithdrawnRoutesDescriptor();

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

Register_ClassDescriptor(BgpUpdateWithdrawnRoutesDescriptor)

BgpUpdateWithdrawnRoutesDescriptor::BgpUpdateWithdrawnRoutesDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdateWithdrawnRoutes)), "")
{
    propertynames = nullptr;
}

BgpUpdateWithdrawnRoutesDescriptor::~BgpUpdateWithdrawnRoutesDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdateWithdrawnRoutesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdateWithdrawnRoutes *>(obj)!=nullptr;
}

const char **BgpUpdateWithdrawnRoutesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdateWithdrawnRoutesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdateWithdrawnRoutesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BgpUpdateWithdrawnRoutesDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_length
        0,    // FIELD_prefix
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdateWithdrawnRoutesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "length",
        "prefix",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int BgpUpdateWithdrawnRoutesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "prefix") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdateWithdrawnRoutesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",    // FIELD_length
        "inet::Ipv4Address",    // FIELD_prefix
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdateWithdrawnRoutesDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdateWithdrawnRoutesDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdateWithdrawnRoutesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateWithdrawnRoutes *pp = (BgpUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpUpdateWithdrawnRoutesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateWithdrawnRoutes *pp = (BgpUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdateWithdrawnRoutesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateWithdrawnRoutes *pp = (BgpUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        case FIELD_length: return ulong2string(pp->length);
        case FIELD_prefix: return pp->prefix.str();
        default: return "";
    }
}

bool BgpUpdateWithdrawnRoutesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateWithdrawnRoutes *pp = (BgpUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        case FIELD_length: pp->length = string2ulong(value); return true;
        default: return false;
    }
}

const char *BgpUpdateWithdrawnRoutesDescriptor::getFieldStructName(int field) const
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

void *BgpUpdateWithdrawnRoutesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateWithdrawnRoutes *pp = (BgpUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        case FIELD_prefix: return toVoidPtr(&pp->prefix); break;
        default: return nullptr;
    }
}

BgpUpdateNlri::BgpUpdateNlri()
{
    this->length = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const BgpUpdateNlri& a)
{
    doParsimPacking(b,a.length);
    doParsimPacking(b,a.prefix);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BgpUpdateNlri& a)
{
    doParsimUnpacking(b,a.length);
    doParsimUnpacking(b,a.prefix);
}

class BgpUpdateNlriDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_length,
        FIELD_prefix,
    };
  public:
    BgpUpdateNlriDescriptor();
    virtual ~BgpUpdateNlriDescriptor();

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

Register_ClassDescriptor(BgpUpdateNlriDescriptor)

BgpUpdateNlriDescriptor::BgpUpdateNlriDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdateNlri)), "")
{
    propertynames = nullptr;
}

BgpUpdateNlriDescriptor::~BgpUpdateNlriDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdateNlriDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdateNlri *>(obj)!=nullptr;
}

const char **BgpUpdateNlriDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdateNlriDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdateNlriDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BgpUpdateNlriDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_length
        0,    // FIELD_prefix
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdateNlriDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "length",
        "prefix",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int BgpUpdateNlriDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "prefix") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdateNlriDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",    // FIELD_length
        "inet::Ipv4Address",    // FIELD_prefix
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdateNlriDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdateNlriDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdateNlriDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateNlri *pp = (BgpUpdateNlri *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BgpUpdateNlriDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateNlri *pp = (BgpUpdateNlri *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdateNlriDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateNlri *pp = (BgpUpdateNlri *)object; (void)pp;
    switch (field) {
        case FIELD_length: return ulong2string(pp->length);
        case FIELD_prefix: return pp->prefix.str();
        default: return "";
    }
}

bool BgpUpdateNlriDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateNlri *pp = (BgpUpdateNlri *)object; (void)pp;
    switch (field) {
        case FIELD_length: pp->length = string2ulong(value); return true;
        default: return false;
    }
}

const char *BgpUpdateNlriDescriptor::getFieldStructName(int field) const
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

void *BgpUpdateNlriDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateNlri *pp = (BgpUpdateNlri *)object; (void)pp;
    switch (field) {
        case FIELD_prefix: return toVoidPtr(&pp->prefix); break;
        default: return nullptr;
    }
}

Register_Class(BgpUpdatePathAttributeList)

BgpUpdatePathAttributeList::BgpUpdatePathAttributeList() : ::omnetpp::cObject()
{
}

BgpUpdatePathAttributeList::BgpUpdatePathAttributeList(const BgpUpdatePathAttributeList& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

BgpUpdatePathAttributeList::~BgpUpdatePathAttributeList()
{
    delete [] this->asPath;
    delete [] this->localPref;
    delete [] this->atomicAggregate;
}

BgpUpdatePathAttributeList& BgpUpdatePathAttributeList::operator=(const BgpUpdatePathAttributeList& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdatePathAttributeList::copy(const BgpUpdatePathAttributeList& other)
{
    this->origin = other.origin;
    delete [] this->asPath;
    this->asPath = (other.asPath_arraysize==0) ? nullptr : new BgpUpdatePathAttributesAsPath[other.asPath_arraysize];
    asPath_arraysize = other.asPath_arraysize;
    for (size_t i = 0; i < asPath_arraysize; i++) {
        this->asPath[i] = other.asPath[i];
    }
    this->nextHop = other.nextHop;
    delete [] this->localPref;
    this->localPref = (other.localPref_arraysize==0) ? nullptr : new BgpUpdatePathAttributesLocalPref[other.localPref_arraysize];
    localPref_arraysize = other.localPref_arraysize;
    for (size_t i = 0; i < localPref_arraysize; i++) {
        this->localPref[i] = other.localPref[i];
    }
    delete [] this->atomicAggregate;
    this->atomicAggregate = (other.atomicAggregate_arraysize==0) ? nullptr : new BgpUpdatePathAttributesAtomicAggregate[other.atomicAggregate_arraysize];
    atomicAggregate_arraysize = other.atomicAggregate_arraysize;
    for (size_t i = 0; i < atomicAggregate_arraysize; i++) {
        this->atomicAggregate[i] = other.atomicAggregate[i];
    }
}

void BgpUpdatePathAttributeList::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->origin);
    b->pack(asPath_arraysize);
    doParsimArrayPacking(b,this->asPath,asPath_arraysize);
    doParsimPacking(b,this->nextHop);
    b->pack(localPref_arraysize);
    doParsimArrayPacking(b,this->localPref,localPref_arraysize);
    b->pack(atomicAggregate_arraysize);
    doParsimArrayPacking(b,this->atomicAggregate,atomicAggregate_arraysize);
}

void BgpUpdatePathAttributeList::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->origin);
    delete [] this->asPath;
    b->unpack(asPath_arraysize);
    if (asPath_arraysize == 0) {
        this->asPath = nullptr;
    } else {
        this->asPath = new BgpUpdatePathAttributesAsPath[asPath_arraysize];
        doParsimArrayUnpacking(b,this->asPath,asPath_arraysize);
    }
    doParsimUnpacking(b,this->nextHop);
    delete [] this->localPref;
    b->unpack(localPref_arraysize);
    if (localPref_arraysize == 0) {
        this->localPref = nullptr;
    } else {
        this->localPref = new BgpUpdatePathAttributesLocalPref[localPref_arraysize];
        doParsimArrayUnpacking(b,this->localPref,localPref_arraysize);
    }
    delete [] this->atomicAggregate;
    b->unpack(atomicAggregate_arraysize);
    if (atomicAggregate_arraysize == 0) {
        this->atomicAggregate = nullptr;
    } else {
        this->atomicAggregate = new BgpUpdatePathAttributesAtomicAggregate[atomicAggregate_arraysize];
        doParsimArrayUnpacking(b,this->atomicAggregate,atomicAggregate_arraysize);
    }
}

const BgpUpdatePathAttributesOrigin& BgpUpdatePathAttributeList::getOrigin() const
{
    return this->origin;
}

void BgpUpdatePathAttributeList::setOrigin(const BgpUpdatePathAttributesOrigin& origin)
{
    this->origin = origin;
}

size_t BgpUpdatePathAttributeList::getAsPathArraySize() const
{
    return asPath_arraysize;
}

const BgpUpdatePathAttributesAsPath& BgpUpdatePathAttributeList::getAsPath(size_t k) const
{
    if (k >= asPath_arraysize) throw omnetpp::cRuntimeError("Array of size asPath_arraysize indexed by %lu", (unsigned long)k);
    return this->asPath[k];
}

void BgpUpdatePathAttributeList::setAsPathArraySize(size_t newSize)
{
    BgpUpdatePathAttributesAsPath *asPath2 = (newSize==0) ? nullptr : new BgpUpdatePathAttributesAsPath[newSize];
    size_t minSize = asPath_arraysize < newSize ? asPath_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        asPath2[i] = this->asPath[i];
    delete [] this->asPath;
    this->asPath = asPath2;
    asPath_arraysize = newSize;
}

void BgpUpdatePathAttributeList::setAsPath(size_t k, const BgpUpdatePathAttributesAsPath& asPath)
{
    if (k >= asPath_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->asPath[k] = asPath;
}

void BgpUpdatePathAttributeList::insertAsPath(size_t k, const BgpUpdatePathAttributesAsPath& asPath)
{
    if (k > asPath_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = asPath_arraysize + 1;
    BgpUpdatePathAttributesAsPath *asPath2 = new BgpUpdatePathAttributesAsPath[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        asPath2[i] = this->asPath[i];
    asPath2[k] = asPath;
    for (i = k + 1; i < newSize; i++)
        asPath2[i] = this->asPath[i-1];
    delete [] this->asPath;
    this->asPath = asPath2;
    asPath_arraysize = newSize;
}

void BgpUpdatePathAttributeList::insertAsPath(const BgpUpdatePathAttributesAsPath& asPath)
{
    insertAsPath(asPath_arraysize, asPath);
}

void BgpUpdatePathAttributeList::eraseAsPath(size_t k)
{
    if (k >= asPath_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = asPath_arraysize - 1;
    BgpUpdatePathAttributesAsPath *asPath2 = (newSize == 0) ? nullptr : new BgpUpdatePathAttributesAsPath[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        asPath2[i] = this->asPath[i];
    for (i = k; i < newSize; i++)
        asPath2[i] = this->asPath[i+1];
    delete [] this->asPath;
    this->asPath = asPath2;
    asPath_arraysize = newSize;
}

const BgpUpdatePathAttributesNextHop& BgpUpdatePathAttributeList::getNextHop() const
{
    return this->nextHop;
}

void BgpUpdatePathAttributeList::setNextHop(const BgpUpdatePathAttributesNextHop& nextHop)
{
    this->nextHop = nextHop;
}

size_t BgpUpdatePathAttributeList::getLocalPrefArraySize() const
{
    return localPref_arraysize;
}

const BgpUpdatePathAttributesLocalPref& BgpUpdatePathAttributeList::getLocalPref(size_t k) const
{
    if (k >= localPref_arraysize) throw omnetpp::cRuntimeError("Array of size localPref_arraysize indexed by %lu", (unsigned long)k);
    return this->localPref[k];
}

void BgpUpdatePathAttributeList::setLocalPrefArraySize(size_t newSize)
{
    BgpUpdatePathAttributesLocalPref *localPref2 = (newSize==0) ? nullptr : new BgpUpdatePathAttributesLocalPref[newSize];
    size_t minSize = localPref_arraysize < newSize ? localPref_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        localPref2[i] = this->localPref[i];
    delete [] this->localPref;
    this->localPref = localPref2;
    localPref_arraysize = newSize;
}

void BgpUpdatePathAttributeList::setLocalPref(size_t k, const BgpUpdatePathAttributesLocalPref& localPref)
{
    if (k >= localPref_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->localPref[k] = localPref;
}

void BgpUpdatePathAttributeList::insertLocalPref(size_t k, const BgpUpdatePathAttributesLocalPref& localPref)
{
    if (k > localPref_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = localPref_arraysize + 1;
    BgpUpdatePathAttributesLocalPref *localPref2 = new BgpUpdatePathAttributesLocalPref[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        localPref2[i] = this->localPref[i];
    localPref2[k] = localPref;
    for (i = k + 1; i < newSize; i++)
        localPref2[i] = this->localPref[i-1];
    delete [] this->localPref;
    this->localPref = localPref2;
    localPref_arraysize = newSize;
}

void BgpUpdatePathAttributeList::insertLocalPref(const BgpUpdatePathAttributesLocalPref& localPref)
{
    insertLocalPref(localPref_arraysize, localPref);
}

void BgpUpdatePathAttributeList::eraseLocalPref(size_t k)
{
    if (k >= localPref_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = localPref_arraysize - 1;
    BgpUpdatePathAttributesLocalPref *localPref2 = (newSize == 0) ? nullptr : new BgpUpdatePathAttributesLocalPref[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        localPref2[i] = this->localPref[i];
    for (i = k; i < newSize; i++)
        localPref2[i] = this->localPref[i+1];
    delete [] this->localPref;
    this->localPref = localPref2;
    localPref_arraysize = newSize;
}

size_t BgpUpdatePathAttributeList::getAtomicAggregateArraySize() const
{
    return atomicAggregate_arraysize;
}

const BgpUpdatePathAttributesAtomicAggregate& BgpUpdatePathAttributeList::getAtomicAggregate(size_t k) const
{
    if (k >= atomicAggregate_arraysize) throw omnetpp::cRuntimeError("Array of size atomicAggregate_arraysize indexed by %lu", (unsigned long)k);
    return this->atomicAggregate[k];
}

void BgpUpdatePathAttributeList::setAtomicAggregateArraySize(size_t newSize)
{
    BgpUpdatePathAttributesAtomicAggregate *atomicAggregate2 = (newSize==0) ? nullptr : new BgpUpdatePathAttributesAtomicAggregate[newSize];
    size_t minSize = atomicAggregate_arraysize < newSize ? atomicAggregate_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        atomicAggregate2[i] = this->atomicAggregate[i];
    delete [] this->atomicAggregate;
    this->atomicAggregate = atomicAggregate2;
    atomicAggregate_arraysize = newSize;
}

void BgpUpdatePathAttributeList::setAtomicAggregate(size_t k, const BgpUpdatePathAttributesAtomicAggregate& atomicAggregate)
{
    if (k >= atomicAggregate_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->atomicAggregate[k] = atomicAggregate;
}

void BgpUpdatePathAttributeList::insertAtomicAggregate(size_t k, const BgpUpdatePathAttributesAtomicAggregate& atomicAggregate)
{
    if (k > atomicAggregate_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = atomicAggregate_arraysize + 1;
    BgpUpdatePathAttributesAtomicAggregate *atomicAggregate2 = new BgpUpdatePathAttributesAtomicAggregate[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        atomicAggregate2[i] = this->atomicAggregate[i];
    atomicAggregate2[k] = atomicAggregate;
    for (i = k + 1; i < newSize; i++)
        atomicAggregate2[i] = this->atomicAggregate[i-1];
    delete [] this->atomicAggregate;
    this->atomicAggregate = atomicAggregate2;
    atomicAggregate_arraysize = newSize;
}

void BgpUpdatePathAttributeList::insertAtomicAggregate(const BgpUpdatePathAttributesAtomicAggregate& atomicAggregate)
{
    insertAtomicAggregate(atomicAggregate_arraysize, atomicAggregate);
}

void BgpUpdatePathAttributeList::eraseAtomicAggregate(size_t k)
{
    if (k >= atomicAggregate_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = atomicAggregate_arraysize - 1;
    BgpUpdatePathAttributesAtomicAggregate *atomicAggregate2 = (newSize == 0) ? nullptr : new BgpUpdatePathAttributesAtomicAggregate[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        atomicAggregate2[i] = this->atomicAggregate[i];
    for (i = k; i < newSize; i++)
        atomicAggregate2[i] = this->atomicAggregate[i+1];
    delete [] this->atomicAggregate;
    this->atomicAggregate = atomicAggregate2;
    atomicAggregate_arraysize = newSize;
}

class BgpUpdatePathAttributeListDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_origin,
        FIELD_asPath,
        FIELD_nextHop,
        FIELD_localPref,
        FIELD_atomicAggregate,
    };
  public:
    BgpUpdatePathAttributeListDescriptor();
    virtual ~BgpUpdatePathAttributeListDescriptor();

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

Register_ClassDescriptor(BgpUpdatePathAttributeListDescriptor)

BgpUpdatePathAttributeListDescriptor::BgpUpdatePathAttributeListDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::bgp::BgpUpdatePathAttributeList)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

BgpUpdatePathAttributeListDescriptor::~BgpUpdatePathAttributeListDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdatePathAttributeListDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdatePathAttributeList *>(obj)!=nullptr;
}

const char **BgpUpdatePathAttributeListDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdatePathAttributeListDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdatePathAttributeListDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int BgpUpdatePathAttributeListDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_origin
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_asPath
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_nextHop
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_localPref
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_atomicAggregate
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdatePathAttributeListDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "origin",
        "asPath",
        "nextHop",
        "localPref",
        "atomicAggregate",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int BgpUpdatePathAttributeListDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "origin") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "asPath") == 0) return base+1;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextHop") == 0) return base+2;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localPref") == 0) return base+3;
    if (fieldName[0] == 'a' && strcmp(fieldName, "atomicAggregate") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdatePathAttributeListDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bgp::BgpUpdatePathAttributesOrigin",    // FIELD_origin
        "inet::bgp::BgpUpdatePathAttributesAsPath",    // FIELD_asPath
        "inet::bgp::BgpUpdatePathAttributesNextHop",    // FIELD_nextHop
        "inet::bgp::BgpUpdatePathAttributesLocalPref",    // FIELD_localPref
        "inet::bgp::BgpUpdatePathAttributesAtomicAggregate",    // FIELD_atomicAggregate
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdatePathAttributeListDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdatePathAttributeListDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdatePathAttributeListDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributeList *pp = (BgpUpdatePathAttributeList *)object; (void)pp;
    switch (field) {
        case FIELD_asPath: return pp->getAsPathArraySize();
        case FIELD_localPref: return pp->getLocalPrefArraySize();
        case FIELD_atomicAggregate: return pp->getAtomicAggregateArraySize();
        default: return 0;
    }
}

const char *BgpUpdatePathAttributeListDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributeList *pp = (BgpUpdatePathAttributeList *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdatePathAttributeListDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributeList *pp = (BgpUpdatePathAttributeList *)object; (void)pp;
    switch (field) {
        case FIELD_origin: {std::stringstream out; out << pp->getOrigin(); return out.str();}
        case FIELD_asPath: {std::stringstream out; out << pp->getAsPath(i); return out.str();}
        case FIELD_nextHop: {std::stringstream out; out << pp->getNextHop(); return out.str();}
        case FIELD_localPref: {std::stringstream out; out << pp->getLocalPref(i); return out.str();}
        case FIELD_atomicAggregate: {std::stringstream out; out << pp->getAtomicAggregate(i); return out.str();}
        default: return "";
    }
}

bool BgpUpdatePathAttributeListDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributeList *pp = (BgpUpdatePathAttributeList *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BgpUpdatePathAttributeListDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_origin: return omnetpp::opp_typename(typeid(BgpUpdatePathAttributesOrigin));
        case FIELD_asPath: return omnetpp::opp_typename(typeid(BgpUpdatePathAttributesAsPath));
        case FIELD_nextHop: return omnetpp::opp_typename(typeid(BgpUpdatePathAttributesNextHop));
        case FIELD_localPref: return omnetpp::opp_typename(typeid(BgpUpdatePathAttributesLocalPref));
        case FIELD_atomicAggregate: return omnetpp::opp_typename(typeid(BgpUpdatePathAttributesAtomicAggregate));
        default: return nullptr;
    };
}

void *BgpUpdatePathAttributeListDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdatePathAttributeList *pp = (BgpUpdatePathAttributeList *)object; (void)pp;
    switch (field) {
        case FIELD_origin: return toVoidPtr(&pp->getOrigin()); break;
        case FIELD_asPath: return toVoidPtr(&pp->getAsPath(i)); break;
        case FIELD_nextHop: return toVoidPtr(&pp->getNextHop()); break;
        case FIELD_localPref: return toVoidPtr(&pp->getLocalPref(i)); break;
        case FIELD_atomicAggregate: return toVoidPtr(&pp->getAtomicAggregate(i)); break;
        default: return nullptr;
    }
}

BgpUpdateMessage_Base::BgpUpdateMessage_Base() : ::inet::bgp::BgpHeader()
{
    this->setType(BGP_UPDATE);
    this->setChunkLength(BGP_HEADER_OCTETS + BGP_EMPTY_UPDATE_OCTETS);

}

BgpUpdateMessage_Base::BgpUpdateMessage_Base(const BgpUpdateMessage_Base& other) : ::inet::bgp::BgpHeader(other)
{
    copy(other);
}

BgpUpdateMessage_Base::~BgpUpdateMessage_Base()
{
    delete [] this->withdrawnRoutes;
    delete [] this->pathAttributeList;
}

BgpUpdateMessage_Base& BgpUpdateMessage_Base::operator=(const BgpUpdateMessage_Base& other)
{
    if (this == &other) return *this;
    ::inet::bgp::BgpHeader::operator=(other);
    copy(other);
    return *this;
}

void BgpUpdateMessage_Base::copy(const BgpUpdateMessage_Base& other)
{
    delete [] this->withdrawnRoutes;
    this->withdrawnRoutes = (other.withdrawnRoutes_arraysize==0) ? nullptr : new BgpUpdateWithdrawnRoutes[other.withdrawnRoutes_arraysize];
    withdrawnRoutes_arraysize = other.withdrawnRoutes_arraysize;
    for (size_t i = 0; i < withdrawnRoutes_arraysize; i++) {
        this->withdrawnRoutes[i] = other.withdrawnRoutes[i];
    }
    delete [] this->pathAttributeList;
    this->pathAttributeList = (other.pathAttributeList_arraysize==0) ? nullptr : new BgpUpdatePathAttributeList[other.pathAttributeList_arraysize];
    pathAttributeList_arraysize = other.pathAttributeList_arraysize;
    for (size_t i = 0; i < pathAttributeList_arraysize; i++) {
        this->pathAttributeList[i] = other.pathAttributeList[i];
    }
    this->NLRI = other.NLRI;
}

void BgpUpdateMessage_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BgpHeader::parsimPack(b);
    b->pack(withdrawnRoutes_arraysize);
    doParsimArrayPacking(b,this->withdrawnRoutes,withdrawnRoutes_arraysize);
    b->pack(pathAttributeList_arraysize);
    doParsimArrayPacking(b,this->pathAttributeList,pathAttributeList_arraysize);
    doParsimPacking(b,this->NLRI);
}

void BgpUpdateMessage_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BgpHeader::parsimUnpack(b);
    delete [] this->withdrawnRoutes;
    b->unpack(withdrawnRoutes_arraysize);
    if (withdrawnRoutes_arraysize == 0) {
        this->withdrawnRoutes = nullptr;
    } else {
        this->withdrawnRoutes = new BgpUpdateWithdrawnRoutes[withdrawnRoutes_arraysize];
        doParsimArrayUnpacking(b,this->withdrawnRoutes,withdrawnRoutes_arraysize);
    }
    delete [] this->pathAttributeList;
    b->unpack(pathAttributeList_arraysize);
    if (pathAttributeList_arraysize == 0) {
        this->pathAttributeList = nullptr;
    } else {
        this->pathAttributeList = new BgpUpdatePathAttributeList[pathAttributeList_arraysize];
        doParsimArrayUnpacking(b,this->pathAttributeList,pathAttributeList_arraysize);
    }
    doParsimUnpacking(b,this->NLRI);
}

size_t BgpUpdateMessage_Base::getWithdrawnRoutesArraySize() const
{
    return withdrawnRoutes_arraysize;
}

const BgpUpdateWithdrawnRoutes& BgpUpdateMessage_Base::getWithdrawnRoutes(size_t k) const
{
    if (k >= withdrawnRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size withdrawnRoutes_arraysize indexed by %lu", (unsigned long)k);
    return this->withdrawnRoutes[k];
}

void BgpUpdateMessage_Base::setWithdrawnRoutesArraySize(size_t newSize)
{
    handleChange();
    BgpUpdateWithdrawnRoutes *withdrawnRoutes2 = (newSize==0) ? nullptr : new BgpUpdateWithdrawnRoutes[newSize];
    size_t minSize = withdrawnRoutes_arraysize < newSize ? withdrawnRoutes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        withdrawnRoutes2[i] = this->withdrawnRoutes[i];
    delete [] this->withdrawnRoutes;
    this->withdrawnRoutes = withdrawnRoutes2;
    withdrawnRoutes_arraysize = newSize;
}

void BgpUpdateMessage_Base::setWithdrawnRoutes(size_t k, const BgpUpdateWithdrawnRoutes& withdrawnRoutes)
{
    if (k >= withdrawnRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->withdrawnRoutes[k] = withdrawnRoutes;
}

void BgpUpdateMessage_Base::insertWithdrawnRoutes(size_t k, const BgpUpdateWithdrawnRoutes& withdrawnRoutes)
{
    handleChange();
    if (k > withdrawnRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = withdrawnRoutes_arraysize + 1;
    BgpUpdateWithdrawnRoutes *withdrawnRoutes2 = new BgpUpdateWithdrawnRoutes[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        withdrawnRoutes2[i] = this->withdrawnRoutes[i];
    withdrawnRoutes2[k] = withdrawnRoutes;
    for (i = k + 1; i < newSize; i++)
        withdrawnRoutes2[i] = this->withdrawnRoutes[i-1];
    delete [] this->withdrawnRoutes;
    this->withdrawnRoutes = withdrawnRoutes2;
    withdrawnRoutes_arraysize = newSize;
}

void BgpUpdateMessage_Base::insertWithdrawnRoutes(const BgpUpdateWithdrawnRoutes& withdrawnRoutes)
{
    insertWithdrawnRoutes(withdrawnRoutes_arraysize, withdrawnRoutes);
}

void BgpUpdateMessage_Base::eraseWithdrawnRoutes(size_t k)
{
    if (k >= withdrawnRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = withdrawnRoutes_arraysize - 1;
    BgpUpdateWithdrawnRoutes *withdrawnRoutes2 = (newSize == 0) ? nullptr : new BgpUpdateWithdrawnRoutes[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        withdrawnRoutes2[i] = this->withdrawnRoutes[i];
    for (i = k; i < newSize; i++)
        withdrawnRoutes2[i] = this->withdrawnRoutes[i+1];
    delete [] this->withdrawnRoutes;
    this->withdrawnRoutes = withdrawnRoutes2;
    withdrawnRoutes_arraysize = newSize;
}

size_t BgpUpdateMessage_Base::getPathAttributeListArraySize() const
{
    return pathAttributeList_arraysize;
}

const BgpUpdatePathAttributeList& BgpUpdateMessage_Base::getPathAttributeList(size_t k) const
{
    if (k >= pathAttributeList_arraysize) throw omnetpp::cRuntimeError("Array of size pathAttributeList_arraysize indexed by %lu", (unsigned long)k);
    return this->pathAttributeList[k];
}

void BgpUpdateMessage_Base::setPathAttributeListArraySize(size_t newSize)
{
    handleChange();
    BgpUpdatePathAttributeList *pathAttributeList2 = (newSize==0) ? nullptr : new BgpUpdatePathAttributeList[newSize];
    size_t minSize = pathAttributeList_arraysize < newSize ? pathAttributeList_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        pathAttributeList2[i] = this->pathAttributeList[i];
    delete [] this->pathAttributeList;
    this->pathAttributeList = pathAttributeList2;
    pathAttributeList_arraysize = newSize;
}

void BgpUpdateMessage_Base::setPathAttributeList(size_t k, const BgpUpdatePathAttributeList& pathAttributeList)
{
    if (k >= pathAttributeList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->pathAttributeList[k] = pathAttributeList;
}

void BgpUpdateMessage_Base::insertPathAttributeList(size_t k, const BgpUpdatePathAttributeList& pathAttributeList)
{
    handleChange();
    if (k > pathAttributeList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = pathAttributeList_arraysize + 1;
    BgpUpdatePathAttributeList *pathAttributeList2 = new BgpUpdatePathAttributeList[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        pathAttributeList2[i] = this->pathAttributeList[i];
    pathAttributeList2[k] = pathAttributeList;
    for (i = k + 1; i < newSize; i++)
        pathAttributeList2[i] = this->pathAttributeList[i-1];
    delete [] this->pathAttributeList;
    this->pathAttributeList = pathAttributeList2;
    pathAttributeList_arraysize = newSize;
}

void BgpUpdateMessage_Base::insertPathAttributeList(const BgpUpdatePathAttributeList& pathAttributeList)
{
    insertPathAttributeList(pathAttributeList_arraysize, pathAttributeList);
}

void BgpUpdateMessage_Base::erasePathAttributeList(size_t k)
{
    if (k >= pathAttributeList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = pathAttributeList_arraysize - 1;
    BgpUpdatePathAttributeList *pathAttributeList2 = (newSize == 0) ? nullptr : new BgpUpdatePathAttributeList[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        pathAttributeList2[i] = this->pathAttributeList[i];
    for (i = k; i < newSize; i++)
        pathAttributeList2[i] = this->pathAttributeList[i+1];
    delete [] this->pathAttributeList;
    this->pathAttributeList = pathAttributeList2;
    pathAttributeList_arraysize = newSize;
}

const BgpUpdateNlri& BgpUpdateMessage_Base::getNLRI() const
{
    return this->NLRI;
}

void BgpUpdateMessage_Base::setNLRI(const BgpUpdateNlri& NLRI)
{
    handleChange();
    this->NLRI = NLRI;
}

class BgpUpdateMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_withdrawnRoutes,
        FIELD_pathAttributeList,
        FIELD_NLRI,
    };
  public:
    BgpUpdateMessageDescriptor();
    virtual ~BgpUpdateMessageDescriptor();

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

Register_ClassDescriptor(BgpUpdateMessageDescriptor)

BgpUpdateMessageDescriptor::BgpUpdateMessageDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BgpUpdateMessage", "inet::bgp::BgpHeader")
{
    propertynames = nullptr;
}

BgpUpdateMessageDescriptor::~BgpUpdateMessageDescriptor()
{
    delete[] propertynames;
}

bool BgpUpdateMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BgpUpdateMessage_Base *>(obj)!=nullptr;
}

const char **BgpUpdateMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BgpUpdateMessageDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "customize")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BgpUpdateMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int BgpUpdateMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_withdrawnRoutes
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_pathAttributeList
        FD_ISCOMPOUND,    // FIELD_NLRI
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *BgpUpdateMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "withdrawnRoutes",
        "pathAttributeList",
        "NLRI",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int BgpUpdateMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'w' && strcmp(fieldName, "withdrawnRoutes") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pathAttributeList") == 0) return base+1;
    if (fieldName[0] == 'N' && strcmp(fieldName, "NLRI") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BgpUpdateMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bgp::BgpUpdateWithdrawnRoutes",    // FIELD_withdrawnRoutes
        "inet::bgp::BgpUpdatePathAttributeList",    // FIELD_pathAttributeList
        "inet::bgp::BgpUpdateNlri",    // FIELD_NLRI
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **BgpUpdateMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *BgpUpdateMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BgpUpdateMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateMessage_Base *pp = (BgpUpdateMessage_Base *)object; (void)pp;
    switch (field) {
        case FIELD_withdrawnRoutes: return pp->getWithdrawnRoutesArraySize();
        case FIELD_pathAttributeList: return pp->getPathAttributeListArraySize();
        default: return 0;
    }
}

const char *BgpUpdateMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateMessage_Base *pp = (BgpUpdateMessage_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BgpUpdateMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateMessage_Base *pp = (BgpUpdateMessage_Base *)object; (void)pp;
    switch (field) {
        case FIELD_withdrawnRoutes: {std::stringstream out; out << pp->getWithdrawnRoutes(i); return out.str();}
        case FIELD_pathAttributeList: {std::stringstream out; out << pp->getPathAttributeList(i); return out.str();}
        case FIELD_NLRI: {std::stringstream out; out << pp->getNLRI(); return out.str();}
        default: return "";
    }
}

bool BgpUpdateMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateMessage_Base *pp = (BgpUpdateMessage_Base *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BgpUpdateMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_withdrawnRoutes: return omnetpp::opp_typename(typeid(BgpUpdateWithdrawnRoutes));
        case FIELD_pathAttributeList: return omnetpp::opp_typename(typeid(BgpUpdatePathAttributeList));
        case FIELD_NLRI: return omnetpp::opp_typename(typeid(BgpUpdateNlri));
        default: return nullptr;
    };
}

void *BgpUpdateMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BgpUpdateMessage_Base *pp = (BgpUpdateMessage_Base *)object; (void)pp;
    switch (field) {
        case FIELD_withdrawnRoutes: return toVoidPtr(&pp->getWithdrawnRoutes(i)); break;
        case FIELD_pathAttributeList: return toVoidPtr(&pp->getPathAttributeList(i)); break;
        case FIELD_NLRI: return toVoidPtr(&pp->getNLRI()); break;
        default: return nullptr;
    }
}

} // namespace bgp
} // namespace inet

