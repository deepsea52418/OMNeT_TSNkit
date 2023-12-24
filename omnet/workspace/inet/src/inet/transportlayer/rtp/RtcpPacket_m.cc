//
// Generated file, do not edit! Created by nedtool 5.6 from inet/transportlayer/rtp/RtcpPacket.msg.
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
#include "RtcpPacket_m.h"

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

} // namespace inet

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

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::rtp::RtcpPacketType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::rtp::RtcpPacketType"));
    e->insert(RTCP_PT_UNDEF, "RTCP_PT_UNDEF");
    e->insert(RTCP_PT_SR, "RTCP_PT_SR");
    e->insert(RTCP_PT_RR, "RTCP_PT_RR");
    e->insert(RTCP_PT_SDES, "RTCP_PT_SDES");
    e->insert(RTCP_PT_BYE, "RTCP_PT_BYE");
)

Register_Class(RtcpPacket)

RtcpPacket::RtcpPacket() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

RtcpPacket::RtcpPacket(const RtcpPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

RtcpPacket::~RtcpPacket()
{
}

RtcpPacket& RtcpPacket::operator=(const RtcpPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void RtcpPacket::copy(const RtcpPacket& other)
{
    this->version = other.version;
    this->padding = other.padding;
    this->count = other.count;
    this->packetType = other.packetType;
    this->rtcpLength = other.rtcpLength;
}

void RtcpPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->padding);
    doParsimPacking(b,this->count);
    doParsimPacking(b,this->packetType);
    doParsimPacking(b,this->rtcpLength);
}

void RtcpPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->padding);
    doParsimUnpacking(b,this->count);
    doParsimUnpacking(b,this->packetType);
    doParsimUnpacking(b,this->rtcpLength);
}

int8_t RtcpPacket::getVersion() const
{
    return this->version;
}

void RtcpPacket::setVersion(int8_t version)
{
    handleChange();
    this->version = version;
}

bool RtcpPacket::getPadding() const
{
    return this->padding;
}

void RtcpPacket::setPadding(bool padding)
{
    handleChange();
    this->padding = padding;
}

short RtcpPacket::getCount() const
{
    return this->count;
}

void RtcpPacket::setCount(short count)
{
    handleChange();
    this->count = count;
}

inet::rtp::RtcpPacketType RtcpPacket::getPacketType() const
{
    return this->packetType;
}

void RtcpPacket::setPacketType(inet::rtp::RtcpPacketType packetType)
{
    handleChange();
    this->packetType = packetType;
}

int RtcpPacket::getRtcpLength() const
{
    return this->rtcpLength;
}

void RtcpPacket::setRtcpLength(int rtcpLength)
{
    handleChange();
    this->rtcpLength = rtcpLength;
}

class RtcpPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_version,
        FIELD_padding,
        FIELD_count,
        FIELD_packetType,
        FIELD_rtcpLength,
    };
  public:
    RtcpPacketDescriptor();
    virtual ~RtcpPacketDescriptor();

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

Register_ClassDescriptor(RtcpPacketDescriptor)

RtcpPacketDescriptor::RtcpPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtcpPacket)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

RtcpPacketDescriptor::~RtcpPacketDescriptor()
{
    delete[] propertynames;
}

bool RtcpPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtcpPacket *>(obj)!=nullptr;
}

const char **RtcpPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtcpPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtcpPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int RtcpPacketDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,    // FIELD_count
        FD_ISEDITABLE,    // FIELD_packetType
        FD_ISEDITABLE,    // FIELD_rtcpLength
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *RtcpPacketDescriptor::getFieldName(int field) const
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
        "count",
        "packetType",
        "rtcpLength",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int RtcpPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "version") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "padding") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "count") == 0) return base+2;
    if (fieldName[0] == 'p' && strcmp(fieldName, "packetType") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rtcpLength") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtcpPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int8",    // FIELD_version
        "bool",    // FIELD_padding
        "short",    // FIELD_count
        "inet::rtp::RtcpPacketType",    // FIELD_packetType
        "int",    // FIELD_rtcpLength
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **RtcpPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_packetType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *RtcpPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_packetType:
            if (!strcmp(propertyname, "enum")) return "inet::rtp::RtcpPacketType";
            return nullptr;
        default: return nullptr;
    }
}

int RtcpPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtcpPacket *pp = (RtcpPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtcpPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtcpPacket *pp = (RtcpPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtcpPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtcpPacket *pp = (RtcpPacket *)object; (void)pp;
    switch (field) {
        case FIELD_version: return long2string(pp->getVersion());
        case FIELD_padding: return bool2string(pp->getPadding());
        case FIELD_count: return long2string(pp->getCount());
        case FIELD_packetType: return enum2string(pp->getPacketType(), "inet::rtp::RtcpPacketType");
        case FIELD_rtcpLength: return long2string(pp->getRtcpLength());
        default: return "";
    }
}

bool RtcpPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtcpPacket *pp = (RtcpPacket *)object; (void)pp;
    switch (field) {
        case FIELD_version: pp->setVersion(string2long(value)); return true;
        case FIELD_padding: pp->setPadding(string2bool(value)); return true;
        case FIELD_count: pp->setCount(string2long(value)); return true;
        case FIELD_packetType: pp->setPacketType((inet::rtp::RtcpPacketType)string2enum(value, "inet::rtp::RtcpPacketType")); return true;
        case FIELD_rtcpLength: pp->setRtcpLength(string2long(value)); return true;
        default: return false;
    }
}

const char *RtcpPacketDescriptor::getFieldStructName(int field) const
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

void *RtcpPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtcpPacket *pp = (RtcpPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtcpReceiverReportPacket)

RtcpReceiverReportPacket::RtcpReceiverReportPacket() : ::inet::rtp::RtcpPacket()
{
    this->setPacketType(RTCP_PT_RR);
    this->setChunkLength(getChunkLength() + B(4));

    take(&this->receptionReports);
}

RtcpReceiverReportPacket::RtcpReceiverReportPacket(const RtcpReceiverReportPacket& other) : ::inet::rtp::RtcpPacket(other)
{
    take(&this->receptionReports);
    copy(other);
}

RtcpReceiverReportPacket::~RtcpReceiverReportPacket()
{
    drop(&this->receptionReports);
}

RtcpReceiverReportPacket& RtcpReceiverReportPacket::operator=(const RtcpReceiverReportPacket& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtcpPacket::operator=(other);
    copy(other);
    return *this;
}

void RtcpReceiverReportPacket::copy(const RtcpReceiverReportPacket& other)
{
    this->ssrc = other.ssrc;
    this->receptionReports = other.receptionReports;
    this->receptionReports.setName(other.receptionReports.getName());
}

void RtcpReceiverReportPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtcpPacket::parsimPack(b);
    doParsimPacking(b,this->ssrc);
    doParsimPacking(b,this->receptionReports);
}

void RtcpReceiverReportPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtcpPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->ssrc);
    doParsimUnpacking(b,this->receptionReports);
}

uint32_t RtcpReceiverReportPacket::getSsrc() const
{
    return this->ssrc;
}

void RtcpReceiverReportPacket::setSsrc(uint32_t ssrc)
{
    handleChange();
    this->ssrc = ssrc;
}

const cArray& RtcpReceiverReportPacket::getReceptionReports() const
{
    return this->receptionReports;
}

void RtcpReceiverReportPacket::setReceptionReports(const cArray& receptionReports)
{
    handleChange();
    this->receptionReports = receptionReports;
}

class RtcpReceiverReportPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_ssrc,
        FIELD_receptionReports,
    };
  public:
    RtcpReceiverReportPacketDescriptor();
    virtual ~RtcpReceiverReportPacketDescriptor();

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

Register_ClassDescriptor(RtcpReceiverReportPacketDescriptor)

RtcpReceiverReportPacketDescriptor::RtcpReceiverReportPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtcpReceiverReportPacket)), "inet::rtp::RtcpPacket")
{
    propertynames = nullptr;
}

RtcpReceiverReportPacketDescriptor::~RtcpReceiverReportPacketDescriptor()
{
    delete[] propertynames;
}

bool RtcpReceiverReportPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtcpReceiverReportPacket *>(obj)!=nullptr;
}

const char **RtcpReceiverReportPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtcpReceiverReportPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtcpReceiverReportPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int RtcpReceiverReportPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ssrc
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_receptionReports
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *RtcpReceiverReportPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ssrc",
        "receptionReports",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int RtcpReceiverReportPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "ssrc") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "receptionReports") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtcpReceiverReportPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_ssrc
        "omnetpp::cArray",    // FIELD_receptionReports
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **RtcpReceiverReportPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *RtcpReceiverReportPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtcpReceiverReportPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtcpReceiverReportPacket *pp = (RtcpReceiverReportPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtcpReceiverReportPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtcpReceiverReportPacket *pp = (RtcpReceiverReportPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtcpReceiverReportPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtcpReceiverReportPacket *pp = (RtcpReceiverReportPacket *)object; (void)pp;
    switch (field) {
        case FIELD_ssrc: return ulong2string(pp->getSsrc());
        case FIELD_receptionReports: {std::stringstream out; out << pp->getReceptionReports(); return out.str();}
        default: return "";
    }
}

bool RtcpReceiverReportPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtcpReceiverReportPacket *pp = (RtcpReceiverReportPacket *)object; (void)pp;
    switch (field) {
        case FIELD_ssrc: pp->setSsrc(string2ulong(value)); return true;
        default: return false;
    }
}

const char *RtcpReceiverReportPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_receptionReports: return omnetpp::opp_typename(typeid(cArray));
        default: return nullptr;
    };
}

void *RtcpReceiverReportPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtcpReceiverReportPacket *pp = (RtcpReceiverReportPacket *)object; (void)pp;
    switch (field) {
        case FIELD_receptionReports: return toVoidPtr(&pp->getReceptionReports()); break;
        default: return nullptr;
    }
}

Register_Class(RtcpSdesPacket)

RtcpSdesPacket::RtcpSdesPacket() : ::inet::rtp::RtcpPacket()
{
    this->setPacketType(RTCP_PT_SDES);

    take(&this->sdesChunks);
}

RtcpSdesPacket::RtcpSdesPacket(const RtcpSdesPacket& other) : ::inet::rtp::RtcpPacket(other)
{
    take(&this->sdesChunks);
    copy(other);
}

RtcpSdesPacket::~RtcpSdesPacket()
{
    drop(&this->sdesChunks);
}

RtcpSdesPacket& RtcpSdesPacket::operator=(const RtcpSdesPacket& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtcpPacket::operator=(other);
    copy(other);
    return *this;
}

void RtcpSdesPacket::copy(const RtcpSdesPacket& other)
{
    this->sdesChunks = other.sdesChunks;
    this->sdesChunks.setName(other.sdesChunks.getName());
}

void RtcpSdesPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtcpPacket::parsimPack(b);
    doParsimPacking(b,this->sdesChunks);
}

void RtcpSdesPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtcpPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sdesChunks);
}

const cArray& RtcpSdesPacket::getSdesChunks() const
{
    return this->sdesChunks;
}

void RtcpSdesPacket::setSdesChunks(const cArray& sdesChunks)
{
    handleChange();
    this->sdesChunks = sdesChunks;
}

class RtcpSdesPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_sdesChunks,
    };
  public:
    RtcpSdesPacketDescriptor();
    virtual ~RtcpSdesPacketDescriptor();

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

Register_ClassDescriptor(RtcpSdesPacketDescriptor)

RtcpSdesPacketDescriptor::RtcpSdesPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtcpSdesPacket)), "inet::rtp::RtcpPacket")
{
    propertynames = nullptr;
}

RtcpSdesPacketDescriptor::~RtcpSdesPacketDescriptor()
{
    delete[] propertynames;
}

bool RtcpSdesPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtcpSdesPacket *>(obj)!=nullptr;
}

const char **RtcpSdesPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtcpSdesPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtcpSdesPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RtcpSdesPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_sdesChunks
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *RtcpSdesPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sdesChunks",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int RtcpSdesPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sdesChunks") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtcpSdesPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::cArray",    // FIELD_sdesChunks
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **RtcpSdesPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *RtcpSdesPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtcpSdesPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtcpSdesPacket *pp = (RtcpSdesPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtcpSdesPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtcpSdesPacket *pp = (RtcpSdesPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtcpSdesPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtcpSdesPacket *pp = (RtcpSdesPacket *)object; (void)pp;
    switch (field) {
        case FIELD_sdesChunks: {std::stringstream out; out << pp->getSdesChunks(); return out.str();}
        default: return "";
    }
}

bool RtcpSdesPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtcpSdesPacket *pp = (RtcpSdesPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RtcpSdesPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_sdesChunks: return omnetpp::opp_typename(typeid(cArray));
        default: return nullptr;
    };
}

void *RtcpSdesPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtcpSdesPacket *pp = (RtcpSdesPacket *)object; (void)pp;
    switch (field) {
        case FIELD_sdesChunks: return toVoidPtr(&pp->getSdesChunks()); break;
        default: return nullptr;
    }
}

Register_Class(RtcpByePacket)

RtcpByePacket::RtcpByePacket() : ::inet::rtp::RtcpPacket()
{
    this->setPacketType(RTCP_PT_BYE);
    this->setChunkLength(getChunkLength() + B(4));
    this->setCount(1);

}

RtcpByePacket::RtcpByePacket(const RtcpByePacket& other) : ::inet::rtp::RtcpPacket(other)
{
    copy(other);
}

RtcpByePacket::~RtcpByePacket()
{
}

RtcpByePacket& RtcpByePacket::operator=(const RtcpByePacket& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtcpPacket::operator=(other);
    copy(other);
    return *this;
}

void RtcpByePacket::copy(const RtcpByePacket& other)
{
    this->ssrc = other.ssrc;
}

void RtcpByePacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtcpPacket::parsimPack(b);
    doParsimPacking(b,this->ssrc);
}

void RtcpByePacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtcpPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->ssrc);
}

uint32_t RtcpByePacket::getSsrc() const
{
    return this->ssrc;
}

void RtcpByePacket::setSsrc(uint32_t ssrc)
{
    handleChange();
    this->ssrc = ssrc;
}

class RtcpByePacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_ssrc,
    };
  public:
    RtcpByePacketDescriptor();
    virtual ~RtcpByePacketDescriptor();

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

Register_ClassDescriptor(RtcpByePacketDescriptor)

RtcpByePacketDescriptor::RtcpByePacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtcpByePacket)), "inet::rtp::RtcpPacket")
{
    propertynames = nullptr;
}

RtcpByePacketDescriptor::~RtcpByePacketDescriptor()
{
    delete[] propertynames;
}

bool RtcpByePacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtcpByePacket *>(obj)!=nullptr;
}

const char **RtcpByePacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtcpByePacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtcpByePacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RtcpByePacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ssrc
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *RtcpByePacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ssrc",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int RtcpByePacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "ssrc") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtcpByePacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_ssrc
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **RtcpByePacketDescriptor::getFieldPropertyNames(int field) const
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

const char *RtcpByePacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtcpByePacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtcpByePacket *pp = (RtcpByePacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtcpByePacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtcpByePacket *pp = (RtcpByePacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtcpByePacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtcpByePacket *pp = (RtcpByePacket *)object; (void)pp;
    switch (field) {
        case FIELD_ssrc: return ulong2string(pp->getSsrc());
        default: return "";
    }
}

bool RtcpByePacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtcpByePacket *pp = (RtcpByePacket *)object; (void)pp;
    switch (field) {
        case FIELD_ssrc: pp->setSsrc(string2ulong(value)); return true;
        default: return false;
    }
}

const char *RtcpByePacketDescriptor::getFieldStructName(int field) const
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

void *RtcpByePacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtcpByePacket *pp = (RtcpByePacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RtcpSenderReportPacket)

RtcpSenderReportPacket::RtcpSenderReportPacket() : ::inet::rtp::RtcpReceiverReportPacket()
{
    this->setPacketType(RTCP_PT_SR);
    this->setChunkLength(getChunkLength() + B(20));

}

RtcpSenderReportPacket::RtcpSenderReportPacket(const RtcpSenderReportPacket& other) : ::inet::rtp::RtcpReceiverReportPacket(other)
{
    copy(other);
}

RtcpSenderReportPacket::~RtcpSenderReportPacket()
{
}

RtcpSenderReportPacket& RtcpSenderReportPacket::operator=(const RtcpSenderReportPacket& other)
{
    if (this == &other) return *this;
    ::inet::rtp::RtcpReceiverReportPacket::operator=(other);
    copy(other);
    return *this;
}

void RtcpSenderReportPacket::copy(const RtcpSenderReportPacket& other)
{
    this->senderReport = other.senderReport;
}

void RtcpSenderReportPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RtcpReceiverReportPacket::parsimPack(b);
    doParsimPacking(b,this->senderReport);
}

void RtcpSenderReportPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RtcpReceiverReportPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->senderReport);
}

const SenderReport& RtcpSenderReportPacket::getSenderReport() const
{
    return this->senderReport;
}

void RtcpSenderReportPacket::setSenderReport(const SenderReport& senderReport)
{
    handleChange();
    this->senderReport = senderReport;
}

class RtcpSenderReportPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_senderReport,
    };
  public:
    RtcpSenderReportPacketDescriptor();
    virtual ~RtcpSenderReportPacketDescriptor();

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

Register_ClassDescriptor(RtcpSenderReportPacketDescriptor)

RtcpSenderReportPacketDescriptor::RtcpSenderReportPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtcpSenderReportPacket)), "inet::rtp::RtcpReceiverReportPacket")
{
    propertynames = nullptr;
}

RtcpSenderReportPacketDescriptor::~RtcpSenderReportPacketDescriptor()
{
    delete[] propertynames;
}

bool RtcpSenderReportPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtcpSenderReportPacket *>(obj)!=nullptr;
}

const char **RtcpSenderReportPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtcpSenderReportPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtcpSenderReportPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RtcpSenderReportPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_senderReport
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *RtcpSenderReportPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "senderReport",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int RtcpSenderReportPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "senderReport") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtcpSenderReportPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::rtp::SenderReport",    // FIELD_senderReport
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **RtcpSenderReportPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *RtcpSenderReportPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RtcpSenderReportPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtcpSenderReportPacket *pp = (RtcpSenderReportPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtcpSenderReportPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtcpSenderReportPacket *pp = (RtcpSenderReportPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtcpSenderReportPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtcpSenderReportPacket *pp = (RtcpSenderReportPacket *)object; (void)pp;
    switch (field) {
        case FIELD_senderReport: {std::stringstream out; out << pp->getSenderReport(); return out.str();}
        default: return "";
    }
}

bool RtcpSenderReportPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtcpSenderReportPacket *pp = (RtcpSenderReportPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RtcpSenderReportPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_senderReport: return omnetpp::opp_typename(typeid(SenderReport));
        default: return nullptr;
    };
}

void *RtcpSenderReportPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtcpSenderReportPacket *pp = (RtcpSenderReportPacket *)object; (void)pp;
    switch (field) {
        case FIELD_senderReport: return toVoidPtr(&pp->getSenderReport()); break;
        default: return nullptr;
    }
}

} // namespace rtp
} // namespace inet

