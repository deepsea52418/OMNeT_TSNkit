//
// Generated file, do not edit! Created by nedtool 5.6 from inet/transportlayer/rtp/Reports.msg.
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
#include "Reports_m.h"

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

Register_Class(SenderReport)

SenderReport::SenderReport() : ::omnetpp::cObject()
{
}

SenderReport::SenderReport(const SenderReport& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

SenderReport::~SenderReport()
{
}

SenderReport& SenderReport::operator=(const SenderReport& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void SenderReport::copy(const SenderReport& other)
{
    this->NTPTimeStamp = other.NTPTimeStamp;
    this->RTPTimeStamp = other.RTPTimeStamp;
    this->packetCount = other.packetCount;
    this->byteCount = other.byteCount;
}

void SenderReport::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->NTPTimeStamp);
    doParsimPacking(b,this->RTPTimeStamp);
    doParsimPacking(b,this->packetCount);
    doParsimPacking(b,this->byteCount);
}

void SenderReport::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->NTPTimeStamp);
    doParsimUnpacking(b,this->RTPTimeStamp);
    doParsimUnpacking(b,this->packetCount);
    doParsimUnpacking(b,this->byteCount);
}

uint64_t SenderReport::getNTPTimeStamp() const
{
    return this->NTPTimeStamp;
}

void SenderReport::setNTPTimeStamp(uint64_t NTPTimeStamp)
{
    this->NTPTimeStamp = NTPTimeStamp;
}

uint32_t SenderReport::getRTPTimeStamp() const
{
    return this->RTPTimeStamp;
}

void SenderReport::setRTPTimeStamp(uint32_t RTPTimeStamp)
{
    this->RTPTimeStamp = RTPTimeStamp;
}

uint32_t SenderReport::getPacketCount() const
{
    return this->packetCount;
}

void SenderReport::setPacketCount(uint32_t packetCount)
{
    this->packetCount = packetCount;
}

uint32_t SenderReport::getByteCount() const
{
    return this->byteCount;
}

void SenderReport::setByteCount(uint32_t byteCount)
{
    this->byteCount = byteCount;
}

class SenderReportDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_NTPTimeStamp,
        FIELD_RTPTimeStamp,
        FIELD_packetCount,
        FIELD_byteCount,
    };
  public:
    SenderReportDescriptor();
    virtual ~SenderReportDescriptor();

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

Register_ClassDescriptor(SenderReportDescriptor)

SenderReportDescriptor::SenderReportDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::SenderReport)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

SenderReportDescriptor::~SenderReportDescriptor()
{
    delete[] propertynames;
}

bool SenderReportDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SenderReport *>(obj)!=nullptr;
}

const char **SenderReportDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SenderReportDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SenderReportDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SenderReportDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_NTPTimeStamp
        FD_ISEDITABLE,    // FIELD_RTPTimeStamp
        FD_ISEDITABLE,    // FIELD_packetCount
        FD_ISEDITABLE,    // FIELD_byteCount
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SenderReportDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "NTPTimeStamp",
        "RTPTimeStamp",
        "packetCount",
        "byteCount",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SenderReportDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'N' && strcmp(fieldName, "NTPTimeStamp") == 0) return base+0;
    if (fieldName[0] == 'R' && strcmp(fieldName, "RTPTimeStamp") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "packetCount") == 0) return base+2;
    if (fieldName[0] == 'b' && strcmp(fieldName, "byteCount") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SenderReportDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64",    // FIELD_NTPTimeStamp
        "uint32",    // FIELD_RTPTimeStamp
        "uint32",    // FIELD_packetCount
        "uint32",    // FIELD_byteCount
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SenderReportDescriptor::getFieldPropertyNames(int field) const
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

const char *SenderReportDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SenderReportDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SenderReport *pp = (SenderReport *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SenderReportDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SenderReport *pp = (SenderReport *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SenderReportDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SenderReport *pp = (SenderReport *)object; (void)pp;
    switch (field) {
        case FIELD_NTPTimeStamp: return uint642string(pp->getNTPTimeStamp());
        case FIELD_RTPTimeStamp: return ulong2string(pp->getRTPTimeStamp());
        case FIELD_packetCount: return ulong2string(pp->getPacketCount());
        case FIELD_byteCount: return ulong2string(pp->getByteCount());
        default: return "";
    }
}

bool SenderReportDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SenderReport *pp = (SenderReport *)object; (void)pp;
    switch (field) {
        case FIELD_NTPTimeStamp: pp->setNTPTimeStamp(string2uint64(value)); return true;
        case FIELD_RTPTimeStamp: pp->setRTPTimeStamp(string2ulong(value)); return true;
        case FIELD_packetCount: pp->setPacketCount(string2ulong(value)); return true;
        case FIELD_byteCount: pp->setByteCount(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SenderReportDescriptor::getFieldStructName(int field) const
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

void *SenderReportDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SenderReport *pp = (SenderReport *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ReceptionReport)

ReceptionReport::ReceptionReport() : ::omnetpp::cObject()
{
}

ReceptionReport::ReceptionReport(const ReceptionReport& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

ReceptionReport::~ReceptionReport()
{
}

ReceptionReport& ReceptionReport::operator=(const ReceptionReport& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void ReceptionReport::copy(const ReceptionReport& other)
{
    this->ssrc = other.ssrc;
    this->fractionLost = other.fractionLost;
    this->packetsLostCumulative = other.packetsLostCumulative;
    this->sequenceNumber = other.sequenceNumber;
    this->jitter = other.jitter;
    this->lastSR = other.lastSR;
    this->delaySinceLastSR = other.delaySinceLastSR;
}

void ReceptionReport::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->ssrc);
    doParsimPacking(b,this->fractionLost);
    doParsimPacking(b,this->packetsLostCumulative);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->jitter);
    doParsimPacking(b,this->lastSR);
    doParsimPacking(b,this->delaySinceLastSR);
}

void ReceptionReport::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->ssrc);
    doParsimUnpacking(b,this->fractionLost);
    doParsimUnpacking(b,this->packetsLostCumulative);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->jitter);
    doParsimUnpacking(b,this->lastSR);
    doParsimUnpacking(b,this->delaySinceLastSR);
}

uint32_t ReceptionReport::getSsrc() const
{
    return this->ssrc;
}

void ReceptionReport::setSsrc(uint32_t ssrc)
{
    this->ssrc = ssrc;
}

uint8_t ReceptionReport::getFractionLost() const
{
    return this->fractionLost;
}

void ReceptionReport::setFractionLost(uint8_t fractionLost)
{
    this->fractionLost = fractionLost;
}

int ReceptionReport::getPacketsLostCumulative() const
{
    return this->packetsLostCumulative;
}

void ReceptionReport::setPacketsLostCumulative(int packetsLostCumulative)
{
    this->packetsLostCumulative = packetsLostCumulative;
}

uint32_t ReceptionReport::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void ReceptionReport::setSequenceNumber(uint32_t sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

int ReceptionReport::getJitter() const
{
    return this->jitter;
}

void ReceptionReport::setJitter(int jitter)
{
    this->jitter = jitter;
}

int ReceptionReport::getLastSR() const
{
    return this->lastSR;
}

void ReceptionReport::setLastSR(int lastSR)
{
    this->lastSR = lastSR;
}

int ReceptionReport::getDelaySinceLastSR() const
{
    return this->delaySinceLastSR;
}

void ReceptionReport::setDelaySinceLastSR(int delaySinceLastSR)
{
    this->delaySinceLastSR = delaySinceLastSR;
}

class ReceptionReportDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_ssrc,
        FIELD_fractionLost,
        FIELD_packetsLostCumulative,
        FIELD_sequenceNumber,
        FIELD_jitter,
        FIELD_lastSR,
        FIELD_delaySinceLastSR,
    };
  public:
    ReceptionReportDescriptor();
    virtual ~ReceptionReportDescriptor();

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

Register_ClassDescriptor(ReceptionReportDescriptor)

ReceptionReportDescriptor::ReceptionReportDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::ReceptionReport)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

ReceptionReportDescriptor::~ReceptionReportDescriptor()
{
    delete[] propertynames;
}

bool ReceptionReportDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ReceptionReport *>(obj)!=nullptr;
}

const char **ReceptionReportDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ReceptionReportDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ReceptionReportDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int ReceptionReportDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ssrc
        FD_ISEDITABLE,    // FIELD_fractionLost
        FD_ISEDITABLE,    // FIELD_packetsLostCumulative
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISEDITABLE,    // FIELD_jitter
        FD_ISEDITABLE,    // FIELD_lastSR
        FD_ISEDITABLE,    // FIELD_delaySinceLastSR
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *ReceptionReportDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ssrc",
        "fractionLost",
        "packetsLostCumulative",
        "sequenceNumber",
        "jitter",
        "lastSR",
        "delaySinceLastSR",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int ReceptionReportDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "ssrc") == 0) return base+0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fractionLost") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "packetsLostCumulative") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "sequenceNumber") == 0) return base+3;
    if (fieldName[0] == 'j' && strcmp(fieldName, "jitter") == 0) return base+4;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lastSR") == 0) return base+5;
    if (fieldName[0] == 'd' && strcmp(fieldName, "delaySinceLastSR") == 0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ReceptionReportDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_ssrc
        "uint8",    // FIELD_fractionLost
        "int",    // FIELD_packetsLostCumulative
        "uint32",    // FIELD_sequenceNumber
        "int",    // FIELD_jitter
        "int",    // FIELD_lastSR
        "int",    // FIELD_delaySinceLastSR
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **ReceptionReportDescriptor::getFieldPropertyNames(int field) const
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

const char *ReceptionReportDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int ReceptionReportDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ReceptionReport *pp = (ReceptionReport *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ReceptionReportDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ReceptionReport *pp = (ReceptionReport *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ReceptionReportDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ReceptionReport *pp = (ReceptionReport *)object; (void)pp;
    switch (field) {
        case FIELD_ssrc: return ulong2string(pp->getSsrc());
        case FIELD_fractionLost: return ulong2string(pp->getFractionLost());
        case FIELD_packetsLostCumulative: return long2string(pp->getPacketsLostCumulative());
        case FIELD_sequenceNumber: return ulong2string(pp->getSequenceNumber());
        case FIELD_jitter: return long2string(pp->getJitter());
        case FIELD_lastSR: return long2string(pp->getLastSR());
        case FIELD_delaySinceLastSR: return long2string(pp->getDelaySinceLastSR());
        default: return "";
    }
}

bool ReceptionReportDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ReceptionReport *pp = (ReceptionReport *)object; (void)pp;
    switch (field) {
        case FIELD_ssrc: pp->setSsrc(string2ulong(value)); return true;
        case FIELD_fractionLost: pp->setFractionLost(string2ulong(value)); return true;
        case FIELD_packetsLostCumulative: pp->setPacketsLostCumulative(string2long(value)); return true;
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2ulong(value)); return true;
        case FIELD_jitter: pp->setJitter(string2long(value)); return true;
        case FIELD_lastSR: pp->setLastSR(string2long(value)); return true;
        case FIELD_delaySinceLastSR: pp->setDelaySinceLastSR(string2long(value)); return true;
        default: return false;
    }
}

const char *ReceptionReportDescriptor::getFieldStructName(int field) const
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

void *ReceptionReportDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ReceptionReport *pp = (ReceptionReport *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace rtp
} // namespace inet

