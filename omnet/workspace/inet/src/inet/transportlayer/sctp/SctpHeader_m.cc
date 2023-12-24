//
// Generated file, do not edit! Created by nedtool 5.6 from inet/transportlayer/sctp/SctpHeader.msg.
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
#include "SctpHeader_m.h"

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
namespace sctp {

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

SctpHeader_Base::SctpHeader_Base() : ::inet::TransportHeaderBase()
{
}

SctpHeader_Base::SctpHeader_Base(const SctpHeader_Base& other) : ::inet::TransportHeaderBase(other)
{
    copy(other);
}

SctpHeader_Base::~SctpHeader_Base()
{
}

SctpHeader_Base& SctpHeader_Base::operator=(const SctpHeader_Base& other)
{
    if (this == &other) return *this;
    ::inet::TransportHeaderBase::operator=(other);
    copy(other);
    return *this;
}

void SctpHeader_Base::copy(const SctpHeader_Base& other)
{
    this->srcPort = other.srcPort;
    this->destPort = other.destPort;
    this->vTag = other.vTag;
    this->checksumOk = other.checksumOk;
    this->crc = other.crc;
    this->crcMode = other.crcMode;
    this->headerLength = other.headerLength;
}

void SctpHeader_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TransportHeaderBase::parsimPack(b);
    doParsimPacking(b,this->srcPort);
    doParsimPacking(b,this->destPort);
    doParsimPacking(b,this->vTag);
    doParsimPacking(b,this->checksumOk);
    doParsimPacking(b,this->crc);
    doParsimPacking(b,this->crcMode);
    doParsimPacking(b,this->headerLength);
    // field sctpChunks is abstract -- please do packing in customized class
}

void SctpHeader_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TransportHeaderBase::parsimUnpack(b);
    doParsimUnpacking(b,this->srcPort);
    doParsimUnpacking(b,this->destPort);
    doParsimUnpacking(b,this->vTag);
    doParsimUnpacking(b,this->checksumOk);
    doParsimUnpacking(b,this->crc);
    doParsimUnpacking(b,this->crcMode);
    doParsimUnpacking(b,this->headerLength);
    // field sctpChunks is abstract -- please do unpacking in customized class
}

uint16_t SctpHeader_Base::getSrcPort() const
{
    return this->srcPort;
}

void SctpHeader_Base::setSrcPort(uint16_t srcPort)
{
    handleChange();
    this->srcPort = srcPort;
}

uint16_t SctpHeader_Base::getDestPort() const
{
    return this->destPort;
}

void SctpHeader_Base::setDestPort(uint16_t destPort)
{
    handleChange();
    this->destPort = destPort;
}

uint32_t SctpHeader_Base::getVTag() const
{
    return this->vTag;
}

void SctpHeader_Base::setVTag(uint32_t vTag)
{
    handleChange();
    this->vTag = vTag;
}

bool SctpHeader_Base::getChecksumOk() const
{
    return this->checksumOk;
}

void SctpHeader_Base::setChecksumOk(bool checksumOk)
{
    handleChange();
    this->checksumOk = checksumOk;
}

uint16_t SctpHeader_Base::getCrc() const
{
    return this->crc;
}

void SctpHeader_Base::setCrc(uint16_t crc)
{
    handleChange();
    this->crc = crc;
}

inet::CrcMode SctpHeader_Base::getCrcMode() const
{
    return this->crcMode;
}

void SctpHeader_Base::setCrcMode(inet::CrcMode crcMode)
{
    handleChange();
    this->crcMode = crcMode;
}

unsigned short SctpHeader_Base::getHeaderLength() const
{
    return this->headerLength;
}

void SctpHeader_Base::setHeaderLength(unsigned short headerLength)
{
    handleChange();
    this->headerLength = headerLength;
}

class SctpHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_srcPort,
        FIELD_destPort,
        FIELD_vTag,
        FIELD_checksumOk,
        FIELD_crc,
        FIELD_crcMode,
        FIELD_headerLength,
        FIELD_sctpChunks,
    };
  public:
    SctpHeaderDescriptor();
    virtual ~SctpHeaderDescriptor();

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

Register_ClassDescriptor(SctpHeaderDescriptor)

SctpHeaderDescriptor::SctpHeaderDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SctpHeader", "inet::TransportHeaderBase")
{
    propertynames = nullptr;
}

SctpHeaderDescriptor::~SctpHeaderDescriptor()
{
    delete[] propertynames;
}

bool SctpHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpHeader_Base *>(obj)!=nullptr;
}

const char **SctpHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpHeaderDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "customize")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int SctpHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srcPort
        FD_ISEDITABLE,    // FIELD_destPort
        FD_ISEDITABLE,    // FIELD_vTag
        FD_ISEDITABLE,    // FIELD_checksumOk
        FD_ISEDITABLE,    // FIELD_crc
        0,    // FIELD_crcMode
        FD_ISEDITABLE,    // FIELD_headerLength
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_sctpChunks
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *SctpHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcPort",
        "destPort",
        "vTag",
        "checksumOk",
        "crc",
        "crcMode",
        "headerLength",
        "sctpChunks",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int SctpHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "srcPort") == 0) return base+0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destPort") == 0) return base+1;
    if (fieldName[0] == 'v' && strcmp(fieldName, "vTag") == 0) return base+2;
    if (fieldName[0] == 'c' && strcmp(fieldName, "checksumOk") == 0) return base+3;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crc") == 0) return base+4;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crcMode") == 0) return base+5;
    if (fieldName[0] == 'h' && strcmp(fieldName, "headerLength") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "sctpChunks") == 0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",    // FIELD_srcPort
        "uint16",    // FIELD_destPort
        "uint32",    // FIELD_vTag
        "bool",    // FIELD_checksumOk
        "uint16_t",    // FIELD_crc
        "inet::CrcMode",    // FIELD_crcMode
        "unsigned short",    // FIELD_headerLength
        "inet::sctp::SctpChunk",    // FIELD_sctpChunks
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpHeaderDescriptor::getFieldPropertyNames(int field) const
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
        default: return nullptr;
    }
}

const char *SctpHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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
        default: return nullptr;
    }
}

int SctpHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpHeader_Base *pp = (SctpHeader_Base *)object; (void)pp;
    switch (field) {
        case FIELD_sctpChunks: return pp->getSctpChunksArraySize();
        default: return 0;
    }
}

const char *SctpHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpHeader_Base *pp = (SctpHeader_Base *)object; (void)pp;
    switch (field) {
        case FIELD_sctpChunks: { const SctpChunk * value = pp->getSctpChunks(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string SctpHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpHeader_Base *pp = (SctpHeader_Base *)object; (void)pp;
    switch (field) {
        case FIELD_srcPort: return ulong2string(pp->getSrcPort());
        case FIELD_destPort: return ulong2string(pp->getDestPort());
        case FIELD_vTag: return ulong2string(pp->getVTag());
        case FIELD_checksumOk: return bool2string(pp->getChecksumOk());
        case FIELD_crc: return ulong2string(pp->getCrc());
        case FIELD_crcMode: return enum2string(pp->getCrcMode(), "inet::CrcMode");
        case FIELD_headerLength: return ulong2string(pp->getHeaderLength());
        case FIELD_sctpChunks: {std::stringstream out; out << pp->getSctpChunks(i); return out.str();}
        default: return "";
    }
}

bool SctpHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpHeader_Base *pp = (SctpHeader_Base *)object; (void)pp;
    switch (field) {
        case FIELD_srcPort: pp->setSrcPort(string2ulong(value)); return true;
        case FIELD_destPort: pp->setDestPort(string2ulong(value)); return true;
        case FIELD_vTag: pp->setVTag(string2ulong(value)); return true;
        case FIELD_checksumOk: pp->setChecksumOk(string2bool(value)); return true;
        case FIELD_crc: pp->setCrc(string2ulong(value)); return true;
        case FIELD_headerLength: pp->setHeaderLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_sctpChunks: return omnetpp::opp_typename(typeid(SctpChunk));
        default: return nullptr;
    };
}

void *SctpHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpHeader_Base *pp = (SctpHeader_Base *)object; (void)pp;
    switch (field) {
        case FIELD_sctpChunks: return toVoidPtr(pp->getSctpChunks(i)); break;
        default: return nullptr;
    }
}

Register_Class(SctpChunk)

SctpChunk::SctpChunk(const char *name) : ::omnetpp::cPacket(name)
{
}

SctpChunk::SctpChunk(const SctpChunk& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SctpChunk::~SctpChunk()
{
    delete [] this->chunkName;
}

SctpChunk& SctpChunk::operator=(const SctpChunk& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SctpChunk::copy(const SctpChunk& other)
{
    this->sctpChunkType = other.sctpChunkType;
    this->flags = other.flags;
    this->length = other.length;
    delete [] this->chunkName;
    this->chunkName = (other.chunkName_arraysize==0) ? nullptr : new char[other.chunkName_arraysize];
    chunkName_arraysize = other.chunkName_arraysize;
    for (size_t i = 0; i < chunkName_arraysize; i++) {
        this->chunkName[i] = other.chunkName[i];
    }
}

void SctpChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sctpChunkType);
    doParsimPacking(b,this->flags);
    doParsimPacking(b,this->length);
    b->pack(chunkName_arraysize);
    doParsimArrayPacking(b,this->chunkName,chunkName_arraysize);
}

void SctpChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sctpChunkType);
    doParsimUnpacking(b,this->flags);
    doParsimUnpacking(b,this->length);
    delete [] this->chunkName;
    b->unpack(chunkName_arraysize);
    if (chunkName_arraysize == 0) {
        this->chunkName = nullptr;
    } else {
        this->chunkName = new char[chunkName_arraysize];
        doParsimArrayUnpacking(b,this->chunkName,chunkName_arraysize);
    }
}

uint8_t SctpChunk::getSctpChunkType() const
{
    return this->sctpChunkType;
}

void SctpChunk::setSctpChunkType(uint8_t sctpChunkType)
{
    this->sctpChunkType = sctpChunkType;
}

uint32_t SctpChunk::getFlags() const
{
    return this->flags;
}

void SctpChunk::setFlags(uint32_t flags)
{
    this->flags = flags;
}

unsigned short SctpChunk::getLength() const
{
    return this->length;
}

void SctpChunk::setLength(unsigned short length)
{
    this->length = length;
}

size_t SctpChunk::getChunkNameArraySize() const
{
    return chunkName_arraysize;
}

char SctpChunk::getChunkName(size_t k) const
{
    if (k >= chunkName_arraysize) throw omnetpp::cRuntimeError("Array of size chunkName_arraysize indexed by %lu", (unsigned long)k);
    return this->chunkName[k];
}

void SctpChunk::setChunkNameArraySize(size_t newSize)
{
    char *chunkName2 = (newSize==0) ? nullptr : new char[newSize];
    size_t minSize = chunkName_arraysize < newSize ? chunkName_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        chunkName2[i] = this->chunkName[i];
    for (size_t i = minSize; i < newSize; i++)
        chunkName2[i] = 0;
    delete [] this->chunkName;
    this->chunkName = chunkName2;
    chunkName_arraysize = newSize;
}

void SctpChunk::setChunkName(size_t k, char chunkName)
{
    if (k >= chunkName_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->chunkName[k] = chunkName;
}

void SctpChunk::insertChunkName(size_t k, char chunkName)
{
    if (k > chunkName_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = chunkName_arraysize + 1;
    char *chunkName2 = new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        chunkName2[i] = this->chunkName[i];
    chunkName2[k] = chunkName;
    for (i = k + 1; i < newSize; i++)
        chunkName2[i] = this->chunkName[i-1];
    delete [] this->chunkName;
    this->chunkName = chunkName2;
    chunkName_arraysize = newSize;
}

void SctpChunk::insertChunkName(char chunkName)
{
    insertChunkName(chunkName_arraysize, chunkName);
}

void SctpChunk::eraseChunkName(size_t k)
{
    if (k >= chunkName_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = chunkName_arraysize - 1;
    char *chunkName2 = (newSize == 0) ? nullptr : new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        chunkName2[i] = this->chunkName[i];
    for (i = k; i < newSize; i++)
        chunkName2[i] = this->chunkName[i+1];
    delete [] this->chunkName;
    this->chunkName = chunkName2;
    chunkName_arraysize = newSize;
}

class SctpChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_sctpChunkType,
        FIELD_flags,
        FIELD_length,
        FIELD_chunkName,
    };
  public:
    SctpChunkDescriptor();
    virtual ~SctpChunkDescriptor();

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

Register_ClassDescriptor(SctpChunkDescriptor)

SctpChunkDescriptor::SctpChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpChunk)), "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SctpChunkDescriptor::~SctpChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpChunk *>(obj)!=nullptr;
}

const char **SctpChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SctpChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sctpChunkType
        FD_ISEDITABLE,    // FIELD_flags
        FD_ISEDITABLE,    // FIELD_length
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_chunkName
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SctpChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sctpChunkType",
        "flags",
        "length",
        "chunkName",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SctpChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sctpChunkType") == 0) return base+0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "flags") == 0) return base+1;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+2;
    if (fieldName[0] == 'c' && strcmp(fieldName, "chunkName") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8",    // FIELD_sctpChunkType
        "uint32",    // FIELD_flags
        "unsigned short",    // FIELD_length
        "char",    // FIELD_chunkName
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpChunk *pp = (SctpChunk *)object; (void)pp;
    switch (field) {
        case FIELD_chunkName: return pp->getChunkNameArraySize();
        default: return 0;
    }
}

const char *SctpChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpChunk *pp = (SctpChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpChunk *pp = (SctpChunk *)object; (void)pp;
    switch (field) {
        case FIELD_sctpChunkType: return ulong2string(pp->getSctpChunkType());
        case FIELD_flags: return ulong2string(pp->getFlags());
        case FIELD_length: return ulong2string(pp->getLength());
        case FIELD_chunkName: return long2string(pp->getChunkName(i));
        default: return "";
    }
}

bool SctpChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpChunk *pp = (SctpChunk *)object; (void)pp;
    switch (field) {
        case FIELD_sctpChunkType: pp->setSctpChunkType(string2ulong(value)); return true;
        case FIELD_flags: pp->setFlags(string2ulong(value)); return true;
        case FIELD_length: pp->setLength(string2ulong(value)); return true;
        case FIELD_chunkName: pp->setChunkName(i,string2long(value)); return true;
        default: return false;
    }
}

const char *SctpChunkDescriptor::getFieldStructName(int field) const
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

void *SctpChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpChunk *pp = (SctpChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpInitChunk)

SctpInitChunk::SctpInitChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpInitChunk::SctpInitChunk(const SctpInitChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpInitChunk::~SctpInitChunk()
{
    delete [] this->addresses;
    delete [] this->unrecognizedParameters;
    delete [] this->sctpChunkTypes;
    delete [] this->sepChunks;
    delete [] this->hmacTypes;
    delete [] this->random;
}

SctpInitChunk& SctpInitChunk::operator=(const SctpInitChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpInitChunk::copy(const SctpInitChunk& other)
{
    this->initTag = other.initTag;
    this->a_rwnd = other.a_rwnd;
    this->noOutStreams = other.noOutStreams;
    this->noInStreams = other.noInStreams;
    this->initTsn = other.initTsn;
    this->forwardTsn = other.forwardTsn;
    this->ipv4Supported = other.ipv4Supported;
    this->ipv6Supported = other.ipv6Supported;
    delete [] this->addresses;
    this->addresses = (other.addresses_arraysize==0) ? nullptr : new L3Address[other.addresses_arraysize];
    addresses_arraysize = other.addresses_arraysize;
    for (size_t i = 0; i < addresses_arraysize; i++) {
        this->addresses[i] = other.addresses[i];
    }
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = (other.unrecognizedParameters_arraysize==0) ? nullptr : new uint8_t[other.unrecognizedParameters_arraysize];
    unrecognizedParameters_arraysize = other.unrecognizedParameters_arraysize;
    for (size_t i = 0; i < unrecognizedParameters_arraysize; i++) {
        this->unrecognizedParameters[i] = other.unrecognizedParameters[i];
    }
    this->msg_rwnd = other.msg_rwnd;
    delete [] this->sctpChunkTypes;
    this->sctpChunkTypes = (other.sctpChunkTypes_arraysize==0) ? nullptr : new uint16_t[other.sctpChunkTypes_arraysize];
    sctpChunkTypes_arraysize = other.sctpChunkTypes_arraysize;
    for (size_t i = 0; i < sctpChunkTypes_arraysize; i++) {
        this->sctpChunkTypes[i] = other.sctpChunkTypes[i];
    }
    delete [] this->sepChunks;
    this->sepChunks = (other.sepChunks_arraysize==0) ? nullptr : new uint16_t[other.sepChunks_arraysize];
    sepChunks_arraysize = other.sepChunks_arraysize;
    for (size_t i = 0; i < sepChunks_arraysize; i++) {
        this->sepChunks[i] = other.sepChunks[i];
    }
    delete [] this->hmacTypes;
    this->hmacTypes = (other.hmacTypes_arraysize==0) ? nullptr : new uint16_t[other.hmacTypes_arraysize];
    hmacTypes_arraysize = other.hmacTypes_arraysize;
    for (size_t i = 0; i < hmacTypes_arraysize; i++) {
        this->hmacTypes[i] = other.hmacTypes[i];
    }
    delete [] this->random;
    this->random = (other.random_arraysize==0) ? nullptr : new uint8_t[other.random_arraysize];
    random_arraysize = other.random_arraysize;
    for (size_t i = 0; i < random_arraysize; i++) {
        this->random[i] = other.random[i];
    }
}

void SctpInitChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->initTag);
    doParsimPacking(b,this->a_rwnd);
    doParsimPacking(b,this->noOutStreams);
    doParsimPacking(b,this->noInStreams);
    doParsimPacking(b,this->initTsn);
    doParsimPacking(b,this->forwardTsn);
    doParsimPacking(b,this->ipv4Supported);
    doParsimPacking(b,this->ipv6Supported);
    b->pack(addresses_arraysize);
    doParsimArrayPacking(b,this->addresses,addresses_arraysize);
    b->pack(unrecognizedParameters_arraysize);
    doParsimArrayPacking(b,this->unrecognizedParameters,unrecognizedParameters_arraysize);
    doParsimPacking(b,this->msg_rwnd);
    b->pack(sctpChunkTypes_arraysize);
    doParsimArrayPacking(b,this->sctpChunkTypes,sctpChunkTypes_arraysize);
    b->pack(sepChunks_arraysize);
    doParsimArrayPacking(b,this->sepChunks,sepChunks_arraysize);
    b->pack(hmacTypes_arraysize);
    doParsimArrayPacking(b,this->hmacTypes,hmacTypes_arraysize);
    b->pack(random_arraysize);
    doParsimArrayPacking(b,this->random,random_arraysize);
}

void SctpInitChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->initTag);
    doParsimUnpacking(b,this->a_rwnd);
    doParsimUnpacking(b,this->noOutStreams);
    doParsimUnpacking(b,this->noInStreams);
    doParsimUnpacking(b,this->initTsn);
    doParsimUnpacking(b,this->forwardTsn);
    doParsimUnpacking(b,this->ipv4Supported);
    doParsimUnpacking(b,this->ipv6Supported);
    delete [] this->addresses;
    b->unpack(addresses_arraysize);
    if (addresses_arraysize == 0) {
        this->addresses = nullptr;
    } else {
        this->addresses = new L3Address[addresses_arraysize];
        doParsimArrayUnpacking(b,this->addresses,addresses_arraysize);
    }
    delete [] this->unrecognizedParameters;
    b->unpack(unrecognizedParameters_arraysize);
    if (unrecognizedParameters_arraysize == 0) {
        this->unrecognizedParameters = nullptr;
    } else {
        this->unrecognizedParameters = new uint8_t[unrecognizedParameters_arraysize];
        doParsimArrayUnpacking(b,this->unrecognizedParameters,unrecognizedParameters_arraysize);
    }
    doParsimUnpacking(b,this->msg_rwnd);
    delete [] this->sctpChunkTypes;
    b->unpack(sctpChunkTypes_arraysize);
    if (sctpChunkTypes_arraysize == 0) {
        this->sctpChunkTypes = nullptr;
    } else {
        this->sctpChunkTypes = new uint16_t[sctpChunkTypes_arraysize];
        doParsimArrayUnpacking(b,this->sctpChunkTypes,sctpChunkTypes_arraysize);
    }
    delete [] this->sepChunks;
    b->unpack(sepChunks_arraysize);
    if (sepChunks_arraysize == 0) {
        this->sepChunks = nullptr;
    } else {
        this->sepChunks = new uint16_t[sepChunks_arraysize];
        doParsimArrayUnpacking(b,this->sepChunks,sepChunks_arraysize);
    }
    delete [] this->hmacTypes;
    b->unpack(hmacTypes_arraysize);
    if (hmacTypes_arraysize == 0) {
        this->hmacTypes = nullptr;
    } else {
        this->hmacTypes = new uint16_t[hmacTypes_arraysize];
        doParsimArrayUnpacking(b,this->hmacTypes,hmacTypes_arraysize);
    }
    delete [] this->random;
    b->unpack(random_arraysize);
    if (random_arraysize == 0) {
        this->random = nullptr;
    } else {
        this->random = new uint8_t[random_arraysize];
        doParsimArrayUnpacking(b,this->random,random_arraysize);
    }
}

uint32_t SctpInitChunk::getInitTag() const
{
    return this->initTag;
}

void SctpInitChunk::setInitTag(uint32_t initTag)
{
    this->initTag = initTag;
}

uint32_t SctpInitChunk::getA_rwnd() const
{
    return this->a_rwnd;
}

void SctpInitChunk::setA_rwnd(uint32_t a_rwnd)
{
    this->a_rwnd = a_rwnd;
}

uint16_t SctpInitChunk::getNoOutStreams() const
{
    return this->noOutStreams;
}

void SctpInitChunk::setNoOutStreams(uint16_t noOutStreams)
{
    this->noOutStreams = noOutStreams;
}

uint16_t SctpInitChunk::getNoInStreams() const
{
    return this->noInStreams;
}

void SctpInitChunk::setNoInStreams(uint16_t noInStreams)
{
    this->noInStreams = noInStreams;
}

uint32_t SctpInitChunk::getInitTsn() const
{
    return this->initTsn;
}

void SctpInitChunk::setInitTsn(uint32_t initTsn)
{
    this->initTsn = initTsn;
}

bool SctpInitChunk::getForwardTsn() const
{
    return this->forwardTsn;
}

void SctpInitChunk::setForwardTsn(bool forwardTsn)
{
    this->forwardTsn = forwardTsn;
}

bool SctpInitChunk::getIpv4Supported() const
{
    return this->ipv4Supported;
}

void SctpInitChunk::setIpv4Supported(bool ipv4Supported)
{
    this->ipv4Supported = ipv4Supported;
}

bool SctpInitChunk::getIpv6Supported() const
{
    return this->ipv6Supported;
}

void SctpInitChunk::setIpv6Supported(bool ipv6Supported)
{
    this->ipv6Supported = ipv6Supported;
}

size_t SctpInitChunk::getAddressesArraySize() const
{
    return addresses_arraysize;
}

const L3Address& SctpInitChunk::getAddresses(size_t k) const
{
    if (k >= addresses_arraysize) throw omnetpp::cRuntimeError("Array of size addresses_arraysize indexed by %lu", (unsigned long)k);
    return this->addresses[k];
}

void SctpInitChunk::setAddressesArraySize(size_t newSize)
{
    L3Address *addresses2 = (newSize==0) ? nullptr : new L3Address[newSize];
    size_t minSize = addresses_arraysize < newSize ? addresses_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        addresses2[i] = this->addresses[i];
    delete [] this->addresses;
    this->addresses = addresses2;
    addresses_arraysize = newSize;
}

void SctpInitChunk::setAddresses(size_t k, const L3Address& addresses)
{
    if (k >= addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->addresses[k] = addresses;
}

void SctpInitChunk::insertAddresses(size_t k, const L3Address& addresses)
{
    if (k > addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = addresses_arraysize + 1;
    L3Address *addresses2 = new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        addresses2[i] = this->addresses[i];
    addresses2[k] = addresses;
    for (i = k + 1; i < newSize; i++)
        addresses2[i] = this->addresses[i-1];
    delete [] this->addresses;
    this->addresses = addresses2;
    addresses_arraysize = newSize;
}

void SctpInitChunk::insertAddresses(const L3Address& addresses)
{
    insertAddresses(addresses_arraysize, addresses);
}

void SctpInitChunk::eraseAddresses(size_t k)
{
    if (k >= addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = addresses_arraysize - 1;
    L3Address *addresses2 = (newSize == 0) ? nullptr : new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        addresses2[i] = this->addresses[i];
    for (i = k; i < newSize; i++)
        addresses2[i] = this->addresses[i+1];
    delete [] this->addresses;
    this->addresses = addresses2;
    addresses_arraysize = newSize;
}

size_t SctpInitChunk::getUnrecognizedParametersArraySize() const
{
    return unrecognizedParameters_arraysize;
}

uint8_t SctpInitChunk::getUnrecognizedParameters(size_t k) const
{
    if (k >= unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size unrecognizedParameters_arraysize indexed by %lu", (unsigned long)k);
    return this->unrecognizedParameters[k];
}

void SctpInitChunk::setUnrecognizedParametersArraySize(size_t newSize)
{
    uint8_t *unrecognizedParameters2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = unrecognizedParameters_arraysize < newSize ? unrecognizedParameters_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i];
    for (size_t i = minSize; i < newSize; i++)
        unrecognizedParameters2[i] = 0;
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = unrecognizedParameters2;
    unrecognizedParameters_arraysize = newSize;
}

void SctpInitChunk::setUnrecognizedParameters(size_t k, uint8_t unrecognizedParameters)
{
    if (k >= unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->unrecognizedParameters[k] = unrecognizedParameters;
}

void SctpInitChunk::insertUnrecognizedParameters(size_t k, uint8_t unrecognizedParameters)
{
    if (k > unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = unrecognizedParameters_arraysize + 1;
    uint8_t *unrecognizedParameters2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i];
    unrecognizedParameters2[k] = unrecognizedParameters;
    for (i = k + 1; i < newSize; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i-1];
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = unrecognizedParameters2;
    unrecognizedParameters_arraysize = newSize;
}

void SctpInitChunk::insertUnrecognizedParameters(uint8_t unrecognizedParameters)
{
    insertUnrecognizedParameters(unrecognizedParameters_arraysize, unrecognizedParameters);
}

void SctpInitChunk::eraseUnrecognizedParameters(size_t k)
{
    if (k >= unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = unrecognizedParameters_arraysize - 1;
    uint8_t *unrecognizedParameters2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i];
    for (i = k; i < newSize; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i+1];
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = unrecognizedParameters2;
    unrecognizedParameters_arraysize = newSize;
}

uint32_t SctpInitChunk::getMsg_rwnd() const
{
    return this->msg_rwnd;
}

void SctpInitChunk::setMsg_rwnd(uint32_t msg_rwnd)
{
    this->msg_rwnd = msg_rwnd;
}

size_t SctpInitChunk::getSctpChunkTypesArraySize() const
{
    return sctpChunkTypes_arraysize;
}

uint16_t SctpInitChunk::getSctpChunkTypes(size_t k) const
{
    if (k >= sctpChunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size sctpChunkTypes_arraysize indexed by %lu", (unsigned long)k);
    return this->sctpChunkTypes[k];
}

void SctpInitChunk::setSctpChunkTypesArraySize(size_t newSize)
{
    uint16_t *sctpChunkTypes2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = sctpChunkTypes_arraysize < newSize ? sctpChunkTypes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i];
    for (size_t i = minSize; i < newSize; i++)
        sctpChunkTypes2[i] = 0;
    delete [] this->sctpChunkTypes;
    this->sctpChunkTypes = sctpChunkTypes2;
    sctpChunkTypes_arraysize = newSize;
}

void SctpInitChunk::setSctpChunkTypes(size_t k, uint16_t sctpChunkTypes)
{
    if (k >= sctpChunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->sctpChunkTypes[k] = sctpChunkTypes;
}

void SctpInitChunk::insertSctpChunkTypes(size_t k, uint16_t sctpChunkTypes)
{
    if (k > sctpChunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sctpChunkTypes_arraysize + 1;
    uint16_t *sctpChunkTypes2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i];
    sctpChunkTypes2[k] = sctpChunkTypes;
    for (i = k + 1; i < newSize; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i-1];
    delete [] this->sctpChunkTypes;
    this->sctpChunkTypes = sctpChunkTypes2;
    sctpChunkTypes_arraysize = newSize;
}

void SctpInitChunk::insertSctpChunkTypes(uint16_t sctpChunkTypes)
{
    insertSctpChunkTypes(sctpChunkTypes_arraysize, sctpChunkTypes);
}

void SctpInitChunk::eraseSctpChunkTypes(size_t k)
{
    if (k >= sctpChunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sctpChunkTypes_arraysize - 1;
    uint16_t *sctpChunkTypes2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i];
    for (i = k; i < newSize; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i+1];
    delete [] this->sctpChunkTypes;
    this->sctpChunkTypes = sctpChunkTypes2;
    sctpChunkTypes_arraysize = newSize;
}

size_t SctpInitChunk::getSepChunksArraySize() const
{
    return sepChunks_arraysize;
}

uint16_t SctpInitChunk::getSepChunks(size_t k) const
{
    if (k >= sepChunks_arraysize) throw omnetpp::cRuntimeError("Array of size sepChunks_arraysize indexed by %lu", (unsigned long)k);
    return this->sepChunks[k];
}

void SctpInitChunk::setSepChunksArraySize(size_t newSize)
{
    uint16_t *sepChunks2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = sepChunks_arraysize < newSize ? sepChunks_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sepChunks2[i] = this->sepChunks[i];
    for (size_t i = minSize; i < newSize; i++)
        sepChunks2[i] = 0;
    delete [] this->sepChunks;
    this->sepChunks = sepChunks2;
    sepChunks_arraysize = newSize;
}

void SctpInitChunk::setSepChunks(size_t k, uint16_t sepChunks)
{
    if (k >= sepChunks_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->sepChunks[k] = sepChunks;
}

void SctpInitChunk::insertSepChunks(size_t k, uint16_t sepChunks)
{
    if (k > sepChunks_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sepChunks_arraysize + 1;
    uint16_t *sepChunks2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sepChunks2[i] = this->sepChunks[i];
    sepChunks2[k] = sepChunks;
    for (i = k + 1; i < newSize; i++)
        sepChunks2[i] = this->sepChunks[i-1];
    delete [] this->sepChunks;
    this->sepChunks = sepChunks2;
    sepChunks_arraysize = newSize;
}

void SctpInitChunk::insertSepChunks(uint16_t sepChunks)
{
    insertSepChunks(sepChunks_arraysize, sepChunks);
}

void SctpInitChunk::eraseSepChunks(size_t k)
{
    if (k >= sepChunks_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sepChunks_arraysize - 1;
    uint16_t *sepChunks2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sepChunks2[i] = this->sepChunks[i];
    for (i = k; i < newSize; i++)
        sepChunks2[i] = this->sepChunks[i+1];
    delete [] this->sepChunks;
    this->sepChunks = sepChunks2;
    sepChunks_arraysize = newSize;
}

size_t SctpInitChunk::getHmacTypesArraySize() const
{
    return hmacTypes_arraysize;
}

uint16_t SctpInitChunk::getHmacTypes(size_t k) const
{
    if (k >= hmacTypes_arraysize) throw omnetpp::cRuntimeError("Array of size hmacTypes_arraysize indexed by %lu", (unsigned long)k);
    return this->hmacTypes[k];
}

void SctpInitChunk::setHmacTypesArraySize(size_t newSize)
{
    uint16_t *hmacTypes2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = hmacTypes_arraysize < newSize ? hmacTypes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        hmacTypes2[i] = this->hmacTypes[i];
    for (size_t i = minSize; i < newSize; i++)
        hmacTypes2[i] = 0;
    delete [] this->hmacTypes;
    this->hmacTypes = hmacTypes2;
    hmacTypes_arraysize = newSize;
}

void SctpInitChunk::setHmacTypes(size_t k, uint16_t hmacTypes)
{
    if (k >= hmacTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->hmacTypes[k] = hmacTypes;
}

void SctpInitChunk::insertHmacTypes(size_t k, uint16_t hmacTypes)
{
    if (k > hmacTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = hmacTypes_arraysize + 1;
    uint16_t *hmacTypes2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        hmacTypes2[i] = this->hmacTypes[i];
    hmacTypes2[k] = hmacTypes;
    for (i = k + 1; i < newSize; i++)
        hmacTypes2[i] = this->hmacTypes[i-1];
    delete [] this->hmacTypes;
    this->hmacTypes = hmacTypes2;
    hmacTypes_arraysize = newSize;
}

void SctpInitChunk::insertHmacTypes(uint16_t hmacTypes)
{
    insertHmacTypes(hmacTypes_arraysize, hmacTypes);
}

void SctpInitChunk::eraseHmacTypes(size_t k)
{
    if (k >= hmacTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = hmacTypes_arraysize - 1;
    uint16_t *hmacTypes2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        hmacTypes2[i] = this->hmacTypes[i];
    for (i = k; i < newSize; i++)
        hmacTypes2[i] = this->hmacTypes[i+1];
    delete [] this->hmacTypes;
    this->hmacTypes = hmacTypes2;
    hmacTypes_arraysize = newSize;
}

size_t SctpInitChunk::getRandomArraySize() const
{
    return random_arraysize;
}

uint8_t SctpInitChunk::getRandom(size_t k) const
{
    if (k >= random_arraysize) throw omnetpp::cRuntimeError("Array of size random_arraysize indexed by %lu", (unsigned long)k);
    return this->random[k];
}

void SctpInitChunk::setRandomArraySize(size_t newSize)
{
    uint8_t *random2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = random_arraysize < newSize ? random_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        random2[i] = this->random[i];
    for (size_t i = minSize; i < newSize; i++)
        random2[i] = 0;
    delete [] this->random;
    this->random = random2;
    random_arraysize = newSize;
}

void SctpInitChunk::setRandom(size_t k, uint8_t random)
{
    if (k >= random_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->random[k] = random;
}

void SctpInitChunk::insertRandom(size_t k, uint8_t random)
{
    if (k > random_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = random_arraysize + 1;
    uint8_t *random2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        random2[i] = this->random[i];
    random2[k] = random;
    for (i = k + 1; i < newSize; i++)
        random2[i] = this->random[i-1];
    delete [] this->random;
    this->random = random2;
    random_arraysize = newSize;
}

void SctpInitChunk::insertRandom(uint8_t random)
{
    insertRandom(random_arraysize, random);
}

void SctpInitChunk::eraseRandom(size_t k)
{
    if (k >= random_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = random_arraysize - 1;
    uint8_t *random2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        random2[i] = this->random[i];
    for (i = k; i < newSize; i++)
        random2[i] = this->random[i+1];
    delete [] this->random;
    this->random = random2;
    random_arraysize = newSize;
}

class SctpInitChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_initTag,
        FIELD_a_rwnd,
        FIELD_noOutStreams,
        FIELD_noInStreams,
        FIELD_initTsn,
        FIELD_forwardTsn,
        FIELD_ipv4Supported,
        FIELD_ipv6Supported,
        FIELD_addresses,
        FIELD_unrecognizedParameters,
        FIELD_msg_rwnd,
        FIELD_sctpChunkTypes,
        FIELD_sepChunks,
        FIELD_hmacTypes,
        FIELD_random,
    };
  public:
    SctpInitChunkDescriptor();
    virtual ~SctpInitChunkDescriptor();

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

Register_ClassDescriptor(SctpInitChunkDescriptor)

SctpInitChunkDescriptor::SctpInitChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpInitChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpInitChunkDescriptor::~SctpInitChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpInitChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpInitChunk *>(obj)!=nullptr;
}

const char **SctpInitChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpInitChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpInitChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount() : 15;
}

unsigned int SctpInitChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_initTag
        FD_ISEDITABLE,    // FIELD_a_rwnd
        FD_ISEDITABLE,    // FIELD_noOutStreams
        FD_ISEDITABLE,    // FIELD_noInStreams
        FD_ISEDITABLE,    // FIELD_initTsn
        FD_ISEDITABLE,    // FIELD_forwardTsn
        FD_ISEDITABLE,    // FIELD_ipv4Supported
        FD_ISEDITABLE,    // FIELD_ipv6Supported
        FD_ISARRAY,    // FIELD_addresses
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_unrecognizedParameters
        FD_ISEDITABLE,    // FIELD_msg_rwnd
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_sctpChunkTypes
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_sepChunks
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_hmacTypes
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_random
    };
    return (field >= 0 && field < 15) ? fieldTypeFlags[field] : 0;
}

const char *SctpInitChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "initTag",
        "a_rwnd",
        "noOutStreams",
        "noInStreams",
        "initTsn",
        "forwardTsn",
        "ipv4Supported",
        "ipv6Supported",
        "addresses",
        "unrecognizedParameters",
        "msg_rwnd",
        "sctpChunkTypes",
        "sepChunks",
        "hmacTypes",
        "random",
    };
    return (field >= 0 && field < 15) ? fieldNames[field] : nullptr;
}

int SctpInitChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "initTag") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "a_rwnd") == 0) return base+1;
    if (fieldName[0] == 'n' && strcmp(fieldName, "noOutStreams") == 0) return base+2;
    if (fieldName[0] == 'n' && strcmp(fieldName, "noInStreams") == 0) return base+3;
    if (fieldName[0] == 'i' && strcmp(fieldName, "initTsn") == 0) return base+4;
    if (fieldName[0] == 'f' && strcmp(fieldName, "forwardTsn") == 0) return base+5;
    if (fieldName[0] == 'i' && strcmp(fieldName, "ipv4Supported") == 0) return base+6;
    if (fieldName[0] == 'i' && strcmp(fieldName, "ipv6Supported") == 0) return base+7;
    if (fieldName[0] == 'a' && strcmp(fieldName, "addresses") == 0) return base+8;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unrecognizedParameters") == 0) return base+9;
    if (fieldName[0] == 'm' && strcmp(fieldName, "msg_rwnd") == 0) return base+10;
    if (fieldName[0] == 's' && strcmp(fieldName, "sctpChunkTypes") == 0) return base+11;
    if (fieldName[0] == 's' && strcmp(fieldName, "sepChunks") == 0) return base+12;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hmacTypes") == 0) return base+13;
    if (fieldName[0] == 'r' && strcmp(fieldName, "random") == 0) return base+14;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpInitChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_initTag
        "uint32",    // FIELD_a_rwnd
        "uint16",    // FIELD_noOutStreams
        "uint16",    // FIELD_noInStreams
        "uint32",    // FIELD_initTsn
        "bool",    // FIELD_forwardTsn
        "bool",    // FIELD_ipv4Supported
        "bool",    // FIELD_ipv6Supported
        "inet::L3Address",    // FIELD_addresses
        "uint8",    // FIELD_unrecognizedParameters
        "uint32",    // FIELD_msg_rwnd
        "uint16",    // FIELD_sctpChunkTypes
        "uint16",    // FIELD_sepChunks
        "uint16",    // FIELD_hmacTypes
        "uint8",    // FIELD_random
    };
    return (field >= 0 && field < 15) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpInitChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpInitChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpInitChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpInitChunk *pp = (SctpInitChunk *)object; (void)pp;
    switch (field) {
        case FIELD_addresses: return pp->getAddressesArraySize();
        case FIELD_unrecognizedParameters: return pp->getUnrecognizedParametersArraySize();
        case FIELD_sctpChunkTypes: return pp->getSctpChunkTypesArraySize();
        case FIELD_sepChunks: return pp->getSepChunksArraySize();
        case FIELD_hmacTypes: return pp->getHmacTypesArraySize();
        case FIELD_random: return pp->getRandomArraySize();
        default: return 0;
    }
}

const char *SctpInitChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpInitChunk *pp = (SctpInitChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpInitChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpInitChunk *pp = (SctpInitChunk *)object; (void)pp;
    switch (field) {
        case FIELD_initTag: return ulong2string(pp->getInitTag());
        case FIELD_a_rwnd: return ulong2string(pp->getA_rwnd());
        case FIELD_noOutStreams: return ulong2string(pp->getNoOutStreams());
        case FIELD_noInStreams: return ulong2string(pp->getNoInStreams());
        case FIELD_initTsn: return ulong2string(pp->getInitTsn());
        case FIELD_forwardTsn: return bool2string(pp->getForwardTsn());
        case FIELD_ipv4Supported: return bool2string(pp->getIpv4Supported());
        case FIELD_ipv6Supported: return bool2string(pp->getIpv6Supported());
        case FIELD_addresses: return pp->getAddresses(i).str();
        case FIELD_unrecognizedParameters: return ulong2string(pp->getUnrecognizedParameters(i));
        case FIELD_msg_rwnd: return ulong2string(pp->getMsg_rwnd());
        case FIELD_sctpChunkTypes: return ulong2string(pp->getSctpChunkTypes(i));
        case FIELD_sepChunks: return ulong2string(pp->getSepChunks(i));
        case FIELD_hmacTypes: return ulong2string(pp->getHmacTypes(i));
        case FIELD_random: return ulong2string(pp->getRandom(i));
        default: return "";
    }
}

bool SctpInitChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpInitChunk *pp = (SctpInitChunk *)object; (void)pp;
    switch (field) {
        case FIELD_initTag: pp->setInitTag(string2ulong(value)); return true;
        case FIELD_a_rwnd: pp->setA_rwnd(string2ulong(value)); return true;
        case FIELD_noOutStreams: pp->setNoOutStreams(string2ulong(value)); return true;
        case FIELD_noInStreams: pp->setNoInStreams(string2ulong(value)); return true;
        case FIELD_initTsn: pp->setInitTsn(string2ulong(value)); return true;
        case FIELD_forwardTsn: pp->setForwardTsn(string2bool(value)); return true;
        case FIELD_ipv4Supported: pp->setIpv4Supported(string2bool(value)); return true;
        case FIELD_ipv6Supported: pp->setIpv6Supported(string2bool(value)); return true;
        case FIELD_unrecognizedParameters: pp->setUnrecognizedParameters(i,string2ulong(value)); return true;
        case FIELD_msg_rwnd: pp->setMsg_rwnd(string2ulong(value)); return true;
        case FIELD_sctpChunkTypes: pp->setSctpChunkTypes(i,string2ulong(value)); return true;
        case FIELD_sepChunks: pp->setSepChunks(i,string2ulong(value)); return true;
        case FIELD_hmacTypes: pp->setHmacTypes(i,string2ulong(value)); return true;
        case FIELD_random: pp->setRandom(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpInitChunkDescriptor::getFieldStructName(int field) const
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

void *SctpInitChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpInitChunk *pp = (SctpInitChunk *)object; (void)pp;
    switch (field) {
        case FIELD_addresses: return toVoidPtr(&pp->getAddresses(i)); break;
        default: return nullptr;
    }
}

Register_Class(SctpInitAckChunk)

SctpInitAckChunk::SctpInitAckChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpInitAckChunk::SctpInitAckChunk(const SctpInitAckChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpInitAckChunk::~SctpInitAckChunk()
{
    delete [] this->addresses;
    delete [] this->cookie;
    delete [] this->unrecognizedParameters;
    delete [] this->random;
    delete [] this->sctpChunkTypes;
    delete [] this->sepChunks;
    delete [] this->hmacTypes;
}

SctpInitAckChunk& SctpInitAckChunk::operator=(const SctpInitAckChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpInitAckChunk::copy(const SctpInitAckChunk& other)
{
    this->initTag = other.initTag;
    this->a_rwnd = other.a_rwnd;
    this->noOutStreams = other.noOutStreams;
    this->noInStreams = other.noInStreams;
    this->initTsn = other.initTsn;
    this->forwardTsn = other.forwardTsn;
    this->ipv4Supported = other.ipv4Supported;
    this->ipv6Supported = other.ipv6Supported;
    delete [] this->addresses;
    this->addresses = (other.addresses_arraysize==0) ? nullptr : new L3Address[other.addresses_arraysize];
    addresses_arraysize = other.addresses_arraysize;
    for (size_t i = 0; i < addresses_arraysize; i++) {
        this->addresses[i] = other.addresses[i];
    }
    delete [] this->cookie;
    this->cookie = (other.cookie_arraysize==0) ? nullptr : new char[other.cookie_arraysize];
    cookie_arraysize = other.cookie_arraysize;
    for (size_t i = 0; i < cookie_arraysize; i++) {
        this->cookie[i] = other.cookie[i];
    }
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = (other.unrecognizedParameters_arraysize==0) ? nullptr : new uint8_t[other.unrecognizedParameters_arraysize];
    unrecognizedParameters_arraysize = other.unrecognizedParameters_arraysize;
    for (size_t i = 0; i < unrecognizedParameters_arraysize; i++) {
        this->unrecognizedParameters[i] = other.unrecognizedParameters[i];
    }
    this->stateCookie = other.stateCookie;
    this->msg_rwnd = other.msg_rwnd;
    delete [] this->random;
    this->random = (other.random_arraysize==0) ? nullptr : new uint8_t[other.random_arraysize];
    random_arraysize = other.random_arraysize;
    for (size_t i = 0; i < random_arraysize; i++) {
        this->random[i] = other.random[i];
    }
    delete [] this->sctpChunkTypes;
    this->sctpChunkTypes = (other.sctpChunkTypes_arraysize==0) ? nullptr : new uint16_t[other.sctpChunkTypes_arraysize];
    sctpChunkTypes_arraysize = other.sctpChunkTypes_arraysize;
    for (size_t i = 0; i < sctpChunkTypes_arraysize; i++) {
        this->sctpChunkTypes[i] = other.sctpChunkTypes[i];
    }
    delete [] this->sepChunks;
    this->sepChunks = (other.sepChunks_arraysize==0) ? nullptr : new uint16_t[other.sepChunks_arraysize];
    sepChunks_arraysize = other.sepChunks_arraysize;
    for (size_t i = 0; i < sepChunks_arraysize; i++) {
        this->sepChunks[i] = other.sepChunks[i];
    }
    delete [] this->hmacTypes;
    this->hmacTypes = (other.hmacTypes_arraysize==0) ? nullptr : new uint16_t[other.hmacTypes_arraysize];
    hmacTypes_arraysize = other.hmacTypes_arraysize;
    for (size_t i = 0; i < hmacTypes_arraysize; i++) {
        this->hmacTypes[i] = other.hmacTypes[i];
    }
}

void SctpInitAckChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->initTag);
    doParsimPacking(b,this->a_rwnd);
    doParsimPacking(b,this->noOutStreams);
    doParsimPacking(b,this->noInStreams);
    doParsimPacking(b,this->initTsn);
    doParsimPacking(b,this->forwardTsn);
    doParsimPacking(b,this->ipv4Supported);
    doParsimPacking(b,this->ipv6Supported);
    b->pack(addresses_arraysize);
    doParsimArrayPacking(b,this->addresses,addresses_arraysize);
    b->pack(cookie_arraysize);
    doParsimArrayPacking(b,this->cookie,cookie_arraysize);
    b->pack(unrecognizedParameters_arraysize);
    doParsimArrayPacking(b,this->unrecognizedParameters,unrecognizedParameters_arraysize);
    doParsimPacking(b,this->stateCookie);
    doParsimPacking(b,this->msg_rwnd);
    b->pack(random_arraysize);
    doParsimArrayPacking(b,this->random,random_arraysize);
    b->pack(sctpChunkTypes_arraysize);
    doParsimArrayPacking(b,this->sctpChunkTypes,sctpChunkTypes_arraysize);
    b->pack(sepChunks_arraysize);
    doParsimArrayPacking(b,this->sepChunks,sepChunks_arraysize);
    b->pack(hmacTypes_arraysize);
    doParsimArrayPacking(b,this->hmacTypes,hmacTypes_arraysize);
}

void SctpInitAckChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->initTag);
    doParsimUnpacking(b,this->a_rwnd);
    doParsimUnpacking(b,this->noOutStreams);
    doParsimUnpacking(b,this->noInStreams);
    doParsimUnpacking(b,this->initTsn);
    doParsimUnpacking(b,this->forwardTsn);
    doParsimUnpacking(b,this->ipv4Supported);
    doParsimUnpacking(b,this->ipv6Supported);
    delete [] this->addresses;
    b->unpack(addresses_arraysize);
    if (addresses_arraysize == 0) {
        this->addresses = nullptr;
    } else {
        this->addresses = new L3Address[addresses_arraysize];
        doParsimArrayUnpacking(b,this->addresses,addresses_arraysize);
    }
    delete [] this->cookie;
    b->unpack(cookie_arraysize);
    if (cookie_arraysize == 0) {
        this->cookie = nullptr;
    } else {
        this->cookie = new char[cookie_arraysize];
        doParsimArrayUnpacking(b,this->cookie,cookie_arraysize);
    }
    delete [] this->unrecognizedParameters;
    b->unpack(unrecognizedParameters_arraysize);
    if (unrecognizedParameters_arraysize == 0) {
        this->unrecognizedParameters = nullptr;
    } else {
        this->unrecognizedParameters = new uint8_t[unrecognizedParameters_arraysize];
        doParsimArrayUnpacking(b,this->unrecognizedParameters,unrecognizedParameters_arraysize);
    }
    doParsimUnpacking(b,this->stateCookie);
    doParsimUnpacking(b,this->msg_rwnd);
    delete [] this->random;
    b->unpack(random_arraysize);
    if (random_arraysize == 0) {
        this->random = nullptr;
    } else {
        this->random = new uint8_t[random_arraysize];
        doParsimArrayUnpacking(b,this->random,random_arraysize);
    }
    delete [] this->sctpChunkTypes;
    b->unpack(sctpChunkTypes_arraysize);
    if (sctpChunkTypes_arraysize == 0) {
        this->sctpChunkTypes = nullptr;
    } else {
        this->sctpChunkTypes = new uint16_t[sctpChunkTypes_arraysize];
        doParsimArrayUnpacking(b,this->sctpChunkTypes,sctpChunkTypes_arraysize);
    }
    delete [] this->sepChunks;
    b->unpack(sepChunks_arraysize);
    if (sepChunks_arraysize == 0) {
        this->sepChunks = nullptr;
    } else {
        this->sepChunks = new uint16_t[sepChunks_arraysize];
        doParsimArrayUnpacking(b,this->sepChunks,sepChunks_arraysize);
    }
    delete [] this->hmacTypes;
    b->unpack(hmacTypes_arraysize);
    if (hmacTypes_arraysize == 0) {
        this->hmacTypes = nullptr;
    } else {
        this->hmacTypes = new uint16_t[hmacTypes_arraysize];
        doParsimArrayUnpacking(b,this->hmacTypes,hmacTypes_arraysize);
    }
}

uint32_t SctpInitAckChunk::getInitTag() const
{
    return this->initTag;
}

void SctpInitAckChunk::setInitTag(uint32_t initTag)
{
    this->initTag = initTag;
}

uint32_t SctpInitAckChunk::getA_rwnd() const
{
    return this->a_rwnd;
}

void SctpInitAckChunk::setA_rwnd(uint32_t a_rwnd)
{
    this->a_rwnd = a_rwnd;
}

uint16_t SctpInitAckChunk::getNoOutStreams() const
{
    return this->noOutStreams;
}

void SctpInitAckChunk::setNoOutStreams(uint16_t noOutStreams)
{
    this->noOutStreams = noOutStreams;
}

uint16_t SctpInitAckChunk::getNoInStreams() const
{
    return this->noInStreams;
}

void SctpInitAckChunk::setNoInStreams(uint16_t noInStreams)
{
    this->noInStreams = noInStreams;
}

uint32_t SctpInitAckChunk::getInitTsn() const
{
    return this->initTsn;
}

void SctpInitAckChunk::setInitTsn(uint32_t initTsn)
{
    this->initTsn = initTsn;
}

bool SctpInitAckChunk::getForwardTsn() const
{
    return this->forwardTsn;
}

void SctpInitAckChunk::setForwardTsn(bool forwardTsn)
{
    this->forwardTsn = forwardTsn;
}

bool SctpInitAckChunk::getIpv4Supported() const
{
    return this->ipv4Supported;
}

void SctpInitAckChunk::setIpv4Supported(bool ipv4Supported)
{
    this->ipv4Supported = ipv4Supported;
}

bool SctpInitAckChunk::getIpv6Supported() const
{
    return this->ipv6Supported;
}

void SctpInitAckChunk::setIpv6Supported(bool ipv6Supported)
{
    this->ipv6Supported = ipv6Supported;
}

size_t SctpInitAckChunk::getAddressesArraySize() const
{
    return addresses_arraysize;
}

const L3Address& SctpInitAckChunk::getAddresses(size_t k) const
{
    if (k >= addresses_arraysize) throw omnetpp::cRuntimeError("Array of size addresses_arraysize indexed by %lu", (unsigned long)k);
    return this->addresses[k];
}

void SctpInitAckChunk::setAddressesArraySize(size_t newSize)
{
    L3Address *addresses2 = (newSize==0) ? nullptr : new L3Address[newSize];
    size_t minSize = addresses_arraysize < newSize ? addresses_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        addresses2[i] = this->addresses[i];
    delete [] this->addresses;
    this->addresses = addresses2;
    addresses_arraysize = newSize;
}

void SctpInitAckChunk::setAddresses(size_t k, const L3Address& addresses)
{
    if (k >= addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->addresses[k] = addresses;
}

void SctpInitAckChunk::insertAddresses(size_t k, const L3Address& addresses)
{
    if (k > addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = addresses_arraysize + 1;
    L3Address *addresses2 = new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        addresses2[i] = this->addresses[i];
    addresses2[k] = addresses;
    for (i = k + 1; i < newSize; i++)
        addresses2[i] = this->addresses[i-1];
    delete [] this->addresses;
    this->addresses = addresses2;
    addresses_arraysize = newSize;
}

void SctpInitAckChunk::insertAddresses(const L3Address& addresses)
{
    insertAddresses(addresses_arraysize, addresses);
}

void SctpInitAckChunk::eraseAddresses(size_t k)
{
    if (k >= addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = addresses_arraysize - 1;
    L3Address *addresses2 = (newSize == 0) ? nullptr : new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        addresses2[i] = this->addresses[i];
    for (i = k; i < newSize; i++)
        addresses2[i] = this->addresses[i+1];
    delete [] this->addresses;
    this->addresses = addresses2;
    addresses_arraysize = newSize;
}

size_t SctpInitAckChunk::getCookieArraySize() const
{
    return cookie_arraysize;
}

char SctpInitAckChunk::getCookie(size_t k) const
{
    if (k >= cookie_arraysize) throw omnetpp::cRuntimeError("Array of size cookie_arraysize indexed by %lu", (unsigned long)k);
    return this->cookie[k];
}

void SctpInitAckChunk::setCookieArraySize(size_t newSize)
{
    char *cookie2 = (newSize==0) ? nullptr : new char[newSize];
    size_t minSize = cookie_arraysize < newSize ? cookie_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        cookie2[i] = this->cookie[i];
    for (size_t i = minSize; i < newSize; i++)
        cookie2[i] = 0;
    delete [] this->cookie;
    this->cookie = cookie2;
    cookie_arraysize = newSize;
}

void SctpInitAckChunk::setCookie(size_t k, char cookie)
{
    if (k >= cookie_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->cookie[k] = cookie;
}

void SctpInitAckChunk::insertCookie(size_t k, char cookie)
{
    if (k > cookie_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = cookie_arraysize + 1;
    char *cookie2 = new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        cookie2[i] = this->cookie[i];
    cookie2[k] = cookie;
    for (i = k + 1; i < newSize; i++)
        cookie2[i] = this->cookie[i-1];
    delete [] this->cookie;
    this->cookie = cookie2;
    cookie_arraysize = newSize;
}

void SctpInitAckChunk::insertCookie(char cookie)
{
    insertCookie(cookie_arraysize, cookie);
}

void SctpInitAckChunk::eraseCookie(size_t k)
{
    if (k >= cookie_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = cookie_arraysize - 1;
    char *cookie2 = (newSize == 0) ? nullptr : new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        cookie2[i] = this->cookie[i];
    for (i = k; i < newSize; i++)
        cookie2[i] = this->cookie[i+1];
    delete [] this->cookie;
    this->cookie = cookie2;
    cookie_arraysize = newSize;
}

size_t SctpInitAckChunk::getUnrecognizedParametersArraySize() const
{
    return unrecognizedParameters_arraysize;
}

uint8_t SctpInitAckChunk::getUnrecognizedParameters(size_t k) const
{
    if (k >= unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size unrecognizedParameters_arraysize indexed by %lu", (unsigned long)k);
    return this->unrecognizedParameters[k];
}

void SctpInitAckChunk::setUnrecognizedParametersArraySize(size_t newSize)
{
    uint8_t *unrecognizedParameters2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = unrecognizedParameters_arraysize < newSize ? unrecognizedParameters_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i];
    for (size_t i = minSize; i < newSize; i++)
        unrecognizedParameters2[i] = 0;
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = unrecognizedParameters2;
    unrecognizedParameters_arraysize = newSize;
}

void SctpInitAckChunk::setUnrecognizedParameters(size_t k, uint8_t unrecognizedParameters)
{
    if (k >= unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->unrecognizedParameters[k] = unrecognizedParameters;
}

void SctpInitAckChunk::insertUnrecognizedParameters(size_t k, uint8_t unrecognizedParameters)
{
    if (k > unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = unrecognizedParameters_arraysize + 1;
    uint8_t *unrecognizedParameters2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i];
    unrecognizedParameters2[k] = unrecognizedParameters;
    for (i = k + 1; i < newSize; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i-1];
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = unrecognizedParameters2;
    unrecognizedParameters_arraysize = newSize;
}

void SctpInitAckChunk::insertUnrecognizedParameters(uint8_t unrecognizedParameters)
{
    insertUnrecognizedParameters(unrecognizedParameters_arraysize, unrecognizedParameters);
}

void SctpInitAckChunk::eraseUnrecognizedParameters(size_t k)
{
    if (k >= unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = unrecognizedParameters_arraysize - 1;
    uint8_t *unrecognizedParameters2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i];
    for (i = k; i < newSize; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i+1];
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = unrecognizedParameters2;
    unrecognizedParameters_arraysize = newSize;
}

const SctpCookie * SctpInitAckChunk::getStateCookie() const
{
    return this->stateCookie;
}

void SctpInitAckChunk::setStateCookie(SctpCookie * stateCookie)
{
    this->stateCookie = stateCookie;
}

uint32_t SctpInitAckChunk::getMsg_rwnd() const
{
    return this->msg_rwnd;
}

void SctpInitAckChunk::setMsg_rwnd(uint32_t msg_rwnd)
{
    this->msg_rwnd = msg_rwnd;
}

size_t SctpInitAckChunk::getRandomArraySize() const
{
    return random_arraysize;
}

uint8_t SctpInitAckChunk::getRandom(size_t k) const
{
    if (k >= random_arraysize) throw omnetpp::cRuntimeError("Array of size random_arraysize indexed by %lu", (unsigned long)k);
    return this->random[k];
}

void SctpInitAckChunk::setRandomArraySize(size_t newSize)
{
    uint8_t *random2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = random_arraysize < newSize ? random_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        random2[i] = this->random[i];
    for (size_t i = minSize; i < newSize; i++)
        random2[i] = 0;
    delete [] this->random;
    this->random = random2;
    random_arraysize = newSize;
}

void SctpInitAckChunk::setRandom(size_t k, uint8_t random)
{
    if (k >= random_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->random[k] = random;
}

void SctpInitAckChunk::insertRandom(size_t k, uint8_t random)
{
    if (k > random_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = random_arraysize + 1;
    uint8_t *random2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        random2[i] = this->random[i];
    random2[k] = random;
    for (i = k + 1; i < newSize; i++)
        random2[i] = this->random[i-1];
    delete [] this->random;
    this->random = random2;
    random_arraysize = newSize;
}

void SctpInitAckChunk::insertRandom(uint8_t random)
{
    insertRandom(random_arraysize, random);
}

void SctpInitAckChunk::eraseRandom(size_t k)
{
    if (k >= random_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = random_arraysize - 1;
    uint8_t *random2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        random2[i] = this->random[i];
    for (i = k; i < newSize; i++)
        random2[i] = this->random[i+1];
    delete [] this->random;
    this->random = random2;
    random_arraysize = newSize;
}

size_t SctpInitAckChunk::getSctpChunkTypesArraySize() const
{
    return sctpChunkTypes_arraysize;
}

uint16_t SctpInitAckChunk::getSctpChunkTypes(size_t k) const
{
    if (k >= sctpChunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size sctpChunkTypes_arraysize indexed by %lu", (unsigned long)k);
    return this->sctpChunkTypes[k];
}

void SctpInitAckChunk::setSctpChunkTypesArraySize(size_t newSize)
{
    uint16_t *sctpChunkTypes2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = sctpChunkTypes_arraysize < newSize ? sctpChunkTypes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i];
    for (size_t i = minSize; i < newSize; i++)
        sctpChunkTypes2[i] = 0;
    delete [] this->sctpChunkTypes;
    this->sctpChunkTypes = sctpChunkTypes2;
    sctpChunkTypes_arraysize = newSize;
}

void SctpInitAckChunk::setSctpChunkTypes(size_t k, uint16_t sctpChunkTypes)
{
    if (k >= sctpChunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->sctpChunkTypes[k] = sctpChunkTypes;
}

void SctpInitAckChunk::insertSctpChunkTypes(size_t k, uint16_t sctpChunkTypes)
{
    if (k > sctpChunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sctpChunkTypes_arraysize + 1;
    uint16_t *sctpChunkTypes2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i];
    sctpChunkTypes2[k] = sctpChunkTypes;
    for (i = k + 1; i < newSize; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i-1];
    delete [] this->sctpChunkTypes;
    this->sctpChunkTypes = sctpChunkTypes2;
    sctpChunkTypes_arraysize = newSize;
}

void SctpInitAckChunk::insertSctpChunkTypes(uint16_t sctpChunkTypes)
{
    insertSctpChunkTypes(sctpChunkTypes_arraysize, sctpChunkTypes);
}

void SctpInitAckChunk::eraseSctpChunkTypes(size_t k)
{
    if (k >= sctpChunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sctpChunkTypes_arraysize - 1;
    uint16_t *sctpChunkTypes2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i];
    for (i = k; i < newSize; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i+1];
    delete [] this->sctpChunkTypes;
    this->sctpChunkTypes = sctpChunkTypes2;
    sctpChunkTypes_arraysize = newSize;
}

size_t SctpInitAckChunk::getSepChunksArraySize() const
{
    return sepChunks_arraysize;
}

uint16_t SctpInitAckChunk::getSepChunks(size_t k) const
{
    if (k >= sepChunks_arraysize) throw omnetpp::cRuntimeError("Array of size sepChunks_arraysize indexed by %lu", (unsigned long)k);
    return this->sepChunks[k];
}

void SctpInitAckChunk::setSepChunksArraySize(size_t newSize)
{
    uint16_t *sepChunks2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = sepChunks_arraysize < newSize ? sepChunks_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sepChunks2[i] = this->sepChunks[i];
    for (size_t i = minSize; i < newSize; i++)
        sepChunks2[i] = 0;
    delete [] this->sepChunks;
    this->sepChunks = sepChunks2;
    sepChunks_arraysize = newSize;
}

void SctpInitAckChunk::setSepChunks(size_t k, uint16_t sepChunks)
{
    if (k >= sepChunks_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->sepChunks[k] = sepChunks;
}

void SctpInitAckChunk::insertSepChunks(size_t k, uint16_t sepChunks)
{
    if (k > sepChunks_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sepChunks_arraysize + 1;
    uint16_t *sepChunks2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sepChunks2[i] = this->sepChunks[i];
    sepChunks2[k] = sepChunks;
    for (i = k + 1; i < newSize; i++)
        sepChunks2[i] = this->sepChunks[i-1];
    delete [] this->sepChunks;
    this->sepChunks = sepChunks2;
    sepChunks_arraysize = newSize;
}

void SctpInitAckChunk::insertSepChunks(uint16_t sepChunks)
{
    insertSepChunks(sepChunks_arraysize, sepChunks);
}

void SctpInitAckChunk::eraseSepChunks(size_t k)
{
    if (k >= sepChunks_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sepChunks_arraysize - 1;
    uint16_t *sepChunks2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sepChunks2[i] = this->sepChunks[i];
    for (i = k; i < newSize; i++)
        sepChunks2[i] = this->sepChunks[i+1];
    delete [] this->sepChunks;
    this->sepChunks = sepChunks2;
    sepChunks_arraysize = newSize;
}

size_t SctpInitAckChunk::getHmacTypesArraySize() const
{
    return hmacTypes_arraysize;
}

uint16_t SctpInitAckChunk::getHmacTypes(size_t k) const
{
    if (k >= hmacTypes_arraysize) throw omnetpp::cRuntimeError("Array of size hmacTypes_arraysize indexed by %lu", (unsigned long)k);
    return this->hmacTypes[k];
}

void SctpInitAckChunk::setHmacTypesArraySize(size_t newSize)
{
    uint16_t *hmacTypes2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = hmacTypes_arraysize < newSize ? hmacTypes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        hmacTypes2[i] = this->hmacTypes[i];
    for (size_t i = minSize; i < newSize; i++)
        hmacTypes2[i] = 0;
    delete [] this->hmacTypes;
    this->hmacTypes = hmacTypes2;
    hmacTypes_arraysize = newSize;
}

void SctpInitAckChunk::setHmacTypes(size_t k, uint16_t hmacTypes)
{
    if (k >= hmacTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->hmacTypes[k] = hmacTypes;
}

void SctpInitAckChunk::insertHmacTypes(size_t k, uint16_t hmacTypes)
{
    if (k > hmacTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = hmacTypes_arraysize + 1;
    uint16_t *hmacTypes2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        hmacTypes2[i] = this->hmacTypes[i];
    hmacTypes2[k] = hmacTypes;
    for (i = k + 1; i < newSize; i++)
        hmacTypes2[i] = this->hmacTypes[i-1];
    delete [] this->hmacTypes;
    this->hmacTypes = hmacTypes2;
    hmacTypes_arraysize = newSize;
}

void SctpInitAckChunk::insertHmacTypes(uint16_t hmacTypes)
{
    insertHmacTypes(hmacTypes_arraysize, hmacTypes);
}

void SctpInitAckChunk::eraseHmacTypes(size_t k)
{
    if (k >= hmacTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = hmacTypes_arraysize - 1;
    uint16_t *hmacTypes2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        hmacTypes2[i] = this->hmacTypes[i];
    for (i = k; i < newSize; i++)
        hmacTypes2[i] = this->hmacTypes[i+1];
    delete [] this->hmacTypes;
    this->hmacTypes = hmacTypes2;
    hmacTypes_arraysize = newSize;
}

class SctpInitAckChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_initTag,
        FIELD_a_rwnd,
        FIELD_noOutStreams,
        FIELD_noInStreams,
        FIELD_initTsn,
        FIELD_forwardTsn,
        FIELD_ipv4Supported,
        FIELD_ipv6Supported,
        FIELD_addresses,
        FIELD_cookie,
        FIELD_unrecognizedParameters,
        FIELD_stateCookie,
        FIELD_msg_rwnd,
        FIELD_random,
        FIELD_sctpChunkTypes,
        FIELD_sepChunks,
        FIELD_hmacTypes,
    };
  public:
    SctpInitAckChunkDescriptor();
    virtual ~SctpInitAckChunkDescriptor();

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

Register_ClassDescriptor(SctpInitAckChunkDescriptor)

SctpInitAckChunkDescriptor::SctpInitAckChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpInitAckChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpInitAckChunkDescriptor::~SctpInitAckChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpInitAckChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpInitAckChunk *>(obj)!=nullptr;
}

const char **SctpInitAckChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpInitAckChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpInitAckChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 17+basedesc->getFieldCount() : 17;
}

unsigned int SctpInitAckChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_initTag
        FD_ISEDITABLE,    // FIELD_a_rwnd
        FD_ISEDITABLE,    // FIELD_noOutStreams
        FD_ISEDITABLE,    // FIELD_noInStreams
        FD_ISEDITABLE,    // FIELD_initTsn
        FD_ISEDITABLE,    // FIELD_forwardTsn
        FD_ISEDITABLE,    // FIELD_ipv4Supported
        FD_ISEDITABLE,    // FIELD_ipv6Supported
        FD_ISARRAY,    // FIELD_addresses
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_cookie
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_unrecognizedParameters
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_stateCookie
        FD_ISEDITABLE,    // FIELD_msg_rwnd
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_random
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_sctpChunkTypes
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_sepChunks
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_hmacTypes
    };
    return (field >= 0 && field < 17) ? fieldTypeFlags[field] : 0;
}

const char *SctpInitAckChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "initTag",
        "a_rwnd",
        "noOutStreams",
        "noInStreams",
        "initTsn",
        "forwardTsn",
        "ipv4Supported",
        "ipv6Supported",
        "addresses",
        "cookie",
        "unrecognizedParameters",
        "stateCookie",
        "msg_rwnd",
        "random",
        "sctpChunkTypes",
        "sepChunks",
        "hmacTypes",
    };
    return (field >= 0 && field < 17) ? fieldNames[field] : nullptr;
}

int SctpInitAckChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "initTag") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "a_rwnd") == 0) return base+1;
    if (fieldName[0] == 'n' && strcmp(fieldName, "noOutStreams") == 0) return base+2;
    if (fieldName[0] == 'n' && strcmp(fieldName, "noInStreams") == 0) return base+3;
    if (fieldName[0] == 'i' && strcmp(fieldName, "initTsn") == 0) return base+4;
    if (fieldName[0] == 'f' && strcmp(fieldName, "forwardTsn") == 0) return base+5;
    if (fieldName[0] == 'i' && strcmp(fieldName, "ipv4Supported") == 0) return base+6;
    if (fieldName[0] == 'i' && strcmp(fieldName, "ipv6Supported") == 0) return base+7;
    if (fieldName[0] == 'a' && strcmp(fieldName, "addresses") == 0) return base+8;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cookie") == 0) return base+9;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unrecognizedParameters") == 0) return base+10;
    if (fieldName[0] == 's' && strcmp(fieldName, "stateCookie") == 0) return base+11;
    if (fieldName[0] == 'm' && strcmp(fieldName, "msg_rwnd") == 0) return base+12;
    if (fieldName[0] == 'r' && strcmp(fieldName, "random") == 0) return base+13;
    if (fieldName[0] == 's' && strcmp(fieldName, "sctpChunkTypes") == 0) return base+14;
    if (fieldName[0] == 's' && strcmp(fieldName, "sepChunks") == 0) return base+15;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hmacTypes") == 0) return base+16;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpInitAckChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_initTag
        "uint32",    // FIELD_a_rwnd
        "uint16",    // FIELD_noOutStreams
        "uint16",    // FIELD_noInStreams
        "uint32",    // FIELD_initTsn
        "bool",    // FIELD_forwardTsn
        "bool",    // FIELD_ipv4Supported
        "bool",    // FIELD_ipv6Supported
        "inet::L3Address",    // FIELD_addresses
        "char",    // FIELD_cookie
        "uint8",    // FIELD_unrecognizedParameters
        "inet::sctp::SctpCookie",    // FIELD_stateCookie
        "uint32",    // FIELD_msg_rwnd
        "uint8",    // FIELD_random
        "uint16",    // FIELD_sctpChunkTypes
        "uint16",    // FIELD_sepChunks
        "uint16",    // FIELD_hmacTypes
    };
    return (field >= 0 && field < 17) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpInitAckChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpInitAckChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpInitAckChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpInitAckChunk *pp = (SctpInitAckChunk *)object; (void)pp;
    switch (field) {
        case FIELD_addresses: return pp->getAddressesArraySize();
        case FIELD_cookie: return pp->getCookieArraySize();
        case FIELD_unrecognizedParameters: return pp->getUnrecognizedParametersArraySize();
        case FIELD_random: return pp->getRandomArraySize();
        case FIELD_sctpChunkTypes: return pp->getSctpChunkTypesArraySize();
        case FIELD_sepChunks: return pp->getSepChunksArraySize();
        case FIELD_hmacTypes: return pp->getHmacTypesArraySize();
        default: return 0;
    }
}

const char *SctpInitAckChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpInitAckChunk *pp = (SctpInitAckChunk *)object; (void)pp;
    switch (field) {
        case FIELD_stateCookie: { const SctpCookie * value = pp->getStateCookie(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string SctpInitAckChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpInitAckChunk *pp = (SctpInitAckChunk *)object; (void)pp;
    switch (field) {
        case FIELD_initTag: return ulong2string(pp->getInitTag());
        case FIELD_a_rwnd: return ulong2string(pp->getA_rwnd());
        case FIELD_noOutStreams: return ulong2string(pp->getNoOutStreams());
        case FIELD_noInStreams: return ulong2string(pp->getNoInStreams());
        case FIELD_initTsn: return ulong2string(pp->getInitTsn());
        case FIELD_forwardTsn: return bool2string(pp->getForwardTsn());
        case FIELD_ipv4Supported: return bool2string(pp->getIpv4Supported());
        case FIELD_ipv6Supported: return bool2string(pp->getIpv6Supported());
        case FIELD_addresses: return pp->getAddresses(i).str();
        case FIELD_cookie: return long2string(pp->getCookie(i));
        case FIELD_unrecognizedParameters: return ulong2string(pp->getUnrecognizedParameters(i));
        case FIELD_stateCookie: {std::stringstream out; out << pp->getStateCookie(); return out.str();}
        case FIELD_msg_rwnd: return ulong2string(pp->getMsg_rwnd());
        case FIELD_random: return ulong2string(pp->getRandom(i));
        case FIELD_sctpChunkTypes: return ulong2string(pp->getSctpChunkTypes(i));
        case FIELD_sepChunks: return ulong2string(pp->getSepChunks(i));
        case FIELD_hmacTypes: return ulong2string(pp->getHmacTypes(i));
        default: return "";
    }
}

bool SctpInitAckChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpInitAckChunk *pp = (SctpInitAckChunk *)object; (void)pp;
    switch (field) {
        case FIELD_initTag: pp->setInitTag(string2ulong(value)); return true;
        case FIELD_a_rwnd: pp->setA_rwnd(string2ulong(value)); return true;
        case FIELD_noOutStreams: pp->setNoOutStreams(string2ulong(value)); return true;
        case FIELD_noInStreams: pp->setNoInStreams(string2ulong(value)); return true;
        case FIELD_initTsn: pp->setInitTsn(string2ulong(value)); return true;
        case FIELD_forwardTsn: pp->setForwardTsn(string2bool(value)); return true;
        case FIELD_ipv4Supported: pp->setIpv4Supported(string2bool(value)); return true;
        case FIELD_ipv6Supported: pp->setIpv6Supported(string2bool(value)); return true;
        case FIELD_cookie: pp->setCookie(i,string2long(value)); return true;
        case FIELD_unrecognizedParameters: pp->setUnrecognizedParameters(i,string2ulong(value)); return true;
        case FIELD_msg_rwnd: pp->setMsg_rwnd(string2ulong(value)); return true;
        case FIELD_random: pp->setRandom(i,string2ulong(value)); return true;
        case FIELD_sctpChunkTypes: pp->setSctpChunkTypes(i,string2ulong(value)); return true;
        case FIELD_sepChunks: pp->setSepChunks(i,string2ulong(value)); return true;
        case FIELD_hmacTypes: pp->setHmacTypes(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpInitAckChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_stateCookie: return omnetpp::opp_typename(typeid(SctpCookie));
        default: return nullptr;
    };
}

void *SctpInitAckChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpInitAckChunk *pp = (SctpInitAckChunk *)object; (void)pp;
    switch (field) {
        case FIELD_addresses: return toVoidPtr(&pp->getAddresses(i)); break;
        case FIELD_stateCookie: return toVoidPtr(pp->getStateCookie()); break;
        default: return nullptr;
    }
}

Register_Class(SctpCookieEchoChunk)

SctpCookieEchoChunk::SctpCookieEchoChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpCookieEchoChunk::SctpCookieEchoChunk(const SctpCookieEchoChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpCookieEchoChunk::~SctpCookieEchoChunk()
{
    delete [] this->cookie;
    delete [] this->unrecognizedParameters;
}

SctpCookieEchoChunk& SctpCookieEchoChunk::operator=(const SctpCookieEchoChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpCookieEchoChunk::copy(const SctpCookieEchoChunk& other)
{
    delete [] this->cookie;
    this->cookie = (other.cookie_arraysize==0) ? nullptr : new char[other.cookie_arraysize];
    cookie_arraysize = other.cookie_arraysize;
    for (size_t i = 0; i < cookie_arraysize; i++) {
        this->cookie[i] = other.cookie[i];
    }
    this->stateCookie = other.stateCookie;
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = (other.unrecognizedParameters_arraysize==0) ? nullptr : new uint8_t[other.unrecognizedParameters_arraysize];
    unrecognizedParameters_arraysize = other.unrecognizedParameters_arraysize;
    for (size_t i = 0; i < unrecognizedParameters_arraysize; i++) {
        this->unrecognizedParameters[i] = other.unrecognizedParameters[i];
    }
}

void SctpCookieEchoChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    b->pack(cookie_arraysize);
    doParsimArrayPacking(b,this->cookie,cookie_arraysize);
    doParsimPacking(b,this->stateCookie);
    b->pack(unrecognizedParameters_arraysize);
    doParsimArrayPacking(b,this->unrecognizedParameters,unrecognizedParameters_arraysize);
}

void SctpCookieEchoChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    delete [] this->cookie;
    b->unpack(cookie_arraysize);
    if (cookie_arraysize == 0) {
        this->cookie = nullptr;
    } else {
        this->cookie = new char[cookie_arraysize];
        doParsimArrayUnpacking(b,this->cookie,cookie_arraysize);
    }
    doParsimUnpacking(b,this->stateCookie);
    delete [] this->unrecognizedParameters;
    b->unpack(unrecognizedParameters_arraysize);
    if (unrecognizedParameters_arraysize == 0) {
        this->unrecognizedParameters = nullptr;
    } else {
        this->unrecognizedParameters = new uint8_t[unrecognizedParameters_arraysize];
        doParsimArrayUnpacking(b,this->unrecognizedParameters,unrecognizedParameters_arraysize);
    }
}

size_t SctpCookieEchoChunk::getCookieArraySize() const
{
    return cookie_arraysize;
}

char SctpCookieEchoChunk::getCookie(size_t k) const
{
    if (k >= cookie_arraysize) throw omnetpp::cRuntimeError("Array of size cookie_arraysize indexed by %lu", (unsigned long)k);
    return this->cookie[k];
}

void SctpCookieEchoChunk::setCookieArraySize(size_t newSize)
{
    char *cookie2 = (newSize==0) ? nullptr : new char[newSize];
    size_t minSize = cookie_arraysize < newSize ? cookie_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        cookie2[i] = this->cookie[i];
    for (size_t i = minSize; i < newSize; i++)
        cookie2[i] = 0;
    delete [] this->cookie;
    this->cookie = cookie2;
    cookie_arraysize = newSize;
}

void SctpCookieEchoChunk::setCookie(size_t k, char cookie)
{
    if (k >= cookie_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->cookie[k] = cookie;
}

void SctpCookieEchoChunk::insertCookie(size_t k, char cookie)
{
    if (k > cookie_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = cookie_arraysize + 1;
    char *cookie2 = new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        cookie2[i] = this->cookie[i];
    cookie2[k] = cookie;
    for (i = k + 1; i < newSize; i++)
        cookie2[i] = this->cookie[i-1];
    delete [] this->cookie;
    this->cookie = cookie2;
    cookie_arraysize = newSize;
}

void SctpCookieEchoChunk::insertCookie(char cookie)
{
    insertCookie(cookie_arraysize, cookie);
}

void SctpCookieEchoChunk::eraseCookie(size_t k)
{
    if (k >= cookie_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = cookie_arraysize - 1;
    char *cookie2 = (newSize == 0) ? nullptr : new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        cookie2[i] = this->cookie[i];
    for (i = k; i < newSize; i++)
        cookie2[i] = this->cookie[i+1];
    delete [] this->cookie;
    this->cookie = cookie2;
    cookie_arraysize = newSize;
}

const SctpCookie * SctpCookieEchoChunk::getStateCookie() const
{
    return this->stateCookie;
}

void SctpCookieEchoChunk::setStateCookie(SctpCookie * stateCookie)
{
    this->stateCookie = stateCookie;
}

size_t SctpCookieEchoChunk::getUnrecognizedParametersArraySize() const
{
    return unrecognizedParameters_arraysize;
}

uint8_t SctpCookieEchoChunk::getUnrecognizedParameters(size_t k) const
{
    if (k >= unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size unrecognizedParameters_arraysize indexed by %lu", (unsigned long)k);
    return this->unrecognizedParameters[k];
}

void SctpCookieEchoChunk::setUnrecognizedParametersArraySize(size_t newSize)
{
    uint8_t *unrecognizedParameters2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = unrecognizedParameters_arraysize < newSize ? unrecognizedParameters_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i];
    for (size_t i = minSize; i < newSize; i++)
        unrecognizedParameters2[i] = 0;
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = unrecognizedParameters2;
    unrecognizedParameters_arraysize = newSize;
}

void SctpCookieEchoChunk::setUnrecognizedParameters(size_t k, uint8_t unrecognizedParameters)
{
    if (k >= unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->unrecognizedParameters[k] = unrecognizedParameters;
}

void SctpCookieEchoChunk::insertUnrecognizedParameters(size_t k, uint8_t unrecognizedParameters)
{
    if (k > unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = unrecognizedParameters_arraysize + 1;
    uint8_t *unrecognizedParameters2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i];
    unrecognizedParameters2[k] = unrecognizedParameters;
    for (i = k + 1; i < newSize; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i-1];
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = unrecognizedParameters2;
    unrecognizedParameters_arraysize = newSize;
}

void SctpCookieEchoChunk::insertUnrecognizedParameters(uint8_t unrecognizedParameters)
{
    insertUnrecognizedParameters(unrecognizedParameters_arraysize, unrecognizedParameters);
}

void SctpCookieEchoChunk::eraseUnrecognizedParameters(size_t k)
{
    if (k >= unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = unrecognizedParameters_arraysize - 1;
    uint8_t *unrecognizedParameters2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i];
    for (i = k; i < newSize; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i+1];
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = unrecognizedParameters2;
    unrecognizedParameters_arraysize = newSize;
}

class SctpCookieEchoChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_cookie,
        FIELD_stateCookie,
        FIELD_unrecognizedParameters,
    };
  public:
    SctpCookieEchoChunkDescriptor();
    virtual ~SctpCookieEchoChunkDescriptor();

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

Register_ClassDescriptor(SctpCookieEchoChunkDescriptor)

SctpCookieEchoChunkDescriptor::SctpCookieEchoChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpCookieEchoChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpCookieEchoChunkDescriptor::~SctpCookieEchoChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpCookieEchoChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpCookieEchoChunk *>(obj)!=nullptr;
}

const char **SctpCookieEchoChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpCookieEchoChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpCookieEchoChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SctpCookieEchoChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_cookie
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_stateCookie
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_unrecognizedParameters
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SctpCookieEchoChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "cookie",
        "stateCookie",
        "unrecognizedParameters",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SctpCookieEchoChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cookie") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "stateCookie") == 0) return base+1;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unrecognizedParameters") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpCookieEchoChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",    // FIELD_cookie
        "inet::sctp::SctpCookie",    // FIELD_stateCookie
        "uint8",    // FIELD_unrecognizedParameters
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpCookieEchoChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpCookieEchoChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpCookieEchoChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpCookieEchoChunk *pp = (SctpCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case FIELD_cookie: return pp->getCookieArraySize();
        case FIELD_unrecognizedParameters: return pp->getUnrecognizedParametersArraySize();
        default: return 0;
    }
}

const char *SctpCookieEchoChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpCookieEchoChunk *pp = (SctpCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case FIELD_stateCookie: { const SctpCookie * value = pp->getStateCookie(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string SctpCookieEchoChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpCookieEchoChunk *pp = (SctpCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case FIELD_cookie: return long2string(pp->getCookie(i));
        case FIELD_stateCookie: {std::stringstream out; out << pp->getStateCookie(); return out.str();}
        case FIELD_unrecognizedParameters: return ulong2string(pp->getUnrecognizedParameters(i));
        default: return "";
    }
}

bool SctpCookieEchoChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpCookieEchoChunk *pp = (SctpCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case FIELD_cookie: pp->setCookie(i,string2long(value)); return true;
        case FIELD_unrecognizedParameters: pp->setUnrecognizedParameters(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpCookieEchoChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_stateCookie: return omnetpp::opp_typename(typeid(SctpCookie));
        default: return nullptr;
    };
}

void *SctpCookieEchoChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpCookieEchoChunk *pp = (SctpCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case FIELD_stateCookie: return toVoidPtr(pp->getStateCookie()); break;
        default: return nullptr;
    }
}

Register_Class(SctpCookie)

SctpCookie::SctpCookie(const char *name) : ::omnetpp::cNamedObject(name)
{
}

SctpCookie::SctpCookie(const SctpCookie& other) : ::omnetpp::cNamedObject(other)
{
    copy(other);
}

SctpCookie::~SctpCookie()
{
    delete [] this->localTieTag;
    delete [] this->peerTieTag;
}

SctpCookie& SctpCookie::operator=(const SctpCookie& other)
{
    if (this == &other) return *this;
    ::omnetpp::cNamedObject::operator=(other);
    copy(other);
    return *this;
}

void SctpCookie::copy(const SctpCookie& other)
{
    this->creationTime = other.creationTime;
    this->localTag = other.localTag;
    this->peerTag = other.peerTag;
    delete [] this->localTieTag;
    this->localTieTag = (other.localTieTag_arraysize==0) ? nullptr : new uint8_t[other.localTieTag_arraysize];
    localTieTag_arraysize = other.localTieTag_arraysize;
    for (size_t i = 0; i < localTieTag_arraysize; i++) {
        this->localTieTag[i] = other.localTieTag[i];
    }
    delete [] this->peerTieTag;
    this->peerTieTag = (other.peerTieTag_arraysize==0) ? nullptr : new uint8_t[other.peerTieTag_arraysize];
    peerTieTag_arraysize = other.peerTieTag_arraysize;
    for (size_t i = 0; i < peerTieTag_arraysize; i++) {
        this->peerTieTag[i] = other.peerTieTag[i];
    }
    this->length = other.length;
}

void SctpCookie::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cNamedObject::parsimPack(b);
    doParsimPacking(b,this->creationTime);
    doParsimPacking(b,this->localTag);
    doParsimPacking(b,this->peerTag);
    b->pack(localTieTag_arraysize);
    doParsimArrayPacking(b,this->localTieTag,localTieTag_arraysize);
    b->pack(peerTieTag_arraysize);
    doParsimArrayPacking(b,this->peerTieTag,peerTieTag_arraysize);
    doParsimPacking(b,this->length);
}

void SctpCookie::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cNamedObject::parsimUnpack(b);
    doParsimUnpacking(b,this->creationTime);
    doParsimUnpacking(b,this->localTag);
    doParsimUnpacking(b,this->peerTag);
    delete [] this->localTieTag;
    b->unpack(localTieTag_arraysize);
    if (localTieTag_arraysize == 0) {
        this->localTieTag = nullptr;
    } else {
        this->localTieTag = new uint8_t[localTieTag_arraysize];
        doParsimArrayUnpacking(b,this->localTieTag,localTieTag_arraysize);
    }
    delete [] this->peerTieTag;
    b->unpack(peerTieTag_arraysize);
    if (peerTieTag_arraysize == 0) {
        this->peerTieTag = nullptr;
    } else {
        this->peerTieTag = new uint8_t[peerTieTag_arraysize];
        doParsimArrayUnpacking(b,this->peerTieTag,peerTieTag_arraysize);
    }
    doParsimUnpacking(b,this->length);
}

omnetpp::simtime_t SctpCookie::getCreationTime() const
{
    return this->creationTime;
}

void SctpCookie::setCreationTime(omnetpp::simtime_t creationTime)
{
    this->creationTime = creationTime;
}

uint32_t SctpCookie::getLocalTag() const
{
    return this->localTag;
}

void SctpCookie::setLocalTag(uint32_t localTag)
{
    this->localTag = localTag;
}

uint32_t SctpCookie::getPeerTag() const
{
    return this->peerTag;
}

void SctpCookie::setPeerTag(uint32_t peerTag)
{
    this->peerTag = peerTag;
}

size_t SctpCookie::getLocalTieTagArraySize() const
{
    return localTieTag_arraysize;
}

uint8_t SctpCookie::getLocalTieTag(size_t k) const
{
    if (k >= localTieTag_arraysize) throw omnetpp::cRuntimeError("Array of size localTieTag_arraysize indexed by %lu", (unsigned long)k);
    return this->localTieTag[k];
}

void SctpCookie::setLocalTieTagArraySize(size_t newSize)
{
    uint8_t *localTieTag2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = localTieTag_arraysize < newSize ? localTieTag_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        localTieTag2[i] = this->localTieTag[i];
    for (size_t i = minSize; i < newSize; i++)
        localTieTag2[i] = 0;
    delete [] this->localTieTag;
    this->localTieTag = localTieTag2;
    localTieTag_arraysize = newSize;
}

void SctpCookie::setLocalTieTag(size_t k, uint8_t localTieTag)
{
    if (k >= localTieTag_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->localTieTag[k] = localTieTag;
}

void SctpCookie::insertLocalTieTag(size_t k, uint8_t localTieTag)
{
    if (k > localTieTag_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = localTieTag_arraysize + 1;
    uint8_t *localTieTag2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        localTieTag2[i] = this->localTieTag[i];
    localTieTag2[k] = localTieTag;
    for (i = k + 1; i < newSize; i++)
        localTieTag2[i] = this->localTieTag[i-1];
    delete [] this->localTieTag;
    this->localTieTag = localTieTag2;
    localTieTag_arraysize = newSize;
}

void SctpCookie::insertLocalTieTag(uint8_t localTieTag)
{
    insertLocalTieTag(localTieTag_arraysize, localTieTag);
}

void SctpCookie::eraseLocalTieTag(size_t k)
{
    if (k >= localTieTag_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = localTieTag_arraysize - 1;
    uint8_t *localTieTag2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        localTieTag2[i] = this->localTieTag[i];
    for (i = k; i < newSize; i++)
        localTieTag2[i] = this->localTieTag[i+1];
    delete [] this->localTieTag;
    this->localTieTag = localTieTag2;
    localTieTag_arraysize = newSize;
}

size_t SctpCookie::getPeerTieTagArraySize() const
{
    return peerTieTag_arraysize;
}

uint8_t SctpCookie::getPeerTieTag(size_t k) const
{
    if (k >= peerTieTag_arraysize) throw omnetpp::cRuntimeError("Array of size peerTieTag_arraysize indexed by %lu", (unsigned long)k);
    return this->peerTieTag[k];
}

void SctpCookie::setPeerTieTagArraySize(size_t newSize)
{
    uint8_t *peerTieTag2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = peerTieTag_arraysize < newSize ? peerTieTag_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        peerTieTag2[i] = this->peerTieTag[i];
    for (size_t i = minSize; i < newSize; i++)
        peerTieTag2[i] = 0;
    delete [] this->peerTieTag;
    this->peerTieTag = peerTieTag2;
    peerTieTag_arraysize = newSize;
}

void SctpCookie::setPeerTieTag(size_t k, uint8_t peerTieTag)
{
    if (k >= peerTieTag_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->peerTieTag[k] = peerTieTag;
}

void SctpCookie::insertPeerTieTag(size_t k, uint8_t peerTieTag)
{
    if (k > peerTieTag_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = peerTieTag_arraysize + 1;
    uint8_t *peerTieTag2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        peerTieTag2[i] = this->peerTieTag[i];
    peerTieTag2[k] = peerTieTag;
    for (i = k + 1; i < newSize; i++)
        peerTieTag2[i] = this->peerTieTag[i-1];
    delete [] this->peerTieTag;
    this->peerTieTag = peerTieTag2;
    peerTieTag_arraysize = newSize;
}

void SctpCookie::insertPeerTieTag(uint8_t peerTieTag)
{
    insertPeerTieTag(peerTieTag_arraysize, peerTieTag);
}

void SctpCookie::erasePeerTieTag(size_t k)
{
    if (k >= peerTieTag_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = peerTieTag_arraysize - 1;
    uint8_t *peerTieTag2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        peerTieTag2[i] = this->peerTieTag[i];
    for (i = k; i < newSize; i++)
        peerTieTag2[i] = this->peerTieTag[i+1];
    delete [] this->peerTieTag;
    this->peerTieTag = peerTieTag2;
    peerTieTag_arraysize = newSize;
}

uint32_t SctpCookie::getLength() const
{
    return this->length;
}

void SctpCookie::setLength(uint32_t length)
{
    this->length = length;
}

class SctpCookieDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_creationTime,
        FIELD_localTag,
        FIELD_peerTag,
        FIELD_localTieTag,
        FIELD_peerTieTag,
        FIELD_length,
    };
  public:
    SctpCookieDescriptor();
    virtual ~SctpCookieDescriptor();

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

Register_ClassDescriptor(SctpCookieDescriptor)

SctpCookieDescriptor::SctpCookieDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpCookie)), "omnetpp::cNamedObject")
{
    propertynames = nullptr;
}

SctpCookieDescriptor::~SctpCookieDescriptor()
{
    delete[] propertynames;
}

bool SctpCookieDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpCookie *>(obj)!=nullptr;
}

const char **SctpCookieDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpCookieDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpCookieDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int SctpCookieDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_creationTime
        FD_ISEDITABLE,    // FIELD_localTag
        FD_ISEDITABLE,    // FIELD_peerTag
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_localTieTag
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_peerTieTag
        FD_ISEDITABLE,    // FIELD_length
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *SctpCookieDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "creationTime",
        "localTag",
        "peerTag",
        "localTieTag",
        "peerTieTag",
        "length",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int SctpCookieDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "creationTime") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localTag") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "peerTag") == 0) return base+2;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localTieTag") == 0) return base+3;
    if (fieldName[0] == 'p' && strcmp(fieldName, "peerTieTag") == 0) return base+4;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpCookieDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::simtime_t",    // FIELD_creationTime
        "uint32",    // FIELD_localTag
        "uint32",    // FIELD_peerTag
        "uint8",    // FIELD_localTieTag
        "uint8",    // FIELD_peerTieTag
        "uint32",    // FIELD_length
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpCookieDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpCookieDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpCookieDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpCookie *pp = (SctpCookie *)object; (void)pp;
    switch (field) {
        case FIELD_localTieTag: return pp->getLocalTieTagArraySize();
        case FIELD_peerTieTag: return pp->getPeerTieTagArraySize();
        default: return 0;
    }
}

const char *SctpCookieDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpCookie *pp = (SctpCookie *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpCookieDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpCookie *pp = (SctpCookie *)object; (void)pp;
    switch (field) {
        case FIELD_creationTime: return simtime2string(pp->getCreationTime());
        case FIELD_localTag: return ulong2string(pp->getLocalTag());
        case FIELD_peerTag: return ulong2string(pp->getPeerTag());
        case FIELD_localTieTag: return ulong2string(pp->getLocalTieTag(i));
        case FIELD_peerTieTag: return ulong2string(pp->getPeerTieTag(i));
        case FIELD_length: return ulong2string(pp->getLength());
        default: return "";
    }
}

bool SctpCookieDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpCookie *pp = (SctpCookie *)object; (void)pp;
    switch (field) {
        case FIELD_localTag: pp->setLocalTag(string2ulong(value)); return true;
        case FIELD_peerTag: pp->setPeerTag(string2ulong(value)); return true;
        case FIELD_localTieTag: pp->setLocalTieTag(i,string2ulong(value)); return true;
        case FIELD_peerTieTag: pp->setPeerTieTag(i,string2ulong(value)); return true;
        case FIELD_length: pp->setLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpCookieDescriptor::getFieldStructName(int field) const
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

void *SctpCookieDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpCookie *pp = (SctpCookie *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpCookieAckChunk)

SctpCookieAckChunk::SctpCookieAckChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpCookieAckChunk::SctpCookieAckChunk(const SctpCookieAckChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpCookieAckChunk::~SctpCookieAckChunk()
{
}

SctpCookieAckChunk& SctpCookieAckChunk::operator=(const SctpCookieAckChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpCookieAckChunk::copy(const SctpCookieAckChunk& other)
{
}

void SctpCookieAckChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
}

void SctpCookieAckChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
}

class SctpCookieAckChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    SctpCookieAckChunkDescriptor();
    virtual ~SctpCookieAckChunkDescriptor();

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

Register_ClassDescriptor(SctpCookieAckChunkDescriptor)

SctpCookieAckChunkDescriptor::SctpCookieAckChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpCookieAckChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpCookieAckChunkDescriptor::~SctpCookieAckChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpCookieAckChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpCookieAckChunk *>(obj)!=nullptr;
}

const char **SctpCookieAckChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpCookieAckChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpCookieAckChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int SctpCookieAckChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *SctpCookieAckChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int SctpCookieAckChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpCookieAckChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **SctpCookieAckChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpCookieAckChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpCookieAckChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpCookieAckChunk *pp = (SctpCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpCookieAckChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpCookieAckChunk *pp = (SctpCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpCookieAckChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpCookieAckChunk *pp = (SctpCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SctpCookieAckChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpCookieAckChunk *pp = (SctpCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SctpCookieAckChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *SctpCookieAckChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpCookieAckChunk *pp = (SctpCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpDataMsg)

SctpDataMsg::SctpDataMsg(const char *name) : ::omnetpp::cPacket(name)
{
}

SctpDataMsg::SctpDataMsg(const SctpDataMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SctpDataMsg::~SctpDataMsg()
{
}

SctpDataMsg& SctpDataMsg::operator=(const SctpDataMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SctpDataMsg::copy(const SctpDataMsg& other)
{
    this->eBit = other.eBit;
    this->bBit = other.bBit;
    this->enqueuingTime = other.enqueuingTime;
    this->expiryTime = other.expiryTime;
    this->ppid = other.ppid;
    this->initialDestination = other.initialDestination;
    this->msgNum = other.msgNum;
    this->sid = other.sid;
    this->ordered = other.ordered;
    this->booksize = other.booksize;
    this->rtx = other.rtx;
    this->fragment = other.fragment;
    this->prMethod = other.prMethod;
    this->priority = other.priority;
    this->strReset = other.strReset;
    this->sackNow = other.sackNow;
}

void SctpDataMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->eBit);
    doParsimPacking(b,this->bBit);
    doParsimPacking(b,this->enqueuingTime);
    doParsimPacking(b,this->expiryTime);
    doParsimPacking(b,this->ppid);
    doParsimPacking(b,this->initialDestination);
    doParsimPacking(b,this->msgNum);
    doParsimPacking(b,this->sid);
    doParsimPacking(b,this->ordered);
    doParsimPacking(b,this->booksize);
    doParsimPacking(b,this->rtx);
    doParsimPacking(b,this->fragment);
    doParsimPacking(b,this->prMethod);
    doParsimPacking(b,this->priority);
    doParsimPacking(b,this->strReset);
    doParsimPacking(b,this->sackNow);
}

void SctpDataMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->eBit);
    doParsimUnpacking(b,this->bBit);
    doParsimUnpacking(b,this->enqueuingTime);
    doParsimUnpacking(b,this->expiryTime);
    doParsimUnpacking(b,this->ppid);
    doParsimUnpacking(b,this->initialDestination);
    doParsimUnpacking(b,this->msgNum);
    doParsimUnpacking(b,this->sid);
    doParsimUnpacking(b,this->ordered);
    doParsimUnpacking(b,this->booksize);
    doParsimUnpacking(b,this->rtx);
    doParsimUnpacking(b,this->fragment);
    doParsimUnpacking(b,this->prMethod);
    doParsimUnpacking(b,this->priority);
    doParsimUnpacking(b,this->strReset);
    doParsimUnpacking(b,this->sackNow);
}

bool SctpDataMsg::getEBit() const
{
    return this->eBit;
}

void SctpDataMsg::setEBit(bool eBit)
{
    this->eBit = eBit;
}

bool SctpDataMsg::getBBit() const
{
    return this->bBit;
}

void SctpDataMsg::setBBit(bool bBit)
{
    this->bBit = bBit;
}

omnetpp::simtime_t SctpDataMsg::getEnqueuingTime() const
{
    return this->enqueuingTime;
}

void SctpDataMsg::setEnqueuingTime(omnetpp::simtime_t enqueuingTime)
{
    this->enqueuingTime = enqueuingTime;
}

omnetpp::simtime_t SctpDataMsg::getExpiryTime() const
{
    return this->expiryTime;
}

void SctpDataMsg::setExpiryTime(omnetpp::simtime_t expiryTime)
{
    this->expiryTime = expiryTime;
}

uint32_t SctpDataMsg::getPpid() const
{
    return this->ppid;
}

void SctpDataMsg::setPpid(uint32_t ppid)
{
    this->ppid = ppid;
}

const L3Address& SctpDataMsg::getInitialDestination() const
{
    return this->initialDestination;
}

void SctpDataMsg::setInitialDestination(const L3Address& initialDestination)
{
    this->initialDestination = initialDestination;
}

uint32_t SctpDataMsg::getMsgNum() const
{
    return this->msgNum;
}

void SctpDataMsg::setMsgNum(uint32_t msgNum)
{
    this->msgNum = msgNum;
}

uint16_t SctpDataMsg::getSid() const
{
    return this->sid;
}

void SctpDataMsg::setSid(uint16_t sid)
{
    this->sid = sid;
}

bool SctpDataMsg::getOrdered() const
{
    return this->ordered;
}

void SctpDataMsg::setOrdered(bool ordered)
{
    this->ordered = ordered;
}

uint32_t SctpDataMsg::getBooksize() const
{
    return this->booksize;
}

void SctpDataMsg::setBooksize(uint32_t booksize)
{
    this->booksize = booksize;
}

uint32_t SctpDataMsg::getRtx() const
{
    return this->rtx;
}

void SctpDataMsg::setRtx(uint32_t rtx)
{
    this->rtx = rtx;
}

bool SctpDataMsg::getFragment() const
{
    return this->fragment;
}

void SctpDataMsg::setFragment(bool fragment)
{
    this->fragment = fragment;
}

uint32_t SctpDataMsg::getPrMethod() const
{
    return this->prMethod;
}

void SctpDataMsg::setPrMethod(uint32_t prMethod)
{
    this->prMethod = prMethod;
}

uint32_t SctpDataMsg::getPriority() const
{
    return this->priority;
}

void SctpDataMsg::setPriority(uint32_t priority)
{
    this->priority = priority;
}

bool SctpDataMsg::getStrReset() const
{
    return this->strReset;
}

void SctpDataMsg::setStrReset(bool strReset)
{
    this->strReset = strReset;
}

bool SctpDataMsg::getSackNow() const
{
    return this->sackNow;
}

void SctpDataMsg::setSackNow(bool sackNow)
{
    this->sackNow = sackNow;
}

class SctpDataMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_eBit,
        FIELD_bBit,
        FIELD_enqueuingTime,
        FIELD_expiryTime,
        FIELD_ppid,
        FIELD_initialDestination,
        FIELD_msgNum,
        FIELD_sid,
        FIELD_ordered,
        FIELD_booksize,
        FIELD_rtx,
        FIELD_fragment,
        FIELD_prMethod,
        FIELD_priority,
        FIELD_strReset,
        FIELD_sackNow,
    };
  public:
    SctpDataMsgDescriptor();
    virtual ~SctpDataMsgDescriptor();

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

Register_ClassDescriptor(SctpDataMsgDescriptor)

SctpDataMsgDescriptor::SctpDataMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpDataMsg)), "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SctpDataMsgDescriptor::~SctpDataMsgDescriptor()
{
    delete[] propertynames;
}

bool SctpDataMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpDataMsg *>(obj)!=nullptr;
}

const char **SctpDataMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpDataMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpDataMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 16+basedesc->getFieldCount() : 16;
}

unsigned int SctpDataMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_eBit
        FD_ISEDITABLE,    // FIELD_bBit
        0,    // FIELD_enqueuingTime
        0,    // FIELD_expiryTime
        FD_ISEDITABLE,    // FIELD_ppid
        0,    // FIELD_initialDestination
        FD_ISEDITABLE,    // FIELD_msgNum
        FD_ISEDITABLE,    // FIELD_sid
        FD_ISEDITABLE,    // FIELD_ordered
        FD_ISEDITABLE,    // FIELD_booksize
        FD_ISEDITABLE,    // FIELD_rtx
        FD_ISEDITABLE,    // FIELD_fragment
        FD_ISEDITABLE,    // FIELD_prMethod
        FD_ISEDITABLE,    // FIELD_priority
        FD_ISEDITABLE,    // FIELD_strReset
        FD_ISEDITABLE,    // FIELD_sackNow
    };
    return (field >= 0 && field < 16) ? fieldTypeFlags[field] : 0;
}

const char *SctpDataMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "eBit",
        "bBit",
        "enqueuingTime",
        "expiryTime",
        "ppid",
        "initialDestination",
        "msgNum",
        "sid",
        "ordered",
        "booksize",
        "rtx",
        "fragment",
        "prMethod",
        "priority",
        "strReset",
        "sackNow",
    };
    return (field >= 0 && field < 16) ? fieldNames[field] : nullptr;
}

int SctpDataMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'e' && strcmp(fieldName, "eBit") == 0) return base+0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bBit") == 0) return base+1;
    if (fieldName[0] == 'e' && strcmp(fieldName, "enqueuingTime") == 0) return base+2;
    if (fieldName[0] == 'e' && strcmp(fieldName, "expiryTime") == 0) return base+3;
    if (fieldName[0] == 'p' && strcmp(fieldName, "ppid") == 0) return base+4;
    if (fieldName[0] == 'i' && strcmp(fieldName, "initialDestination") == 0) return base+5;
    if (fieldName[0] == 'm' && strcmp(fieldName, "msgNum") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "sid") == 0) return base+7;
    if (fieldName[0] == 'o' && strcmp(fieldName, "ordered") == 0) return base+8;
    if (fieldName[0] == 'b' && strcmp(fieldName, "booksize") == 0) return base+9;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rtx") == 0) return base+10;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fragment") == 0) return base+11;
    if (fieldName[0] == 'p' && strcmp(fieldName, "prMethod") == 0) return base+12;
    if (fieldName[0] == 'p' && strcmp(fieldName, "priority") == 0) return base+13;
    if (fieldName[0] == 's' && strcmp(fieldName, "strReset") == 0) return base+14;
    if (fieldName[0] == 's' && strcmp(fieldName, "sackNow") == 0) return base+15;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpDataMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_eBit
        "bool",    // FIELD_bBit
        "omnetpp::simtime_t",    // FIELD_enqueuingTime
        "omnetpp::simtime_t",    // FIELD_expiryTime
        "uint32",    // FIELD_ppid
        "inet::L3Address",    // FIELD_initialDestination
        "uint32",    // FIELD_msgNum
        "uint16",    // FIELD_sid
        "bool",    // FIELD_ordered
        "uint32",    // FIELD_booksize
        "uint32",    // FIELD_rtx
        "bool",    // FIELD_fragment
        "uint32",    // FIELD_prMethod
        "uint32",    // FIELD_priority
        "bool",    // FIELD_strReset
        "bool",    // FIELD_sackNow
    };
    return (field >= 0 && field < 16) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpDataMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpDataMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpDataMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpDataMsg *pp = (SctpDataMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpDataMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpDataMsg *pp = (SctpDataMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpDataMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpDataMsg *pp = (SctpDataMsg *)object; (void)pp;
    switch (field) {
        case FIELD_eBit: return bool2string(pp->getEBit());
        case FIELD_bBit: return bool2string(pp->getBBit());
        case FIELD_enqueuingTime: return simtime2string(pp->getEnqueuingTime());
        case FIELD_expiryTime: return simtime2string(pp->getExpiryTime());
        case FIELD_ppid: return ulong2string(pp->getPpid());
        case FIELD_initialDestination: return pp->getInitialDestination().str();
        case FIELD_msgNum: return ulong2string(pp->getMsgNum());
        case FIELD_sid: return ulong2string(pp->getSid());
        case FIELD_ordered: return bool2string(pp->getOrdered());
        case FIELD_booksize: return ulong2string(pp->getBooksize());
        case FIELD_rtx: return ulong2string(pp->getRtx());
        case FIELD_fragment: return bool2string(pp->getFragment());
        case FIELD_prMethod: return ulong2string(pp->getPrMethod());
        case FIELD_priority: return ulong2string(pp->getPriority());
        case FIELD_strReset: return bool2string(pp->getStrReset());
        case FIELD_sackNow: return bool2string(pp->getSackNow());
        default: return "";
    }
}

bool SctpDataMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpDataMsg *pp = (SctpDataMsg *)object; (void)pp;
    switch (field) {
        case FIELD_eBit: pp->setEBit(string2bool(value)); return true;
        case FIELD_bBit: pp->setBBit(string2bool(value)); return true;
        case FIELD_ppid: pp->setPpid(string2ulong(value)); return true;
        case FIELD_msgNum: pp->setMsgNum(string2ulong(value)); return true;
        case FIELD_sid: pp->setSid(string2ulong(value)); return true;
        case FIELD_ordered: pp->setOrdered(string2bool(value)); return true;
        case FIELD_booksize: pp->setBooksize(string2ulong(value)); return true;
        case FIELD_rtx: pp->setRtx(string2ulong(value)); return true;
        case FIELD_fragment: pp->setFragment(string2bool(value)); return true;
        case FIELD_prMethod: pp->setPrMethod(string2ulong(value)); return true;
        case FIELD_priority: pp->setPriority(string2ulong(value)); return true;
        case FIELD_strReset: pp->setStrReset(string2bool(value)); return true;
        case FIELD_sackNow: pp->setSackNow(string2bool(value)); return true;
        default: return false;
    }
}

const char *SctpDataMsgDescriptor::getFieldStructName(int field) const
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

void *SctpDataMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpDataMsg *pp = (SctpDataMsg *)object; (void)pp;
    switch (field) {
        case FIELD_initialDestination: return toVoidPtr(&pp->getInitialDestination()); break;
        default: return nullptr;
    }
}

Register_Class(SctpDataChunk)

SctpDataChunk::SctpDataChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpDataChunk::SctpDataChunk(const SctpDataChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpDataChunk::~SctpDataChunk()
{
}

SctpDataChunk& SctpDataChunk::operator=(const SctpDataChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpDataChunk::copy(const SctpDataChunk& other)
{
    this->eBit = other.eBit;
    this->bBit = other.bBit;
    this->uBit = other.uBit;
    this->iBit = other.iBit;
    this->tsn = other.tsn;
    this->sid = other.sid;
    this->ssn = other.ssn;
    this->ppid = other.ppid;
    this->enqueuingTime = other.enqueuingTime;
    this->firstSendTime = other.firstSendTime;
}

void SctpDataChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->eBit);
    doParsimPacking(b,this->bBit);
    doParsimPacking(b,this->uBit);
    doParsimPacking(b,this->iBit);
    doParsimPacking(b,this->tsn);
    doParsimPacking(b,this->sid);
    doParsimPacking(b,this->ssn);
    doParsimPacking(b,this->ppid);
    doParsimPacking(b,this->enqueuingTime);
    doParsimPacking(b,this->firstSendTime);
}

void SctpDataChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->eBit);
    doParsimUnpacking(b,this->bBit);
    doParsimUnpacking(b,this->uBit);
    doParsimUnpacking(b,this->iBit);
    doParsimUnpacking(b,this->tsn);
    doParsimUnpacking(b,this->sid);
    doParsimUnpacking(b,this->ssn);
    doParsimUnpacking(b,this->ppid);
    doParsimUnpacking(b,this->enqueuingTime);
    doParsimUnpacking(b,this->firstSendTime);
}

bool SctpDataChunk::getEBit() const
{
    return this->eBit;
}

void SctpDataChunk::setEBit(bool eBit)
{
    this->eBit = eBit;
}

bool SctpDataChunk::getBBit() const
{
    return this->bBit;
}

void SctpDataChunk::setBBit(bool bBit)
{
    this->bBit = bBit;
}

bool SctpDataChunk::getUBit() const
{
    return this->uBit;
}

void SctpDataChunk::setUBit(bool uBit)
{
    this->uBit = uBit;
}

bool SctpDataChunk::getIBit() const
{
    return this->iBit;
}

void SctpDataChunk::setIBit(bool iBit)
{
    this->iBit = iBit;
}

uint32_t SctpDataChunk::getTsn() const
{
    return this->tsn;
}

void SctpDataChunk::setTsn(uint32_t tsn)
{
    this->tsn = tsn;
}

uint16_t SctpDataChunk::getSid() const
{
    return this->sid;
}

void SctpDataChunk::setSid(uint16_t sid)
{
    this->sid = sid;
}

uint16_t SctpDataChunk::getSsn() const
{
    return this->ssn;
}

void SctpDataChunk::setSsn(uint16_t ssn)
{
    this->ssn = ssn;
}

uint32_t SctpDataChunk::getPpid() const
{
    return this->ppid;
}

void SctpDataChunk::setPpid(uint32_t ppid)
{
    this->ppid = ppid;
}

omnetpp::simtime_t SctpDataChunk::getEnqueuingTime() const
{
    return this->enqueuingTime;
}

void SctpDataChunk::setEnqueuingTime(omnetpp::simtime_t enqueuingTime)
{
    this->enqueuingTime = enqueuingTime;
}

omnetpp::simtime_t SctpDataChunk::getFirstSendTime() const
{
    return this->firstSendTime;
}

void SctpDataChunk::setFirstSendTime(omnetpp::simtime_t firstSendTime)
{
    this->firstSendTime = firstSendTime;
}

class SctpDataChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_eBit,
        FIELD_bBit,
        FIELD_uBit,
        FIELD_iBit,
        FIELD_tsn,
        FIELD_sid,
        FIELD_ssn,
        FIELD_ppid,
        FIELD_enqueuingTime,
        FIELD_firstSendTime,
    };
  public:
    SctpDataChunkDescriptor();
    virtual ~SctpDataChunkDescriptor();

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

Register_ClassDescriptor(SctpDataChunkDescriptor)

SctpDataChunkDescriptor::SctpDataChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpDataChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpDataChunkDescriptor::~SctpDataChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpDataChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpDataChunk *>(obj)!=nullptr;
}

const char **SctpDataChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpDataChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpDataChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int SctpDataChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_eBit
        FD_ISEDITABLE,    // FIELD_bBit
        FD_ISEDITABLE,    // FIELD_uBit
        FD_ISEDITABLE,    // FIELD_iBit
        FD_ISEDITABLE,    // FIELD_tsn
        FD_ISEDITABLE,    // FIELD_sid
        FD_ISEDITABLE,    // FIELD_ssn
        FD_ISEDITABLE,    // FIELD_ppid
        0,    // FIELD_enqueuingTime
        0,    // FIELD_firstSendTime
    };
    return (field >= 0 && field < 10) ? fieldTypeFlags[field] : 0;
}

const char *SctpDataChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "eBit",
        "bBit",
        "uBit",
        "iBit",
        "tsn",
        "sid",
        "ssn",
        "ppid",
        "enqueuingTime",
        "firstSendTime",
    };
    return (field >= 0 && field < 10) ? fieldNames[field] : nullptr;
}

int SctpDataChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'e' && strcmp(fieldName, "eBit") == 0) return base+0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bBit") == 0) return base+1;
    if (fieldName[0] == 'u' && strcmp(fieldName, "uBit") == 0) return base+2;
    if (fieldName[0] == 'i' && strcmp(fieldName, "iBit") == 0) return base+3;
    if (fieldName[0] == 't' && strcmp(fieldName, "tsn") == 0) return base+4;
    if (fieldName[0] == 's' && strcmp(fieldName, "sid") == 0) return base+5;
    if (fieldName[0] == 's' && strcmp(fieldName, "ssn") == 0) return base+6;
    if (fieldName[0] == 'p' && strcmp(fieldName, "ppid") == 0) return base+7;
    if (fieldName[0] == 'e' && strcmp(fieldName, "enqueuingTime") == 0) return base+8;
    if (fieldName[0] == 'f' && strcmp(fieldName, "firstSendTime") == 0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpDataChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_eBit
        "bool",    // FIELD_bBit
        "bool",    // FIELD_uBit
        "bool",    // FIELD_iBit
        "uint32",    // FIELD_tsn
        "uint16",    // FIELD_sid
        "uint16",    // FIELD_ssn
        "uint32",    // FIELD_ppid
        "omnetpp::simtime_t",    // FIELD_enqueuingTime
        "omnetpp::simtime_t",    // FIELD_firstSendTime
    };
    return (field >= 0 && field < 10) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpDataChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpDataChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpDataChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpDataChunk *pp = (SctpDataChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpDataChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpDataChunk *pp = (SctpDataChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpDataChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpDataChunk *pp = (SctpDataChunk *)object; (void)pp;
    switch (field) {
        case FIELD_eBit: return bool2string(pp->getEBit());
        case FIELD_bBit: return bool2string(pp->getBBit());
        case FIELD_uBit: return bool2string(pp->getUBit());
        case FIELD_iBit: return bool2string(pp->getIBit());
        case FIELD_tsn: return ulong2string(pp->getTsn());
        case FIELD_sid: return ulong2string(pp->getSid());
        case FIELD_ssn: return ulong2string(pp->getSsn());
        case FIELD_ppid: return ulong2string(pp->getPpid());
        case FIELD_enqueuingTime: return simtime2string(pp->getEnqueuingTime());
        case FIELD_firstSendTime: return simtime2string(pp->getFirstSendTime());
        default: return "";
    }
}

bool SctpDataChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpDataChunk *pp = (SctpDataChunk *)object; (void)pp;
    switch (field) {
        case FIELD_eBit: pp->setEBit(string2bool(value)); return true;
        case FIELD_bBit: pp->setBBit(string2bool(value)); return true;
        case FIELD_uBit: pp->setUBit(string2bool(value)); return true;
        case FIELD_iBit: pp->setIBit(string2bool(value)); return true;
        case FIELD_tsn: pp->setTsn(string2ulong(value)); return true;
        case FIELD_sid: pp->setSid(string2ulong(value)); return true;
        case FIELD_ssn: pp->setSsn(string2ulong(value)); return true;
        case FIELD_ppid: pp->setPpid(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpDataChunkDescriptor::getFieldStructName(int field) const
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

void *SctpDataChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpDataChunk *pp = (SctpDataChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpForwardTsnChunk)

SctpForwardTsnChunk::SctpForwardTsnChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpForwardTsnChunk::SctpForwardTsnChunk(const SctpForwardTsnChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpForwardTsnChunk::~SctpForwardTsnChunk()
{
    delete [] this->sid;
    delete [] this->ssn;
}

SctpForwardTsnChunk& SctpForwardTsnChunk::operator=(const SctpForwardTsnChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpForwardTsnChunk::copy(const SctpForwardTsnChunk& other)
{
    this->newCumTsn = other.newCumTsn;
    delete [] this->sid;
    this->sid = (other.sid_arraysize==0) ? nullptr : new uint16_t[other.sid_arraysize];
    sid_arraysize = other.sid_arraysize;
    for (size_t i = 0; i < sid_arraysize; i++) {
        this->sid[i] = other.sid[i];
    }
    delete [] this->ssn;
    this->ssn = (other.ssn_arraysize==0) ? nullptr : new short[other.ssn_arraysize];
    ssn_arraysize = other.ssn_arraysize;
    for (size_t i = 0; i < ssn_arraysize; i++) {
        this->ssn[i] = other.ssn[i];
    }
}

void SctpForwardTsnChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->newCumTsn);
    b->pack(sid_arraysize);
    doParsimArrayPacking(b,this->sid,sid_arraysize);
    b->pack(ssn_arraysize);
    doParsimArrayPacking(b,this->ssn,ssn_arraysize);
}

void SctpForwardTsnChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->newCumTsn);
    delete [] this->sid;
    b->unpack(sid_arraysize);
    if (sid_arraysize == 0) {
        this->sid = nullptr;
    } else {
        this->sid = new uint16_t[sid_arraysize];
        doParsimArrayUnpacking(b,this->sid,sid_arraysize);
    }
    delete [] this->ssn;
    b->unpack(ssn_arraysize);
    if (ssn_arraysize == 0) {
        this->ssn = nullptr;
    } else {
        this->ssn = new short[ssn_arraysize];
        doParsimArrayUnpacking(b,this->ssn,ssn_arraysize);
    }
}

uint32_t SctpForwardTsnChunk::getNewCumTsn() const
{
    return this->newCumTsn;
}

void SctpForwardTsnChunk::setNewCumTsn(uint32_t newCumTsn)
{
    this->newCumTsn = newCumTsn;
}

size_t SctpForwardTsnChunk::getSidArraySize() const
{
    return sid_arraysize;
}

uint16_t SctpForwardTsnChunk::getSid(size_t k) const
{
    if (k >= sid_arraysize) throw omnetpp::cRuntimeError("Array of size sid_arraysize indexed by %lu", (unsigned long)k);
    return this->sid[k];
}

void SctpForwardTsnChunk::setSidArraySize(size_t newSize)
{
    uint16_t *sid2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = sid_arraysize < newSize ? sid_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sid2[i] = this->sid[i];
    for (size_t i = minSize; i < newSize; i++)
        sid2[i] = 0;
    delete [] this->sid;
    this->sid = sid2;
    sid_arraysize = newSize;
}

void SctpForwardTsnChunk::setSid(size_t k, uint16_t sid)
{
    if (k >= sid_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->sid[k] = sid;
}

void SctpForwardTsnChunk::insertSid(size_t k, uint16_t sid)
{
    if (k > sid_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sid_arraysize + 1;
    uint16_t *sid2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sid2[i] = this->sid[i];
    sid2[k] = sid;
    for (i = k + 1; i < newSize; i++)
        sid2[i] = this->sid[i-1];
    delete [] this->sid;
    this->sid = sid2;
    sid_arraysize = newSize;
}

void SctpForwardTsnChunk::insertSid(uint16_t sid)
{
    insertSid(sid_arraysize, sid);
}

void SctpForwardTsnChunk::eraseSid(size_t k)
{
    if (k >= sid_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sid_arraysize - 1;
    uint16_t *sid2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sid2[i] = this->sid[i];
    for (i = k; i < newSize; i++)
        sid2[i] = this->sid[i+1];
    delete [] this->sid;
    this->sid = sid2;
    sid_arraysize = newSize;
}

size_t SctpForwardTsnChunk::getSsnArraySize() const
{
    return ssn_arraysize;
}

short SctpForwardTsnChunk::getSsn(size_t k) const
{
    if (k >= ssn_arraysize) throw omnetpp::cRuntimeError("Array of size ssn_arraysize indexed by %lu", (unsigned long)k);
    return this->ssn[k];
}

void SctpForwardTsnChunk::setSsnArraySize(size_t newSize)
{
    short *ssn2 = (newSize==0) ? nullptr : new short[newSize];
    size_t minSize = ssn_arraysize < newSize ? ssn_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        ssn2[i] = this->ssn[i];
    for (size_t i = minSize; i < newSize; i++)
        ssn2[i] = 0;
    delete [] this->ssn;
    this->ssn = ssn2;
    ssn_arraysize = newSize;
}

void SctpForwardTsnChunk::setSsn(size_t k, short ssn)
{
    if (k >= ssn_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->ssn[k] = ssn;
}

void SctpForwardTsnChunk::insertSsn(size_t k, short ssn)
{
    if (k > ssn_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = ssn_arraysize + 1;
    short *ssn2 = new short[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        ssn2[i] = this->ssn[i];
    ssn2[k] = ssn;
    for (i = k + 1; i < newSize; i++)
        ssn2[i] = this->ssn[i-1];
    delete [] this->ssn;
    this->ssn = ssn2;
    ssn_arraysize = newSize;
}

void SctpForwardTsnChunk::insertSsn(short ssn)
{
    insertSsn(ssn_arraysize, ssn);
}

void SctpForwardTsnChunk::eraseSsn(size_t k)
{
    if (k >= ssn_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = ssn_arraysize - 1;
    short *ssn2 = (newSize == 0) ? nullptr : new short[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        ssn2[i] = this->ssn[i];
    for (i = k; i < newSize; i++)
        ssn2[i] = this->ssn[i+1];
    delete [] this->ssn;
    this->ssn = ssn2;
    ssn_arraysize = newSize;
}

class SctpForwardTsnChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_newCumTsn,
        FIELD_sid,
        FIELD_ssn,
    };
  public:
    SctpForwardTsnChunkDescriptor();
    virtual ~SctpForwardTsnChunkDescriptor();

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

Register_ClassDescriptor(SctpForwardTsnChunkDescriptor)

SctpForwardTsnChunkDescriptor::SctpForwardTsnChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpForwardTsnChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpForwardTsnChunkDescriptor::~SctpForwardTsnChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpForwardTsnChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpForwardTsnChunk *>(obj)!=nullptr;
}

const char **SctpForwardTsnChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpForwardTsnChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpForwardTsnChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SctpForwardTsnChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_newCumTsn
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_sid
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_ssn
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SctpForwardTsnChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "newCumTsn",
        "sid",
        "ssn",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SctpForwardTsnChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "newCumTsn") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sid") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "ssn") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpForwardTsnChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_newCumTsn
        "uint16",    // FIELD_sid
        "short",    // FIELD_ssn
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpForwardTsnChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpForwardTsnChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpForwardTsnChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpForwardTsnChunk *pp = (SctpForwardTsnChunk *)object; (void)pp;
    switch (field) {
        case FIELD_sid: return pp->getSidArraySize();
        case FIELD_ssn: return pp->getSsnArraySize();
        default: return 0;
    }
}

const char *SctpForwardTsnChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpForwardTsnChunk *pp = (SctpForwardTsnChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpForwardTsnChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpForwardTsnChunk *pp = (SctpForwardTsnChunk *)object; (void)pp;
    switch (field) {
        case FIELD_newCumTsn: return ulong2string(pp->getNewCumTsn());
        case FIELD_sid: return ulong2string(pp->getSid(i));
        case FIELD_ssn: return long2string(pp->getSsn(i));
        default: return "";
    }
}

bool SctpForwardTsnChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpForwardTsnChunk *pp = (SctpForwardTsnChunk *)object; (void)pp;
    switch (field) {
        case FIELD_newCumTsn: pp->setNewCumTsn(string2ulong(value)); return true;
        case FIELD_sid: pp->setSid(i,string2ulong(value)); return true;
        case FIELD_ssn: pp->setSsn(i,string2long(value)); return true;
        default: return false;
    }
}

const char *SctpForwardTsnChunkDescriptor::getFieldStructName(int field) const
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

void *SctpForwardTsnChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpForwardTsnChunk *pp = (SctpForwardTsnChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpSackChunk)

SctpSackChunk::SctpSackChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpSackChunk::SctpSackChunk(const SctpSackChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpSackChunk::~SctpSackChunk()
{
    delete [] this->gapStart;
    delete [] this->gapStop;
    delete [] this->dupTsns;
    delete [] this->nrGapStart;
    delete [] this->nrGapStop;
}

SctpSackChunk& SctpSackChunk::operator=(const SctpSackChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpSackChunk::copy(const SctpSackChunk& other)
{
    this->cumTsnAck = other.cumTsnAck;
    this->a_rwnd = other.a_rwnd;
    this->numGaps = other.numGaps;
    this->numNrGaps = other.numNrGaps;
    this->numDupTsns = other.numDupTsns;
    this->isNrSack_ = other.isNrSack_;
    delete [] this->gapStart;
    this->gapStart = (other.gapStart_arraysize==0) ? nullptr : new uint32_t[other.gapStart_arraysize];
    gapStart_arraysize = other.gapStart_arraysize;
    for (size_t i = 0; i < gapStart_arraysize; i++) {
        this->gapStart[i] = other.gapStart[i];
    }
    delete [] this->gapStop;
    this->gapStop = (other.gapStop_arraysize==0) ? nullptr : new uint32_t[other.gapStop_arraysize];
    gapStop_arraysize = other.gapStop_arraysize;
    for (size_t i = 0; i < gapStop_arraysize; i++) {
        this->gapStop[i] = other.gapStop[i];
    }
    delete [] this->dupTsns;
    this->dupTsns = (other.dupTsns_arraysize==0) ? nullptr : new uint32_t[other.dupTsns_arraysize];
    dupTsns_arraysize = other.dupTsns_arraysize;
    for (size_t i = 0; i < dupTsns_arraysize; i++) {
        this->dupTsns[i] = other.dupTsns[i];
    }
    this->sackSeqNum = other.sackSeqNum;
    delete [] this->nrGapStart;
    this->nrGapStart = (other.nrGapStart_arraysize==0) ? nullptr : new uint32_t[other.nrGapStart_arraysize];
    nrGapStart_arraysize = other.nrGapStart_arraysize;
    for (size_t i = 0; i < nrGapStart_arraysize; i++) {
        this->nrGapStart[i] = other.nrGapStart[i];
    }
    delete [] this->nrGapStop;
    this->nrGapStop = (other.nrGapStop_arraysize==0) ? nullptr : new uint32_t[other.nrGapStop_arraysize];
    nrGapStop_arraysize = other.nrGapStop_arraysize;
    for (size_t i = 0; i < nrGapStop_arraysize; i++) {
        this->nrGapStop[i] = other.nrGapStop[i];
    }
    this->msg_rwnd = other.msg_rwnd;
    this->dacPacketsRcvd = other.dacPacketsRcvd;
    this->nrSubtractRGaps = other.nrSubtractRGaps;
}

void SctpSackChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->cumTsnAck);
    doParsimPacking(b,this->a_rwnd);
    doParsimPacking(b,this->numGaps);
    doParsimPacking(b,this->numNrGaps);
    doParsimPacking(b,this->numDupTsns);
    doParsimPacking(b,this->isNrSack_);
    b->pack(gapStart_arraysize);
    doParsimArrayPacking(b,this->gapStart,gapStart_arraysize);
    b->pack(gapStop_arraysize);
    doParsimArrayPacking(b,this->gapStop,gapStop_arraysize);
    b->pack(dupTsns_arraysize);
    doParsimArrayPacking(b,this->dupTsns,dupTsns_arraysize);
    doParsimPacking(b,this->sackSeqNum);
    b->pack(nrGapStart_arraysize);
    doParsimArrayPacking(b,this->nrGapStart,nrGapStart_arraysize);
    b->pack(nrGapStop_arraysize);
    doParsimArrayPacking(b,this->nrGapStop,nrGapStop_arraysize);
    doParsimPacking(b,this->msg_rwnd);
    doParsimPacking(b,this->dacPacketsRcvd);
    doParsimPacking(b,this->nrSubtractRGaps);
}

void SctpSackChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->cumTsnAck);
    doParsimUnpacking(b,this->a_rwnd);
    doParsimUnpacking(b,this->numGaps);
    doParsimUnpacking(b,this->numNrGaps);
    doParsimUnpacking(b,this->numDupTsns);
    doParsimUnpacking(b,this->isNrSack_);
    delete [] this->gapStart;
    b->unpack(gapStart_arraysize);
    if (gapStart_arraysize == 0) {
        this->gapStart = nullptr;
    } else {
        this->gapStart = new uint32_t[gapStart_arraysize];
        doParsimArrayUnpacking(b,this->gapStart,gapStart_arraysize);
    }
    delete [] this->gapStop;
    b->unpack(gapStop_arraysize);
    if (gapStop_arraysize == 0) {
        this->gapStop = nullptr;
    } else {
        this->gapStop = new uint32_t[gapStop_arraysize];
        doParsimArrayUnpacking(b,this->gapStop,gapStop_arraysize);
    }
    delete [] this->dupTsns;
    b->unpack(dupTsns_arraysize);
    if (dupTsns_arraysize == 0) {
        this->dupTsns = nullptr;
    } else {
        this->dupTsns = new uint32_t[dupTsns_arraysize];
        doParsimArrayUnpacking(b,this->dupTsns,dupTsns_arraysize);
    }
    doParsimUnpacking(b,this->sackSeqNum);
    delete [] this->nrGapStart;
    b->unpack(nrGapStart_arraysize);
    if (nrGapStart_arraysize == 0) {
        this->nrGapStart = nullptr;
    } else {
        this->nrGapStart = new uint32_t[nrGapStart_arraysize];
        doParsimArrayUnpacking(b,this->nrGapStart,nrGapStart_arraysize);
    }
    delete [] this->nrGapStop;
    b->unpack(nrGapStop_arraysize);
    if (nrGapStop_arraysize == 0) {
        this->nrGapStop = nullptr;
    } else {
        this->nrGapStop = new uint32_t[nrGapStop_arraysize];
        doParsimArrayUnpacking(b,this->nrGapStop,nrGapStop_arraysize);
    }
    doParsimUnpacking(b,this->msg_rwnd);
    doParsimUnpacking(b,this->dacPacketsRcvd);
    doParsimUnpacking(b,this->nrSubtractRGaps);
}

uint32_t SctpSackChunk::getCumTsnAck() const
{
    return this->cumTsnAck;
}

void SctpSackChunk::setCumTsnAck(uint32_t cumTsnAck)
{
    this->cumTsnAck = cumTsnAck;
}

uint32_t SctpSackChunk::getA_rwnd() const
{
    return this->a_rwnd;
}

void SctpSackChunk::setA_rwnd(uint32_t a_rwnd)
{
    this->a_rwnd = a_rwnd;
}

uint16_t SctpSackChunk::getNumGaps() const
{
    return this->numGaps;
}

void SctpSackChunk::setNumGaps(uint16_t numGaps)
{
    this->numGaps = numGaps;
}

uint16_t SctpSackChunk::getNumNrGaps() const
{
    return this->numNrGaps;
}

void SctpSackChunk::setNumNrGaps(uint16_t numNrGaps)
{
    this->numNrGaps = numNrGaps;
}

uint16_t SctpSackChunk::getNumDupTsns() const
{
    return this->numDupTsns;
}

void SctpSackChunk::setNumDupTsns(uint16_t numDupTsns)
{
    this->numDupTsns = numDupTsns;
}

bool SctpSackChunk::isNrSack() const
{
    return this->isNrSack_;
}

void SctpSackChunk::setIsNrSack(bool isNrSack)
{
    this->isNrSack_ = isNrSack;
}

size_t SctpSackChunk::getGapStartArraySize() const
{
    return gapStart_arraysize;
}

uint32_t SctpSackChunk::getGapStart(size_t k) const
{
    if (k >= gapStart_arraysize) throw omnetpp::cRuntimeError("Array of size gapStart_arraysize indexed by %lu", (unsigned long)k);
    return this->gapStart[k];
}

void SctpSackChunk::setGapStartArraySize(size_t newSize)
{
    uint32_t *gapStart2 = (newSize==0) ? nullptr : new uint32_t[newSize];
    size_t minSize = gapStart_arraysize < newSize ? gapStart_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        gapStart2[i] = this->gapStart[i];
    for (size_t i = minSize; i < newSize; i++)
        gapStart2[i] = 0;
    delete [] this->gapStart;
    this->gapStart = gapStart2;
    gapStart_arraysize = newSize;
}

void SctpSackChunk::setGapStart(size_t k, uint32_t gapStart)
{
    if (k >= gapStart_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->gapStart[k] = gapStart;
}

void SctpSackChunk::insertGapStart(size_t k, uint32_t gapStart)
{
    if (k > gapStart_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = gapStart_arraysize + 1;
    uint32_t *gapStart2 = new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        gapStart2[i] = this->gapStart[i];
    gapStart2[k] = gapStart;
    for (i = k + 1; i < newSize; i++)
        gapStart2[i] = this->gapStart[i-1];
    delete [] this->gapStart;
    this->gapStart = gapStart2;
    gapStart_arraysize = newSize;
}

void SctpSackChunk::insertGapStart(uint32_t gapStart)
{
    insertGapStart(gapStart_arraysize, gapStart);
}

void SctpSackChunk::eraseGapStart(size_t k)
{
    if (k >= gapStart_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = gapStart_arraysize - 1;
    uint32_t *gapStart2 = (newSize == 0) ? nullptr : new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        gapStart2[i] = this->gapStart[i];
    for (i = k; i < newSize; i++)
        gapStart2[i] = this->gapStart[i+1];
    delete [] this->gapStart;
    this->gapStart = gapStart2;
    gapStart_arraysize = newSize;
}

size_t SctpSackChunk::getGapStopArraySize() const
{
    return gapStop_arraysize;
}

uint32_t SctpSackChunk::getGapStop(size_t k) const
{
    if (k >= gapStop_arraysize) throw omnetpp::cRuntimeError("Array of size gapStop_arraysize indexed by %lu", (unsigned long)k);
    return this->gapStop[k];
}

void SctpSackChunk::setGapStopArraySize(size_t newSize)
{
    uint32_t *gapStop2 = (newSize==0) ? nullptr : new uint32_t[newSize];
    size_t minSize = gapStop_arraysize < newSize ? gapStop_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        gapStop2[i] = this->gapStop[i];
    for (size_t i = minSize; i < newSize; i++)
        gapStop2[i] = 0;
    delete [] this->gapStop;
    this->gapStop = gapStop2;
    gapStop_arraysize = newSize;
}

void SctpSackChunk::setGapStop(size_t k, uint32_t gapStop)
{
    if (k >= gapStop_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->gapStop[k] = gapStop;
}

void SctpSackChunk::insertGapStop(size_t k, uint32_t gapStop)
{
    if (k > gapStop_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = gapStop_arraysize + 1;
    uint32_t *gapStop2 = new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        gapStop2[i] = this->gapStop[i];
    gapStop2[k] = gapStop;
    for (i = k + 1; i < newSize; i++)
        gapStop2[i] = this->gapStop[i-1];
    delete [] this->gapStop;
    this->gapStop = gapStop2;
    gapStop_arraysize = newSize;
}

void SctpSackChunk::insertGapStop(uint32_t gapStop)
{
    insertGapStop(gapStop_arraysize, gapStop);
}

void SctpSackChunk::eraseGapStop(size_t k)
{
    if (k >= gapStop_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = gapStop_arraysize - 1;
    uint32_t *gapStop2 = (newSize == 0) ? nullptr : new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        gapStop2[i] = this->gapStop[i];
    for (i = k; i < newSize; i++)
        gapStop2[i] = this->gapStop[i+1];
    delete [] this->gapStop;
    this->gapStop = gapStop2;
    gapStop_arraysize = newSize;
}

size_t SctpSackChunk::getDupTsnsArraySize() const
{
    return dupTsns_arraysize;
}

uint32_t SctpSackChunk::getDupTsns(size_t k) const
{
    if (k >= dupTsns_arraysize) throw omnetpp::cRuntimeError("Array of size dupTsns_arraysize indexed by %lu", (unsigned long)k);
    return this->dupTsns[k];
}

void SctpSackChunk::setDupTsnsArraySize(size_t newSize)
{
    uint32_t *dupTsns2 = (newSize==0) ? nullptr : new uint32_t[newSize];
    size_t minSize = dupTsns_arraysize < newSize ? dupTsns_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        dupTsns2[i] = this->dupTsns[i];
    for (size_t i = minSize; i < newSize; i++)
        dupTsns2[i] = 0;
    delete [] this->dupTsns;
    this->dupTsns = dupTsns2;
    dupTsns_arraysize = newSize;
}

void SctpSackChunk::setDupTsns(size_t k, uint32_t dupTsns)
{
    if (k >= dupTsns_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->dupTsns[k] = dupTsns;
}

void SctpSackChunk::insertDupTsns(size_t k, uint32_t dupTsns)
{
    if (k > dupTsns_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = dupTsns_arraysize + 1;
    uint32_t *dupTsns2 = new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        dupTsns2[i] = this->dupTsns[i];
    dupTsns2[k] = dupTsns;
    for (i = k + 1; i < newSize; i++)
        dupTsns2[i] = this->dupTsns[i-1];
    delete [] this->dupTsns;
    this->dupTsns = dupTsns2;
    dupTsns_arraysize = newSize;
}

void SctpSackChunk::insertDupTsns(uint32_t dupTsns)
{
    insertDupTsns(dupTsns_arraysize, dupTsns);
}

void SctpSackChunk::eraseDupTsns(size_t k)
{
    if (k >= dupTsns_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = dupTsns_arraysize - 1;
    uint32_t *dupTsns2 = (newSize == 0) ? nullptr : new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        dupTsns2[i] = this->dupTsns[i];
    for (i = k; i < newSize; i++)
        dupTsns2[i] = this->dupTsns[i+1];
    delete [] this->dupTsns;
    this->dupTsns = dupTsns2;
    dupTsns_arraysize = newSize;
}

uint32_t SctpSackChunk::getSackSeqNum() const
{
    return this->sackSeqNum;
}

void SctpSackChunk::setSackSeqNum(uint32_t sackSeqNum)
{
    this->sackSeqNum = sackSeqNum;
}

size_t SctpSackChunk::getNrGapStartArraySize() const
{
    return nrGapStart_arraysize;
}

uint32_t SctpSackChunk::getNrGapStart(size_t k) const
{
    if (k >= nrGapStart_arraysize) throw omnetpp::cRuntimeError("Array of size nrGapStart_arraysize indexed by %lu", (unsigned long)k);
    return this->nrGapStart[k];
}

void SctpSackChunk::setNrGapStartArraySize(size_t newSize)
{
    uint32_t *nrGapStart2 = (newSize==0) ? nullptr : new uint32_t[newSize];
    size_t minSize = nrGapStart_arraysize < newSize ? nrGapStart_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        nrGapStart2[i] = this->nrGapStart[i];
    for (size_t i = minSize; i < newSize; i++)
        nrGapStart2[i] = 0;
    delete [] this->nrGapStart;
    this->nrGapStart = nrGapStart2;
    nrGapStart_arraysize = newSize;
}

void SctpSackChunk::setNrGapStart(size_t k, uint32_t nrGapStart)
{
    if (k >= nrGapStart_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->nrGapStart[k] = nrGapStart;
}

void SctpSackChunk::insertNrGapStart(size_t k, uint32_t nrGapStart)
{
    if (k > nrGapStart_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = nrGapStart_arraysize + 1;
    uint32_t *nrGapStart2 = new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        nrGapStart2[i] = this->nrGapStart[i];
    nrGapStart2[k] = nrGapStart;
    for (i = k + 1; i < newSize; i++)
        nrGapStart2[i] = this->nrGapStart[i-1];
    delete [] this->nrGapStart;
    this->nrGapStart = nrGapStart2;
    nrGapStart_arraysize = newSize;
}

void SctpSackChunk::insertNrGapStart(uint32_t nrGapStart)
{
    insertNrGapStart(nrGapStart_arraysize, nrGapStart);
}

void SctpSackChunk::eraseNrGapStart(size_t k)
{
    if (k >= nrGapStart_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = nrGapStart_arraysize - 1;
    uint32_t *nrGapStart2 = (newSize == 0) ? nullptr : new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        nrGapStart2[i] = this->nrGapStart[i];
    for (i = k; i < newSize; i++)
        nrGapStart2[i] = this->nrGapStart[i+1];
    delete [] this->nrGapStart;
    this->nrGapStart = nrGapStart2;
    nrGapStart_arraysize = newSize;
}

size_t SctpSackChunk::getNrGapStopArraySize() const
{
    return nrGapStop_arraysize;
}

uint32_t SctpSackChunk::getNrGapStop(size_t k) const
{
    if (k >= nrGapStop_arraysize) throw omnetpp::cRuntimeError("Array of size nrGapStop_arraysize indexed by %lu", (unsigned long)k);
    return this->nrGapStop[k];
}

void SctpSackChunk::setNrGapStopArraySize(size_t newSize)
{
    uint32_t *nrGapStop2 = (newSize==0) ? nullptr : new uint32_t[newSize];
    size_t minSize = nrGapStop_arraysize < newSize ? nrGapStop_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        nrGapStop2[i] = this->nrGapStop[i];
    for (size_t i = minSize; i < newSize; i++)
        nrGapStop2[i] = 0;
    delete [] this->nrGapStop;
    this->nrGapStop = nrGapStop2;
    nrGapStop_arraysize = newSize;
}

void SctpSackChunk::setNrGapStop(size_t k, uint32_t nrGapStop)
{
    if (k >= nrGapStop_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->nrGapStop[k] = nrGapStop;
}

void SctpSackChunk::insertNrGapStop(size_t k, uint32_t nrGapStop)
{
    if (k > nrGapStop_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = nrGapStop_arraysize + 1;
    uint32_t *nrGapStop2 = new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        nrGapStop2[i] = this->nrGapStop[i];
    nrGapStop2[k] = nrGapStop;
    for (i = k + 1; i < newSize; i++)
        nrGapStop2[i] = this->nrGapStop[i-1];
    delete [] this->nrGapStop;
    this->nrGapStop = nrGapStop2;
    nrGapStop_arraysize = newSize;
}

void SctpSackChunk::insertNrGapStop(uint32_t nrGapStop)
{
    insertNrGapStop(nrGapStop_arraysize, nrGapStop);
}

void SctpSackChunk::eraseNrGapStop(size_t k)
{
    if (k >= nrGapStop_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = nrGapStop_arraysize - 1;
    uint32_t *nrGapStop2 = (newSize == 0) ? nullptr : new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        nrGapStop2[i] = this->nrGapStop[i];
    for (i = k; i < newSize; i++)
        nrGapStop2[i] = this->nrGapStop[i+1];
    delete [] this->nrGapStop;
    this->nrGapStop = nrGapStop2;
    nrGapStop_arraysize = newSize;
}

uint32_t SctpSackChunk::getMsg_rwnd() const
{
    return this->msg_rwnd;
}

void SctpSackChunk::setMsg_rwnd(uint32_t msg_rwnd)
{
    this->msg_rwnd = msg_rwnd;
}

uint8_t SctpSackChunk::getDacPacketsRcvd() const
{
    return this->dacPacketsRcvd;
}

void SctpSackChunk::setDacPacketsRcvd(uint8_t dacPacketsRcvd)
{
    this->dacPacketsRcvd = dacPacketsRcvd;
}

bool SctpSackChunk::getNrSubtractRGaps() const
{
    return this->nrSubtractRGaps;
}

void SctpSackChunk::setNrSubtractRGaps(bool nrSubtractRGaps)
{
    this->nrSubtractRGaps = nrSubtractRGaps;
}

class SctpSackChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_cumTsnAck,
        FIELD_a_rwnd,
        FIELD_numGaps,
        FIELD_numNrGaps,
        FIELD_numDupTsns,
        FIELD_isNrSack,
        FIELD_gapStart,
        FIELD_gapStop,
        FIELD_dupTsns,
        FIELD_sackSeqNum,
        FIELD_nrGapStart,
        FIELD_nrGapStop,
        FIELD_msg_rwnd,
        FIELD_dacPacketsRcvd,
        FIELD_nrSubtractRGaps,
    };
  public:
    SctpSackChunkDescriptor();
    virtual ~SctpSackChunkDescriptor();

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

Register_ClassDescriptor(SctpSackChunkDescriptor)

SctpSackChunkDescriptor::SctpSackChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpSackChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpSackChunkDescriptor::~SctpSackChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpSackChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpSackChunk *>(obj)!=nullptr;
}

const char **SctpSackChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpSackChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpSackChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount() : 15;
}

unsigned int SctpSackChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_cumTsnAck
        FD_ISEDITABLE,    // FIELD_a_rwnd
        FD_ISEDITABLE,    // FIELD_numGaps
        FD_ISEDITABLE,    // FIELD_numNrGaps
        FD_ISEDITABLE,    // FIELD_numDupTsns
        FD_ISEDITABLE,    // FIELD_isNrSack
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_gapStart
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_gapStop
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_dupTsns
        FD_ISEDITABLE,    // FIELD_sackSeqNum
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_nrGapStart
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_nrGapStop
        FD_ISEDITABLE,    // FIELD_msg_rwnd
        FD_ISEDITABLE,    // FIELD_dacPacketsRcvd
        FD_ISEDITABLE,    // FIELD_nrSubtractRGaps
    };
    return (field >= 0 && field < 15) ? fieldTypeFlags[field] : 0;
}

const char *SctpSackChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "cumTsnAck",
        "a_rwnd",
        "numGaps",
        "numNrGaps",
        "numDupTsns",
        "isNrSack",
        "gapStart",
        "gapStop",
        "dupTsns",
        "sackSeqNum",
        "nrGapStart",
        "nrGapStop",
        "msg_rwnd",
        "dacPacketsRcvd",
        "nrSubtractRGaps",
    };
    return (field >= 0 && field < 15) ? fieldNames[field] : nullptr;
}

int SctpSackChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cumTsnAck") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "a_rwnd") == 0) return base+1;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numGaps") == 0) return base+2;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numNrGaps") == 0) return base+3;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numDupTsns") == 0) return base+4;
    if (fieldName[0] == 'i' && strcmp(fieldName, "isNrSack") == 0) return base+5;
    if (fieldName[0] == 'g' && strcmp(fieldName, "gapStart") == 0) return base+6;
    if (fieldName[0] == 'g' && strcmp(fieldName, "gapStop") == 0) return base+7;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dupTsns") == 0) return base+8;
    if (fieldName[0] == 's' && strcmp(fieldName, "sackSeqNum") == 0) return base+9;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nrGapStart") == 0) return base+10;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nrGapStop") == 0) return base+11;
    if (fieldName[0] == 'm' && strcmp(fieldName, "msg_rwnd") == 0) return base+12;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dacPacketsRcvd") == 0) return base+13;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nrSubtractRGaps") == 0) return base+14;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpSackChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_cumTsnAck
        "uint32",    // FIELD_a_rwnd
        "uint16",    // FIELD_numGaps
        "uint16",    // FIELD_numNrGaps
        "uint16",    // FIELD_numDupTsns
        "bool",    // FIELD_isNrSack
        "uint32",    // FIELD_gapStart
        "uint32",    // FIELD_gapStop
        "uint32",    // FIELD_dupTsns
        "uint32",    // FIELD_sackSeqNum
        "uint32",    // FIELD_nrGapStart
        "uint32",    // FIELD_nrGapStop
        "uint32",    // FIELD_msg_rwnd
        "uint8",    // FIELD_dacPacketsRcvd
        "bool",    // FIELD_nrSubtractRGaps
    };
    return (field >= 0 && field < 15) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpSackChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpSackChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpSackChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpSackChunk *pp = (SctpSackChunk *)object; (void)pp;
    switch (field) {
        case FIELD_gapStart: return pp->getGapStartArraySize();
        case FIELD_gapStop: return pp->getGapStopArraySize();
        case FIELD_dupTsns: return pp->getDupTsnsArraySize();
        case FIELD_nrGapStart: return pp->getNrGapStartArraySize();
        case FIELD_nrGapStop: return pp->getNrGapStopArraySize();
        default: return 0;
    }
}

const char *SctpSackChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSackChunk *pp = (SctpSackChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpSackChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSackChunk *pp = (SctpSackChunk *)object; (void)pp;
    switch (field) {
        case FIELD_cumTsnAck: return ulong2string(pp->getCumTsnAck());
        case FIELD_a_rwnd: return ulong2string(pp->getA_rwnd());
        case FIELD_numGaps: return ulong2string(pp->getNumGaps());
        case FIELD_numNrGaps: return ulong2string(pp->getNumNrGaps());
        case FIELD_numDupTsns: return ulong2string(pp->getNumDupTsns());
        case FIELD_isNrSack: return bool2string(pp->isNrSack());
        case FIELD_gapStart: return ulong2string(pp->getGapStart(i));
        case FIELD_gapStop: return ulong2string(pp->getGapStop(i));
        case FIELD_dupTsns: return ulong2string(pp->getDupTsns(i));
        case FIELD_sackSeqNum: return ulong2string(pp->getSackSeqNum());
        case FIELD_nrGapStart: return ulong2string(pp->getNrGapStart(i));
        case FIELD_nrGapStop: return ulong2string(pp->getNrGapStop(i));
        case FIELD_msg_rwnd: return ulong2string(pp->getMsg_rwnd());
        case FIELD_dacPacketsRcvd: return ulong2string(pp->getDacPacketsRcvd());
        case FIELD_nrSubtractRGaps: return bool2string(pp->getNrSubtractRGaps());
        default: return "";
    }
}

bool SctpSackChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpSackChunk *pp = (SctpSackChunk *)object; (void)pp;
    switch (field) {
        case FIELD_cumTsnAck: pp->setCumTsnAck(string2ulong(value)); return true;
        case FIELD_a_rwnd: pp->setA_rwnd(string2ulong(value)); return true;
        case FIELD_numGaps: pp->setNumGaps(string2ulong(value)); return true;
        case FIELD_numNrGaps: pp->setNumNrGaps(string2ulong(value)); return true;
        case FIELD_numDupTsns: pp->setNumDupTsns(string2ulong(value)); return true;
        case FIELD_isNrSack: pp->setIsNrSack(string2bool(value)); return true;
        case FIELD_gapStart: pp->setGapStart(i,string2ulong(value)); return true;
        case FIELD_gapStop: pp->setGapStop(i,string2ulong(value)); return true;
        case FIELD_dupTsns: pp->setDupTsns(i,string2ulong(value)); return true;
        case FIELD_sackSeqNum: pp->setSackSeqNum(string2ulong(value)); return true;
        case FIELD_nrGapStart: pp->setNrGapStart(i,string2ulong(value)); return true;
        case FIELD_nrGapStop: pp->setNrGapStop(i,string2ulong(value)); return true;
        case FIELD_msg_rwnd: pp->setMsg_rwnd(string2ulong(value)); return true;
        case FIELD_dacPacketsRcvd: pp->setDacPacketsRcvd(string2ulong(value)); return true;
        case FIELD_nrSubtractRGaps: pp->setNrSubtractRGaps(string2bool(value)); return true;
        default: return false;
    }
}

const char *SctpSackChunkDescriptor::getFieldStructName(int field) const
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

void *SctpSackChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpSackChunk *pp = (SctpSackChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpAbortChunk)

SctpAbortChunk::SctpAbortChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpAbortChunk::SctpAbortChunk(const SctpAbortChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpAbortChunk::~SctpAbortChunk()
{
}

SctpAbortChunk& SctpAbortChunk::operator=(const SctpAbortChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpAbortChunk::copy(const SctpAbortChunk& other)
{
    this->T_Bit = other.T_Bit;
}

void SctpAbortChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->T_Bit);
}

void SctpAbortChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->T_Bit);
}

bool SctpAbortChunk::getT_Bit() const
{
    return this->T_Bit;
}

void SctpAbortChunk::setT_Bit(bool T_Bit)
{
    this->T_Bit = T_Bit;
}

class SctpAbortChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_T_Bit,
    };
  public:
    SctpAbortChunkDescriptor();
    virtual ~SctpAbortChunkDescriptor();

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

Register_ClassDescriptor(SctpAbortChunkDescriptor)

SctpAbortChunkDescriptor::SctpAbortChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpAbortChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpAbortChunkDescriptor::~SctpAbortChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpAbortChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpAbortChunk *>(obj)!=nullptr;
}

const char **SctpAbortChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpAbortChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpAbortChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SctpAbortChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_T_Bit
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SctpAbortChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "T_Bit",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SctpAbortChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'T' && strcmp(fieldName, "T_Bit") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpAbortChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_T_Bit
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpAbortChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpAbortChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpAbortChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpAbortChunk *pp = (SctpAbortChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpAbortChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAbortChunk *pp = (SctpAbortChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpAbortChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAbortChunk *pp = (SctpAbortChunk *)object; (void)pp;
    switch (field) {
        case FIELD_T_Bit: return bool2string(pp->getT_Bit());
        default: return "";
    }
}

bool SctpAbortChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpAbortChunk *pp = (SctpAbortChunk *)object; (void)pp;
    switch (field) {
        case FIELD_T_Bit: pp->setT_Bit(string2bool(value)); return true;
        default: return false;
    }
}

const char *SctpAbortChunkDescriptor::getFieldStructName(int field) const
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

void *SctpAbortChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpAbortChunk *pp = (SctpAbortChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpHeartbeatChunk)

SctpHeartbeatChunk::SctpHeartbeatChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpHeartbeatChunk::SctpHeartbeatChunk(const SctpHeartbeatChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpHeartbeatChunk::~SctpHeartbeatChunk()
{
    delete [] this->info;
}

SctpHeartbeatChunk& SctpHeartbeatChunk::operator=(const SctpHeartbeatChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpHeartbeatChunk::copy(const SctpHeartbeatChunk& other)
{
    this->remoteAddr = other.remoteAddr;
    this->timeField = other.timeField;
    delete [] this->info;
    this->info = (other.info_arraysize==0) ? nullptr : new char[other.info_arraysize];
    info_arraysize = other.info_arraysize;
    for (size_t i = 0; i < info_arraysize; i++) {
        this->info[i] = other.info[i];
    }
}

void SctpHeartbeatChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->timeField);
    b->pack(info_arraysize);
    doParsimArrayPacking(b,this->info,info_arraysize);
}

void SctpHeartbeatChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->timeField);
    delete [] this->info;
    b->unpack(info_arraysize);
    if (info_arraysize == 0) {
        this->info = nullptr;
    } else {
        this->info = new char[info_arraysize];
        doParsimArrayUnpacking(b,this->info,info_arraysize);
    }
}

const L3Address& SctpHeartbeatChunk::getRemoteAddr() const
{
    return this->remoteAddr;
}

void SctpHeartbeatChunk::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

omnetpp::simtime_t SctpHeartbeatChunk::getTimeField() const
{
    return this->timeField;
}

void SctpHeartbeatChunk::setTimeField(omnetpp::simtime_t timeField)
{
    this->timeField = timeField;
}

size_t SctpHeartbeatChunk::getInfoArraySize() const
{
    return info_arraysize;
}

char SctpHeartbeatChunk::getInfo(size_t k) const
{
    if (k >= info_arraysize) throw omnetpp::cRuntimeError("Array of size info_arraysize indexed by %lu", (unsigned long)k);
    return this->info[k];
}

void SctpHeartbeatChunk::setInfoArraySize(size_t newSize)
{
    char *info2 = (newSize==0) ? nullptr : new char[newSize];
    size_t minSize = info_arraysize < newSize ? info_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        info2[i] = this->info[i];
    for (size_t i = minSize; i < newSize; i++)
        info2[i] = 0;
    delete [] this->info;
    this->info = info2;
    info_arraysize = newSize;
}

void SctpHeartbeatChunk::setInfo(size_t k, char info)
{
    if (k >= info_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->info[k] = info;
}

void SctpHeartbeatChunk::insertInfo(size_t k, char info)
{
    if (k > info_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = info_arraysize + 1;
    char *info2 = new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        info2[i] = this->info[i];
    info2[k] = info;
    for (i = k + 1; i < newSize; i++)
        info2[i] = this->info[i-1];
    delete [] this->info;
    this->info = info2;
    info_arraysize = newSize;
}

void SctpHeartbeatChunk::insertInfo(char info)
{
    insertInfo(info_arraysize, info);
}

void SctpHeartbeatChunk::eraseInfo(size_t k)
{
    if (k >= info_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = info_arraysize - 1;
    char *info2 = (newSize == 0) ? nullptr : new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        info2[i] = this->info[i];
    for (i = k; i < newSize; i++)
        info2[i] = this->info[i+1];
    delete [] this->info;
    this->info = info2;
    info_arraysize = newSize;
}

class SctpHeartbeatChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_remoteAddr,
        FIELD_timeField,
        FIELD_info,
    };
  public:
    SctpHeartbeatChunkDescriptor();
    virtual ~SctpHeartbeatChunkDescriptor();

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

Register_ClassDescriptor(SctpHeartbeatChunkDescriptor)

SctpHeartbeatChunkDescriptor::SctpHeartbeatChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpHeartbeatChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpHeartbeatChunkDescriptor::~SctpHeartbeatChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpHeartbeatChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpHeartbeatChunk *>(obj)!=nullptr;
}

const char **SctpHeartbeatChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpHeartbeatChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpHeartbeatChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SctpHeartbeatChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_remoteAddr
        0,    // FIELD_timeField
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_info
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SctpHeartbeatChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteAddr",
        "timeField",
        "info",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SctpHeartbeatChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddr") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "timeField") == 0) return base+1;
    if (fieldName[0] == 'i' && strcmp(fieldName, "info") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpHeartbeatChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_remoteAddr
        "omnetpp::simtime_t",    // FIELD_timeField
        "char",    // FIELD_info
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpHeartbeatChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpHeartbeatChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpHeartbeatChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpHeartbeatChunk *pp = (SctpHeartbeatChunk *)object; (void)pp;
    switch (field) {
        case FIELD_info: return pp->getInfoArraySize();
        default: return 0;
    }
}

const char *SctpHeartbeatChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpHeartbeatChunk *pp = (SctpHeartbeatChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpHeartbeatChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpHeartbeatChunk *pp = (SctpHeartbeatChunk *)object; (void)pp;
    switch (field) {
        case FIELD_remoteAddr: return pp->getRemoteAddr().str();
        case FIELD_timeField: return simtime2string(pp->getTimeField());
        case FIELD_info: return long2string(pp->getInfo(i));
        default: return "";
    }
}

bool SctpHeartbeatChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpHeartbeatChunk *pp = (SctpHeartbeatChunk *)object; (void)pp;
    switch (field) {
        case FIELD_info: pp->setInfo(i,string2long(value)); return true;
        default: return false;
    }
}

const char *SctpHeartbeatChunkDescriptor::getFieldStructName(int field) const
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

void *SctpHeartbeatChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpHeartbeatChunk *pp = (SctpHeartbeatChunk *)object; (void)pp;
    switch (field) {
        case FIELD_remoteAddr: return toVoidPtr(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(SctpHeartbeatAckChunk)

SctpHeartbeatAckChunk::SctpHeartbeatAckChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpHeartbeatAckChunk::SctpHeartbeatAckChunk(const SctpHeartbeatAckChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpHeartbeatAckChunk::~SctpHeartbeatAckChunk()
{
    delete [] this->info;
}

SctpHeartbeatAckChunk& SctpHeartbeatAckChunk::operator=(const SctpHeartbeatAckChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpHeartbeatAckChunk::copy(const SctpHeartbeatAckChunk& other)
{
    this->remoteAddr = other.remoteAddr;
    this->timeField = other.timeField;
    delete [] this->info;
    this->info = (other.info_arraysize==0) ? nullptr : new char[other.info_arraysize];
    info_arraysize = other.info_arraysize;
    for (size_t i = 0; i < info_arraysize; i++) {
        this->info[i] = other.info[i];
    }
}

void SctpHeartbeatAckChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->timeField);
    b->pack(info_arraysize);
    doParsimArrayPacking(b,this->info,info_arraysize);
}

void SctpHeartbeatAckChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->timeField);
    delete [] this->info;
    b->unpack(info_arraysize);
    if (info_arraysize == 0) {
        this->info = nullptr;
    } else {
        this->info = new char[info_arraysize];
        doParsimArrayUnpacking(b,this->info,info_arraysize);
    }
}

const L3Address& SctpHeartbeatAckChunk::getRemoteAddr() const
{
    return this->remoteAddr;
}

void SctpHeartbeatAckChunk::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

omnetpp::simtime_t SctpHeartbeatAckChunk::getTimeField() const
{
    return this->timeField;
}

void SctpHeartbeatAckChunk::setTimeField(omnetpp::simtime_t timeField)
{
    this->timeField = timeField;
}

size_t SctpHeartbeatAckChunk::getInfoArraySize() const
{
    return info_arraysize;
}

char SctpHeartbeatAckChunk::getInfo(size_t k) const
{
    if (k >= info_arraysize) throw omnetpp::cRuntimeError("Array of size info_arraysize indexed by %lu", (unsigned long)k);
    return this->info[k];
}

void SctpHeartbeatAckChunk::setInfoArraySize(size_t newSize)
{
    char *info2 = (newSize==0) ? nullptr : new char[newSize];
    size_t minSize = info_arraysize < newSize ? info_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        info2[i] = this->info[i];
    for (size_t i = minSize; i < newSize; i++)
        info2[i] = 0;
    delete [] this->info;
    this->info = info2;
    info_arraysize = newSize;
}

void SctpHeartbeatAckChunk::setInfo(size_t k, char info)
{
    if (k >= info_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->info[k] = info;
}

void SctpHeartbeatAckChunk::insertInfo(size_t k, char info)
{
    if (k > info_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = info_arraysize + 1;
    char *info2 = new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        info2[i] = this->info[i];
    info2[k] = info;
    for (i = k + 1; i < newSize; i++)
        info2[i] = this->info[i-1];
    delete [] this->info;
    this->info = info2;
    info_arraysize = newSize;
}

void SctpHeartbeatAckChunk::insertInfo(char info)
{
    insertInfo(info_arraysize, info);
}

void SctpHeartbeatAckChunk::eraseInfo(size_t k)
{
    if (k >= info_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = info_arraysize - 1;
    char *info2 = (newSize == 0) ? nullptr : new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        info2[i] = this->info[i];
    for (i = k; i < newSize; i++)
        info2[i] = this->info[i+1];
    delete [] this->info;
    this->info = info2;
    info_arraysize = newSize;
}

class SctpHeartbeatAckChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_remoteAddr,
        FIELD_timeField,
        FIELD_info,
    };
  public:
    SctpHeartbeatAckChunkDescriptor();
    virtual ~SctpHeartbeatAckChunkDescriptor();

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

Register_ClassDescriptor(SctpHeartbeatAckChunkDescriptor)

SctpHeartbeatAckChunkDescriptor::SctpHeartbeatAckChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpHeartbeatAckChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpHeartbeatAckChunkDescriptor::~SctpHeartbeatAckChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpHeartbeatAckChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpHeartbeatAckChunk *>(obj)!=nullptr;
}

const char **SctpHeartbeatAckChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpHeartbeatAckChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpHeartbeatAckChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SctpHeartbeatAckChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_remoteAddr
        0,    // FIELD_timeField
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_info
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SctpHeartbeatAckChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteAddr",
        "timeField",
        "info",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SctpHeartbeatAckChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddr") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "timeField") == 0) return base+1;
    if (fieldName[0] == 'i' && strcmp(fieldName, "info") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpHeartbeatAckChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_remoteAddr
        "omnetpp::simtime_t",    // FIELD_timeField
        "char",    // FIELD_info
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpHeartbeatAckChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpHeartbeatAckChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpHeartbeatAckChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpHeartbeatAckChunk *pp = (SctpHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        case FIELD_info: return pp->getInfoArraySize();
        default: return 0;
    }
}

const char *SctpHeartbeatAckChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpHeartbeatAckChunk *pp = (SctpHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpHeartbeatAckChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpHeartbeatAckChunk *pp = (SctpHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        case FIELD_remoteAddr: return pp->getRemoteAddr().str();
        case FIELD_timeField: return simtime2string(pp->getTimeField());
        case FIELD_info: return long2string(pp->getInfo(i));
        default: return "";
    }
}

bool SctpHeartbeatAckChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpHeartbeatAckChunk *pp = (SctpHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        case FIELD_info: pp->setInfo(i,string2long(value)); return true;
        default: return false;
    }
}

const char *SctpHeartbeatAckChunkDescriptor::getFieldStructName(int field) const
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

void *SctpHeartbeatAckChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpHeartbeatAckChunk *pp = (SctpHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        case FIELD_remoteAddr: return toVoidPtr(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(SctpShutdownChunk)

SctpShutdownChunk::SctpShutdownChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpShutdownChunk::SctpShutdownChunk(const SctpShutdownChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpShutdownChunk::~SctpShutdownChunk()
{
}

SctpShutdownChunk& SctpShutdownChunk::operator=(const SctpShutdownChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpShutdownChunk::copy(const SctpShutdownChunk& other)
{
    this->cumTsnAck = other.cumTsnAck;
}

void SctpShutdownChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->cumTsnAck);
}

void SctpShutdownChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->cumTsnAck);
}

uint32_t SctpShutdownChunk::getCumTsnAck() const
{
    return this->cumTsnAck;
}

void SctpShutdownChunk::setCumTsnAck(uint32_t cumTsnAck)
{
    this->cumTsnAck = cumTsnAck;
}

class SctpShutdownChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_cumTsnAck,
    };
  public:
    SctpShutdownChunkDescriptor();
    virtual ~SctpShutdownChunkDescriptor();

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

Register_ClassDescriptor(SctpShutdownChunkDescriptor)

SctpShutdownChunkDescriptor::SctpShutdownChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpShutdownChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpShutdownChunkDescriptor::~SctpShutdownChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpShutdownChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpShutdownChunk *>(obj)!=nullptr;
}

const char **SctpShutdownChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpShutdownChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpShutdownChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SctpShutdownChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_cumTsnAck
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SctpShutdownChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "cumTsnAck",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SctpShutdownChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cumTsnAck") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpShutdownChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_cumTsnAck
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpShutdownChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpShutdownChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpShutdownChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownChunk *pp = (SctpShutdownChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpShutdownChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownChunk *pp = (SctpShutdownChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpShutdownChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownChunk *pp = (SctpShutdownChunk *)object; (void)pp;
    switch (field) {
        case FIELD_cumTsnAck: return ulong2string(pp->getCumTsnAck());
        default: return "";
    }
}

bool SctpShutdownChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownChunk *pp = (SctpShutdownChunk *)object; (void)pp;
    switch (field) {
        case FIELD_cumTsnAck: pp->setCumTsnAck(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpShutdownChunkDescriptor::getFieldStructName(int field) const
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

void *SctpShutdownChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownChunk *pp = (SctpShutdownChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpShutdownAckChunk)

SctpShutdownAckChunk::SctpShutdownAckChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpShutdownAckChunk::SctpShutdownAckChunk(const SctpShutdownAckChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpShutdownAckChunk::~SctpShutdownAckChunk()
{
}

SctpShutdownAckChunk& SctpShutdownAckChunk::operator=(const SctpShutdownAckChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpShutdownAckChunk::copy(const SctpShutdownAckChunk& other)
{
}

void SctpShutdownAckChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
}

void SctpShutdownAckChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
}

class SctpShutdownAckChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    SctpShutdownAckChunkDescriptor();
    virtual ~SctpShutdownAckChunkDescriptor();

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

Register_ClassDescriptor(SctpShutdownAckChunkDescriptor)

SctpShutdownAckChunkDescriptor::SctpShutdownAckChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpShutdownAckChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpShutdownAckChunkDescriptor::~SctpShutdownAckChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpShutdownAckChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpShutdownAckChunk *>(obj)!=nullptr;
}

const char **SctpShutdownAckChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpShutdownAckChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpShutdownAckChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int SctpShutdownAckChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *SctpShutdownAckChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int SctpShutdownAckChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpShutdownAckChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **SctpShutdownAckChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpShutdownAckChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpShutdownAckChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownAckChunk *pp = (SctpShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpShutdownAckChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownAckChunk *pp = (SctpShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpShutdownAckChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownAckChunk *pp = (SctpShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SctpShutdownAckChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownAckChunk *pp = (SctpShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SctpShutdownAckChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *SctpShutdownAckChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownAckChunk *pp = (SctpShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpShutdownCompleteChunk)

SctpShutdownCompleteChunk::SctpShutdownCompleteChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpShutdownCompleteChunk::SctpShutdownCompleteChunk(const SctpShutdownCompleteChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpShutdownCompleteChunk::~SctpShutdownCompleteChunk()
{
}

SctpShutdownCompleteChunk& SctpShutdownCompleteChunk::operator=(const SctpShutdownCompleteChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpShutdownCompleteChunk::copy(const SctpShutdownCompleteChunk& other)
{
    this->TBit = other.TBit;
}

void SctpShutdownCompleteChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->TBit);
}

void SctpShutdownCompleteChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->TBit);
}

bool SctpShutdownCompleteChunk::getTBit() const
{
    return this->TBit;
}

void SctpShutdownCompleteChunk::setTBit(bool TBit)
{
    this->TBit = TBit;
}

class SctpShutdownCompleteChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_TBit,
    };
  public:
    SctpShutdownCompleteChunkDescriptor();
    virtual ~SctpShutdownCompleteChunkDescriptor();

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

Register_ClassDescriptor(SctpShutdownCompleteChunkDescriptor)

SctpShutdownCompleteChunkDescriptor::SctpShutdownCompleteChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpShutdownCompleteChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpShutdownCompleteChunkDescriptor::~SctpShutdownCompleteChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpShutdownCompleteChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpShutdownCompleteChunk *>(obj)!=nullptr;
}

const char **SctpShutdownCompleteChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpShutdownCompleteChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpShutdownCompleteChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SctpShutdownCompleteChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_TBit
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SctpShutdownCompleteChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "TBit",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SctpShutdownCompleteChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'T' && strcmp(fieldName, "TBit") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpShutdownCompleteChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_TBit
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpShutdownCompleteChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpShutdownCompleteChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpShutdownCompleteChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownCompleteChunk *pp = (SctpShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpShutdownCompleteChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownCompleteChunk *pp = (SctpShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpShutdownCompleteChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownCompleteChunk *pp = (SctpShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        case FIELD_TBit: return bool2string(pp->getTBit());
        default: return "";
    }
}

bool SctpShutdownCompleteChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownCompleteChunk *pp = (SctpShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        case FIELD_TBit: pp->setTBit(string2bool(value)); return true;
        default: return false;
    }
}

const char *SctpShutdownCompleteChunkDescriptor::getFieldStructName(int field) const
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

void *SctpShutdownCompleteChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpShutdownCompleteChunk *pp = (SctpShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

SctpErrorChunk_Base::SctpErrorChunk_Base(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpErrorChunk_Base::SctpErrorChunk_Base(const SctpErrorChunk_Base& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpErrorChunk_Base::~SctpErrorChunk_Base()
{
}

SctpErrorChunk_Base& SctpErrorChunk_Base::operator=(const SctpErrorChunk_Base& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpErrorChunk_Base::copy(const SctpErrorChunk_Base& other)
{
    this->TBit = other.TBit;
    this->MBit = other.MBit;
}

void SctpErrorChunk_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->TBit);
    doParsimPacking(b,this->MBit);
    // field parameters is abstract -- please do packing in customized class
}

void SctpErrorChunk_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->TBit);
    doParsimUnpacking(b,this->MBit);
    // field parameters is abstract -- please do unpacking in customized class
}

bool SctpErrorChunk_Base::getTBit() const
{
    return this->TBit;
}

void SctpErrorChunk_Base::setTBit(bool TBit)
{
    this->TBit = TBit;
}

bool SctpErrorChunk_Base::getMBit() const
{
    return this->MBit;
}

void SctpErrorChunk_Base::setMBit(bool MBit)
{
    this->MBit = MBit;
}

class SctpErrorChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_TBit,
        FIELD_MBit,
        FIELD_parameters,
    };
  public:
    SctpErrorChunkDescriptor();
    virtual ~SctpErrorChunkDescriptor();

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

Register_ClassDescriptor(SctpErrorChunkDescriptor)

SctpErrorChunkDescriptor::SctpErrorChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SctpErrorChunk", "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpErrorChunkDescriptor::~SctpErrorChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpErrorChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpErrorChunk_Base *>(obj)!=nullptr;
}

const char **SctpErrorChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpErrorChunkDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "customize")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpErrorChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SctpErrorChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_TBit
        FD_ISEDITABLE,    // FIELD_MBit
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_parameters
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SctpErrorChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "TBit",
        "MBit",
        "parameters",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SctpErrorChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'T' && strcmp(fieldName, "TBit") == 0) return base+0;
    if (fieldName[0] == 'M' && strcmp(fieldName, "MBit") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "parameters") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpErrorChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_TBit
        "bool",    // FIELD_MBit
        "inet::sctp::SctpParameter",    // FIELD_parameters
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpErrorChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpErrorChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpErrorChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpErrorChunk_Base *pp = (SctpErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_parameters: return pp->getParametersArraySize();
        default: return 0;
    }
}

const char *SctpErrorChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpErrorChunk_Base *pp = (SctpErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_parameters: { const SctpParameter * value = pp->getParameters(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string SctpErrorChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpErrorChunk_Base *pp = (SctpErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_TBit: return bool2string(pp->getTBit());
        case FIELD_MBit: return bool2string(pp->getMBit());
        case FIELD_parameters: {std::stringstream out; out << pp->getParameters(i); return out.str();}
        default: return "";
    }
}

bool SctpErrorChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpErrorChunk_Base *pp = (SctpErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_TBit: pp->setTBit(string2bool(value)); return true;
        case FIELD_MBit: pp->setMBit(string2bool(value)); return true;
        default: return false;
    }
}

const char *SctpErrorChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_parameters: return omnetpp::opp_typename(typeid(SctpParameter));
        default: return nullptr;
    };
}

void *SctpErrorChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpErrorChunk_Base *pp = (SctpErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_parameters: return toVoidPtr(pp->getParameters(i)); break;
        default: return nullptr;
    }
}

Register_Class(SctpParameter)

SctpParameter::SctpParameter(const char *name) : ::omnetpp::cPacket(name)
{
}

SctpParameter::SctpParameter(const SctpParameter& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SctpParameter::~SctpParameter()
{
    delete [] this->name;
}

SctpParameter& SctpParameter::operator=(const SctpParameter& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SctpParameter::copy(const SctpParameter& other)
{
    this->parameterType = other.parameterType;
    delete [] this->name;
    this->name = (other.name_arraysize==0) ? nullptr : new char[other.name_arraysize];
    name_arraysize = other.name_arraysize;
    for (size_t i = 0; i < name_arraysize; i++) {
        this->name[i] = other.name[i];
    }
}

void SctpParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->parameterType);
    b->pack(name_arraysize);
    doParsimArrayPacking(b,this->name,name_arraysize);
}

void SctpParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->parameterType);
    delete [] this->name;
    b->unpack(name_arraysize);
    if (name_arraysize == 0) {
        this->name = nullptr;
    } else {
        this->name = new char[name_arraysize];
        doParsimArrayUnpacking(b,this->name,name_arraysize);
    }
}

uint16_t SctpParameter::getParameterType() const
{
    return this->parameterType;
}

void SctpParameter::setParameterType(uint16_t parameterType)
{
    this->parameterType = parameterType;
}

size_t SctpParameter::getNameArraySize() const
{
    return name_arraysize;
}

char SctpParameter::getName(size_t k) const
{
    if (k >= name_arraysize) throw omnetpp::cRuntimeError("Array of size name_arraysize indexed by %lu", (unsigned long)k);
    return this->name[k];
}

void SctpParameter::setNameArraySize(size_t newSize)
{
    char *name2 = (newSize==0) ? nullptr : new char[newSize];
    size_t minSize = name_arraysize < newSize ? name_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        name2[i] = this->name[i];
    for (size_t i = minSize; i < newSize; i++)
        name2[i] = 0;
    delete [] this->name;
    this->name = name2;
    name_arraysize = newSize;
}

void SctpParameter::setName(size_t k, char name)
{
    if (k >= name_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->name[k] = name;
}

void SctpParameter::insertName(size_t k, char name)
{
    if (k > name_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = name_arraysize + 1;
    char *name2 = new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        name2[i] = this->name[i];
    name2[k] = name;
    for (i = k + 1; i < newSize; i++)
        name2[i] = this->name[i-1];
    delete [] this->name;
    this->name = name2;
    name_arraysize = newSize;
}

void SctpParameter::insertName(char name)
{
    insertName(name_arraysize, name);
}

void SctpParameter::eraseName(size_t k)
{
    if (k >= name_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = name_arraysize - 1;
    char *name2 = (newSize == 0) ? nullptr : new char[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        name2[i] = this->name[i];
    for (i = k; i < newSize; i++)
        name2[i] = this->name[i+1];
    delete [] this->name;
    this->name = name2;
    name_arraysize = newSize;
}

class SctpParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_parameterType,
        FIELD_name,
    };
  public:
    SctpParameterDescriptor();
    virtual ~SctpParameterDescriptor();

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

Register_ClassDescriptor(SctpParameterDescriptor)

SctpParameterDescriptor::SctpParameterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpParameter)), "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SctpParameterDescriptor::~SctpParameterDescriptor()
{
    delete[] propertynames;
}

bool SctpParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpParameter *>(obj)!=nullptr;
}

const char **SctpParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SctpParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_parameterType
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_name
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *SctpParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "parameterType",
        "name",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int SctpParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "parameterType") == 0) return base+0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "name") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",    // FIELD_parameterType
        "char",    // FIELD_name
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpParameter *pp = (SctpParameter *)object; (void)pp;
    switch (field) {
        case FIELD_name: return pp->getNameArraySize();
        default: return 0;
    }
}

const char *SctpParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpParameter *pp = (SctpParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpParameter *pp = (SctpParameter *)object; (void)pp;
    switch (field) {
        case FIELD_parameterType: return ulong2string(pp->getParameterType());
        case FIELD_name: return long2string(pp->getName(i));
        default: return "";
    }
}

bool SctpParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpParameter *pp = (SctpParameter *)object; (void)pp;
    switch (field) {
        case FIELD_parameterType: pp->setParameterType(string2ulong(value)); return true;
        case FIELD_name: pp->setName(i,string2long(value)); return true;
        default: return false;
    }
}

const char *SctpParameterDescriptor::getFieldStructName(int field) const
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

void *SctpParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpParameter *pp = (SctpParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpPacketDropChunk)

SctpPacketDropChunk::SctpPacketDropChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpPacketDropChunk::SctpPacketDropChunk(const SctpPacketDropChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpPacketDropChunk::~SctpPacketDropChunk()
{
}

SctpPacketDropChunk& SctpPacketDropChunk::operator=(const SctpPacketDropChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpPacketDropChunk::copy(const SctpPacketDropChunk& other)
{
    this->cFlag = other.cFlag;
    this->tFlag = other.tFlag;
    this->bFlag = other.bFlag;
    this->mFlag = other.mFlag;
    this->maxRwnd = other.maxRwnd;
    this->queuedData = other.queuedData;
    this->truncLength = other.truncLength;
}

void SctpPacketDropChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->cFlag);
    doParsimPacking(b,this->tFlag);
    doParsimPacking(b,this->bFlag);
    doParsimPacking(b,this->mFlag);
    doParsimPacking(b,this->maxRwnd);
    doParsimPacking(b,this->queuedData);
    doParsimPacking(b,this->truncLength);
}

void SctpPacketDropChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->cFlag);
    doParsimUnpacking(b,this->tFlag);
    doParsimUnpacking(b,this->bFlag);
    doParsimUnpacking(b,this->mFlag);
    doParsimUnpacking(b,this->maxRwnd);
    doParsimUnpacking(b,this->queuedData);
    doParsimUnpacking(b,this->truncLength);
}

bool SctpPacketDropChunk::getCFlag() const
{
    return this->cFlag;
}

void SctpPacketDropChunk::setCFlag(bool cFlag)
{
    this->cFlag = cFlag;
}

bool SctpPacketDropChunk::getTFlag() const
{
    return this->tFlag;
}

void SctpPacketDropChunk::setTFlag(bool tFlag)
{
    this->tFlag = tFlag;
}

bool SctpPacketDropChunk::getBFlag() const
{
    return this->bFlag;
}

void SctpPacketDropChunk::setBFlag(bool bFlag)
{
    this->bFlag = bFlag;
}

bool SctpPacketDropChunk::getMFlag() const
{
    return this->mFlag;
}

void SctpPacketDropChunk::setMFlag(bool mFlag)
{
    this->mFlag = mFlag;
}

uint32_t SctpPacketDropChunk::getMaxRwnd() const
{
    return this->maxRwnd;
}

void SctpPacketDropChunk::setMaxRwnd(uint32_t maxRwnd)
{
    this->maxRwnd = maxRwnd;
}

uint32_t SctpPacketDropChunk::getQueuedData() const
{
    return this->queuedData;
}

void SctpPacketDropChunk::setQueuedData(uint32_t queuedData)
{
    this->queuedData = queuedData;
}

uint16_t SctpPacketDropChunk::getTruncLength() const
{
    return this->truncLength;
}

void SctpPacketDropChunk::setTruncLength(uint16_t truncLength)
{
    this->truncLength = truncLength;
}

class SctpPacketDropChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_cFlag,
        FIELD_tFlag,
        FIELD_bFlag,
        FIELD_mFlag,
        FIELD_maxRwnd,
        FIELD_queuedData,
        FIELD_truncLength,
    };
  public:
    SctpPacketDropChunkDescriptor();
    virtual ~SctpPacketDropChunkDescriptor();

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

Register_ClassDescriptor(SctpPacketDropChunkDescriptor)

SctpPacketDropChunkDescriptor::SctpPacketDropChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpPacketDropChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpPacketDropChunkDescriptor::~SctpPacketDropChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpPacketDropChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpPacketDropChunk *>(obj)!=nullptr;
}

const char **SctpPacketDropChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpPacketDropChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpPacketDropChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int SctpPacketDropChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_cFlag
        FD_ISEDITABLE,    // FIELD_tFlag
        FD_ISEDITABLE,    // FIELD_bFlag
        FD_ISEDITABLE,    // FIELD_mFlag
        FD_ISEDITABLE,    // FIELD_maxRwnd
        FD_ISEDITABLE,    // FIELD_queuedData
        FD_ISEDITABLE,    // FIELD_truncLength
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *SctpPacketDropChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "cFlag",
        "tFlag",
        "bFlag",
        "mFlag",
        "maxRwnd",
        "queuedData",
        "truncLength",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int SctpPacketDropChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cFlag") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tFlag") == 0) return base+1;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bFlag") == 0) return base+2;
    if (fieldName[0] == 'm' && strcmp(fieldName, "mFlag") == 0) return base+3;
    if (fieldName[0] == 'm' && strcmp(fieldName, "maxRwnd") == 0) return base+4;
    if (fieldName[0] == 'q' && strcmp(fieldName, "queuedData") == 0) return base+5;
    if (fieldName[0] == 't' && strcmp(fieldName, "truncLength") == 0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpPacketDropChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_cFlag
        "bool",    // FIELD_tFlag
        "bool",    // FIELD_bFlag
        "bool",    // FIELD_mFlag
        "uint32",    // FIELD_maxRwnd
        "uint32",    // FIELD_queuedData
        "uint16",    // FIELD_truncLength
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpPacketDropChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpPacketDropChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpPacketDropChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpPacketDropChunk *pp = (SctpPacketDropChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpPacketDropChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpPacketDropChunk *pp = (SctpPacketDropChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpPacketDropChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpPacketDropChunk *pp = (SctpPacketDropChunk *)object; (void)pp;
    switch (field) {
        case FIELD_cFlag: return bool2string(pp->getCFlag());
        case FIELD_tFlag: return bool2string(pp->getTFlag());
        case FIELD_bFlag: return bool2string(pp->getBFlag());
        case FIELD_mFlag: return bool2string(pp->getMFlag());
        case FIELD_maxRwnd: return ulong2string(pp->getMaxRwnd());
        case FIELD_queuedData: return ulong2string(pp->getQueuedData());
        case FIELD_truncLength: return ulong2string(pp->getTruncLength());
        default: return "";
    }
}

bool SctpPacketDropChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpPacketDropChunk *pp = (SctpPacketDropChunk *)object; (void)pp;
    switch (field) {
        case FIELD_cFlag: pp->setCFlag(string2bool(value)); return true;
        case FIELD_tFlag: pp->setTFlag(string2bool(value)); return true;
        case FIELD_bFlag: pp->setBFlag(string2bool(value)); return true;
        case FIELD_mFlag: pp->setMFlag(string2bool(value)); return true;
        case FIELD_maxRwnd: pp->setMaxRwnd(string2ulong(value)); return true;
        case FIELD_queuedData: pp->setQueuedData(string2ulong(value)); return true;
        case FIELD_truncLength: pp->setTruncLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpPacketDropChunkDescriptor::getFieldStructName(int field) const
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

void *SctpPacketDropChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpPacketDropChunk *pp = (SctpPacketDropChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

SctpStreamResetChunk_Base::SctpStreamResetChunk_Base(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpStreamResetChunk_Base::SctpStreamResetChunk_Base(const SctpStreamResetChunk_Base& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpStreamResetChunk_Base::~SctpStreamResetChunk_Base()
{
}

SctpStreamResetChunk_Base& SctpStreamResetChunk_Base::operator=(const SctpStreamResetChunk_Base& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpStreamResetChunk_Base::copy(const SctpStreamResetChunk_Base& other)
{
}

void SctpStreamResetChunk_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    // field parameters is abstract -- please do packing in customized class
}

void SctpStreamResetChunk_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    // field parameters is abstract -- please do unpacking in customized class
}

class SctpStreamResetChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_parameters,
    };
  public:
    SctpStreamResetChunkDescriptor();
    virtual ~SctpStreamResetChunkDescriptor();

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

Register_ClassDescriptor(SctpStreamResetChunkDescriptor)

SctpStreamResetChunkDescriptor::SctpStreamResetChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SctpStreamResetChunk", "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpStreamResetChunkDescriptor::~SctpStreamResetChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpStreamResetChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpStreamResetChunk_Base *>(obj)!=nullptr;
}

const char **SctpStreamResetChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpStreamResetChunkDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "customize")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpStreamResetChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SctpStreamResetChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_parameters
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SctpStreamResetChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "parameters",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SctpStreamResetChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "parameters") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpStreamResetChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::sctp::SctpParameter",    // FIELD_parameters
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpStreamResetChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpStreamResetChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpStreamResetChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpStreamResetChunk_Base *pp = (SctpStreamResetChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_parameters: return pp->getParametersArraySize();
        default: return 0;
    }
}

const char *SctpStreamResetChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpStreamResetChunk_Base *pp = (SctpStreamResetChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_parameters: { const SctpParameter * value = pp->getParameters(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string SctpStreamResetChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpStreamResetChunk_Base *pp = (SctpStreamResetChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_parameters: {std::stringstream out; out << pp->getParameters(i); return out.str();}
        default: return "";
    }
}

bool SctpStreamResetChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpStreamResetChunk_Base *pp = (SctpStreamResetChunk_Base *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SctpStreamResetChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_parameters: return omnetpp::opp_typename(typeid(SctpParameter));
        default: return nullptr;
    };
}

void *SctpStreamResetChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpStreamResetChunk_Base *pp = (SctpStreamResetChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_parameters: return toVoidPtr(pp->getParameters(i)); break;
        default: return nullptr;
    }
}

Register_Class(SctpOutgoingSsnResetRequestParameter)

SctpOutgoingSsnResetRequestParameter::SctpOutgoingSsnResetRequestParameter(const char *name) : ::inet::sctp::SctpParameter(name)
{
}

SctpOutgoingSsnResetRequestParameter::SctpOutgoingSsnResetRequestParameter(const SctpOutgoingSsnResetRequestParameter& other) : ::inet::sctp::SctpParameter(other)
{
    copy(other);
}

SctpOutgoingSsnResetRequestParameter::~SctpOutgoingSsnResetRequestParameter()
{
    delete [] this->streamNumbers;
}

SctpOutgoingSsnResetRequestParameter& SctpOutgoingSsnResetRequestParameter::operator=(const SctpOutgoingSsnResetRequestParameter& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpParameter::operator=(other);
    copy(other);
    return *this;
}

void SctpOutgoingSsnResetRequestParameter::copy(const SctpOutgoingSsnResetRequestParameter& other)
{
    this->srReqSn = other.srReqSn;
    this->srResSn = other.srResSn;
    this->lastTsn = other.lastTsn;
    delete [] this->streamNumbers;
    this->streamNumbers = (other.streamNumbers_arraysize==0) ? nullptr : new uint16_t[other.streamNumbers_arraysize];
    streamNumbers_arraysize = other.streamNumbers_arraysize;
    for (size_t i = 0; i < streamNumbers_arraysize; i++) {
        this->streamNumbers[i] = other.streamNumbers[i];
    }
}

void SctpOutgoingSsnResetRequestParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpParameter::parsimPack(b);
    doParsimPacking(b,this->srReqSn);
    doParsimPacking(b,this->srResSn);
    doParsimPacking(b,this->lastTsn);
    b->pack(streamNumbers_arraysize);
    doParsimArrayPacking(b,this->streamNumbers,streamNumbers_arraysize);
}

void SctpOutgoingSsnResetRequestParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->srReqSn);
    doParsimUnpacking(b,this->srResSn);
    doParsimUnpacking(b,this->lastTsn);
    delete [] this->streamNumbers;
    b->unpack(streamNumbers_arraysize);
    if (streamNumbers_arraysize == 0) {
        this->streamNumbers = nullptr;
    } else {
        this->streamNumbers = new uint16_t[streamNumbers_arraysize];
        doParsimArrayUnpacking(b,this->streamNumbers,streamNumbers_arraysize);
    }
}

uint32_t SctpOutgoingSsnResetRequestParameter::getSrReqSn() const
{
    return this->srReqSn;
}

void SctpOutgoingSsnResetRequestParameter::setSrReqSn(uint32_t srReqSn)
{
    this->srReqSn = srReqSn;
}

uint32_t SctpOutgoingSsnResetRequestParameter::getSrResSn() const
{
    return this->srResSn;
}

void SctpOutgoingSsnResetRequestParameter::setSrResSn(uint32_t srResSn)
{
    this->srResSn = srResSn;
}

uint32_t SctpOutgoingSsnResetRequestParameter::getLastTsn() const
{
    return this->lastTsn;
}

void SctpOutgoingSsnResetRequestParameter::setLastTsn(uint32_t lastTsn)
{
    this->lastTsn = lastTsn;
}

size_t SctpOutgoingSsnResetRequestParameter::getStreamNumbersArraySize() const
{
    return streamNumbers_arraysize;
}

uint16_t SctpOutgoingSsnResetRequestParameter::getStreamNumbers(size_t k) const
{
    if (k >= streamNumbers_arraysize) throw omnetpp::cRuntimeError("Array of size streamNumbers_arraysize indexed by %lu", (unsigned long)k);
    return this->streamNumbers[k];
}

void SctpOutgoingSsnResetRequestParameter::setStreamNumbersArraySize(size_t newSize)
{
    uint16_t *streamNumbers2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = streamNumbers_arraysize < newSize ? streamNumbers_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        streamNumbers2[i] = this->streamNumbers[i];
    for (size_t i = minSize; i < newSize; i++)
        streamNumbers2[i] = 0;
    delete [] this->streamNumbers;
    this->streamNumbers = streamNumbers2;
    streamNumbers_arraysize = newSize;
}

void SctpOutgoingSsnResetRequestParameter::setStreamNumbers(size_t k, uint16_t streamNumbers)
{
    if (k >= streamNumbers_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->streamNumbers[k] = streamNumbers;
}

void SctpOutgoingSsnResetRequestParameter::insertStreamNumbers(size_t k, uint16_t streamNumbers)
{
    if (k > streamNumbers_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = streamNumbers_arraysize + 1;
    uint16_t *streamNumbers2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        streamNumbers2[i] = this->streamNumbers[i];
    streamNumbers2[k] = streamNumbers;
    for (i = k + 1; i < newSize; i++)
        streamNumbers2[i] = this->streamNumbers[i-1];
    delete [] this->streamNumbers;
    this->streamNumbers = streamNumbers2;
    streamNumbers_arraysize = newSize;
}

void SctpOutgoingSsnResetRequestParameter::insertStreamNumbers(uint16_t streamNumbers)
{
    insertStreamNumbers(streamNumbers_arraysize, streamNumbers);
}

void SctpOutgoingSsnResetRequestParameter::eraseStreamNumbers(size_t k)
{
    if (k >= streamNumbers_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = streamNumbers_arraysize - 1;
    uint16_t *streamNumbers2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        streamNumbers2[i] = this->streamNumbers[i];
    for (i = k; i < newSize; i++)
        streamNumbers2[i] = this->streamNumbers[i+1];
    delete [] this->streamNumbers;
    this->streamNumbers = streamNumbers2;
    streamNumbers_arraysize = newSize;
}

class SctpOutgoingSsnResetRequestParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_srReqSn,
        FIELD_srResSn,
        FIELD_lastTsn,
        FIELD_streamNumbers,
    };
  public:
    SctpOutgoingSsnResetRequestParameterDescriptor();
    virtual ~SctpOutgoingSsnResetRequestParameterDescriptor();

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

Register_ClassDescriptor(SctpOutgoingSsnResetRequestParameterDescriptor)

SctpOutgoingSsnResetRequestParameterDescriptor::SctpOutgoingSsnResetRequestParameterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpOutgoingSsnResetRequestParameter)), "inet::sctp::SctpParameter")
{
    propertynames = nullptr;
}

SctpOutgoingSsnResetRequestParameterDescriptor::~SctpOutgoingSsnResetRequestParameterDescriptor()
{
    delete[] propertynames;
}

bool SctpOutgoingSsnResetRequestParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpOutgoingSsnResetRequestParameter *>(obj)!=nullptr;
}

const char **SctpOutgoingSsnResetRequestParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpOutgoingSsnResetRequestParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpOutgoingSsnResetRequestParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SctpOutgoingSsnResetRequestParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srReqSn
        FD_ISEDITABLE,    // FIELD_srResSn
        FD_ISEDITABLE,    // FIELD_lastTsn
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_streamNumbers
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SctpOutgoingSsnResetRequestParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srReqSn",
        "srResSn",
        "lastTsn",
        "streamNumbers",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SctpOutgoingSsnResetRequestParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "srReqSn") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "srResSn") == 0) return base+1;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lastTsn") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "streamNumbers") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpOutgoingSsnResetRequestParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_srReqSn
        "uint32",    // FIELD_srResSn
        "uint32",    // FIELD_lastTsn
        "uint16",    // FIELD_streamNumbers
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpOutgoingSsnResetRequestParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpOutgoingSsnResetRequestParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpOutgoingSsnResetRequestParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpOutgoingSsnResetRequestParameter *pp = (SctpOutgoingSsnResetRequestParameter *)object; (void)pp;
    switch (field) {
        case FIELD_streamNumbers: return pp->getStreamNumbersArraySize();
        default: return 0;
    }
}

const char *SctpOutgoingSsnResetRequestParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpOutgoingSsnResetRequestParameter *pp = (SctpOutgoingSsnResetRequestParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpOutgoingSsnResetRequestParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpOutgoingSsnResetRequestParameter *pp = (SctpOutgoingSsnResetRequestParameter *)object; (void)pp;
    switch (field) {
        case FIELD_srReqSn: return ulong2string(pp->getSrReqSn());
        case FIELD_srResSn: return ulong2string(pp->getSrResSn());
        case FIELD_lastTsn: return ulong2string(pp->getLastTsn());
        case FIELD_streamNumbers: return ulong2string(pp->getStreamNumbers(i));
        default: return "";
    }
}

bool SctpOutgoingSsnResetRequestParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpOutgoingSsnResetRequestParameter *pp = (SctpOutgoingSsnResetRequestParameter *)object; (void)pp;
    switch (field) {
        case FIELD_srReqSn: pp->setSrReqSn(string2ulong(value)); return true;
        case FIELD_srResSn: pp->setSrResSn(string2ulong(value)); return true;
        case FIELD_lastTsn: pp->setLastTsn(string2ulong(value)); return true;
        case FIELD_streamNumbers: pp->setStreamNumbers(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpOutgoingSsnResetRequestParameterDescriptor::getFieldStructName(int field) const
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

void *SctpOutgoingSsnResetRequestParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpOutgoingSsnResetRequestParameter *pp = (SctpOutgoingSsnResetRequestParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

SctpIncomingSsnResetRequestParameter_Base::SctpIncomingSsnResetRequestParameter_Base(const char *name) : ::inet::sctp::SctpParameter(name)
{
}

SctpIncomingSsnResetRequestParameter_Base::SctpIncomingSsnResetRequestParameter_Base(const SctpIncomingSsnResetRequestParameter_Base& other) : ::inet::sctp::SctpParameter(other)
{
    copy(other);
}

SctpIncomingSsnResetRequestParameter_Base::~SctpIncomingSsnResetRequestParameter_Base()
{
    delete [] this->streamNumbers;
}

SctpIncomingSsnResetRequestParameter_Base& SctpIncomingSsnResetRequestParameter_Base::operator=(const SctpIncomingSsnResetRequestParameter_Base& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpParameter::operator=(other);
    copy(other);
    return *this;
}

void SctpIncomingSsnResetRequestParameter_Base::copy(const SctpIncomingSsnResetRequestParameter_Base& other)
{
    this->srReqSn = other.srReqSn;
    delete [] this->streamNumbers;
    this->streamNumbers = (other.streamNumbers_arraysize==0) ? nullptr : new uint16_t[other.streamNumbers_arraysize];
    streamNumbers_arraysize = other.streamNumbers_arraysize;
    for (size_t i = 0; i < streamNumbers_arraysize; i++) {
        this->streamNumbers[i] = other.streamNumbers[i];
    }
}

void SctpIncomingSsnResetRequestParameter_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpParameter::parsimPack(b);
    doParsimPacking(b,this->srReqSn);
    b->pack(streamNumbers_arraysize);
    doParsimArrayPacking(b,this->streamNumbers,streamNumbers_arraysize);
}

void SctpIncomingSsnResetRequestParameter_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->srReqSn);
    delete [] this->streamNumbers;
    b->unpack(streamNumbers_arraysize);
    if (streamNumbers_arraysize == 0) {
        this->streamNumbers = nullptr;
    } else {
        this->streamNumbers = new uint16_t[streamNumbers_arraysize];
        doParsimArrayUnpacking(b,this->streamNumbers,streamNumbers_arraysize);
    }
}

uint32_t SctpIncomingSsnResetRequestParameter_Base::getSrReqSn() const
{
    return this->srReqSn;
}

void SctpIncomingSsnResetRequestParameter_Base::setSrReqSn(uint32_t srReqSn)
{
    this->srReqSn = srReqSn;
}

size_t SctpIncomingSsnResetRequestParameter_Base::getStreamNumbersArraySize() const
{
    return streamNumbers_arraysize;
}

uint16_t SctpIncomingSsnResetRequestParameter_Base::getStreamNumbers(size_t k) const
{
    if (k >= streamNumbers_arraysize) throw omnetpp::cRuntimeError("Array of size streamNumbers_arraysize indexed by %lu", (unsigned long)k);
    return this->streamNumbers[k];
}

void SctpIncomingSsnResetRequestParameter_Base::setStreamNumbersArraySize(size_t newSize)
{
    uint16_t *streamNumbers2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = streamNumbers_arraysize < newSize ? streamNumbers_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        streamNumbers2[i] = this->streamNumbers[i];
    for (size_t i = minSize; i < newSize; i++)
        streamNumbers2[i] = 0;
    delete [] this->streamNumbers;
    this->streamNumbers = streamNumbers2;
    streamNumbers_arraysize = newSize;
}

void SctpIncomingSsnResetRequestParameter_Base::setStreamNumbers(size_t k, uint16_t streamNumbers)
{
    if (k >= streamNumbers_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->streamNumbers[k] = streamNumbers;
}

void SctpIncomingSsnResetRequestParameter_Base::insertStreamNumbers(size_t k, uint16_t streamNumbers)
{
    if (k > streamNumbers_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = streamNumbers_arraysize + 1;
    uint16_t *streamNumbers2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        streamNumbers2[i] = this->streamNumbers[i];
    streamNumbers2[k] = streamNumbers;
    for (i = k + 1; i < newSize; i++)
        streamNumbers2[i] = this->streamNumbers[i-1];
    delete [] this->streamNumbers;
    this->streamNumbers = streamNumbers2;
    streamNumbers_arraysize = newSize;
}

void SctpIncomingSsnResetRequestParameter_Base::insertStreamNumbers(uint16_t streamNumbers)
{
    insertStreamNumbers(streamNumbers_arraysize, streamNumbers);
}

void SctpIncomingSsnResetRequestParameter_Base::eraseStreamNumbers(size_t k)
{
    if (k >= streamNumbers_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = streamNumbers_arraysize - 1;
    uint16_t *streamNumbers2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        streamNumbers2[i] = this->streamNumbers[i];
    for (i = k; i < newSize; i++)
        streamNumbers2[i] = this->streamNumbers[i+1];
    delete [] this->streamNumbers;
    this->streamNumbers = streamNumbers2;
    streamNumbers_arraysize = newSize;
}

class SctpIncomingSsnResetRequestParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_srReqSn,
        FIELD_streamNumbers,
    };
  public:
    SctpIncomingSsnResetRequestParameterDescriptor();
    virtual ~SctpIncomingSsnResetRequestParameterDescriptor();

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

Register_ClassDescriptor(SctpIncomingSsnResetRequestParameterDescriptor)

SctpIncomingSsnResetRequestParameterDescriptor::SctpIncomingSsnResetRequestParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SctpIncomingSsnResetRequestParameter", "inet::sctp::SctpParameter")
{
    propertynames = nullptr;
}

SctpIncomingSsnResetRequestParameterDescriptor::~SctpIncomingSsnResetRequestParameterDescriptor()
{
    delete[] propertynames;
}

bool SctpIncomingSsnResetRequestParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpIncomingSsnResetRequestParameter_Base *>(obj)!=nullptr;
}

const char **SctpIncomingSsnResetRequestParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpIncomingSsnResetRequestParameterDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "customize")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpIncomingSsnResetRequestParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SctpIncomingSsnResetRequestParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srReqSn
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_streamNumbers
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *SctpIncomingSsnResetRequestParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srReqSn",
        "streamNumbers",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int SctpIncomingSsnResetRequestParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "srReqSn") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "streamNumbers") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpIncomingSsnResetRequestParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_srReqSn
        "uint16",    // FIELD_streamNumbers
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpIncomingSsnResetRequestParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpIncomingSsnResetRequestParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpIncomingSsnResetRequestParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpIncomingSsnResetRequestParameter_Base *pp = (SctpIncomingSsnResetRequestParameter_Base *)object; (void)pp;
    switch (field) {
        case FIELD_streamNumbers: return pp->getStreamNumbersArraySize();
        default: return 0;
    }
}

const char *SctpIncomingSsnResetRequestParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpIncomingSsnResetRequestParameter_Base *pp = (SctpIncomingSsnResetRequestParameter_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpIncomingSsnResetRequestParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpIncomingSsnResetRequestParameter_Base *pp = (SctpIncomingSsnResetRequestParameter_Base *)object; (void)pp;
    switch (field) {
        case FIELD_srReqSn: return ulong2string(pp->getSrReqSn());
        case FIELD_streamNumbers: return ulong2string(pp->getStreamNumbers(i));
        default: return "";
    }
}

bool SctpIncomingSsnResetRequestParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpIncomingSsnResetRequestParameter_Base *pp = (SctpIncomingSsnResetRequestParameter_Base *)object; (void)pp;
    switch (field) {
        case FIELD_srReqSn: pp->setSrReqSn(string2ulong(value)); return true;
        case FIELD_streamNumbers: pp->setStreamNumbers(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpIncomingSsnResetRequestParameterDescriptor::getFieldStructName(int field) const
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

void *SctpIncomingSsnResetRequestParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpIncomingSsnResetRequestParameter_Base *pp = (SctpIncomingSsnResetRequestParameter_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpSsnTsnResetRequestParameter)

SctpSsnTsnResetRequestParameter::SctpSsnTsnResetRequestParameter(const char *name) : ::inet::sctp::SctpParameter(name)
{
}

SctpSsnTsnResetRequestParameter::SctpSsnTsnResetRequestParameter(const SctpSsnTsnResetRequestParameter& other) : ::inet::sctp::SctpParameter(other)
{
    copy(other);
}

SctpSsnTsnResetRequestParameter::~SctpSsnTsnResetRequestParameter()
{
}

SctpSsnTsnResetRequestParameter& SctpSsnTsnResetRequestParameter::operator=(const SctpSsnTsnResetRequestParameter& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpParameter::operator=(other);
    copy(other);
    return *this;
}

void SctpSsnTsnResetRequestParameter::copy(const SctpSsnTsnResetRequestParameter& other)
{
    this->srReqSn = other.srReqSn;
}

void SctpSsnTsnResetRequestParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpParameter::parsimPack(b);
    doParsimPacking(b,this->srReqSn);
}

void SctpSsnTsnResetRequestParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->srReqSn);
}

uint32_t SctpSsnTsnResetRequestParameter::getSrReqSn() const
{
    return this->srReqSn;
}

void SctpSsnTsnResetRequestParameter::setSrReqSn(uint32_t srReqSn)
{
    this->srReqSn = srReqSn;
}

class SctpSsnTsnResetRequestParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_srReqSn,
    };
  public:
    SctpSsnTsnResetRequestParameterDescriptor();
    virtual ~SctpSsnTsnResetRequestParameterDescriptor();

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

Register_ClassDescriptor(SctpSsnTsnResetRequestParameterDescriptor)

SctpSsnTsnResetRequestParameterDescriptor::SctpSsnTsnResetRequestParameterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpSsnTsnResetRequestParameter)), "inet::sctp::SctpParameter")
{
    propertynames = nullptr;
}

SctpSsnTsnResetRequestParameterDescriptor::~SctpSsnTsnResetRequestParameterDescriptor()
{
    delete[] propertynames;
}

bool SctpSsnTsnResetRequestParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpSsnTsnResetRequestParameter *>(obj)!=nullptr;
}

const char **SctpSsnTsnResetRequestParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpSsnTsnResetRequestParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpSsnTsnResetRequestParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SctpSsnTsnResetRequestParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srReqSn
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SctpSsnTsnResetRequestParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srReqSn",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SctpSsnTsnResetRequestParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "srReqSn") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpSsnTsnResetRequestParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_srReqSn
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpSsnTsnResetRequestParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpSsnTsnResetRequestParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpSsnTsnResetRequestParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpSsnTsnResetRequestParameter *pp = (SctpSsnTsnResetRequestParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpSsnTsnResetRequestParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSsnTsnResetRequestParameter *pp = (SctpSsnTsnResetRequestParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpSsnTsnResetRequestParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSsnTsnResetRequestParameter *pp = (SctpSsnTsnResetRequestParameter *)object; (void)pp;
    switch (field) {
        case FIELD_srReqSn: return ulong2string(pp->getSrReqSn());
        default: return "";
    }
}

bool SctpSsnTsnResetRequestParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpSsnTsnResetRequestParameter *pp = (SctpSsnTsnResetRequestParameter *)object; (void)pp;
    switch (field) {
        case FIELD_srReqSn: pp->setSrReqSn(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpSsnTsnResetRequestParameterDescriptor::getFieldStructName(int field) const
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

void *SctpSsnTsnResetRequestParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpSsnTsnResetRequestParameter *pp = (SctpSsnTsnResetRequestParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpStreamResetResponseParameter)

SctpStreamResetResponseParameter::SctpStreamResetResponseParameter(const char *name) : ::inet::sctp::SctpParameter(name)
{
}

SctpStreamResetResponseParameter::SctpStreamResetResponseParameter(const SctpStreamResetResponseParameter& other) : ::inet::sctp::SctpParameter(other)
{
    copy(other);
}

SctpStreamResetResponseParameter::~SctpStreamResetResponseParameter()
{
}

SctpStreamResetResponseParameter& SctpStreamResetResponseParameter::operator=(const SctpStreamResetResponseParameter& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpParameter::operator=(other);
    copy(other);
    return *this;
}

void SctpStreamResetResponseParameter::copy(const SctpStreamResetResponseParameter& other)
{
    this->srResSn = other.srResSn;
    this->result = other.result;
    this->sendersNextTsn = other.sendersNextTsn;
    this->receiversNextTsn = other.receiversNextTsn;
}

void SctpStreamResetResponseParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpParameter::parsimPack(b);
    doParsimPacking(b,this->srResSn);
    doParsimPacking(b,this->result);
    doParsimPacking(b,this->sendersNextTsn);
    doParsimPacking(b,this->receiversNextTsn);
}

void SctpStreamResetResponseParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->srResSn);
    doParsimUnpacking(b,this->result);
    doParsimUnpacking(b,this->sendersNextTsn);
    doParsimUnpacking(b,this->receiversNextTsn);
}

uint32_t SctpStreamResetResponseParameter::getSrResSn() const
{
    return this->srResSn;
}

void SctpStreamResetResponseParameter::setSrResSn(uint32_t srResSn)
{
    this->srResSn = srResSn;
}

uint32_t SctpStreamResetResponseParameter::getResult() const
{
    return this->result;
}

void SctpStreamResetResponseParameter::setResult(uint32_t result)
{
    this->result = result;
}

uint32_t SctpStreamResetResponseParameter::getSendersNextTsn() const
{
    return this->sendersNextTsn;
}

void SctpStreamResetResponseParameter::setSendersNextTsn(uint32_t sendersNextTsn)
{
    this->sendersNextTsn = sendersNextTsn;
}

uint32_t SctpStreamResetResponseParameter::getReceiversNextTsn() const
{
    return this->receiversNextTsn;
}

void SctpStreamResetResponseParameter::setReceiversNextTsn(uint32_t receiversNextTsn)
{
    this->receiversNextTsn = receiversNextTsn;
}

class SctpStreamResetResponseParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_srResSn,
        FIELD_result,
        FIELD_sendersNextTsn,
        FIELD_receiversNextTsn,
    };
  public:
    SctpStreamResetResponseParameterDescriptor();
    virtual ~SctpStreamResetResponseParameterDescriptor();

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

Register_ClassDescriptor(SctpStreamResetResponseParameterDescriptor)

SctpStreamResetResponseParameterDescriptor::SctpStreamResetResponseParameterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpStreamResetResponseParameter)), "inet::sctp::SctpParameter")
{
    propertynames = nullptr;
}

SctpStreamResetResponseParameterDescriptor::~SctpStreamResetResponseParameterDescriptor()
{
    delete[] propertynames;
}

bool SctpStreamResetResponseParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpStreamResetResponseParameter *>(obj)!=nullptr;
}

const char **SctpStreamResetResponseParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpStreamResetResponseParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpStreamResetResponseParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SctpStreamResetResponseParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srResSn
        FD_ISEDITABLE,    // FIELD_result
        FD_ISEDITABLE,    // FIELD_sendersNextTsn
        FD_ISEDITABLE,    // FIELD_receiversNextTsn
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SctpStreamResetResponseParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srResSn",
        "result",
        "sendersNextTsn",
        "receiversNextTsn",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SctpStreamResetResponseParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "srResSn") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "result") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "sendersNextTsn") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "receiversNextTsn") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpStreamResetResponseParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_srResSn
        "uint32",    // FIELD_result
        "uint32",    // FIELD_sendersNextTsn
        "uint32",    // FIELD_receiversNextTsn
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpStreamResetResponseParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpStreamResetResponseParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpStreamResetResponseParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpStreamResetResponseParameter *pp = (SctpStreamResetResponseParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpStreamResetResponseParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpStreamResetResponseParameter *pp = (SctpStreamResetResponseParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpStreamResetResponseParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpStreamResetResponseParameter *pp = (SctpStreamResetResponseParameter *)object; (void)pp;
    switch (field) {
        case FIELD_srResSn: return ulong2string(pp->getSrResSn());
        case FIELD_result: return ulong2string(pp->getResult());
        case FIELD_sendersNextTsn: return ulong2string(pp->getSendersNextTsn());
        case FIELD_receiversNextTsn: return ulong2string(pp->getReceiversNextTsn());
        default: return "";
    }
}

bool SctpStreamResetResponseParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpStreamResetResponseParameter *pp = (SctpStreamResetResponseParameter *)object; (void)pp;
    switch (field) {
        case FIELD_srResSn: pp->setSrResSn(string2ulong(value)); return true;
        case FIELD_result: pp->setResult(string2ulong(value)); return true;
        case FIELD_sendersNextTsn: pp->setSendersNextTsn(string2ulong(value)); return true;
        case FIELD_receiversNextTsn: pp->setReceiversNextTsn(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpStreamResetResponseParameterDescriptor::getFieldStructName(int field) const
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

void *SctpStreamResetResponseParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpStreamResetResponseParameter *pp = (SctpStreamResetResponseParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpAddStreamsRequestParameter)

SctpAddStreamsRequestParameter::SctpAddStreamsRequestParameter(const char *name) : ::inet::sctp::SctpParameter(name)
{
}

SctpAddStreamsRequestParameter::SctpAddStreamsRequestParameter(const SctpAddStreamsRequestParameter& other) : ::inet::sctp::SctpParameter(other)
{
    copy(other);
}

SctpAddStreamsRequestParameter::~SctpAddStreamsRequestParameter()
{
}

SctpAddStreamsRequestParameter& SctpAddStreamsRequestParameter::operator=(const SctpAddStreamsRequestParameter& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpParameter::operator=(other);
    copy(other);
    return *this;
}

void SctpAddStreamsRequestParameter::copy(const SctpAddStreamsRequestParameter& other)
{
    this->srReqSn = other.srReqSn;
    this->numberOfStreams = other.numberOfStreams;
    this->reserved = other.reserved;
}

void SctpAddStreamsRequestParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpParameter::parsimPack(b);
    doParsimPacking(b,this->srReqSn);
    doParsimPacking(b,this->numberOfStreams);
    doParsimPacking(b,this->reserved);
}

void SctpAddStreamsRequestParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->srReqSn);
    doParsimUnpacking(b,this->numberOfStreams);
    doParsimUnpacking(b,this->reserved);
}

uint32_t SctpAddStreamsRequestParameter::getSrReqSn() const
{
    return this->srReqSn;
}

void SctpAddStreamsRequestParameter::setSrReqSn(uint32_t srReqSn)
{
    this->srReqSn = srReqSn;
}

uint16_t SctpAddStreamsRequestParameter::getNumberOfStreams() const
{
    return this->numberOfStreams;
}

void SctpAddStreamsRequestParameter::setNumberOfStreams(uint16_t numberOfStreams)
{
    this->numberOfStreams = numberOfStreams;
}

uint16_t SctpAddStreamsRequestParameter::getReserved() const
{
    return this->reserved;
}

void SctpAddStreamsRequestParameter::setReserved(uint16_t reserved)
{
    this->reserved = reserved;
}

class SctpAddStreamsRequestParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_srReqSn,
        FIELD_numberOfStreams,
        FIELD_reserved,
    };
  public:
    SctpAddStreamsRequestParameterDescriptor();
    virtual ~SctpAddStreamsRequestParameterDescriptor();

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

Register_ClassDescriptor(SctpAddStreamsRequestParameterDescriptor)

SctpAddStreamsRequestParameterDescriptor::SctpAddStreamsRequestParameterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpAddStreamsRequestParameter)), "inet::sctp::SctpParameter")
{
    propertynames = nullptr;
}

SctpAddStreamsRequestParameterDescriptor::~SctpAddStreamsRequestParameterDescriptor()
{
    delete[] propertynames;
}

bool SctpAddStreamsRequestParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpAddStreamsRequestParameter *>(obj)!=nullptr;
}

const char **SctpAddStreamsRequestParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpAddStreamsRequestParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpAddStreamsRequestParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SctpAddStreamsRequestParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srReqSn
        FD_ISEDITABLE,    // FIELD_numberOfStreams
        FD_ISEDITABLE,    // FIELD_reserved
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SctpAddStreamsRequestParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srReqSn",
        "numberOfStreams",
        "reserved",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SctpAddStreamsRequestParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "srReqSn") == 0) return base+0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numberOfStreams") == 0) return base+1;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpAddStreamsRequestParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_srReqSn
        "uint16",    // FIELD_numberOfStreams
        "uint16",    // FIELD_reserved
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpAddStreamsRequestParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpAddStreamsRequestParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpAddStreamsRequestParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpAddStreamsRequestParameter *pp = (SctpAddStreamsRequestParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpAddStreamsRequestParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAddStreamsRequestParameter *pp = (SctpAddStreamsRequestParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpAddStreamsRequestParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAddStreamsRequestParameter *pp = (SctpAddStreamsRequestParameter *)object; (void)pp;
    switch (field) {
        case FIELD_srReqSn: return ulong2string(pp->getSrReqSn());
        case FIELD_numberOfStreams: return ulong2string(pp->getNumberOfStreams());
        case FIELD_reserved: return ulong2string(pp->getReserved());
        default: return "";
    }
}

bool SctpAddStreamsRequestParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpAddStreamsRequestParameter *pp = (SctpAddStreamsRequestParameter *)object; (void)pp;
    switch (field) {
        case FIELD_srReqSn: pp->setSrReqSn(string2ulong(value)); return true;
        case FIELD_numberOfStreams: pp->setNumberOfStreams(string2ulong(value)); return true;
        case FIELD_reserved: pp->setReserved(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpAddStreamsRequestParameterDescriptor::getFieldStructName(int field) const
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

void *SctpAddStreamsRequestParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpAddStreamsRequestParameter *pp = (SctpAddStreamsRequestParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpResetTimer)

SctpResetTimer::SctpResetTimer(const char *name) : ::omnetpp::cPacket(name)
{
}

SctpResetTimer::SctpResetTimer(const SctpResetTimer& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SctpResetTimer::~SctpResetTimer()
{
}

SctpResetTimer& SctpResetTimer::operator=(const SctpResetTimer& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SctpResetTimer::copy(const SctpResetTimer& other)
{
    this->inSN = other.inSN;
    this->inAcked = other.inAcked;
    this->outSN = other.outSN;
    this->outAcked = other.outAcked;
}

void SctpResetTimer::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->inSN);
    doParsimPacking(b,this->inAcked);
    doParsimPacking(b,this->outSN);
    doParsimPacking(b,this->outAcked);
}

void SctpResetTimer::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->inSN);
    doParsimUnpacking(b,this->inAcked);
    doParsimUnpacking(b,this->outSN);
    doParsimUnpacking(b,this->outAcked);
}

uint32_t SctpResetTimer::getInSN() const
{
    return this->inSN;
}

void SctpResetTimer::setInSN(uint32_t inSN)
{
    this->inSN = inSN;
}

bool SctpResetTimer::getInAcked() const
{
    return this->inAcked;
}

void SctpResetTimer::setInAcked(bool inAcked)
{
    this->inAcked = inAcked;
}

uint32_t SctpResetTimer::getOutSN() const
{
    return this->outSN;
}

void SctpResetTimer::setOutSN(uint32_t outSN)
{
    this->outSN = outSN;
}

bool SctpResetTimer::getOutAcked() const
{
    return this->outAcked;
}

void SctpResetTimer::setOutAcked(bool outAcked)
{
    this->outAcked = outAcked;
}

class SctpResetTimerDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_inSN,
        FIELD_inAcked,
        FIELD_outSN,
        FIELD_outAcked,
    };
  public:
    SctpResetTimerDescriptor();
    virtual ~SctpResetTimerDescriptor();

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

Register_ClassDescriptor(SctpResetTimerDescriptor)

SctpResetTimerDescriptor::SctpResetTimerDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpResetTimer)), "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SctpResetTimerDescriptor::~SctpResetTimerDescriptor()
{
    delete[] propertynames;
}

bool SctpResetTimerDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpResetTimer *>(obj)!=nullptr;
}

const char **SctpResetTimerDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpResetTimerDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpResetTimerDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SctpResetTimerDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_inSN
        FD_ISEDITABLE,    // FIELD_inAcked
        FD_ISEDITABLE,    // FIELD_outSN
        FD_ISEDITABLE,    // FIELD_outAcked
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SctpResetTimerDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "inSN",
        "inAcked",
        "outSN",
        "outAcked",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SctpResetTimerDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "inSN") == 0) return base+0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "inAcked") == 0) return base+1;
    if (fieldName[0] == 'o' && strcmp(fieldName, "outSN") == 0) return base+2;
    if (fieldName[0] == 'o' && strcmp(fieldName, "outAcked") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpResetTimerDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_inSN
        "bool",    // FIELD_inAcked
        "uint32",    // FIELD_outSN
        "bool",    // FIELD_outAcked
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpResetTimerDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpResetTimerDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpResetTimerDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpResetTimer *pp = (SctpResetTimer *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpResetTimerDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpResetTimer *pp = (SctpResetTimer *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpResetTimerDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpResetTimer *pp = (SctpResetTimer *)object; (void)pp;
    switch (field) {
        case FIELD_inSN: return ulong2string(pp->getInSN());
        case FIELD_inAcked: return bool2string(pp->getInAcked());
        case FIELD_outSN: return ulong2string(pp->getOutSN());
        case FIELD_outAcked: return bool2string(pp->getOutAcked());
        default: return "";
    }
}

bool SctpResetTimerDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpResetTimer *pp = (SctpResetTimer *)object; (void)pp;
    switch (field) {
        case FIELD_inSN: pp->setInSN(string2ulong(value)); return true;
        case FIELD_inAcked: pp->setInAcked(string2bool(value)); return true;
        case FIELD_outSN: pp->setOutSN(string2ulong(value)); return true;
        case FIELD_outAcked: pp->setOutAcked(string2bool(value)); return true;
        default: return false;
    }
}

const char *SctpResetTimerDescriptor::getFieldStructName(int field) const
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

void *SctpResetTimerDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpResetTimer *pp = (SctpResetTimer *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpAuthenticationChunk)

SctpAuthenticationChunk::SctpAuthenticationChunk(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpAuthenticationChunk::SctpAuthenticationChunk(const SctpAuthenticationChunk& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpAuthenticationChunk::~SctpAuthenticationChunk()
{
    delete [] this->HMAC;
}

SctpAuthenticationChunk& SctpAuthenticationChunk::operator=(const SctpAuthenticationChunk& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpAuthenticationChunk::copy(const SctpAuthenticationChunk& other)
{
    this->sharedKey = other.sharedKey;
    this->hMacIdentifier = other.hMacIdentifier;
    this->hMacOk = other.hMacOk;
    delete [] this->HMAC;
    this->HMAC = (other.HMAC_arraysize==0) ? nullptr : new uint32_t[other.HMAC_arraysize];
    HMAC_arraysize = other.HMAC_arraysize;
    for (size_t i = 0; i < HMAC_arraysize; i++) {
        this->HMAC[i] = other.HMAC[i];
    }
}

void SctpAuthenticationChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->sharedKey);
    doParsimPacking(b,this->hMacIdentifier);
    doParsimPacking(b,this->hMacOk);
    b->pack(HMAC_arraysize);
    doParsimArrayPacking(b,this->HMAC,HMAC_arraysize);
}

void SctpAuthenticationChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->sharedKey);
    doParsimUnpacking(b,this->hMacIdentifier);
    doParsimUnpacking(b,this->hMacOk);
    delete [] this->HMAC;
    b->unpack(HMAC_arraysize);
    if (HMAC_arraysize == 0) {
        this->HMAC = nullptr;
    } else {
        this->HMAC = new uint32_t[HMAC_arraysize];
        doParsimArrayUnpacking(b,this->HMAC,HMAC_arraysize);
    }
}

uint16_t SctpAuthenticationChunk::getSharedKey() const
{
    return this->sharedKey;
}

void SctpAuthenticationChunk::setSharedKey(uint16_t sharedKey)
{
    this->sharedKey = sharedKey;
}

uint16_t SctpAuthenticationChunk::getHMacIdentifier() const
{
    return this->hMacIdentifier;
}

void SctpAuthenticationChunk::setHMacIdentifier(uint16_t hMacIdentifier)
{
    this->hMacIdentifier = hMacIdentifier;
}

bool SctpAuthenticationChunk::getHMacOk() const
{
    return this->hMacOk;
}

void SctpAuthenticationChunk::setHMacOk(bool hMacOk)
{
    this->hMacOk = hMacOk;
}

size_t SctpAuthenticationChunk::getHMACArraySize() const
{
    return HMAC_arraysize;
}

uint32_t SctpAuthenticationChunk::getHMAC(size_t k) const
{
    if (k >= HMAC_arraysize) throw omnetpp::cRuntimeError("Array of size HMAC_arraysize indexed by %lu", (unsigned long)k);
    return this->HMAC[k];
}

void SctpAuthenticationChunk::setHMACArraySize(size_t newSize)
{
    uint32_t *HMAC2 = (newSize==0) ? nullptr : new uint32_t[newSize];
    size_t minSize = HMAC_arraysize < newSize ? HMAC_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        HMAC2[i] = this->HMAC[i];
    for (size_t i = minSize; i < newSize; i++)
        HMAC2[i] = 0;
    delete [] this->HMAC;
    this->HMAC = HMAC2;
    HMAC_arraysize = newSize;
}

void SctpAuthenticationChunk::setHMAC(size_t k, uint32_t HMAC)
{
    if (k >= HMAC_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->HMAC[k] = HMAC;
}

void SctpAuthenticationChunk::insertHMAC(size_t k, uint32_t HMAC)
{
    if (k > HMAC_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = HMAC_arraysize + 1;
    uint32_t *HMAC2 = new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        HMAC2[i] = this->HMAC[i];
    HMAC2[k] = HMAC;
    for (i = k + 1; i < newSize; i++)
        HMAC2[i] = this->HMAC[i-1];
    delete [] this->HMAC;
    this->HMAC = HMAC2;
    HMAC_arraysize = newSize;
}

void SctpAuthenticationChunk::insertHMAC(uint32_t HMAC)
{
    insertHMAC(HMAC_arraysize, HMAC);
}

void SctpAuthenticationChunk::eraseHMAC(size_t k)
{
    if (k >= HMAC_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = HMAC_arraysize - 1;
    uint32_t *HMAC2 = (newSize == 0) ? nullptr : new uint32_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        HMAC2[i] = this->HMAC[i];
    for (i = k; i < newSize; i++)
        HMAC2[i] = this->HMAC[i+1];
    delete [] this->HMAC;
    this->HMAC = HMAC2;
    HMAC_arraysize = newSize;
}

class SctpAuthenticationChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_sharedKey,
        FIELD_hMacIdentifier,
        FIELD_hMacOk,
        FIELD_HMAC,
    };
  public:
    SctpAuthenticationChunkDescriptor();
    virtual ~SctpAuthenticationChunkDescriptor();

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

Register_ClassDescriptor(SctpAuthenticationChunkDescriptor)

SctpAuthenticationChunkDescriptor::SctpAuthenticationChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpAuthenticationChunk)), "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpAuthenticationChunkDescriptor::~SctpAuthenticationChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpAuthenticationChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpAuthenticationChunk *>(obj)!=nullptr;
}

const char **SctpAuthenticationChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpAuthenticationChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpAuthenticationChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SctpAuthenticationChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sharedKey
        FD_ISEDITABLE,    // FIELD_hMacIdentifier
        FD_ISEDITABLE,    // FIELD_hMacOk
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_HMAC
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SctpAuthenticationChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sharedKey",
        "hMacIdentifier",
        "hMacOk",
        "HMAC",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SctpAuthenticationChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sharedKey") == 0) return base+0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hMacIdentifier") == 0) return base+1;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hMacOk") == 0) return base+2;
    if (fieldName[0] == 'H' && strcmp(fieldName, "HMAC") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpAuthenticationChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",    // FIELD_sharedKey
        "uint16",    // FIELD_hMacIdentifier
        "bool",    // FIELD_hMacOk
        "uint32",    // FIELD_HMAC
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpAuthenticationChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpAuthenticationChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpAuthenticationChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpAuthenticationChunk *pp = (SctpAuthenticationChunk *)object; (void)pp;
    switch (field) {
        case FIELD_HMAC: return pp->getHMACArraySize();
        default: return 0;
    }
}

const char *SctpAuthenticationChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAuthenticationChunk *pp = (SctpAuthenticationChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpAuthenticationChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAuthenticationChunk *pp = (SctpAuthenticationChunk *)object; (void)pp;
    switch (field) {
        case FIELD_sharedKey: return ulong2string(pp->getSharedKey());
        case FIELD_hMacIdentifier: return ulong2string(pp->getHMacIdentifier());
        case FIELD_hMacOk: return bool2string(pp->getHMacOk());
        case FIELD_HMAC: return ulong2string(pp->getHMAC(i));
        default: return "";
    }
}

bool SctpAuthenticationChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpAuthenticationChunk *pp = (SctpAuthenticationChunk *)object; (void)pp;
    switch (field) {
        case FIELD_sharedKey: pp->setSharedKey(string2ulong(value)); return true;
        case FIELD_hMacIdentifier: pp->setHMacIdentifier(string2ulong(value)); return true;
        case FIELD_hMacOk: pp->setHMacOk(string2bool(value)); return true;
        case FIELD_HMAC: pp->setHMAC(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpAuthenticationChunkDescriptor::getFieldStructName(int field) const
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

void *SctpAuthenticationChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpAuthenticationChunk *pp = (SctpAuthenticationChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

SctpAsconfChunk_Base::SctpAsconfChunk_Base(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpAsconfChunk_Base::SctpAsconfChunk_Base(const SctpAsconfChunk_Base& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpAsconfChunk_Base::~SctpAsconfChunk_Base()
{
}

SctpAsconfChunk_Base& SctpAsconfChunk_Base::operator=(const SctpAsconfChunk_Base& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpAsconfChunk_Base::copy(const SctpAsconfChunk_Base& other)
{
    this->serialNumber = other.serialNumber;
    this->addressParam = other.addressParam;
    this->peerVTag = other.peerVTag;
}

void SctpAsconfChunk_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->serialNumber);
    doParsimPacking(b,this->addressParam);
    doParsimPacking(b,this->peerVTag);
    // field asconfParams is abstract -- please do packing in customized class
}

void SctpAsconfChunk_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->serialNumber);
    doParsimUnpacking(b,this->addressParam);
    doParsimUnpacking(b,this->peerVTag);
    // field asconfParams is abstract -- please do unpacking in customized class
}

uint32_t SctpAsconfChunk_Base::getSerialNumber() const
{
    return this->serialNumber;
}

void SctpAsconfChunk_Base::setSerialNumber(uint32_t serialNumber)
{
    this->serialNumber = serialNumber;
}

const L3Address& SctpAsconfChunk_Base::getAddressParam() const
{
    return this->addressParam;
}

void SctpAsconfChunk_Base::setAddressParam(const L3Address& addressParam)
{
    this->addressParam = addressParam;
}

uint32_t SctpAsconfChunk_Base::getPeerVTag() const
{
    return this->peerVTag;
}

void SctpAsconfChunk_Base::setPeerVTag(uint32_t peerVTag)
{
    this->peerVTag = peerVTag;
}

class SctpAsconfChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_serialNumber,
        FIELD_addressParam,
        FIELD_peerVTag,
        FIELD_asconfParams,
    };
  public:
    SctpAsconfChunkDescriptor();
    virtual ~SctpAsconfChunkDescriptor();

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

Register_ClassDescriptor(SctpAsconfChunkDescriptor)

SctpAsconfChunkDescriptor::SctpAsconfChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SctpAsconfChunk", "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpAsconfChunkDescriptor::~SctpAsconfChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpAsconfChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpAsconfChunk_Base *>(obj)!=nullptr;
}

const char **SctpAsconfChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpAsconfChunkDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "customize")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpAsconfChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SctpAsconfChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_serialNumber
        0,    // FIELD_addressParam
        FD_ISEDITABLE,    // FIELD_peerVTag
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_asconfParams
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SctpAsconfChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "serialNumber",
        "addressParam",
        "peerVTag",
        "asconfParams",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SctpAsconfChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "serialNumber") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "addressParam") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "peerVTag") == 0) return base+2;
    if (fieldName[0] == 'a' && strcmp(fieldName, "asconfParams") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpAsconfChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_serialNumber
        "inet::L3Address",    // FIELD_addressParam
        "uint32",    // FIELD_peerVTag
        "inet::sctp::SctpParameter",    // FIELD_asconfParams
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpAsconfChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpAsconfChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpAsconfChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpAsconfChunk_Base *pp = (SctpAsconfChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_asconfParams: return pp->getAsconfParamsArraySize();
        default: return 0;
    }
}

const char *SctpAsconfChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAsconfChunk_Base *pp = (SctpAsconfChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_asconfParams: { const SctpParameter * value = pp->getAsconfParams(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string SctpAsconfChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAsconfChunk_Base *pp = (SctpAsconfChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_serialNumber: return ulong2string(pp->getSerialNumber());
        case FIELD_addressParam: return pp->getAddressParam().str();
        case FIELD_peerVTag: return ulong2string(pp->getPeerVTag());
        case FIELD_asconfParams: {std::stringstream out; out << pp->getAsconfParams(i); return out.str();}
        default: return "";
    }
}

bool SctpAsconfChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpAsconfChunk_Base *pp = (SctpAsconfChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_serialNumber: pp->setSerialNumber(string2ulong(value)); return true;
        case FIELD_peerVTag: pp->setPeerVTag(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpAsconfChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_asconfParams: return omnetpp::opp_typename(typeid(SctpParameter));
        default: return nullptr;
    };
}

void *SctpAsconfChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpAsconfChunk_Base *pp = (SctpAsconfChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_addressParam: return toVoidPtr(&pp->getAddressParam()); break;
        case FIELD_asconfParams: return toVoidPtr(pp->getAsconfParams(i)); break;
        default: return nullptr;
    }
}

SctpAsconfAckChunk_Base::SctpAsconfAckChunk_Base(const char *name) : ::inet::sctp::SctpChunk(name)
{
}

SctpAsconfAckChunk_Base::SctpAsconfAckChunk_Base(const SctpAsconfAckChunk_Base& other) : ::inet::sctp::SctpChunk(other)
{
    copy(other);
}

SctpAsconfAckChunk_Base::~SctpAsconfAckChunk_Base()
{
}

SctpAsconfAckChunk_Base& SctpAsconfAckChunk_Base::operator=(const SctpAsconfAckChunk_Base& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpChunk::operator=(other);
    copy(other);
    return *this;
}

void SctpAsconfAckChunk_Base::copy(const SctpAsconfAckChunk_Base& other)
{
    this->serialNumber = other.serialNumber;
}

void SctpAsconfAckChunk_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpChunk::parsimPack(b);
    doParsimPacking(b,this->serialNumber);
    // field asconfResponse is abstract -- please do packing in customized class
}

void SctpAsconfAckChunk_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->serialNumber);
    // field asconfResponse is abstract -- please do unpacking in customized class
}

uint32_t SctpAsconfAckChunk_Base::getSerialNumber() const
{
    return this->serialNumber;
}

void SctpAsconfAckChunk_Base::setSerialNumber(uint32_t serialNumber)
{
    this->serialNumber = serialNumber;
}

class SctpAsconfAckChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_serialNumber,
        FIELD_asconfResponse,
    };
  public:
    SctpAsconfAckChunkDescriptor();
    virtual ~SctpAsconfAckChunkDescriptor();

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

Register_ClassDescriptor(SctpAsconfAckChunkDescriptor)

SctpAsconfAckChunkDescriptor::SctpAsconfAckChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SctpAsconfAckChunk", "inet::sctp::SctpChunk")
{
    propertynames = nullptr;
}

SctpAsconfAckChunkDescriptor::~SctpAsconfAckChunkDescriptor()
{
    delete[] propertynames;
}

bool SctpAsconfAckChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpAsconfAckChunk_Base *>(obj)!=nullptr;
}

const char **SctpAsconfAckChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpAsconfAckChunkDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "customize")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpAsconfAckChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SctpAsconfAckChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_serialNumber
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_asconfResponse
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *SctpAsconfAckChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "serialNumber",
        "asconfResponse",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int SctpAsconfAckChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "serialNumber") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "asconfResponse") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpAsconfAckChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_serialNumber
        "inet::sctp::SctpParameter",    // FIELD_asconfResponse
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpAsconfAckChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpAsconfAckChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpAsconfAckChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpAsconfAckChunk_Base *pp = (SctpAsconfAckChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_asconfResponse: return pp->getAsconfResponseArraySize();
        default: return 0;
    }
}

const char *SctpAsconfAckChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAsconfAckChunk_Base *pp = (SctpAsconfAckChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_asconfResponse: { const SctpParameter * value = pp->getAsconfResponse(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string SctpAsconfAckChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAsconfAckChunk_Base *pp = (SctpAsconfAckChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_serialNumber: return ulong2string(pp->getSerialNumber());
        case FIELD_asconfResponse: {std::stringstream out; out << pp->getAsconfResponse(i); return out.str();}
        default: return "";
    }
}

bool SctpAsconfAckChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpAsconfAckChunk_Base *pp = (SctpAsconfAckChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_serialNumber: pp->setSerialNumber(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpAsconfAckChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_asconfResponse: return omnetpp::opp_typename(typeid(SctpParameter));
        default: return nullptr;
    };
}

void *SctpAsconfAckChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpAsconfAckChunk_Base *pp = (SctpAsconfAckChunk_Base *)object; (void)pp;
    switch (field) {
        case FIELD_asconfResponse: return toVoidPtr(pp->getAsconfResponse(i)); break;
        default: return nullptr;
    }
}

Register_Class(SctpAddIPParameter)

SctpAddIPParameter::SctpAddIPParameter(const char *name) : ::inet::sctp::SctpParameter(name)
{
}

SctpAddIPParameter::SctpAddIPParameter(const SctpAddIPParameter& other) : ::inet::sctp::SctpParameter(other)
{
    copy(other);
}

SctpAddIPParameter::~SctpAddIPParameter()
{
}

SctpAddIPParameter& SctpAddIPParameter::operator=(const SctpAddIPParameter& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpParameter::operator=(other);
    copy(other);
    return *this;
}

void SctpAddIPParameter::copy(const SctpAddIPParameter& other)
{
    this->requestCorrelationId = other.requestCorrelationId;
    this->addressParam = other.addressParam;
}

void SctpAddIPParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpParameter::parsimPack(b);
    doParsimPacking(b,this->requestCorrelationId);
    doParsimPacking(b,this->addressParam);
}

void SctpAddIPParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->requestCorrelationId);
    doParsimUnpacking(b,this->addressParam);
}

uint32_t SctpAddIPParameter::getRequestCorrelationId() const
{
    return this->requestCorrelationId;
}

void SctpAddIPParameter::setRequestCorrelationId(uint32_t requestCorrelationId)
{
    this->requestCorrelationId = requestCorrelationId;
}

const L3Address& SctpAddIPParameter::getAddressParam() const
{
    return this->addressParam;
}

void SctpAddIPParameter::setAddressParam(const L3Address& addressParam)
{
    this->addressParam = addressParam;
}

class SctpAddIPParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_requestCorrelationId,
        FIELD_addressParam,
    };
  public:
    SctpAddIPParameterDescriptor();
    virtual ~SctpAddIPParameterDescriptor();

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

Register_ClassDescriptor(SctpAddIPParameterDescriptor)

SctpAddIPParameterDescriptor::SctpAddIPParameterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpAddIPParameter)), "inet::sctp::SctpParameter")
{
    propertynames = nullptr;
}

SctpAddIPParameterDescriptor::~SctpAddIPParameterDescriptor()
{
    delete[] propertynames;
}

bool SctpAddIPParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpAddIPParameter *>(obj)!=nullptr;
}

const char **SctpAddIPParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpAddIPParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpAddIPParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SctpAddIPParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_requestCorrelationId
        0,    // FIELD_addressParam
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *SctpAddIPParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "requestCorrelationId",
        "addressParam",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int SctpAddIPParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "requestCorrelationId") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "addressParam") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpAddIPParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_requestCorrelationId
        "inet::L3Address",    // FIELD_addressParam
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpAddIPParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpAddIPParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpAddIPParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpAddIPParameter *pp = (SctpAddIPParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpAddIPParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAddIPParameter *pp = (SctpAddIPParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpAddIPParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAddIPParameter *pp = (SctpAddIPParameter *)object; (void)pp;
    switch (field) {
        case FIELD_requestCorrelationId: return ulong2string(pp->getRequestCorrelationId());
        case FIELD_addressParam: return pp->getAddressParam().str();
        default: return "";
    }
}

bool SctpAddIPParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpAddIPParameter *pp = (SctpAddIPParameter *)object; (void)pp;
    switch (field) {
        case FIELD_requestCorrelationId: pp->setRequestCorrelationId(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpAddIPParameterDescriptor::getFieldStructName(int field) const
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

void *SctpAddIPParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpAddIPParameter *pp = (SctpAddIPParameter *)object; (void)pp;
    switch (field) {
        case FIELD_addressParam: return toVoidPtr(&pp->getAddressParam()); break;
        default: return nullptr;
    }
}

Register_Class(SctpDeleteIPParameter)

SctpDeleteIPParameter::SctpDeleteIPParameter(const char *name) : ::inet::sctp::SctpParameter(name)
{
}

SctpDeleteIPParameter::SctpDeleteIPParameter(const SctpDeleteIPParameter& other) : ::inet::sctp::SctpParameter(other)
{
    copy(other);
}

SctpDeleteIPParameter::~SctpDeleteIPParameter()
{
}

SctpDeleteIPParameter& SctpDeleteIPParameter::operator=(const SctpDeleteIPParameter& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpParameter::operator=(other);
    copy(other);
    return *this;
}

void SctpDeleteIPParameter::copy(const SctpDeleteIPParameter& other)
{
    this->requestCorrelationId = other.requestCorrelationId;
    this->addressParam = other.addressParam;
}

void SctpDeleteIPParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpParameter::parsimPack(b);
    doParsimPacking(b,this->requestCorrelationId);
    doParsimPacking(b,this->addressParam);
}

void SctpDeleteIPParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->requestCorrelationId);
    doParsimUnpacking(b,this->addressParam);
}

uint32_t SctpDeleteIPParameter::getRequestCorrelationId() const
{
    return this->requestCorrelationId;
}

void SctpDeleteIPParameter::setRequestCorrelationId(uint32_t requestCorrelationId)
{
    this->requestCorrelationId = requestCorrelationId;
}

const L3Address& SctpDeleteIPParameter::getAddressParam() const
{
    return this->addressParam;
}

void SctpDeleteIPParameter::setAddressParam(const L3Address& addressParam)
{
    this->addressParam = addressParam;
}

class SctpDeleteIPParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_requestCorrelationId,
        FIELD_addressParam,
    };
  public:
    SctpDeleteIPParameterDescriptor();
    virtual ~SctpDeleteIPParameterDescriptor();

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

Register_ClassDescriptor(SctpDeleteIPParameterDescriptor)

SctpDeleteIPParameterDescriptor::SctpDeleteIPParameterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpDeleteIPParameter)), "inet::sctp::SctpParameter")
{
    propertynames = nullptr;
}

SctpDeleteIPParameterDescriptor::~SctpDeleteIPParameterDescriptor()
{
    delete[] propertynames;
}

bool SctpDeleteIPParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpDeleteIPParameter *>(obj)!=nullptr;
}

const char **SctpDeleteIPParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpDeleteIPParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpDeleteIPParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SctpDeleteIPParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_requestCorrelationId
        0,    // FIELD_addressParam
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *SctpDeleteIPParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "requestCorrelationId",
        "addressParam",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int SctpDeleteIPParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "requestCorrelationId") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "addressParam") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpDeleteIPParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_requestCorrelationId
        "inet::L3Address",    // FIELD_addressParam
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpDeleteIPParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpDeleteIPParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpDeleteIPParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpDeleteIPParameter *pp = (SctpDeleteIPParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpDeleteIPParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpDeleteIPParameter *pp = (SctpDeleteIPParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpDeleteIPParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpDeleteIPParameter *pp = (SctpDeleteIPParameter *)object; (void)pp;
    switch (field) {
        case FIELD_requestCorrelationId: return ulong2string(pp->getRequestCorrelationId());
        case FIELD_addressParam: return pp->getAddressParam().str();
        default: return "";
    }
}

bool SctpDeleteIPParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpDeleteIPParameter *pp = (SctpDeleteIPParameter *)object; (void)pp;
    switch (field) {
        case FIELD_requestCorrelationId: pp->setRequestCorrelationId(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpDeleteIPParameterDescriptor::getFieldStructName(int field) const
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

void *SctpDeleteIPParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpDeleteIPParameter *pp = (SctpDeleteIPParameter *)object; (void)pp;
    switch (field) {
        case FIELD_addressParam: return toVoidPtr(&pp->getAddressParam()); break;
        default: return nullptr;
    }
}

Register_Class(SctpSetPrimaryIPParameter)

SctpSetPrimaryIPParameter::SctpSetPrimaryIPParameter(const char *name) : ::inet::sctp::SctpParameter(name)
{
}

SctpSetPrimaryIPParameter::SctpSetPrimaryIPParameter(const SctpSetPrimaryIPParameter& other) : ::inet::sctp::SctpParameter(other)
{
    copy(other);
}

SctpSetPrimaryIPParameter::~SctpSetPrimaryIPParameter()
{
}

SctpSetPrimaryIPParameter& SctpSetPrimaryIPParameter::operator=(const SctpSetPrimaryIPParameter& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpParameter::operator=(other);
    copy(other);
    return *this;
}

void SctpSetPrimaryIPParameter::copy(const SctpSetPrimaryIPParameter& other)
{
    this->requestCorrelationId = other.requestCorrelationId;
    this->addressParam = other.addressParam;
}

void SctpSetPrimaryIPParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpParameter::parsimPack(b);
    doParsimPacking(b,this->requestCorrelationId);
    doParsimPacking(b,this->addressParam);
}

void SctpSetPrimaryIPParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->requestCorrelationId);
    doParsimUnpacking(b,this->addressParam);
}

uint32_t SctpSetPrimaryIPParameter::getRequestCorrelationId() const
{
    return this->requestCorrelationId;
}

void SctpSetPrimaryIPParameter::setRequestCorrelationId(uint32_t requestCorrelationId)
{
    this->requestCorrelationId = requestCorrelationId;
}

const L3Address& SctpSetPrimaryIPParameter::getAddressParam() const
{
    return this->addressParam;
}

void SctpSetPrimaryIPParameter::setAddressParam(const L3Address& addressParam)
{
    this->addressParam = addressParam;
}

class SctpSetPrimaryIPParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_requestCorrelationId,
        FIELD_addressParam,
    };
  public:
    SctpSetPrimaryIPParameterDescriptor();
    virtual ~SctpSetPrimaryIPParameterDescriptor();

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

Register_ClassDescriptor(SctpSetPrimaryIPParameterDescriptor)

SctpSetPrimaryIPParameterDescriptor::SctpSetPrimaryIPParameterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpSetPrimaryIPParameter)), "inet::sctp::SctpParameter")
{
    propertynames = nullptr;
}

SctpSetPrimaryIPParameterDescriptor::~SctpSetPrimaryIPParameterDescriptor()
{
    delete[] propertynames;
}

bool SctpSetPrimaryIPParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpSetPrimaryIPParameter *>(obj)!=nullptr;
}

const char **SctpSetPrimaryIPParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpSetPrimaryIPParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpSetPrimaryIPParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SctpSetPrimaryIPParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_requestCorrelationId
        0,    // FIELD_addressParam
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *SctpSetPrimaryIPParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "requestCorrelationId",
        "addressParam",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int SctpSetPrimaryIPParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "requestCorrelationId") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "addressParam") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpSetPrimaryIPParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_requestCorrelationId
        "inet::L3Address",    // FIELD_addressParam
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpSetPrimaryIPParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpSetPrimaryIPParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpSetPrimaryIPParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpSetPrimaryIPParameter *pp = (SctpSetPrimaryIPParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpSetPrimaryIPParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSetPrimaryIPParameter *pp = (SctpSetPrimaryIPParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpSetPrimaryIPParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSetPrimaryIPParameter *pp = (SctpSetPrimaryIPParameter *)object; (void)pp;
    switch (field) {
        case FIELD_requestCorrelationId: return ulong2string(pp->getRequestCorrelationId());
        case FIELD_addressParam: return pp->getAddressParam().str();
        default: return "";
    }
}

bool SctpSetPrimaryIPParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpSetPrimaryIPParameter *pp = (SctpSetPrimaryIPParameter *)object; (void)pp;
    switch (field) {
        case FIELD_requestCorrelationId: pp->setRequestCorrelationId(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpSetPrimaryIPParameterDescriptor::getFieldStructName(int field) const
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

void *SctpSetPrimaryIPParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpSetPrimaryIPParameter *pp = (SctpSetPrimaryIPParameter *)object; (void)pp;
    switch (field) {
        case FIELD_addressParam: return toVoidPtr(&pp->getAddressParam()); break;
        default: return nullptr;
    }
}

Register_Class(SctpSupportedExtensionsParameter)

SctpSupportedExtensionsParameter::SctpSupportedExtensionsParameter(const char *name) : ::inet::sctp::SctpParameter(name)
{
}

SctpSupportedExtensionsParameter::SctpSupportedExtensionsParameter(const SctpSupportedExtensionsParameter& other) : ::inet::sctp::SctpParameter(other)
{
    copy(other);
}

SctpSupportedExtensionsParameter::~SctpSupportedExtensionsParameter()
{
    delete [] this->sctpChunkTypes;
}

SctpSupportedExtensionsParameter& SctpSupportedExtensionsParameter::operator=(const SctpSupportedExtensionsParameter& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpParameter::operator=(other);
    copy(other);
    return *this;
}

void SctpSupportedExtensionsParameter::copy(const SctpSupportedExtensionsParameter& other)
{
    delete [] this->sctpChunkTypes;
    this->sctpChunkTypes = (other.sctpChunkTypes_arraysize==0) ? nullptr : new uint16_t[other.sctpChunkTypes_arraysize];
    sctpChunkTypes_arraysize = other.sctpChunkTypes_arraysize;
    for (size_t i = 0; i < sctpChunkTypes_arraysize; i++) {
        this->sctpChunkTypes[i] = other.sctpChunkTypes[i];
    }
}

void SctpSupportedExtensionsParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpParameter::parsimPack(b);
    b->pack(sctpChunkTypes_arraysize);
    doParsimArrayPacking(b,this->sctpChunkTypes,sctpChunkTypes_arraysize);
}

void SctpSupportedExtensionsParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpParameter::parsimUnpack(b);
    delete [] this->sctpChunkTypes;
    b->unpack(sctpChunkTypes_arraysize);
    if (sctpChunkTypes_arraysize == 0) {
        this->sctpChunkTypes = nullptr;
    } else {
        this->sctpChunkTypes = new uint16_t[sctpChunkTypes_arraysize];
        doParsimArrayUnpacking(b,this->sctpChunkTypes,sctpChunkTypes_arraysize);
    }
}

size_t SctpSupportedExtensionsParameter::getSctpChunkTypesArraySize() const
{
    return sctpChunkTypes_arraysize;
}

uint16_t SctpSupportedExtensionsParameter::getSctpChunkTypes(size_t k) const
{
    if (k >= sctpChunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size sctpChunkTypes_arraysize indexed by %lu", (unsigned long)k);
    return this->sctpChunkTypes[k];
}

void SctpSupportedExtensionsParameter::setSctpChunkTypesArraySize(size_t newSize)
{
    uint16_t *sctpChunkTypes2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = sctpChunkTypes_arraysize < newSize ? sctpChunkTypes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i];
    for (size_t i = minSize; i < newSize; i++)
        sctpChunkTypes2[i] = 0;
    delete [] this->sctpChunkTypes;
    this->sctpChunkTypes = sctpChunkTypes2;
    sctpChunkTypes_arraysize = newSize;
}

void SctpSupportedExtensionsParameter::setSctpChunkTypes(size_t k, uint16_t sctpChunkTypes)
{
    if (k >= sctpChunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->sctpChunkTypes[k] = sctpChunkTypes;
}

void SctpSupportedExtensionsParameter::insertSctpChunkTypes(size_t k, uint16_t sctpChunkTypes)
{
    if (k > sctpChunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sctpChunkTypes_arraysize + 1;
    uint16_t *sctpChunkTypes2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i];
    sctpChunkTypes2[k] = sctpChunkTypes;
    for (i = k + 1; i < newSize; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i-1];
    delete [] this->sctpChunkTypes;
    this->sctpChunkTypes = sctpChunkTypes2;
    sctpChunkTypes_arraysize = newSize;
}

void SctpSupportedExtensionsParameter::insertSctpChunkTypes(uint16_t sctpChunkTypes)
{
    insertSctpChunkTypes(sctpChunkTypes_arraysize, sctpChunkTypes);
}

void SctpSupportedExtensionsParameter::eraseSctpChunkTypes(size_t k)
{
    if (k >= sctpChunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sctpChunkTypes_arraysize - 1;
    uint16_t *sctpChunkTypes2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i];
    for (i = k; i < newSize; i++)
        sctpChunkTypes2[i] = this->sctpChunkTypes[i+1];
    delete [] this->sctpChunkTypes;
    this->sctpChunkTypes = sctpChunkTypes2;
    sctpChunkTypes_arraysize = newSize;
}

class SctpSupportedExtensionsParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_sctpChunkTypes,
    };
  public:
    SctpSupportedExtensionsParameterDescriptor();
    virtual ~SctpSupportedExtensionsParameterDescriptor();

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

Register_ClassDescriptor(SctpSupportedExtensionsParameterDescriptor)

SctpSupportedExtensionsParameterDescriptor::SctpSupportedExtensionsParameterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpSupportedExtensionsParameter)), "inet::sctp::SctpParameter")
{
    propertynames = nullptr;
}

SctpSupportedExtensionsParameterDescriptor::~SctpSupportedExtensionsParameterDescriptor()
{
    delete[] propertynames;
}

bool SctpSupportedExtensionsParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpSupportedExtensionsParameter *>(obj)!=nullptr;
}

const char **SctpSupportedExtensionsParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpSupportedExtensionsParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpSupportedExtensionsParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SctpSupportedExtensionsParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_sctpChunkTypes
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SctpSupportedExtensionsParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sctpChunkTypes",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SctpSupportedExtensionsParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sctpChunkTypes") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpSupportedExtensionsParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",    // FIELD_sctpChunkTypes
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpSupportedExtensionsParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpSupportedExtensionsParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpSupportedExtensionsParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpSupportedExtensionsParameter *pp = (SctpSupportedExtensionsParameter *)object; (void)pp;
    switch (field) {
        case FIELD_sctpChunkTypes: return pp->getSctpChunkTypesArraySize();
        default: return 0;
    }
}

const char *SctpSupportedExtensionsParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSupportedExtensionsParameter *pp = (SctpSupportedExtensionsParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpSupportedExtensionsParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSupportedExtensionsParameter *pp = (SctpSupportedExtensionsParameter *)object; (void)pp;
    switch (field) {
        case FIELD_sctpChunkTypes: return ulong2string(pp->getSctpChunkTypes(i));
        default: return "";
    }
}

bool SctpSupportedExtensionsParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpSupportedExtensionsParameter *pp = (SctpSupportedExtensionsParameter *)object; (void)pp;
    switch (field) {
        case FIELD_sctpChunkTypes: pp->setSctpChunkTypes(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpSupportedExtensionsParameterDescriptor::getFieldStructName(int field) const
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

void *SctpSupportedExtensionsParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpSupportedExtensionsParameter *pp = (SctpSupportedExtensionsParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpErrorCauseParameter)

SctpErrorCauseParameter::SctpErrorCauseParameter(const char *name) : ::inet::sctp::SctpParameter(name)
{
}

SctpErrorCauseParameter::SctpErrorCauseParameter(const SctpErrorCauseParameter& other) : ::inet::sctp::SctpParameter(other)
{
    copy(other);
}

SctpErrorCauseParameter::~SctpErrorCauseParameter()
{
}

SctpErrorCauseParameter& SctpErrorCauseParameter::operator=(const SctpErrorCauseParameter& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpParameter::operator=(other);
    copy(other);
    return *this;
}

void SctpErrorCauseParameter::copy(const SctpErrorCauseParameter& other)
{
    this->responseCorrelationId = other.responseCorrelationId;
    this->errorCauseType = other.errorCauseType;
}

void SctpErrorCauseParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpParameter::parsimPack(b);
    doParsimPacking(b,this->responseCorrelationId);
    doParsimPacking(b,this->errorCauseType);
}

void SctpErrorCauseParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->responseCorrelationId);
    doParsimUnpacking(b,this->errorCauseType);
}

uint32_t SctpErrorCauseParameter::getResponseCorrelationId() const
{
    return this->responseCorrelationId;
}

void SctpErrorCauseParameter::setResponseCorrelationId(uint32_t responseCorrelationId)
{
    this->responseCorrelationId = responseCorrelationId;
}

uint32_t SctpErrorCauseParameter::getErrorCauseType() const
{
    return this->errorCauseType;
}

void SctpErrorCauseParameter::setErrorCauseType(uint32_t errorCauseType)
{
    this->errorCauseType = errorCauseType;
}

class SctpErrorCauseParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_responseCorrelationId,
        FIELD_errorCauseType,
    };
  public:
    SctpErrorCauseParameterDescriptor();
    virtual ~SctpErrorCauseParameterDescriptor();

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

Register_ClassDescriptor(SctpErrorCauseParameterDescriptor)

SctpErrorCauseParameterDescriptor::SctpErrorCauseParameterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpErrorCauseParameter)), "inet::sctp::SctpParameter")
{
    propertynames = nullptr;
}

SctpErrorCauseParameterDescriptor::~SctpErrorCauseParameterDescriptor()
{
    delete[] propertynames;
}

bool SctpErrorCauseParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpErrorCauseParameter *>(obj)!=nullptr;
}

const char **SctpErrorCauseParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpErrorCauseParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpErrorCauseParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SctpErrorCauseParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_responseCorrelationId
        FD_ISEDITABLE,    // FIELD_errorCauseType
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *SctpErrorCauseParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "responseCorrelationId",
        "errorCauseType",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int SctpErrorCauseParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "responseCorrelationId") == 0) return base+0;
    if (fieldName[0] == 'e' && strcmp(fieldName, "errorCauseType") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpErrorCauseParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_responseCorrelationId
        "uint32",    // FIELD_errorCauseType
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpErrorCauseParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpErrorCauseParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpErrorCauseParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpErrorCauseParameter *pp = (SctpErrorCauseParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpErrorCauseParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpErrorCauseParameter *pp = (SctpErrorCauseParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpErrorCauseParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpErrorCauseParameter *pp = (SctpErrorCauseParameter *)object; (void)pp;
    switch (field) {
        case FIELD_responseCorrelationId: return ulong2string(pp->getResponseCorrelationId());
        case FIELD_errorCauseType: return ulong2string(pp->getErrorCauseType());
        default: return "";
    }
}

bool SctpErrorCauseParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpErrorCauseParameter *pp = (SctpErrorCauseParameter *)object; (void)pp;
    switch (field) {
        case FIELD_responseCorrelationId: pp->setResponseCorrelationId(string2ulong(value)); return true;
        case FIELD_errorCauseType: pp->setErrorCauseType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpErrorCauseParameterDescriptor::getFieldStructName(int field) const
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

void *SctpErrorCauseParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpErrorCauseParameter *pp = (SctpErrorCauseParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpSimpleErrorCauseParameter)

SctpSimpleErrorCauseParameter::SctpSimpleErrorCauseParameter(const char *name) : ::inet::sctp::SctpParameter(name)
{
}

SctpSimpleErrorCauseParameter::SctpSimpleErrorCauseParameter(const SctpSimpleErrorCauseParameter& other) : ::inet::sctp::SctpParameter(other)
{
    copy(other);
}

SctpSimpleErrorCauseParameter::~SctpSimpleErrorCauseParameter()
{
}

SctpSimpleErrorCauseParameter& SctpSimpleErrorCauseParameter::operator=(const SctpSimpleErrorCauseParameter& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpParameter::operator=(other);
    copy(other);
    return *this;
}

void SctpSimpleErrorCauseParameter::copy(const SctpSimpleErrorCauseParameter& other)
{
    this->value = other.value;
}

void SctpSimpleErrorCauseParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpParameter::parsimPack(b);
    doParsimPacking(b,this->value);
}

void SctpSimpleErrorCauseParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

uint16_t SctpSimpleErrorCauseParameter::getValue() const
{
    return this->value;
}

void SctpSimpleErrorCauseParameter::setValue(uint16_t value)
{
    this->value = value;
}

class SctpSimpleErrorCauseParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_value,
    };
  public:
    SctpSimpleErrorCauseParameterDescriptor();
    virtual ~SctpSimpleErrorCauseParameterDescriptor();

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

Register_ClassDescriptor(SctpSimpleErrorCauseParameterDescriptor)

SctpSimpleErrorCauseParameterDescriptor::SctpSimpleErrorCauseParameterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpSimpleErrorCauseParameter)), "inet::sctp::SctpParameter")
{
    propertynames = nullptr;
}

SctpSimpleErrorCauseParameterDescriptor::~SctpSimpleErrorCauseParameterDescriptor()
{
    delete[] propertynames;
}

bool SctpSimpleErrorCauseParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpSimpleErrorCauseParameter *>(obj)!=nullptr;
}

const char **SctpSimpleErrorCauseParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpSimpleErrorCauseParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpSimpleErrorCauseParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SctpSimpleErrorCauseParameterDescriptor::getFieldTypeFlags(int field) const
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

const char *SctpSimpleErrorCauseParameterDescriptor::getFieldName(int field) const
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

int SctpSimpleErrorCauseParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "value") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpSimpleErrorCauseParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",    // FIELD_value
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpSimpleErrorCauseParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpSimpleErrorCauseParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpSimpleErrorCauseParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpSimpleErrorCauseParameter *pp = (SctpSimpleErrorCauseParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpSimpleErrorCauseParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSimpleErrorCauseParameter *pp = (SctpSimpleErrorCauseParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpSimpleErrorCauseParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSimpleErrorCauseParameter *pp = (SctpSimpleErrorCauseParameter *)object; (void)pp;
    switch (field) {
        case FIELD_value: return ulong2string(pp->getValue());
        default: return "";
    }
}

bool SctpSimpleErrorCauseParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpSimpleErrorCauseParameter *pp = (SctpSimpleErrorCauseParameter *)object; (void)pp;
    switch (field) {
        case FIELD_value: pp->setValue(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpSimpleErrorCauseParameterDescriptor::getFieldStructName(int field) const
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

void *SctpSimpleErrorCauseParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpSimpleErrorCauseParameter *pp = (SctpSimpleErrorCauseParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpSuccessIndication)

SctpSuccessIndication::SctpSuccessIndication(const char *name) : ::inet::sctp::SctpParameter(name)
{
}

SctpSuccessIndication::SctpSuccessIndication(const SctpSuccessIndication& other) : ::inet::sctp::SctpParameter(other)
{
    copy(other);
}

SctpSuccessIndication::~SctpSuccessIndication()
{
}

SctpSuccessIndication& SctpSuccessIndication::operator=(const SctpSuccessIndication& other)
{
    if (this == &other) return *this;
    ::inet::sctp::SctpParameter::operator=(other);
    copy(other);
    return *this;
}

void SctpSuccessIndication::copy(const SctpSuccessIndication& other)
{
    this->responseCorrelationId = other.responseCorrelationId;
}

void SctpSuccessIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SctpParameter::parsimPack(b);
    doParsimPacking(b,this->responseCorrelationId);
}

void SctpSuccessIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SctpParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->responseCorrelationId);
}

uint32_t SctpSuccessIndication::getResponseCorrelationId() const
{
    return this->responseCorrelationId;
}

void SctpSuccessIndication::setResponseCorrelationId(uint32_t responseCorrelationId)
{
    this->responseCorrelationId = responseCorrelationId;
}

class SctpSuccessIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_responseCorrelationId,
    };
  public:
    SctpSuccessIndicationDescriptor();
    virtual ~SctpSuccessIndicationDescriptor();

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

Register_ClassDescriptor(SctpSuccessIndicationDescriptor)

SctpSuccessIndicationDescriptor::SctpSuccessIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::SctpSuccessIndication)), "inet::sctp::SctpParameter")
{
    propertynames = nullptr;
}

SctpSuccessIndicationDescriptor::~SctpSuccessIndicationDescriptor()
{
    delete[] propertynames;
}

bool SctpSuccessIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpSuccessIndication *>(obj)!=nullptr;
}

const char **SctpSuccessIndicationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpSuccessIndicationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpSuccessIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SctpSuccessIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_responseCorrelationId
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SctpSuccessIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "responseCorrelationId",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SctpSuccessIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "responseCorrelationId") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpSuccessIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_responseCorrelationId
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpSuccessIndicationDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpSuccessIndicationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpSuccessIndicationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpSuccessIndication *pp = (SctpSuccessIndication *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpSuccessIndicationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSuccessIndication *pp = (SctpSuccessIndication *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpSuccessIndicationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSuccessIndication *pp = (SctpSuccessIndication *)object; (void)pp;
    switch (field) {
        case FIELD_responseCorrelationId: return ulong2string(pp->getResponseCorrelationId());
        default: return "";
    }
}

bool SctpSuccessIndicationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpSuccessIndication *pp = (SctpSuccessIndication *)object; (void)pp;
    switch (field) {
        case FIELD_responseCorrelationId: pp->setResponseCorrelationId(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpSuccessIndicationDescriptor::getFieldStructName(int field) const
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

void *SctpSuccessIndicationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpSuccessIndication *pp = (SctpSuccessIndication *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NatMessage)

NatMessage::NatMessage(const char *name) : ::omnetpp::cMessage(name)
{
}

NatMessage::NatMessage(const NatMessage& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

NatMessage::~NatMessage()
{
    delete [] this->peer1Addresses;
    delete [] this->peer2Addresses;
}

NatMessage& NatMessage::operator=(const NatMessage& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void NatMessage::copy(const NatMessage& other)
{
    this->multi = other.multi;
    this->peer1 = other.peer1;
    delete [] this->peer1Addresses;
    this->peer1Addresses = (other.peer1Addresses_arraysize==0) ? nullptr : new L3Address[other.peer1Addresses_arraysize];
    peer1Addresses_arraysize = other.peer1Addresses_arraysize;
    for (size_t i = 0; i < peer1Addresses_arraysize; i++) {
        this->peer1Addresses[i] = other.peer1Addresses[i];
    }
    this->portPeer1 = other.portPeer1;
    this->peer2 = other.peer2;
    delete [] this->peer2Addresses;
    this->peer2Addresses = (other.peer2Addresses_arraysize==0) ? nullptr : new L3Address[other.peer2Addresses_arraysize];
    peer2Addresses_arraysize = other.peer2Addresses_arraysize;
    for (size_t i = 0; i < peer2Addresses_arraysize; i++) {
        this->peer2Addresses[i] = other.peer2Addresses[i];
    }
    this->portPeer2 = other.portPeer2;
}

void NatMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->multi);
    doParsimPacking(b,this->peer1);
    b->pack(peer1Addresses_arraysize);
    doParsimArrayPacking(b,this->peer1Addresses,peer1Addresses_arraysize);
    doParsimPacking(b,this->portPeer1);
    doParsimPacking(b,this->peer2);
    b->pack(peer2Addresses_arraysize);
    doParsimArrayPacking(b,this->peer2Addresses,peer2Addresses_arraysize);
    doParsimPacking(b,this->portPeer2);
}

void NatMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->multi);
    doParsimUnpacking(b,this->peer1);
    delete [] this->peer1Addresses;
    b->unpack(peer1Addresses_arraysize);
    if (peer1Addresses_arraysize == 0) {
        this->peer1Addresses = nullptr;
    } else {
        this->peer1Addresses = new L3Address[peer1Addresses_arraysize];
        doParsimArrayUnpacking(b,this->peer1Addresses,peer1Addresses_arraysize);
    }
    doParsimUnpacking(b,this->portPeer1);
    doParsimUnpacking(b,this->peer2);
    delete [] this->peer2Addresses;
    b->unpack(peer2Addresses_arraysize);
    if (peer2Addresses_arraysize == 0) {
        this->peer2Addresses = nullptr;
    } else {
        this->peer2Addresses = new L3Address[peer2Addresses_arraysize];
        doParsimArrayUnpacking(b,this->peer2Addresses,peer2Addresses_arraysize);
    }
    doParsimUnpacking(b,this->portPeer2);
}

bool NatMessage::getMulti() const
{
    return this->multi;
}

void NatMessage::setMulti(bool multi)
{
    this->multi = multi;
}

uint16_t NatMessage::getPeer1() const
{
    return this->peer1;
}

void NatMessage::setPeer1(uint16_t peer1)
{
    this->peer1 = peer1;
}

size_t NatMessage::getPeer1AddressesArraySize() const
{
    return peer1Addresses_arraysize;
}

const L3Address& NatMessage::getPeer1Addresses(size_t k) const
{
    if (k >= peer1Addresses_arraysize) throw omnetpp::cRuntimeError("Array of size peer1Addresses_arraysize indexed by %lu", (unsigned long)k);
    return this->peer1Addresses[k];
}

void NatMessage::setPeer1AddressesArraySize(size_t newSize)
{
    L3Address *peer1Addresses2 = (newSize==0) ? nullptr : new L3Address[newSize];
    size_t minSize = peer1Addresses_arraysize < newSize ? peer1Addresses_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        peer1Addresses2[i] = this->peer1Addresses[i];
    delete [] this->peer1Addresses;
    this->peer1Addresses = peer1Addresses2;
    peer1Addresses_arraysize = newSize;
}

void NatMessage::setPeer1Addresses(size_t k, const L3Address& peer1Addresses)
{
    if (k >= peer1Addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->peer1Addresses[k] = peer1Addresses;
}

void NatMessage::insertPeer1Addresses(size_t k, const L3Address& peer1Addresses)
{
    if (k > peer1Addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = peer1Addresses_arraysize + 1;
    L3Address *peer1Addresses2 = new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        peer1Addresses2[i] = this->peer1Addresses[i];
    peer1Addresses2[k] = peer1Addresses;
    for (i = k + 1; i < newSize; i++)
        peer1Addresses2[i] = this->peer1Addresses[i-1];
    delete [] this->peer1Addresses;
    this->peer1Addresses = peer1Addresses2;
    peer1Addresses_arraysize = newSize;
}

void NatMessage::insertPeer1Addresses(const L3Address& peer1Addresses)
{
    insertPeer1Addresses(peer1Addresses_arraysize, peer1Addresses);
}

void NatMessage::erasePeer1Addresses(size_t k)
{
    if (k >= peer1Addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = peer1Addresses_arraysize - 1;
    L3Address *peer1Addresses2 = (newSize == 0) ? nullptr : new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        peer1Addresses2[i] = this->peer1Addresses[i];
    for (i = k; i < newSize; i++)
        peer1Addresses2[i] = this->peer1Addresses[i+1];
    delete [] this->peer1Addresses;
    this->peer1Addresses = peer1Addresses2;
    peer1Addresses_arraysize = newSize;
}

uint32_t NatMessage::getPortPeer1() const
{
    return this->portPeer1;
}

void NatMessage::setPortPeer1(uint32_t portPeer1)
{
    this->portPeer1 = portPeer1;
}

uint16_t NatMessage::getPeer2() const
{
    return this->peer2;
}

void NatMessage::setPeer2(uint16_t peer2)
{
    this->peer2 = peer2;
}

size_t NatMessage::getPeer2AddressesArraySize() const
{
    return peer2Addresses_arraysize;
}

const L3Address& NatMessage::getPeer2Addresses(size_t k) const
{
    if (k >= peer2Addresses_arraysize) throw omnetpp::cRuntimeError("Array of size peer2Addresses_arraysize indexed by %lu", (unsigned long)k);
    return this->peer2Addresses[k];
}

void NatMessage::setPeer2AddressesArraySize(size_t newSize)
{
    L3Address *peer2Addresses2 = (newSize==0) ? nullptr : new L3Address[newSize];
    size_t minSize = peer2Addresses_arraysize < newSize ? peer2Addresses_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        peer2Addresses2[i] = this->peer2Addresses[i];
    delete [] this->peer2Addresses;
    this->peer2Addresses = peer2Addresses2;
    peer2Addresses_arraysize = newSize;
}

void NatMessage::setPeer2Addresses(size_t k, const L3Address& peer2Addresses)
{
    if (k >= peer2Addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->peer2Addresses[k] = peer2Addresses;
}

void NatMessage::insertPeer2Addresses(size_t k, const L3Address& peer2Addresses)
{
    if (k > peer2Addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = peer2Addresses_arraysize + 1;
    L3Address *peer2Addresses2 = new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        peer2Addresses2[i] = this->peer2Addresses[i];
    peer2Addresses2[k] = peer2Addresses;
    for (i = k + 1; i < newSize; i++)
        peer2Addresses2[i] = this->peer2Addresses[i-1];
    delete [] this->peer2Addresses;
    this->peer2Addresses = peer2Addresses2;
    peer2Addresses_arraysize = newSize;
}

void NatMessage::insertPeer2Addresses(const L3Address& peer2Addresses)
{
    insertPeer2Addresses(peer2Addresses_arraysize, peer2Addresses);
}

void NatMessage::erasePeer2Addresses(size_t k)
{
    if (k >= peer2Addresses_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = peer2Addresses_arraysize - 1;
    L3Address *peer2Addresses2 = (newSize == 0) ? nullptr : new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        peer2Addresses2[i] = this->peer2Addresses[i];
    for (i = k; i < newSize; i++)
        peer2Addresses2[i] = this->peer2Addresses[i+1];
    delete [] this->peer2Addresses;
    this->peer2Addresses = peer2Addresses2;
    peer2Addresses_arraysize = newSize;
}

uint32_t NatMessage::getPortPeer2() const
{
    return this->portPeer2;
}

void NatMessage::setPortPeer2(uint32_t portPeer2)
{
    this->portPeer2 = portPeer2;
}

class NatMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_multi,
        FIELD_peer1,
        FIELD_peer1Addresses,
        FIELD_portPeer1,
        FIELD_peer2,
        FIELD_peer2Addresses,
        FIELD_portPeer2,
    };
  public:
    NatMessageDescriptor();
    virtual ~NatMessageDescriptor();

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

Register_ClassDescriptor(NatMessageDescriptor)

NatMessageDescriptor::NatMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::sctp::NatMessage)), "omnetpp::cMessage")
{
    propertynames = nullptr;
}

NatMessageDescriptor::~NatMessageDescriptor()
{
    delete[] propertynames;
}

bool NatMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NatMessage *>(obj)!=nullptr;
}

const char **NatMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NatMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NatMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int NatMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_multi
        FD_ISEDITABLE,    // FIELD_peer1
        FD_ISARRAY,    // FIELD_peer1Addresses
        FD_ISEDITABLE,    // FIELD_portPeer1
        FD_ISEDITABLE,    // FIELD_peer2
        FD_ISARRAY,    // FIELD_peer2Addresses
        FD_ISEDITABLE,    // FIELD_portPeer2
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *NatMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "multi",
        "peer1",
        "peer1Addresses",
        "portPeer1",
        "peer2",
        "peer2Addresses",
        "portPeer2",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int NatMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "multi") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "peer1") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "peer1Addresses") == 0) return base+2;
    if (fieldName[0] == 'p' && strcmp(fieldName, "portPeer1") == 0) return base+3;
    if (fieldName[0] == 'p' && strcmp(fieldName, "peer2") == 0) return base+4;
    if (fieldName[0] == 'p' && strcmp(fieldName, "peer2Addresses") == 0) return base+5;
    if (fieldName[0] == 'p' && strcmp(fieldName, "portPeer2") == 0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NatMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_multi
        "uint16",    // FIELD_peer1
        "inet::L3Address",    // FIELD_peer1Addresses
        "uint32",    // FIELD_portPeer1
        "uint16",    // FIELD_peer2
        "inet::L3Address",    // FIELD_peer2Addresses
        "uint32",    // FIELD_portPeer2
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **NatMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *NatMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NatMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NatMessage *pp = (NatMessage *)object; (void)pp;
    switch (field) {
        case FIELD_peer1Addresses: return pp->getPeer1AddressesArraySize();
        case FIELD_peer2Addresses: return pp->getPeer2AddressesArraySize();
        default: return 0;
    }
}

const char *NatMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NatMessage *pp = (NatMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NatMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NatMessage *pp = (NatMessage *)object; (void)pp;
    switch (field) {
        case FIELD_multi: return bool2string(pp->getMulti());
        case FIELD_peer1: return ulong2string(pp->getPeer1());
        case FIELD_peer1Addresses: return pp->getPeer1Addresses(i).str();
        case FIELD_portPeer1: return ulong2string(pp->getPortPeer1());
        case FIELD_peer2: return ulong2string(pp->getPeer2());
        case FIELD_peer2Addresses: return pp->getPeer2Addresses(i).str();
        case FIELD_portPeer2: return ulong2string(pp->getPortPeer2());
        default: return "";
    }
}

bool NatMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NatMessage *pp = (NatMessage *)object; (void)pp;
    switch (field) {
        case FIELD_multi: pp->setMulti(string2bool(value)); return true;
        case FIELD_peer1: pp->setPeer1(string2ulong(value)); return true;
        case FIELD_portPeer1: pp->setPortPeer1(string2ulong(value)); return true;
        case FIELD_peer2: pp->setPeer2(string2ulong(value)); return true;
        case FIELD_portPeer2: pp->setPortPeer2(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NatMessageDescriptor::getFieldStructName(int field) const
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

void *NatMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NatMessage *pp = (NatMessage *)object; (void)pp;
    switch (field) {
        case FIELD_peer1Addresses: return toVoidPtr(&pp->getPeer1Addresses(i)); break;
        case FIELD_peer2Addresses: return toVoidPtr(&pp->getPeer2Addresses(i)); break;
        default: return nullptr;
    }
}

} // namespace sctp
} // namespace inet

