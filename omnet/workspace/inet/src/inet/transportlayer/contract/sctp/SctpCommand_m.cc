//
// Generated file, do not edit! Created by nedtool 5.6 from inet/transportlayer/contract/sctp/SctpCommand.msg.
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
#include "SctpCommand_m.h"

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

class AddressVectorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    AddressVectorDescriptor();
    virtual ~AddressVectorDescriptor();

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

Register_ClassDescriptor(AddressVectorDescriptor)

AddressVectorDescriptor::AddressVectorDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::AddressVector)), "")
{
    propertynames = nullptr;
}

AddressVectorDescriptor::~AddressVectorDescriptor()
{
    delete[] propertynames;
}

bool AddressVectorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AddressVector *>(obj)!=nullptr;
}

const char **AddressVectorDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AddressVectorDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AddressVectorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int AddressVectorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *AddressVectorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int AddressVectorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AddressVectorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **AddressVectorDescriptor::getFieldPropertyNames(int field) const
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

const char *AddressVectorDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AddressVectorDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AddressVector *pp = (AddressVector *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AddressVectorDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AddressVector *pp = (AddressVector *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AddressVectorDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AddressVector *pp = (AddressVector *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool AddressVectorDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AddressVector *pp = (AddressVector *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *AddressVectorDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *AddressVectorDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AddressVector *pp = (AddressVector *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::SctpErrorCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::SctpErrorCode"));
)

Register_Class(SctpSimpleMessage)

SctpSimpleMessage::SctpSimpleMessage(const char *name) : ::omnetpp::cPacket(name)
{
}

SctpSimpleMessage::SctpSimpleMessage(const SctpSimpleMessage& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SctpSimpleMessage::~SctpSimpleMessage()
{
    delete [] this->data;
}

SctpSimpleMessage& SctpSimpleMessage::operator=(const SctpSimpleMessage& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SctpSimpleMessage::copy(const SctpSimpleMessage& other)
{
    this->dataLen = other.dataLen;
    delete [] this->data;
    this->data = (other.data_arraysize==0) ? nullptr : new uint8_t[other.data_arraysize];
    data_arraysize = other.data_arraysize;
    for (size_t i = 0; i < data_arraysize; i++) {
        this->data[i] = other.data[i];
    }
    this->creationTime = other.creationTime;
    this->encaps = other.encaps;
}

void SctpSimpleMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->dataLen);
    b->pack(data_arraysize);
    doParsimArrayPacking(b,this->data,data_arraysize);
    doParsimPacking(b,this->creationTime);
    doParsimPacking(b,this->encaps);
}

void SctpSimpleMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->dataLen);
    delete [] this->data;
    b->unpack(data_arraysize);
    if (data_arraysize == 0) {
        this->data = nullptr;
    } else {
        this->data = new uint8_t[data_arraysize];
        doParsimArrayUnpacking(b,this->data,data_arraysize);
    }
    doParsimUnpacking(b,this->creationTime);
    doParsimUnpacking(b,this->encaps);
}

uint32_t SctpSimpleMessage::getDataLen() const
{
    return this->dataLen;
}

void SctpSimpleMessage::setDataLen(uint32_t dataLen)
{
    this->dataLen = dataLen;
}

size_t SctpSimpleMessage::getDataArraySize() const
{
    return data_arraysize;
}

uint8_t SctpSimpleMessage::getData(size_t k) const
{
    if (k >= data_arraysize) throw omnetpp::cRuntimeError("Array of size data_arraysize indexed by %lu", (unsigned long)k);
    return this->data[k];
}

void SctpSimpleMessage::setDataArraySize(size_t newSize)
{
    uint8_t *data2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = data_arraysize < newSize ? data_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        data2[i] = this->data[i];
    for (size_t i = minSize; i < newSize; i++)
        data2[i] = 0;
    delete [] this->data;
    this->data = data2;
    data_arraysize = newSize;
}

void SctpSimpleMessage::setData(size_t k, uint8_t data)
{
    if (k >= data_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->data[k] = data;
}

void SctpSimpleMessage::insertData(size_t k, uint8_t data)
{
    if (k > data_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = data_arraysize + 1;
    uint8_t *data2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        data2[i] = this->data[i];
    data2[k] = data;
    for (i = k + 1; i < newSize; i++)
        data2[i] = this->data[i-1];
    delete [] this->data;
    this->data = data2;
    data_arraysize = newSize;
}

void SctpSimpleMessage::insertData(uint8_t data)
{
    insertData(data_arraysize, data);
}

void SctpSimpleMessage::eraseData(size_t k)
{
    if (k >= data_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = data_arraysize - 1;
    uint8_t *data2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        data2[i] = this->data[i];
    for (i = k; i < newSize; i++)
        data2[i] = this->data[i+1];
    delete [] this->data;
    this->data = data2;
    data_arraysize = newSize;
}

omnetpp::simtime_t SctpSimpleMessage::getCreationTime() const
{
    return this->creationTime;
}

void SctpSimpleMessage::setCreationTime(omnetpp::simtime_t creationTime)
{
    this->creationTime = creationTime;
}

bool SctpSimpleMessage::getEncaps() const
{
    return this->encaps;
}

void SctpSimpleMessage::setEncaps(bool encaps)
{
    this->encaps = encaps;
}

class SctpSimpleMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_dataLen,
        FIELD_data,
        FIELD_creationTime,
        FIELD_encaps,
    };
  public:
    SctpSimpleMessageDescriptor();
    virtual ~SctpSimpleMessageDescriptor();

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

Register_ClassDescriptor(SctpSimpleMessageDescriptor)

SctpSimpleMessageDescriptor::SctpSimpleMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpSimpleMessage)), "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SctpSimpleMessageDescriptor::~SctpSimpleMessageDescriptor()
{
    delete[] propertynames;
}

bool SctpSimpleMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpSimpleMessage *>(obj)!=nullptr;
}

const char **SctpSimpleMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpSimpleMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpSimpleMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SctpSimpleMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_dataLen
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_data
        0,    // FIELD_creationTime
        FD_ISEDITABLE,    // FIELD_encaps
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SctpSimpleMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "dataLen",
        "data",
        "creationTime",
        "encaps",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SctpSimpleMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dataLen") == 0) return base+0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "data") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "creationTime") == 0) return base+2;
    if (fieldName[0] == 'e' && strcmp(fieldName, "encaps") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpSimpleMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_dataLen
        "uint8_t",    // FIELD_data
        "omnetpp::simtime_t",    // FIELD_creationTime
        "bool",    // FIELD_encaps
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpSimpleMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpSimpleMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpSimpleMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpSimpleMessage *pp = (SctpSimpleMessage *)object; (void)pp;
    switch (field) {
        case FIELD_data: return pp->getDataArraySize();
        default: return 0;
    }
}

const char *SctpSimpleMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSimpleMessage *pp = (SctpSimpleMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpSimpleMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSimpleMessage *pp = (SctpSimpleMessage *)object; (void)pp;
    switch (field) {
        case FIELD_dataLen: return ulong2string(pp->getDataLen());
        case FIELD_data: return ulong2string(pp->getData(i));
        case FIELD_creationTime: return simtime2string(pp->getCreationTime());
        case FIELD_encaps: return bool2string(pp->getEncaps());
        default: return "";
    }
}

bool SctpSimpleMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpSimpleMessage *pp = (SctpSimpleMessage *)object; (void)pp;
    switch (field) {
        case FIELD_dataLen: pp->setDataLen(string2ulong(value)); return true;
        case FIELD_data: pp->setData(i,string2ulong(value)); return true;
        case FIELD_encaps: pp->setEncaps(string2bool(value)); return true;
        default: return false;
    }
}

const char *SctpSimpleMessageDescriptor::getFieldStructName(int field) const
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

void *SctpSimpleMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpSimpleMessage *pp = (SctpSimpleMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpCommandReq)

SctpCommandReq::SctpCommandReq() : ::inet::TagBase()
{
}

SctpCommandReq::SctpCommandReq(const SctpCommandReq& other) : ::inet::TagBase(other)
{
    copy(other);
}

SctpCommandReq::~SctpCommandReq()
{
}

SctpCommandReq& SctpCommandReq::operator=(const SctpCommandReq& other)
{
    if (this == &other) return *this;
    ::inet::TagBase::operator=(other);
    copy(other);
    return *this;
}

void SctpCommandReq::copy(const SctpCommandReq& other)
{
    this->socketId = other.socketId;
    this->sid = other.sid;
    this->numMsgs = other.numMsgs;
    this->ssn = other.ssn;
    this->sendUnordered = other.sendUnordered;
    this->prValue = other.prValue;
    this->localAddr = other.localAddr;
    this->remoteAddr = other.remoteAddr;
    this->localPort = other.localPort;
    this->remotePort = other.remotePort;
    this->gate = other.gate;
    this->fd = other.fd;
}

void SctpCommandReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TagBase::parsimPack(b);
    doParsimPacking(b,this->socketId);
    doParsimPacking(b,this->sid);
    doParsimPacking(b,this->numMsgs);
    doParsimPacking(b,this->ssn);
    doParsimPacking(b,this->sendUnordered);
    doParsimPacking(b,this->prValue);
    doParsimPacking(b,this->localAddr);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->localPort);
    doParsimPacking(b,this->remotePort);
    doParsimPacking(b,this->gate);
    doParsimPacking(b,this->fd);
}

void SctpCommandReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->socketId);
    doParsimUnpacking(b,this->sid);
    doParsimUnpacking(b,this->numMsgs);
    doParsimUnpacking(b,this->ssn);
    doParsimUnpacking(b,this->sendUnordered);
    doParsimUnpacking(b,this->prValue);
    doParsimUnpacking(b,this->localAddr);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->localPort);
    doParsimUnpacking(b,this->remotePort);
    doParsimUnpacking(b,this->gate);
    doParsimUnpacking(b,this->fd);
}

int SctpCommandReq::getSocketId() const
{
    return this->socketId;
}

void SctpCommandReq::setSocketId(int socketId)
{
    this->socketId = socketId;
}

int SctpCommandReq::getSid() const
{
    return this->sid;
}

void SctpCommandReq::setSid(int sid)
{
    this->sid = sid;
}

int SctpCommandReq::getNumMsgs() const
{
    return this->numMsgs;
}

void SctpCommandReq::setNumMsgs(int numMsgs)
{
    this->numMsgs = numMsgs;
}

int SctpCommandReq::getSsn() const
{
    return this->ssn;
}

void SctpCommandReq::setSsn(int ssn)
{
    this->ssn = ssn;
}

unsigned short SctpCommandReq::getSendUnordered() const
{
    return this->sendUnordered;
}

void SctpCommandReq::setSendUnordered(unsigned short sendUnordered)
{
    this->sendUnordered = sendUnordered;
}

double SctpCommandReq::getPrValue() const
{
    return this->prValue;
}

void SctpCommandReq::setPrValue(double prValue)
{
    this->prValue = prValue;
}

const L3Address& SctpCommandReq::getLocalAddr() const
{
    return this->localAddr;
}

void SctpCommandReq::setLocalAddr(const L3Address& localAddr)
{
    this->localAddr = localAddr;
}

const L3Address& SctpCommandReq::getRemoteAddr() const
{
    return this->remoteAddr;
}

void SctpCommandReq::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

int SctpCommandReq::getLocalPort() const
{
    return this->localPort;
}

void SctpCommandReq::setLocalPort(int localPort)
{
    this->localPort = localPort;
}

int SctpCommandReq::getRemotePort() const
{
    return this->remotePort;
}

void SctpCommandReq::setRemotePort(int remotePort)
{
    this->remotePort = remotePort;
}

int SctpCommandReq::getGate() const
{
    return this->gate;
}

void SctpCommandReq::setGate(int gate)
{
    this->gate = gate;
}

int SctpCommandReq::getFd() const
{
    return this->fd;
}

void SctpCommandReq::setFd(int fd)
{
    this->fd = fd;
}

class SctpCommandReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_socketId,
        FIELD_sid,
        FIELD_numMsgs,
        FIELD_ssn,
        FIELD_sendUnordered,
        FIELD_prValue,
        FIELD_localAddr,
        FIELD_remoteAddr,
        FIELD_localPort,
        FIELD_remotePort,
        FIELD_gate,
        FIELD_fd,
    };
  public:
    SctpCommandReqDescriptor();
    virtual ~SctpCommandReqDescriptor();

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

Register_ClassDescriptor(SctpCommandReqDescriptor)

SctpCommandReqDescriptor::SctpCommandReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpCommandReq)), "inet::TagBase")
{
    propertynames = nullptr;
}

SctpCommandReqDescriptor::~SctpCommandReqDescriptor()
{
    delete[] propertynames;
}

bool SctpCommandReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpCommandReq *>(obj)!=nullptr;
}

const char **SctpCommandReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpCommandReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpCommandReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int SctpCommandReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_socketId
        FD_ISEDITABLE,    // FIELD_sid
        FD_ISEDITABLE,    // FIELD_numMsgs
        FD_ISEDITABLE,    // FIELD_ssn
        FD_ISEDITABLE,    // FIELD_sendUnordered
        FD_ISEDITABLE,    // FIELD_prValue
        0,    // FIELD_localAddr
        0,    // FIELD_remoteAddr
        FD_ISEDITABLE,    // FIELD_localPort
        FD_ISEDITABLE,    // FIELD_remotePort
        FD_ISEDITABLE,    // FIELD_gate
        FD_ISEDITABLE,    // FIELD_fd
    };
    return (field >= 0 && field < 12) ? fieldTypeFlags[field] : 0;
}

const char *SctpCommandReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "socketId",
        "sid",
        "numMsgs",
        "ssn",
        "sendUnordered",
        "prValue",
        "localAddr",
        "remoteAddr",
        "localPort",
        "remotePort",
        "gate",
        "fd",
    };
    return (field >= 0 && field < 12) ? fieldNames[field] : nullptr;
}

int SctpCommandReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "socketId") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sid") == 0) return base+1;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numMsgs") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "ssn") == 0) return base+3;
    if (fieldName[0] == 's' && strcmp(fieldName, "sendUnordered") == 0) return base+4;
    if (fieldName[0] == 'p' && strcmp(fieldName, "prValue") == 0) return base+5;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localAddr") == 0) return base+6;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddr") == 0) return base+7;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localPort") == 0) return base+8;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remotePort") == 0) return base+9;
    if (fieldName[0] == 'g' && strcmp(fieldName, "gate") == 0) return base+10;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fd") == 0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpCommandReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_socketId
        "int",    // FIELD_sid
        "int",    // FIELD_numMsgs
        "int",    // FIELD_ssn
        "unsigned short",    // FIELD_sendUnordered
        "double",    // FIELD_prValue
        "inet::L3Address",    // FIELD_localAddr
        "inet::L3Address",    // FIELD_remoteAddr
        "int",    // FIELD_localPort
        "int",    // FIELD_remotePort
        "int",    // FIELD_gate
        "int",    // FIELD_fd
    };
    return (field >= 0 && field < 12) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpCommandReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpCommandReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpCommandReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpCommandReq *pp = (SctpCommandReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpCommandReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpCommandReq *pp = (SctpCommandReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpCommandReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpCommandReq *pp = (SctpCommandReq *)object; (void)pp;
    switch (field) {
        case FIELD_socketId: return long2string(pp->getSocketId());
        case FIELD_sid: return long2string(pp->getSid());
        case FIELD_numMsgs: return long2string(pp->getNumMsgs());
        case FIELD_ssn: return long2string(pp->getSsn());
        case FIELD_sendUnordered: return ulong2string(pp->getSendUnordered());
        case FIELD_prValue: return double2string(pp->getPrValue());
        case FIELD_localAddr: return pp->getLocalAddr().str();
        case FIELD_remoteAddr: return pp->getRemoteAddr().str();
        case FIELD_localPort: return long2string(pp->getLocalPort());
        case FIELD_remotePort: return long2string(pp->getRemotePort());
        case FIELD_gate: return long2string(pp->getGate());
        case FIELD_fd: return long2string(pp->getFd());
        default: return "";
    }
}

bool SctpCommandReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpCommandReq *pp = (SctpCommandReq *)object; (void)pp;
    switch (field) {
        case FIELD_socketId: pp->setSocketId(string2long(value)); return true;
        case FIELD_sid: pp->setSid(string2long(value)); return true;
        case FIELD_numMsgs: pp->setNumMsgs(string2long(value)); return true;
        case FIELD_ssn: pp->setSsn(string2long(value)); return true;
        case FIELD_sendUnordered: pp->setSendUnordered(string2ulong(value)); return true;
        case FIELD_prValue: pp->setPrValue(string2double(value)); return true;
        case FIELD_localPort: pp->setLocalPort(string2long(value)); return true;
        case FIELD_remotePort: pp->setRemotePort(string2long(value)); return true;
        case FIELD_gate: pp->setGate(string2long(value)); return true;
        case FIELD_fd: pp->setFd(string2long(value)); return true;
        default: return false;
    }
}

const char *SctpCommandReqDescriptor::getFieldStructName(int field) const
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

void *SctpCommandReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpCommandReq *pp = (SctpCommandReq *)object; (void)pp;
    switch (field) {
        case FIELD_localAddr: return toVoidPtr(&pp->getLocalAddr()); break;
        case FIELD_remoteAddr: return toVoidPtr(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(SctpSendReq)

SctpSendReq::SctpSendReq() : ::inet::SctpCommandReq()
{
}

SctpSendReq::SctpSendReq(const SctpSendReq& other) : ::inet::SctpCommandReq(other)
{
    copy(other);
}

SctpSendReq::~SctpSendReq()
{
}

SctpSendReq& SctpSendReq::operator=(const SctpSendReq& other)
{
    if (this == &other) return *this;
    ::inet::SctpCommandReq::operator=(other);
    copy(other);
    return *this;
}

void SctpSendReq::copy(const SctpSendReq& other)
{
    this->prMethod = other.prMethod;
    this->last = other.last;
    this->ppid = other.ppid;
    this->primary = other.primary;
    this->sackNow = other.sackNow;
}

void SctpSendReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SctpCommandReq::parsimPack(b);
    doParsimPacking(b,this->prMethod);
    doParsimPacking(b,this->last);
    doParsimPacking(b,this->ppid);
    doParsimPacking(b,this->primary);
    doParsimPacking(b,this->sackNow);
}

void SctpSendReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SctpCommandReq::parsimUnpack(b);
    doParsimUnpacking(b,this->prMethod);
    doParsimUnpacking(b,this->last);
    doParsimUnpacking(b,this->ppid);
    doParsimUnpacking(b,this->primary);
    doParsimUnpacking(b,this->sackNow);
}

unsigned int SctpSendReq::getPrMethod() const
{
    return this->prMethod;
}

void SctpSendReq::setPrMethod(unsigned int prMethod)
{
    this->prMethod = prMethod;
}

bool SctpSendReq::getLast() const
{
    return this->last;
}

void SctpSendReq::setLast(bool last)
{
    this->last = last;
}

unsigned int SctpSendReq::getPpid() const
{
    return this->ppid;
}

void SctpSendReq::setPpid(unsigned int ppid)
{
    this->ppid = ppid;
}

bool SctpSendReq::getPrimary() const
{
    return this->primary;
}

void SctpSendReq::setPrimary(bool primary)
{
    this->primary = primary;
}

bool SctpSendReq::getSackNow() const
{
    return this->sackNow;
}

void SctpSendReq::setSackNow(bool sackNow)
{
    this->sackNow = sackNow;
}

class SctpSendReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_prMethod,
        FIELD_last,
        FIELD_ppid,
        FIELD_primary,
        FIELD_sackNow,
    };
  public:
    SctpSendReqDescriptor();
    virtual ~SctpSendReqDescriptor();

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

Register_ClassDescriptor(SctpSendReqDescriptor)

SctpSendReqDescriptor::SctpSendReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpSendReq)), "inet::SctpCommandReq")
{
    propertynames = nullptr;
}

SctpSendReqDescriptor::~SctpSendReqDescriptor()
{
    delete[] propertynames;
}

bool SctpSendReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpSendReq *>(obj)!=nullptr;
}

const char **SctpSendReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpSendReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpSendReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int SctpSendReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_prMethod
        FD_ISEDITABLE,    // FIELD_last
        FD_ISEDITABLE,    // FIELD_ppid
        FD_ISEDITABLE,    // FIELD_primary
        FD_ISEDITABLE,    // FIELD_sackNow
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *SctpSendReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "prMethod",
        "last",
        "ppid",
        "primary",
        "sackNow",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int SctpSendReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "prMethod") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "last") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "ppid") == 0) return base+2;
    if (fieldName[0] == 'p' && strcmp(fieldName, "primary") == 0) return base+3;
    if (fieldName[0] == 's' && strcmp(fieldName, "sackNow") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpSendReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_prMethod
        "bool",    // FIELD_last
        "unsigned int",    // FIELD_ppid
        "bool",    // FIELD_primary
        "bool",    // FIELD_sackNow
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpSendReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpSendReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpSendReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpSendReq *pp = (SctpSendReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpSendReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSendReq *pp = (SctpSendReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpSendReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSendReq *pp = (SctpSendReq *)object; (void)pp;
    switch (field) {
        case FIELD_prMethod: return ulong2string(pp->getPrMethod());
        case FIELD_last: return bool2string(pp->getLast());
        case FIELD_ppid: return ulong2string(pp->getPpid());
        case FIELD_primary: return bool2string(pp->getPrimary());
        case FIELD_sackNow: return bool2string(pp->getSackNow());
        default: return "";
    }
}

bool SctpSendReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpSendReq *pp = (SctpSendReq *)object; (void)pp;
    switch (field) {
        case FIELD_prMethod: pp->setPrMethod(string2ulong(value)); return true;
        case FIELD_last: pp->setLast(string2bool(value)); return true;
        case FIELD_ppid: pp->setPpid(string2ulong(value)); return true;
        case FIELD_primary: pp->setPrimary(string2bool(value)); return true;
        case FIELD_sackNow: pp->setSackNow(string2bool(value)); return true;
        default: return false;
    }
}

const char *SctpSendReqDescriptor::getFieldStructName(int field) const
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

void *SctpSendReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpSendReq *pp = (SctpSendReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpOpenReq)

SctpOpenReq::SctpOpenReq() : ::inet::SctpCommandReq()
{
}

SctpOpenReq::SctpOpenReq(const SctpOpenReq& other) : ::inet::SctpCommandReq(other)
{
    copy(other);
}

SctpOpenReq::~SctpOpenReq()
{
}

SctpOpenReq& SctpOpenReq::operator=(const SctpOpenReq& other)
{
    if (this == &other) return *this;
    ::inet::SctpCommandReq::operator=(other);
    copy(other);
    return *this;
}

void SctpOpenReq::copy(const SctpOpenReq& other)
{
    this->localAddresses = other.localAddresses;
    this->remoteAddresses = other.remoteAddresses;
    this->fork = other.fork;
    this->queueClass = other.queueClass;
    this->sctpAlgorithmClass = other.sctpAlgorithmClass;
    this->inboundStreams = other.inboundStreams;
    this->outboundStreams = other.outboundStreams;
    this->streamReset = other.streamReset;
    this->appLimited = other.appLimited;
    this->prMethod = other.prMethod;
    this->numRequests = other.numRequests;
    this->messagesToPush = other.messagesToPush;
}

void SctpOpenReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SctpCommandReq::parsimPack(b);
    doParsimPacking(b,this->localAddresses);
    doParsimPacking(b,this->remoteAddresses);
    doParsimPacking(b,this->fork);
    doParsimPacking(b,this->queueClass);
    doParsimPacking(b,this->sctpAlgorithmClass);
    doParsimPacking(b,this->inboundStreams);
    doParsimPacking(b,this->outboundStreams);
    doParsimPacking(b,this->streamReset);
    doParsimPacking(b,this->appLimited);
    doParsimPacking(b,this->prMethod);
    doParsimPacking(b,this->numRequests);
    doParsimPacking(b,this->messagesToPush);
}

void SctpOpenReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SctpCommandReq::parsimUnpack(b);
    doParsimUnpacking(b,this->localAddresses);
    doParsimUnpacking(b,this->remoteAddresses);
    doParsimUnpacking(b,this->fork);
    doParsimUnpacking(b,this->queueClass);
    doParsimUnpacking(b,this->sctpAlgorithmClass);
    doParsimUnpacking(b,this->inboundStreams);
    doParsimUnpacking(b,this->outboundStreams);
    doParsimUnpacking(b,this->streamReset);
    doParsimUnpacking(b,this->appLimited);
    doParsimUnpacking(b,this->prMethod);
    doParsimUnpacking(b,this->numRequests);
    doParsimUnpacking(b,this->messagesToPush);
}

const AddressVector& SctpOpenReq::getLocalAddresses() const
{
    return this->localAddresses;
}

void SctpOpenReq::setLocalAddresses(const AddressVector& localAddresses)
{
    this->localAddresses = localAddresses;
}

const AddressVector& SctpOpenReq::getRemoteAddresses() const
{
    return this->remoteAddresses;
}

void SctpOpenReq::setRemoteAddresses(const AddressVector& remoteAddresses)
{
    this->remoteAddresses = remoteAddresses;
}

bool SctpOpenReq::getFork() const
{
    return this->fork;
}

void SctpOpenReq::setFork(bool fork)
{
    this->fork = fork;
}

const char * SctpOpenReq::getQueueClass() const
{
    return this->queueClass.c_str();
}

void SctpOpenReq::setQueueClass(const char * queueClass)
{
    this->queueClass = queueClass;
}

const char * SctpOpenReq::getSctpAlgorithmClass() const
{
    return this->sctpAlgorithmClass.c_str();
}

void SctpOpenReq::setSctpAlgorithmClass(const char * sctpAlgorithmClass)
{
    this->sctpAlgorithmClass = sctpAlgorithmClass;
}

uint32_t SctpOpenReq::getInboundStreams() const
{
    return this->inboundStreams;
}

void SctpOpenReq::setInboundStreams(uint32_t inboundStreams)
{
    this->inboundStreams = inboundStreams;
}

uint32_t SctpOpenReq::getOutboundStreams() const
{
    return this->outboundStreams;
}

void SctpOpenReq::setOutboundStreams(uint32_t outboundStreams)
{
    this->outboundStreams = outboundStreams;
}

bool SctpOpenReq::getStreamReset() const
{
    return this->streamReset;
}

void SctpOpenReq::setStreamReset(bool streamReset)
{
    this->streamReset = streamReset;
}

bool SctpOpenReq::getAppLimited() const
{
    return this->appLimited;
}

void SctpOpenReq::setAppLimited(bool appLimited)
{
    this->appLimited = appLimited;
}

int SctpOpenReq::getPrMethod() const
{
    return this->prMethod;
}

void SctpOpenReq::setPrMethod(int prMethod)
{
    this->prMethod = prMethod;
}

uint32_t SctpOpenReq::getNumRequests() const
{
    return this->numRequests;
}

void SctpOpenReq::setNumRequests(uint32_t numRequests)
{
    this->numRequests = numRequests;
}

uint32_t SctpOpenReq::getMessagesToPush() const
{
    return this->messagesToPush;
}

void SctpOpenReq::setMessagesToPush(uint32_t messagesToPush)
{
    this->messagesToPush = messagesToPush;
}

class SctpOpenReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_localAddresses,
        FIELD_remoteAddresses,
        FIELD_fork,
        FIELD_queueClass,
        FIELD_sctpAlgorithmClass,
        FIELD_inboundStreams,
        FIELD_outboundStreams,
        FIELD_streamReset,
        FIELD_appLimited,
        FIELD_prMethod,
        FIELD_numRequests,
        FIELD_messagesToPush,
    };
  public:
    SctpOpenReqDescriptor();
    virtual ~SctpOpenReqDescriptor();

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

Register_ClassDescriptor(SctpOpenReqDescriptor)

SctpOpenReqDescriptor::SctpOpenReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpOpenReq)), "inet::SctpCommandReq")
{
    propertynames = nullptr;
}

SctpOpenReqDescriptor::~SctpOpenReqDescriptor()
{
    delete[] propertynames;
}

bool SctpOpenReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpOpenReq *>(obj)!=nullptr;
}

const char **SctpOpenReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpOpenReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpOpenReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int SctpOpenReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_localAddresses
        FD_ISCOMPOUND,    // FIELD_remoteAddresses
        FD_ISEDITABLE,    // FIELD_fork
        FD_ISEDITABLE,    // FIELD_queueClass
        FD_ISEDITABLE,    // FIELD_sctpAlgorithmClass
        FD_ISEDITABLE,    // FIELD_inboundStreams
        FD_ISEDITABLE,    // FIELD_outboundStreams
        FD_ISEDITABLE,    // FIELD_streamReset
        FD_ISEDITABLE,    // FIELD_appLimited
        FD_ISEDITABLE,    // FIELD_prMethod
        FD_ISEDITABLE,    // FIELD_numRequests
        FD_ISEDITABLE,    // FIELD_messagesToPush
    };
    return (field >= 0 && field < 12) ? fieldTypeFlags[field] : 0;
}

const char *SctpOpenReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "localAddresses",
        "remoteAddresses",
        "fork",
        "queueClass",
        "sctpAlgorithmClass",
        "inboundStreams",
        "outboundStreams",
        "streamReset",
        "appLimited",
        "prMethod",
        "numRequests",
        "messagesToPush",
    };
    return (field >= 0 && field < 12) ? fieldNames[field] : nullptr;
}

int SctpOpenReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localAddresses") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddresses") == 0) return base+1;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fork") == 0) return base+2;
    if (fieldName[0] == 'q' && strcmp(fieldName, "queueClass") == 0) return base+3;
    if (fieldName[0] == 's' && strcmp(fieldName, "sctpAlgorithmClass") == 0) return base+4;
    if (fieldName[0] == 'i' && strcmp(fieldName, "inboundStreams") == 0) return base+5;
    if (fieldName[0] == 'o' && strcmp(fieldName, "outboundStreams") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "streamReset") == 0) return base+7;
    if (fieldName[0] == 'a' && strcmp(fieldName, "appLimited") == 0) return base+8;
    if (fieldName[0] == 'p' && strcmp(fieldName, "prMethod") == 0) return base+9;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numRequests") == 0) return base+10;
    if (fieldName[0] == 'm' && strcmp(fieldName, "messagesToPush") == 0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpOpenReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::AddressVector",    // FIELD_localAddresses
        "inet::AddressVector",    // FIELD_remoteAddresses
        "bool",    // FIELD_fork
        "string",    // FIELD_queueClass
        "string",    // FIELD_sctpAlgorithmClass
        "uint32",    // FIELD_inboundStreams
        "uint32",    // FIELD_outboundStreams
        "bool",    // FIELD_streamReset
        "bool",    // FIELD_appLimited
        "int",    // FIELD_prMethod
        "uint32",    // FIELD_numRequests
        "uint32",    // FIELD_messagesToPush
    };
    return (field >= 0 && field < 12) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpOpenReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpOpenReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpOpenReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpOpenReq *pp = (SctpOpenReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpOpenReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpOpenReq *pp = (SctpOpenReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpOpenReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpOpenReq *pp = (SctpOpenReq *)object; (void)pp;
    switch (field) {
        case FIELD_localAddresses: {std::stringstream out; out << pp->getLocalAddresses(); return out.str();}
        case FIELD_remoteAddresses: {std::stringstream out; out << pp->getRemoteAddresses(); return out.str();}
        case FIELD_fork: return bool2string(pp->getFork());
        case FIELD_queueClass: return oppstring2string(pp->getQueueClass());
        case FIELD_sctpAlgorithmClass: return oppstring2string(pp->getSctpAlgorithmClass());
        case FIELD_inboundStreams: return ulong2string(pp->getInboundStreams());
        case FIELD_outboundStreams: return ulong2string(pp->getOutboundStreams());
        case FIELD_streamReset: return bool2string(pp->getStreamReset());
        case FIELD_appLimited: return bool2string(pp->getAppLimited());
        case FIELD_prMethod: return long2string(pp->getPrMethod());
        case FIELD_numRequests: return ulong2string(pp->getNumRequests());
        case FIELD_messagesToPush: return ulong2string(pp->getMessagesToPush());
        default: return "";
    }
}

bool SctpOpenReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpOpenReq *pp = (SctpOpenReq *)object; (void)pp;
    switch (field) {
        case FIELD_fork: pp->setFork(string2bool(value)); return true;
        case FIELD_queueClass: pp->setQueueClass((value)); return true;
        case FIELD_sctpAlgorithmClass: pp->setSctpAlgorithmClass((value)); return true;
        case FIELD_inboundStreams: pp->setInboundStreams(string2ulong(value)); return true;
        case FIELD_outboundStreams: pp->setOutboundStreams(string2ulong(value)); return true;
        case FIELD_streamReset: pp->setStreamReset(string2bool(value)); return true;
        case FIELD_appLimited: pp->setAppLimited(string2bool(value)); return true;
        case FIELD_prMethod: pp->setPrMethod(string2long(value)); return true;
        case FIELD_numRequests: pp->setNumRequests(string2ulong(value)); return true;
        case FIELD_messagesToPush: pp->setMessagesToPush(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpOpenReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_localAddresses: return omnetpp::opp_typename(typeid(AddressVector));
        case FIELD_remoteAddresses: return omnetpp::opp_typename(typeid(AddressVector));
        default: return nullptr;
    };
}

void *SctpOpenReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpOpenReq *pp = (SctpOpenReq *)object; (void)pp;
    switch (field) {
        case FIELD_localAddresses: return toVoidPtr(&pp->getLocalAddresses()); break;
        case FIELD_remoteAddresses: return toVoidPtr(&pp->getRemoteAddresses()); break;
        default: return nullptr;
    }
}

Register_Class(SctpAvailableReq)

SctpAvailableReq::SctpAvailableReq() : ::inet::SctpCommandReq()
{
}

SctpAvailableReq::SctpAvailableReq(const SctpAvailableReq& other) : ::inet::SctpCommandReq(other)
{
    copy(other);
}

SctpAvailableReq::~SctpAvailableReq()
{
}

SctpAvailableReq& SctpAvailableReq::operator=(const SctpAvailableReq& other)
{
    if (this == &other) return *this;
    ::inet::SctpCommandReq::operator=(other);
    copy(other);
    return *this;
}

void SctpAvailableReq::copy(const SctpAvailableReq& other)
{
    this->newSocketId = other.newSocketId;
}

void SctpAvailableReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SctpCommandReq::parsimPack(b);
    doParsimPacking(b,this->newSocketId);
}

void SctpAvailableReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SctpCommandReq::parsimUnpack(b);
    doParsimUnpacking(b,this->newSocketId);
}

int SctpAvailableReq::getNewSocketId() const
{
    return this->newSocketId;
}

void SctpAvailableReq::setNewSocketId(int newSocketId)
{
    this->newSocketId = newSocketId;
}

class SctpAvailableReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_newSocketId,
    };
  public:
    SctpAvailableReqDescriptor();
    virtual ~SctpAvailableReqDescriptor();

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

Register_ClassDescriptor(SctpAvailableReqDescriptor)

SctpAvailableReqDescriptor::SctpAvailableReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpAvailableReq)), "inet::SctpCommandReq")
{
    propertynames = nullptr;
}

SctpAvailableReqDescriptor::~SctpAvailableReqDescriptor()
{
    delete[] propertynames;
}

bool SctpAvailableReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpAvailableReq *>(obj)!=nullptr;
}

const char **SctpAvailableReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpAvailableReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpAvailableReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SctpAvailableReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_newSocketId
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SctpAvailableReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "newSocketId",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SctpAvailableReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "newSocketId") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpAvailableReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_newSocketId
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpAvailableReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpAvailableReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpAvailableReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpAvailableReq *pp = (SctpAvailableReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpAvailableReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAvailableReq *pp = (SctpAvailableReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpAvailableReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpAvailableReq *pp = (SctpAvailableReq *)object; (void)pp;
    switch (field) {
        case FIELD_newSocketId: return long2string(pp->getNewSocketId());
        default: return "";
    }
}

bool SctpAvailableReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpAvailableReq *pp = (SctpAvailableReq *)object; (void)pp;
    switch (field) {
        case FIELD_newSocketId: pp->setNewSocketId(string2long(value)); return true;
        default: return false;
    }
}

const char *SctpAvailableReqDescriptor::getFieldStructName(int field) const
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

void *SctpAvailableReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpAvailableReq *pp = (SctpAvailableReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpConnectReq)

SctpConnectReq::SctpConnectReq() : ::inet::SctpCommandReq()
{
}

SctpConnectReq::SctpConnectReq(const SctpConnectReq& other) : ::inet::SctpCommandReq(other)
{
    copy(other);
}

SctpConnectReq::~SctpConnectReq()
{
}

SctpConnectReq& SctpConnectReq::operator=(const SctpConnectReq& other)
{
    if (this == &other) return *this;
    ::inet::SctpCommandReq::operator=(other);
    copy(other);
    return *this;
}

void SctpConnectReq::copy(const SctpConnectReq& other)
{
    this->remoteAddresses = other.remoteAddresses;
    this->status = other.status;
    this->inboundStreams = other.inboundStreams;
    this->outboundStreams = other.outboundStreams;
}

void SctpConnectReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SctpCommandReq::parsimPack(b);
    doParsimPacking(b,this->remoteAddresses);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->inboundStreams);
    doParsimPacking(b,this->outboundStreams);
}

void SctpConnectReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SctpCommandReq::parsimUnpack(b);
    doParsimUnpacking(b,this->remoteAddresses);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->inboundStreams);
    doParsimUnpacking(b,this->outboundStreams);
}

const AddressVector& SctpConnectReq::getRemoteAddresses() const
{
    return this->remoteAddresses;
}

void SctpConnectReq::setRemoteAddresses(const AddressVector& remoteAddresses)
{
    this->remoteAddresses = remoteAddresses;
}

int SctpConnectReq::getStatus() const
{
    return this->status;
}

void SctpConnectReq::setStatus(int status)
{
    this->status = status;
}

int SctpConnectReq::getInboundStreams() const
{
    return this->inboundStreams;
}

void SctpConnectReq::setInboundStreams(int inboundStreams)
{
    this->inboundStreams = inboundStreams;
}

int SctpConnectReq::getOutboundStreams() const
{
    return this->outboundStreams;
}

void SctpConnectReq::setOutboundStreams(int outboundStreams)
{
    this->outboundStreams = outboundStreams;
}

class SctpConnectReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_remoteAddresses,
        FIELD_status,
        FIELD_inboundStreams,
        FIELD_outboundStreams,
    };
  public:
    SctpConnectReqDescriptor();
    virtual ~SctpConnectReqDescriptor();

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

Register_ClassDescriptor(SctpConnectReqDescriptor)

SctpConnectReqDescriptor::SctpConnectReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpConnectReq)), "inet::SctpCommandReq")
{
    propertynames = nullptr;
}

SctpConnectReqDescriptor::~SctpConnectReqDescriptor()
{
    delete[] propertynames;
}

bool SctpConnectReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpConnectReq *>(obj)!=nullptr;
}

const char **SctpConnectReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpConnectReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpConnectReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SctpConnectReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_remoteAddresses
        FD_ISEDITABLE,    // FIELD_status
        FD_ISEDITABLE,    // FIELD_inboundStreams
        FD_ISEDITABLE,    // FIELD_outboundStreams
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SctpConnectReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteAddresses",
        "status",
        "inboundStreams",
        "outboundStreams",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SctpConnectReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddresses") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "status") == 0) return base+1;
    if (fieldName[0] == 'i' && strcmp(fieldName, "inboundStreams") == 0) return base+2;
    if (fieldName[0] == 'o' && strcmp(fieldName, "outboundStreams") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpConnectReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::AddressVector",    // FIELD_remoteAddresses
        "int",    // FIELD_status
        "int",    // FIELD_inboundStreams
        "int",    // FIELD_outboundStreams
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpConnectReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpConnectReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpConnectReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpConnectReq *pp = (SctpConnectReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpConnectReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpConnectReq *pp = (SctpConnectReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpConnectReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpConnectReq *pp = (SctpConnectReq *)object; (void)pp;
    switch (field) {
        case FIELD_remoteAddresses: {std::stringstream out; out << pp->getRemoteAddresses(); return out.str();}
        case FIELD_status: return long2string(pp->getStatus());
        case FIELD_inboundStreams: return long2string(pp->getInboundStreams());
        case FIELD_outboundStreams: return long2string(pp->getOutboundStreams());
        default: return "";
    }
}

bool SctpConnectReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpConnectReq *pp = (SctpConnectReq *)object; (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(string2long(value)); return true;
        case FIELD_inboundStreams: pp->setInboundStreams(string2long(value)); return true;
        case FIELD_outboundStreams: pp->setOutboundStreams(string2long(value)); return true;
        default: return false;
    }
}

const char *SctpConnectReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_remoteAddresses: return omnetpp::opp_typename(typeid(AddressVector));
        default: return nullptr;
    };
}

void *SctpConnectReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpConnectReq *pp = (SctpConnectReq *)object; (void)pp;
    switch (field) {
        case FIELD_remoteAddresses: return toVoidPtr(&pp->getRemoteAddresses()); break;
        default: return nullptr;
    }
}

Register_Class(SctpRcvReq)

SctpRcvReq::SctpRcvReq() : ::inet::SctpCommandReq()
{
}

SctpRcvReq::SctpRcvReq(const SctpRcvReq& other) : ::inet::SctpCommandReq(other)
{
    copy(other);
}

SctpRcvReq::~SctpRcvReq()
{
}

SctpRcvReq& SctpRcvReq::operator=(const SctpRcvReq& other)
{
    if (this == &other) return *this;
    ::inet::SctpCommandReq::operator=(other);
    copy(other);
    return *this;
}

void SctpRcvReq::copy(const SctpRcvReq& other)
{
    this->ppid = other.ppid;
    this->tsn = other.tsn;
    this->cumTsn = other.cumTsn;
}

void SctpRcvReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SctpCommandReq::parsimPack(b);
    doParsimPacking(b,this->ppid);
    doParsimPacking(b,this->tsn);
    doParsimPacking(b,this->cumTsn);
}

void SctpRcvReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SctpCommandReq::parsimUnpack(b);
    doParsimUnpacking(b,this->ppid);
    doParsimUnpacking(b,this->tsn);
    doParsimUnpacking(b,this->cumTsn);
}

uint32_t SctpRcvReq::getPpid() const
{
    return this->ppid;
}

void SctpRcvReq::setPpid(uint32_t ppid)
{
    this->ppid = ppid;
}

uint32_t SctpRcvReq::getTsn() const
{
    return this->tsn;
}

void SctpRcvReq::setTsn(uint32_t tsn)
{
    this->tsn = tsn;
}

uint32_t SctpRcvReq::getCumTsn() const
{
    return this->cumTsn;
}

void SctpRcvReq::setCumTsn(uint32_t cumTsn)
{
    this->cumTsn = cumTsn;
}

class SctpRcvReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_ppid,
        FIELD_tsn,
        FIELD_cumTsn,
    };
  public:
    SctpRcvReqDescriptor();
    virtual ~SctpRcvReqDescriptor();

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

Register_ClassDescriptor(SctpRcvReqDescriptor)

SctpRcvReqDescriptor::SctpRcvReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpRcvReq)), "inet::SctpCommandReq")
{
    propertynames = nullptr;
}

SctpRcvReqDescriptor::~SctpRcvReqDescriptor()
{
    delete[] propertynames;
}

bool SctpRcvReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpRcvReq *>(obj)!=nullptr;
}

const char **SctpRcvReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpRcvReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpRcvReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SctpRcvReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ppid
        FD_ISEDITABLE,    // FIELD_tsn
        FD_ISEDITABLE,    // FIELD_cumTsn
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SctpRcvReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ppid",
        "tsn",
        "cumTsn",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SctpRcvReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "ppid") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tsn") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cumTsn") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpRcvReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_ppid
        "uint32",    // FIELD_tsn
        "uint32",    // FIELD_cumTsn
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpRcvReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpRcvReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpRcvReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpRcvReq *pp = (SctpRcvReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpRcvReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpRcvReq *pp = (SctpRcvReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpRcvReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpRcvReq *pp = (SctpRcvReq *)object; (void)pp;
    switch (field) {
        case FIELD_ppid: return ulong2string(pp->getPpid());
        case FIELD_tsn: return ulong2string(pp->getTsn());
        case FIELD_cumTsn: return ulong2string(pp->getCumTsn());
        default: return "";
    }
}

bool SctpRcvReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpRcvReq *pp = (SctpRcvReq *)object; (void)pp;
    switch (field) {
        case FIELD_ppid: pp->setPpid(string2ulong(value)); return true;
        case FIELD_tsn: pp->setTsn(string2ulong(value)); return true;
        case FIELD_cumTsn: pp->setCumTsn(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpRcvReqDescriptor::getFieldStructName(int field) const
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

void *SctpRcvReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpRcvReq *pp = (SctpRcvReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpStatusReq)

SctpStatusReq::SctpStatusReq() : ::inet::SctpCommandReq()
{
}

SctpStatusReq::SctpStatusReq(const SctpStatusReq& other) : ::inet::SctpCommandReq(other)
{
    copy(other);
}

SctpStatusReq::~SctpStatusReq()
{
}

SctpStatusReq& SctpStatusReq::operator=(const SctpStatusReq& other)
{
    if (this == &other) return *this;
    ::inet::SctpCommandReq::operator=(other);
    copy(other);
    return *this;
}

void SctpStatusReq::copy(const SctpStatusReq& other)
{
    this->state = other.state;
    this->stateName = other.stateName;
    this->pathId = other.pathId;
    this->active = other.active;
}

void SctpStatusReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SctpCommandReq::parsimPack(b);
    doParsimPacking(b,this->state);
    doParsimPacking(b,this->stateName);
    doParsimPacking(b,this->pathId);
    doParsimPacking(b,this->active);
}

void SctpStatusReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SctpCommandReq::parsimUnpack(b);
    doParsimUnpacking(b,this->state);
    doParsimUnpacking(b,this->stateName);
    doParsimUnpacking(b,this->pathId);
    doParsimUnpacking(b,this->active);
}

int SctpStatusReq::getState() const
{
    return this->state;
}

void SctpStatusReq::setState(int state)
{
    this->state = state;
}

const char * SctpStatusReq::getStateName() const
{
    return this->stateName.c_str();
}

void SctpStatusReq::setStateName(const char * stateName)
{
    this->stateName = stateName;
}

const L3Address& SctpStatusReq::getPathId() const
{
    return this->pathId;
}

void SctpStatusReq::setPathId(const L3Address& pathId)
{
    this->pathId = pathId;
}

bool SctpStatusReq::getActive() const
{
    return this->active;
}

void SctpStatusReq::setActive(bool active)
{
    this->active = active;
}

class SctpStatusReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_state,
        FIELD_stateName,
        FIELD_pathId,
        FIELD_active,
    };
  public:
    SctpStatusReqDescriptor();
    virtual ~SctpStatusReqDescriptor();

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

Register_ClassDescriptor(SctpStatusReqDescriptor)

SctpStatusReqDescriptor::SctpStatusReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpStatusReq)), "inet::SctpCommandReq")
{
    propertynames = nullptr;
}

SctpStatusReqDescriptor::~SctpStatusReqDescriptor()
{
    delete[] propertynames;
}

bool SctpStatusReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpStatusReq *>(obj)!=nullptr;
}

const char **SctpStatusReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpStatusReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpStatusReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SctpStatusReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_state
        FD_ISEDITABLE,    // FIELD_stateName
        0,    // FIELD_pathId
        FD_ISEDITABLE,    // FIELD_active
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SctpStatusReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "state",
        "stateName",
        "pathId",
        "active",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SctpStatusReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "state") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "stateName") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pathId") == 0) return base+2;
    if (fieldName[0] == 'a' && strcmp(fieldName, "active") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpStatusReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_state
        "string",    // FIELD_stateName
        "inet::L3Address",    // FIELD_pathId
        "bool",    // FIELD_active
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpStatusReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpStatusReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpStatusReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpStatusReq *pp = (SctpStatusReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpStatusReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpStatusReq *pp = (SctpStatusReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpStatusReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpStatusReq *pp = (SctpStatusReq *)object; (void)pp;
    switch (field) {
        case FIELD_state: return long2string(pp->getState());
        case FIELD_stateName: return oppstring2string(pp->getStateName());
        case FIELD_pathId: return pp->getPathId().str();
        case FIELD_active: return bool2string(pp->getActive());
        default: return "";
    }
}

bool SctpStatusReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpStatusReq *pp = (SctpStatusReq *)object; (void)pp;
    switch (field) {
        case FIELD_state: pp->setState(string2long(value)); return true;
        case FIELD_stateName: pp->setStateName((value)); return true;
        case FIELD_active: pp->setActive(string2bool(value)); return true;
        default: return false;
    }
}

const char *SctpStatusReqDescriptor::getFieldStructName(int field) const
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

void *SctpStatusReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpStatusReq *pp = (SctpStatusReq *)object; (void)pp;
    switch (field) {
        case FIELD_pathId: return toVoidPtr(&pp->getPathId()); break;
        default: return nullptr;
    }
}

Register_Class(SctpResetReq)

SctpResetReq::SctpResetReq() : ::inet::SctpCommandReq()
{
}

SctpResetReq::SctpResetReq(const SctpResetReq& other) : ::inet::SctpCommandReq(other)
{
    copy(other);
}

SctpResetReq::~SctpResetReq()
{
    delete [] this->streams;
}

SctpResetReq& SctpResetReq::operator=(const SctpResetReq& other)
{
    if (this == &other) return *this;
    ::inet::SctpCommandReq::operator=(other);
    copy(other);
    return *this;
}

void SctpResetReq::copy(const SctpResetReq& other)
{
    this->requestType = other.requestType;
    this->instreams = other.instreams;
    this->outstreams = other.outstreams;
    delete [] this->streams;
    this->streams = (other.streams_arraysize==0) ? nullptr : new uint16_t[other.streams_arraysize];
    streams_arraysize = other.streams_arraysize;
    for (size_t i = 0; i < streams_arraysize; i++) {
        this->streams[i] = other.streams[i];
    }
}

void SctpResetReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SctpCommandReq::parsimPack(b);
    doParsimPacking(b,this->requestType);
    doParsimPacking(b,this->instreams);
    doParsimPacking(b,this->outstreams);
    b->pack(streams_arraysize);
    doParsimArrayPacking(b,this->streams,streams_arraysize);
}

void SctpResetReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SctpCommandReq::parsimUnpack(b);
    doParsimUnpacking(b,this->requestType);
    doParsimUnpacking(b,this->instreams);
    doParsimUnpacking(b,this->outstreams);
    delete [] this->streams;
    b->unpack(streams_arraysize);
    if (streams_arraysize == 0) {
        this->streams = nullptr;
    } else {
        this->streams = new uint16_t[streams_arraysize];
        doParsimArrayUnpacking(b,this->streams,streams_arraysize);
    }
}

unsigned short SctpResetReq::getRequestType() const
{
    return this->requestType;
}

void SctpResetReq::setRequestType(unsigned short requestType)
{
    this->requestType = requestType;
}

uint16_t SctpResetReq::getInstreams() const
{
    return this->instreams;
}

void SctpResetReq::setInstreams(uint16_t instreams)
{
    this->instreams = instreams;
}

uint16_t SctpResetReq::getOutstreams() const
{
    return this->outstreams;
}

void SctpResetReq::setOutstreams(uint16_t outstreams)
{
    this->outstreams = outstreams;
}

size_t SctpResetReq::getStreamsArraySize() const
{
    return streams_arraysize;
}

uint16_t SctpResetReq::getStreams(size_t k) const
{
    if (k >= streams_arraysize) throw omnetpp::cRuntimeError("Array of size streams_arraysize indexed by %lu", (unsigned long)k);
    return this->streams[k];
}

void SctpResetReq::setStreamsArraySize(size_t newSize)
{
    uint16_t *streams2 = (newSize==0) ? nullptr : new uint16_t[newSize];
    size_t minSize = streams_arraysize < newSize ? streams_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        streams2[i] = this->streams[i];
    for (size_t i = minSize; i < newSize; i++)
        streams2[i] = 0;
    delete [] this->streams;
    this->streams = streams2;
    streams_arraysize = newSize;
}

void SctpResetReq::setStreams(size_t k, uint16_t streams)
{
    if (k >= streams_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->streams[k] = streams;
}

void SctpResetReq::insertStreams(size_t k, uint16_t streams)
{
    if (k > streams_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = streams_arraysize + 1;
    uint16_t *streams2 = new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        streams2[i] = this->streams[i];
    streams2[k] = streams;
    for (i = k + 1; i < newSize; i++)
        streams2[i] = this->streams[i-1];
    delete [] this->streams;
    this->streams = streams2;
    streams_arraysize = newSize;
}

void SctpResetReq::insertStreams(uint16_t streams)
{
    insertStreams(streams_arraysize, streams);
}

void SctpResetReq::eraseStreams(size_t k)
{
    if (k >= streams_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = streams_arraysize - 1;
    uint16_t *streams2 = (newSize == 0) ? nullptr : new uint16_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        streams2[i] = this->streams[i];
    for (i = k; i < newSize; i++)
        streams2[i] = this->streams[i+1];
    delete [] this->streams;
    this->streams = streams2;
    streams_arraysize = newSize;
}

class SctpResetReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_requestType,
        FIELD_instreams,
        FIELD_outstreams,
        FIELD_streams,
    };
  public:
    SctpResetReqDescriptor();
    virtual ~SctpResetReqDescriptor();

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

Register_ClassDescriptor(SctpResetReqDescriptor)

SctpResetReqDescriptor::SctpResetReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpResetReq)), "inet::SctpCommandReq")
{
    propertynames = nullptr;
}

SctpResetReqDescriptor::~SctpResetReqDescriptor()
{
    delete[] propertynames;
}

bool SctpResetReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpResetReq *>(obj)!=nullptr;
}

const char **SctpResetReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpResetReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpResetReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SctpResetReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_requestType
        FD_ISEDITABLE,    // FIELD_instreams
        FD_ISEDITABLE,    // FIELD_outstreams
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_streams
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SctpResetReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "requestType",
        "instreams",
        "outstreams",
        "streams",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SctpResetReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "requestType") == 0) return base+0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "instreams") == 0) return base+1;
    if (fieldName[0] == 'o' && strcmp(fieldName, "outstreams") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "streams") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpResetReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_requestType
        "uint16",    // FIELD_instreams
        "uint16",    // FIELD_outstreams
        "uint16",    // FIELD_streams
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpResetReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpResetReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpResetReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpResetReq *pp = (SctpResetReq *)object; (void)pp;
    switch (field) {
        case FIELD_streams: return pp->getStreamsArraySize();
        default: return 0;
    }
}

const char *SctpResetReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpResetReq *pp = (SctpResetReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpResetReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpResetReq *pp = (SctpResetReq *)object; (void)pp;
    switch (field) {
        case FIELD_requestType: return ulong2string(pp->getRequestType());
        case FIELD_instreams: return ulong2string(pp->getInstreams());
        case FIELD_outstreams: return ulong2string(pp->getOutstreams());
        case FIELD_streams: return ulong2string(pp->getStreams(i));
        default: return "";
    }
}

bool SctpResetReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpResetReq *pp = (SctpResetReq *)object; (void)pp;
    switch (field) {
        case FIELD_requestType: pp->setRequestType(string2ulong(value)); return true;
        case FIELD_instreams: pp->setInstreams(string2ulong(value)); return true;
        case FIELD_outstreams: pp->setOutstreams(string2ulong(value)); return true;
        case FIELD_streams: pp->setStreams(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SctpResetReqDescriptor::getFieldStructName(int field) const
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

void *SctpResetReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpResetReq *pp = (SctpResetReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpInfoReq)

SctpInfoReq::SctpInfoReq() : ::inet::SctpCommandReq()
{
}

SctpInfoReq::SctpInfoReq(const SctpInfoReq& other) : ::inet::SctpCommandReq(other)
{
    copy(other);
}

SctpInfoReq::~SctpInfoReq()
{
}

SctpInfoReq& SctpInfoReq::operator=(const SctpInfoReq& other)
{
    if (this == &other) return *this;
    ::inet::SctpCommandReq::operator=(other);
    copy(other);
    return *this;
}

void SctpInfoReq::copy(const SctpInfoReq& other)
{
    this->text = other.text;
}

void SctpInfoReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SctpCommandReq::parsimPack(b);
    doParsimPacking(b,this->text);
}

void SctpInfoReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SctpCommandReq::parsimUnpack(b);
    doParsimUnpacking(b,this->text);
}

int SctpInfoReq::getText() const
{
    return this->text;
}

void SctpInfoReq::setText(int text)
{
    this->text = text;
}

class SctpInfoReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_text,
    };
  public:
    SctpInfoReqDescriptor();
    virtual ~SctpInfoReqDescriptor();

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

Register_ClassDescriptor(SctpInfoReqDescriptor)

SctpInfoReqDescriptor::SctpInfoReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpInfoReq)), "inet::SctpCommandReq")
{
    propertynames = nullptr;
}

SctpInfoReqDescriptor::~SctpInfoReqDescriptor()
{
    delete[] propertynames;
}

bool SctpInfoReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpInfoReq *>(obj)!=nullptr;
}

const char **SctpInfoReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpInfoReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpInfoReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SctpInfoReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_text
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SctpInfoReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "text",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SctpInfoReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "text") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpInfoReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_text
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpInfoReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpInfoReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpInfoReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpInfoReq *pp = (SctpInfoReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpInfoReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpInfoReq *pp = (SctpInfoReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpInfoReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpInfoReq *pp = (SctpInfoReq *)object; (void)pp;
    switch (field) {
        case FIELD_text: return long2string(pp->getText());
        default: return "";
    }
}

bool SctpInfoReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpInfoReq *pp = (SctpInfoReq *)object; (void)pp;
    switch (field) {
        case FIELD_text: pp->setText(string2long(value)); return true;
        default: return false;
    }
}

const char *SctpInfoReqDescriptor::getFieldStructName(int field) const
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

void *SctpInfoReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpInfoReq *pp = (SctpInfoReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpPathInfoReq)

SctpPathInfoReq::SctpPathInfoReq() : ::inet::SctpCommandReq()
{
}

SctpPathInfoReq::SctpPathInfoReq(const SctpPathInfoReq& other) : ::inet::SctpCommandReq(other)
{
    copy(other);
}

SctpPathInfoReq::~SctpPathInfoReq()
{
}

SctpPathInfoReq& SctpPathInfoReq::operator=(const SctpPathInfoReq& other)
{
    if (this == &other) return *this;
    ::inet::SctpCommandReq::operator=(other);
    copy(other);
    return *this;
}

void SctpPathInfoReq::copy(const SctpPathInfoReq& other)
{
    this->remoteAddress = other.remoteAddress;
}

void SctpPathInfoReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SctpCommandReq::parsimPack(b);
    doParsimPacking(b,this->remoteAddress);
}

void SctpPathInfoReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SctpCommandReq::parsimUnpack(b);
    doParsimUnpacking(b,this->remoteAddress);
}

const L3Address& SctpPathInfoReq::getRemoteAddress() const
{
    return this->remoteAddress;
}

void SctpPathInfoReq::setRemoteAddress(const L3Address& remoteAddress)
{
    this->remoteAddress = remoteAddress;
}

class SctpPathInfoReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_remoteAddress,
    };
  public:
    SctpPathInfoReqDescriptor();
    virtual ~SctpPathInfoReqDescriptor();

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

Register_ClassDescriptor(SctpPathInfoReqDescriptor)

SctpPathInfoReqDescriptor::SctpPathInfoReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpPathInfoReq)), "inet::SctpCommandReq")
{
    propertynames = nullptr;
}

SctpPathInfoReqDescriptor::~SctpPathInfoReqDescriptor()
{
    delete[] propertynames;
}

bool SctpPathInfoReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpPathInfoReq *>(obj)!=nullptr;
}

const char **SctpPathInfoReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpPathInfoReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpPathInfoReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SctpPathInfoReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_remoteAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SctpPathInfoReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SctpPathInfoReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddress") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpPathInfoReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_remoteAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpPathInfoReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpPathInfoReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpPathInfoReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpPathInfoReq *pp = (SctpPathInfoReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpPathInfoReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpPathInfoReq *pp = (SctpPathInfoReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpPathInfoReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpPathInfoReq *pp = (SctpPathInfoReq *)object; (void)pp;
    switch (field) {
        case FIELD_remoteAddress: return pp->getRemoteAddress().str();
        default: return "";
    }
}

bool SctpPathInfoReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpPathInfoReq *pp = (SctpPathInfoReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SctpPathInfoReqDescriptor::getFieldStructName(int field) const
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

void *SctpPathInfoReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpPathInfoReq *pp = (SctpPathInfoReq *)object; (void)pp;
    switch (field) {
        case FIELD_remoteAddress: return toVoidPtr(&pp->getRemoteAddress()); break;
        default: return nullptr;
    }
}

Register_Class(SctpRtoReq)

SctpRtoReq::SctpRtoReq() : ::inet::SctpCommandReq()
{
}

SctpRtoReq::SctpRtoReq(const SctpRtoReq& other) : ::inet::SctpCommandReq(other)
{
    copy(other);
}

SctpRtoReq::~SctpRtoReq()
{
}

SctpRtoReq& SctpRtoReq::operator=(const SctpRtoReq& other)
{
    if (this == &other) return *this;
    ::inet::SctpCommandReq::operator=(other);
    copy(other);
    return *this;
}

void SctpRtoReq::copy(const SctpRtoReq& other)
{
    this->rtoInitial = other.rtoInitial;
    this->rtoMin = other.rtoMin;
    this->rtoMax = other.rtoMax;
}

void SctpRtoReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SctpCommandReq::parsimPack(b);
    doParsimPacking(b,this->rtoInitial);
    doParsimPacking(b,this->rtoMin);
    doParsimPacking(b,this->rtoMax);
}

void SctpRtoReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SctpCommandReq::parsimUnpack(b);
    doParsimUnpacking(b,this->rtoInitial);
    doParsimUnpacking(b,this->rtoMin);
    doParsimUnpacking(b,this->rtoMax);
}

double SctpRtoReq::getRtoInitial() const
{
    return this->rtoInitial;
}

void SctpRtoReq::setRtoInitial(double rtoInitial)
{
    this->rtoInitial = rtoInitial;
}

double SctpRtoReq::getRtoMin() const
{
    return this->rtoMin;
}

void SctpRtoReq::setRtoMin(double rtoMin)
{
    this->rtoMin = rtoMin;
}

double SctpRtoReq::getRtoMax() const
{
    return this->rtoMax;
}

void SctpRtoReq::setRtoMax(double rtoMax)
{
    this->rtoMax = rtoMax;
}

class SctpRtoReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_rtoInitial,
        FIELD_rtoMin,
        FIELD_rtoMax,
    };
  public:
    SctpRtoReqDescriptor();
    virtual ~SctpRtoReqDescriptor();

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

Register_ClassDescriptor(SctpRtoReqDescriptor)

SctpRtoReqDescriptor::SctpRtoReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpRtoReq)), "inet::SctpCommandReq")
{
    propertynames = nullptr;
}

SctpRtoReqDescriptor::~SctpRtoReqDescriptor()
{
    delete[] propertynames;
}

bool SctpRtoReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpRtoReq *>(obj)!=nullptr;
}

const char **SctpRtoReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpRtoReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpRtoReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SctpRtoReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_rtoInitial
        FD_ISEDITABLE,    // FIELD_rtoMin
        FD_ISEDITABLE,    // FIELD_rtoMax
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SctpRtoReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "rtoInitial",
        "rtoMin",
        "rtoMax",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SctpRtoReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rtoInitial") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rtoMin") == 0) return base+1;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rtoMax") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpRtoReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_rtoInitial
        "double",    // FIELD_rtoMin
        "double",    // FIELD_rtoMax
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpRtoReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpRtoReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpRtoReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpRtoReq *pp = (SctpRtoReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpRtoReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpRtoReq *pp = (SctpRtoReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpRtoReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpRtoReq *pp = (SctpRtoReq *)object; (void)pp;
    switch (field) {
        case FIELD_rtoInitial: return double2string(pp->getRtoInitial());
        case FIELD_rtoMin: return double2string(pp->getRtoMin());
        case FIELD_rtoMax: return double2string(pp->getRtoMax());
        default: return "";
    }
}

bool SctpRtoReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpRtoReq *pp = (SctpRtoReq *)object; (void)pp;
    switch (field) {
        case FIELD_rtoInitial: pp->setRtoInitial(string2double(value)); return true;
        case FIELD_rtoMin: pp->setRtoMin(string2double(value)); return true;
        case FIELD_rtoMax: pp->setRtoMax(string2double(value)); return true;
        default: return false;
    }
}

const char *SctpRtoReqDescriptor::getFieldStructName(int field) const
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

void *SctpRtoReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpRtoReq *pp = (SctpRtoReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpSendQueueAbatedReq)

SctpSendQueueAbatedReq::SctpSendQueueAbatedReq() : ::inet::SctpCommandReq()
{
}

SctpSendQueueAbatedReq::SctpSendQueueAbatedReq(const SctpSendQueueAbatedReq& other) : ::inet::SctpCommandReq(other)
{
    copy(other);
}

SctpSendQueueAbatedReq::~SctpSendQueueAbatedReq()
{
    delete [] this->queuedForStream;
}

SctpSendQueueAbatedReq& SctpSendQueueAbatedReq::operator=(const SctpSendQueueAbatedReq& other)
{
    if (this == &other) return *this;
    ::inet::SctpCommandReq::operator=(other);
    copy(other);
    return *this;
}

void SctpSendQueueAbatedReq::copy(const SctpSendQueueAbatedReq& other)
{
    this->bytesAvailable = other.bytesAvailable;
    this->bytesQueued = other.bytesQueued;
    this->bytesLimit = other.bytesLimit;
    delete [] this->queuedForStream;
    this->queuedForStream = (other.queuedForStream_arraysize==0) ? nullptr : new uint64_t[other.queuedForStream_arraysize];
    queuedForStream_arraysize = other.queuedForStream_arraysize;
    for (size_t i = 0; i < queuedForStream_arraysize; i++) {
        this->queuedForStream[i] = other.queuedForStream[i];
    }
}

void SctpSendQueueAbatedReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SctpCommandReq::parsimPack(b);
    doParsimPacking(b,this->bytesAvailable);
    doParsimPacking(b,this->bytesQueued);
    doParsimPacking(b,this->bytesLimit);
    b->pack(queuedForStream_arraysize);
    doParsimArrayPacking(b,this->queuedForStream,queuedForStream_arraysize);
}

void SctpSendQueueAbatedReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SctpCommandReq::parsimUnpack(b);
    doParsimUnpacking(b,this->bytesAvailable);
    doParsimUnpacking(b,this->bytesQueued);
    doParsimUnpacking(b,this->bytesLimit);
    delete [] this->queuedForStream;
    b->unpack(queuedForStream_arraysize);
    if (queuedForStream_arraysize == 0) {
        this->queuedForStream = nullptr;
    } else {
        this->queuedForStream = new uint64_t[queuedForStream_arraysize];
        doParsimArrayUnpacking(b,this->queuedForStream,queuedForStream_arraysize);
    }
}

uint64_t SctpSendQueueAbatedReq::getBytesAvailable() const
{
    return this->bytesAvailable;
}

void SctpSendQueueAbatedReq::setBytesAvailable(uint64_t bytesAvailable)
{
    this->bytesAvailable = bytesAvailable;
}

uint64_t SctpSendQueueAbatedReq::getBytesQueued() const
{
    return this->bytesQueued;
}

void SctpSendQueueAbatedReq::setBytesQueued(uint64_t bytesQueued)
{
    this->bytesQueued = bytesQueued;
}

uint64_t SctpSendQueueAbatedReq::getBytesLimit() const
{
    return this->bytesLimit;
}

void SctpSendQueueAbatedReq::setBytesLimit(uint64_t bytesLimit)
{
    this->bytesLimit = bytesLimit;
}

size_t SctpSendQueueAbatedReq::getQueuedForStreamArraySize() const
{
    return queuedForStream_arraysize;
}

uint64_t SctpSendQueueAbatedReq::getQueuedForStream(size_t k) const
{
    if (k >= queuedForStream_arraysize) throw omnetpp::cRuntimeError("Array of size queuedForStream_arraysize indexed by %lu", (unsigned long)k);
    return this->queuedForStream[k];
}

void SctpSendQueueAbatedReq::setQueuedForStreamArraySize(size_t newSize)
{
    uint64_t *queuedForStream2 = (newSize==0) ? nullptr : new uint64_t[newSize];
    size_t minSize = queuedForStream_arraysize < newSize ? queuedForStream_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        queuedForStream2[i] = this->queuedForStream[i];
    for (size_t i = minSize; i < newSize; i++)
        queuedForStream2[i] = 0;
    delete [] this->queuedForStream;
    this->queuedForStream = queuedForStream2;
    queuedForStream_arraysize = newSize;
}

void SctpSendQueueAbatedReq::setQueuedForStream(size_t k, uint64_t queuedForStream)
{
    if (k >= queuedForStream_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->queuedForStream[k] = queuedForStream;
}

void SctpSendQueueAbatedReq::insertQueuedForStream(size_t k, uint64_t queuedForStream)
{
    if (k > queuedForStream_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = queuedForStream_arraysize + 1;
    uint64_t *queuedForStream2 = new uint64_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        queuedForStream2[i] = this->queuedForStream[i];
    queuedForStream2[k] = queuedForStream;
    for (i = k + 1; i < newSize; i++)
        queuedForStream2[i] = this->queuedForStream[i-1];
    delete [] this->queuedForStream;
    this->queuedForStream = queuedForStream2;
    queuedForStream_arraysize = newSize;
}

void SctpSendQueueAbatedReq::insertQueuedForStream(uint64_t queuedForStream)
{
    insertQueuedForStream(queuedForStream_arraysize, queuedForStream);
}

void SctpSendQueueAbatedReq::eraseQueuedForStream(size_t k)
{
    if (k >= queuedForStream_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = queuedForStream_arraysize - 1;
    uint64_t *queuedForStream2 = (newSize == 0) ? nullptr : new uint64_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        queuedForStream2[i] = this->queuedForStream[i];
    for (i = k; i < newSize; i++)
        queuedForStream2[i] = this->queuedForStream[i+1];
    delete [] this->queuedForStream;
    this->queuedForStream = queuedForStream2;
    queuedForStream_arraysize = newSize;
}

class SctpSendQueueAbatedReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_bytesAvailable,
        FIELD_bytesQueued,
        FIELD_bytesLimit,
        FIELD_queuedForStream,
    };
  public:
    SctpSendQueueAbatedReqDescriptor();
    virtual ~SctpSendQueueAbatedReqDescriptor();

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

Register_ClassDescriptor(SctpSendQueueAbatedReqDescriptor)

SctpSendQueueAbatedReqDescriptor::SctpSendQueueAbatedReqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpSendQueueAbatedReq)), "inet::SctpCommandReq")
{
    propertynames = nullptr;
}

SctpSendQueueAbatedReqDescriptor::~SctpSendQueueAbatedReqDescriptor()
{
    delete[] propertynames;
}

bool SctpSendQueueAbatedReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpSendQueueAbatedReq *>(obj)!=nullptr;
}

const char **SctpSendQueueAbatedReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpSendQueueAbatedReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpSendQueueAbatedReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SctpSendQueueAbatedReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_bytesAvailable
        FD_ISEDITABLE,    // FIELD_bytesQueued
        FD_ISEDITABLE,    // FIELD_bytesLimit
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_queuedForStream
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SctpSendQueueAbatedReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bytesAvailable",
        "bytesQueued",
        "bytesLimit",
        "queuedForStream",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SctpSendQueueAbatedReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bytesAvailable") == 0) return base+0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bytesQueued") == 0) return base+1;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bytesLimit") == 0) return base+2;
    if (fieldName[0] == 'q' && strcmp(fieldName, "queuedForStream") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpSendQueueAbatedReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64",    // FIELD_bytesAvailable
        "uint64",    // FIELD_bytesQueued
        "uint64",    // FIELD_bytesLimit
        "uint64",    // FIELD_queuedForStream
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpSendQueueAbatedReqDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpSendQueueAbatedReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpSendQueueAbatedReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpSendQueueAbatedReq *pp = (SctpSendQueueAbatedReq *)object; (void)pp;
    switch (field) {
        case FIELD_queuedForStream: return pp->getQueuedForStreamArraySize();
        default: return 0;
    }
}

const char *SctpSendQueueAbatedReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSendQueueAbatedReq *pp = (SctpSendQueueAbatedReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpSendQueueAbatedReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpSendQueueAbatedReq *pp = (SctpSendQueueAbatedReq *)object; (void)pp;
    switch (field) {
        case FIELD_bytesAvailable: return uint642string(pp->getBytesAvailable());
        case FIELD_bytesQueued: return uint642string(pp->getBytesQueued());
        case FIELD_bytesLimit: return uint642string(pp->getBytesLimit());
        case FIELD_queuedForStream: return uint642string(pp->getQueuedForStream(i));
        default: return "";
    }
}

bool SctpSendQueueAbatedReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpSendQueueAbatedReq *pp = (SctpSendQueueAbatedReq *)object; (void)pp;
    switch (field) {
        case FIELD_bytesAvailable: pp->setBytesAvailable(string2uint64(value)); return true;
        case FIELD_bytesQueued: pp->setBytesQueued(string2uint64(value)); return true;
        case FIELD_bytesLimit: pp->setBytesLimit(string2uint64(value)); return true;
        case FIELD_queuedForStream: pp->setQueuedForStream(i,string2uint64(value)); return true;
        default: return false;
    }
}

const char *SctpSendQueueAbatedReqDescriptor::getFieldStructName(int field) const
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

void *SctpSendQueueAbatedReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpSendQueueAbatedReq *pp = (SctpSendQueueAbatedReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SctpPathInfo)

SctpPathInfo::SctpPathInfo(const char *name) : ::omnetpp::cNamedObject(name)
{
}

SctpPathInfo::SctpPathInfo(const SctpPathInfo& other) : ::omnetpp::cNamedObject(other)
{
    copy(other);
}

SctpPathInfo::~SctpPathInfo()
{
}

SctpPathInfo& SctpPathInfo::operator=(const SctpPathInfo& other)
{
    if (this == &other) return *this;
    ::omnetpp::cNamedObject::operator=(other);
    copy(other);
    return *this;
}

void SctpPathInfo::copy(const SctpPathInfo& other)
{
    this->remoteAddress = other.remoteAddress;
}

void SctpPathInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cNamedObject::parsimPack(b);
    doParsimPacking(b,this->remoteAddress);
}

void SctpPathInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cNamedObject::parsimUnpack(b);
    doParsimUnpacking(b,this->remoteAddress);
}

const L3Address& SctpPathInfo::getRemoteAddress() const
{
    return this->remoteAddress;
}

void SctpPathInfo::setRemoteAddress(const L3Address& remoteAddress)
{
    this->remoteAddress = remoteAddress;
}

class SctpPathInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_remoteAddress,
    };
  public:
    SctpPathInfoDescriptor();
    virtual ~SctpPathInfoDescriptor();

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

Register_ClassDescriptor(SctpPathInfoDescriptor)

SctpPathInfoDescriptor::SctpPathInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SctpPathInfo)), "omnetpp::cNamedObject")
{
    propertynames = nullptr;
}

SctpPathInfoDescriptor::~SctpPathInfoDescriptor()
{
    delete[] propertynames;
}

bool SctpPathInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SctpPathInfo *>(obj)!=nullptr;
}

const char **SctpPathInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SctpPathInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SctpPathInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SctpPathInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_remoteAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SctpPathInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SctpPathInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddress") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SctpPathInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_remoteAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SctpPathInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *SctpPathInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SctpPathInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SctpPathInfo *pp = (SctpPathInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SctpPathInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpPathInfo *pp = (SctpPathInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SctpPathInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SctpPathInfo *pp = (SctpPathInfo *)object; (void)pp;
    switch (field) {
        case FIELD_remoteAddress: return pp->getRemoteAddress().str();
        default: return "";
    }
}

bool SctpPathInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SctpPathInfo *pp = (SctpPathInfo *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SctpPathInfoDescriptor::getFieldStructName(int field) const
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

void *SctpPathInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SctpPathInfo *pp = (SctpPathInfo *)object; (void)pp;
    switch (field) {
        case FIELD_remoteAddress: return toVoidPtr(&pp->getRemoteAddress()); break;
        default: return nullptr;
    }
}

} // namespace inet

