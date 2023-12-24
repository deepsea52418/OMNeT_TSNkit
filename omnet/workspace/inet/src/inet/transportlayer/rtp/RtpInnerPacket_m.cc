//
// Generated file, do not edit! Created by nedtool 5.6 from inet/transportlayer/rtp/RtpInnerPacket.msg.
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
#include "RtpInnerPacket_m.h"

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

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::rtp::RtpInpType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::rtp::RtpInpType"));
    e->insert(RTP_INP_UNDEF, "RTP_INP_UNDEF");
    e->insert(RTP_INP_INITIALIZE_PROFILE, "RTP_INP_INITIALIZE_PROFILE");
    e->insert(RTP_INP_PROFILE_INITIALIZED, "RTP_INP_PROFILE_INITIALIZED");
    e->insert(RTP_INP_INITIALIZE_RTCP, "RTP_INP_INITIALIZE_RTCP");
    e->insert(RTP_INP_RTCP_INITIALIZED, "RTP_INP_RTCP_INITIALIZED");
    e->insert(RTP_INP_CREATE_SENDER_MODULE, "RTP_INP_CREATE_SENDER_MODULE");
    e->insert(RTP_INP_SENDER_MODULE_CREATED, "RTP_INP_SENDER_MODULE_CREATED");
    e->insert(RTP_INP_DELETE_SENDER_MODULE, "RTP_INP_DELETE_SENDER_MODULE");
    e->insert(RTP_INP_SENDER_MODULE_DELETED, "RTP_INP_SENDER_MODULE_DELETED");
    e->insert(RTP_INP_INITIALIZE_SENDER_MODULE, "RTP_INP_INITIALIZE_SENDER_MODULE");
    e->insert(RTP_INP_SENDER_MODULE_INITIALIZED, "RTP_INP_SENDER_MODULE_INITIALIZED");
    e->insert(RTP_INP_SENDER_MODULE_CONTROL, "RTP_INP_SENDER_MODULE_CONTROL");
    e->insert(RTP_INP_SENDER_MODULE_STATUS, "RTP_INP_SENDER_MODULE_STATUS");
    e->insert(RTP_INP_LEAVE_SESSION, "RTP_INP_LEAVE_SESSION");
    e->insert(RTP_INP_SESSION_LEFT, "RTP_INP_SESSION_LEFT");
    e->insert(RTP_INP_DATA_OUT, "RTP_INP_DATA_OUT");
    e->insert(RTP_INP_DATA_IN, "RTP_INP_DATA_IN");
)

Register_Class(RtpInnerPacket)

RtpInnerPacket::RtpInnerPacket(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

RtpInnerPacket::RtpInnerPacket(const RtpInnerPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

RtpInnerPacket::~RtpInnerPacket()
{
}

RtpInnerPacket& RtpInnerPacket::operator=(const RtpInnerPacket& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void RtpInnerPacket::copy(const RtpInnerPacket& other)
{
    this->type = other.type;
    this->commonName = other.commonName;
    this->mtu = other.mtu;
    this->bandwidth = other.bandwidth;
    this->rtcpPercentage = other.rtcpPercentage;
    this->address = other.address;
    this->port = other.port;
    this->ssrc = other.ssrc;
    this->payloadType = other.payloadType;
    this->fileName = other.fileName;
    this->clockRate = other.clockRate;
    this->timeStampBase = other.timeStampBase;
    this->sequenceNumberBase = other.sequenceNumberBase;
}

void RtpInnerPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->commonName);
    doParsimPacking(b,this->mtu);
    doParsimPacking(b,this->bandwidth);
    doParsimPacking(b,this->rtcpPercentage);
    doParsimPacking(b,this->address);
    doParsimPacking(b,this->port);
    doParsimPacking(b,this->ssrc);
    doParsimPacking(b,this->payloadType);
    doParsimPacking(b,this->fileName);
    doParsimPacking(b,this->clockRate);
    doParsimPacking(b,this->timeStampBase);
    doParsimPacking(b,this->sequenceNumberBase);
}

void RtpInnerPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->commonName);
    doParsimUnpacking(b,this->mtu);
    doParsimUnpacking(b,this->bandwidth);
    doParsimUnpacking(b,this->rtcpPercentage);
    doParsimUnpacking(b,this->address);
    doParsimUnpacking(b,this->port);
    doParsimUnpacking(b,this->ssrc);
    doParsimUnpacking(b,this->payloadType);
    doParsimUnpacking(b,this->fileName);
    doParsimUnpacking(b,this->clockRate);
    doParsimUnpacking(b,this->timeStampBase);
    doParsimUnpacking(b,this->sequenceNumberBase);
}

inet::rtp::RtpInpType RtpInnerPacket::getType() const
{
    return this->type;
}

void RtpInnerPacket::setType(inet::rtp::RtpInpType type)
{
    this->type = type;
}

const char * RtpInnerPacket::getCommonName() const
{
    return this->commonName.c_str();
}

void RtpInnerPacket::setCommonName(const char * commonName)
{
    this->commonName = commonName;
}

int RtpInnerPacket::getMtu() const
{
    return this->mtu;
}

void RtpInnerPacket::setMtu(int mtu)
{
    this->mtu = mtu;
}

int RtpInnerPacket::getBandwidth() const
{
    return this->bandwidth;
}

void RtpInnerPacket::setBandwidth(int bandwidth)
{
    this->bandwidth = bandwidth;
}

int RtpInnerPacket::getRtcpPercentage() const
{
    return this->rtcpPercentage;
}

void RtpInnerPacket::setRtcpPercentage(int rtcpPercentage)
{
    this->rtcpPercentage = rtcpPercentage;
}

const Ipv4Address& RtpInnerPacket::getAddress() const
{
    return this->address;
}

void RtpInnerPacket::setAddress(const Ipv4Address& address)
{
    this->address = address;
}

int RtpInnerPacket::getPort() const
{
    return this->port;
}

void RtpInnerPacket::setPort(int port)
{
    this->port = port;
}

uint32_t RtpInnerPacket::getSsrc() const
{
    return this->ssrc;
}

void RtpInnerPacket::setSsrc(uint32_t ssrc)
{
    this->ssrc = ssrc;
}

int RtpInnerPacket::getPayloadType() const
{
    return this->payloadType;
}

void RtpInnerPacket::setPayloadType(int payloadType)
{
    this->payloadType = payloadType;
}

const char * RtpInnerPacket::getFileName() const
{
    return this->fileName.c_str();
}

void RtpInnerPacket::setFileName(const char * fileName)
{
    this->fileName = fileName;
}

int RtpInnerPacket::getClockRate() const
{
    return this->clockRate;
}

void RtpInnerPacket::setClockRate(int clockRate)
{
    this->clockRate = clockRate;
}

int RtpInnerPacket::getTimeStampBase() const
{
    return this->timeStampBase;
}

void RtpInnerPacket::setTimeStampBase(int timeStampBase)
{
    this->timeStampBase = timeStampBase;
}

int RtpInnerPacket::getSequenceNumberBase() const
{
    return this->sequenceNumberBase;
}

void RtpInnerPacket::setSequenceNumberBase(int sequenceNumberBase)
{
    this->sequenceNumberBase = sequenceNumberBase;
}

class RtpInnerPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_commonName,
        FIELD_mtu,
        FIELD_bandwidth,
        FIELD_rtcpPercentage,
        FIELD_address,
        FIELD_port,
        FIELD_ssrc,
        FIELD_payloadType,
        FIELD_fileName,
        FIELD_clockRate,
        FIELD_timeStampBase,
        FIELD_sequenceNumberBase,
    };
  public:
    RtpInnerPacketDescriptor();
    virtual ~RtpInnerPacketDescriptor();

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

Register_ClassDescriptor(RtpInnerPacketDescriptor)

RtpInnerPacketDescriptor::RtpInnerPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::rtp::RtpInnerPacket)), "omnetpp::cPacket")
{
    propertynames = nullptr;
}

RtpInnerPacketDescriptor::~RtpInnerPacketDescriptor()
{
    delete[] propertynames;
}

bool RtpInnerPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RtpInnerPacket *>(obj)!=nullptr;
}

const char **RtpInnerPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RtpInnerPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RtpInnerPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 13+basedesc->getFieldCount() : 13;
}

unsigned int RtpInnerPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_commonName
        FD_ISEDITABLE,    // FIELD_mtu
        FD_ISEDITABLE,    // FIELD_bandwidth
        FD_ISEDITABLE,    // FIELD_rtcpPercentage
        0,    // FIELD_address
        FD_ISEDITABLE,    // FIELD_port
        FD_ISEDITABLE,    // FIELD_ssrc
        FD_ISEDITABLE,    // FIELD_payloadType
        FD_ISEDITABLE,    // FIELD_fileName
        FD_ISEDITABLE,    // FIELD_clockRate
        FD_ISEDITABLE,    // FIELD_timeStampBase
        FD_ISEDITABLE,    // FIELD_sequenceNumberBase
    };
    return (field >= 0 && field < 13) ? fieldTypeFlags[field] : 0;
}

const char *RtpInnerPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "commonName",
        "mtu",
        "bandwidth",
        "rtcpPercentage",
        "address",
        "port",
        "ssrc",
        "payloadType",
        "fileName",
        "clockRate",
        "timeStampBase",
        "sequenceNumberBase",
    };
    return (field >= 0 && field < 13) ? fieldNames[field] : nullptr;
}

int RtpInnerPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "commonName") == 0) return base+1;
    if (fieldName[0] == 'm' && strcmp(fieldName, "mtu") == 0) return base+2;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bandwidth") == 0) return base+3;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rtcpPercentage") == 0) return base+4;
    if (fieldName[0] == 'a' && strcmp(fieldName, "address") == 0) return base+5;
    if (fieldName[0] == 'p' && strcmp(fieldName, "port") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "ssrc") == 0) return base+7;
    if (fieldName[0] == 'p' && strcmp(fieldName, "payloadType") == 0) return base+8;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fileName") == 0) return base+9;
    if (fieldName[0] == 'c' && strcmp(fieldName, "clockRate") == 0) return base+10;
    if (fieldName[0] == 't' && strcmp(fieldName, "timeStampBase") == 0) return base+11;
    if (fieldName[0] == 's' && strcmp(fieldName, "sequenceNumberBase") == 0) return base+12;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RtpInnerPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::rtp::RtpInpType",    // FIELD_type
        "string",    // FIELD_commonName
        "int",    // FIELD_mtu
        "int",    // FIELD_bandwidth
        "int",    // FIELD_rtcpPercentage
        "inet::Ipv4Address",    // FIELD_address
        "int",    // FIELD_port
        "uint32",    // FIELD_ssrc
        "int",    // FIELD_payloadType
        "string",    // FIELD_fileName
        "int",    // FIELD_clockRate
        "int",    // FIELD_timeStampBase
        "int",    // FIELD_sequenceNumberBase
    };
    return (field >= 0 && field < 13) ? fieldTypeStrings[field] : nullptr;
}

const char **RtpInnerPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *RtpInnerPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::rtp::RtpInpType";
            return nullptr;
        default: return nullptr;
    }
}

int RtpInnerPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RtpInnerPacket *pp = (RtpInnerPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RtpInnerPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpInnerPacket *pp = (RtpInnerPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RtpInnerPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RtpInnerPacket *pp = (RtpInnerPacket *)object; (void)pp;
    switch (field) {
        case FIELD_type: return enum2string(pp->getType(), "inet::rtp::RtpInpType");
        case FIELD_commonName: return oppstring2string(pp->getCommonName());
        case FIELD_mtu: return long2string(pp->getMtu());
        case FIELD_bandwidth: return long2string(pp->getBandwidth());
        case FIELD_rtcpPercentage: return long2string(pp->getRtcpPercentage());
        case FIELD_address: return pp->getAddress().str();
        case FIELD_port: return long2string(pp->getPort());
        case FIELD_ssrc: return ulong2string(pp->getSsrc());
        case FIELD_payloadType: return long2string(pp->getPayloadType());
        case FIELD_fileName: return oppstring2string(pp->getFileName());
        case FIELD_clockRate: return long2string(pp->getClockRate());
        case FIELD_timeStampBase: return long2string(pp->getTimeStampBase());
        case FIELD_sequenceNumberBase: return long2string(pp->getSequenceNumberBase());
        default: return "";
    }
}

bool RtpInnerPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RtpInnerPacket *pp = (RtpInnerPacket *)object; (void)pp;
    switch (field) {
        case FIELD_type: pp->setType((inet::rtp::RtpInpType)string2enum(value, "inet::rtp::RtpInpType")); return true;
        case FIELD_commonName: pp->setCommonName((value)); return true;
        case FIELD_mtu: pp->setMtu(string2long(value)); return true;
        case FIELD_bandwidth: pp->setBandwidth(string2long(value)); return true;
        case FIELD_rtcpPercentage: pp->setRtcpPercentage(string2long(value)); return true;
        case FIELD_port: pp->setPort(string2long(value)); return true;
        case FIELD_ssrc: pp->setSsrc(string2ulong(value)); return true;
        case FIELD_payloadType: pp->setPayloadType(string2long(value)); return true;
        case FIELD_fileName: pp->setFileName((value)); return true;
        case FIELD_clockRate: pp->setClockRate(string2long(value)); return true;
        case FIELD_timeStampBase: pp->setTimeStampBase(string2long(value)); return true;
        case FIELD_sequenceNumberBase: pp->setSequenceNumberBase(string2long(value)); return true;
        default: return false;
    }
}

const char *RtpInnerPacketDescriptor::getFieldStructName(int field) const
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

void *RtpInnerPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RtpInnerPacket *pp = (RtpInnerPacket *)object; (void)pp;
    switch (field) {
        case FIELD_address: return toVoidPtr(&pp->getAddress()); break;
        default: return nullptr;
    }
}

} // namespace rtp
} // namespace inet

