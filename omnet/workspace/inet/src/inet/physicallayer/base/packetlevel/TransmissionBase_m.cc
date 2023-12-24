//
// Generated file, do not edit! Created by nedtool 5.6 from inet/physicallayer/base/packetlevel/TransmissionBase.msg.
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
#include "TransmissionBase_m.h"

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

class TransmissionBaseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_id,
        FIELD_startTime,
        FIELD_startPosition,
        FIELD_startOrientation,
        FIELD_endTime,
        FIELD_endPosition,
        FIELD_endOrientation,
        FIELD_duration,
        FIELD_preambleDuration,
        FIELD_headerDuration,
        FIELD_dataDuration,
    };
  public:
    TransmissionBaseDescriptor();
    virtual ~TransmissionBaseDescriptor();

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

Register_ClassDescriptor(TransmissionBaseDescriptor)

TransmissionBaseDescriptor::TransmissionBaseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::TransmissionBase)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

TransmissionBaseDescriptor::~TransmissionBaseDescriptor()
{
    delete[] propertynames;
}

bool TransmissionBaseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TransmissionBase *>(obj)!=nullptr;
}

const char **TransmissionBaseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TransmissionBaseDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TransmissionBaseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount() : 11;
}

unsigned int TransmissionBaseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_id
        0,    // FIELD_startTime
        FD_ISCOMPOUND,    // FIELD_startPosition
        FD_ISCOMPOUND,    // FIELD_startOrientation
        0,    // FIELD_endTime
        FD_ISCOMPOUND,    // FIELD_endPosition
        FD_ISCOMPOUND,    // FIELD_endOrientation
        0,    // FIELD_duration
        0,    // FIELD_preambleDuration
        0,    // FIELD_headerDuration
        0,    // FIELD_dataDuration
    };
    return (field >= 0 && field < 11) ? fieldTypeFlags[field] : 0;
}

const char *TransmissionBaseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "id",
        "startTime",
        "startPosition",
        "startOrientation",
        "endTime",
        "endPosition",
        "endOrientation",
        "duration",
        "preambleDuration",
        "headerDuration",
        "dataDuration",
    };
    return (field >= 0 && field < 11) ? fieldNames[field] : nullptr;
}

int TransmissionBaseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "id") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "startTime") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "startPosition") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "startOrientation") == 0) return base+3;
    if (fieldName[0] == 'e' && strcmp(fieldName, "endTime") == 0) return base+4;
    if (fieldName[0] == 'e' && strcmp(fieldName, "endPosition") == 0) return base+5;
    if (fieldName[0] == 'e' && strcmp(fieldName, "endOrientation") == 0) return base+6;
    if (fieldName[0] == 'd' && strcmp(fieldName, "duration") == 0) return base+7;
    if (fieldName[0] == 'p' && strcmp(fieldName, "preambleDuration") == 0) return base+8;
    if (fieldName[0] == 'h' && strcmp(fieldName, "headerDuration") == 0) return base+9;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dataDuration") == 0) return base+10;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TransmissionBaseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_id
        "omnetpp::simtime_t",    // FIELD_startTime
        "inet::Coord",    // FIELD_startPosition
        "inet::Quaternion",    // FIELD_startOrientation
        "omnetpp::simtime_t",    // FIELD_endTime
        "inet::Coord",    // FIELD_endPosition
        "inet::Quaternion",    // FIELD_endOrientation
        "omnetpp::simtime_t",    // FIELD_duration
        "omnetpp::simtime_t",    // FIELD_preambleDuration
        "omnetpp::simtime_t",    // FIELD_headerDuration
        "omnetpp::simtime_t",    // FIELD_dataDuration
    };
    return (field >= 0 && field < 11) ? fieldTypeStrings[field] : nullptr;
}

const char **TransmissionBaseDescriptor::getFieldPropertyNames(int field) const
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

const char *TransmissionBaseDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TransmissionBaseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TransmissionBase *pp = (TransmissionBase *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TransmissionBaseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TransmissionBase *pp = (TransmissionBase *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TransmissionBaseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TransmissionBase *pp = (TransmissionBase *)object; (void)pp;
    switch (field) {
        case FIELD_id: return long2string(pp->getId());
        case FIELD_startTime: return simtime2string(pp->getStartTime());
        case FIELD_startPosition: {std::stringstream out; out << pp->getStartPosition(); return out.str();}
        case FIELD_startOrientation: {std::stringstream out; out << pp->getStartOrientation(); return out.str();}
        case FIELD_endTime: return simtime2string(pp->getEndTime());
        case FIELD_endPosition: {std::stringstream out; out << pp->getEndPosition(); return out.str();}
        case FIELD_endOrientation: {std::stringstream out; out << pp->getEndOrientation(); return out.str();}
        case FIELD_duration: return simtime2string(pp->getDuration());
        case FIELD_preambleDuration: return simtime2string(pp->getPreambleDuration());
        case FIELD_headerDuration: return simtime2string(pp->getHeaderDuration());
        case FIELD_dataDuration: return simtime2string(pp->getDataDuration());
        default: return "";
    }
}

bool TransmissionBaseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TransmissionBase *pp = (TransmissionBase *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TransmissionBaseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_startPosition: return omnetpp::opp_typename(typeid(Coord));
        case FIELD_startOrientation: return omnetpp::opp_typename(typeid(Quaternion));
        case FIELD_endPosition: return omnetpp::opp_typename(typeid(Coord));
        case FIELD_endOrientation: return omnetpp::opp_typename(typeid(Quaternion));
        default: return nullptr;
    };
}

void *TransmissionBaseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TransmissionBase *pp = (TransmissionBase *)object; (void)pp;
    switch (field) {
        case FIELD_startPosition: return toVoidPtr(&pp->getStartPosition()); break;
        case FIELD_startOrientation: return toVoidPtr(&pp->getStartOrientation()); break;
        case FIELD_endPosition: return toVoidPtr(&pp->getEndPosition()); break;
        case FIELD_endOrientation: return toVoidPtr(&pp->getEndOrientation()); break;
        default: return nullptr;
    }
}

} // namespace physicallayer
} // namespace inet

