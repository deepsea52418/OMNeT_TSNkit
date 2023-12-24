//
// Generated file, do not edit! Created by nedtool 5.6 from inet/networklayer/xmipv6/MobilityHeader.msg.
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
#include "MobilityHeader_m.h"

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

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::MobilityHeaderType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::MobilityHeaderType"));
    e->insert(BINDING_REFRESH_REQUEST, "BINDING_REFRESH_REQUEST");
    e->insert(HOME_TEST_INIT, "HOME_TEST_INIT");
    e->insert(CARE_OF_TEST_INIT, "CARE_OF_TEST_INIT");
    e->insert(HOME_TEST, "HOME_TEST");
    e->insert(CARE_OF_TEST, "CARE_OF_TEST");
    e->insert(BINDING_UPDATE, "BINDING_UPDATE");
    e->insert(BINDING_ACKNOWLEDGEMENT, "BINDING_ACKNOWLEDGEMENT");
    e->insert(BINDING_ERROR, "BINDING_ERROR");
)

Register_Class(MobilityHeader)

MobilityHeader::MobilityHeader() : ::inet::FieldsChunk()
{
}

MobilityHeader::MobilityHeader(const MobilityHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

MobilityHeader::~MobilityHeader()
{
}

MobilityHeader& MobilityHeader::operator=(const MobilityHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void MobilityHeader::copy(const MobilityHeader& other)
{
    this->mobilityHeaderType = other.mobilityHeaderType;
}

void MobilityHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->mobilityHeaderType);
}

void MobilityHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->mobilityHeaderType);
}

inet::MobilityHeaderType MobilityHeader::getMobilityHeaderType() const
{
    return this->mobilityHeaderType;
}

void MobilityHeader::setMobilityHeaderType(inet::MobilityHeaderType mobilityHeaderType)
{
    handleChange();
    this->mobilityHeaderType = mobilityHeaderType;
}

class MobilityHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_mobilityHeaderType,
    };
  public:
    MobilityHeaderDescriptor();
    virtual ~MobilityHeaderDescriptor();

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

Register_ClassDescriptor(MobilityHeaderDescriptor)

MobilityHeaderDescriptor::MobilityHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::MobilityHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

MobilityHeaderDescriptor::~MobilityHeaderDescriptor()
{
    delete[] propertynames;
}

bool MobilityHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MobilityHeader *>(obj)!=nullptr;
}

const char **MobilityHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MobilityHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MobilityHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int MobilityHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_mobilityHeaderType
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MobilityHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "mobilityHeaderType",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MobilityHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "mobilityHeaderType") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MobilityHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MobilityHeaderType",    // FIELD_mobilityHeaderType
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MobilityHeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_mobilityHeaderType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MobilityHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_mobilityHeaderType:
            if (!strcmp(propertyname, "enum")) return "inet::MobilityHeaderType";
            return nullptr;
        default: return nullptr;
    }
}

int MobilityHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MobilityHeader *pp = (MobilityHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MobilityHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MobilityHeader *pp = (MobilityHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MobilityHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MobilityHeader *pp = (MobilityHeader *)object; (void)pp;
    switch (field) {
        case FIELD_mobilityHeaderType: return enum2string(pp->getMobilityHeaderType(), "inet::MobilityHeaderType");
        default: return "";
    }
}

bool MobilityHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MobilityHeader *pp = (MobilityHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MobilityHeaderDescriptor::getFieldStructName(int field) const
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

void *MobilityHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MobilityHeader *pp = (MobilityHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(BindingUpdate)

BindingUpdate::BindingUpdate() : ::inet::MobilityHeader()
{
}

BindingUpdate::BindingUpdate(const BindingUpdate& other) : ::inet::MobilityHeader(other)
{
    copy(other);
}

BindingUpdate::~BindingUpdate()
{
}

BindingUpdate& BindingUpdate::operator=(const BindingUpdate& other)
{
    if (this == &other) return *this;
    ::inet::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void BindingUpdate::copy(const BindingUpdate& other)
{
    this->lifetime = other.lifetime;
    this->sequence = other.sequence;
    this->ackFlag = other.ackFlag;
    this->homeRegistrationFlag = other.homeRegistrationFlag;
    this->linkLocalAddressCompatibilityFlag = other.linkLocalAddressCompatibilityFlag;
    this->keyManagementFlag = other.keyManagementFlag;
    this->homeAddressMN = other.homeAddressMN;
    this->bindingAuthorizationData = other.bindingAuthorizationData;
}

void BindingUpdate::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::MobilityHeader::parsimPack(b);
    doParsimPacking(b,this->lifetime);
    doParsimPacking(b,this->sequence);
    doParsimPacking(b,this->ackFlag);
    doParsimPacking(b,this->homeRegistrationFlag);
    doParsimPacking(b,this->linkLocalAddressCompatibilityFlag);
    doParsimPacking(b,this->keyManagementFlag);
    doParsimPacking(b,this->homeAddressMN);
    doParsimPacking(b,this->bindingAuthorizationData);
}

void BindingUpdate::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::MobilityHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->lifetime);
    doParsimUnpacking(b,this->sequence);
    doParsimUnpacking(b,this->ackFlag);
    doParsimUnpacking(b,this->homeRegistrationFlag);
    doParsimUnpacking(b,this->linkLocalAddressCompatibilityFlag);
    doParsimUnpacking(b,this->keyManagementFlag);
    doParsimUnpacking(b,this->homeAddressMN);
    doParsimUnpacking(b,this->bindingAuthorizationData);
}

unsigned int BindingUpdate::getLifetime() const
{
    return this->lifetime;
}

void BindingUpdate::setLifetime(unsigned int lifetime)
{
    handleChange();
    this->lifetime = lifetime;
}

unsigned int BindingUpdate::getSequence() const
{
    return this->sequence;
}

void BindingUpdate::setSequence(unsigned int sequence)
{
    handleChange();
    this->sequence = sequence;
}

bool BindingUpdate::getAckFlag() const
{
    return this->ackFlag;
}

void BindingUpdate::setAckFlag(bool ackFlag)
{
    handleChange();
    this->ackFlag = ackFlag;
}

bool BindingUpdate::getHomeRegistrationFlag() const
{
    return this->homeRegistrationFlag;
}

void BindingUpdate::setHomeRegistrationFlag(bool homeRegistrationFlag)
{
    handleChange();
    this->homeRegistrationFlag = homeRegistrationFlag;
}

bool BindingUpdate::getLinkLocalAddressCompatibilityFlag() const
{
    return this->linkLocalAddressCompatibilityFlag;
}

void BindingUpdate::setLinkLocalAddressCompatibilityFlag(bool linkLocalAddressCompatibilityFlag)
{
    handleChange();
    this->linkLocalAddressCompatibilityFlag = linkLocalAddressCompatibilityFlag;
}

bool BindingUpdate::getKeyManagementFlag() const
{
    return this->keyManagementFlag;
}

void BindingUpdate::setKeyManagementFlag(bool keyManagementFlag)
{
    handleChange();
    this->keyManagementFlag = keyManagementFlag;
}

const Ipv6Address& BindingUpdate::getHomeAddressMN() const
{
    return this->homeAddressMN;
}

void BindingUpdate::setHomeAddressMN(const Ipv6Address& homeAddressMN)
{
    handleChange();
    this->homeAddressMN = homeAddressMN;
}

int BindingUpdate::getBindingAuthorizationData() const
{
    return this->bindingAuthorizationData;
}

void BindingUpdate::setBindingAuthorizationData(int bindingAuthorizationData)
{
    handleChange();
    this->bindingAuthorizationData = bindingAuthorizationData;
}

class BindingUpdateDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_lifetime,
        FIELD_sequence,
        FIELD_ackFlag,
        FIELD_homeRegistrationFlag,
        FIELD_linkLocalAddressCompatibilityFlag,
        FIELD_keyManagementFlag,
        FIELD_homeAddressMN,
        FIELD_bindingAuthorizationData,
    };
  public:
    BindingUpdateDescriptor();
    virtual ~BindingUpdateDescriptor();

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

Register_ClassDescriptor(BindingUpdateDescriptor)

BindingUpdateDescriptor::BindingUpdateDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::BindingUpdate)), "inet::MobilityHeader")
{
    propertynames = nullptr;
}

BindingUpdateDescriptor::~BindingUpdateDescriptor()
{
    delete[] propertynames;
}

bool BindingUpdateDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BindingUpdate *>(obj)!=nullptr;
}

const char **BindingUpdateDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BindingUpdateDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BindingUpdateDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int BindingUpdateDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_lifetime
        FD_ISEDITABLE,    // FIELD_sequence
        FD_ISEDITABLE,    // FIELD_ackFlag
        FD_ISEDITABLE,    // FIELD_homeRegistrationFlag
        FD_ISEDITABLE,    // FIELD_linkLocalAddressCompatibilityFlag
        FD_ISEDITABLE,    // FIELD_keyManagementFlag
        0,    // FIELD_homeAddressMN
        FD_ISEDITABLE,    // FIELD_bindingAuthorizationData
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *BindingUpdateDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lifetime",
        "sequence",
        "ackFlag",
        "homeRegistrationFlag",
        "linkLocalAddressCompatibilityFlag",
        "keyManagementFlag",
        "homeAddressMN",
        "bindingAuthorizationData",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int BindingUpdateDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lifetime") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sequence") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "ackFlag") == 0) return base+2;
    if (fieldName[0] == 'h' && strcmp(fieldName, "homeRegistrationFlag") == 0) return base+3;
    if (fieldName[0] == 'l' && strcmp(fieldName, "linkLocalAddressCompatibilityFlag") == 0) return base+4;
    if (fieldName[0] == 'k' && strcmp(fieldName, "keyManagementFlag") == 0) return base+5;
    if (fieldName[0] == 'h' && strcmp(fieldName, "homeAddressMN") == 0) return base+6;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bindingAuthorizationData") == 0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BindingUpdateDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_lifetime
        "unsigned int",    // FIELD_sequence
        "bool",    // FIELD_ackFlag
        "bool",    // FIELD_homeRegistrationFlag
        "bool",    // FIELD_linkLocalAddressCompatibilityFlag
        "bool",    // FIELD_keyManagementFlag
        "inet::Ipv6Address",    // FIELD_homeAddressMN
        "int",    // FIELD_bindingAuthorizationData
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **BindingUpdateDescriptor::getFieldPropertyNames(int field) const
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

const char *BindingUpdateDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BindingUpdateDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BindingUpdate *pp = (BindingUpdate *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BindingUpdateDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BindingUpdate *pp = (BindingUpdate *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BindingUpdateDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BindingUpdate *pp = (BindingUpdate *)object; (void)pp;
    switch (field) {
        case FIELD_lifetime: return ulong2string(pp->getLifetime());
        case FIELD_sequence: return ulong2string(pp->getSequence());
        case FIELD_ackFlag: return bool2string(pp->getAckFlag());
        case FIELD_homeRegistrationFlag: return bool2string(pp->getHomeRegistrationFlag());
        case FIELD_linkLocalAddressCompatibilityFlag: return bool2string(pp->getLinkLocalAddressCompatibilityFlag());
        case FIELD_keyManagementFlag: return bool2string(pp->getKeyManagementFlag());
        case FIELD_homeAddressMN: return pp->getHomeAddressMN().str();
        case FIELD_bindingAuthorizationData: return long2string(pp->getBindingAuthorizationData());
        default: return "";
    }
}

bool BindingUpdateDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BindingUpdate *pp = (BindingUpdate *)object; (void)pp;
    switch (field) {
        case FIELD_lifetime: pp->setLifetime(string2ulong(value)); return true;
        case FIELD_sequence: pp->setSequence(string2ulong(value)); return true;
        case FIELD_ackFlag: pp->setAckFlag(string2bool(value)); return true;
        case FIELD_homeRegistrationFlag: pp->setHomeRegistrationFlag(string2bool(value)); return true;
        case FIELD_linkLocalAddressCompatibilityFlag: pp->setLinkLocalAddressCompatibilityFlag(string2bool(value)); return true;
        case FIELD_keyManagementFlag: pp->setKeyManagementFlag(string2bool(value)); return true;
        case FIELD_bindingAuthorizationData: pp->setBindingAuthorizationData(string2long(value)); return true;
        default: return false;
    }
}

const char *BindingUpdateDescriptor::getFieldStructName(int field) const
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

void *BindingUpdateDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BindingUpdate *pp = (BindingUpdate *)object; (void)pp;
    switch (field) {
        case FIELD_homeAddressMN: return toVoidPtr(&pp->getHomeAddressMN()); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::BaStatus");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::BaStatus"));
    e->insert(BINDING_UPDATE_ACCEPTED, "BINDING_UPDATE_ACCEPTED");
    e->insert(BU_ACCEPT_BUT_DISCOVER_PREFIX, "BU_ACCEPT_BUT_DISCOVER_PREFIX");
    e->insert(REASON_UNSPECIFIED, "REASON_UNSPECIFIED");
    e->insert(ADMINISTRATIVELY_PROHIBITED, "ADMINISTRATIVELY_PROHIBITED");
    e->insert(INSUFFICIENT_RESOURCES, "INSUFFICIENT_RESOURCES");
    e->insert(HOME_REGISTRATION_NOT_SUPPORTED, "HOME_REGISTRATION_NOT_SUPPORTED");
    e->insert(NOT_HOME_SUBNET, "NOT_HOME_SUBNET");
    e->insert(NOT_HA_FOR_THIS_MN, "NOT_HA_FOR_THIS_MN");
    e->insert(DAD_FAILED, "DAD_FAILED");
    e->insert(SEQUENCE_NUMBER_OUT_OF_WINDOW, "SEQUENCE_NUMBER_OUT_OF_WINDOW");
    e->insert(EXPIRED_HOME_NONCE_INDEX, "EXPIRED_HOME_NONCE_INDEX");
    e->insert(EXPIRED_CARE_OF_NONCE_INDEX, "EXPIRED_CARE_OF_NONCE_INDEX");
    e->insert(EXPIRED_NONCES, "EXPIRED_NONCES");
    e->insert(REGISTRATION_TYPE_CHANGE_DISALLOWED, "REGISTRATION_TYPE_CHANGE_DISALLOWED");
)

Register_Class(BindingAcknowledgement)

BindingAcknowledgement::BindingAcknowledgement() : ::inet::MobilityHeader()
{
}

BindingAcknowledgement::BindingAcknowledgement(const BindingAcknowledgement& other) : ::inet::MobilityHeader(other)
{
    copy(other);
}

BindingAcknowledgement::~BindingAcknowledgement()
{
}

BindingAcknowledgement& BindingAcknowledgement::operator=(const BindingAcknowledgement& other)
{
    if (this == &other) return *this;
    ::inet::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void BindingAcknowledgement::copy(const BindingAcknowledgement& other)
{
    this->status = other.status;
    this->sequenceNumber = other.sequenceNumber;
    this->lifetime = other.lifetime;
    this->keyManagementFlag = other.keyManagementFlag;
    this->bindingAuthorizationData = other.bindingAuthorizationData;
}

void BindingAcknowledgement::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::MobilityHeader::parsimPack(b);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->lifetime);
    doParsimPacking(b,this->keyManagementFlag);
    doParsimPacking(b,this->bindingAuthorizationData);
}

void BindingAcknowledgement::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::MobilityHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->lifetime);
    doParsimUnpacking(b,this->keyManagementFlag);
    doParsimUnpacking(b,this->bindingAuthorizationData);
}

inet::BaStatus BindingAcknowledgement::getStatus() const
{
    return this->status;
}

void BindingAcknowledgement::setStatus(inet::BaStatus status)
{
    handleChange();
    this->status = status;
}

unsigned int BindingAcknowledgement::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void BindingAcknowledgement::setSequenceNumber(unsigned int sequenceNumber)
{
    handleChange();
    this->sequenceNumber = sequenceNumber;
}

unsigned int BindingAcknowledgement::getLifetime() const
{
    return this->lifetime;
}

void BindingAcknowledgement::setLifetime(unsigned int lifetime)
{
    handleChange();
    this->lifetime = lifetime;
}

bool BindingAcknowledgement::getKeyManagementFlag() const
{
    return this->keyManagementFlag;
}

void BindingAcknowledgement::setKeyManagementFlag(bool keyManagementFlag)
{
    handleChange();
    this->keyManagementFlag = keyManagementFlag;
}

int BindingAcknowledgement::getBindingAuthorizationData() const
{
    return this->bindingAuthorizationData;
}

void BindingAcknowledgement::setBindingAuthorizationData(int bindingAuthorizationData)
{
    handleChange();
    this->bindingAuthorizationData = bindingAuthorizationData;
}

class BindingAcknowledgementDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_status,
        FIELD_sequenceNumber,
        FIELD_lifetime,
        FIELD_keyManagementFlag,
        FIELD_bindingAuthorizationData,
    };
  public:
    BindingAcknowledgementDescriptor();
    virtual ~BindingAcknowledgementDescriptor();

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

Register_ClassDescriptor(BindingAcknowledgementDescriptor)

BindingAcknowledgementDescriptor::BindingAcknowledgementDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::BindingAcknowledgement)), "inet::MobilityHeader")
{
    propertynames = nullptr;
}

BindingAcknowledgementDescriptor::~BindingAcknowledgementDescriptor()
{
    delete[] propertynames;
}

bool BindingAcknowledgementDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BindingAcknowledgement *>(obj)!=nullptr;
}

const char **BindingAcknowledgementDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BindingAcknowledgementDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BindingAcknowledgementDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int BindingAcknowledgementDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_status
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISEDITABLE,    // FIELD_lifetime
        FD_ISEDITABLE,    // FIELD_keyManagementFlag
        FD_ISEDITABLE,    // FIELD_bindingAuthorizationData
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *BindingAcknowledgementDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
        "sequenceNumber",
        "lifetime",
        "keyManagementFlag",
        "bindingAuthorizationData",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int BindingAcknowledgementDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "status") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sequenceNumber") == 0) return base+1;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lifetime") == 0) return base+2;
    if (fieldName[0] == 'k' && strcmp(fieldName, "keyManagementFlag") == 0) return base+3;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bindingAuthorizationData") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BindingAcknowledgementDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::BaStatus",    // FIELD_status
        "unsigned int",    // FIELD_sequenceNumber
        "unsigned int",    // FIELD_lifetime
        "bool",    // FIELD_keyManagementFlag
        "int",    // FIELD_bindingAuthorizationData
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **BindingAcknowledgementDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *BindingAcknowledgementDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyname, "enum")) return "inet::BaStatus";
            return nullptr;
        default: return nullptr;
    }
}

int BindingAcknowledgementDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BindingAcknowledgement *pp = (BindingAcknowledgement *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BindingAcknowledgementDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BindingAcknowledgement *pp = (BindingAcknowledgement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BindingAcknowledgementDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BindingAcknowledgement *pp = (BindingAcknowledgement *)object; (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "inet::BaStatus");
        case FIELD_sequenceNumber: return ulong2string(pp->getSequenceNumber());
        case FIELD_lifetime: return ulong2string(pp->getLifetime());
        case FIELD_keyManagementFlag: return bool2string(pp->getKeyManagementFlag());
        case FIELD_bindingAuthorizationData: return long2string(pp->getBindingAuthorizationData());
        default: return "";
    }
}

bool BindingAcknowledgementDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BindingAcknowledgement *pp = (BindingAcknowledgement *)object; (void)pp;
    switch (field) {
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2ulong(value)); return true;
        case FIELD_lifetime: pp->setLifetime(string2ulong(value)); return true;
        case FIELD_keyManagementFlag: pp->setKeyManagementFlag(string2bool(value)); return true;
        case FIELD_bindingAuthorizationData: pp->setBindingAuthorizationData(string2long(value)); return true;
        default: return false;
    }
}

const char *BindingAcknowledgementDescriptor::getFieldStructName(int field) const
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

void *BindingAcknowledgementDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BindingAcknowledgement *pp = (BindingAcknowledgement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::BeStatus");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::BeStatus"));
    e->insert(UNKNOWN_BINDING_FOR_HOME_ADDRESS_DEST_OPTION, "UNKNOWN_BINDING_FOR_HOME_ADDRESS_DEST_OPTION");
    e->insert(UNKNOWN_MH_TYPE, "UNKNOWN_MH_TYPE");
)

Register_Class(BindingError)

BindingError::BindingError() : ::inet::MobilityHeader()
{
}

BindingError::BindingError(const BindingError& other) : ::inet::MobilityHeader(other)
{
    copy(other);
}

BindingError::~BindingError()
{
}

BindingError& BindingError::operator=(const BindingError& other)
{
    if (this == &other) return *this;
    ::inet::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void BindingError::copy(const BindingError& other)
{
    this->status = other.status;
    this->homeAddress = other.homeAddress;
}

void BindingError::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::MobilityHeader::parsimPack(b);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->homeAddress);
}

void BindingError::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::MobilityHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->homeAddress);
}

inet::BeStatus BindingError::getStatus() const
{
    return this->status;
}

void BindingError::setStatus(inet::BeStatus status)
{
    handleChange();
    this->status = status;
}

const Ipv6Address& BindingError::getHomeAddress() const
{
    return this->homeAddress;
}

void BindingError::setHomeAddress(const Ipv6Address& homeAddress)
{
    handleChange();
    this->homeAddress = homeAddress;
}

class BindingErrorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_status,
        FIELD_homeAddress,
    };
  public:
    BindingErrorDescriptor();
    virtual ~BindingErrorDescriptor();

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

Register_ClassDescriptor(BindingErrorDescriptor)

BindingErrorDescriptor::BindingErrorDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::BindingError)), "inet::MobilityHeader")
{
    propertynames = nullptr;
}

BindingErrorDescriptor::~BindingErrorDescriptor()
{
    delete[] propertynames;
}

bool BindingErrorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BindingError *>(obj)!=nullptr;
}

const char **BindingErrorDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BindingErrorDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BindingErrorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BindingErrorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_status
        0,    // FIELD_homeAddress
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *BindingErrorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
        "homeAddress",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int BindingErrorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "status") == 0) return base+0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "homeAddress") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BindingErrorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::BeStatus",    // FIELD_status
        "inet::Ipv6Address",    // FIELD_homeAddress
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **BindingErrorDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *BindingErrorDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyname, "enum")) return "inet::BeStatus";
            return nullptr;
        default: return nullptr;
    }
}

int BindingErrorDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BindingError *pp = (BindingError *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BindingErrorDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BindingError *pp = (BindingError *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BindingErrorDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BindingError *pp = (BindingError *)object; (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "inet::BeStatus");
        case FIELD_homeAddress: return pp->getHomeAddress().str();
        default: return "";
    }
}

bool BindingErrorDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BindingError *pp = (BindingError *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BindingErrorDescriptor::getFieldStructName(int field) const
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

void *BindingErrorDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BindingError *pp = (BindingError *)object; (void)pp;
    switch (field) {
        case FIELD_homeAddress: return toVoidPtr(&pp->getHomeAddress()); break;
        default: return nullptr;
    }
}

Register_Class(HomeTestInit)

HomeTestInit::HomeTestInit() : ::inet::MobilityHeader()
{
}

HomeTestInit::HomeTestInit(const HomeTestInit& other) : ::inet::MobilityHeader(other)
{
    copy(other);
}

HomeTestInit::~HomeTestInit()
{
}

HomeTestInit& HomeTestInit::operator=(const HomeTestInit& other)
{
    if (this == &other) return *this;
    ::inet::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void HomeTestInit::copy(const HomeTestInit& other)
{
    this->homeInitCookie = other.homeInitCookie;
}

void HomeTestInit::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::MobilityHeader::parsimPack(b);
    doParsimPacking(b,this->homeInitCookie);
}

void HomeTestInit::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::MobilityHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->homeInitCookie);
}

unsigned int HomeTestInit::getHomeInitCookie() const
{
    return this->homeInitCookie;
}

void HomeTestInit::setHomeInitCookie(unsigned int homeInitCookie)
{
    handleChange();
    this->homeInitCookie = homeInitCookie;
}

class HomeTestInitDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_homeInitCookie,
    };
  public:
    HomeTestInitDescriptor();
    virtual ~HomeTestInitDescriptor();

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

Register_ClassDescriptor(HomeTestInitDescriptor)

HomeTestInitDescriptor::HomeTestInitDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::HomeTestInit)), "inet::MobilityHeader")
{
    propertynames = nullptr;
}

HomeTestInitDescriptor::~HomeTestInitDescriptor()
{
    delete[] propertynames;
}

bool HomeTestInitDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HomeTestInit *>(obj)!=nullptr;
}

const char **HomeTestInitDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HomeTestInitDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HomeTestInitDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int HomeTestInitDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_homeInitCookie
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *HomeTestInitDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "homeInitCookie",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int HomeTestInitDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "homeInitCookie") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HomeTestInitDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_homeInitCookie
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **HomeTestInitDescriptor::getFieldPropertyNames(int field) const
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

const char *HomeTestInitDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int HomeTestInitDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    HomeTestInit *pp = (HomeTestInit *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *HomeTestInitDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HomeTestInit *pp = (HomeTestInit *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HomeTestInitDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HomeTestInit *pp = (HomeTestInit *)object; (void)pp;
    switch (field) {
        case FIELD_homeInitCookie: return ulong2string(pp->getHomeInitCookie());
        default: return "";
    }
}

bool HomeTestInitDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    HomeTestInit *pp = (HomeTestInit *)object; (void)pp;
    switch (field) {
        case FIELD_homeInitCookie: pp->setHomeInitCookie(string2ulong(value)); return true;
        default: return false;
    }
}

const char *HomeTestInitDescriptor::getFieldStructName(int field) const
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

void *HomeTestInitDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    HomeTestInit *pp = (HomeTestInit *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(HomeTest)

HomeTest::HomeTest() : ::inet::MobilityHeader()
{
}

HomeTest::HomeTest(const HomeTest& other) : ::inet::MobilityHeader(other)
{
    copy(other);
}

HomeTest::~HomeTest()
{
}

HomeTest& HomeTest::operator=(const HomeTest& other)
{
    if (this == &other) return *this;
    ::inet::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void HomeTest::copy(const HomeTest& other)
{
    this->homeInitCookie = other.homeInitCookie;
    this->homeKeyGenToken = other.homeKeyGenToken;
}

void HomeTest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::MobilityHeader::parsimPack(b);
    doParsimPacking(b,this->homeInitCookie);
    doParsimPacking(b,this->homeKeyGenToken);
}

void HomeTest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::MobilityHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->homeInitCookie);
    doParsimUnpacking(b,this->homeKeyGenToken);
}

unsigned int HomeTest::getHomeInitCookie() const
{
    return this->homeInitCookie;
}

void HomeTest::setHomeInitCookie(unsigned int homeInitCookie)
{
    handleChange();
    this->homeInitCookie = homeInitCookie;
}

unsigned int HomeTest::getHomeKeyGenToken() const
{
    return this->homeKeyGenToken;
}

void HomeTest::setHomeKeyGenToken(unsigned int homeKeyGenToken)
{
    handleChange();
    this->homeKeyGenToken = homeKeyGenToken;
}

class HomeTestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_homeInitCookie,
        FIELD_homeKeyGenToken,
    };
  public:
    HomeTestDescriptor();
    virtual ~HomeTestDescriptor();

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

Register_ClassDescriptor(HomeTestDescriptor)

HomeTestDescriptor::HomeTestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::HomeTest)), "inet::MobilityHeader")
{
    propertynames = nullptr;
}

HomeTestDescriptor::~HomeTestDescriptor()
{
    delete[] propertynames;
}

bool HomeTestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HomeTest *>(obj)!=nullptr;
}

const char **HomeTestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HomeTestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HomeTestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int HomeTestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_homeInitCookie
        FD_ISEDITABLE,    // FIELD_homeKeyGenToken
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *HomeTestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "homeInitCookie",
        "homeKeyGenToken",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int HomeTestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "homeInitCookie") == 0) return base+0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "homeKeyGenToken") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HomeTestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_homeInitCookie
        "unsigned int",    // FIELD_homeKeyGenToken
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **HomeTestDescriptor::getFieldPropertyNames(int field) const
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

const char *HomeTestDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int HomeTestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    HomeTest *pp = (HomeTest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *HomeTestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HomeTest *pp = (HomeTest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HomeTestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HomeTest *pp = (HomeTest *)object; (void)pp;
    switch (field) {
        case FIELD_homeInitCookie: return ulong2string(pp->getHomeInitCookie());
        case FIELD_homeKeyGenToken: return ulong2string(pp->getHomeKeyGenToken());
        default: return "";
    }
}

bool HomeTestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    HomeTest *pp = (HomeTest *)object; (void)pp;
    switch (field) {
        case FIELD_homeInitCookie: pp->setHomeInitCookie(string2ulong(value)); return true;
        case FIELD_homeKeyGenToken: pp->setHomeKeyGenToken(string2ulong(value)); return true;
        default: return false;
    }
}

const char *HomeTestDescriptor::getFieldStructName(int field) const
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

void *HomeTestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    HomeTest *pp = (HomeTest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CareOfTestInit)

CareOfTestInit::CareOfTestInit() : ::inet::MobilityHeader()
{
}

CareOfTestInit::CareOfTestInit(const CareOfTestInit& other) : ::inet::MobilityHeader(other)
{
    copy(other);
}

CareOfTestInit::~CareOfTestInit()
{
}

CareOfTestInit& CareOfTestInit::operator=(const CareOfTestInit& other)
{
    if (this == &other) return *this;
    ::inet::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void CareOfTestInit::copy(const CareOfTestInit& other)
{
    this->careOfInitCookie = other.careOfInitCookie;
}

void CareOfTestInit::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::MobilityHeader::parsimPack(b);
    doParsimPacking(b,this->careOfInitCookie);
}

void CareOfTestInit::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::MobilityHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->careOfInitCookie);
}

unsigned int CareOfTestInit::getCareOfInitCookie() const
{
    return this->careOfInitCookie;
}

void CareOfTestInit::setCareOfInitCookie(unsigned int careOfInitCookie)
{
    handleChange();
    this->careOfInitCookie = careOfInitCookie;
}

class CareOfTestInitDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_careOfInitCookie,
    };
  public:
    CareOfTestInitDescriptor();
    virtual ~CareOfTestInitDescriptor();

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

Register_ClassDescriptor(CareOfTestInitDescriptor)

CareOfTestInitDescriptor::CareOfTestInitDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::CareOfTestInit)), "inet::MobilityHeader")
{
    propertynames = nullptr;
}

CareOfTestInitDescriptor::~CareOfTestInitDescriptor()
{
    delete[] propertynames;
}

bool CareOfTestInitDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CareOfTestInit *>(obj)!=nullptr;
}

const char **CareOfTestInitDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CareOfTestInitDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CareOfTestInitDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int CareOfTestInitDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_careOfInitCookie
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *CareOfTestInitDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "careOfInitCookie",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int CareOfTestInitDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "careOfInitCookie") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CareOfTestInitDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_careOfInitCookie
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **CareOfTestInitDescriptor::getFieldPropertyNames(int field) const
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

const char *CareOfTestInitDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int CareOfTestInitDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CareOfTestInit *pp = (CareOfTestInit *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *CareOfTestInitDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CareOfTestInit *pp = (CareOfTestInit *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CareOfTestInitDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CareOfTestInit *pp = (CareOfTestInit *)object; (void)pp;
    switch (field) {
        case FIELD_careOfInitCookie: return ulong2string(pp->getCareOfInitCookie());
        default: return "";
    }
}

bool CareOfTestInitDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CareOfTestInit *pp = (CareOfTestInit *)object; (void)pp;
    switch (field) {
        case FIELD_careOfInitCookie: pp->setCareOfInitCookie(string2ulong(value)); return true;
        default: return false;
    }
}

const char *CareOfTestInitDescriptor::getFieldStructName(int field) const
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

void *CareOfTestInitDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CareOfTestInit *pp = (CareOfTestInit *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CareOfTest)

CareOfTest::CareOfTest() : ::inet::MobilityHeader()
{
}

CareOfTest::CareOfTest(const CareOfTest& other) : ::inet::MobilityHeader(other)
{
    copy(other);
}

CareOfTest::~CareOfTest()
{
}

CareOfTest& CareOfTest::operator=(const CareOfTest& other)
{
    if (this == &other) return *this;
    ::inet::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void CareOfTest::copy(const CareOfTest& other)
{
    this->careOfInitCookie = other.careOfInitCookie;
    this->careOfKeyGenToken = other.careOfKeyGenToken;
}

void CareOfTest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::MobilityHeader::parsimPack(b);
    doParsimPacking(b,this->careOfInitCookie);
    doParsimPacking(b,this->careOfKeyGenToken);
}

void CareOfTest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::MobilityHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->careOfInitCookie);
    doParsimUnpacking(b,this->careOfKeyGenToken);
}

unsigned int CareOfTest::getCareOfInitCookie() const
{
    return this->careOfInitCookie;
}

void CareOfTest::setCareOfInitCookie(unsigned int careOfInitCookie)
{
    handleChange();
    this->careOfInitCookie = careOfInitCookie;
}

unsigned int CareOfTest::getCareOfKeyGenToken() const
{
    return this->careOfKeyGenToken;
}

void CareOfTest::setCareOfKeyGenToken(unsigned int careOfKeyGenToken)
{
    handleChange();
    this->careOfKeyGenToken = careOfKeyGenToken;
}

class CareOfTestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_careOfInitCookie,
        FIELD_careOfKeyGenToken,
    };
  public:
    CareOfTestDescriptor();
    virtual ~CareOfTestDescriptor();

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

Register_ClassDescriptor(CareOfTestDescriptor)

CareOfTestDescriptor::CareOfTestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::CareOfTest)), "inet::MobilityHeader")
{
    propertynames = nullptr;
}

CareOfTestDescriptor::~CareOfTestDescriptor()
{
    delete[] propertynames;
}

bool CareOfTestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CareOfTest *>(obj)!=nullptr;
}

const char **CareOfTestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CareOfTestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CareOfTestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int CareOfTestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_careOfInitCookie
        FD_ISEDITABLE,    // FIELD_careOfKeyGenToken
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *CareOfTestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "careOfInitCookie",
        "careOfKeyGenToken",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int CareOfTestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "careOfInitCookie") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "careOfKeyGenToken") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CareOfTestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_careOfInitCookie
        "unsigned int",    // FIELD_careOfKeyGenToken
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **CareOfTestDescriptor::getFieldPropertyNames(int field) const
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

const char *CareOfTestDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int CareOfTestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CareOfTest *pp = (CareOfTest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *CareOfTestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CareOfTest *pp = (CareOfTest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CareOfTestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CareOfTest *pp = (CareOfTest *)object; (void)pp;
    switch (field) {
        case FIELD_careOfInitCookie: return ulong2string(pp->getCareOfInitCookie());
        case FIELD_careOfKeyGenToken: return ulong2string(pp->getCareOfKeyGenToken());
        default: return "";
    }
}

bool CareOfTestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CareOfTest *pp = (CareOfTest *)object; (void)pp;
    switch (field) {
        case FIELD_careOfInitCookie: pp->setCareOfInitCookie(string2ulong(value)); return true;
        case FIELD_careOfKeyGenToken: pp->setCareOfKeyGenToken(string2ulong(value)); return true;
        default: return false;
    }
}

const char *CareOfTestDescriptor::getFieldStructName(int field) const
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

void *CareOfTestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CareOfTest *pp = (CareOfTest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(BindingRefreshRequest)

BindingRefreshRequest::BindingRefreshRequest() : ::inet::MobilityHeader()
{
}

BindingRefreshRequest::BindingRefreshRequest(const BindingRefreshRequest& other) : ::inet::MobilityHeader(other)
{
    copy(other);
}

BindingRefreshRequest::~BindingRefreshRequest()
{
}

BindingRefreshRequest& BindingRefreshRequest::operator=(const BindingRefreshRequest& other)
{
    if (this == &other) return *this;
    ::inet::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void BindingRefreshRequest::copy(const BindingRefreshRequest& other)
{
}

void BindingRefreshRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::MobilityHeader::parsimPack(b);
}

void BindingRefreshRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::MobilityHeader::parsimUnpack(b);
}

class BindingRefreshRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    BindingRefreshRequestDescriptor();
    virtual ~BindingRefreshRequestDescriptor();

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

Register_ClassDescriptor(BindingRefreshRequestDescriptor)

BindingRefreshRequestDescriptor::BindingRefreshRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::BindingRefreshRequest)), "inet::MobilityHeader")
{
    propertynames = nullptr;
}

BindingRefreshRequestDescriptor::~BindingRefreshRequestDescriptor()
{
    delete[] propertynames;
}

bool BindingRefreshRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BindingRefreshRequest *>(obj)!=nullptr;
}

const char **BindingRefreshRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BindingRefreshRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BindingRefreshRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int BindingRefreshRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *BindingRefreshRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int BindingRefreshRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BindingRefreshRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **BindingRefreshRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *BindingRefreshRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BindingRefreshRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BindingRefreshRequest *pp = (BindingRefreshRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BindingRefreshRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BindingRefreshRequest *pp = (BindingRefreshRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BindingRefreshRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BindingRefreshRequest *pp = (BindingRefreshRequest *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool BindingRefreshRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BindingRefreshRequest *pp = (BindingRefreshRequest *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BindingRefreshRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *BindingRefreshRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BindingRefreshRequest *pp = (BindingRefreshRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(HomeAddressOption)

HomeAddressOption::HomeAddressOption() : ::inet::Ipv6DestinationOptionsHeader()
{
}

HomeAddressOption::HomeAddressOption(const HomeAddressOption& other) : ::inet::Ipv6DestinationOptionsHeader(other)
{
    copy(other);
}

HomeAddressOption::~HomeAddressOption()
{
}

HomeAddressOption& HomeAddressOption::operator=(const HomeAddressOption& other)
{
    if (this == &other) return *this;
    ::inet::Ipv6DestinationOptionsHeader::operator=(other);
    copy(other);
    return *this;
}

void HomeAddressOption::copy(const HomeAddressOption& other)
{
    this->homeAddress = other.homeAddress;
}

void HomeAddressOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Ipv6DestinationOptionsHeader::parsimPack(b);
    doParsimPacking(b,this->homeAddress);
}

void HomeAddressOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Ipv6DestinationOptionsHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->homeAddress);
}

const Ipv6Address& HomeAddressOption::getHomeAddress() const
{
    return this->homeAddress;
}

void HomeAddressOption::setHomeAddress(const Ipv6Address& homeAddress)
{
    this->homeAddress = homeAddress;
}

class HomeAddressOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_homeAddress,
    };
  public:
    HomeAddressOptionDescriptor();
    virtual ~HomeAddressOptionDescriptor();

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

Register_ClassDescriptor(HomeAddressOptionDescriptor)

HomeAddressOptionDescriptor::HomeAddressOptionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::HomeAddressOption)), "inet::Ipv6DestinationOptionsHeader")
{
    propertynames = nullptr;
}

HomeAddressOptionDescriptor::~HomeAddressOptionDescriptor()
{
    delete[] propertynames;
}

bool HomeAddressOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HomeAddressOption *>(obj)!=nullptr;
}

const char **HomeAddressOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HomeAddressOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HomeAddressOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int HomeAddressOptionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_homeAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *HomeAddressOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "homeAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int HomeAddressOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "homeAddress") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HomeAddressOptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv6Address",    // FIELD_homeAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **HomeAddressOptionDescriptor::getFieldPropertyNames(int field) const
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

const char *HomeAddressOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int HomeAddressOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    HomeAddressOption *pp = (HomeAddressOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *HomeAddressOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HomeAddressOption *pp = (HomeAddressOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HomeAddressOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HomeAddressOption *pp = (HomeAddressOption *)object; (void)pp;
    switch (field) {
        case FIELD_homeAddress: return pp->getHomeAddress().str();
        default: return "";
    }
}

bool HomeAddressOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    HomeAddressOption *pp = (HomeAddressOption *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *HomeAddressOptionDescriptor::getFieldStructName(int field) const
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

void *HomeAddressOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    HomeAddressOption *pp = (HomeAddressOption *)object; (void)pp;
    switch (field) {
        case FIELD_homeAddress: return toVoidPtr(&pp->getHomeAddress()); break;
        default: return nullptr;
    }
}

} // namespace inet

