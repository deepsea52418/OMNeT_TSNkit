//
// Generated file, do not edit! Created by nedtool 5.6 from inet/linklayer/ieee80211/mac/Ieee80211Frame.msg.
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
#include "Ieee80211Frame_m.h"

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
namespace ieee80211 {

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ieee80211::Ieee80211FrameType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ieee80211::Ieee80211FrameType"));
    e->insert(ST_ASSOCIATIONREQUEST, "ST_ASSOCIATIONREQUEST");
    e->insert(ST_ASSOCIATIONRESPONSE, "ST_ASSOCIATIONRESPONSE");
    e->insert(ST_REASSOCIATIONREQUEST, "ST_REASSOCIATIONREQUEST");
    e->insert(ST_REASSOCIATIONRESPONSE, "ST_REASSOCIATIONRESPONSE");
    e->insert(ST_PROBEREQUEST, "ST_PROBEREQUEST");
    e->insert(ST_PROBERESPONSE, "ST_PROBERESPONSE");
    e->insert(ST_BEACON, "ST_BEACON");
    e->insert(ST_ATIM, "ST_ATIM");
    e->insert(ST_DISASSOCIATION, "ST_DISASSOCIATION");
    e->insert(ST_AUTHENTICATION, "ST_AUTHENTICATION");
    e->insert(ST_DEAUTHENTICATION, "ST_DEAUTHENTICATION");
    e->insert(ST_ACTION, "ST_ACTION");
    e->insert(ST_NOACKACTION, "ST_NOACKACTION");
    e->insert(ST_PSPOLL, "ST_PSPOLL");
    e->insert(ST_RTS, "ST_RTS");
    e->insert(ST_CTS, "ST_CTS");
    e->insert(ST_ACK, "ST_ACK");
    e->insert(ST_BLOCKACK_REQ, "ST_BLOCKACK_REQ");
    e->insert(ST_BLOCKACK, "ST_BLOCKACK");
    e->insert(ST_DATA, "ST_DATA");
    e->insert(ST_DATA_WITH_QOS, "ST_DATA_WITH_QOS");
    e->insert(ST_LBMS_REQUEST, "ST_LBMS_REQUEST");
    e->insert(ST_LBMS_REPORT, "ST_LBMS_REPORT");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ieee80211::AckPolicy");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ieee80211::AckPolicy"));
    e->insert(NORMAL_ACK, "NORMAL_ACK");
    e->insert(NO_ACK, "NO_ACK");
    e->insert(NO_EXPLICIT_ACK, "NO_EXPLICIT_ACK");
    e->insert(BLOCK_ACK, "BLOCK_ACK");
)

Register_Class(Ieee80211MacTrailer)

Ieee80211MacTrailer::Ieee80211MacTrailer() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

Ieee80211MacTrailer::Ieee80211MacTrailer(const Ieee80211MacTrailer& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ieee80211MacTrailer::~Ieee80211MacTrailer()
{
}

Ieee80211MacTrailer& Ieee80211MacTrailer::operator=(const Ieee80211MacTrailer& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211MacTrailer::copy(const Ieee80211MacTrailer& other)
{
    this->fcs = other.fcs;
    this->fcsMode = other.fcsMode;
}

void Ieee80211MacTrailer::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->fcs);
    doParsimPacking(b,this->fcsMode);
}

void Ieee80211MacTrailer::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->fcs);
    doParsimUnpacking(b,this->fcsMode);
}

uint32_t Ieee80211MacTrailer::getFcs() const
{
    return this->fcs;
}

void Ieee80211MacTrailer::setFcs(uint32_t fcs)
{
    handleChange();
    this->fcs = fcs;
}

inet::FcsMode Ieee80211MacTrailer::getFcsMode() const
{
    return this->fcsMode;
}

void Ieee80211MacTrailer::setFcsMode(inet::FcsMode fcsMode)
{
    handleChange();
    this->fcsMode = fcsMode;
}

class Ieee80211MacTrailerDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_fcs,
        FIELD_fcsMode,
    };
  public:
    Ieee80211MacTrailerDescriptor();
    virtual ~Ieee80211MacTrailerDescriptor();

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

Register_ClassDescriptor(Ieee80211MacTrailerDescriptor)

Ieee80211MacTrailerDescriptor::Ieee80211MacTrailerDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211MacTrailer)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ieee80211MacTrailerDescriptor::~Ieee80211MacTrailerDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211MacTrailerDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211MacTrailer *>(obj)!=nullptr;
}

const char **Ieee80211MacTrailerDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211MacTrailerDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211MacTrailerDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ieee80211MacTrailerDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_fcs
        0,    // FIELD_fcsMode
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211MacTrailerDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fcs",
        "fcsMode",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ieee80211MacTrailerDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fcs") == 0) return base+0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fcsMode") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211MacTrailerDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_fcs
        "inet::FcsMode",    // FIELD_fcsMode
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211MacTrailerDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_fcsMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211MacTrailerDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_fcsMode:
            if (!strcmp(propertyname, "enum")) return "inet::FcsMode";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211MacTrailerDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MacTrailer *pp = (Ieee80211MacTrailer *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211MacTrailerDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MacTrailer *pp = (Ieee80211MacTrailer *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211MacTrailerDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MacTrailer *pp = (Ieee80211MacTrailer *)object; (void)pp;
    switch (field) {
        case FIELD_fcs: return ulong2string(pp->getFcs());
        case FIELD_fcsMode: return enum2string(pp->getFcsMode(), "inet::FcsMode");
        default: return "";
    }
}

bool Ieee80211MacTrailerDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MacTrailer *pp = (Ieee80211MacTrailer *)object; (void)pp;
    switch (field) {
        case FIELD_fcs: pp->setFcs(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ieee80211MacTrailerDescriptor::getFieldStructName(int field) const
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

void *Ieee80211MacTrailerDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MacTrailer *pp = (Ieee80211MacTrailer *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211MacHeader)

Ieee80211MacHeader::Ieee80211MacHeader() : ::inet::FieldsChunk()
{
    this->setChunkLength(LENGTH_ACK - B(4));

}

Ieee80211MacHeader::Ieee80211MacHeader(const Ieee80211MacHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ieee80211MacHeader::~Ieee80211MacHeader()
{
}

Ieee80211MacHeader& Ieee80211MacHeader::operator=(const Ieee80211MacHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211MacHeader::copy(const Ieee80211MacHeader& other)
{
    this->type = other.type;
    this->toDS = other.toDS;
    this->fromDS = other.fromDS;
    this->retry = other.retry;
    this->moreFragments = other.moreFragments;
    this->duration = other.duration;
    this->AID = other.AID;
    this->receiverAddress = other.receiverAddress;
    this->MACArrive = other.MACArrive;
}

void Ieee80211MacHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->toDS);
    doParsimPacking(b,this->fromDS);
    doParsimPacking(b,this->retry);
    doParsimPacking(b,this->moreFragments);
    doParsimPacking(b,this->duration);
    doParsimPacking(b,this->AID);
    doParsimPacking(b,this->receiverAddress);
    doParsimPacking(b,this->MACArrive);
}

void Ieee80211MacHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->toDS);
    doParsimUnpacking(b,this->fromDS);
    doParsimUnpacking(b,this->retry);
    doParsimUnpacking(b,this->moreFragments);
    doParsimUnpacking(b,this->duration);
    doParsimUnpacking(b,this->AID);
    doParsimUnpacking(b,this->receiverAddress);
    doParsimUnpacking(b,this->MACArrive);
}

inet::ieee80211::Ieee80211FrameType Ieee80211MacHeader::getType() const
{
    return this->type;
}

void Ieee80211MacHeader::setType(inet::ieee80211::Ieee80211FrameType type)
{
    handleChange();
    this->type = type;
}

bool Ieee80211MacHeader::getToDS() const
{
    return this->toDS;
}

void Ieee80211MacHeader::setToDS(bool toDS)
{
    handleChange();
    this->toDS = toDS;
}

bool Ieee80211MacHeader::getFromDS() const
{
    return this->fromDS;
}

void Ieee80211MacHeader::setFromDS(bool fromDS)
{
    handleChange();
    this->fromDS = fromDS;
}

bool Ieee80211MacHeader::getRetry() const
{
    return this->retry;
}

void Ieee80211MacHeader::setRetry(bool retry)
{
    handleChange();
    this->retry = retry;
}

bool Ieee80211MacHeader::getMoreFragments() const
{
    return this->moreFragments;
}

void Ieee80211MacHeader::setMoreFragments(bool moreFragments)
{
    handleChange();
    this->moreFragments = moreFragments;
}

omnetpp::simtime_t Ieee80211MacHeader::getDuration() const
{
    return this->duration;
}

void Ieee80211MacHeader::setDuration(omnetpp::simtime_t duration)
{
    handleChange();
    this->duration = duration;
}

short Ieee80211MacHeader::getAID() const
{
    return this->AID;
}

void Ieee80211MacHeader::setAID(short AID)
{
    handleChange();
    this->AID = AID;
}

const MacAddress& Ieee80211MacHeader::getReceiverAddress() const
{
    return this->receiverAddress;
}

void Ieee80211MacHeader::setReceiverAddress(const MacAddress& receiverAddress)
{
    handleChange();
    this->receiverAddress = receiverAddress;
}

omnetpp::simtime_t Ieee80211MacHeader::getMACArrive() const
{
    return this->MACArrive;
}

void Ieee80211MacHeader::setMACArrive(omnetpp::simtime_t MACArrive)
{
    handleChange();
    this->MACArrive = MACArrive;
}

class Ieee80211MacHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_toDS,
        FIELD_fromDS,
        FIELD_retry,
        FIELD_moreFragments,
        FIELD_duration,
        FIELD_AID,
        FIELD_receiverAddress,
        FIELD_MACArrive,
    };
  public:
    Ieee80211MacHeaderDescriptor();
    virtual ~Ieee80211MacHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211MacHeaderDescriptor)

Ieee80211MacHeaderDescriptor::Ieee80211MacHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211MacHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ieee80211MacHeaderDescriptor::~Ieee80211MacHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211MacHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211MacHeader *>(obj)!=nullptr;
}

const char **Ieee80211MacHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211MacHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211MacHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ieee80211MacHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_toDS
        FD_ISEDITABLE,    // FIELD_fromDS
        FD_ISEDITABLE,    // FIELD_retry
        FD_ISEDITABLE,    // FIELD_moreFragments
        0,    // FIELD_duration
        FD_ISEDITABLE,    // FIELD_AID
        0,    // FIELD_receiverAddress
        0,    // FIELD_MACArrive
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211MacHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "toDS",
        "fromDS",
        "retry",
        "moreFragments",
        "duration",
        "AID",
        "receiverAddress",
        "MACArrive",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int Ieee80211MacHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "toDS") == 0) return base+1;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fromDS") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "retry") == 0) return base+3;
    if (fieldName[0] == 'm' && strcmp(fieldName, "moreFragments") == 0) return base+4;
    if (fieldName[0] == 'd' && strcmp(fieldName, "duration") == 0) return base+5;
    if (fieldName[0] == 'A' && strcmp(fieldName, "AID") == 0) return base+6;
    if (fieldName[0] == 'r' && strcmp(fieldName, "receiverAddress") == 0) return base+7;
    if (fieldName[0] == 'M' && strcmp(fieldName, "MACArrive") == 0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211MacHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ieee80211::Ieee80211FrameType",    // FIELD_type
        "bool",    // FIELD_toDS
        "bool",    // FIELD_fromDS
        "bool",    // FIELD_retry
        "bool",    // FIELD_moreFragments
        "omnetpp::simtime_t",    // FIELD_duration
        "short",    // FIELD_AID
        "inet::MacAddress",    // FIELD_receiverAddress
        "omnetpp::simtime_t",    // FIELD_MACArrive
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211MacHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211MacHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::ieee80211::Ieee80211FrameType";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211MacHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MacHeader *pp = (Ieee80211MacHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211MacHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MacHeader *pp = (Ieee80211MacHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211MacHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MacHeader *pp = (Ieee80211MacHeader *)object; (void)pp;
    switch (field) {
        case FIELD_type: return enum2string(pp->getType(), "inet::ieee80211::Ieee80211FrameType");
        case FIELD_toDS: return bool2string(pp->getToDS());
        case FIELD_fromDS: return bool2string(pp->getFromDS());
        case FIELD_retry: return bool2string(pp->getRetry());
        case FIELD_moreFragments: return bool2string(pp->getMoreFragments());
        case FIELD_duration: return simtime2string(pp->getDuration());
        case FIELD_AID: return long2string(pp->getAID());
        case FIELD_receiverAddress: return pp->getReceiverAddress().str();
        case FIELD_MACArrive: return simtime2string(pp->getMACArrive());
        default: return "";
    }
}

bool Ieee80211MacHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MacHeader *pp = (Ieee80211MacHeader *)object; (void)pp;
    switch (field) {
        case FIELD_type: pp->setType((inet::ieee80211::Ieee80211FrameType)string2enum(value, "inet::ieee80211::Ieee80211FrameType")); return true;
        case FIELD_toDS: pp->setToDS(string2bool(value)); return true;
        case FIELD_fromDS: pp->setFromDS(string2bool(value)); return true;
        case FIELD_retry: pp->setRetry(string2bool(value)); return true;
        case FIELD_moreFragments: pp->setMoreFragments(string2bool(value)); return true;
        case FIELD_AID: pp->setAID(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211MacHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee80211MacHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MacHeader *pp = (Ieee80211MacHeader *)object; (void)pp;
    switch (field) {
        case FIELD_receiverAddress: return toVoidPtr(&pp->getReceiverAddress()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211OneAddressHeader)

Ieee80211OneAddressHeader::Ieee80211OneAddressHeader() : ::inet::ieee80211::Ieee80211MacHeader()
{
}

Ieee80211OneAddressHeader::Ieee80211OneAddressHeader(const Ieee80211OneAddressHeader& other) : ::inet::ieee80211::Ieee80211MacHeader(other)
{
    copy(other);
}

Ieee80211OneAddressHeader::~Ieee80211OneAddressHeader()
{
}

Ieee80211OneAddressHeader& Ieee80211OneAddressHeader::operator=(const Ieee80211OneAddressHeader& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211MacHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211OneAddressHeader::copy(const Ieee80211OneAddressHeader& other)
{
}

void Ieee80211OneAddressHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211MacHeader::parsimPack(b);
}

void Ieee80211OneAddressHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211MacHeader::parsimUnpack(b);
}

class Ieee80211OneAddressHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211OneAddressHeaderDescriptor();
    virtual ~Ieee80211OneAddressHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211OneAddressHeaderDescriptor)

Ieee80211OneAddressHeaderDescriptor::Ieee80211OneAddressHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211OneAddressHeader)), "inet::ieee80211::Ieee80211MacHeader")
{
    propertynames = nullptr;
}

Ieee80211OneAddressHeaderDescriptor::~Ieee80211OneAddressHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211OneAddressHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211OneAddressHeader *>(obj)!=nullptr;
}

const char **Ieee80211OneAddressHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211OneAddressHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211OneAddressHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211OneAddressHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211OneAddressHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211OneAddressHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211OneAddressHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211OneAddressHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211OneAddressHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211OneAddressHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressHeader *pp = (Ieee80211OneAddressHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211OneAddressHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressHeader *pp = (Ieee80211OneAddressHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211OneAddressHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressHeader *pp = (Ieee80211OneAddressHeader *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211OneAddressHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressHeader *pp = (Ieee80211OneAddressHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211OneAddressHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211OneAddressHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressHeader *pp = (Ieee80211OneAddressHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211AckFrame)

Ieee80211AckFrame::Ieee80211AckFrame() : ::inet::ieee80211::Ieee80211OneAddressHeader()
{
    this->setChunkLength(LENGTH_ACK - B(4));
    this->setType(ST_ACK);
}

Ieee80211AckFrame::Ieee80211AckFrame(const Ieee80211AckFrame& other) : ::inet::ieee80211::Ieee80211OneAddressHeader(other)
{
    copy(other);
}

Ieee80211AckFrame::~Ieee80211AckFrame()
{
}

Ieee80211AckFrame& Ieee80211AckFrame::operator=(const Ieee80211AckFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211OneAddressHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AckFrame::copy(const Ieee80211AckFrame& other)
{
}

void Ieee80211AckFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211OneAddressHeader::parsimPack(b);
}

void Ieee80211AckFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211OneAddressHeader::parsimUnpack(b);
}

class Ieee80211AckFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211AckFrameDescriptor();
    virtual ~Ieee80211AckFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211AckFrameDescriptor)

Ieee80211AckFrameDescriptor::Ieee80211AckFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211AckFrame)), "inet::ieee80211::Ieee80211OneAddressHeader")
{
    propertynames = nullptr;
}

Ieee80211AckFrameDescriptor::~Ieee80211AckFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AckFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AckFrame *>(obj)!=nullptr;
}

const char **Ieee80211AckFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AckFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AckFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211AckFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211AckFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211AckFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AckFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211AckFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AckFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211AckFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AckFrame *pp = (Ieee80211AckFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AckFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AckFrame *pp = (Ieee80211AckFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AckFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AckFrame *pp = (Ieee80211AckFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211AckFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AckFrame *pp = (Ieee80211AckFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211AckFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211AckFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AckFrame *pp = (Ieee80211AckFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211TwoAddressHeader)

Ieee80211TwoAddressHeader::Ieee80211TwoAddressHeader() : ::inet::ieee80211::Ieee80211OneAddressHeader()
{
    this->setChunkLength(LENGTH_RTS - B(4));

}

Ieee80211TwoAddressHeader::Ieee80211TwoAddressHeader(const Ieee80211TwoAddressHeader& other) : ::inet::ieee80211::Ieee80211OneAddressHeader(other)
{
    copy(other);
}

Ieee80211TwoAddressHeader::~Ieee80211TwoAddressHeader()
{
}

Ieee80211TwoAddressHeader& Ieee80211TwoAddressHeader::operator=(const Ieee80211TwoAddressHeader& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211OneAddressHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211TwoAddressHeader::copy(const Ieee80211TwoAddressHeader& other)
{
    this->transmitterAddress = other.transmitterAddress;
}

void Ieee80211TwoAddressHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211OneAddressHeader::parsimPack(b);
    doParsimPacking(b,this->transmitterAddress);
}

void Ieee80211TwoAddressHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211OneAddressHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->transmitterAddress);
}

const MacAddress& Ieee80211TwoAddressHeader::getTransmitterAddress() const
{
    return this->transmitterAddress;
}

void Ieee80211TwoAddressHeader::setTransmitterAddress(const MacAddress& transmitterAddress)
{
    handleChange();
    this->transmitterAddress = transmitterAddress;
}

class Ieee80211TwoAddressHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_transmitterAddress,
    };
  public:
    Ieee80211TwoAddressHeaderDescriptor();
    virtual ~Ieee80211TwoAddressHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211TwoAddressHeaderDescriptor)

Ieee80211TwoAddressHeaderDescriptor::Ieee80211TwoAddressHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211TwoAddressHeader)), "inet::ieee80211::Ieee80211OneAddressHeader")
{
    propertynames = nullptr;
}

Ieee80211TwoAddressHeaderDescriptor::~Ieee80211TwoAddressHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211TwoAddressHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211TwoAddressHeader *>(obj)!=nullptr;
}

const char **Ieee80211TwoAddressHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211TwoAddressHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211TwoAddressHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211TwoAddressHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_transmitterAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211TwoAddressHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "transmitterAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ieee80211TwoAddressHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "transmitterAddress") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211TwoAddressHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MacAddress",    // FIELD_transmitterAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211TwoAddressHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211TwoAddressHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211TwoAddressHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressHeader *pp = (Ieee80211TwoAddressHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211TwoAddressHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressHeader *pp = (Ieee80211TwoAddressHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211TwoAddressHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressHeader *pp = (Ieee80211TwoAddressHeader *)object; (void)pp;
    switch (field) {
        case FIELD_transmitterAddress: return pp->getTransmitterAddress().str();
        default: return "";
    }
}

bool Ieee80211TwoAddressHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressHeader *pp = (Ieee80211TwoAddressHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211TwoAddressHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee80211TwoAddressHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressHeader *pp = (Ieee80211TwoAddressHeader *)object; (void)pp;
    switch (field) {
        case FIELD_transmitterAddress: return toVoidPtr(&pp->getTransmitterAddress()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211RtsFrame)

Ieee80211RtsFrame::Ieee80211RtsFrame() : ::inet::ieee80211::Ieee80211TwoAddressHeader()
{
    this->setChunkLength(LENGTH_RTS - B(4));
    this->setType(ST_RTS);
}

Ieee80211RtsFrame::Ieee80211RtsFrame(const Ieee80211RtsFrame& other) : ::inet::ieee80211::Ieee80211TwoAddressHeader(other)
{
    copy(other);
}

Ieee80211RtsFrame::~Ieee80211RtsFrame()
{
}

Ieee80211RtsFrame& Ieee80211RtsFrame::operator=(const Ieee80211RtsFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211TwoAddressHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211RtsFrame::copy(const Ieee80211RtsFrame& other)
{
}

void Ieee80211RtsFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211TwoAddressHeader::parsimPack(b);
}

void Ieee80211RtsFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211TwoAddressHeader::parsimUnpack(b);
}

class Ieee80211RtsFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211RtsFrameDescriptor();
    virtual ~Ieee80211RtsFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211RtsFrameDescriptor)

Ieee80211RtsFrameDescriptor::Ieee80211RtsFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211RtsFrame)), "inet::ieee80211::Ieee80211TwoAddressHeader")
{
    propertynames = nullptr;
}

Ieee80211RtsFrameDescriptor::~Ieee80211RtsFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211RtsFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211RtsFrame *>(obj)!=nullptr;
}

const char **Ieee80211RtsFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211RtsFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211RtsFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211RtsFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211RtsFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211RtsFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211RtsFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211RtsFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211RtsFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211RtsFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RtsFrame *pp = (Ieee80211RtsFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211RtsFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RtsFrame *pp = (Ieee80211RtsFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211RtsFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RtsFrame *pp = (Ieee80211RtsFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211RtsFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RtsFrame *pp = (Ieee80211RtsFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211RtsFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211RtsFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RtsFrame *pp = (Ieee80211RtsFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211CtsFrame)

Ieee80211CtsFrame::Ieee80211CtsFrame() : ::inet::ieee80211::Ieee80211OneAddressHeader()
{
    this->setChunkLength(LENGTH_CTS - B(4));
    this->setType(ST_CTS);
}

Ieee80211CtsFrame::Ieee80211CtsFrame(const Ieee80211CtsFrame& other) : ::inet::ieee80211::Ieee80211OneAddressHeader(other)
{
    copy(other);
}

Ieee80211CtsFrame::~Ieee80211CtsFrame()
{
}

Ieee80211CtsFrame& Ieee80211CtsFrame::operator=(const Ieee80211CtsFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211OneAddressHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211CtsFrame::copy(const Ieee80211CtsFrame& other)
{
}

void Ieee80211CtsFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211OneAddressHeader::parsimPack(b);
}

void Ieee80211CtsFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211OneAddressHeader::parsimUnpack(b);
}

class Ieee80211CtsFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211CtsFrameDescriptor();
    virtual ~Ieee80211CtsFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211CtsFrameDescriptor)

Ieee80211CtsFrameDescriptor::Ieee80211CtsFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211CtsFrame)), "inet::ieee80211::Ieee80211OneAddressHeader")
{
    propertynames = nullptr;
}

Ieee80211CtsFrameDescriptor::~Ieee80211CtsFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211CtsFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211CtsFrame *>(obj)!=nullptr;
}

const char **Ieee80211CtsFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211CtsFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211CtsFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211CtsFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211CtsFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211CtsFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211CtsFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211CtsFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211CtsFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211CtsFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CtsFrame *pp = (Ieee80211CtsFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211CtsFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CtsFrame *pp = (Ieee80211CtsFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211CtsFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CtsFrame *pp = (Ieee80211CtsFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211CtsFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CtsFrame *pp = (Ieee80211CtsFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211CtsFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211CtsFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CtsFrame *pp = (Ieee80211CtsFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211DataOrMgmtHeader)

Ieee80211DataOrMgmtHeader::Ieee80211DataOrMgmtHeader() : ::inet::ieee80211::Ieee80211TwoAddressHeader()
{
    this->setChunkLength(LENGTH_MGMT - B(4));

}

Ieee80211DataOrMgmtHeader::Ieee80211DataOrMgmtHeader(const Ieee80211DataOrMgmtHeader& other) : ::inet::ieee80211::Ieee80211TwoAddressHeader(other)
{
    copy(other);
}

Ieee80211DataOrMgmtHeader::~Ieee80211DataOrMgmtHeader()
{
}

Ieee80211DataOrMgmtHeader& Ieee80211DataOrMgmtHeader::operator=(const Ieee80211DataOrMgmtHeader& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211TwoAddressHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DataOrMgmtHeader::copy(const Ieee80211DataOrMgmtHeader& other)
{
    this->address3 = other.address3;
    this->fragmentNumber = other.fragmentNumber;
    this->sequenceNumber = other.sequenceNumber;
}

void Ieee80211DataOrMgmtHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211TwoAddressHeader::parsimPack(b);
    doParsimPacking(b,this->address3);
    doParsimPacking(b,this->fragmentNumber);
    doParsimPacking(b,this->sequenceNumber);
}

void Ieee80211DataOrMgmtHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211TwoAddressHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->address3);
    doParsimUnpacking(b,this->fragmentNumber);
    doParsimUnpacking(b,this->sequenceNumber);
}

const MacAddress& Ieee80211DataOrMgmtHeader::getAddress3() const
{
    return this->address3;
}

void Ieee80211DataOrMgmtHeader::setAddress3(const MacAddress& address3)
{
    handleChange();
    this->address3 = address3;
}

short Ieee80211DataOrMgmtHeader::getFragmentNumber() const
{
    return this->fragmentNumber;
}

void Ieee80211DataOrMgmtHeader::setFragmentNumber(short fragmentNumber)
{
    handleChange();
    this->fragmentNumber = fragmentNumber;
}

const SequenceNumber& Ieee80211DataOrMgmtHeader::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void Ieee80211DataOrMgmtHeader::setSequenceNumber(const SequenceNumber& sequenceNumber)
{
    handleChange();
    this->sequenceNumber = sequenceNumber;
}

class Ieee80211DataOrMgmtHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_address3,
        FIELD_fragmentNumber,
        FIELD_sequenceNumber,
    };
  public:
    Ieee80211DataOrMgmtHeaderDescriptor();
    virtual ~Ieee80211DataOrMgmtHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211DataOrMgmtHeaderDescriptor)

Ieee80211DataOrMgmtHeaderDescriptor::Ieee80211DataOrMgmtHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211DataOrMgmtHeader)), "inet::ieee80211::Ieee80211TwoAddressHeader")
{
    propertynames = nullptr;
}

Ieee80211DataOrMgmtHeaderDescriptor::~Ieee80211DataOrMgmtHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DataOrMgmtHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DataOrMgmtHeader *>(obj)!=nullptr;
}

const char **Ieee80211DataOrMgmtHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DataOrMgmtHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DataOrMgmtHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211DataOrMgmtHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_address3
        FD_ISEDITABLE,    // FIELD_fragmentNumber
        0,    // FIELD_sequenceNumber
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211DataOrMgmtHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "address3",
        "fragmentNumber",
        "sequenceNumber",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ieee80211DataOrMgmtHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "address3") == 0) return base+0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fragmentNumber") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "sequenceNumber") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DataOrMgmtHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MacAddress",    // FIELD_address3
        "short",    // FIELD_fragmentNumber
        "inet::SequenceNumber",    // FIELD_sequenceNumber
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DataOrMgmtHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211DataOrMgmtHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211DataOrMgmtHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtHeader *pp = (Ieee80211DataOrMgmtHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DataOrMgmtHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtHeader *pp = (Ieee80211DataOrMgmtHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DataOrMgmtHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtHeader *pp = (Ieee80211DataOrMgmtHeader *)object; (void)pp;
    switch (field) {
        case FIELD_address3: return pp->getAddress3().str();
        case FIELD_fragmentNumber: return long2string(pp->getFragmentNumber());
        case FIELD_sequenceNumber: {std::stringstream out; out << pp->getSequenceNumber(); return out.str();}
        default: return "";
    }
}

bool Ieee80211DataOrMgmtHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtHeader *pp = (Ieee80211DataOrMgmtHeader *)object; (void)pp;
    switch (field) {
        case FIELD_fragmentNumber: pp->setFragmentNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211DataOrMgmtHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee80211DataOrMgmtHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtHeader *pp = (Ieee80211DataOrMgmtHeader *)object; (void)pp;
    switch (field) {
        case FIELD_address3: return toVoidPtr(&pp->getAddress3()); break;
        case FIELD_sequenceNumber: return toVoidPtr(&pp->getSequenceNumber()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211DataHeader)

Ieee80211DataHeader::Ieee80211DataHeader() : ::inet::ieee80211::Ieee80211DataOrMgmtHeader()
{
    this->setChunkLength(DATAFRAME_HEADER_MINLENGTH);
    this->setType(ST_DATA);

}

Ieee80211DataHeader::Ieee80211DataHeader(const Ieee80211DataHeader& other) : ::inet::ieee80211::Ieee80211DataOrMgmtHeader(other)
{
    copy(other);
}

Ieee80211DataHeader::~Ieee80211DataHeader()
{
}

Ieee80211DataHeader& Ieee80211DataHeader::operator=(const Ieee80211DataHeader& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211DataOrMgmtHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DataHeader::copy(const Ieee80211DataHeader& other)
{
    this->address4 = other.address4;
    this->ackPolicy = other.ackPolicy;
    this->tid = other.tid;
    this->aMsduPresent = other.aMsduPresent;
}

void Ieee80211DataHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211DataOrMgmtHeader::parsimPack(b);
    doParsimPacking(b,this->address4);
    doParsimPacking(b,this->ackPolicy);
    doParsimPacking(b,this->tid);
    doParsimPacking(b,this->aMsduPresent);
}

void Ieee80211DataHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211DataOrMgmtHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->address4);
    doParsimUnpacking(b,this->ackPolicy);
    doParsimUnpacking(b,this->tid);
    doParsimUnpacking(b,this->aMsduPresent);
}

const MacAddress& Ieee80211DataHeader::getAddress4() const
{
    return this->address4;
}

void Ieee80211DataHeader::setAddress4(const MacAddress& address4)
{
    handleChange();
    this->address4 = address4;
}

inet::ieee80211::AckPolicy Ieee80211DataHeader::getAckPolicy() const
{
    return this->ackPolicy;
}

void Ieee80211DataHeader::setAckPolicy(inet::ieee80211::AckPolicy ackPolicy)
{
    handleChange();
    this->ackPolicy = ackPolicy;
}

uint8_t Ieee80211DataHeader::getTid() const
{
    return this->tid;
}

void Ieee80211DataHeader::setTid(uint8_t tid)
{
    handleChange();
    this->tid = tid;
}

bool Ieee80211DataHeader::getAMsduPresent() const
{
    return this->aMsduPresent;
}

void Ieee80211DataHeader::setAMsduPresent(bool aMsduPresent)
{
    handleChange();
    this->aMsduPresent = aMsduPresent;
}

class Ieee80211DataHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_address4,
        FIELD_ackPolicy,
        FIELD_tid,
        FIELD_aMsduPresent,
    };
  public:
    Ieee80211DataHeaderDescriptor();
    virtual ~Ieee80211DataHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211DataHeaderDescriptor)

Ieee80211DataHeaderDescriptor::Ieee80211DataHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211DataHeader)), "inet::ieee80211::Ieee80211DataOrMgmtHeader")
{
    propertynames = nullptr;
}

Ieee80211DataHeaderDescriptor::~Ieee80211DataHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DataHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DataHeader *>(obj)!=nullptr;
}

const char **Ieee80211DataHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DataHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DataHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211DataHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_address4
        FD_ISEDITABLE,    // FIELD_ackPolicy
        FD_ISEDITABLE,    // FIELD_tid
        FD_ISEDITABLE,    // FIELD_aMsduPresent
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211DataHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "address4",
        "ackPolicy",
        "tid",
        "aMsduPresent",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Ieee80211DataHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "address4") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "ackPolicy") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "tid") == 0) return base+2;
    if (fieldName[0] == 'a' && strcmp(fieldName, "aMsduPresent") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DataHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MacAddress",    // FIELD_address4
        "inet::ieee80211::AckPolicy",    // FIELD_ackPolicy
        "uint8",    // FIELD_tid
        "bool",    // FIELD_aMsduPresent
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DataHeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_ackPolicy: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211DataHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_ackPolicy:
            if (!strcmp(propertyname, "enum")) return "inet::ieee80211::AckPolicy";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211DataHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataHeader *pp = (Ieee80211DataHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DataHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataHeader *pp = (Ieee80211DataHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DataHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataHeader *pp = (Ieee80211DataHeader *)object; (void)pp;
    switch (field) {
        case FIELD_address4: return pp->getAddress4().str();
        case FIELD_ackPolicy: return enum2string(pp->getAckPolicy(), "inet::ieee80211::AckPolicy");
        case FIELD_tid: return ulong2string(pp->getTid());
        case FIELD_aMsduPresent: return bool2string(pp->getAMsduPresent());
        default: return "";
    }
}

bool Ieee80211DataHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataHeader *pp = (Ieee80211DataHeader *)object; (void)pp;
    switch (field) {
        case FIELD_ackPolicy: pp->setAckPolicy((inet::ieee80211::AckPolicy)string2enum(value, "inet::ieee80211::AckPolicy")); return true;
        case FIELD_tid: pp->setTid(string2ulong(value)); return true;
        case FIELD_aMsduPresent: pp->setAMsduPresent(string2bool(value)); return true;
        default: return false;
    }
}

const char *Ieee80211DataHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee80211DataHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataHeader *pp = (Ieee80211DataHeader *)object; (void)pp;
    switch (field) {
        case FIELD_address4: return toVoidPtr(&pp->getAddress4()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211MgmtHeader)

Ieee80211MgmtHeader::Ieee80211MgmtHeader() : ::inet::ieee80211::Ieee80211DataOrMgmtHeader()
{
}

Ieee80211MgmtHeader::Ieee80211MgmtHeader(const Ieee80211MgmtHeader& other) : ::inet::ieee80211::Ieee80211DataOrMgmtHeader(other)
{
    copy(other);
}

Ieee80211MgmtHeader::~Ieee80211MgmtHeader()
{
}

Ieee80211MgmtHeader& Ieee80211MgmtHeader::operator=(const Ieee80211MgmtHeader& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211DataOrMgmtHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211MgmtHeader::copy(const Ieee80211MgmtHeader& other)
{
}

void Ieee80211MgmtHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211DataOrMgmtHeader::parsimPack(b);
}

void Ieee80211MgmtHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211DataOrMgmtHeader::parsimUnpack(b);
}

class Ieee80211MgmtHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211MgmtHeaderDescriptor();
    virtual ~Ieee80211MgmtHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211MgmtHeaderDescriptor)

Ieee80211MgmtHeaderDescriptor::Ieee80211MgmtHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211MgmtHeader)), "inet::ieee80211::Ieee80211DataOrMgmtHeader")
{
    propertynames = nullptr;
}

Ieee80211MgmtHeaderDescriptor::~Ieee80211MgmtHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211MgmtHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211MgmtHeader *>(obj)!=nullptr;
}

const char **Ieee80211MgmtHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211MgmtHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211MgmtHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211MgmtHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211MgmtHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211MgmtHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211MgmtHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211MgmtHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211MgmtHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211MgmtHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MgmtHeader *pp = (Ieee80211MgmtHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211MgmtHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MgmtHeader *pp = (Ieee80211MgmtHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211MgmtHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MgmtHeader *pp = (Ieee80211MgmtHeader *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211MgmtHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MgmtHeader *pp = (Ieee80211MgmtHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211MgmtHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211MgmtHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MgmtHeader *pp = (Ieee80211MgmtHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211ActionFrame)

Ieee80211ActionFrame::Ieee80211ActionFrame() : ::inet::ieee80211::Ieee80211MgmtHeader()
{
    this->setType(ST_ACTION);

}

Ieee80211ActionFrame::Ieee80211ActionFrame(const Ieee80211ActionFrame& other) : ::inet::ieee80211::Ieee80211MgmtHeader(other)
{
    copy(other);
}

Ieee80211ActionFrame::~Ieee80211ActionFrame()
{
}

Ieee80211ActionFrame& Ieee80211ActionFrame::operator=(const Ieee80211ActionFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211MgmtHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ActionFrame::copy(const Ieee80211ActionFrame& other)
{
    this->category = other.category;
}

void Ieee80211ActionFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211MgmtHeader::parsimPack(b);
    doParsimPacking(b,this->category);
}

void Ieee80211ActionFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211MgmtHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->category);
}

short Ieee80211ActionFrame::getCategory() const
{
    return this->category;
}

void Ieee80211ActionFrame::setCategory(short category)
{
    handleChange();
    this->category = category;
}

class Ieee80211ActionFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_category,
    };
  public:
    Ieee80211ActionFrameDescriptor();
    virtual ~Ieee80211ActionFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211ActionFrameDescriptor)

Ieee80211ActionFrameDescriptor::Ieee80211ActionFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211ActionFrame)), "inet::ieee80211::Ieee80211MgmtHeader")
{
    propertynames = nullptr;
}

Ieee80211ActionFrameDescriptor::~Ieee80211ActionFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ActionFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ActionFrame *>(obj)!=nullptr;
}

const char **Ieee80211ActionFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ActionFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ActionFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211ActionFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_category
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211ActionFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "category",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ieee80211ActionFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "category") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ActionFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_category
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ActionFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ActionFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ActionFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrame *pp = (Ieee80211ActionFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ActionFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrame *pp = (Ieee80211ActionFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ActionFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrame *pp = (Ieee80211ActionFrame *)object; (void)pp;
    switch (field) {
        case FIELD_category: return long2string(pp->getCategory());
        default: return "";
    }
}

bool Ieee80211ActionFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrame *pp = (Ieee80211ActionFrame *)object; (void)pp;
    switch (field) {
        case FIELD_category: pp->setCategory(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211ActionFrameDescriptor::getFieldStructName(int field) const
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

void *Ieee80211ActionFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrame *pp = (Ieee80211ActionFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211MsduSubframeHeader)

Ieee80211MsduSubframeHeader::Ieee80211MsduSubframeHeader() : ::inet::FieldsChunk()
{
    this->setChunkLength(LENGTH_A_MSDU_SUBFRAME_HEADER);

}

Ieee80211MsduSubframeHeader::Ieee80211MsduSubframeHeader(const Ieee80211MsduSubframeHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ieee80211MsduSubframeHeader::~Ieee80211MsduSubframeHeader()
{
}

Ieee80211MsduSubframeHeader& Ieee80211MsduSubframeHeader::operator=(const Ieee80211MsduSubframeHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211MsduSubframeHeader::copy(const Ieee80211MsduSubframeHeader& other)
{
    this->sa = other.sa;
    this->da = other.da;
    this->length = other.length;
}

void Ieee80211MsduSubframeHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->sa);
    doParsimPacking(b,this->da);
    doParsimPacking(b,this->length);
}

void Ieee80211MsduSubframeHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->sa);
    doParsimUnpacking(b,this->da);
    doParsimUnpacking(b,this->length);
}

const MacAddress& Ieee80211MsduSubframeHeader::getSa() const
{
    return this->sa;
}

void Ieee80211MsduSubframeHeader::setSa(const MacAddress& sa)
{
    handleChange();
    this->sa = sa;
}

const MacAddress& Ieee80211MsduSubframeHeader::getDa() const
{
    return this->da;
}

void Ieee80211MsduSubframeHeader::setDa(const MacAddress& da)
{
    handleChange();
    this->da = da;
}

int Ieee80211MsduSubframeHeader::getLength() const
{
    return this->length;
}

void Ieee80211MsduSubframeHeader::setLength(int length)
{
    handleChange();
    this->length = length;
}

class Ieee80211MsduSubframeHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_sa,
        FIELD_da,
        FIELD_length,
    };
  public:
    Ieee80211MsduSubframeHeaderDescriptor();
    virtual ~Ieee80211MsduSubframeHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211MsduSubframeHeaderDescriptor)

Ieee80211MsduSubframeHeaderDescriptor::Ieee80211MsduSubframeHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211MsduSubframeHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ieee80211MsduSubframeHeaderDescriptor::~Ieee80211MsduSubframeHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211MsduSubframeHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211MsduSubframeHeader *>(obj)!=nullptr;
}

const char **Ieee80211MsduSubframeHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211MsduSubframeHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211MsduSubframeHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211MsduSubframeHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_sa
        0,    // FIELD_da
        FD_ISEDITABLE,    // FIELD_length
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211MsduSubframeHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sa",
        "da",
        "length",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ieee80211MsduSubframeHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sa") == 0) return base+0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "da") == 0) return base+1;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211MsduSubframeHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MacAddress",    // FIELD_sa
        "inet::MacAddress",    // FIELD_da
        "int",    // FIELD_length
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211MsduSubframeHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211MsduSubframeHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211MsduSubframeHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MsduSubframeHeader *pp = (Ieee80211MsduSubframeHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211MsduSubframeHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MsduSubframeHeader *pp = (Ieee80211MsduSubframeHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211MsduSubframeHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MsduSubframeHeader *pp = (Ieee80211MsduSubframeHeader *)object; (void)pp;
    switch (field) {
        case FIELD_sa: return pp->getSa().str();
        case FIELD_da: return pp->getDa().str();
        case FIELD_length: return long2string(pp->getLength());
        default: return "";
    }
}

bool Ieee80211MsduSubframeHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MsduSubframeHeader *pp = (Ieee80211MsduSubframeHeader *)object; (void)pp;
    switch (field) {
        case FIELD_length: pp->setLength(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211MsduSubframeHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee80211MsduSubframeHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MsduSubframeHeader *pp = (Ieee80211MsduSubframeHeader *)object; (void)pp;
    switch (field) {
        case FIELD_sa: return toVoidPtr(&pp->getSa()); break;
        case FIELD_da: return toVoidPtr(&pp->getDa()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211MpduSubframeHeader)

Ieee80211MpduSubframeHeader::Ieee80211MpduSubframeHeader() : ::inet::FieldsChunk()
{
    this->setChunkLength(LENGTH_A_MPDU_SUBFRAME_HEADER);

}

Ieee80211MpduSubframeHeader::Ieee80211MpduSubframeHeader(const Ieee80211MpduSubframeHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ieee80211MpduSubframeHeader::~Ieee80211MpduSubframeHeader()
{
}

Ieee80211MpduSubframeHeader& Ieee80211MpduSubframeHeader::operator=(const Ieee80211MpduSubframeHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211MpduSubframeHeader::copy(const Ieee80211MpduSubframeHeader& other)
{
    this->length = other.length;
}

void Ieee80211MpduSubframeHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->length);
}

void Ieee80211MpduSubframeHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->length);
}

int Ieee80211MpduSubframeHeader::getLength() const
{
    return this->length;
}

void Ieee80211MpduSubframeHeader::setLength(int length)
{
    handleChange();
    this->length = length;
}

class Ieee80211MpduSubframeHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_length,
    };
  public:
    Ieee80211MpduSubframeHeaderDescriptor();
    virtual ~Ieee80211MpduSubframeHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211MpduSubframeHeaderDescriptor)

Ieee80211MpduSubframeHeaderDescriptor::Ieee80211MpduSubframeHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211MpduSubframeHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ieee80211MpduSubframeHeaderDescriptor::~Ieee80211MpduSubframeHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211MpduSubframeHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211MpduSubframeHeader *>(obj)!=nullptr;
}

const char **Ieee80211MpduSubframeHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211MpduSubframeHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211MpduSubframeHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211MpduSubframeHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_length
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211MpduSubframeHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "length",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ieee80211MpduSubframeHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211MpduSubframeHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_length
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211MpduSubframeHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211MpduSubframeHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211MpduSubframeHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MpduSubframeHeader *pp = (Ieee80211MpduSubframeHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211MpduSubframeHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MpduSubframeHeader *pp = (Ieee80211MpduSubframeHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211MpduSubframeHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MpduSubframeHeader *pp = (Ieee80211MpduSubframeHeader *)object; (void)pp;
    switch (field) {
        case FIELD_length: return long2string(pp->getLength());
        default: return "";
    }
}

bool Ieee80211MpduSubframeHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MpduSubframeHeader *pp = (Ieee80211MpduSubframeHeader *)object; (void)pp;
    switch (field) {
        case FIELD_length: pp->setLength(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211MpduSubframeHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee80211MpduSubframeHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MpduSubframeHeader *pp = (Ieee80211MpduSubframeHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211AddbaRequest)

Ieee80211AddbaRequest::Ieee80211AddbaRequest() : ::inet::ieee80211::Ieee80211ActionFrame()
{
    this->setChunkLength(LENGTH_ADDBAREQ - B(4));
    this->setCategory(3);

}

Ieee80211AddbaRequest::Ieee80211AddbaRequest(const Ieee80211AddbaRequest& other) : ::inet::ieee80211::Ieee80211ActionFrame(other)
{
    copy(other);
}

Ieee80211AddbaRequest::~Ieee80211AddbaRequest()
{
}

Ieee80211AddbaRequest& Ieee80211AddbaRequest::operator=(const Ieee80211AddbaRequest& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211ActionFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AddbaRequest::copy(const Ieee80211AddbaRequest& other)
{
    this->blockAckAction = other.blockAckAction;
    this->dialogToken = other.dialogToken;
    this->aMsduSupported = other.aMsduSupported;
    this->blockAckPolicy = other.blockAckPolicy;
    this->tid = other.tid;
    this->bufferSize = other.bufferSize;
    this->blockAckTimeoutValue = other.blockAckTimeoutValue;
    this->_fragmentNumber = other._fragmentNumber;
    this->startingSequenceNumber = other.startingSequenceNumber;
}

void Ieee80211AddbaRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ActionFrame::parsimPack(b);
    doParsimPacking(b,this->blockAckAction);
    doParsimPacking(b,this->dialogToken);
    doParsimPacking(b,this->aMsduSupported);
    doParsimPacking(b,this->blockAckPolicy);
    doParsimPacking(b,this->tid);
    doParsimPacking(b,this->bufferSize);
    doParsimPacking(b,this->blockAckTimeoutValue);
    doParsimPacking(b,this->_fragmentNumber);
    doParsimPacking(b,this->startingSequenceNumber);
}

void Ieee80211AddbaRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ActionFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->blockAckAction);
    doParsimUnpacking(b,this->dialogToken);
    doParsimUnpacking(b,this->aMsduSupported);
    doParsimUnpacking(b,this->blockAckPolicy);
    doParsimUnpacking(b,this->tid);
    doParsimUnpacking(b,this->bufferSize);
    doParsimUnpacking(b,this->blockAckTimeoutValue);
    doParsimUnpacking(b,this->_fragmentNumber);
    doParsimUnpacking(b,this->startingSequenceNumber);
}

int Ieee80211AddbaRequest::getBlockAckAction() const
{
    return this->blockAckAction;
}

void Ieee80211AddbaRequest::setBlockAckAction(int blockAckAction)
{
    handleChange();
    this->blockAckAction = blockAckAction;
}

int Ieee80211AddbaRequest::getDialogToken() const
{
    return this->dialogToken;
}

void Ieee80211AddbaRequest::setDialogToken(int dialogToken)
{
    handleChange();
    this->dialogToken = dialogToken;
}

bool Ieee80211AddbaRequest::getAMsduSupported() const
{
    return this->aMsduSupported;
}

void Ieee80211AddbaRequest::setAMsduSupported(bool aMsduSupported)
{
    handleChange();
    this->aMsduSupported = aMsduSupported;
}

bool Ieee80211AddbaRequest::getBlockAckPolicy() const
{
    return this->blockAckPolicy;
}

void Ieee80211AddbaRequest::setBlockAckPolicy(bool blockAckPolicy)
{
    handleChange();
    this->blockAckPolicy = blockAckPolicy;
}

int Ieee80211AddbaRequest::getTid() const
{
    return this->tid;
}

void Ieee80211AddbaRequest::setTid(int tid)
{
    handleChange();
    this->tid = tid;
}

int Ieee80211AddbaRequest::getBufferSize() const
{
    return this->bufferSize;
}

void Ieee80211AddbaRequest::setBufferSize(int bufferSize)
{
    handleChange();
    this->bufferSize = bufferSize;
}

omnetpp::simtime_t Ieee80211AddbaRequest::getBlockAckTimeoutValue() const
{
    return this->blockAckTimeoutValue;
}

void Ieee80211AddbaRequest::setBlockAckTimeoutValue(omnetpp::simtime_t blockAckTimeoutValue)
{
    handleChange();
    this->blockAckTimeoutValue = blockAckTimeoutValue;
}

int Ieee80211AddbaRequest::get_fragmentNumber() const
{
    return this->_fragmentNumber;
}

void Ieee80211AddbaRequest::set_fragmentNumber(int _fragmentNumber)
{
    handleChange();
    this->_fragmentNumber = _fragmentNumber;
}

const SequenceNumber& Ieee80211AddbaRequest::getStartingSequenceNumber() const
{
    return this->startingSequenceNumber;
}

void Ieee80211AddbaRequest::setStartingSequenceNumber(const SequenceNumber& startingSequenceNumber)
{
    handleChange();
    this->startingSequenceNumber = startingSequenceNumber;
}

class Ieee80211AddbaRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_blockAckAction,
        FIELD_dialogToken,
        FIELD_aMsduSupported,
        FIELD_blockAckPolicy,
        FIELD_tid,
        FIELD_bufferSize,
        FIELD_blockAckTimeoutValue,
        FIELD__fragmentNumber,
        FIELD_startingSequenceNumber,
    };
  public:
    Ieee80211AddbaRequestDescriptor();
    virtual ~Ieee80211AddbaRequestDescriptor();

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

Register_ClassDescriptor(Ieee80211AddbaRequestDescriptor)

Ieee80211AddbaRequestDescriptor::Ieee80211AddbaRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211AddbaRequest)), "inet::ieee80211::Ieee80211ActionFrame")
{
    propertynames = nullptr;
}

Ieee80211AddbaRequestDescriptor::~Ieee80211AddbaRequestDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AddbaRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AddbaRequest *>(obj)!=nullptr;
}

const char **Ieee80211AddbaRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AddbaRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AddbaRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ieee80211AddbaRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_blockAckAction
        FD_ISEDITABLE,    // FIELD_dialogToken
        FD_ISEDITABLE,    // FIELD_aMsduSupported
        FD_ISEDITABLE,    // FIELD_blockAckPolicy
        FD_ISEDITABLE,    // FIELD_tid
        FD_ISEDITABLE,    // FIELD_bufferSize
        0,    // FIELD_blockAckTimeoutValue
        FD_ISEDITABLE,    // FIELD__fragmentNumber
        0,    // FIELD_startingSequenceNumber
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211AddbaRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "blockAckAction",
        "dialogToken",
        "aMsduSupported",
        "blockAckPolicy",
        "tid",
        "bufferSize",
        "blockAckTimeoutValue",
        "_fragmentNumber",
        "startingSequenceNumber",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int Ieee80211AddbaRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "blockAckAction") == 0) return base+0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dialogToken") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "aMsduSupported") == 0) return base+2;
    if (fieldName[0] == 'b' && strcmp(fieldName, "blockAckPolicy") == 0) return base+3;
    if (fieldName[0] == 't' && strcmp(fieldName, "tid") == 0) return base+4;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bufferSize") == 0) return base+5;
    if (fieldName[0] == 'b' && strcmp(fieldName, "blockAckTimeoutValue") == 0) return base+6;
    if (fieldName[0] == '_' && strcmp(fieldName, "_fragmentNumber") == 0) return base+7;
    if (fieldName[0] == 's' && strcmp(fieldName, "startingSequenceNumber") == 0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AddbaRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_blockAckAction
        "int",    // FIELD_dialogToken
        "bool",    // FIELD_aMsduSupported
        "bool",    // FIELD_blockAckPolicy
        "int",    // FIELD_tid
        "int",    // FIELD_bufferSize
        "omnetpp::simtime_t",    // FIELD_blockAckTimeoutValue
        "int",    // FIELD__fragmentNumber
        "inet::SequenceNumber",    // FIELD_startingSequenceNumber
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AddbaRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AddbaRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211AddbaRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaRequest *pp = (Ieee80211AddbaRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AddbaRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaRequest *pp = (Ieee80211AddbaRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AddbaRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaRequest *pp = (Ieee80211AddbaRequest *)object; (void)pp;
    switch (field) {
        case FIELD_blockAckAction: return long2string(pp->getBlockAckAction());
        case FIELD_dialogToken: return long2string(pp->getDialogToken());
        case FIELD_aMsduSupported: return bool2string(pp->getAMsduSupported());
        case FIELD_blockAckPolicy: return bool2string(pp->getBlockAckPolicy());
        case FIELD_tid: return long2string(pp->getTid());
        case FIELD_bufferSize: return long2string(pp->getBufferSize());
        case FIELD_blockAckTimeoutValue: return simtime2string(pp->getBlockAckTimeoutValue());
        case FIELD__fragmentNumber: return long2string(pp->get_fragmentNumber());
        case FIELD_startingSequenceNumber: {std::stringstream out; out << pp->getStartingSequenceNumber(); return out.str();}
        default: return "";
    }
}

bool Ieee80211AddbaRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaRequest *pp = (Ieee80211AddbaRequest *)object; (void)pp;
    switch (field) {
        case FIELD_blockAckAction: pp->setBlockAckAction(string2long(value)); return true;
        case FIELD_dialogToken: pp->setDialogToken(string2long(value)); return true;
        case FIELD_aMsduSupported: pp->setAMsduSupported(string2bool(value)); return true;
        case FIELD_blockAckPolicy: pp->setBlockAckPolicy(string2bool(value)); return true;
        case FIELD_tid: pp->setTid(string2long(value)); return true;
        case FIELD_bufferSize: pp->setBufferSize(string2long(value)); return true;
        case FIELD__fragmentNumber: pp->set_fragmentNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211AddbaRequestDescriptor::getFieldStructName(int field) const
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

void *Ieee80211AddbaRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaRequest *pp = (Ieee80211AddbaRequest *)object; (void)pp;
    switch (field) {
        case FIELD_startingSequenceNumber: return toVoidPtr(&pp->getStartingSequenceNumber()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211AddbaResponse)

Ieee80211AddbaResponse::Ieee80211AddbaResponse() : ::inet::ieee80211::Ieee80211ActionFrame()
{
    this->setCategory(3);

}

Ieee80211AddbaResponse::Ieee80211AddbaResponse(const Ieee80211AddbaResponse& other) : ::inet::ieee80211::Ieee80211ActionFrame(other)
{
    copy(other);
}

Ieee80211AddbaResponse::~Ieee80211AddbaResponse()
{
}

Ieee80211AddbaResponse& Ieee80211AddbaResponse::operator=(const Ieee80211AddbaResponse& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211ActionFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AddbaResponse::copy(const Ieee80211AddbaResponse& other)
{
    this->blockAckAction = other.blockAckAction;
    this->dialogToken = other.dialogToken;
    this->statusCode = other.statusCode;
    this->aMsduSupported = other.aMsduSupported;
    this->blockAckPolicy = other.blockAckPolicy;
    this->tid = other.tid;
    this->bufferSize = other.bufferSize;
    this->blockAckTimeoutValue = other.blockAckTimeoutValue;
}

void Ieee80211AddbaResponse::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ActionFrame::parsimPack(b);
    doParsimPacking(b,this->blockAckAction);
    doParsimPacking(b,this->dialogToken);
    doParsimPacking(b,this->statusCode);
    doParsimPacking(b,this->aMsduSupported);
    doParsimPacking(b,this->blockAckPolicy);
    doParsimPacking(b,this->tid);
    doParsimPacking(b,this->bufferSize);
    doParsimPacking(b,this->blockAckTimeoutValue);
}

void Ieee80211AddbaResponse::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ActionFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->blockAckAction);
    doParsimUnpacking(b,this->dialogToken);
    doParsimUnpacking(b,this->statusCode);
    doParsimUnpacking(b,this->aMsduSupported);
    doParsimUnpacking(b,this->blockAckPolicy);
    doParsimUnpacking(b,this->tid);
    doParsimUnpacking(b,this->bufferSize);
    doParsimUnpacking(b,this->blockAckTimeoutValue);
}

int Ieee80211AddbaResponse::getBlockAckAction() const
{
    return this->blockAckAction;
}

void Ieee80211AddbaResponse::setBlockAckAction(int blockAckAction)
{
    handleChange();
    this->blockAckAction = blockAckAction;
}

int Ieee80211AddbaResponse::getDialogToken() const
{
    return this->dialogToken;
}

void Ieee80211AddbaResponse::setDialogToken(int dialogToken)
{
    handleChange();
    this->dialogToken = dialogToken;
}

int Ieee80211AddbaResponse::getStatusCode() const
{
    return this->statusCode;
}

void Ieee80211AddbaResponse::setStatusCode(int statusCode)
{
    handleChange();
    this->statusCode = statusCode;
}

bool Ieee80211AddbaResponse::getAMsduSupported() const
{
    return this->aMsduSupported;
}

void Ieee80211AddbaResponse::setAMsduSupported(bool aMsduSupported)
{
    handleChange();
    this->aMsduSupported = aMsduSupported;
}

bool Ieee80211AddbaResponse::getBlockAckPolicy() const
{
    return this->blockAckPolicy;
}

void Ieee80211AddbaResponse::setBlockAckPolicy(bool blockAckPolicy)
{
    handleChange();
    this->blockAckPolicy = blockAckPolicy;
}

int Ieee80211AddbaResponse::getTid() const
{
    return this->tid;
}

void Ieee80211AddbaResponse::setTid(int tid)
{
    handleChange();
    this->tid = tid;
}

int Ieee80211AddbaResponse::getBufferSize() const
{
    return this->bufferSize;
}

void Ieee80211AddbaResponse::setBufferSize(int bufferSize)
{
    handleChange();
    this->bufferSize = bufferSize;
}

omnetpp::simtime_t Ieee80211AddbaResponse::getBlockAckTimeoutValue() const
{
    return this->blockAckTimeoutValue;
}

void Ieee80211AddbaResponse::setBlockAckTimeoutValue(omnetpp::simtime_t blockAckTimeoutValue)
{
    handleChange();
    this->blockAckTimeoutValue = blockAckTimeoutValue;
}

class Ieee80211AddbaResponseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_blockAckAction,
        FIELD_dialogToken,
        FIELD_statusCode,
        FIELD_aMsduSupported,
        FIELD_blockAckPolicy,
        FIELD_tid,
        FIELD_bufferSize,
        FIELD_blockAckTimeoutValue,
    };
  public:
    Ieee80211AddbaResponseDescriptor();
    virtual ~Ieee80211AddbaResponseDescriptor();

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

Register_ClassDescriptor(Ieee80211AddbaResponseDescriptor)

Ieee80211AddbaResponseDescriptor::Ieee80211AddbaResponseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211AddbaResponse)), "inet::ieee80211::Ieee80211ActionFrame")
{
    propertynames = nullptr;
}

Ieee80211AddbaResponseDescriptor::~Ieee80211AddbaResponseDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AddbaResponseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AddbaResponse *>(obj)!=nullptr;
}

const char **Ieee80211AddbaResponseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AddbaResponseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AddbaResponseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int Ieee80211AddbaResponseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_blockAckAction
        FD_ISEDITABLE,    // FIELD_dialogToken
        FD_ISEDITABLE,    // FIELD_statusCode
        FD_ISEDITABLE,    // FIELD_aMsduSupported
        FD_ISEDITABLE,    // FIELD_blockAckPolicy
        FD_ISEDITABLE,    // FIELD_tid
        FD_ISEDITABLE,    // FIELD_bufferSize
        0,    // FIELD_blockAckTimeoutValue
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211AddbaResponseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "blockAckAction",
        "dialogToken",
        "statusCode",
        "aMsduSupported",
        "blockAckPolicy",
        "tid",
        "bufferSize",
        "blockAckTimeoutValue",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int Ieee80211AddbaResponseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "blockAckAction") == 0) return base+0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dialogToken") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "statusCode") == 0) return base+2;
    if (fieldName[0] == 'a' && strcmp(fieldName, "aMsduSupported") == 0) return base+3;
    if (fieldName[0] == 'b' && strcmp(fieldName, "blockAckPolicy") == 0) return base+4;
    if (fieldName[0] == 't' && strcmp(fieldName, "tid") == 0) return base+5;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bufferSize") == 0) return base+6;
    if (fieldName[0] == 'b' && strcmp(fieldName, "blockAckTimeoutValue") == 0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AddbaResponseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_blockAckAction
        "int",    // FIELD_dialogToken
        "int",    // FIELD_statusCode
        "bool",    // FIELD_aMsduSupported
        "bool",    // FIELD_blockAckPolicy
        "int",    // FIELD_tid
        "int",    // FIELD_bufferSize
        "omnetpp::simtime_t",    // FIELD_blockAckTimeoutValue
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AddbaResponseDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AddbaResponseDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211AddbaResponseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaResponse *pp = (Ieee80211AddbaResponse *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AddbaResponseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaResponse *pp = (Ieee80211AddbaResponse *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AddbaResponseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaResponse *pp = (Ieee80211AddbaResponse *)object; (void)pp;
    switch (field) {
        case FIELD_blockAckAction: return long2string(pp->getBlockAckAction());
        case FIELD_dialogToken: return long2string(pp->getDialogToken());
        case FIELD_statusCode: return long2string(pp->getStatusCode());
        case FIELD_aMsduSupported: return bool2string(pp->getAMsduSupported());
        case FIELD_blockAckPolicy: return bool2string(pp->getBlockAckPolicy());
        case FIELD_tid: return long2string(pp->getTid());
        case FIELD_bufferSize: return long2string(pp->getBufferSize());
        case FIELD_blockAckTimeoutValue: return simtime2string(pp->getBlockAckTimeoutValue());
        default: return "";
    }
}

bool Ieee80211AddbaResponseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaResponse *pp = (Ieee80211AddbaResponse *)object; (void)pp;
    switch (field) {
        case FIELD_blockAckAction: pp->setBlockAckAction(string2long(value)); return true;
        case FIELD_dialogToken: pp->setDialogToken(string2long(value)); return true;
        case FIELD_statusCode: pp->setStatusCode(string2long(value)); return true;
        case FIELD_aMsduSupported: pp->setAMsduSupported(string2bool(value)); return true;
        case FIELD_blockAckPolicy: pp->setBlockAckPolicy(string2bool(value)); return true;
        case FIELD_tid: pp->setTid(string2long(value)); return true;
        case FIELD_bufferSize: pp->setBufferSize(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211AddbaResponseDescriptor::getFieldStructName(int field) const
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

void *Ieee80211AddbaResponseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaResponse *pp = (Ieee80211AddbaResponse *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211Delba)

Ieee80211Delba::Ieee80211Delba() : ::inet::ieee80211::Ieee80211ActionFrame()
{
    this->setCategory(3);

}

Ieee80211Delba::Ieee80211Delba(const Ieee80211Delba& other) : ::inet::ieee80211::Ieee80211ActionFrame(other)
{
    copy(other);
}

Ieee80211Delba::~Ieee80211Delba()
{
}

Ieee80211Delba& Ieee80211Delba::operator=(const Ieee80211Delba& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211ActionFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211Delba::copy(const Ieee80211Delba& other)
{
    this->blockAckAction = other.blockAckAction;
    this->initiator = other.initiator;
    this->tid = other.tid;
    this->reasonCode = other.reasonCode;
}

void Ieee80211Delba::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ActionFrame::parsimPack(b);
    doParsimPacking(b,this->blockAckAction);
    doParsimPacking(b,this->initiator);
    doParsimPacking(b,this->tid);
    doParsimPacking(b,this->reasonCode);
}

void Ieee80211Delba::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ActionFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->blockAckAction);
    doParsimUnpacking(b,this->initiator);
    doParsimUnpacking(b,this->tid);
    doParsimUnpacking(b,this->reasonCode);
}

int Ieee80211Delba::getBlockAckAction() const
{
    return this->blockAckAction;
}

void Ieee80211Delba::setBlockAckAction(int blockAckAction)
{
    handleChange();
    this->blockAckAction = blockAckAction;
}

bool Ieee80211Delba::getInitiator() const
{
    return this->initiator;
}

void Ieee80211Delba::setInitiator(bool initiator)
{
    handleChange();
    this->initiator = initiator;
}

int Ieee80211Delba::getTid() const
{
    return this->tid;
}

void Ieee80211Delba::setTid(int tid)
{
    handleChange();
    this->tid = tid;
}

int Ieee80211Delba::getReasonCode() const
{
    return this->reasonCode;
}

void Ieee80211Delba::setReasonCode(int reasonCode)
{
    handleChange();
    this->reasonCode = reasonCode;
}

class Ieee80211DelbaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_blockAckAction,
        FIELD_initiator,
        FIELD_tid,
        FIELD_reasonCode,
    };
  public:
    Ieee80211DelbaDescriptor();
    virtual ~Ieee80211DelbaDescriptor();

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

Register_ClassDescriptor(Ieee80211DelbaDescriptor)

Ieee80211DelbaDescriptor::Ieee80211DelbaDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211Delba)), "inet::ieee80211::Ieee80211ActionFrame")
{
    propertynames = nullptr;
}

Ieee80211DelbaDescriptor::~Ieee80211DelbaDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DelbaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211Delba *>(obj)!=nullptr;
}

const char **Ieee80211DelbaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DelbaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DelbaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211DelbaDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_blockAckAction
        FD_ISEDITABLE,    // FIELD_initiator
        FD_ISEDITABLE,    // FIELD_tid
        FD_ISEDITABLE,    // FIELD_reasonCode
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211DelbaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "blockAckAction",
        "initiator",
        "tid",
        "reasonCode",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Ieee80211DelbaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "blockAckAction") == 0) return base+0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "initiator") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "tid") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reasonCode") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DelbaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_blockAckAction
        "bool",    // FIELD_initiator
        "int",    // FIELD_tid
        "int",    // FIELD_reasonCode
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DelbaDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211DelbaDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211DelbaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Delba *pp = (Ieee80211Delba *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DelbaDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Delba *pp = (Ieee80211Delba *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DelbaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Delba *pp = (Ieee80211Delba *)object; (void)pp;
    switch (field) {
        case FIELD_blockAckAction: return long2string(pp->getBlockAckAction());
        case FIELD_initiator: return bool2string(pp->getInitiator());
        case FIELD_tid: return long2string(pp->getTid());
        case FIELD_reasonCode: return long2string(pp->getReasonCode());
        default: return "";
    }
}

bool Ieee80211DelbaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Delba *pp = (Ieee80211Delba *)object; (void)pp;
    switch (field) {
        case FIELD_blockAckAction: pp->setBlockAckAction(string2long(value)); return true;
        case FIELD_initiator: pp->setInitiator(string2bool(value)); return true;
        case FIELD_tid: pp->setTid(string2long(value)); return true;
        case FIELD_reasonCode: pp->setReasonCode(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211DelbaDescriptor::getFieldStructName(int field) const
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

void *Ieee80211DelbaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Delba *pp = (Ieee80211Delba *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211BlockAckReq)

Ieee80211BlockAckReq::Ieee80211BlockAckReq() : ::inet::ieee80211::Ieee80211TwoAddressHeader()
{
    this->setType(ST_BLOCKACK_REQ);

}

Ieee80211BlockAckReq::Ieee80211BlockAckReq(const Ieee80211BlockAckReq& other) : ::inet::ieee80211::Ieee80211TwoAddressHeader(other)
{
    copy(other);
}

Ieee80211BlockAckReq::~Ieee80211BlockAckReq()
{
}

Ieee80211BlockAckReq& Ieee80211BlockAckReq::operator=(const Ieee80211BlockAckReq& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211TwoAddressHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211BlockAckReq::copy(const Ieee80211BlockAckReq& other)
{
    this->multiTid = other.multiTid;
    this->compressedBitmap = other.compressedBitmap;
    this->barAckPolicy = other.barAckPolicy;
}

void Ieee80211BlockAckReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211TwoAddressHeader::parsimPack(b);
    doParsimPacking(b,this->multiTid);
    doParsimPacking(b,this->compressedBitmap);
    doParsimPacking(b,this->barAckPolicy);
}

void Ieee80211BlockAckReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211TwoAddressHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->multiTid);
    doParsimUnpacking(b,this->compressedBitmap);
    doParsimUnpacking(b,this->barAckPolicy);
}

bool Ieee80211BlockAckReq::getMultiTid() const
{
    return this->multiTid;
}

void Ieee80211BlockAckReq::setMultiTid(bool multiTid)
{
    handleChange();
    this->multiTid = multiTid;
}

bool Ieee80211BlockAckReq::getCompressedBitmap() const
{
    return this->compressedBitmap;
}

void Ieee80211BlockAckReq::setCompressedBitmap(bool compressedBitmap)
{
    handleChange();
    this->compressedBitmap = compressedBitmap;
}

bool Ieee80211BlockAckReq::getBarAckPolicy() const
{
    return this->barAckPolicy;
}

void Ieee80211BlockAckReq::setBarAckPolicy(bool barAckPolicy)
{
    handleChange();
    this->barAckPolicy = barAckPolicy;
}

class Ieee80211BlockAckReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_multiTid,
        FIELD_compressedBitmap,
        FIELD_barAckPolicy,
    };
  public:
    Ieee80211BlockAckReqDescriptor();
    virtual ~Ieee80211BlockAckReqDescriptor();

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

Register_ClassDescriptor(Ieee80211BlockAckReqDescriptor)

Ieee80211BlockAckReqDescriptor::Ieee80211BlockAckReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211BlockAckReq)), "inet::ieee80211::Ieee80211TwoAddressHeader")
{
    propertynames = nullptr;
}

Ieee80211BlockAckReqDescriptor::~Ieee80211BlockAckReqDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211BlockAckReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211BlockAckReq *>(obj)!=nullptr;
}

const char **Ieee80211BlockAckReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211BlockAckReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211BlockAckReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211BlockAckReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_multiTid
        FD_ISEDITABLE,    // FIELD_compressedBitmap
        FD_ISEDITABLE,    // FIELD_barAckPolicy
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211BlockAckReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "multiTid",
        "compressedBitmap",
        "barAckPolicy",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ieee80211BlockAckReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "multiTid") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "compressedBitmap") == 0) return base+1;
    if (fieldName[0] == 'b' && strcmp(fieldName, "barAckPolicy") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211BlockAckReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_multiTid
        "bool",    // FIELD_compressedBitmap
        "bool",    // FIELD_barAckPolicy
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211BlockAckReqDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211BlockAckReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211BlockAckReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAckReq *pp = (Ieee80211BlockAckReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211BlockAckReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAckReq *pp = (Ieee80211BlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211BlockAckReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAckReq *pp = (Ieee80211BlockAckReq *)object; (void)pp;
    switch (field) {
        case FIELD_multiTid: return bool2string(pp->getMultiTid());
        case FIELD_compressedBitmap: return bool2string(pp->getCompressedBitmap());
        case FIELD_barAckPolicy: return bool2string(pp->getBarAckPolicy());
        default: return "";
    }
}

bool Ieee80211BlockAckReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAckReq *pp = (Ieee80211BlockAckReq *)object; (void)pp;
    switch (field) {
        case FIELD_multiTid: pp->setMultiTid(string2bool(value)); return true;
        case FIELD_compressedBitmap: pp->setCompressedBitmap(string2bool(value)); return true;
        case FIELD_barAckPolicy: pp->setBarAckPolicy(string2bool(value)); return true;
        default: return false;
    }
}

const char *Ieee80211BlockAckReqDescriptor::getFieldStructName(int field) const
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

void *Ieee80211BlockAckReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAckReq *pp = (Ieee80211BlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211BasicBlockAckReq)

Ieee80211BasicBlockAckReq::Ieee80211BasicBlockAckReq() : ::inet::ieee80211::Ieee80211BlockAckReq()
{
    this->setMultiTid(0);
    this->setCompressedBitmap(0);

}

Ieee80211BasicBlockAckReq::Ieee80211BasicBlockAckReq(const Ieee80211BasicBlockAckReq& other) : ::inet::ieee80211::Ieee80211BlockAckReq(other)
{
    copy(other);
}

Ieee80211BasicBlockAckReq::~Ieee80211BasicBlockAckReq()
{
}

Ieee80211BasicBlockAckReq& Ieee80211BasicBlockAckReq::operator=(const Ieee80211BasicBlockAckReq& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211BlockAckReq::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211BasicBlockAckReq::copy(const Ieee80211BasicBlockAckReq& other)
{
    this->tidInfo = other.tidInfo;
    this->fragmentNumber = other.fragmentNumber;
    this->startingSequenceNumber = other.startingSequenceNumber;
}

void Ieee80211BasicBlockAckReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BlockAckReq::parsimPack(b);
    doParsimPacking(b,this->tidInfo);
    doParsimPacking(b,this->fragmentNumber);
    doParsimPacking(b,this->startingSequenceNumber);
}

void Ieee80211BasicBlockAckReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BlockAckReq::parsimUnpack(b);
    doParsimUnpacking(b,this->tidInfo);
    doParsimUnpacking(b,this->fragmentNumber);
    doParsimUnpacking(b,this->startingSequenceNumber);
}

int Ieee80211BasicBlockAckReq::getTidInfo() const
{
    return this->tidInfo;
}

void Ieee80211BasicBlockAckReq::setTidInfo(int tidInfo)
{
    handleChange();
    this->tidInfo = tidInfo;
}

int Ieee80211BasicBlockAckReq::getFragmentNumber() const
{
    return this->fragmentNumber;
}

void Ieee80211BasicBlockAckReq::setFragmentNumber(int fragmentNumber)
{
    handleChange();
    this->fragmentNumber = fragmentNumber;
}

const SequenceNumber& Ieee80211BasicBlockAckReq::getStartingSequenceNumber() const
{
    return this->startingSequenceNumber;
}

void Ieee80211BasicBlockAckReq::setStartingSequenceNumber(const SequenceNumber& startingSequenceNumber)
{
    handleChange();
    this->startingSequenceNumber = startingSequenceNumber;
}

class Ieee80211BasicBlockAckReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tidInfo,
        FIELD_fragmentNumber,
        FIELD_startingSequenceNumber,
    };
  public:
    Ieee80211BasicBlockAckReqDescriptor();
    virtual ~Ieee80211BasicBlockAckReqDescriptor();

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

Register_ClassDescriptor(Ieee80211BasicBlockAckReqDescriptor)

Ieee80211BasicBlockAckReqDescriptor::Ieee80211BasicBlockAckReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211BasicBlockAckReq)), "inet::ieee80211::Ieee80211BlockAckReq")
{
    propertynames = nullptr;
}

Ieee80211BasicBlockAckReqDescriptor::~Ieee80211BasicBlockAckReqDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211BasicBlockAckReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211BasicBlockAckReq *>(obj)!=nullptr;
}

const char **Ieee80211BasicBlockAckReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211BasicBlockAckReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211BasicBlockAckReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211BasicBlockAckReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_tidInfo
        FD_ISEDITABLE,    // FIELD_fragmentNumber
        0,    // FIELD_startingSequenceNumber
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211BasicBlockAckReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tidInfo",
        "fragmentNumber",
        "startingSequenceNumber",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ieee80211BasicBlockAckReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tidInfo") == 0) return base+0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fragmentNumber") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "startingSequenceNumber") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211BasicBlockAckReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_tidInfo
        "int",    // FIELD_fragmentNumber
        "inet::SequenceNumber",    // FIELD_startingSequenceNumber
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211BasicBlockAckReqDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211BasicBlockAckReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211BasicBlockAckReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAckReq *pp = (Ieee80211BasicBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211BasicBlockAckReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAckReq *pp = (Ieee80211BasicBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211BasicBlockAckReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAckReq *pp = (Ieee80211BasicBlockAckReq *)object; (void)pp;
    switch (field) {
        case FIELD_tidInfo: return long2string(pp->getTidInfo());
        case FIELD_fragmentNumber: return long2string(pp->getFragmentNumber());
        case FIELD_startingSequenceNumber: {std::stringstream out; out << pp->getStartingSequenceNumber(); return out.str();}
        default: return "";
    }
}

bool Ieee80211BasicBlockAckReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAckReq *pp = (Ieee80211BasicBlockAckReq *)object; (void)pp;
    switch (field) {
        case FIELD_tidInfo: pp->setTidInfo(string2long(value)); return true;
        case FIELD_fragmentNumber: pp->setFragmentNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211BasicBlockAckReqDescriptor::getFieldStructName(int field) const
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

void *Ieee80211BasicBlockAckReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAckReq *pp = (Ieee80211BasicBlockAckReq *)object; (void)pp;
    switch (field) {
        case FIELD_startingSequenceNumber: return toVoidPtr(&pp->getStartingSequenceNumber()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211CompressedBlockAckReq)

Ieee80211CompressedBlockAckReq::Ieee80211CompressedBlockAckReq() : ::inet::ieee80211::Ieee80211BlockAckReq()
{
    this->setType(ST_BLOCKACK_REQ);
    this->setMultiTid(0);
    this->setCompressedBitmap(1);

}

Ieee80211CompressedBlockAckReq::Ieee80211CompressedBlockAckReq(const Ieee80211CompressedBlockAckReq& other) : ::inet::ieee80211::Ieee80211BlockAckReq(other)
{
    copy(other);
}

Ieee80211CompressedBlockAckReq::~Ieee80211CompressedBlockAckReq()
{
}

Ieee80211CompressedBlockAckReq& Ieee80211CompressedBlockAckReq::operator=(const Ieee80211CompressedBlockAckReq& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211BlockAckReq::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211CompressedBlockAckReq::copy(const Ieee80211CompressedBlockAckReq& other)
{
    this->tidInfo = other.tidInfo;
    this->fragmentNumber = other.fragmentNumber;
    this->startingSequenceNumber = other.startingSequenceNumber;
}

void Ieee80211CompressedBlockAckReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BlockAckReq::parsimPack(b);
    doParsimPacking(b,this->tidInfo);
    doParsimPacking(b,this->fragmentNumber);
    doParsimPacking(b,this->startingSequenceNumber);
}

void Ieee80211CompressedBlockAckReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BlockAckReq::parsimUnpack(b);
    doParsimUnpacking(b,this->tidInfo);
    doParsimUnpacking(b,this->fragmentNumber);
    doParsimUnpacking(b,this->startingSequenceNumber);
}

int Ieee80211CompressedBlockAckReq::getTidInfo() const
{
    return this->tidInfo;
}

void Ieee80211CompressedBlockAckReq::setTidInfo(int tidInfo)
{
    handleChange();
    this->tidInfo = tidInfo;
}

int Ieee80211CompressedBlockAckReq::getFragmentNumber() const
{
    return this->fragmentNumber;
}

void Ieee80211CompressedBlockAckReq::setFragmentNumber(int fragmentNumber)
{
    handleChange();
    this->fragmentNumber = fragmentNumber;
}

const SequenceNumber& Ieee80211CompressedBlockAckReq::getStartingSequenceNumber() const
{
    return this->startingSequenceNumber;
}

void Ieee80211CompressedBlockAckReq::setStartingSequenceNumber(const SequenceNumber& startingSequenceNumber)
{
    handleChange();
    this->startingSequenceNumber = startingSequenceNumber;
}

class Ieee80211CompressedBlockAckReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tidInfo,
        FIELD_fragmentNumber,
        FIELD_startingSequenceNumber,
    };
  public:
    Ieee80211CompressedBlockAckReqDescriptor();
    virtual ~Ieee80211CompressedBlockAckReqDescriptor();

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

Register_ClassDescriptor(Ieee80211CompressedBlockAckReqDescriptor)

Ieee80211CompressedBlockAckReqDescriptor::Ieee80211CompressedBlockAckReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211CompressedBlockAckReq)), "inet::ieee80211::Ieee80211BlockAckReq")
{
    propertynames = nullptr;
}

Ieee80211CompressedBlockAckReqDescriptor::~Ieee80211CompressedBlockAckReqDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211CompressedBlockAckReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211CompressedBlockAckReq *>(obj)!=nullptr;
}

const char **Ieee80211CompressedBlockAckReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211CompressedBlockAckReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211CompressedBlockAckReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211CompressedBlockAckReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_tidInfo
        FD_ISEDITABLE,    // FIELD_fragmentNumber
        0,    // FIELD_startingSequenceNumber
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211CompressedBlockAckReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tidInfo",
        "fragmentNumber",
        "startingSequenceNumber",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ieee80211CompressedBlockAckReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tidInfo") == 0) return base+0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fragmentNumber") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "startingSequenceNumber") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211CompressedBlockAckReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_tidInfo
        "int",    // FIELD_fragmentNumber
        "inet::SequenceNumber",    // FIELD_startingSequenceNumber
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211CompressedBlockAckReqDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211CompressedBlockAckReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211CompressedBlockAckReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAckReq *pp = (Ieee80211CompressedBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211CompressedBlockAckReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAckReq *pp = (Ieee80211CompressedBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211CompressedBlockAckReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAckReq *pp = (Ieee80211CompressedBlockAckReq *)object; (void)pp;
    switch (field) {
        case FIELD_tidInfo: return long2string(pp->getTidInfo());
        case FIELD_fragmentNumber: return long2string(pp->getFragmentNumber());
        case FIELD_startingSequenceNumber: {std::stringstream out; out << pp->getStartingSequenceNumber(); return out.str();}
        default: return "";
    }
}

bool Ieee80211CompressedBlockAckReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAckReq *pp = (Ieee80211CompressedBlockAckReq *)object; (void)pp;
    switch (field) {
        case FIELD_tidInfo: pp->setTidInfo(string2long(value)); return true;
        case FIELD_fragmentNumber: pp->setFragmentNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211CompressedBlockAckReqDescriptor::getFieldStructName(int field) const
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

void *Ieee80211CompressedBlockAckReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAckReq *pp = (Ieee80211CompressedBlockAckReq *)object; (void)pp;
    switch (field) {
        case FIELD_startingSequenceNumber: return toVoidPtr(&pp->getStartingSequenceNumber()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211MultiTidBlockAckReq)

Ieee80211MultiTidBlockAckReq::Ieee80211MultiTidBlockAckReq() : ::inet::ieee80211::Ieee80211BlockAckReq()
{
    this->setType(ST_BLOCKACK_REQ);
    this->setMultiTid(1);
    this->setCompressedBitmap(1);
}

Ieee80211MultiTidBlockAckReq::Ieee80211MultiTidBlockAckReq(const Ieee80211MultiTidBlockAckReq& other) : ::inet::ieee80211::Ieee80211BlockAckReq(other)
{
    copy(other);
}

Ieee80211MultiTidBlockAckReq::~Ieee80211MultiTidBlockAckReq()
{
}

Ieee80211MultiTidBlockAckReq& Ieee80211MultiTidBlockAckReq::operator=(const Ieee80211MultiTidBlockAckReq& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211BlockAckReq::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211MultiTidBlockAckReq::copy(const Ieee80211MultiTidBlockAckReq& other)
{
}

void Ieee80211MultiTidBlockAckReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BlockAckReq::parsimPack(b);
}

void Ieee80211MultiTidBlockAckReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BlockAckReq::parsimUnpack(b);
}

class Ieee80211MultiTidBlockAckReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211MultiTidBlockAckReqDescriptor();
    virtual ~Ieee80211MultiTidBlockAckReqDescriptor();

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

Register_ClassDescriptor(Ieee80211MultiTidBlockAckReqDescriptor)

Ieee80211MultiTidBlockAckReqDescriptor::Ieee80211MultiTidBlockAckReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211MultiTidBlockAckReq)), "inet::ieee80211::Ieee80211BlockAckReq")
{
    propertynames = nullptr;
}

Ieee80211MultiTidBlockAckReqDescriptor::~Ieee80211MultiTidBlockAckReqDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211MultiTidBlockAckReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211MultiTidBlockAckReq *>(obj)!=nullptr;
}

const char **Ieee80211MultiTidBlockAckReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211MultiTidBlockAckReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211MultiTidBlockAckReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211MultiTidBlockAckReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211MultiTidBlockAckReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211MultiTidBlockAckReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211MultiTidBlockAckReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211MultiTidBlockAckReqDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211MultiTidBlockAckReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211MultiTidBlockAckReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAckReq *pp = (Ieee80211MultiTidBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211MultiTidBlockAckReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAckReq *pp = (Ieee80211MultiTidBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211MultiTidBlockAckReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAckReq *pp = (Ieee80211MultiTidBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211MultiTidBlockAckReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAckReq *pp = (Ieee80211MultiTidBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211MultiTidBlockAckReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211MultiTidBlockAckReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAckReq *pp = (Ieee80211MultiTidBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211BlockAck)

Ieee80211BlockAck::Ieee80211BlockAck() : ::inet::ieee80211::Ieee80211TwoAddressHeader()
{
    this->setType(ST_BLOCKACK);

}

Ieee80211BlockAck::Ieee80211BlockAck(const Ieee80211BlockAck& other) : ::inet::ieee80211::Ieee80211TwoAddressHeader(other)
{
    copy(other);
}

Ieee80211BlockAck::~Ieee80211BlockAck()
{
}

Ieee80211BlockAck& Ieee80211BlockAck::operator=(const Ieee80211BlockAck& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211TwoAddressHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211BlockAck::copy(const Ieee80211BlockAck& other)
{
    this->blockAckPolicy = other.blockAckPolicy;
    this->multiTid = other.multiTid;
    this->compressedBitmap = other.compressedBitmap;
}

void Ieee80211BlockAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211TwoAddressHeader::parsimPack(b);
    doParsimPacking(b,this->blockAckPolicy);
    doParsimPacking(b,this->multiTid);
    doParsimPacking(b,this->compressedBitmap);
}

void Ieee80211BlockAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211TwoAddressHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->blockAckPolicy);
    doParsimUnpacking(b,this->multiTid);
    doParsimUnpacking(b,this->compressedBitmap);
}

bool Ieee80211BlockAck::getBlockAckPolicy() const
{
    return this->blockAckPolicy;
}

void Ieee80211BlockAck::setBlockAckPolicy(bool blockAckPolicy)
{
    handleChange();
    this->blockAckPolicy = blockAckPolicy;
}

bool Ieee80211BlockAck::getMultiTid() const
{
    return this->multiTid;
}

void Ieee80211BlockAck::setMultiTid(bool multiTid)
{
    handleChange();
    this->multiTid = multiTid;
}

bool Ieee80211BlockAck::getCompressedBitmap() const
{
    return this->compressedBitmap;
}

void Ieee80211BlockAck::setCompressedBitmap(bool compressedBitmap)
{
    handleChange();
    this->compressedBitmap = compressedBitmap;
}

class Ieee80211BlockAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_blockAckPolicy,
        FIELD_multiTid,
        FIELD_compressedBitmap,
    };
  public:
    Ieee80211BlockAckDescriptor();
    virtual ~Ieee80211BlockAckDescriptor();

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

Register_ClassDescriptor(Ieee80211BlockAckDescriptor)

Ieee80211BlockAckDescriptor::Ieee80211BlockAckDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211BlockAck)), "inet::ieee80211::Ieee80211TwoAddressHeader")
{
    propertynames = nullptr;
}

Ieee80211BlockAckDescriptor::~Ieee80211BlockAckDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211BlockAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211BlockAck *>(obj)!=nullptr;
}

const char **Ieee80211BlockAckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211BlockAckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211BlockAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211BlockAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_blockAckPolicy
        FD_ISEDITABLE,    // FIELD_multiTid
        FD_ISEDITABLE,    // FIELD_compressedBitmap
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211BlockAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "blockAckPolicy",
        "multiTid",
        "compressedBitmap",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ieee80211BlockAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "blockAckPolicy") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "multiTid") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "compressedBitmap") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211BlockAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_blockAckPolicy
        "bool",    // FIELD_multiTid
        "bool",    // FIELD_compressedBitmap
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211BlockAckDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211BlockAckDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211BlockAckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAck *pp = (Ieee80211BlockAck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211BlockAckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAck *pp = (Ieee80211BlockAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211BlockAckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAck *pp = (Ieee80211BlockAck *)object; (void)pp;
    switch (field) {
        case FIELD_blockAckPolicy: return bool2string(pp->getBlockAckPolicy());
        case FIELD_multiTid: return bool2string(pp->getMultiTid());
        case FIELD_compressedBitmap: return bool2string(pp->getCompressedBitmap());
        default: return "";
    }
}

bool Ieee80211BlockAckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAck *pp = (Ieee80211BlockAck *)object; (void)pp;
    switch (field) {
        case FIELD_blockAckPolicy: pp->setBlockAckPolicy(string2bool(value)); return true;
        case FIELD_multiTid: pp->setMultiTid(string2bool(value)); return true;
        case FIELD_compressedBitmap: pp->setCompressedBitmap(string2bool(value)); return true;
        default: return false;
    }
}

const char *Ieee80211BlockAckDescriptor::getFieldStructName(int field) const
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

void *Ieee80211BlockAckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAck *pp = (Ieee80211BlockAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211BasicBlockAck)

Ieee80211BasicBlockAck::Ieee80211BasicBlockAck() : ::inet::ieee80211::Ieee80211BlockAck()
{
    this->setChunkLength(LENGTH_BASIC_BLOCKACK - B(4));
    this->setMultiTid(0);
    this->setCompressedBitmap(0);

}

Ieee80211BasicBlockAck::Ieee80211BasicBlockAck(const Ieee80211BasicBlockAck& other) : ::inet::ieee80211::Ieee80211BlockAck(other)
{
    copy(other);
}

Ieee80211BasicBlockAck::~Ieee80211BasicBlockAck()
{
}

Ieee80211BasicBlockAck& Ieee80211BasicBlockAck::operator=(const Ieee80211BasicBlockAck& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211BlockAck::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211BasicBlockAck::copy(const Ieee80211BasicBlockAck& other)
{
    this->fragmentNumber = other.fragmentNumber;
    this->startingSequenceNumber = other.startingSequenceNumber;
    for (size_t i = 0; i < 64; i++) {
        this->blockAckBitmap[i] = other.blockAckBitmap[i];
    }
    this->tidInfo = other.tidInfo;
}

void Ieee80211BasicBlockAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BlockAck::parsimPack(b);
    doParsimPacking(b,this->fragmentNumber);
    doParsimPacking(b,this->startingSequenceNumber);
    doParsimArrayPacking(b,this->blockAckBitmap,64);
    doParsimPacking(b,this->tidInfo);
}

void Ieee80211BasicBlockAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BlockAck::parsimUnpack(b);
    doParsimUnpacking(b,this->fragmentNumber);
    doParsimUnpacking(b,this->startingSequenceNumber);
    doParsimArrayUnpacking(b,this->blockAckBitmap,64);
    doParsimUnpacking(b,this->tidInfo);
}

int Ieee80211BasicBlockAck::getFragmentNumber() const
{
    return this->fragmentNumber;
}

void Ieee80211BasicBlockAck::setFragmentNumber(int fragmentNumber)
{
    handleChange();
    this->fragmentNumber = fragmentNumber;
}

const SequenceNumber& Ieee80211BasicBlockAck::getStartingSequenceNumber() const
{
    return this->startingSequenceNumber;
}

void Ieee80211BasicBlockAck::setStartingSequenceNumber(const SequenceNumber& startingSequenceNumber)
{
    handleChange();
    this->startingSequenceNumber = startingSequenceNumber;
}

size_t Ieee80211BasicBlockAck::getBlockAckBitmapArraySize() const
{
    return 64;
}

const BitVector& Ieee80211BasicBlockAck::getBlockAckBitmap(size_t k) const
{
    if (k >= 64) throw omnetpp::cRuntimeError("Array of size 64 indexed by %lu", (unsigned long)k);
    return this->blockAckBitmap[k];
}

void Ieee80211BasicBlockAck::setBlockAckBitmap(size_t k, const BitVector& blockAckBitmap)
{
    if (k >= 64) throw omnetpp::cRuntimeError("Array of size 64 indexed by %lu", (unsigned long)k);
    handleChange();
    this->blockAckBitmap[k] = blockAckBitmap;
}

int Ieee80211BasicBlockAck::getTidInfo() const
{
    return this->tidInfo;
}

void Ieee80211BasicBlockAck::setTidInfo(int tidInfo)
{
    handleChange();
    this->tidInfo = tidInfo;
}

class Ieee80211BasicBlockAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_fragmentNumber,
        FIELD_startingSequenceNumber,
        FIELD_blockAckBitmap,
        FIELD_tidInfo,
    };
  public:
    Ieee80211BasicBlockAckDescriptor();
    virtual ~Ieee80211BasicBlockAckDescriptor();

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

Register_ClassDescriptor(Ieee80211BasicBlockAckDescriptor)

Ieee80211BasicBlockAckDescriptor::Ieee80211BasicBlockAckDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211BasicBlockAck)), "inet::ieee80211::Ieee80211BlockAck")
{
    propertynames = nullptr;
}

Ieee80211BasicBlockAckDescriptor::~Ieee80211BasicBlockAckDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211BasicBlockAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211BasicBlockAck *>(obj)!=nullptr;
}

const char **Ieee80211BasicBlockAckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211BasicBlockAckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211BasicBlockAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211BasicBlockAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_fragmentNumber
        0,    // FIELD_startingSequenceNumber
        FD_ISARRAY,    // FIELD_blockAckBitmap
        FD_ISEDITABLE,    // FIELD_tidInfo
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211BasicBlockAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fragmentNumber",
        "startingSequenceNumber",
        "blockAckBitmap",
        "tidInfo",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Ieee80211BasicBlockAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fragmentNumber") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "startingSequenceNumber") == 0) return base+1;
    if (fieldName[0] == 'b' && strcmp(fieldName, "blockAckBitmap") == 0) return base+2;
    if (fieldName[0] == 't' && strcmp(fieldName, "tidInfo") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211BasicBlockAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_fragmentNumber
        "inet::SequenceNumber",    // FIELD_startingSequenceNumber
        "inet::BitVector",    // FIELD_blockAckBitmap
        "int",    // FIELD_tidInfo
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211BasicBlockAckDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211BasicBlockAckDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211BasicBlockAckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAck *pp = (Ieee80211BasicBlockAck *)object; (void)pp;
    switch (field) {
        case FIELD_blockAckBitmap: return 64;
        default: return 0;
    }
}

const char *Ieee80211BasicBlockAckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAck *pp = (Ieee80211BasicBlockAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211BasicBlockAckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAck *pp = (Ieee80211BasicBlockAck *)object; (void)pp;
    switch (field) {
        case FIELD_fragmentNumber: return long2string(pp->getFragmentNumber());
        case FIELD_startingSequenceNumber: {std::stringstream out; out << pp->getStartingSequenceNumber(); return out.str();}
        case FIELD_blockAckBitmap: return pp->getBlockAckBitmap(i).toString();
        case FIELD_tidInfo: return long2string(pp->getTidInfo());
        default: return "";
    }
}

bool Ieee80211BasicBlockAckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAck *pp = (Ieee80211BasicBlockAck *)object; (void)pp;
    switch (field) {
        case FIELD_fragmentNumber: pp->setFragmentNumber(string2long(value)); return true;
        case FIELD_tidInfo: pp->setTidInfo(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211BasicBlockAckDescriptor::getFieldStructName(int field) const
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

void *Ieee80211BasicBlockAckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAck *pp = (Ieee80211BasicBlockAck *)object; (void)pp;
    switch (field) {
        case FIELD_startingSequenceNumber: return toVoidPtr(&pp->getStartingSequenceNumber()); break;
        case FIELD_blockAckBitmap: return toVoidPtr(&pp->getBlockAckBitmap(i)); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211CompressedBlockAck)

Ieee80211CompressedBlockAck::Ieee80211CompressedBlockAck() : ::inet::ieee80211::Ieee80211BlockAck()
{
    this->setMultiTid(0);
    this->setCompressedBitmap(1);

}

Ieee80211CompressedBlockAck::Ieee80211CompressedBlockAck(const Ieee80211CompressedBlockAck& other) : ::inet::ieee80211::Ieee80211BlockAck(other)
{
    copy(other);
}

Ieee80211CompressedBlockAck::~Ieee80211CompressedBlockAck()
{
}

Ieee80211CompressedBlockAck& Ieee80211CompressedBlockAck::operator=(const Ieee80211CompressedBlockAck& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211BlockAck::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211CompressedBlockAck::copy(const Ieee80211CompressedBlockAck& other)
{
    this->fragmentNumber = other.fragmentNumber;
    this->startingSequenceNumber = other.startingSequenceNumber;
    this->blockAckBitmap = other.blockAckBitmap;
    this->tidInfo = other.tidInfo;
}

void Ieee80211CompressedBlockAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BlockAck::parsimPack(b);
    doParsimPacking(b,this->fragmentNumber);
    doParsimPacking(b,this->startingSequenceNumber);
    doParsimPacking(b,this->blockAckBitmap);
    doParsimPacking(b,this->tidInfo);
}

void Ieee80211CompressedBlockAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BlockAck::parsimUnpack(b);
    doParsimUnpacking(b,this->fragmentNumber);
    doParsimUnpacking(b,this->startingSequenceNumber);
    doParsimUnpacking(b,this->blockAckBitmap);
    doParsimUnpacking(b,this->tidInfo);
}

int Ieee80211CompressedBlockAck::getFragmentNumber() const
{
    return this->fragmentNumber;
}

void Ieee80211CompressedBlockAck::setFragmentNumber(int fragmentNumber)
{
    handleChange();
    this->fragmentNumber = fragmentNumber;
}

const SequenceNumber& Ieee80211CompressedBlockAck::getStartingSequenceNumber() const
{
    return this->startingSequenceNumber;
}

void Ieee80211CompressedBlockAck::setStartingSequenceNumber(const SequenceNumber& startingSequenceNumber)
{
    handleChange();
    this->startingSequenceNumber = startingSequenceNumber;
}

const BitVector& Ieee80211CompressedBlockAck::getBlockAckBitmap() const
{
    return this->blockAckBitmap;
}

void Ieee80211CompressedBlockAck::setBlockAckBitmap(const BitVector& blockAckBitmap)
{
    handleChange();
    this->blockAckBitmap = blockAckBitmap;
}

int Ieee80211CompressedBlockAck::getTidInfo() const
{
    return this->tidInfo;
}

void Ieee80211CompressedBlockAck::setTidInfo(int tidInfo)
{
    handleChange();
    this->tidInfo = tidInfo;
}

class Ieee80211CompressedBlockAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_fragmentNumber,
        FIELD_startingSequenceNumber,
        FIELD_blockAckBitmap,
        FIELD_tidInfo,
    };
  public:
    Ieee80211CompressedBlockAckDescriptor();
    virtual ~Ieee80211CompressedBlockAckDescriptor();

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

Register_ClassDescriptor(Ieee80211CompressedBlockAckDescriptor)

Ieee80211CompressedBlockAckDescriptor::Ieee80211CompressedBlockAckDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211CompressedBlockAck)), "inet::ieee80211::Ieee80211BlockAck")
{
    propertynames = nullptr;
}

Ieee80211CompressedBlockAckDescriptor::~Ieee80211CompressedBlockAckDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211CompressedBlockAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211CompressedBlockAck *>(obj)!=nullptr;
}

const char **Ieee80211CompressedBlockAckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211CompressedBlockAckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211CompressedBlockAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211CompressedBlockAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_fragmentNumber
        0,    // FIELD_startingSequenceNumber
        0,    // FIELD_blockAckBitmap
        FD_ISEDITABLE,    // FIELD_tidInfo
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211CompressedBlockAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fragmentNumber",
        "startingSequenceNumber",
        "blockAckBitmap",
        "tidInfo",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Ieee80211CompressedBlockAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fragmentNumber") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "startingSequenceNumber") == 0) return base+1;
    if (fieldName[0] == 'b' && strcmp(fieldName, "blockAckBitmap") == 0) return base+2;
    if (fieldName[0] == 't' && strcmp(fieldName, "tidInfo") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211CompressedBlockAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_fragmentNumber
        "inet::SequenceNumber",    // FIELD_startingSequenceNumber
        "inet::BitVector",    // FIELD_blockAckBitmap
        "int",    // FIELD_tidInfo
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211CompressedBlockAckDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211CompressedBlockAckDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211CompressedBlockAckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAck *pp = (Ieee80211CompressedBlockAck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211CompressedBlockAckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAck *pp = (Ieee80211CompressedBlockAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211CompressedBlockAckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAck *pp = (Ieee80211CompressedBlockAck *)object; (void)pp;
    switch (field) {
        case FIELD_fragmentNumber: return long2string(pp->getFragmentNumber());
        case FIELD_startingSequenceNumber: {std::stringstream out; out << pp->getStartingSequenceNumber(); return out.str();}
        case FIELD_blockAckBitmap: return pp->getBlockAckBitmap().toString();
        case FIELD_tidInfo: return long2string(pp->getTidInfo());
        default: return "";
    }
}

bool Ieee80211CompressedBlockAckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAck *pp = (Ieee80211CompressedBlockAck *)object; (void)pp;
    switch (field) {
        case FIELD_fragmentNumber: pp->setFragmentNumber(string2long(value)); return true;
        case FIELD_tidInfo: pp->setTidInfo(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211CompressedBlockAckDescriptor::getFieldStructName(int field) const
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

void *Ieee80211CompressedBlockAckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAck *pp = (Ieee80211CompressedBlockAck *)object; (void)pp;
    switch (field) {
        case FIELD_startingSequenceNumber: return toVoidPtr(&pp->getStartingSequenceNumber()); break;
        case FIELD_blockAckBitmap: return toVoidPtr(&pp->getBlockAckBitmap()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211MultiTidBlockAck)

Ieee80211MultiTidBlockAck::Ieee80211MultiTidBlockAck() : ::inet::ieee80211::Ieee80211BlockAck()
{
    this->setMultiTid(1);
    this->setCompressedBitmap(1);
}

Ieee80211MultiTidBlockAck::Ieee80211MultiTidBlockAck(const Ieee80211MultiTidBlockAck& other) : ::inet::ieee80211::Ieee80211BlockAck(other)
{
    copy(other);
}

Ieee80211MultiTidBlockAck::~Ieee80211MultiTidBlockAck()
{
}

Ieee80211MultiTidBlockAck& Ieee80211MultiTidBlockAck::operator=(const Ieee80211MultiTidBlockAck& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211BlockAck::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211MultiTidBlockAck::copy(const Ieee80211MultiTidBlockAck& other)
{
}

void Ieee80211MultiTidBlockAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BlockAck::parsimPack(b);
}

void Ieee80211MultiTidBlockAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BlockAck::parsimUnpack(b);
}

class Ieee80211MultiTidBlockAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211MultiTidBlockAckDescriptor();
    virtual ~Ieee80211MultiTidBlockAckDescriptor();

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

Register_ClassDescriptor(Ieee80211MultiTidBlockAckDescriptor)

Ieee80211MultiTidBlockAckDescriptor::Ieee80211MultiTidBlockAckDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211MultiTidBlockAck)), "inet::ieee80211::Ieee80211BlockAck")
{
    propertynames = nullptr;
}

Ieee80211MultiTidBlockAckDescriptor::~Ieee80211MultiTidBlockAckDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211MultiTidBlockAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211MultiTidBlockAck *>(obj)!=nullptr;
}

const char **Ieee80211MultiTidBlockAckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211MultiTidBlockAckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211MultiTidBlockAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211MultiTidBlockAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211MultiTidBlockAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211MultiTidBlockAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211MultiTidBlockAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211MultiTidBlockAckDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211MultiTidBlockAckDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211MultiTidBlockAckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAck *pp = (Ieee80211MultiTidBlockAck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211MultiTidBlockAckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAck *pp = (Ieee80211MultiTidBlockAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211MultiTidBlockAckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAck *pp = (Ieee80211MultiTidBlockAck *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211MultiTidBlockAckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAck *pp = (Ieee80211MultiTidBlockAck *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211MultiTidBlockAckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211MultiTidBlockAckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAck *pp = (Ieee80211MultiTidBlockAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace ieee80211
} // namespace inet

