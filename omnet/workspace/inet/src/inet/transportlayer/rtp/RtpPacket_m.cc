//
// Generated file, do not edit! Created by nedtool 5.6 from inet/transportlayer/rtp/RtpPacket.msg.
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
#include "RtpPacket_m.h"

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

Register_Class(RtpHeader)

RtpHeader::RtpHeader() : ::inet::FieldsChunk()
{
    this->setChunkLength(RTPPACKET_FIX_HEADERLENGTH);

}

RtpHeader::RtpHeader(const RtpHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

RtpHeader::~RtpHeader()
{
    delete [] this->csrc;
}

RtpHeader& RtpHeader::operator=(const RtpHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void RtpHeader::copy(const RtpHeader& other)
{
    this->version = other.version;
    this->padding = other.padding;
    this->extension = other.extension;
    this->marker = other.marker;
    this->payloadType = other.payloadType;
    this->sequenceNumber = other.sequenceNumber;
    this->timeStamp = other.timeStamp;
    this->ssrc = other.ssrc;
    delete [] this->csrc;
    this->csrc = (other.csrc_arraysize==0) ? nullptr : new uint32_t[other.csrc_arraysize];
    csrc_arraysize = other.csrc_arraysize;
    for (size_t i = 0; i < csrc_arraysize; i++) {
        this->csrc[i] = other.csrc[i];
    }
}

void RtpHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->padding);
    doParsimPacking(b,this->extension);
    doParsimPacking(b,this->marker);
    doParsimPacking(b,this->payloadType);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->timeStamp);
    doParsimPacking(b,this->ssrc);
    b->pack(csrc_arraysize);
    doParsimArrayPacking(b,this->csrc,csrc_arraysize);
}

void RtpHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->padding);
    doParsimUnpacking(b,this->extension);
    doParsimUnpacking(b,this->marker);
    doParsimUnpacking(b,this->payloadType);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->timeStamp);
    doParsimUnpacking(b,this->ssrc);
    delete [] this->csrc;
    b->unpack(csrc_arraysize);
    if (csrc_arraysize == 0) {
        this->csrc = nullptr;
    } else {
        this->csrc = new uint32_t[csrc_arraysize];
        doParsimArrayUnpacking(b,this->csrc,csrc_arraysize);
    }
}

uint8_t RtpHeader::getVersion() const
{
    return this->version;
}

void RtpHeader::setVersion(uint8_t version)
{
    handleChange();
    this->version = version;
}

bool RtpHeader::getPadding() const
{
    return this->padding;
}

void RtpHeader::setPadding(bool padding)
{
    handleChange();
    this->padding = padding;
}

bool RtpHeader::getExtension() const
{
    return this->extension;
}

void RtpHeader::setExtension(bool extension)
{
    handleChange();
    this->extension = extension;
}

bool RtpHeader::getMarker() const
{
    return this->marker;
}

void RtpHeader::setMarker(bool marker)
{
    handleChange();
    this->marker = marker;
}

int8_t RtpHeader::getPayloadType() const
{
    return this->payloadType;
}

void RtpHeader::setPayloadType(int8_t payloadType)
{
    handleChange();
    this->payloadType = payloadType;
}

uint16_t RtpHeader::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void RtpHeader::setSequenceNumber(uint16_t sequenceNumber)
{
    handleChange();
    this->sequenceNumber = sequenceNumber;
}

uint32_t RtpHeader::getTimeStamp() const
{
    return this->timeStamp;
}

void RtpHeader::setTimeStamp(uint32_t timeStamp)
{
    handleChange();
    this->timeStamp = timeStamp;
}

uint32_t RtpHeader::getSsrc() const
{
    return this->ssrc;
}

void RtpHeader::setSsrc(uint32_t ssrc)
{
    handleChange();
    this->ssrc = ssrc;
}

size_t RtpHeader::getCsrcArraySize() const
{
    return csrc_arraysize;
}

uint32_t RtpHeader::getCsrc(size_t k) const
{
    if (k >= csrc_arraysize) throw omnetpp::cRuntimeError("Array of size csrc_arraysize indexed by %lu", (unsigned long)k);
    return this->csrc[k];
}

void RtpHeader::setCsrcArraySize(size_t newSize)
{
    handleChange();
    uint32_t *csrc2 = (newSize==0) ? nullptr : new uint32_t[newSize];
    size_t minSize = csrc_arraysize < newSize ? csrc_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        csrc2[i] = this->csrc[i];
    for (size_t i = minSize; i < newSize; i++)
        csrc2[i] = 0;
    delete [] this->csrc;
    this->csrc = csrc2;
    csrc_arraysize = newSize;
}

void RtpHeader::setCsrc(size_t k, uint32_t csrc)
{
    if (k >= csrc_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->csrc[k] = csrc;
}

void RtpHeader::insertCsrc(size_t k, uint32_t csrc)
{
    handleChange();
    if (k > csrc_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = csrc_arraysize + 1;
    uint32_t *csrc2 = new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        csrc2[i] = this->csrc[i];
    csrc2[k] = csrc;
    for (i = k + 1; i < newSize; i++)
        csrc2[i] = this->csrc[i-1];
    delete [] this->csrc;
    this->csrc = csrc2;
    csrc_arraysize = newSize;
}

void RtpHeader::insertCsrc(uint32_t csrc)
{
    insertCsrc(csrc_arraysize, csrc);
}

void RtpHeader::eraseCsrc(size_t k)
{
    if (k >= csrc_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = csrc_arraysize - 1;
    uint32_t *csrc2 = (newSize == 0) ? nullptr : new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        csrc2[i] = this->csrc[i];
    for (i = k; i < newSize; i++)
        csrc2[i] = this->csrc[i+1];
    delete [] this->csrc;
    this->csrc = csrc2;
    csrc_arraysize = newSize;
}

class RtpHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_version,
        FIELD_padding,
        FIELD_extension,
        FIELD_marker,
        FIELD_payloadType,
        FIELD_sequenceNumber,
        FIELD_timeStamp,
        FIELD_ssrc,
        FIELD_csrc,
    };
  public:
    RtpHeaderDescriptor();
    virtual ~RtpHeaderDescriptor();

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

Register_ClassDescriptor(RtpHeaderDescriptor)

RtpHeaderDescriptor::RtpHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

RtpHeaderDescriptor::~RtpHeaderDescriptor()
{
    delete[] propertynames;
}

bool RtpHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpHeader *>(obj)!=nullptr;
}

const char **RtpHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int RtpHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_version
        FD_ISEDITABLE,    // FIELD_padding
        FD_ISEDITABLE,    // FIELD_extension
        FD_ISEDITABLE,    // FIELD_marker
        FD_ISEDITABLE,    // FIELD_payloadType
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISEDITABLE,    // FIELD_timeStamp
        FD_ISEDITABLE,    // FIELD_ssrc
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_csrc
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *RtpHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "padding",
        "extension",
        "marker",
        "payloadType",
        "sequenceNumber",
        "timeStamp",
        "ssrc",
        "csrc",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int RtpHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "version") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "padding") == 0) return base+1;
    if (fieldName[0] == 'e' && strcmp(fieldName, "extension") == 0) return base+2;
    if (fieldName[0] == 'm' && strcmp(fieldName, "marker") == 0) return base+3;
    if (fieldName[0] == 'p' && strcmp(fieldName, "payloadType") == 0) return base+4;
    if (fieldName[0] == 's' && strcmp(fieldName, "sequenceNumber") == 0) return base+5;
    if (fieldName[0] == 't' && strcmp(fieldName, "timeStamp") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "ssrc") == 0) return base+7;
    if (fieldName[0] == 'c' && strcmp(fieldName, "csrc") == 0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8",    // FIELD_version
        "bool",    // FIELD_padding
        "bool",    // FIELD_extension
        "bool",    // FIELD_marker
        "int8",    // FIELD_payloadType
        "uint16",    // FIELD_sequenceNumber
        "uint32",    // FIELD_timeStamp
        "uint32",    // FIELD_ssrc
        "uint32",    // FIELD_csrc
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **RtpHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtpHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpHeader *pp = (RtpHeader *)object; (void)pp;
    switch (field) {
        case FIELD_csrc: return pp->getCsrcArraySize();
        default: return 0;
    }
}

const char *RtpHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpHeader *pp = (RtpHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpHeader *pp = (RtpHeader *)object; (void)pp;
    switch (field) {
        case FIELD_version: return ulong2string(pp->getVersion());
        case FIELD_padding: return bool2string(pp->getPadding());
        case FIELD_extension: return bool2string(pp->getExtension());
        case FIELD_marker: return bool2string(pp->getMarker());
        case FIELD_payloadType: return long2string(pp->getPayloadType());
        case FIELD_sequenceNumber: return ulong2string(pp->getSequenceNumber());
        case FIELD_timeStamp: return ulong2string(pp->getTimeStamp());
        case FIELD_ssrc: return ulong2string(pp->getSsrc());
        case FIELD_csrc: return ulong2string(pp->getCsrc(i));
        default: return "";
    }
}

bool RtpHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpHeader *pp = (RtpHeader *)object; (void)pp;
    switch (field) {
        case FIELD_version: pp->setVersion(string2ulong(value)); return true;
        case FIELD_padding: pp->setPadding(string2bool(value)); return true;
        case FIELD_extension: pp->setExtension(string2bool(value)); return true;
        case FIELD_marker: pp->setMarker(string2bool(value)); return true;
        case FIELD_payloadType: pp->setPayloadType(string2long(value)); return true;
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2ulong(value)); return true;
        case FIELD_timeStamp: pp->setTimeStamp(string2ulong(value)); return true;
        case FIELD_ssrc: pp->setSsrc(string2ulong(value)); return true;
        case FIELD_csrc: pp->setCsrc(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *RtpHeaderDescriptor::getFieldStructName(int field) const
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

void *RtpHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpHeader *pp = (RtpHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace rtp
} // namespace inet

