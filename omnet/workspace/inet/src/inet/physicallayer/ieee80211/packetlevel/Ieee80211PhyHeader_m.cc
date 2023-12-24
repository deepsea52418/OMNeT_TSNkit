//
// Generated file, do not edit! Created by nedtool 5.6 from inet/physicallayer/ieee80211/packetlevel/Ieee80211PhyHeader.msg.
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
#include "Ieee80211PhyHeader_m.h"

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

Register_Class(Ieee80211PhyPreamble)

Ieee80211PhyPreamble::Ieee80211PhyPreamble() : ::inet::FieldsChunk()
{
}

Ieee80211PhyPreamble::Ieee80211PhyPreamble(const Ieee80211PhyPreamble& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ieee80211PhyPreamble::~Ieee80211PhyPreamble()
{
}

Ieee80211PhyPreamble& Ieee80211PhyPreamble::operator=(const Ieee80211PhyPreamble& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211PhyPreamble::copy(const Ieee80211PhyPreamble& other)
{
}

void Ieee80211PhyPreamble::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
}

void Ieee80211PhyPreamble::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
}

class Ieee80211PhyPreambleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211PhyPreambleDescriptor();
    virtual ~Ieee80211PhyPreambleDescriptor();

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

Register_ClassDescriptor(Ieee80211PhyPreambleDescriptor)

Ieee80211PhyPreambleDescriptor::Ieee80211PhyPreambleDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211PhyPreamble)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ieee80211PhyPreambleDescriptor::~Ieee80211PhyPreambleDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211PhyPreambleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211PhyPreamble *>(obj)!=nullptr;
}

const char **Ieee80211PhyPreambleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211PhyPreambleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211PhyPreambleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211PhyPreambleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211PhyPreambleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211PhyPreambleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211PhyPreambleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211PhyPreambleDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211PhyPreambleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211PhyPreambleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211PhyPreamble *pp = (Ieee80211PhyPreamble *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211PhyPreambleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211PhyPreamble *pp = (Ieee80211PhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211PhyPreambleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211PhyPreamble *pp = (Ieee80211PhyPreamble *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211PhyPreambleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211PhyPreamble *pp = (Ieee80211PhyPreamble *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211PhyPreambleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211PhyPreambleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211PhyPreamble *pp = (Ieee80211PhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211PhyHeader)

Ieee80211PhyHeader::Ieee80211PhyHeader() : ::inet::FieldsChunk()
{
}

Ieee80211PhyHeader::Ieee80211PhyHeader(const Ieee80211PhyHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ieee80211PhyHeader::~Ieee80211PhyHeader()
{
}

Ieee80211PhyHeader& Ieee80211PhyHeader::operator=(const Ieee80211PhyHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211PhyHeader::copy(const Ieee80211PhyHeader& other)
{
    this->lengthField = other.lengthField;
}

void Ieee80211PhyHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->lengthField);
}

void Ieee80211PhyHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->lengthField);
}

B Ieee80211PhyHeader::getLengthField() const
{
    return this->lengthField;
}

void Ieee80211PhyHeader::setLengthField(B lengthField)
{
    handleChange();
    this->lengthField = lengthField;
}

class Ieee80211PhyHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_lengthField,
    };
  public:
    Ieee80211PhyHeaderDescriptor();
    virtual ~Ieee80211PhyHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211PhyHeaderDescriptor)

Ieee80211PhyHeaderDescriptor::Ieee80211PhyHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211PhyHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ieee80211PhyHeaderDescriptor::~Ieee80211PhyHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211PhyHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211PhyHeader *>(obj)!=nullptr;
}

const char **Ieee80211PhyHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211PhyHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211PhyHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211PhyHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_lengthField
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211PhyHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lengthField",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ieee80211PhyHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lengthField") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211PhyHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::B",    // FIELD_lengthField
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211PhyHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211PhyHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211PhyHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211PhyHeader *pp = (Ieee80211PhyHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211PhyHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211PhyHeader *pp = (Ieee80211PhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211PhyHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211PhyHeader *pp = (Ieee80211PhyHeader *)object; (void)pp;
    switch (field) {
        case FIELD_lengthField: return unit2string(pp->getLengthField());
        default: return "";
    }
}

bool Ieee80211PhyHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211PhyHeader *pp = (Ieee80211PhyHeader *)object; (void)pp;
    switch (field) {
        case FIELD_lengthField: pp->setLengthField(B(string2long(value))); return true;
        default: return false;
    }
}

const char *Ieee80211PhyHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee80211PhyHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211PhyHeader *pp = (Ieee80211PhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211FhssPhyPreamble)

Ieee80211FhssPhyPreamble::Ieee80211FhssPhyPreamble() : ::inet::physicallayer::Ieee80211PhyPreamble()
{
    this->setChunkLength(b(96));
}

Ieee80211FhssPhyPreamble::Ieee80211FhssPhyPreamble(const Ieee80211FhssPhyPreamble& other) : ::inet::physicallayer::Ieee80211PhyPreamble(other)
{
    copy(other);
}

Ieee80211FhssPhyPreamble::~Ieee80211FhssPhyPreamble()
{
}

Ieee80211FhssPhyPreamble& Ieee80211FhssPhyPreamble::operator=(const Ieee80211FhssPhyPreamble& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211PhyPreamble::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211FhssPhyPreamble::copy(const Ieee80211FhssPhyPreamble& other)
{
}

void Ieee80211FhssPhyPreamble::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211PhyPreamble::parsimPack(b);
}

void Ieee80211FhssPhyPreamble::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211PhyPreamble::parsimUnpack(b);
}

class Ieee80211FhssPhyPreambleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211FhssPhyPreambleDescriptor();
    virtual ~Ieee80211FhssPhyPreambleDescriptor();

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

Register_ClassDescriptor(Ieee80211FhssPhyPreambleDescriptor)

Ieee80211FhssPhyPreambleDescriptor::Ieee80211FhssPhyPreambleDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211FhssPhyPreamble)), "inet::physicallayer::Ieee80211PhyPreamble")
{
    propertynames = nullptr;
}

Ieee80211FhssPhyPreambleDescriptor::~Ieee80211FhssPhyPreambleDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211FhssPhyPreambleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211FhssPhyPreamble *>(obj)!=nullptr;
}

const char **Ieee80211FhssPhyPreambleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211FhssPhyPreambleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211FhssPhyPreambleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211FhssPhyPreambleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211FhssPhyPreambleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211FhssPhyPreambleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211FhssPhyPreambleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211FhssPhyPreambleDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211FhssPhyPreambleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211FhssPhyPreambleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FhssPhyPreamble *pp = (Ieee80211FhssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211FhssPhyPreambleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FhssPhyPreamble *pp = (Ieee80211FhssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211FhssPhyPreambleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FhssPhyPreamble *pp = (Ieee80211FhssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211FhssPhyPreambleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FhssPhyPreamble *pp = (Ieee80211FhssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211FhssPhyPreambleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211FhssPhyPreambleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FhssPhyPreamble *pp = (Ieee80211FhssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211FhssPhyHeader)

Ieee80211FhssPhyHeader::Ieee80211FhssPhyHeader() : ::inet::physicallayer::Ieee80211PhyHeader()
{
    this->setChunkLength(b(32));

}

Ieee80211FhssPhyHeader::Ieee80211FhssPhyHeader(const Ieee80211FhssPhyHeader& other) : ::inet::physicallayer::Ieee80211PhyHeader(other)
{
    copy(other);
}

Ieee80211FhssPhyHeader::~Ieee80211FhssPhyHeader()
{
}

Ieee80211FhssPhyHeader& Ieee80211FhssPhyHeader::operator=(const Ieee80211FhssPhyHeader& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211PhyHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211FhssPhyHeader::copy(const Ieee80211FhssPhyHeader& other)
{
    this->plw = other.plw;
    this->psf = other.psf;
    this->crc = other.crc;
    this->crcMode = other.crcMode;
}

void Ieee80211FhssPhyHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211PhyHeader::parsimPack(b);
    doParsimPacking(b,this->plw);
    doParsimPacking(b,this->psf);
    doParsimPacking(b,this->crc);
    doParsimPacking(b,this->crcMode);
}

void Ieee80211FhssPhyHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211PhyHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->plw);
    doParsimUnpacking(b,this->psf);
    doParsimUnpacking(b,this->crc);
    doParsimUnpacking(b,this->crcMode);
}

uint16_t Ieee80211FhssPhyHeader::getPlw() const
{
    return this->plw;
}

void Ieee80211FhssPhyHeader::setPlw(uint16_t plw)
{
    handleChange();
    this->plw = plw;
}

uint8_t Ieee80211FhssPhyHeader::getPsf() const
{
    return this->psf;
}

void Ieee80211FhssPhyHeader::setPsf(uint8_t psf)
{
    handleChange();
    this->psf = psf;
}

uint16_t Ieee80211FhssPhyHeader::getCrc() const
{
    return this->crc;
}

void Ieee80211FhssPhyHeader::setCrc(uint16_t crc)
{
    handleChange();
    this->crc = crc;
}

inet::CrcMode Ieee80211FhssPhyHeader::getCrcMode() const
{
    return this->crcMode;
}

void Ieee80211FhssPhyHeader::setCrcMode(inet::CrcMode crcMode)
{
    handleChange();
    this->crcMode = crcMode;
}

class Ieee80211FhssPhyHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_plw,
        FIELD_psf,
        FIELD_crc,
        FIELD_crcMode,
    };
  public:
    Ieee80211FhssPhyHeaderDescriptor();
    virtual ~Ieee80211FhssPhyHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211FhssPhyHeaderDescriptor)

Ieee80211FhssPhyHeaderDescriptor::Ieee80211FhssPhyHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211FhssPhyHeader)), "inet::physicallayer::Ieee80211PhyHeader")
{
    propertynames = nullptr;
}

Ieee80211FhssPhyHeaderDescriptor::~Ieee80211FhssPhyHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211FhssPhyHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211FhssPhyHeader *>(obj)!=nullptr;
}

const char **Ieee80211FhssPhyHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211FhssPhyHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211FhssPhyHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211FhssPhyHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_plw
        FD_ISEDITABLE,    // FIELD_psf
        FD_ISEDITABLE,    // FIELD_crc
        0,    // FIELD_crcMode
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211FhssPhyHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "plw",
        "psf",
        "crc",
        "crcMode",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Ieee80211FhssPhyHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "plw") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "psf") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crc") == 0) return base+2;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crcMode") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211FhssPhyHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_plw
        "uint8_t",    // FIELD_psf
        "uint16_t",    // FIELD_crc
        "inet::CrcMode",    // FIELD_crcMode
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211FhssPhyHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211FhssPhyHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211FhssPhyHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FhssPhyHeader *pp = (Ieee80211FhssPhyHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211FhssPhyHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FhssPhyHeader *pp = (Ieee80211FhssPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211FhssPhyHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FhssPhyHeader *pp = (Ieee80211FhssPhyHeader *)object; (void)pp;
    switch (field) {
        case FIELD_plw: return ulong2string(pp->getPlw());
        case FIELD_psf: return ulong2string(pp->getPsf());
        case FIELD_crc: return ulong2string(pp->getCrc());
        case FIELD_crcMode: return enum2string(pp->getCrcMode(), "inet::CrcMode");
        default: return "";
    }
}

bool Ieee80211FhssPhyHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FhssPhyHeader *pp = (Ieee80211FhssPhyHeader *)object; (void)pp;
    switch (field) {
        case FIELD_plw: pp->setPlw(string2ulong(value)); return true;
        case FIELD_psf: pp->setPsf(string2ulong(value)); return true;
        case FIELD_crc: pp->setCrc(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ieee80211FhssPhyHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee80211FhssPhyHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FhssPhyHeader *pp = (Ieee80211FhssPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211IrPhyPreamble)

Ieee80211IrPhyPreamble::Ieee80211IrPhyPreamble() : ::inet::physicallayer::Ieee80211PhyPreamble()
{
}

Ieee80211IrPhyPreamble::Ieee80211IrPhyPreamble(const Ieee80211IrPhyPreamble& other) : ::inet::physicallayer::Ieee80211PhyPreamble(other)
{
    copy(other);
}

Ieee80211IrPhyPreamble::~Ieee80211IrPhyPreamble()
{
}

Ieee80211IrPhyPreamble& Ieee80211IrPhyPreamble::operator=(const Ieee80211IrPhyPreamble& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211PhyPreamble::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211IrPhyPreamble::copy(const Ieee80211IrPhyPreamble& other)
{
}

void Ieee80211IrPhyPreamble::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211PhyPreamble::parsimPack(b);
}

void Ieee80211IrPhyPreamble::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211PhyPreamble::parsimUnpack(b);
}

class Ieee80211IrPhyPreambleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211IrPhyPreambleDescriptor();
    virtual ~Ieee80211IrPhyPreambleDescriptor();

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

Register_ClassDescriptor(Ieee80211IrPhyPreambleDescriptor)

Ieee80211IrPhyPreambleDescriptor::Ieee80211IrPhyPreambleDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211IrPhyPreamble)), "inet::physicallayer::Ieee80211PhyPreamble")
{
    propertynames = nullptr;
}

Ieee80211IrPhyPreambleDescriptor::~Ieee80211IrPhyPreambleDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211IrPhyPreambleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211IrPhyPreamble *>(obj)!=nullptr;
}

const char **Ieee80211IrPhyPreambleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211IrPhyPreambleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211IrPhyPreambleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211IrPhyPreambleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211IrPhyPreambleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211IrPhyPreambleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211IrPhyPreambleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211IrPhyPreambleDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211IrPhyPreambleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211IrPhyPreambleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211IrPhyPreamble *pp = (Ieee80211IrPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211IrPhyPreambleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211IrPhyPreamble *pp = (Ieee80211IrPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211IrPhyPreambleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211IrPhyPreamble *pp = (Ieee80211IrPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211IrPhyPreambleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211IrPhyPreamble *pp = (Ieee80211IrPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211IrPhyPreambleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211IrPhyPreambleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211IrPhyPreamble *pp = (Ieee80211IrPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211IrPhyHeader)

Ieee80211IrPhyHeader::Ieee80211IrPhyHeader() : ::inet::physicallayer::Ieee80211PhyHeader()
{
}

Ieee80211IrPhyHeader::Ieee80211IrPhyHeader(const Ieee80211IrPhyHeader& other) : ::inet::physicallayer::Ieee80211PhyHeader(other)
{
    copy(other);
}

Ieee80211IrPhyHeader::~Ieee80211IrPhyHeader()
{
}

Ieee80211IrPhyHeader& Ieee80211IrPhyHeader::operator=(const Ieee80211IrPhyHeader& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211PhyHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211IrPhyHeader::copy(const Ieee80211IrPhyHeader& other)
{
    this->crc = other.crc;
    this->crcMode = other.crcMode;
}

void Ieee80211IrPhyHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211PhyHeader::parsimPack(b);
    doParsimPacking(b,this->crc);
    doParsimPacking(b,this->crcMode);
}

void Ieee80211IrPhyHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211PhyHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->crc);
    doParsimUnpacking(b,this->crcMode);
}

uint16_t Ieee80211IrPhyHeader::getCrc() const
{
    return this->crc;
}

void Ieee80211IrPhyHeader::setCrc(uint16_t crc)
{
    handleChange();
    this->crc = crc;
}

inet::CrcMode Ieee80211IrPhyHeader::getCrcMode() const
{
    return this->crcMode;
}

void Ieee80211IrPhyHeader::setCrcMode(inet::CrcMode crcMode)
{
    handleChange();
    this->crcMode = crcMode;
}

class Ieee80211IrPhyHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_crc,
        FIELD_crcMode,
    };
  public:
    Ieee80211IrPhyHeaderDescriptor();
    virtual ~Ieee80211IrPhyHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211IrPhyHeaderDescriptor)

Ieee80211IrPhyHeaderDescriptor::Ieee80211IrPhyHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211IrPhyHeader)), "inet::physicallayer::Ieee80211PhyHeader")
{
    propertynames = nullptr;
}

Ieee80211IrPhyHeaderDescriptor::~Ieee80211IrPhyHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211IrPhyHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211IrPhyHeader *>(obj)!=nullptr;
}

const char **Ieee80211IrPhyHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211IrPhyHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211IrPhyHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ieee80211IrPhyHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_crc
        0,    // FIELD_crcMode
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211IrPhyHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "crc",
        "crcMode",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ieee80211IrPhyHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crc") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crcMode") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211IrPhyHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_crc
        "inet::CrcMode",    // FIELD_crcMode
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211IrPhyHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211IrPhyHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211IrPhyHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211IrPhyHeader *pp = (Ieee80211IrPhyHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211IrPhyHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211IrPhyHeader *pp = (Ieee80211IrPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211IrPhyHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211IrPhyHeader *pp = (Ieee80211IrPhyHeader *)object; (void)pp;
    switch (field) {
        case FIELD_crc: return ulong2string(pp->getCrc());
        case FIELD_crcMode: return enum2string(pp->getCrcMode(), "inet::CrcMode");
        default: return "";
    }
}

bool Ieee80211IrPhyHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211IrPhyHeader *pp = (Ieee80211IrPhyHeader *)object; (void)pp;
    switch (field) {
        case FIELD_crc: pp->setCrc(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ieee80211IrPhyHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee80211IrPhyHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211IrPhyHeader *pp = (Ieee80211IrPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211DsssPhyPreamble)

Ieee80211DsssPhyPreamble::Ieee80211DsssPhyPreamble() : ::inet::physicallayer::Ieee80211PhyPreamble()
{
    this->setChunkLength(b(144));
}

Ieee80211DsssPhyPreamble::Ieee80211DsssPhyPreamble(const Ieee80211DsssPhyPreamble& other) : ::inet::physicallayer::Ieee80211PhyPreamble(other)
{
    copy(other);
}

Ieee80211DsssPhyPreamble::~Ieee80211DsssPhyPreamble()
{
}

Ieee80211DsssPhyPreamble& Ieee80211DsssPhyPreamble::operator=(const Ieee80211DsssPhyPreamble& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211PhyPreamble::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DsssPhyPreamble::copy(const Ieee80211DsssPhyPreamble& other)
{
}

void Ieee80211DsssPhyPreamble::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211PhyPreamble::parsimPack(b);
}

void Ieee80211DsssPhyPreamble::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211PhyPreamble::parsimUnpack(b);
}

class Ieee80211DsssPhyPreambleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211DsssPhyPreambleDescriptor();
    virtual ~Ieee80211DsssPhyPreambleDescriptor();

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

Register_ClassDescriptor(Ieee80211DsssPhyPreambleDescriptor)

Ieee80211DsssPhyPreambleDescriptor::Ieee80211DsssPhyPreambleDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211DsssPhyPreamble)), "inet::physicallayer::Ieee80211PhyPreamble")
{
    propertynames = nullptr;
}

Ieee80211DsssPhyPreambleDescriptor::~Ieee80211DsssPhyPreambleDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DsssPhyPreambleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DsssPhyPreamble *>(obj)!=nullptr;
}

const char **Ieee80211DsssPhyPreambleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DsssPhyPreambleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DsssPhyPreambleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211DsssPhyPreambleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211DsssPhyPreambleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211DsssPhyPreambleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DsssPhyPreambleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211DsssPhyPreambleDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211DsssPhyPreambleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211DsssPhyPreambleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DsssPhyPreamble *pp = (Ieee80211DsssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DsssPhyPreambleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DsssPhyPreamble *pp = (Ieee80211DsssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DsssPhyPreambleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DsssPhyPreamble *pp = (Ieee80211DsssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211DsssPhyPreambleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DsssPhyPreamble *pp = (Ieee80211DsssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211DsssPhyPreambleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211DsssPhyPreambleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DsssPhyPreamble *pp = (Ieee80211DsssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211DsssPhyHeader)

Ieee80211DsssPhyHeader::Ieee80211DsssPhyHeader() : ::inet::physicallayer::Ieee80211PhyHeader()
{
}

Ieee80211DsssPhyHeader::Ieee80211DsssPhyHeader(const Ieee80211DsssPhyHeader& other) : ::inet::physicallayer::Ieee80211PhyHeader(other)
{
    copy(other);
}

Ieee80211DsssPhyHeader::~Ieee80211DsssPhyHeader()
{
}

Ieee80211DsssPhyHeader& Ieee80211DsssPhyHeader::operator=(const Ieee80211DsssPhyHeader& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211PhyHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DsssPhyHeader::copy(const Ieee80211DsssPhyHeader& other)
{
    this->signal = other.signal;
    this->service = other.service;
    this->crc = other.crc;
    this->crcMode = other.crcMode;
}

void Ieee80211DsssPhyHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211PhyHeader::parsimPack(b);
    doParsimPacking(b,this->signal);
    doParsimPacking(b,this->service);
    doParsimPacking(b,this->crc);
    doParsimPacking(b,this->crcMode);
}

void Ieee80211DsssPhyHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211PhyHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->signal);
    doParsimUnpacking(b,this->service);
    doParsimUnpacking(b,this->crc);
    doParsimUnpacking(b,this->crcMode);
}

uint8_t Ieee80211DsssPhyHeader::getSignal() const
{
    return this->signal;
}

void Ieee80211DsssPhyHeader::setSignal(uint8_t signal)
{
    handleChange();
    this->signal = signal;
}

uint8_t Ieee80211DsssPhyHeader::getService() const
{
    return this->service;
}

void Ieee80211DsssPhyHeader::setService(uint8_t service)
{
    handleChange();
    this->service = service;
}

uint16_t Ieee80211DsssPhyHeader::getCrc() const
{
    return this->crc;
}

void Ieee80211DsssPhyHeader::setCrc(uint16_t crc)
{
    handleChange();
    this->crc = crc;
}

inet::CrcMode Ieee80211DsssPhyHeader::getCrcMode() const
{
    return this->crcMode;
}

void Ieee80211DsssPhyHeader::setCrcMode(inet::CrcMode crcMode)
{
    handleChange();
    this->crcMode = crcMode;
}

class Ieee80211DsssPhyHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_signal,
        FIELD_service,
        FIELD_crc,
        FIELD_crcMode,
    };
  public:
    Ieee80211DsssPhyHeaderDescriptor();
    virtual ~Ieee80211DsssPhyHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211DsssPhyHeaderDescriptor)

Ieee80211DsssPhyHeaderDescriptor::Ieee80211DsssPhyHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211DsssPhyHeader)), "inet::physicallayer::Ieee80211PhyHeader")
{
    propertynames = nullptr;
}

Ieee80211DsssPhyHeaderDescriptor::~Ieee80211DsssPhyHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DsssPhyHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DsssPhyHeader *>(obj)!=nullptr;
}

const char **Ieee80211DsssPhyHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DsssPhyHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DsssPhyHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211DsssPhyHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_signal
        FD_ISEDITABLE,    // FIELD_service
        FD_ISEDITABLE,    // FIELD_crc
        0,    // FIELD_crcMode
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211DsssPhyHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "signal",
        "service",
        "crc",
        "crcMode",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Ieee80211DsssPhyHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "signal") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "service") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crc") == 0) return base+2;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crcMode") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DsssPhyHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_signal
        "uint8_t",    // FIELD_service
        "uint16_t",    // FIELD_crc
        "inet::CrcMode",    // FIELD_crcMode
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DsssPhyHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211DsssPhyHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211DsssPhyHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DsssPhyHeader *pp = (Ieee80211DsssPhyHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DsssPhyHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DsssPhyHeader *pp = (Ieee80211DsssPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DsssPhyHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DsssPhyHeader *pp = (Ieee80211DsssPhyHeader *)object; (void)pp;
    switch (field) {
        case FIELD_signal: return ulong2string(pp->getSignal());
        case FIELD_service: return ulong2string(pp->getService());
        case FIELD_crc: return ulong2string(pp->getCrc());
        case FIELD_crcMode: return enum2string(pp->getCrcMode(), "inet::CrcMode");
        default: return "";
    }
}

bool Ieee80211DsssPhyHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DsssPhyHeader *pp = (Ieee80211DsssPhyHeader *)object; (void)pp;
    switch (field) {
        case FIELD_signal: pp->setSignal(string2ulong(value)); return true;
        case FIELD_service: pp->setService(string2ulong(value)); return true;
        case FIELD_crc: pp->setCrc(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ieee80211DsssPhyHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee80211DsssPhyHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DsssPhyHeader *pp = (Ieee80211DsssPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211HrDsssPhyPreamble)

Ieee80211HrDsssPhyPreamble::Ieee80211HrDsssPhyPreamble() : ::inet::physicallayer::Ieee80211DsssPhyPreamble()
{
}

Ieee80211HrDsssPhyPreamble::Ieee80211HrDsssPhyPreamble(const Ieee80211HrDsssPhyPreamble& other) : ::inet::physicallayer::Ieee80211DsssPhyPreamble(other)
{
    copy(other);
}

Ieee80211HrDsssPhyPreamble::~Ieee80211HrDsssPhyPreamble()
{
}

Ieee80211HrDsssPhyPreamble& Ieee80211HrDsssPhyPreamble::operator=(const Ieee80211HrDsssPhyPreamble& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211DsssPhyPreamble::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211HrDsssPhyPreamble::copy(const Ieee80211HrDsssPhyPreamble& other)
{
}

void Ieee80211HrDsssPhyPreamble::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211DsssPhyPreamble::parsimPack(b);
}

void Ieee80211HrDsssPhyPreamble::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211DsssPhyPreamble::parsimUnpack(b);
}

class Ieee80211HrDsssPhyPreambleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211HrDsssPhyPreambleDescriptor();
    virtual ~Ieee80211HrDsssPhyPreambleDescriptor();

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

Register_ClassDescriptor(Ieee80211HrDsssPhyPreambleDescriptor)

Ieee80211HrDsssPhyPreambleDescriptor::Ieee80211HrDsssPhyPreambleDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211HrDsssPhyPreamble)), "inet::physicallayer::Ieee80211DsssPhyPreamble")
{
    propertynames = nullptr;
}

Ieee80211HrDsssPhyPreambleDescriptor::~Ieee80211HrDsssPhyPreambleDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211HrDsssPhyPreambleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211HrDsssPhyPreamble *>(obj)!=nullptr;
}

const char **Ieee80211HrDsssPhyPreambleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211HrDsssPhyPreambleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211HrDsssPhyPreambleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211HrDsssPhyPreambleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211HrDsssPhyPreambleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211HrDsssPhyPreambleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211HrDsssPhyPreambleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211HrDsssPhyPreambleDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211HrDsssPhyPreambleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211HrDsssPhyPreambleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HrDsssPhyPreamble *pp = (Ieee80211HrDsssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211HrDsssPhyPreambleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HrDsssPhyPreamble *pp = (Ieee80211HrDsssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211HrDsssPhyPreambleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HrDsssPhyPreamble *pp = (Ieee80211HrDsssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211HrDsssPhyPreambleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HrDsssPhyPreamble *pp = (Ieee80211HrDsssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211HrDsssPhyPreambleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211HrDsssPhyPreambleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HrDsssPhyPreamble *pp = (Ieee80211HrDsssPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211HrDsssPhyHeader)

Ieee80211HrDsssPhyHeader::Ieee80211HrDsssPhyHeader() : ::inet::physicallayer::Ieee80211DsssPhyHeader()
{
}

Ieee80211HrDsssPhyHeader::Ieee80211HrDsssPhyHeader(const Ieee80211HrDsssPhyHeader& other) : ::inet::physicallayer::Ieee80211DsssPhyHeader(other)
{
    copy(other);
}

Ieee80211HrDsssPhyHeader::~Ieee80211HrDsssPhyHeader()
{
}

Ieee80211HrDsssPhyHeader& Ieee80211HrDsssPhyHeader::operator=(const Ieee80211HrDsssPhyHeader& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211DsssPhyHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211HrDsssPhyHeader::copy(const Ieee80211HrDsssPhyHeader& other)
{
}

void Ieee80211HrDsssPhyHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211DsssPhyHeader::parsimPack(b);
}

void Ieee80211HrDsssPhyHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211DsssPhyHeader::parsimUnpack(b);
}

class Ieee80211HrDsssPhyHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211HrDsssPhyHeaderDescriptor();
    virtual ~Ieee80211HrDsssPhyHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211HrDsssPhyHeaderDescriptor)

Ieee80211HrDsssPhyHeaderDescriptor::Ieee80211HrDsssPhyHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211HrDsssPhyHeader)), "inet::physicallayer::Ieee80211DsssPhyHeader")
{
    propertynames = nullptr;
}

Ieee80211HrDsssPhyHeaderDescriptor::~Ieee80211HrDsssPhyHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211HrDsssPhyHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211HrDsssPhyHeader *>(obj)!=nullptr;
}

const char **Ieee80211HrDsssPhyHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211HrDsssPhyHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211HrDsssPhyHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211HrDsssPhyHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211HrDsssPhyHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211HrDsssPhyHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211HrDsssPhyHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211HrDsssPhyHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211HrDsssPhyHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211HrDsssPhyHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HrDsssPhyHeader *pp = (Ieee80211HrDsssPhyHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211HrDsssPhyHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HrDsssPhyHeader *pp = (Ieee80211HrDsssPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211HrDsssPhyHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HrDsssPhyHeader *pp = (Ieee80211HrDsssPhyHeader *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211HrDsssPhyHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HrDsssPhyHeader *pp = (Ieee80211HrDsssPhyHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211HrDsssPhyHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211HrDsssPhyHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HrDsssPhyHeader *pp = (Ieee80211HrDsssPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211OfdmPhyPreamble)

Ieee80211OfdmPhyPreamble::Ieee80211OfdmPhyPreamble() : ::inet::physicallayer::Ieee80211PhyPreamble()
{
}

Ieee80211OfdmPhyPreamble::Ieee80211OfdmPhyPreamble(const Ieee80211OfdmPhyPreamble& other) : ::inet::physicallayer::Ieee80211PhyPreamble(other)
{
    copy(other);
}

Ieee80211OfdmPhyPreamble::~Ieee80211OfdmPhyPreamble()
{
}

Ieee80211OfdmPhyPreamble& Ieee80211OfdmPhyPreamble::operator=(const Ieee80211OfdmPhyPreamble& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211PhyPreamble::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211OfdmPhyPreamble::copy(const Ieee80211OfdmPhyPreamble& other)
{
}

void Ieee80211OfdmPhyPreamble::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211PhyPreamble::parsimPack(b);
}

void Ieee80211OfdmPhyPreamble::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211PhyPreamble::parsimUnpack(b);
}

class Ieee80211OfdmPhyPreambleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211OfdmPhyPreambleDescriptor();
    virtual ~Ieee80211OfdmPhyPreambleDescriptor();

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

Register_ClassDescriptor(Ieee80211OfdmPhyPreambleDescriptor)

Ieee80211OfdmPhyPreambleDescriptor::Ieee80211OfdmPhyPreambleDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211OfdmPhyPreamble)), "inet::physicallayer::Ieee80211PhyPreamble")
{
    propertynames = nullptr;
}

Ieee80211OfdmPhyPreambleDescriptor::~Ieee80211OfdmPhyPreambleDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211OfdmPhyPreambleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211OfdmPhyPreamble *>(obj)!=nullptr;
}

const char **Ieee80211OfdmPhyPreambleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211OfdmPhyPreambleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211OfdmPhyPreambleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211OfdmPhyPreambleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211OfdmPhyPreambleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211OfdmPhyPreambleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211OfdmPhyPreambleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211OfdmPhyPreambleDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211OfdmPhyPreambleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211OfdmPhyPreambleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmPhyPreamble *pp = (Ieee80211OfdmPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211OfdmPhyPreambleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmPhyPreamble *pp = (Ieee80211OfdmPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211OfdmPhyPreambleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmPhyPreamble *pp = (Ieee80211OfdmPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211OfdmPhyPreambleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmPhyPreamble *pp = (Ieee80211OfdmPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211OfdmPhyPreambleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211OfdmPhyPreambleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmPhyPreamble *pp = (Ieee80211OfdmPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211OfdmPhyHeader)

Ieee80211OfdmPhyHeader::Ieee80211OfdmPhyHeader() : ::inet::physicallayer::Ieee80211PhyHeader()
{
    this->setChunkLength(B(5));

}

Ieee80211OfdmPhyHeader::Ieee80211OfdmPhyHeader(const Ieee80211OfdmPhyHeader& other) : ::inet::physicallayer::Ieee80211PhyHeader(other)
{
    copy(other);
}

Ieee80211OfdmPhyHeader::~Ieee80211OfdmPhyHeader()
{
}

Ieee80211OfdmPhyHeader& Ieee80211OfdmPhyHeader::operator=(const Ieee80211OfdmPhyHeader& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211PhyHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211OfdmPhyHeader::copy(const Ieee80211OfdmPhyHeader& other)
{
    this->rate = other.rate;
    this->service = other.service;
}

void Ieee80211OfdmPhyHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211PhyHeader::parsimPack(b);
    doParsimPacking(b,this->rate);
    doParsimPacking(b,this->service);
}

void Ieee80211OfdmPhyHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211PhyHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->rate);
    doParsimUnpacking(b,this->service);
}

uint8_t Ieee80211OfdmPhyHeader::getRate() const
{
    return this->rate;
}

void Ieee80211OfdmPhyHeader::setRate(uint8_t rate)
{
    handleChange();
    this->rate = rate;
}

uint16_t Ieee80211OfdmPhyHeader::getService() const
{
    return this->service;
}

void Ieee80211OfdmPhyHeader::setService(uint16_t service)
{
    handleChange();
    this->service = service;
}

class Ieee80211OfdmPhyHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_rate,
        FIELD_service,
    };
  public:
    Ieee80211OfdmPhyHeaderDescriptor();
    virtual ~Ieee80211OfdmPhyHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211OfdmPhyHeaderDescriptor)

Ieee80211OfdmPhyHeaderDescriptor::Ieee80211OfdmPhyHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211OfdmPhyHeader)), "inet::physicallayer::Ieee80211PhyHeader")
{
    propertynames = nullptr;
}

Ieee80211OfdmPhyHeaderDescriptor::~Ieee80211OfdmPhyHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211OfdmPhyHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211OfdmPhyHeader *>(obj)!=nullptr;
}

const char **Ieee80211OfdmPhyHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211OfdmPhyHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211OfdmPhyHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ieee80211OfdmPhyHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_rate
        FD_ISEDITABLE,    // FIELD_service
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211OfdmPhyHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "rate",
        "service",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ieee80211OfdmPhyHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rate") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "service") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211OfdmPhyHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_rate
        "uint16_t",    // FIELD_service
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211OfdmPhyHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211OfdmPhyHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211OfdmPhyHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmPhyHeader *pp = (Ieee80211OfdmPhyHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211OfdmPhyHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmPhyHeader *pp = (Ieee80211OfdmPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211OfdmPhyHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmPhyHeader *pp = (Ieee80211OfdmPhyHeader *)object; (void)pp;
    switch (field) {
        case FIELD_rate: return ulong2string(pp->getRate());
        case FIELD_service: return ulong2string(pp->getService());
        default: return "";
    }
}

bool Ieee80211OfdmPhyHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmPhyHeader *pp = (Ieee80211OfdmPhyHeader *)object; (void)pp;
    switch (field) {
        case FIELD_rate: pp->setRate(string2ulong(value)); return true;
        case FIELD_service: pp->setService(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ieee80211OfdmPhyHeaderDescriptor::getFieldStructName(int field) const
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

void *Ieee80211OfdmPhyHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OfdmPhyHeader *pp = (Ieee80211OfdmPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211ErpOfdmPhyPreamble)

Ieee80211ErpOfdmPhyPreamble::Ieee80211ErpOfdmPhyPreamble() : ::inet::physicallayer::Ieee80211OfdmPhyPreamble()
{
}

Ieee80211ErpOfdmPhyPreamble::Ieee80211ErpOfdmPhyPreamble(const Ieee80211ErpOfdmPhyPreamble& other) : ::inet::physicallayer::Ieee80211OfdmPhyPreamble(other)
{
    copy(other);
}

Ieee80211ErpOfdmPhyPreamble::~Ieee80211ErpOfdmPhyPreamble()
{
}

Ieee80211ErpOfdmPhyPreamble& Ieee80211ErpOfdmPhyPreamble::operator=(const Ieee80211ErpOfdmPhyPreamble& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211OfdmPhyPreamble::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ErpOfdmPhyPreamble::copy(const Ieee80211ErpOfdmPhyPreamble& other)
{
}

void Ieee80211ErpOfdmPhyPreamble::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211OfdmPhyPreamble::parsimPack(b);
}

void Ieee80211ErpOfdmPhyPreamble::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211OfdmPhyPreamble::parsimUnpack(b);
}

class Ieee80211ErpOfdmPhyPreambleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211ErpOfdmPhyPreambleDescriptor();
    virtual ~Ieee80211ErpOfdmPhyPreambleDescriptor();

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

Register_ClassDescriptor(Ieee80211ErpOfdmPhyPreambleDescriptor)

Ieee80211ErpOfdmPhyPreambleDescriptor::Ieee80211ErpOfdmPhyPreambleDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211ErpOfdmPhyPreamble)), "inet::physicallayer::Ieee80211OfdmPhyPreamble")
{
    propertynames = nullptr;
}

Ieee80211ErpOfdmPhyPreambleDescriptor::~Ieee80211ErpOfdmPhyPreambleDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ErpOfdmPhyPreambleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ErpOfdmPhyPreamble *>(obj)!=nullptr;
}

const char **Ieee80211ErpOfdmPhyPreambleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ErpOfdmPhyPreambleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ErpOfdmPhyPreambleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211ErpOfdmPhyPreambleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211ErpOfdmPhyPreambleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211ErpOfdmPhyPreambleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ErpOfdmPhyPreambleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211ErpOfdmPhyPreambleDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ErpOfdmPhyPreambleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ErpOfdmPhyPreambleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ErpOfdmPhyPreamble *pp = (Ieee80211ErpOfdmPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ErpOfdmPhyPreambleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ErpOfdmPhyPreamble *pp = (Ieee80211ErpOfdmPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ErpOfdmPhyPreambleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ErpOfdmPhyPreamble *pp = (Ieee80211ErpOfdmPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211ErpOfdmPhyPreambleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ErpOfdmPhyPreamble *pp = (Ieee80211ErpOfdmPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ErpOfdmPhyPreambleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211ErpOfdmPhyPreambleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ErpOfdmPhyPreamble *pp = (Ieee80211ErpOfdmPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211ErpOfdmPhyHeader)

Ieee80211ErpOfdmPhyHeader::Ieee80211ErpOfdmPhyHeader() : ::inet::physicallayer::Ieee80211OfdmPhyHeader()
{
}

Ieee80211ErpOfdmPhyHeader::Ieee80211ErpOfdmPhyHeader(const Ieee80211ErpOfdmPhyHeader& other) : ::inet::physicallayer::Ieee80211OfdmPhyHeader(other)
{
    copy(other);
}

Ieee80211ErpOfdmPhyHeader::~Ieee80211ErpOfdmPhyHeader()
{
}

Ieee80211ErpOfdmPhyHeader& Ieee80211ErpOfdmPhyHeader::operator=(const Ieee80211ErpOfdmPhyHeader& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211OfdmPhyHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ErpOfdmPhyHeader::copy(const Ieee80211ErpOfdmPhyHeader& other)
{
}

void Ieee80211ErpOfdmPhyHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211OfdmPhyHeader::parsimPack(b);
}

void Ieee80211ErpOfdmPhyHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211OfdmPhyHeader::parsimUnpack(b);
}

class Ieee80211ErpOfdmPhyHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211ErpOfdmPhyHeaderDescriptor();
    virtual ~Ieee80211ErpOfdmPhyHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211ErpOfdmPhyHeaderDescriptor)

Ieee80211ErpOfdmPhyHeaderDescriptor::Ieee80211ErpOfdmPhyHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211ErpOfdmPhyHeader)), "inet::physicallayer::Ieee80211OfdmPhyHeader")
{
    propertynames = nullptr;
}

Ieee80211ErpOfdmPhyHeaderDescriptor::~Ieee80211ErpOfdmPhyHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ErpOfdmPhyHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ErpOfdmPhyHeader *>(obj)!=nullptr;
}

const char **Ieee80211ErpOfdmPhyHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ErpOfdmPhyHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ErpOfdmPhyHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211ErpOfdmPhyHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211ErpOfdmPhyHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211ErpOfdmPhyHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ErpOfdmPhyHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211ErpOfdmPhyHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ErpOfdmPhyHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ErpOfdmPhyHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ErpOfdmPhyHeader *pp = (Ieee80211ErpOfdmPhyHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ErpOfdmPhyHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ErpOfdmPhyHeader *pp = (Ieee80211ErpOfdmPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ErpOfdmPhyHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ErpOfdmPhyHeader *pp = (Ieee80211ErpOfdmPhyHeader *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211ErpOfdmPhyHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ErpOfdmPhyHeader *pp = (Ieee80211ErpOfdmPhyHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ErpOfdmPhyHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211ErpOfdmPhyHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ErpOfdmPhyHeader *pp = (Ieee80211ErpOfdmPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211HtPhyPreamble)

Ieee80211HtPhyPreamble::Ieee80211HtPhyPreamble() : ::inet::physicallayer::Ieee80211PhyPreamble()
{
}

Ieee80211HtPhyPreamble::Ieee80211HtPhyPreamble(const Ieee80211HtPhyPreamble& other) : ::inet::physicallayer::Ieee80211PhyPreamble(other)
{
    copy(other);
}

Ieee80211HtPhyPreamble::~Ieee80211HtPhyPreamble()
{
}

Ieee80211HtPhyPreamble& Ieee80211HtPhyPreamble::operator=(const Ieee80211HtPhyPreamble& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211PhyPreamble::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211HtPhyPreamble::copy(const Ieee80211HtPhyPreamble& other)
{
}

void Ieee80211HtPhyPreamble::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211PhyPreamble::parsimPack(b);
}

void Ieee80211HtPhyPreamble::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211PhyPreamble::parsimUnpack(b);
}

class Ieee80211HtPhyPreambleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211HtPhyPreambleDescriptor();
    virtual ~Ieee80211HtPhyPreambleDescriptor();

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

Register_ClassDescriptor(Ieee80211HtPhyPreambleDescriptor)

Ieee80211HtPhyPreambleDescriptor::Ieee80211HtPhyPreambleDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211HtPhyPreamble)), "inet::physicallayer::Ieee80211PhyPreamble")
{
    propertynames = nullptr;
}

Ieee80211HtPhyPreambleDescriptor::~Ieee80211HtPhyPreambleDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211HtPhyPreambleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211HtPhyPreamble *>(obj)!=nullptr;
}

const char **Ieee80211HtPhyPreambleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211HtPhyPreambleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211HtPhyPreambleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211HtPhyPreambleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211HtPhyPreambleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211HtPhyPreambleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211HtPhyPreambleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211HtPhyPreambleDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211HtPhyPreambleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211HtPhyPreambleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HtPhyPreamble *pp = (Ieee80211HtPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211HtPhyPreambleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HtPhyPreamble *pp = (Ieee80211HtPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211HtPhyPreambleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HtPhyPreamble *pp = (Ieee80211HtPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211HtPhyPreambleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HtPhyPreamble *pp = (Ieee80211HtPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211HtPhyPreambleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211HtPhyPreambleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HtPhyPreamble *pp = (Ieee80211HtPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211HtPhyHeader)

Ieee80211HtPhyHeader::Ieee80211HtPhyHeader() : ::inet::physicallayer::Ieee80211PhyHeader()
{
}

Ieee80211HtPhyHeader::Ieee80211HtPhyHeader(const Ieee80211HtPhyHeader& other) : ::inet::physicallayer::Ieee80211PhyHeader(other)
{
    copy(other);
}

Ieee80211HtPhyHeader::~Ieee80211HtPhyHeader()
{
}

Ieee80211HtPhyHeader& Ieee80211HtPhyHeader::operator=(const Ieee80211HtPhyHeader& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211PhyHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211HtPhyHeader::copy(const Ieee80211HtPhyHeader& other)
{
}

void Ieee80211HtPhyHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211PhyHeader::parsimPack(b);
}

void Ieee80211HtPhyHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211PhyHeader::parsimUnpack(b);
}

class Ieee80211HtPhyHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211HtPhyHeaderDescriptor();
    virtual ~Ieee80211HtPhyHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211HtPhyHeaderDescriptor)

Ieee80211HtPhyHeaderDescriptor::Ieee80211HtPhyHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211HtPhyHeader)), "inet::physicallayer::Ieee80211PhyHeader")
{
    propertynames = nullptr;
}

Ieee80211HtPhyHeaderDescriptor::~Ieee80211HtPhyHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211HtPhyHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211HtPhyHeader *>(obj)!=nullptr;
}

const char **Ieee80211HtPhyHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211HtPhyHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211HtPhyHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211HtPhyHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211HtPhyHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211HtPhyHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211HtPhyHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211HtPhyHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211HtPhyHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211HtPhyHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HtPhyHeader *pp = (Ieee80211HtPhyHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211HtPhyHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HtPhyHeader *pp = (Ieee80211HtPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211HtPhyHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HtPhyHeader *pp = (Ieee80211HtPhyHeader *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211HtPhyHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HtPhyHeader *pp = (Ieee80211HtPhyHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211HtPhyHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211HtPhyHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HtPhyHeader *pp = (Ieee80211HtPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211VhtPhyPreamble)

Ieee80211VhtPhyPreamble::Ieee80211VhtPhyPreamble() : ::inet::physicallayer::Ieee80211PhyPreamble()
{
}

Ieee80211VhtPhyPreamble::Ieee80211VhtPhyPreamble(const Ieee80211VhtPhyPreamble& other) : ::inet::physicallayer::Ieee80211PhyPreamble(other)
{
    copy(other);
}

Ieee80211VhtPhyPreamble::~Ieee80211VhtPhyPreamble()
{
}

Ieee80211VhtPhyPreamble& Ieee80211VhtPhyPreamble::operator=(const Ieee80211VhtPhyPreamble& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211PhyPreamble::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211VhtPhyPreamble::copy(const Ieee80211VhtPhyPreamble& other)
{
}

void Ieee80211VhtPhyPreamble::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211PhyPreamble::parsimPack(b);
}

void Ieee80211VhtPhyPreamble::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211PhyPreamble::parsimUnpack(b);
}

class Ieee80211VhtPhyPreambleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211VhtPhyPreambleDescriptor();
    virtual ~Ieee80211VhtPhyPreambleDescriptor();

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

Register_ClassDescriptor(Ieee80211VhtPhyPreambleDescriptor)

Ieee80211VhtPhyPreambleDescriptor::Ieee80211VhtPhyPreambleDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211VhtPhyPreamble)), "inet::physicallayer::Ieee80211PhyPreamble")
{
    propertynames = nullptr;
}

Ieee80211VhtPhyPreambleDescriptor::~Ieee80211VhtPhyPreambleDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211VhtPhyPreambleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211VhtPhyPreamble *>(obj)!=nullptr;
}

const char **Ieee80211VhtPhyPreambleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211VhtPhyPreambleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211VhtPhyPreambleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211VhtPhyPreambleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211VhtPhyPreambleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211VhtPhyPreambleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211VhtPhyPreambleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211VhtPhyPreambleDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211VhtPhyPreambleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211VhtPhyPreambleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211VhtPhyPreamble *pp = (Ieee80211VhtPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211VhtPhyPreambleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211VhtPhyPreamble *pp = (Ieee80211VhtPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211VhtPhyPreambleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211VhtPhyPreamble *pp = (Ieee80211VhtPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211VhtPhyPreambleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211VhtPhyPreamble *pp = (Ieee80211VhtPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211VhtPhyPreambleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211VhtPhyPreambleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211VhtPhyPreamble *pp = (Ieee80211VhtPhyPreamble *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211VhtPhyHeader)

Ieee80211VhtPhyHeader::Ieee80211VhtPhyHeader() : ::inet::physicallayer::Ieee80211PhyHeader()
{
}

Ieee80211VhtPhyHeader::Ieee80211VhtPhyHeader(const Ieee80211VhtPhyHeader& other) : ::inet::physicallayer::Ieee80211PhyHeader(other)
{
    copy(other);
}

Ieee80211VhtPhyHeader::~Ieee80211VhtPhyHeader()
{
}

Ieee80211VhtPhyHeader& Ieee80211VhtPhyHeader::operator=(const Ieee80211VhtPhyHeader& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::Ieee80211PhyHeader::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211VhtPhyHeader::copy(const Ieee80211VhtPhyHeader& other)
{
}

void Ieee80211VhtPhyHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::Ieee80211PhyHeader::parsimPack(b);
}

void Ieee80211VhtPhyHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::Ieee80211PhyHeader::parsimUnpack(b);
}

class Ieee80211VhtPhyHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    Ieee80211VhtPhyHeaderDescriptor();
    virtual ~Ieee80211VhtPhyHeaderDescriptor();

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

Register_ClassDescriptor(Ieee80211VhtPhyHeaderDescriptor)

Ieee80211VhtPhyHeaderDescriptor::Ieee80211VhtPhyHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211VhtPhyHeader)), "inet::physicallayer::Ieee80211PhyHeader")
{
    propertynames = nullptr;
}

Ieee80211VhtPhyHeaderDescriptor::~Ieee80211VhtPhyHeaderDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211VhtPhyHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211VhtPhyHeader *>(obj)!=nullptr;
}

const char **Ieee80211VhtPhyHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211VhtPhyHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211VhtPhyHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211VhtPhyHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211VhtPhyHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211VhtPhyHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211VhtPhyHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211VhtPhyHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211VhtPhyHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211VhtPhyHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211VhtPhyHeader *pp = (Ieee80211VhtPhyHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211VhtPhyHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211VhtPhyHeader *pp = (Ieee80211VhtPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211VhtPhyHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211VhtPhyHeader *pp = (Ieee80211VhtPhyHeader *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211VhtPhyHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211VhtPhyHeader *pp = (Ieee80211VhtPhyHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211VhtPhyHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211VhtPhyHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211VhtPhyHeader *pp = (Ieee80211VhtPhyHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace physicallayer
} // namespace inet

