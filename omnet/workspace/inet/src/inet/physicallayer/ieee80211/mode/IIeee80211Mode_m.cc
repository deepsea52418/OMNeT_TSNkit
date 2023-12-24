//
// Generated file, do not edit! Created by nedtool 5.6 from inet/physicallayer/ieee80211/mode/IIeee80211Mode.msg.
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
#include "IIeee80211Mode_m.h"

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
namespace physicallayer {

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

class IIeee80211PreambleModeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_duration,
    };
  public:
    IIeee80211PreambleModeDescriptor();
    virtual ~IIeee80211PreambleModeDescriptor();

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

Register_ClassDescriptor(IIeee80211PreambleModeDescriptor)

IIeee80211PreambleModeDescriptor::IIeee80211PreambleModeDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::IIeee80211PreambleMode)), "")
{
    propertynames = nullptr;
}

IIeee80211PreambleModeDescriptor::~IIeee80211PreambleModeDescriptor()
{
    delete[] propertynames;
}

bool IIeee80211PreambleModeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IIeee80211PreambleMode *>(obj)!=nullptr;
}

const char **IIeee80211PreambleModeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IIeee80211PreambleModeDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IIeee80211PreambleModeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IIeee80211PreambleModeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_duration
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *IIeee80211PreambleModeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "duration",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int IIeee80211PreambleModeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "duration") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IIeee80211PreambleModeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "omnetpp::simtime_t",    // FIELD_duration
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **IIeee80211PreambleModeDescriptor::getFieldPropertyNames(int field) const
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

const char *IIeee80211PreambleModeDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IIeee80211PreambleModeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IIeee80211PreambleMode *pp = (IIeee80211PreambleMode *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IIeee80211PreambleModeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211PreambleMode *pp = (IIeee80211PreambleMode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IIeee80211PreambleModeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211PreambleMode *pp = (IIeee80211PreambleMode *)object; (void)pp;
    switch (field) {
        case FIELD_duration: return simtime2string(pp->getDuration());
        default: return "";
    }
}

bool IIeee80211PreambleModeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IIeee80211PreambleMode *pp = (IIeee80211PreambleMode *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IIeee80211PreambleModeDescriptor::getFieldStructName(int field) const
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

void *IIeee80211PreambleModeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211PreambleMode *pp = (IIeee80211PreambleMode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class IIeee80211HeaderModeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_netBitrate,
        FIELD_grossBitrate,
        FIELD_Length,
        FIELD_duration,
        FIELD_modulation,
    };
  public:
    IIeee80211HeaderModeDescriptor();
    virtual ~IIeee80211HeaderModeDescriptor();

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

Register_ClassDescriptor(IIeee80211HeaderModeDescriptor)

IIeee80211HeaderModeDescriptor::IIeee80211HeaderModeDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::IIeee80211HeaderMode)), "")
{
    propertynames = nullptr;
}

IIeee80211HeaderModeDescriptor::~IIeee80211HeaderModeDescriptor()
{
    delete[] propertynames;
}

bool IIeee80211HeaderModeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IIeee80211HeaderMode *>(obj)!=nullptr;
}

const char **IIeee80211HeaderModeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IIeee80211HeaderModeDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IIeee80211HeaderModeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int IIeee80211HeaderModeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_netBitrate
        0,    // FIELD_grossBitrate
        0,    // FIELD_Length
        0,    // FIELD_duration
        FD_ISCOMPOUND | FD_ISPOINTER,    // FIELD_modulation
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *IIeee80211HeaderModeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "netBitrate",
        "grossBitrate",
        "Length",
        "duration",
        "modulation",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int IIeee80211HeaderModeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "netBitrate") == 0) return base+0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "grossBitrate") == 0) return base+1;
    if (fieldName[0] == 'L' && strcmp(fieldName, "Length") == 0) return base+2;
    if (fieldName[0] == 'd' && strcmp(fieldName, "duration") == 0) return base+3;
    if (fieldName[0] == 'm' && strcmp(fieldName, "modulation") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IIeee80211HeaderModeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bps",    // FIELD_netBitrate
        "inet::bps",    // FIELD_grossBitrate
        "inet::b",    // FIELD_Length
        "omnetpp::simtime_t",    // FIELD_duration
        "inet::physicallayer::IModulation",    // FIELD_modulation
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **IIeee80211HeaderModeDescriptor::getFieldPropertyNames(int field) const
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

const char *IIeee80211HeaderModeDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IIeee80211HeaderModeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IIeee80211HeaderMode *pp = (IIeee80211HeaderMode *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IIeee80211HeaderModeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211HeaderMode *pp = (IIeee80211HeaderMode *)object; (void)pp;
    switch (field) {
        case FIELD_modulation: { const IModulation * value = pp->getModulation(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string IIeee80211HeaderModeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211HeaderMode *pp = (IIeee80211HeaderMode *)object; (void)pp;
    switch (field) {
        case FIELD_netBitrate: return unit2string(pp->getNetBitrate());
        case FIELD_grossBitrate: return unit2string(pp->getGrossBitrate());
        case FIELD_Length: return unit2string(pp->getLength());
        case FIELD_duration: return simtime2string(pp->getDuration());
        case FIELD_modulation: {std::stringstream out; out << pp->getModulation(); return out.str();}
        default: return "";
    }
}

bool IIeee80211HeaderModeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IIeee80211HeaderMode *pp = (IIeee80211HeaderMode *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IIeee80211HeaderModeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_modulation: return omnetpp::opp_typename(typeid(IModulation));
        default: return nullptr;
    };
}

void *IIeee80211HeaderModeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211HeaderMode *pp = (IIeee80211HeaderMode *)object; (void)pp;
    switch (field) {
        case FIELD_modulation: return toVoidPtr(pp->getModulation()); break;
        default: return nullptr;
    }
}

class IIeee80211DataModeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_netBitrate,
        FIELD_grossBitrate,
        FIELD_modulation,
        FIELD_numberOfSpatialStreams,
    };
  public:
    IIeee80211DataModeDescriptor();
    virtual ~IIeee80211DataModeDescriptor();

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

Register_ClassDescriptor(IIeee80211DataModeDescriptor)

IIeee80211DataModeDescriptor::IIeee80211DataModeDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::IIeee80211DataMode)), "")
{
    propertynames = nullptr;
}

IIeee80211DataModeDescriptor::~IIeee80211DataModeDescriptor()
{
    delete[] propertynames;
}

bool IIeee80211DataModeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IIeee80211DataMode *>(obj)!=nullptr;
}

const char **IIeee80211DataModeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IIeee80211DataModeDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IIeee80211DataModeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int IIeee80211DataModeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_netBitrate
        0,    // FIELD_grossBitrate
        FD_ISCOMPOUND | FD_ISPOINTER,    // FIELD_modulation
        0,    // FIELD_numberOfSpatialStreams
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *IIeee80211DataModeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "netBitrate",
        "grossBitrate",
        "modulation",
        "numberOfSpatialStreams",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int IIeee80211DataModeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "netBitrate") == 0) return base+0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "grossBitrate") == 0) return base+1;
    if (fieldName[0] == 'm' && strcmp(fieldName, "modulation") == 0) return base+2;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numberOfSpatialStreams") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IIeee80211DataModeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::bps",    // FIELD_netBitrate
        "inet::bps",    // FIELD_grossBitrate
        "inet::physicallayer::IModulation",    // FIELD_modulation
        "int",    // FIELD_numberOfSpatialStreams
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **IIeee80211DataModeDescriptor::getFieldPropertyNames(int field) const
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

const char *IIeee80211DataModeDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IIeee80211DataModeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IIeee80211DataMode *pp = (IIeee80211DataMode *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IIeee80211DataModeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211DataMode *pp = (IIeee80211DataMode *)object; (void)pp;
    switch (field) {
        case FIELD_modulation: { const IModulation * value = pp->getModulation(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string IIeee80211DataModeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211DataMode *pp = (IIeee80211DataMode *)object; (void)pp;
    switch (field) {
        case FIELD_netBitrate: return unit2string(pp->getNetBitrate());
        case FIELD_grossBitrate: return unit2string(pp->getGrossBitrate());
        case FIELD_modulation: {std::stringstream out; out << pp->getModulation(); return out.str();}
        case FIELD_numberOfSpatialStreams: return long2string(pp->getNumberOfSpatialStreams());
        default: return "";
    }
}

bool IIeee80211DataModeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IIeee80211DataMode *pp = (IIeee80211DataMode *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IIeee80211DataModeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_modulation: return omnetpp::opp_typename(typeid(IModulation));
        default: return nullptr;
    };
}

void *IIeee80211DataModeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211DataMode *pp = (IIeee80211DataMode *)object; (void)pp;
    switch (field) {
        case FIELD_modulation: return toVoidPtr(pp->getModulation()); break;
        default: return nullptr;
    }
}

class IIeee80211ModeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_legacyCwMin,
        FIELD_legacyCwMax,
        FIELD_name,
        FIELD_preambleMode,
        FIELD_headerMode,
        FIELD_dataMode,
        FIELD_slotTime,
        FIELD_sifsTime,
        FIELD_rifsTime,
        FIELD_ccaTime,
        FIELD_phyRxStartDelay,
        FIELD_rxTxTurnaroundTime,
        FIELD_preambleLength,
        FIELD_plcpHeaderLength,
        FIELD_mpduMaxLength,
    };
  public:
    IIeee80211ModeDescriptor();
    virtual ~IIeee80211ModeDescriptor();

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

Register_ClassDescriptor(IIeee80211ModeDescriptor)

IIeee80211ModeDescriptor::IIeee80211ModeDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::IIeee80211Mode)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

IIeee80211ModeDescriptor::~IIeee80211ModeDescriptor()
{
    delete[] propertynames;
}

bool IIeee80211ModeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IIeee80211Mode *>(obj)!=nullptr;
}

const char **IIeee80211ModeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IIeee80211ModeDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IIeee80211ModeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount() : 15;
}

unsigned int IIeee80211ModeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_legacyCwMin
        0,    // FIELD_legacyCwMax
        0,    // FIELD_name
        FD_ISCOMPOUND | FD_ISPOINTER,    // FIELD_preambleMode
        FD_ISCOMPOUND | FD_ISPOINTER,    // FIELD_headerMode
        FD_ISCOMPOUND | FD_ISPOINTER,    // FIELD_dataMode
        0,    // FIELD_slotTime
        0,    // FIELD_sifsTime
        0,    // FIELD_rifsTime
        0,    // FIELD_ccaTime
        0,    // FIELD_phyRxStartDelay
        0,    // FIELD_rxTxTurnaroundTime
        0,    // FIELD_preambleLength
        0,    // FIELD_plcpHeaderLength
        0,    // FIELD_mpduMaxLength
    };
    return (field >= 0 && field < 15) ? fieldTypeFlags[field] : 0;
}

const char *IIeee80211ModeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "legacyCwMin",
        "legacyCwMax",
        "name",
        "preambleMode",
        "headerMode",
        "dataMode",
        "slotTime",
        "sifsTime",
        "rifsTime",
        "ccaTime",
        "phyRxStartDelay",
        "rxTxTurnaroundTime",
        "preambleLength",
        "plcpHeaderLength",
        "mpduMaxLength",
    };
    return (field >= 0 && field < 15) ? fieldNames[field] : nullptr;
}

int IIeee80211ModeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "legacyCwMin") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "legacyCwMax") == 0) return base+1;
    if (fieldName[0] == 'n' && strcmp(fieldName, "name") == 0) return base+2;
    if (fieldName[0] == 'p' && strcmp(fieldName, "preambleMode") == 0) return base+3;
    if (fieldName[0] == 'h' && strcmp(fieldName, "headerMode") == 0) return base+4;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dataMode") == 0) return base+5;
    if (fieldName[0] == 's' && strcmp(fieldName, "slotTime") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "sifsTime") == 0) return base+7;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rifsTime") == 0) return base+8;
    if (fieldName[0] == 'c' && strcmp(fieldName, "ccaTime") == 0) return base+9;
    if (fieldName[0] == 'p' && strcmp(fieldName, "phyRxStartDelay") == 0) return base+10;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rxTxTurnaroundTime") == 0) return base+11;
    if (fieldName[0] == 'p' && strcmp(fieldName, "preambleLength") == 0) return base+12;
    if (fieldName[0] == 'p' && strcmp(fieldName, "plcpHeaderLength") == 0) return base+13;
    if (fieldName[0] == 'm' && strcmp(fieldName, "mpduMaxLength") == 0) return base+14;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IIeee80211ModeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_legacyCwMin
        "int",    // FIELD_legacyCwMax
        "string",    // FIELD_name
        "inet::physicallayer::IIeee80211PreambleMode",    // FIELD_preambleMode
        "inet::physicallayer::IIeee80211HeaderMode",    // FIELD_headerMode
        "inet::physicallayer::IIeee80211DataMode",    // FIELD_dataMode
        "omnetpp::simtime_t",    // FIELD_slotTime
        "omnetpp::simtime_t",    // FIELD_sifsTime
        "omnetpp::simtime_t",    // FIELD_rifsTime
        "omnetpp::simtime_t",    // FIELD_ccaTime
        "omnetpp::simtime_t",    // FIELD_phyRxStartDelay
        "omnetpp::simtime_t",    // FIELD_rxTxTurnaroundTime
        "omnetpp::simtime_t",    // FIELD_preambleLength
        "omnetpp::simtime_t",    // FIELD_plcpHeaderLength
        "int",    // FIELD_mpduMaxLength
    };
    return (field >= 0 && field < 15) ? fieldTypeStrings[field] : nullptr;
}

const char **IIeee80211ModeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_preambleMode: {
            static const char *names[] = { "getter",  nullptr };
            return names;
        }
        case FIELD_headerMode: {
            static const char *names[] = { "getter",  nullptr };
            return names;
        }
        case FIELD_dataMode: {
            static const char *names[] = { "getter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *IIeee80211ModeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_preambleMode:
            if (!strcmp(propertyname, "getter")) return "_getPreambleMode";
            return nullptr;
        case FIELD_headerMode:
            if (!strcmp(propertyname, "getter")) return "_getHeaderMode";
            return nullptr;
        case FIELD_dataMode:
            if (!strcmp(propertyname, "getter")) return "_getDataMode";
            return nullptr;
        default: return nullptr;
    }
}

int IIeee80211ModeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Mode *pp = (IIeee80211Mode *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IIeee80211ModeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Mode *pp = (IIeee80211Mode *)object; (void)pp;
    switch (field) {
        case FIELD_preambleMode: { const IIeee80211PreambleMode * value = pp->_getPreambleMode(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_headerMode: { const IIeee80211HeaderMode * value = pp->_getHeaderMode(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_dataMode: { const IIeee80211DataMode * value = pp->_getDataMode(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string IIeee80211ModeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Mode *pp = (IIeee80211Mode *)object; (void)pp;
    switch (field) {
        case FIELD_legacyCwMin: return long2string(pp->getLegacyCwMin());
        case FIELD_legacyCwMax: return long2string(pp->getLegacyCwMax());
        case FIELD_name: return oppstring2string(pp->getName());
        case FIELD_preambleMode: {std::stringstream out; out << pp->_getPreambleMode(); return out.str();}
        case FIELD_headerMode: {std::stringstream out; out << pp->_getHeaderMode(); return out.str();}
        case FIELD_dataMode: {std::stringstream out; out << pp->_getDataMode(); return out.str();}
        case FIELD_slotTime: return simtime2string(pp->getSlotTime());
        case FIELD_sifsTime: return simtime2string(pp->getSifsTime());
        case FIELD_rifsTime: return simtime2string(pp->getRifsTime());
        case FIELD_ccaTime: return simtime2string(pp->getCcaTime());
        case FIELD_phyRxStartDelay: return simtime2string(pp->getPhyRxStartDelay());
        case FIELD_rxTxTurnaroundTime: return simtime2string(pp->getRxTxTurnaroundTime());
        case FIELD_preambleLength: return simtime2string(pp->getPreambleLength());
        case FIELD_plcpHeaderLength: return simtime2string(pp->getPlcpHeaderLength());
        case FIELD_mpduMaxLength: return long2string(pp->getMpduMaxLength());
        default: return "";
    }
}

bool IIeee80211ModeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Mode *pp = (IIeee80211Mode *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IIeee80211ModeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_preambleMode: return omnetpp::opp_typename(typeid(IIeee80211PreambleMode));
        case FIELD_headerMode: return omnetpp::opp_typename(typeid(IIeee80211HeaderMode));
        case FIELD_dataMode: return omnetpp::opp_typename(typeid(IIeee80211DataMode));
        default: return nullptr;
    };
}

void *IIeee80211ModeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Mode *pp = (IIeee80211Mode *)object; (void)pp;
    switch (field) {
        case FIELD_preambleMode: return toVoidPtr(pp->_getPreambleMode()); break;
        case FIELD_headerMode: return toVoidPtr(pp->_getHeaderMode()); break;
        case FIELD_dataMode: return toVoidPtr(pp->_getDataMode()); break;
        default: return nullptr;
    }
}

class Ieee80211ModeSetDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_slowestMode,
        FIELD_fastestMode,
        FIELD_slowestMandatoryMode,
        FIELD_fastestMandatoryMode,
        FIELD_sifsTime,
        FIELD_slotTime,
        FIELD_phyRxStartDelay,
        FIELD_cwMin,
        FIELD_cwMax,
    };
  public:
    Ieee80211ModeSetDescriptor();
    virtual ~Ieee80211ModeSetDescriptor();

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

Register_ClassDescriptor(Ieee80211ModeSetDescriptor)

Ieee80211ModeSetDescriptor::Ieee80211ModeSetDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211ModeSet)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ieee80211ModeSetDescriptor::~Ieee80211ModeSetDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ModeSetDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ModeSet *>(obj)!=nullptr;
}

const char **Ieee80211ModeSetDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ModeSetDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ModeSetDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ieee80211ModeSetDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_slowestMode
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_fastestMode
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_slowestMandatoryMode
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_fastestMandatoryMode
        0,    // FIELD_sifsTime
        0,    // FIELD_slotTime
        0,    // FIELD_phyRxStartDelay
        0,    // FIELD_cwMin
        0,    // FIELD_cwMax
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211ModeSetDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "slowestMode",
        "fastestMode",
        "slowestMandatoryMode",
        "fastestMandatoryMode",
        "sifsTime",
        "slotTime",
        "phyRxStartDelay",
        "cwMin",
        "cwMax",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int Ieee80211ModeSetDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "slowestMode") == 0) return base+0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fastestMode") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "slowestMandatoryMode") == 0) return base+2;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fastestMandatoryMode") == 0) return base+3;
    if (fieldName[0] == 's' && strcmp(fieldName, "sifsTime") == 0) return base+4;
    if (fieldName[0] == 's' && strcmp(fieldName, "slotTime") == 0) return base+5;
    if (fieldName[0] == 'p' && strcmp(fieldName, "phyRxStartDelay") == 0) return base+6;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cwMin") == 0) return base+7;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cwMax") == 0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ModeSetDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::physicallayer::IIeee80211Mode",    // FIELD_slowestMode
        "inet::physicallayer::IIeee80211Mode",    // FIELD_fastestMode
        "inet::physicallayer::IIeee80211Mode",    // FIELD_slowestMandatoryMode
        "inet::physicallayer::IIeee80211Mode",    // FIELD_fastestMandatoryMode
        "omnetpp::simtime_t",    // FIELD_sifsTime
        "omnetpp::simtime_t",    // FIELD_slotTime
        "omnetpp::simtime_t",    // FIELD_phyRxStartDelay
        "int",    // FIELD_cwMin
        "int",    // FIELD_cwMax
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ModeSetDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_slowestMode: {
            static const char *names[] = { "getter",  nullptr };
            return names;
        }
        case FIELD_fastestMode: {
            static const char *names[] = { "getter",  nullptr };
            return names;
        }
        case FIELD_slowestMandatoryMode: {
            static const char *names[] = { "getter",  nullptr };
            return names;
        }
        case FIELD_fastestMandatoryMode: {
            static const char *names[] = { "getter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211ModeSetDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_slowestMode:
            if (!strcmp(propertyname, "getter")) return "_getSlowestMode";
            return nullptr;
        case FIELD_fastestMode:
            if (!strcmp(propertyname, "getter")) return "_getFastestMode";
            return nullptr;
        case FIELD_slowestMandatoryMode:
            if (!strcmp(propertyname, "getter")) return "_getSlowestMandatoryMode";
            return nullptr;
        case FIELD_fastestMandatoryMode:
            if (!strcmp(propertyname, "getter")) return "_getFastestMandatoryMode";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211ModeSetDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ModeSet *pp = (Ieee80211ModeSet *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ModeSetDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ModeSet *pp = (Ieee80211ModeSet *)object; (void)pp;
    switch (field) {
        case FIELD_slowestMode: { const IIeee80211Mode * value = pp->_getSlowestMode(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_fastestMode: { const IIeee80211Mode * value = pp->_getFastestMode(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_slowestMandatoryMode: { const IIeee80211Mode * value = pp->_getSlowestMandatoryMode(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_fastestMandatoryMode: { const IIeee80211Mode * value = pp->_getFastestMandatoryMode(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string Ieee80211ModeSetDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ModeSet *pp = (Ieee80211ModeSet *)object; (void)pp;
    switch (field) {
        case FIELD_slowestMode: {std::stringstream out; out << pp->_getSlowestMode(); return out.str();}
        case FIELD_fastestMode: {std::stringstream out; out << pp->_getFastestMode(); return out.str();}
        case FIELD_slowestMandatoryMode: {std::stringstream out; out << pp->_getSlowestMandatoryMode(); return out.str();}
        case FIELD_fastestMandatoryMode: {std::stringstream out; out << pp->_getFastestMandatoryMode(); return out.str();}
        case FIELD_sifsTime: return simtime2string(pp->getSifsTime());
        case FIELD_slotTime: return simtime2string(pp->getSlotTime());
        case FIELD_phyRxStartDelay: return simtime2string(pp->getPhyRxStartDelay());
        case FIELD_cwMin: return long2string(pp->getCwMin());
        case FIELD_cwMax: return long2string(pp->getCwMax());
        default: return "";
    }
}

bool Ieee80211ModeSetDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ModeSet *pp = (Ieee80211ModeSet *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ModeSetDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_slowestMode: return omnetpp::opp_typename(typeid(IIeee80211Mode));
        case FIELD_fastestMode: return omnetpp::opp_typename(typeid(IIeee80211Mode));
        case FIELD_slowestMandatoryMode: return omnetpp::opp_typename(typeid(IIeee80211Mode));
        case FIELD_fastestMandatoryMode: return omnetpp::opp_typename(typeid(IIeee80211Mode));
        default: return nullptr;
    };
}

void *Ieee80211ModeSetDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ModeSet *pp = (Ieee80211ModeSet *)object; (void)pp;
    switch (field) {
        case FIELD_slowestMode: return toVoidPtr(pp->_getSlowestMode()); break;
        case FIELD_fastestMode: return toVoidPtr(pp->_getFastestMode()); break;
        case FIELD_slowestMandatoryMode: return toVoidPtr(pp->_getSlowestMandatoryMode()); break;
        case FIELD_fastestMandatoryMode: return toVoidPtr(pp->_getFastestMandatoryMode()); break;
        default: return nullptr;
    }
}

class Ieee80211OfdmModulationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_subcarrierModulation,
    };
  public:
    Ieee80211OfdmModulationDescriptor();
    virtual ~Ieee80211OfdmModulationDescriptor();

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

Register_ClassDescriptor(Ieee80211OfdmModulationDescriptor)

Ieee80211OfdmModulationDescriptor::Ieee80211OfdmModulationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211OfdmModulation)), "inet::physicallayer::IModulation")
{
    propertynames = nullptr;
}

Ieee80211OfdmModulationDescriptor::~Ieee80211OfdmModulationDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211OfdmModulationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211OfdmModulation *>(obj)!=nullptr;
}

const char **Ieee80211OfdmModulationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211OfdmModulationDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211OfdmModulationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211OfdmModulationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER,    // FIELD_subcarrierModulation
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211OfdmModulationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "subcarrierModulation",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ieee80211OfdmModulationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "subcarrierModulation") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211OfdmModulationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::physicallayer::IModulation",    // FIELD_subcarrierModulation
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211OfdmModulationDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211OfdmModulationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211OfdmModulationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmModulation *pp = (Ieee80211OfdmModulation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211OfdmModulationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmModulation *pp = (Ieee80211OfdmModulation *)object; (void)pp;
    switch (field) {
        case FIELD_subcarrierModulation: { const IModulation * value = pp->getSubcarrierModulation(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string Ieee80211OfdmModulationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmModulation *pp = (Ieee80211OfdmModulation *)object; (void)pp;
    switch (field) {
        case FIELD_subcarrierModulation: {std::stringstream out; out << pp->getSubcarrierModulation(); return out.str();}
        default: return "";
    }
}

bool Ieee80211OfdmModulationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmModulation *pp = (Ieee80211OfdmModulation *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211OfdmModulationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_subcarrierModulation: return omnetpp::opp_typename(typeid(IModulation));
        default: return nullptr;
    };
}

void *Ieee80211OfdmModulationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmModulation *pp = (Ieee80211OfdmModulation *)object; (void)pp;
    switch (field) {
        case FIELD_subcarrierModulation: return toVoidPtr(pp->getSubcarrierModulation()); break;
        default: return nullptr;
    }
}

} // namespace physicallayer
} // namespace inet

