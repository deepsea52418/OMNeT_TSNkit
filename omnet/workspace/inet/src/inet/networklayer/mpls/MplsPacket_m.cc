//
// Generated file, do not edit! Created by nedtool 5.6 from inet/networklayer/mpls/MplsPacket.msg.
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
#include "MplsPacket_m.h"

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

Register_Class(MplsLabel)

MplsLabel::MplsLabel() : ::omnetpp::cObject()
{
}

MplsLabel::MplsLabel(const MplsLabel& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

MplsLabel::~MplsLabel()
{
}

MplsLabel& MplsLabel::operator=(const MplsLabel& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void MplsLabel::copy(const MplsLabel& other)
{
    this->Label = other.Label;
    this->tc = other.tc;
    this->ttl = other.ttl;
}

void MplsLabel::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->Label);
    doParsimPacking(b,this->tc);
    doParsimPacking(b,this->ttl);
}

void MplsLabel::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->Label);
    doParsimUnpacking(b,this->tc);
    doParsimUnpacking(b,this->ttl);
}

long MplsLabel::getLabel() const
{
    return this->Label;
}

void MplsLabel::setLabel(long Label)
{
    this->Label = Label;
}

short MplsLabel::getTc() const
{
    return this->tc;
}

void MplsLabel::setTc(short tc)
{
    this->tc = tc;
}

short MplsLabel::getTtl() const
{
    return this->ttl;
}

void MplsLabel::setTtl(short ttl)
{
    this->ttl = ttl;
}

class MplsLabelDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_Label,
        FIELD_tc,
        FIELD_ttl,
    };
  public:
    MplsLabelDescriptor();
    virtual ~MplsLabelDescriptor();

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

Register_ClassDescriptor(MplsLabelDescriptor)

MplsLabelDescriptor::MplsLabelDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::MplsLabel)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

MplsLabelDescriptor::~MplsLabelDescriptor()
{
    delete[] propertynames;
}

bool MplsLabelDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MplsLabel *>(obj)!=nullptr;
}

const char **MplsLabelDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MplsLabelDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MplsLabelDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int MplsLabelDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_Label
        FD_ISEDITABLE,    // FIELD_tc
        FD_ISEDITABLE,    // FIELD_ttl
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MplsLabelDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "Label",
        "tc",
        "ttl",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MplsLabelDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'L' && strcmp(fieldName, "Label") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tc") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "ttl") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MplsLabelDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "long",    // FIELD_Label
        "short",    // FIELD_tc
        "short",    // FIELD_ttl
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MplsLabelDescriptor::getFieldPropertyNames(int field) const
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

const char *MplsLabelDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int MplsLabelDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MplsLabel *pp = (MplsLabel *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MplsLabelDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MplsLabel *pp = (MplsLabel *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MplsLabelDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MplsLabel *pp = (MplsLabel *)object; (void)pp;
    switch (field) {
        case FIELD_Label: return long2string(pp->getLabel());
        case FIELD_tc: return long2string(pp->getTc());
        case FIELD_ttl: return long2string(pp->getTtl());
        default: return "";
    }
}

bool MplsLabelDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MplsLabel *pp = (MplsLabel *)object; (void)pp;
    switch (field) {
        case FIELD_Label: pp->setLabel(string2long(value)); return true;
        case FIELD_tc: pp->setTc(string2long(value)); return true;
        case FIELD_ttl: pp->setTtl(string2long(value)); return true;
        default: return false;
    }
}

const char *MplsLabelDescriptor::getFieldStructName(int field) const
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

void *MplsLabelDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MplsLabel *pp = (MplsLabel *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(MplsHeader)

MplsHeader::MplsHeader() : ::inet::FieldsChunk()
{
}

MplsHeader::MplsHeader(const MplsHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

MplsHeader::~MplsHeader()
{
    delete [] this->labels;
}

MplsHeader& MplsHeader::operator=(const MplsHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void MplsHeader::copy(const MplsHeader& other)
{
    delete [] this->labels;
    this->labels = (other.labels_arraysize==0) ? nullptr : new MplsLabel[other.labels_arraysize];
    labels_arraysize = other.labels_arraysize;
    for (size_t i = 0; i < labels_arraysize; i++) {
        this->labels[i] = other.labels[i];
    }
}

void MplsHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    b->pack(labels_arraysize);
    doParsimArrayPacking(b,this->labels,labels_arraysize);
}

void MplsHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    delete [] this->labels;
    b->unpack(labels_arraysize);
    if (labels_arraysize == 0) {
        this->labels = nullptr;
    } else {
        this->labels = new MplsLabel[labels_arraysize];
        doParsimArrayUnpacking(b,this->labels,labels_arraysize);
    }
}

size_t MplsHeader::getLabelsArraySize() const
{
    return labels_arraysize;
}

const MplsLabel& MplsHeader::getLabels(size_t k) const
{
    if (k >= labels_arraysize) throw omnetpp::cRuntimeError("Array of size labels_arraysize indexed by %lu", (unsigned long)k);
    return this->labels[k];
}

void MplsHeader::setLabelsArraySize(size_t newSize)
{
    handleChange();
    MplsLabel *labels2 = (newSize==0) ? nullptr : new MplsLabel[newSize];
    size_t minSize = labels_arraysize < newSize ? labels_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        labels2[i] = this->labels[i];
    delete [] this->labels;
    this->labels = labels2;
    labels_arraysize = newSize;
}

void MplsHeader::setLabels(size_t k, const MplsLabel& labels)
{
    if (k >= labels_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->labels[k] = labels;
}

void MplsHeader::insertLabels(size_t k, const MplsLabel& labels)
{
    handleChange();
    if (k > labels_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = labels_arraysize + 1;
    MplsLabel *labels2 = new MplsLabel[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        labels2[i] = this->labels[i];
    labels2[k] = labels;
    for (i = k + 1; i < newSize; i++)
        labels2[i] = this->labels[i-1];
    delete [] this->labels;
    this->labels = labels2;
    labels_arraysize = newSize;
}

void MplsHeader::insertLabels(const MplsLabel& labels)
{
    insertLabels(labels_arraysize, labels);
}

void MplsHeader::eraseLabels(size_t k)
{
    if (k >= labels_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = labels_arraysize - 1;
    MplsLabel *labels2 = (newSize == 0) ? nullptr : new MplsLabel[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        labels2[i] = this->labels[i];
    for (i = k; i < newSize; i++)
        labels2[i] = this->labels[i+1];
    delete [] this->labels;
    this->labels = labels2;
    labels_arraysize = newSize;
}

class MplsHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_labels,
    };
  public:
    MplsHeaderDescriptor();
    virtual ~MplsHeaderDescriptor();

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

Register_ClassDescriptor(MplsHeaderDescriptor)

MplsHeaderDescriptor::MplsHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::MplsHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

MplsHeaderDescriptor::~MplsHeaderDescriptor()
{
    delete[] propertynames;
}

bool MplsHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MplsHeader *>(obj)!=nullptr;
}

const char **MplsHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MplsHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MplsHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int MplsHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_labels
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MplsHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "labels",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MplsHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "labels") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MplsHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MplsLabel",    // FIELD_labels
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MplsHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *MplsHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int MplsHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MplsHeader *pp = (MplsHeader *)object; (void)pp;
    switch (field) {
        case FIELD_labels: return pp->getLabelsArraySize();
        default: return 0;
    }
}

const char *MplsHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MplsHeader *pp = (MplsHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MplsHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MplsHeader *pp = (MplsHeader *)object; (void)pp;
    switch (field) {
        case FIELD_labels: {std::stringstream out; out << pp->getLabels(i); return out.str();}
        default: return "";
    }
}

bool MplsHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MplsHeader *pp = (MplsHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MplsHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_labels: return omnetpp::opp_typename(typeid(MplsLabel));
        default: return nullptr;
    };
}

void *MplsHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MplsHeader *pp = (MplsHeader *)object; (void)pp;
    switch (field) {
        case FIELD_labels: return toVoidPtr(&pp->getLabels(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

