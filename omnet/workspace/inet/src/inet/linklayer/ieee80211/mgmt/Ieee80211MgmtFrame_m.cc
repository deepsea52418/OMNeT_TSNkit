//
// Generated file, do not edit! Created by nedtool 5.6 from inet/linklayer/ieee80211/mgmt/Ieee80211MgmtFrame.msg.
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
#include "Ieee80211MgmtFrame_m.h"

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

Ieee80211CapabilityInformation::Ieee80211CapabilityInformation()
{
    this->ESS = false;
    this->IBSS = false;
    this->CFPollable = false;
    this->CFPollRequest = false;
    this->privacy = false;
    this->DelayedBlockAck = false;
    this->InmediateBlockAck = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const Ieee80211CapabilityInformation& a)
{
    doParsimPacking(b,a.ESS);
    doParsimPacking(b,a.IBSS);
    doParsimPacking(b,a.CFPollable);
    doParsimPacking(b,a.CFPollRequest);
    doParsimPacking(b,a.privacy);
    doParsimPacking(b,a.DelayedBlockAck);
    doParsimPacking(b,a.InmediateBlockAck);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Ieee80211CapabilityInformation& a)
{
    doParsimUnpacking(b,a.ESS);
    doParsimUnpacking(b,a.IBSS);
    doParsimUnpacking(b,a.CFPollable);
    doParsimUnpacking(b,a.CFPollRequest);
    doParsimUnpacking(b,a.privacy);
    doParsimUnpacking(b,a.DelayedBlockAck);
    doParsimUnpacking(b,a.InmediateBlockAck);
}

class Ieee80211CapabilityInformationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_ESS,
        FIELD_IBSS,
        FIELD_CFPollable,
        FIELD_CFPollRequest,
        FIELD_privacy,
        FIELD_DelayedBlockAck,
        FIELD_InmediateBlockAck,
    };
  public:
    Ieee80211CapabilityInformationDescriptor();
    virtual ~Ieee80211CapabilityInformationDescriptor();

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

Register_ClassDescriptor(Ieee80211CapabilityInformationDescriptor)

Ieee80211CapabilityInformationDescriptor::Ieee80211CapabilityInformationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211CapabilityInformation)), "")
{
    propertynames = nullptr;
}

Ieee80211CapabilityInformationDescriptor::~Ieee80211CapabilityInformationDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211CapabilityInformationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211CapabilityInformation *>(obj)!=nullptr;
}

const char **Ieee80211CapabilityInformationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211CapabilityInformationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211CapabilityInformationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int Ieee80211CapabilityInformationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ESS
        FD_ISEDITABLE,    // FIELD_IBSS
        FD_ISEDITABLE,    // FIELD_CFPollable
        FD_ISEDITABLE,    // FIELD_CFPollRequest
        FD_ISEDITABLE,    // FIELD_privacy
        FD_ISEDITABLE,    // FIELD_DelayedBlockAck
        FD_ISEDITABLE,    // FIELD_InmediateBlockAck
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211CapabilityInformationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ESS",
        "IBSS",
        "CFPollable",
        "CFPollRequest",
        "privacy",
        "DelayedBlockAck",
        "InmediateBlockAck",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int Ieee80211CapabilityInformationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'E' && strcmp(fieldName, "ESS") == 0) return base+0;
    if (fieldName[0] == 'I' && strcmp(fieldName, "IBSS") == 0) return base+1;
    if (fieldName[0] == 'C' && strcmp(fieldName, "CFPollable") == 0) return base+2;
    if (fieldName[0] == 'C' && strcmp(fieldName, "CFPollRequest") == 0) return base+3;
    if (fieldName[0] == 'p' && strcmp(fieldName, "privacy") == 0) return base+4;
    if (fieldName[0] == 'D' && strcmp(fieldName, "DelayedBlockAck") == 0) return base+5;
    if (fieldName[0] == 'I' && strcmp(fieldName, "InmediateBlockAck") == 0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211CapabilityInformationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_ESS
        "bool",    // FIELD_IBSS
        "bool",    // FIELD_CFPollable
        "bool",    // FIELD_CFPollRequest
        "bool",    // FIELD_privacy
        "bool",    // FIELD_DelayedBlockAck
        "bool",    // FIELD_InmediateBlockAck
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211CapabilityInformationDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211CapabilityInformationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211CapabilityInformationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CapabilityInformation *pp = (Ieee80211CapabilityInformation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211CapabilityInformationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CapabilityInformation *pp = (Ieee80211CapabilityInformation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211CapabilityInformationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CapabilityInformation *pp = (Ieee80211CapabilityInformation *)object; (void)pp;
    switch (field) {
        case FIELD_ESS: return bool2string(pp->ESS);
        case FIELD_IBSS: return bool2string(pp->IBSS);
        case FIELD_CFPollable: return bool2string(pp->CFPollable);
        case FIELD_CFPollRequest: return bool2string(pp->CFPollRequest);
        case FIELD_privacy: return bool2string(pp->privacy);
        case FIELD_DelayedBlockAck: return bool2string(pp->DelayedBlockAck);
        case FIELD_InmediateBlockAck: return bool2string(pp->InmediateBlockAck);
        default: return "";
    }
}

bool Ieee80211CapabilityInformationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CapabilityInformation *pp = (Ieee80211CapabilityInformation *)object; (void)pp;
    switch (field) {
        case FIELD_ESS: pp->ESS = string2bool(value); return true;
        case FIELD_IBSS: pp->IBSS = string2bool(value); return true;
        case FIELD_CFPollable: pp->CFPollable = string2bool(value); return true;
        case FIELD_CFPollRequest: pp->CFPollRequest = string2bool(value); return true;
        case FIELD_privacy: pp->privacy = string2bool(value); return true;
        case FIELD_DelayedBlockAck: pp->DelayedBlockAck = string2bool(value); return true;
        case FIELD_InmediateBlockAck: pp->InmediateBlockAck = string2bool(value); return true;
        default: return false;
    }
}

const char *Ieee80211CapabilityInformationDescriptor::getFieldStructName(int field) const
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

void *Ieee80211CapabilityInformationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CapabilityInformation *pp = (Ieee80211CapabilityInformation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Ieee80211HandoverParameters::Ieee80211HandoverParameters()
{
    this->avgBackoffTime = 0;
    this->avgWaitTime = 0;
    this->avgErrorRate = 0;
    this->estAvailBW = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const Ieee80211HandoverParameters& a)
{
    doParsimPacking(b,a.avgBackoffTime);
    doParsimPacking(b,a.avgWaitTime);
    doParsimPacking(b,a.avgErrorRate);
    doParsimPacking(b,a.estAvailBW);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Ieee80211HandoverParameters& a)
{
    doParsimUnpacking(b,a.avgBackoffTime);
    doParsimUnpacking(b,a.avgWaitTime);
    doParsimUnpacking(b,a.avgErrorRate);
    doParsimUnpacking(b,a.estAvailBW);
}

class Ieee80211HandoverParametersDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_avgBackoffTime,
        FIELD_avgWaitTime,
        FIELD_avgErrorRate,
        FIELD_estAvailBW,
    };
  public:
    Ieee80211HandoverParametersDescriptor();
    virtual ~Ieee80211HandoverParametersDescriptor();

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

Register_ClassDescriptor(Ieee80211HandoverParametersDescriptor)

Ieee80211HandoverParametersDescriptor::Ieee80211HandoverParametersDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211HandoverParameters)), "")
{
    propertynames = nullptr;
}

Ieee80211HandoverParametersDescriptor::~Ieee80211HandoverParametersDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211HandoverParametersDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211HandoverParameters *>(obj)!=nullptr;
}

const char **Ieee80211HandoverParametersDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211HandoverParametersDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211HandoverParametersDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211HandoverParametersDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_avgBackoffTime
        FD_ISEDITABLE,    // FIELD_avgWaitTime
        FD_ISEDITABLE,    // FIELD_avgErrorRate
        FD_ISEDITABLE,    // FIELD_estAvailBW
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211HandoverParametersDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "avgBackoffTime",
        "avgWaitTime",
        "avgErrorRate",
        "estAvailBW",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Ieee80211HandoverParametersDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "avgBackoffTime") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "avgWaitTime") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "avgErrorRate") == 0) return base+2;
    if (fieldName[0] == 'e' && strcmp(fieldName, "estAvailBW") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211HandoverParametersDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_avgBackoffTime
        "double",    // FIELD_avgWaitTime
        "double",    // FIELD_avgErrorRate
        "double",    // FIELD_estAvailBW
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211HandoverParametersDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211HandoverParametersDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211HandoverParametersDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HandoverParameters *pp = (Ieee80211HandoverParameters *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211HandoverParametersDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HandoverParameters *pp = (Ieee80211HandoverParameters *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211HandoverParametersDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HandoverParameters *pp = (Ieee80211HandoverParameters *)object; (void)pp;
    switch (field) {
        case FIELD_avgBackoffTime: return double2string(pp->avgBackoffTime);
        case FIELD_avgWaitTime: return double2string(pp->avgWaitTime);
        case FIELD_avgErrorRate: return double2string(pp->avgErrorRate);
        case FIELD_estAvailBW: return double2string(pp->estAvailBW);
        default: return "";
    }
}

bool Ieee80211HandoverParametersDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HandoverParameters *pp = (Ieee80211HandoverParameters *)object; (void)pp;
    switch (field) {
        case FIELD_avgBackoffTime: pp->avgBackoffTime = string2double(value); return true;
        case FIELD_avgWaitTime: pp->avgWaitTime = string2double(value); return true;
        case FIELD_avgErrorRate: pp->avgErrorRate = string2double(value); return true;
        case FIELD_estAvailBW: pp->estAvailBW = string2double(value); return true;
        default: return false;
    }
}

const char *Ieee80211HandoverParametersDescriptor::getFieldStructName(int field) const
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

void *Ieee80211HandoverParametersDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HandoverParameters *pp = (Ieee80211HandoverParameters *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ieee80211::Ieee80211ReasonCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ieee80211::Ieee80211ReasonCode"));
    e->insert(RC_UNSPECIFIED, "RC_UNSPECIFIED");
    e->insert(RC_PREV_AUTH_EXPIRED, "RC_PREV_AUTH_EXPIRED");
    e->insert(RC_DEAUTH_MS_LEAVING, "RC_DEAUTH_MS_LEAVING");
    e->insert(RC_DISASS_INACTIVITY, "RC_DISASS_INACTIVITY");
    e->insert(RC_DISASS_TOO_MANY_MS, "RC_DISASS_TOO_MANY_MS");
    e->insert(RC_NONAUTH_CLASS2, "RC_NONAUTH_CLASS2");
    e->insert(RC_NONASS_CLASS3, "RC_NONASS_CLASS3");
    e->insert(RC_DIASS_MS_LEAVING, "RC_DIASS_MS_LEAVING");
    e->insert(RC_NONAUTH_ASS_REQUEST, "RC_NONAUTH_ASS_REQUEST");
    e->insert(RC_MESH_PEERING_CANCELLED, "RC_MESH_PEERING_CANCELLED");
    e->insert(RC_MESH_MAX_PEERS, "RC_MESH_MAX_PEERS");
    e->insert(RC_MESH_CONFIGURATION_POLICY_VIOLATION, "RC_MESH_CONFIGURATION_POLICY_VIOLATION");
    e->insert(RC_MESH_CLOSE_RCVD, "RC_MESH_CLOSE_RCVD");
    e->insert(RC_MESH_MAX_RETRIES, "RC_MESH_MAX_RETRIES");
    e->insert(RC_MESH_CONFIRM_TIMEOUT, "RC_MESH_CONFIRM_TIMEOUT");
    e->insert(RC_MESH_INVALID_GTK, "RC_MESH_INVALID_GTK");
    e->insert(RC_MESH_INCONSISTENT_PARAMETERS, "RC_MESH_INCONSISTENT_PARAMETERS");
    e->insert(RC_MESH_INVALID_SECURITY_CAPABILITY, "RC_MESH_INVALID_SECURITY_CAPABILITY");
    e->insert(RC_MESH_PATH_ERROR_NO_PROXY_INFORMATION, "RC_MESH_PATH_ERROR_NO_PROXY_INFORMATION");
    e->insert(RC_MESH_PATH_ERROR_NO_FORWARDING_INFORMATION, "RC_MESH_PATH_ERROR_NO_FORWARDING_INFORMATION");
    e->insert(RC_MESH_PATH_ERROR_DESTINATION_UNREACHABLE, "RC_MESH_PATH_ERROR_DESTINATION_UNREACHABLE");
    e->insert(RC_MAC_ADDRESS_ALREADY_EXISTS_IN_MBSS, "RC_MAC_ADDRESS_ALREADY_EXISTS_IN_MBSS");
    e->insert(RC_MESH_CHANNEL_SWITCH_REGULATORY_REQUIREMENTS, "RC_MESH_CHANNEL_SWITCH_REGULATORY_REQUIREMENTS");
    e->insert(RC_MESH_CHANNEL_SWITCH_UNSPECIFIED, "RC_MESH_CHANNEL_SWITCH_UNSPECIFIED");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ieee80211::Ieee80211StatusCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ieee80211::Ieee80211StatusCode"));
    e->insert(SC_SUCCESSFUL, "SC_SUCCESSFUL");
    e->insert(SC_UNSPECIFIED, "SC_UNSPECIFIED");
    e->insert(SC_UNSUP_CAP, "SC_UNSUP_CAP");
    e->insert(SC_REASS_DENIED, "SC_REASS_DENIED");
    e->insert(SC_ASS_DENIED_UNKNOWN, "SC_ASS_DENIED_UNKNOWN");
    e->insert(SC_AUTH_ALG0_UNSUP, "SC_AUTH_ALG0_UNSUP");
    e->insert(SC_AUTH_OUT_OF_SEQ, "SC_AUTH_OUT_OF_SEQ");
    e->insert(SC_AUTH_CHALLENGE_FAIL, "SC_AUTH_CHALLENGE_FAIL");
    e->insert(SC_AUTH_TIMEOUT, "SC_AUTH_TIMEOUT");
    e->insert(SC_ASS_TOO_MANY_MS, "SC_ASS_TOO_MANY_MS");
    e->insert(SC_DATARATE_UNSUP, "SC_DATARATE_UNSUP");
    e->insert(SC_AUTH_REJECT_ANTI_CLOGING, "SC_AUTH_REJECT_ANTI_CLOGING");
    e->insert(SC_AUTH_REJECT_FINITE_CYC_GROUP_UNS, "SC_AUTH_REJECT_FINITE_CYC_GROUP_UNS");
    e->insert(SC_TBTT_REQUEST, "SC_TBTT_REQUEST");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ieee80211::Ieee80211HwmpCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ieee80211::Ieee80211HwmpCode"));
    e->insert(IE11S_GANN, "IE11S_GANN");
    e->insert(IE11S_RANN, "IE11S_RANN");
    e->insert(IE11S_PREQ, "IE11S_PREQ");
    e->insert(IE11S_PREP, "IE11S_PREP");
    e->insert(IE11S_PERR, "IE11S_PERR");
)

Ieee80211SupportedRatesElement::Ieee80211SupportedRatesElement()
{
    this->numRates = 0;
    for (size_t i = 0; i < 8; i++)
        this->rate[i] = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const Ieee80211SupportedRatesElement& a)
{
    doParsimPacking(b,a.numRates);
    doParsimArrayPacking(b,a.rate,8);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Ieee80211SupportedRatesElement& a)
{
    doParsimUnpacking(b,a.numRates);
    doParsimArrayUnpacking(b,a.rate,8);
}

class Ieee80211SupportedRatesElementDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_numRates,
        FIELD_rate,
    };
  public:
    Ieee80211SupportedRatesElementDescriptor();
    virtual ~Ieee80211SupportedRatesElementDescriptor();

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

Register_ClassDescriptor(Ieee80211SupportedRatesElementDescriptor)

Ieee80211SupportedRatesElementDescriptor::Ieee80211SupportedRatesElementDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211SupportedRatesElement)), "")
{
    propertynames = nullptr;
}

Ieee80211SupportedRatesElementDescriptor::~Ieee80211SupportedRatesElementDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211SupportedRatesElementDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211SupportedRatesElement *>(obj)!=nullptr;
}

const char **Ieee80211SupportedRatesElementDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211SupportedRatesElementDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211SupportedRatesElementDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ieee80211SupportedRatesElementDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_numRates
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_rate
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211SupportedRatesElementDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "numRates",
        "rate",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ieee80211SupportedRatesElementDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numRates") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rate") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211SupportedRatesElementDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_numRates
        "double",    // FIELD_rate
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211SupportedRatesElementDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211SupportedRatesElementDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211SupportedRatesElementDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211SupportedRatesElement *pp = (Ieee80211SupportedRatesElement *)object; (void)pp;
    switch (field) {
        case FIELD_rate: return 8;
        default: return 0;
    }
}

const char *Ieee80211SupportedRatesElementDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211SupportedRatesElement *pp = (Ieee80211SupportedRatesElement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211SupportedRatesElementDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211SupportedRatesElement *pp = (Ieee80211SupportedRatesElement *)object; (void)pp;
    switch (field) {
        case FIELD_numRates: return long2string(pp->numRates);
        case FIELD_rate: if (i >= 8) return "";
                return double2string(pp->rate[i]);
        default: return "";
    }
}

bool Ieee80211SupportedRatesElementDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211SupportedRatesElement *pp = (Ieee80211SupportedRatesElement *)object; (void)pp;
    switch (field) {
        case FIELD_numRates: pp->numRates = string2long(value); return true;
        case FIELD_rate: if (i >= 8) return "";
                pp->rate[i] = string2double(value); return true;
        default: return false;
    }
}

const char *Ieee80211SupportedRatesElementDescriptor::getFieldStructName(int field) const
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

void *Ieee80211SupportedRatesElementDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211SupportedRatesElement *pp = (Ieee80211SupportedRatesElement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211MgmtFrame)

Ieee80211MgmtFrame::Ieee80211MgmtFrame() : ::inet::FieldsChunk()
{
}

Ieee80211MgmtFrame::Ieee80211MgmtFrame(const Ieee80211MgmtFrame& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ieee80211MgmtFrame::~Ieee80211MgmtFrame()
{
}

Ieee80211MgmtFrame& Ieee80211MgmtFrame::operator=(const Ieee80211MgmtFrame& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211MgmtFrame::copy(const Ieee80211MgmtFrame& other)
{
}

void Ieee80211MgmtFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
}

void Ieee80211MgmtFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
}

class Ieee80211MgmtFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211MgmtFrameDescriptor();
    virtual ~Ieee80211MgmtFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211MgmtFrameDescriptor)

Ieee80211MgmtFrameDescriptor::Ieee80211MgmtFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211MgmtFrame)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ieee80211MgmtFrameDescriptor::~Ieee80211MgmtFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211MgmtFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211MgmtFrame *>(obj)!=nullptr;
}

const char **Ieee80211MgmtFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211MgmtFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211MgmtFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211MgmtFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211MgmtFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211MgmtFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211MgmtFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211MgmtFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211MgmtFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211MgmtFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MgmtFrame *pp = (Ieee80211MgmtFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211MgmtFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MgmtFrame *pp = (Ieee80211MgmtFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211MgmtFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MgmtFrame *pp = (Ieee80211MgmtFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211MgmtFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MgmtFrame *pp = (Ieee80211MgmtFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211MgmtFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211MgmtFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MgmtFrame *pp = (Ieee80211MgmtFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211AuthenticationFrame)

Ieee80211AuthenticationFrame::Ieee80211AuthenticationFrame() : ::inet::ieee80211::Ieee80211MgmtFrame()
{
    this->setChunkLength(B(6));

}

Ieee80211AuthenticationFrame::Ieee80211AuthenticationFrame(const Ieee80211AuthenticationFrame& other) : ::inet::ieee80211::Ieee80211MgmtFrame(other)
{
    copy(other);
}

Ieee80211AuthenticationFrame::~Ieee80211AuthenticationFrame()
{
}

Ieee80211AuthenticationFrame& Ieee80211AuthenticationFrame::operator=(const Ieee80211AuthenticationFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211MgmtFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AuthenticationFrame::copy(const Ieee80211AuthenticationFrame& other)
{
    this->sequenceNumber = other.sequenceNumber;
    this->statusCode = other.statusCode;
    this->isLast_ = other.isLast_;
}

void Ieee80211AuthenticationFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimPack(b);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->statusCode);
    doParsimPacking(b,this->isLast_);
}

void Ieee80211AuthenticationFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->statusCode);
    doParsimUnpacking(b,this->isLast_);
}

unsigned short Ieee80211AuthenticationFrame::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void Ieee80211AuthenticationFrame::setSequenceNumber(unsigned short sequenceNumber)
{
    handleChange();
    this->sequenceNumber = sequenceNumber;
}

inet::ieee80211::Ieee80211StatusCode Ieee80211AuthenticationFrame::getStatusCode() const
{
    return this->statusCode;
}

void Ieee80211AuthenticationFrame::setStatusCode(inet::ieee80211::Ieee80211StatusCode statusCode)
{
    handleChange();
    this->statusCode = statusCode;
}

bool Ieee80211AuthenticationFrame::isLast() const
{
    return this->isLast_;
}

void Ieee80211AuthenticationFrame::setIsLast(bool isLast)
{
    handleChange();
    this->isLast_ = isLast;
}

class Ieee80211AuthenticationFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_sequenceNumber,
        FIELD_statusCode,
        FIELD_isLast,
    };
  public:
    Ieee80211AuthenticationFrameDescriptor();
    virtual ~Ieee80211AuthenticationFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211AuthenticationFrameDescriptor)

Ieee80211AuthenticationFrameDescriptor::Ieee80211AuthenticationFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211AuthenticationFrame)), "inet::ieee80211::Ieee80211MgmtFrame")
{
    propertynames = nullptr;
}

Ieee80211AuthenticationFrameDescriptor::~Ieee80211AuthenticationFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AuthenticationFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AuthenticationFrame *>(obj)!=nullptr;
}

const char **Ieee80211AuthenticationFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AuthenticationFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AuthenticationFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211AuthenticationFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        0,    // FIELD_statusCode
        FD_ISEDITABLE,    // FIELD_isLast
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211AuthenticationFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sequenceNumber",
        "statusCode",
        "isLast",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ieee80211AuthenticationFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sequenceNumber") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "statusCode") == 0) return base+1;
    if (fieldName[0] == 'i' && strcmp(fieldName, "isLast") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AuthenticationFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_sequenceNumber
        "inet::ieee80211::Ieee80211StatusCode",    // FIELD_statusCode
        "bool",    // FIELD_isLast
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AuthenticationFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_statusCode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211AuthenticationFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_statusCode:
            if (!strcmp(propertyname, "enum")) return "inet::ieee80211::Ieee80211StatusCode";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211AuthenticationFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrame *pp = (Ieee80211AuthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AuthenticationFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrame *pp = (Ieee80211AuthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AuthenticationFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrame *pp = (Ieee80211AuthenticationFrame *)object; (void)pp;
    switch (field) {
        case FIELD_sequenceNumber: return ulong2string(pp->getSequenceNumber());
        case FIELD_statusCode: return enum2string(pp->getStatusCode(), "inet::ieee80211::Ieee80211StatusCode");
        case FIELD_isLast: return bool2string(pp->isLast());
        default: return "";
    }
}

bool Ieee80211AuthenticationFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrame *pp = (Ieee80211AuthenticationFrame *)object; (void)pp;
    switch (field) {
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2ulong(value)); return true;
        case FIELD_isLast: pp->setIsLast(string2bool(value)); return true;
        default: return false;
    }
}

const char *Ieee80211AuthenticationFrameDescriptor::getFieldStructName(int field) const
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

void *Ieee80211AuthenticationFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrame *pp = (Ieee80211AuthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211DeauthenticationFrame)

Ieee80211DeauthenticationFrame::Ieee80211DeauthenticationFrame() : ::inet::ieee80211::Ieee80211MgmtFrame()
{
    this->setChunkLength(B(2));

}

Ieee80211DeauthenticationFrame::Ieee80211DeauthenticationFrame(const Ieee80211DeauthenticationFrame& other) : ::inet::ieee80211::Ieee80211MgmtFrame(other)
{
    copy(other);
}

Ieee80211DeauthenticationFrame::~Ieee80211DeauthenticationFrame()
{
}

Ieee80211DeauthenticationFrame& Ieee80211DeauthenticationFrame::operator=(const Ieee80211DeauthenticationFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211MgmtFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DeauthenticationFrame::copy(const Ieee80211DeauthenticationFrame& other)
{
    this->reasonCode = other.reasonCode;
}

void Ieee80211DeauthenticationFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimPack(b);
    doParsimPacking(b,this->reasonCode);
}

void Ieee80211DeauthenticationFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->reasonCode);
}

inet::ieee80211::Ieee80211ReasonCode Ieee80211DeauthenticationFrame::getReasonCode() const
{
    return this->reasonCode;
}

void Ieee80211DeauthenticationFrame::setReasonCode(inet::ieee80211::Ieee80211ReasonCode reasonCode)
{
    handleChange();
    this->reasonCode = reasonCode;
}

class Ieee80211DeauthenticationFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_reasonCode,
    };
  public:
    Ieee80211DeauthenticationFrameDescriptor();
    virtual ~Ieee80211DeauthenticationFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211DeauthenticationFrameDescriptor)

Ieee80211DeauthenticationFrameDescriptor::Ieee80211DeauthenticationFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211DeauthenticationFrame)), "inet::ieee80211::Ieee80211MgmtFrame")
{
    propertynames = nullptr;
}

Ieee80211DeauthenticationFrameDescriptor::~Ieee80211DeauthenticationFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DeauthenticationFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DeauthenticationFrame *>(obj)!=nullptr;
}

const char **Ieee80211DeauthenticationFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DeauthenticationFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DeauthenticationFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211DeauthenticationFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_reasonCode
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211DeauthenticationFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reasonCode",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ieee80211DeauthenticationFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reasonCode") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DeauthenticationFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ieee80211::Ieee80211ReasonCode",    // FIELD_reasonCode
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DeauthenticationFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_reasonCode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211DeauthenticationFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_reasonCode:
            if (!strcmp(propertyname, "enum")) return "inet::ieee80211::Ieee80211ReasonCode";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211DeauthenticationFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrame *pp = (Ieee80211DeauthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DeauthenticationFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrame *pp = (Ieee80211DeauthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DeauthenticationFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrame *pp = (Ieee80211DeauthenticationFrame *)object; (void)pp;
    switch (field) {
        case FIELD_reasonCode: return enum2string(pp->getReasonCode(), "inet::ieee80211::Ieee80211ReasonCode");
        default: return "";
    }
}

bool Ieee80211DeauthenticationFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrame *pp = (Ieee80211DeauthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211DeauthenticationFrameDescriptor::getFieldStructName(int field) const
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

void *Ieee80211DeauthenticationFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrame *pp = (Ieee80211DeauthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211DisassociationFrame)

Ieee80211DisassociationFrame::Ieee80211DisassociationFrame() : ::inet::ieee80211::Ieee80211MgmtFrame()
{
    this->setChunkLength(B(2));

}

Ieee80211DisassociationFrame::Ieee80211DisassociationFrame(const Ieee80211DisassociationFrame& other) : ::inet::ieee80211::Ieee80211MgmtFrame(other)
{
    copy(other);
}

Ieee80211DisassociationFrame::~Ieee80211DisassociationFrame()
{
}

Ieee80211DisassociationFrame& Ieee80211DisassociationFrame::operator=(const Ieee80211DisassociationFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211MgmtFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DisassociationFrame::copy(const Ieee80211DisassociationFrame& other)
{
    this->reasonCode = other.reasonCode;
}

void Ieee80211DisassociationFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimPack(b);
    doParsimPacking(b,this->reasonCode);
}

void Ieee80211DisassociationFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->reasonCode);
}

inet::ieee80211::Ieee80211ReasonCode Ieee80211DisassociationFrame::getReasonCode() const
{
    return this->reasonCode;
}

void Ieee80211DisassociationFrame::setReasonCode(inet::ieee80211::Ieee80211ReasonCode reasonCode)
{
    handleChange();
    this->reasonCode = reasonCode;
}

class Ieee80211DisassociationFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_reasonCode,
    };
  public:
    Ieee80211DisassociationFrameDescriptor();
    virtual ~Ieee80211DisassociationFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211DisassociationFrameDescriptor)

Ieee80211DisassociationFrameDescriptor::Ieee80211DisassociationFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211DisassociationFrame)), "inet::ieee80211::Ieee80211MgmtFrame")
{
    propertynames = nullptr;
}

Ieee80211DisassociationFrameDescriptor::~Ieee80211DisassociationFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DisassociationFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DisassociationFrame *>(obj)!=nullptr;
}

const char **Ieee80211DisassociationFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DisassociationFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DisassociationFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211DisassociationFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_reasonCode
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211DisassociationFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reasonCode",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ieee80211DisassociationFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reasonCode") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DisassociationFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ieee80211::Ieee80211ReasonCode",    // FIELD_reasonCode
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DisassociationFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_reasonCode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211DisassociationFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_reasonCode:
            if (!strcmp(propertyname, "enum")) return "inet::ieee80211::Ieee80211ReasonCode";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211DisassociationFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrame *pp = (Ieee80211DisassociationFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DisassociationFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrame *pp = (Ieee80211DisassociationFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DisassociationFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrame *pp = (Ieee80211DisassociationFrame *)object; (void)pp;
    switch (field) {
        case FIELD_reasonCode: return enum2string(pp->getReasonCode(), "inet::ieee80211::Ieee80211ReasonCode");
        default: return "";
    }
}

bool Ieee80211DisassociationFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrame *pp = (Ieee80211DisassociationFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211DisassociationFrameDescriptor::getFieldStructName(int field) const
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

void *Ieee80211DisassociationFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrame *pp = (Ieee80211DisassociationFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211ProbeRequestFrame)

Ieee80211ProbeRequestFrame::Ieee80211ProbeRequestFrame() : ::inet::ieee80211::Ieee80211MgmtFrame()
{
}

Ieee80211ProbeRequestFrame::Ieee80211ProbeRequestFrame(const Ieee80211ProbeRequestFrame& other) : ::inet::ieee80211::Ieee80211MgmtFrame(other)
{
    copy(other);
}

Ieee80211ProbeRequestFrame::~Ieee80211ProbeRequestFrame()
{
}

Ieee80211ProbeRequestFrame& Ieee80211ProbeRequestFrame::operator=(const Ieee80211ProbeRequestFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211MgmtFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ProbeRequestFrame::copy(const Ieee80211ProbeRequestFrame& other)
{
    this->SSID = other.SSID;
    this->supportedRates = other.supportedRates;
}

void Ieee80211ProbeRequestFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimPack(b);
    doParsimPacking(b,this->SSID);
    doParsimPacking(b,this->supportedRates);
}

void Ieee80211ProbeRequestFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->SSID);
    doParsimUnpacking(b,this->supportedRates);
}

const char * Ieee80211ProbeRequestFrame::getSSID() const
{
    return this->SSID.c_str();
}

void Ieee80211ProbeRequestFrame::setSSID(const char * SSID)
{
    handleChange();
    this->SSID = SSID;
}

const Ieee80211SupportedRatesElement& Ieee80211ProbeRequestFrame::getSupportedRates() const
{
    return this->supportedRates;
}

void Ieee80211ProbeRequestFrame::setSupportedRates(const Ieee80211SupportedRatesElement& supportedRates)
{
    handleChange();
    this->supportedRates = supportedRates;
}

class Ieee80211ProbeRequestFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_SSID,
        FIELD_supportedRates,
    };
  public:
    Ieee80211ProbeRequestFrameDescriptor();
    virtual ~Ieee80211ProbeRequestFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211ProbeRequestFrameDescriptor)

Ieee80211ProbeRequestFrameDescriptor::Ieee80211ProbeRequestFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211ProbeRequestFrame)), "inet::ieee80211::Ieee80211MgmtFrame")
{
    propertynames = nullptr;
}

Ieee80211ProbeRequestFrameDescriptor::~Ieee80211ProbeRequestFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ProbeRequestFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ProbeRequestFrame *>(obj)!=nullptr;
}

const char **Ieee80211ProbeRequestFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ProbeRequestFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ProbeRequestFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ieee80211ProbeRequestFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_SSID
        FD_ISCOMPOUND,    // FIELD_supportedRates
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211ProbeRequestFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "SSID",
        "supportedRates",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ieee80211ProbeRequestFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'S' && strcmp(fieldName, "SSID") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "supportedRates") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ProbeRequestFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_SSID
        "inet::ieee80211::Ieee80211SupportedRatesElement",    // FIELD_supportedRates
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ProbeRequestFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ProbeRequestFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ProbeRequestFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrame *pp = (Ieee80211ProbeRequestFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ProbeRequestFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrame *pp = (Ieee80211ProbeRequestFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ProbeRequestFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrame *pp = (Ieee80211ProbeRequestFrame *)object; (void)pp;
    switch (field) {
        case FIELD_SSID: return oppstring2string(pp->getSSID());
        case FIELD_supportedRates: {std::stringstream out; out << pp->getSupportedRates(); return out.str();}
        default: return "";
    }
}

bool Ieee80211ProbeRequestFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrame *pp = (Ieee80211ProbeRequestFrame *)object; (void)pp;
    switch (field) {
        case FIELD_SSID: pp->setSSID((value)); return true;
        default: return false;
    }
}

const char *Ieee80211ProbeRequestFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_supportedRates: return omnetpp::opp_typename(typeid(Ieee80211SupportedRatesElement));
        default: return nullptr;
    };
}

void *Ieee80211ProbeRequestFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrame *pp = (Ieee80211ProbeRequestFrame *)object; (void)pp;
    switch (field) {
        case FIELD_supportedRates: return toVoidPtr(&pp->getSupportedRates()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211AssociationRequestFrame)

Ieee80211AssociationRequestFrame::Ieee80211AssociationRequestFrame() : ::inet::ieee80211::Ieee80211MgmtFrame()
{
}

Ieee80211AssociationRequestFrame::Ieee80211AssociationRequestFrame(const Ieee80211AssociationRequestFrame& other) : ::inet::ieee80211::Ieee80211MgmtFrame(other)
{
    copy(other);
}

Ieee80211AssociationRequestFrame::~Ieee80211AssociationRequestFrame()
{
}

Ieee80211AssociationRequestFrame& Ieee80211AssociationRequestFrame::operator=(const Ieee80211AssociationRequestFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211MgmtFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AssociationRequestFrame::copy(const Ieee80211AssociationRequestFrame& other)
{
    this->SSID = other.SSID;
    this->supportedRates = other.supportedRates;
}

void Ieee80211AssociationRequestFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimPack(b);
    doParsimPacking(b,this->SSID);
    doParsimPacking(b,this->supportedRates);
}

void Ieee80211AssociationRequestFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->SSID);
    doParsimUnpacking(b,this->supportedRates);
}

const char * Ieee80211AssociationRequestFrame::getSSID() const
{
    return this->SSID.c_str();
}

void Ieee80211AssociationRequestFrame::setSSID(const char * SSID)
{
    handleChange();
    this->SSID = SSID;
}

const Ieee80211SupportedRatesElement& Ieee80211AssociationRequestFrame::getSupportedRates() const
{
    return this->supportedRates;
}

void Ieee80211AssociationRequestFrame::setSupportedRates(const Ieee80211SupportedRatesElement& supportedRates)
{
    handleChange();
    this->supportedRates = supportedRates;
}

class Ieee80211AssociationRequestFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_SSID,
        FIELD_supportedRates,
    };
  public:
    Ieee80211AssociationRequestFrameDescriptor();
    virtual ~Ieee80211AssociationRequestFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211AssociationRequestFrameDescriptor)

Ieee80211AssociationRequestFrameDescriptor::Ieee80211AssociationRequestFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211AssociationRequestFrame)), "inet::ieee80211::Ieee80211MgmtFrame")
{
    propertynames = nullptr;
}

Ieee80211AssociationRequestFrameDescriptor::~Ieee80211AssociationRequestFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AssociationRequestFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AssociationRequestFrame *>(obj)!=nullptr;
}

const char **Ieee80211AssociationRequestFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AssociationRequestFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AssociationRequestFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ieee80211AssociationRequestFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_SSID
        FD_ISCOMPOUND,    // FIELD_supportedRates
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211AssociationRequestFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "SSID",
        "supportedRates",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ieee80211AssociationRequestFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'S' && strcmp(fieldName, "SSID") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "supportedRates") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AssociationRequestFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_SSID
        "inet::ieee80211::Ieee80211SupportedRatesElement",    // FIELD_supportedRates
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AssociationRequestFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AssociationRequestFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211AssociationRequestFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrame *pp = (Ieee80211AssociationRequestFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AssociationRequestFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrame *pp = (Ieee80211AssociationRequestFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AssociationRequestFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrame *pp = (Ieee80211AssociationRequestFrame *)object; (void)pp;
    switch (field) {
        case FIELD_SSID: return oppstring2string(pp->getSSID());
        case FIELD_supportedRates: {std::stringstream out; out << pp->getSupportedRates(); return out.str();}
        default: return "";
    }
}

bool Ieee80211AssociationRequestFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrame *pp = (Ieee80211AssociationRequestFrame *)object; (void)pp;
    switch (field) {
        case FIELD_SSID: pp->setSSID((value)); return true;
        default: return false;
    }
}

const char *Ieee80211AssociationRequestFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_supportedRates: return omnetpp::opp_typename(typeid(Ieee80211SupportedRatesElement));
        default: return nullptr;
    };
}

void *Ieee80211AssociationRequestFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrame *pp = (Ieee80211AssociationRequestFrame *)object; (void)pp;
    switch (field) {
        case FIELD_supportedRates: return toVoidPtr(&pp->getSupportedRates()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211ReassociationRequestFrame)

Ieee80211ReassociationRequestFrame::Ieee80211ReassociationRequestFrame() : ::inet::ieee80211::Ieee80211AssociationRequestFrame()
{
}

Ieee80211ReassociationRequestFrame::Ieee80211ReassociationRequestFrame(const Ieee80211ReassociationRequestFrame& other) : ::inet::ieee80211::Ieee80211AssociationRequestFrame(other)
{
    copy(other);
}

Ieee80211ReassociationRequestFrame::~Ieee80211ReassociationRequestFrame()
{
}

Ieee80211ReassociationRequestFrame& Ieee80211ReassociationRequestFrame::operator=(const Ieee80211ReassociationRequestFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211AssociationRequestFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ReassociationRequestFrame::copy(const Ieee80211ReassociationRequestFrame& other)
{
    this->currentAP = other.currentAP;
}

void Ieee80211ReassociationRequestFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211AssociationRequestFrame::parsimPack(b);
    doParsimPacking(b,this->currentAP);
}

void Ieee80211ReassociationRequestFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211AssociationRequestFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->currentAP);
}

const MacAddress& Ieee80211ReassociationRequestFrame::getCurrentAP() const
{
    return this->currentAP;
}

void Ieee80211ReassociationRequestFrame::setCurrentAP(const MacAddress& currentAP)
{
    handleChange();
    this->currentAP = currentAP;
}

class Ieee80211ReassociationRequestFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_currentAP,
    };
  public:
    Ieee80211ReassociationRequestFrameDescriptor();
    virtual ~Ieee80211ReassociationRequestFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211ReassociationRequestFrameDescriptor)

Ieee80211ReassociationRequestFrameDescriptor::Ieee80211ReassociationRequestFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211ReassociationRequestFrame)), "inet::ieee80211::Ieee80211AssociationRequestFrame")
{
    propertynames = nullptr;
}

Ieee80211ReassociationRequestFrameDescriptor::~Ieee80211ReassociationRequestFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ReassociationRequestFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ReassociationRequestFrame *>(obj)!=nullptr;
}

const char **Ieee80211ReassociationRequestFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ReassociationRequestFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ReassociationRequestFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211ReassociationRequestFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_currentAP
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211ReassociationRequestFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "currentAP",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ieee80211ReassociationRequestFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "currentAP") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ReassociationRequestFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MacAddress",    // FIELD_currentAP
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ReassociationRequestFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ReassociationRequestFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ReassociationRequestFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrame *pp = (Ieee80211ReassociationRequestFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ReassociationRequestFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrame *pp = (Ieee80211ReassociationRequestFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ReassociationRequestFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrame *pp = (Ieee80211ReassociationRequestFrame *)object; (void)pp;
    switch (field) {
        case FIELD_currentAP: return pp->getCurrentAP().str();
        default: return "";
    }
}

bool Ieee80211ReassociationRequestFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrame *pp = (Ieee80211ReassociationRequestFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ReassociationRequestFrameDescriptor::getFieldStructName(int field) const
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

void *Ieee80211ReassociationRequestFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrame *pp = (Ieee80211ReassociationRequestFrame *)object; (void)pp;
    switch (field) {
        case FIELD_currentAP: return toVoidPtr(&pp->getCurrentAP()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211AssociationResponseFrame)

Ieee80211AssociationResponseFrame::Ieee80211AssociationResponseFrame() : ::inet::ieee80211::Ieee80211MgmtFrame()
{
}

Ieee80211AssociationResponseFrame::Ieee80211AssociationResponseFrame(const Ieee80211AssociationResponseFrame& other) : ::inet::ieee80211::Ieee80211MgmtFrame(other)
{
    copy(other);
}

Ieee80211AssociationResponseFrame::~Ieee80211AssociationResponseFrame()
{
}

Ieee80211AssociationResponseFrame& Ieee80211AssociationResponseFrame::operator=(const Ieee80211AssociationResponseFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211MgmtFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AssociationResponseFrame::copy(const Ieee80211AssociationResponseFrame& other)
{
    this->statusCode = other.statusCode;
    this->aid = other.aid;
    this->supportedRates = other.supportedRates;
}

void Ieee80211AssociationResponseFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimPack(b);
    doParsimPacking(b,this->statusCode);
    doParsimPacking(b,this->aid);
    doParsimPacking(b,this->supportedRates);
}

void Ieee80211AssociationResponseFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->statusCode);
    doParsimUnpacking(b,this->aid);
    doParsimUnpacking(b,this->supportedRates);
}

inet::ieee80211::Ieee80211StatusCode Ieee80211AssociationResponseFrame::getStatusCode() const
{
    return this->statusCode;
}

void Ieee80211AssociationResponseFrame::setStatusCode(inet::ieee80211::Ieee80211StatusCode statusCode)
{
    handleChange();
    this->statusCode = statusCode;
}

short Ieee80211AssociationResponseFrame::getAid() const
{
    return this->aid;
}

void Ieee80211AssociationResponseFrame::setAid(short aid)
{
    handleChange();
    this->aid = aid;
}

const Ieee80211SupportedRatesElement& Ieee80211AssociationResponseFrame::getSupportedRates() const
{
    return this->supportedRates;
}

void Ieee80211AssociationResponseFrame::setSupportedRates(const Ieee80211SupportedRatesElement& supportedRates)
{
    handleChange();
    this->supportedRates = supportedRates;
}

class Ieee80211AssociationResponseFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_statusCode,
        FIELD_aid,
        FIELD_supportedRates,
    };
  public:
    Ieee80211AssociationResponseFrameDescriptor();
    virtual ~Ieee80211AssociationResponseFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211AssociationResponseFrameDescriptor)

Ieee80211AssociationResponseFrameDescriptor::Ieee80211AssociationResponseFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211AssociationResponseFrame)), "inet::ieee80211::Ieee80211MgmtFrame")
{
    propertynames = nullptr;
}

Ieee80211AssociationResponseFrameDescriptor::~Ieee80211AssociationResponseFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AssociationResponseFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AssociationResponseFrame *>(obj)!=nullptr;
}

const char **Ieee80211AssociationResponseFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AssociationResponseFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AssociationResponseFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211AssociationResponseFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_statusCode
        FD_ISEDITABLE,    // FIELD_aid
        FD_ISCOMPOUND,    // FIELD_supportedRates
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211AssociationResponseFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "statusCode",
        "aid",
        "supportedRates",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ieee80211AssociationResponseFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "statusCode") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "aid") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "supportedRates") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AssociationResponseFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ieee80211::Ieee80211StatusCode",    // FIELD_statusCode
        "short",    // FIELD_aid
        "inet::ieee80211::Ieee80211SupportedRatesElement",    // FIELD_supportedRates
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AssociationResponseFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_statusCode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211AssociationResponseFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_statusCode:
            if (!strcmp(propertyname, "enum")) return "inet::ieee80211::Ieee80211StatusCode";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211AssociationResponseFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrame *pp = (Ieee80211AssociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AssociationResponseFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrame *pp = (Ieee80211AssociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AssociationResponseFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrame *pp = (Ieee80211AssociationResponseFrame *)object; (void)pp;
    switch (field) {
        case FIELD_statusCode: return enum2string(pp->getStatusCode(), "inet::ieee80211::Ieee80211StatusCode");
        case FIELD_aid: return long2string(pp->getAid());
        case FIELD_supportedRates: {std::stringstream out; out << pp->getSupportedRates(); return out.str();}
        default: return "";
    }
}

bool Ieee80211AssociationResponseFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrame *pp = (Ieee80211AssociationResponseFrame *)object; (void)pp;
    switch (field) {
        case FIELD_aid: pp->setAid(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211AssociationResponseFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_supportedRates: return omnetpp::opp_typename(typeid(Ieee80211SupportedRatesElement));
        default: return nullptr;
    };
}

void *Ieee80211AssociationResponseFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrame *pp = (Ieee80211AssociationResponseFrame *)object; (void)pp;
    switch (field) {
        case FIELD_supportedRates: return toVoidPtr(&pp->getSupportedRates()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211ReassociationResponseFrame)

Ieee80211ReassociationResponseFrame::Ieee80211ReassociationResponseFrame() : ::inet::ieee80211::Ieee80211AssociationResponseFrame()
{
}

Ieee80211ReassociationResponseFrame::Ieee80211ReassociationResponseFrame(const Ieee80211ReassociationResponseFrame& other) : ::inet::ieee80211::Ieee80211AssociationResponseFrame(other)
{
    copy(other);
}

Ieee80211ReassociationResponseFrame::~Ieee80211ReassociationResponseFrame()
{
}

Ieee80211ReassociationResponseFrame& Ieee80211ReassociationResponseFrame::operator=(const Ieee80211ReassociationResponseFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211AssociationResponseFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ReassociationResponseFrame::copy(const Ieee80211ReassociationResponseFrame& other)
{
}

void Ieee80211ReassociationResponseFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211AssociationResponseFrame::parsimPack(b);
}

void Ieee80211ReassociationResponseFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211AssociationResponseFrame::parsimUnpack(b);
}

class Ieee80211ReassociationResponseFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211ReassociationResponseFrameDescriptor();
    virtual ~Ieee80211ReassociationResponseFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211ReassociationResponseFrameDescriptor)

Ieee80211ReassociationResponseFrameDescriptor::Ieee80211ReassociationResponseFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211ReassociationResponseFrame)), "inet::ieee80211::Ieee80211AssociationResponseFrame")
{
    propertynames = nullptr;
}

Ieee80211ReassociationResponseFrameDescriptor::~Ieee80211ReassociationResponseFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ReassociationResponseFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ReassociationResponseFrame *>(obj)!=nullptr;
}

const char **Ieee80211ReassociationResponseFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ReassociationResponseFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ReassociationResponseFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211ReassociationResponseFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211ReassociationResponseFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211ReassociationResponseFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ReassociationResponseFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211ReassociationResponseFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ReassociationResponseFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ReassociationResponseFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrame *pp = (Ieee80211ReassociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ReassociationResponseFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrame *pp = (Ieee80211ReassociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ReassociationResponseFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrame *pp = (Ieee80211ReassociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211ReassociationResponseFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrame *pp = (Ieee80211ReassociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ReassociationResponseFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211ReassociationResponseFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrame *pp = (Ieee80211ReassociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211BeaconFrame)

Ieee80211BeaconFrame::Ieee80211BeaconFrame() : ::inet::ieee80211::Ieee80211MgmtFrame()
{
}

Ieee80211BeaconFrame::Ieee80211BeaconFrame(const Ieee80211BeaconFrame& other) : ::inet::ieee80211::Ieee80211MgmtFrame(other)
{
    copy(other);
}

Ieee80211BeaconFrame::~Ieee80211BeaconFrame()
{
}

Ieee80211BeaconFrame& Ieee80211BeaconFrame::operator=(const Ieee80211BeaconFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211MgmtFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211BeaconFrame::copy(const Ieee80211BeaconFrame& other)
{
    this->SSID = other.SSID;
    this->supportedRates = other.supportedRates;
    this->beaconInterval = other.beaconInterval;
    this->channelNumber = other.channelNumber;
    this->handoverParameters = other.handoverParameters;
}

void Ieee80211BeaconFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimPack(b);
    doParsimPacking(b,this->SSID);
    doParsimPacking(b,this->supportedRates);
    doParsimPacking(b,this->beaconInterval);
    doParsimPacking(b,this->channelNumber);
    doParsimPacking(b,this->handoverParameters);
}

void Ieee80211BeaconFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211MgmtFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->SSID);
    doParsimUnpacking(b,this->supportedRates);
    doParsimUnpacking(b,this->beaconInterval);
    doParsimUnpacking(b,this->channelNumber);
    doParsimUnpacking(b,this->handoverParameters);
}

const char * Ieee80211BeaconFrame::getSSID() const
{
    return this->SSID.c_str();
}

void Ieee80211BeaconFrame::setSSID(const char * SSID)
{
    handleChange();
    this->SSID = SSID;
}

const Ieee80211SupportedRatesElement& Ieee80211BeaconFrame::getSupportedRates() const
{
    return this->supportedRates;
}

void Ieee80211BeaconFrame::setSupportedRates(const Ieee80211SupportedRatesElement& supportedRates)
{
    handleChange();
    this->supportedRates = supportedRates;
}

omnetpp::simtime_t Ieee80211BeaconFrame::getBeaconInterval() const
{
    return this->beaconInterval;
}

void Ieee80211BeaconFrame::setBeaconInterval(omnetpp::simtime_t beaconInterval)
{
    handleChange();
    this->beaconInterval = beaconInterval;
}

int Ieee80211BeaconFrame::getChannelNumber() const
{
    return this->channelNumber;
}

void Ieee80211BeaconFrame::setChannelNumber(int channelNumber)
{
    handleChange();
    this->channelNumber = channelNumber;
}

const Ieee80211HandoverParameters& Ieee80211BeaconFrame::getHandoverParameters() const
{
    return this->handoverParameters;
}

void Ieee80211BeaconFrame::setHandoverParameters(const Ieee80211HandoverParameters& handoverParameters)
{
    handleChange();
    this->handoverParameters = handoverParameters;
}

class Ieee80211BeaconFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_SSID,
        FIELD_supportedRates,
        FIELD_beaconInterval,
        FIELD_channelNumber,
        FIELD_handoverParameters,
    };
  public:
    Ieee80211BeaconFrameDescriptor();
    virtual ~Ieee80211BeaconFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211BeaconFrameDescriptor)

Ieee80211BeaconFrameDescriptor::Ieee80211BeaconFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211BeaconFrame)), "inet::ieee80211::Ieee80211MgmtFrame")
{
    propertynames = nullptr;
}

Ieee80211BeaconFrameDescriptor::~Ieee80211BeaconFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211BeaconFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211BeaconFrame *>(obj)!=nullptr;
}

const char **Ieee80211BeaconFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211BeaconFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211BeaconFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int Ieee80211BeaconFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_SSID
        FD_ISCOMPOUND,    // FIELD_supportedRates
        0,    // FIELD_beaconInterval
        FD_ISEDITABLE,    // FIELD_channelNumber
        FD_ISCOMPOUND,    // FIELD_handoverParameters
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211BeaconFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "SSID",
        "supportedRates",
        "beaconInterval",
        "channelNumber",
        "handoverParameters",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int Ieee80211BeaconFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'S' && strcmp(fieldName, "SSID") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "supportedRates") == 0) return base+1;
    if (fieldName[0] == 'b' && strcmp(fieldName, "beaconInterval") == 0) return base+2;
    if (fieldName[0] == 'c' && strcmp(fieldName, "channelNumber") == 0) return base+3;
    if (fieldName[0] == 'h' && strcmp(fieldName, "handoverParameters") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211BeaconFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_SSID
        "inet::ieee80211::Ieee80211SupportedRatesElement",    // FIELD_supportedRates
        "omnetpp::simtime_t",    // FIELD_beaconInterval
        "int",    // FIELD_channelNumber
        "inet::ieee80211::Ieee80211HandoverParameters",    // FIELD_handoverParameters
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211BeaconFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211BeaconFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211BeaconFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrame *pp = (Ieee80211BeaconFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211BeaconFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrame *pp = (Ieee80211BeaconFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211BeaconFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrame *pp = (Ieee80211BeaconFrame *)object; (void)pp;
    switch (field) {
        case FIELD_SSID: return oppstring2string(pp->getSSID());
        case FIELD_supportedRates: {std::stringstream out; out << pp->getSupportedRates(); return out.str();}
        case FIELD_beaconInterval: return simtime2string(pp->getBeaconInterval());
        case FIELD_channelNumber: return long2string(pp->getChannelNumber());
        case FIELD_handoverParameters: {std::stringstream out; out << pp->getHandoverParameters(); return out.str();}
        default: return "";
    }
}

bool Ieee80211BeaconFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrame *pp = (Ieee80211BeaconFrame *)object; (void)pp;
    switch (field) {
        case FIELD_SSID: pp->setSSID((value)); return true;
        case FIELD_channelNumber: pp->setChannelNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211BeaconFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_supportedRates: return omnetpp::opp_typename(typeid(Ieee80211SupportedRatesElement));
        case FIELD_handoverParameters: return omnetpp::opp_typename(typeid(Ieee80211HandoverParameters));
        default: return nullptr;
    };
}

void *Ieee80211BeaconFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrame *pp = (Ieee80211BeaconFrame *)object; (void)pp;
    switch (field) {
        case FIELD_supportedRates: return toVoidPtr(&pp->getSupportedRates()); break;
        case FIELD_handoverParameters: return toVoidPtr(&pp->getHandoverParameters()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211ProbeResponseFrame)

Ieee80211ProbeResponseFrame::Ieee80211ProbeResponseFrame() : ::inet::ieee80211::Ieee80211BeaconFrame()
{
}

Ieee80211ProbeResponseFrame::Ieee80211ProbeResponseFrame(const Ieee80211ProbeResponseFrame& other) : ::inet::ieee80211::Ieee80211BeaconFrame(other)
{
    copy(other);
}

Ieee80211ProbeResponseFrame::~Ieee80211ProbeResponseFrame()
{
}

Ieee80211ProbeResponseFrame& Ieee80211ProbeResponseFrame::operator=(const Ieee80211ProbeResponseFrame& other)
{
    if (this == &other) return *this;
    ::inet::ieee80211::Ieee80211BeaconFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ProbeResponseFrame::copy(const Ieee80211ProbeResponseFrame& other)
{
}

void Ieee80211ProbeResponseFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BeaconFrame::parsimPack(b);
}

void Ieee80211ProbeResponseFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BeaconFrame::parsimUnpack(b);
}

class Ieee80211ProbeResponseFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211ProbeResponseFrameDescriptor();
    virtual ~Ieee80211ProbeResponseFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211ProbeResponseFrameDescriptor)

Ieee80211ProbeResponseFrameDescriptor::Ieee80211ProbeResponseFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::Ieee80211ProbeResponseFrame)), "inet::ieee80211::Ieee80211BeaconFrame")
{
    propertynames = nullptr;
}

Ieee80211ProbeResponseFrameDescriptor::~Ieee80211ProbeResponseFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ProbeResponseFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ProbeResponseFrame *>(obj)!=nullptr;
}

const char **Ieee80211ProbeResponseFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ProbeResponseFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ProbeResponseFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211ProbeResponseFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211ProbeResponseFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211ProbeResponseFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ProbeResponseFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211ProbeResponseFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ProbeResponseFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ProbeResponseFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrame *pp = (Ieee80211ProbeResponseFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ProbeResponseFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrame *pp = (Ieee80211ProbeResponseFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ProbeResponseFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrame *pp = (Ieee80211ProbeResponseFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211ProbeResponseFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrame *pp = (Ieee80211ProbeResponseFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ProbeResponseFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211ProbeResponseFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrame *pp = (Ieee80211ProbeResponseFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace ieee80211
} // namespace inet

