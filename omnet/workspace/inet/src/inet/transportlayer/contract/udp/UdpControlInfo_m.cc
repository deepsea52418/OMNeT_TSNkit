//
// Generated file, do not edit! Created by nedtool 5.6 from inet/transportlayer/contract/udp/UdpControlInfo.msg.
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
#include "UdpControlInfo_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::UdpCommandCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::UdpCommandCode"));
    e->insert(UDP_C_DATA, "UDP_C_DATA");
    e->insert(UDP_C_BIND, "UDP_C_BIND");
    e->insert(UDP_C_CONNECT, "UDP_C_CONNECT");
    e->insert(UDP_C_SETOPTION, "UDP_C_SETOPTION");
    e->insert(UDP_C_CLOSE, "UDP_C_CLOSE");
    e->insert(UDP_C_DESTROY, "UDP_C_DESTROY");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::UdpStatusInd");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::UdpStatusInd"));
    e->insert(UDP_I_DATA, "UDP_I_DATA");
    e->insert(UDP_I_ERROR, "UDP_I_ERROR");
    e->insert(UDP_I_SOCKET_CLOSED, "UDP_I_SOCKET_CLOSED");
)

Register_Class(UdpControlInfo)

UdpControlInfo::UdpControlInfo() : ::omnetpp::cObject()
{
}

UdpControlInfo::UdpControlInfo(const UdpControlInfo& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

UdpControlInfo::~UdpControlInfo()
{
}

UdpControlInfo& UdpControlInfo::operator=(const UdpControlInfo& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void UdpControlInfo::copy(const UdpControlInfo& other)
{
}

void UdpControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
}

void UdpControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
}

class UdpControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    UdpControlInfoDescriptor();
    virtual ~UdpControlInfoDescriptor();

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

Register_ClassDescriptor(UdpControlInfoDescriptor)

UdpControlInfoDescriptor::UdpControlInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpControlInfo)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

UdpControlInfoDescriptor::~UdpControlInfoDescriptor()
{
    delete[] propertynames;
}

bool UdpControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpControlInfo *>(obj)!=nullptr;
}

const char **UdpControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpControlInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int UdpControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *UdpControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int UdpControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **UdpControlInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpControlInfo *pp = (UdpControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpControlInfo *pp = (UdpControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpControlInfo *pp = (UdpControlInfo *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool UdpControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpControlInfo *pp = (UdpControlInfo *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *UdpControlInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *UdpControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpControlInfo *pp = (UdpControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UdpBindCommand)

UdpBindCommand::UdpBindCommand() : ::inet::UdpControlInfo()
{
}

UdpBindCommand::UdpBindCommand(const UdpBindCommand& other) : ::inet::UdpControlInfo(other)
{
    copy(other);
}

UdpBindCommand::~UdpBindCommand()
{
}

UdpBindCommand& UdpBindCommand::operator=(const UdpBindCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UdpBindCommand::copy(const UdpBindCommand& other)
{
    this->localAddr = other.localAddr;
    this->localPort = other.localPort;
}

void UdpBindCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpControlInfo::parsimPack(b);
    doParsimPacking(b,this->localAddr);
    doParsimPacking(b,this->localPort);
}

void UdpBindCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->localAddr);
    doParsimUnpacking(b,this->localPort);
}

const L3Address& UdpBindCommand::getLocalAddr() const
{
    return this->localAddr;
}

void UdpBindCommand::setLocalAddr(const L3Address& localAddr)
{
    this->localAddr = localAddr;
}

int UdpBindCommand::getLocalPort() const
{
    return this->localPort;
}

void UdpBindCommand::setLocalPort(int localPort)
{
    this->localPort = localPort;
}

class UdpBindCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_localAddr,
        FIELD_localPort,
    };
  public:
    UdpBindCommandDescriptor();
    virtual ~UdpBindCommandDescriptor();

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

Register_ClassDescriptor(UdpBindCommandDescriptor)

UdpBindCommandDescriptor::UdpBindCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpBindCommand)), "inet::UdpControlInfo")
{
    propertynames = nullptr;
}

UdpBindCommandDescriptor::~UdpBindCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpBindCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpBindCommand *>(obj)!=nullptr;
}

const char **UdpBindCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpBindCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpBindCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int UdpBindCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_localAddr
        FD_ISEDITABLE,    // FIELD_localPort
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *UdpBindCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "localAddr",
        "localPort",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int UdpBindCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localAddr") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localPort") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpBindCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_localAddr
        "int",    // FIELD_localPort
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpBindCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpBindCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpBindCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpBindCommand *pp = (UdpBindCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpBindCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpBindCommand *pp = (UdpBindCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpBindCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpBindCommand *pp = (UdpBindCommand *)object; (void)pp;
    switch (field) {
        case FIELD_localAddr: return pp->getLocalAddr().str();
        case FIELD_localPort: return long2string(pp->getLocalPort());
        default: return "";
    }
}

bool UdpBindCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpBindCommand *pp = (UdpBindCommand *)object; (void)pp;
    switch (field) {
        case FIELD_localPort: pp->setLocalPort(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpBindCommandDescriptor::getFieldStructName(int field) const
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

void *UdpBindCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpBindCommand *pp = (UdpBindCommand *)object; (void)pp;
    switch (field) {
        case FIELD_localAddr: return toVoidPtr(&pp->getLocalAddr()); break;
        default: return nullptr;
    }
}

Register_Class(UdpConnectCommand)

UdpConnectCommand::UdpConnectCommand() : ::inet::UdpControlInfo()
{
}

UdpConnectCommand::UdpConnectCommand(const UdpConnectCommand& other) : ::inet::UdpControlInfo(other)
{
    copy(other);
}

UdpConnectCommand::~UdpConnectCommand()
{
}

UdpConnectCommand& UdpConnectCommand::operator=(const UdpConnectCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UdpConnectCommand::copy(const UdpConnectCommand& other)
{
    this->remoteAddr = other.remoteAddr;
    this->remotePort = other.remotePort;
}

void UdpConnectCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpControlInfo::parsimPack(b);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->remotePort);
}

void UdpConnectCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->remotePort);
}

const L3Address& UdpConnectCommand::getRemoteAddr() const
{
    return this->remoteAddr;
}

void UdpConnectCommand::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

int UdpConnectCommand::getRemotePort() const
{
    return this->remotePort;
}

void UdpConnectCommand::setRemotePort(int remotePort)
{
    this->remotePort = remotePort;
}

class UdpConnectCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_remoteAddr,
        FIELD_remotePort,
    };
  public:
    UdpConnectCommandDescriptor();
    virtual ~UdpConnectCommandDescriptor();

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

Register_ClassDescriptor(UdpConnectCommandDescriptor)

UdpConnectCommandDescriptor::UdpConnectCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpConnectCommand)), "inet::UdpControlInfo")
{
    propertynames = nullptr;
}

UdpConnectCommandDescriptor::~UdpConnectCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpConnectCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpConnectCommand *>(obj)!=nullptr;
}

const char **UdpConnectCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpConnectCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpConnectCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int UdpConnectCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_remoteAddr
        FD_ISEDITABLE,    // FIELD_remotePort
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *UdpConnectCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteAddr",
        "remotePort",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int UdpConnectCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddr") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remotePort") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpConnectCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_remoteAddr
        "int",    // FIELD_remotePort
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpConnectCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpConnectCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpConnectCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpConnectCommand *pp = (UdpConnectCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpConnectCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpConnectCommand *pp = (UdpConnectCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpConnectCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpConnectCommand *pp = (UdpConnectCommand *)object; (void)pp;
    switch (field) {
        case FIELD_remoteAddr: return pp->getRemoteAddr().str();
        case FIELD_remotePort: return long2string(pp->getRemotePort());
        default: return "";
    }
}

bool UdpConnectCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpConnectCommand *pp = (UdpConnectCommand *)object; (void)pp;
    switch (field) {
        case FIELD_remotePort: pp->setRemotePort(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpConnectCommandDescriptor::getFieldStructName(int field) const
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

void *UdpConnectCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpConnectCommand *pp = (UdpConnectCommand *)object; (void)pp;
    switch (field) {
        case FIELD_remoteAddr: return toVoidPtr(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(UdpCloseCommand)

UdpCloseCommand::UdpCloseCommand() : ::inet::UdpControlInfo()
{
}

UdpCloseCommand::UdpCloseCommand(const UdpCloseCommand& other) : ::inet::UdpControlInfo(other)
{
    copy(other);
}

UdpCloseCommand::~UdpCloseCommand()
{
}

UdpCloseCommand& UdpCloseCommand::operator=(const UdpCloseCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UdpCloseCommand::copy(const UdpCloseCommand& other)
{
}

void UdpCloseCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpControlInfo::parsimPack(b);
}

void UdpCloseCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpControlInfo::parsimUnpack(b);
}

class UdpCloseCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    UdpCloseCommandDescriptor();
    virtual ~UdpCloseCommandDescriptor();

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

Register_ClassDescriptor(UdpCloseCommandDescriptor)

UdpCloseCommandDescriptor::UdpCloseCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpCloseCommand)), "inet::UdpControlInfo")
{
    propertynames = nullptr;
}

UdpCloseCommandDescriptor::~UdpCloseCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpCloseCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpCloseCommand *>(obj)!=nullptr;
}

const char **UdpCloseCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpCloseCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpCloseCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int UdpCloseCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *UdpCloseCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int UdpCloseCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpCloseCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **UdpCloseCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpCloseCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpCloseCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpCloseCommand *pp = (UdpCloseCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpCloseCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpCloseCommand *pp = (UdpCloseCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpCloseCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpCloseCommand *pp = (UdpCloseCommand *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool UdpCloseCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpCloseCommand *pp = (UdpCloseCommand *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *UdpCloseCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *UdpCloseCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpCloseCommand *pp = (UdpCloseCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UdpSocketClosedIndication)

UdpSocketClosedIndication::UdpSocketClosedIndication() : ::inet::UdpControlInfo()
{
}

UdpSocketClosedIndication::UdpSocketClosedIndication(const UdpSocketClosedIndication& other) : ::inet::UdpControlInfo(other)
{
    copy(other);
}

UdpSocketClosedIndication::~UdpSocketClosedIndication()
{
}

UdpSocketClosedIndication& UdpSocketClosedIndication::operator=(const UdpSocketClosedIndication& other)
{
    if (this == &other) return *this;
    ::inet::UdpControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UdpSocketClosedIndication::copy(const UdpSocketClosedIndication& other)
{
}

void UdpSocketClosedIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpControlInfo::parsimPack(b);
}

void UdpSocketClosedIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpControlInfo::parsimUnpack(b);
}

class UdpSocketClosedIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    UdpSocketClosedIndicationDescriptor();
    virtual ~UdpSocketClosedIndicationDescriptor();

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

Register_ClassDescriptor(UdpSocketClosedIndicationDescriptor)

UdpSocketClosedIndicationDescriptor::UdpSocketClosedIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpSocketClosedIndication)), "inet::UdpControlInfo")
{
    propertynames = nullptr;
}

UdpSocketClosedIndicationDescriptor::~UdpSocketClosedIndicationDescriptor()
{
    delete[] propertynames;
}

bool UdpSocketClosedIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpSocketClosedIndication *>(obj)!=nullptr;
}

const char **UdpSocketClosedIndicationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpSocketClosedIndicationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpSocketClosedIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int UdpSocketClosedIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *UdpSocketClosedIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int UdpSocketClosedIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpSocketClosedIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **UdpSocketClosedIndicationDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpSocketClosedIndicationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpSocketClosedIndicationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpSocketClosedIndication *pp = (UdpSocketClosedIndication *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpSocketClosedIndicationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSocketClosedIndication *pp = (UdpSocketClosedIndication *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpSocketClosedIndicationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSocketClosedIndication *pp = (UdpSocketClosedIndication *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool UdpSocketClosedIndicationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpSocketClosedIndication *pp = (UdpSocketClosedIndication *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *UdpSocketClosedIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *UdpSocketClosedIndicationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpSocketClosedIndication *pp = (UdpSocketClosedIndication *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UdpDestroyCommand)

UdpDestroyCommand::UdpDestroyCommand() : ::inet::UdpControlInfo()
{
}

UdpDestroyCommand::UdpDestroyCommand(const UdpDestroyCommand& other) : ::inet::UdpControlInfo(other)
{
    copy(other);
}

UdpDestroyCommand::~UdpDestroyCommand()
{
}

UdpDestroyCommand& UdpDestroyCommand::operator=(const UdpDestroyCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UdpDestroyCommand::copy(const UdpDestroyCommand& other)
{
}

void UdpDestroyCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpControlInfo::parsimPack(b);
}

void UdpDestroyCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpControlInfo::parsimUnpack(b);
}

class UdpDestroyCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    UdpDestroyCommandDescriptor();
    virtual ~UdpDestroyCommandDescriptor();

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

Register_ClassDescriptor(UdpDestroyCommandDescriptor)

UdpDestroyCommandDescriptor::UdpDestroyCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpDestroyCommand)), "inet::UdpControlInfo")
{
    propertynames = nullptr;
}

UdpDestroyCommandDescriptor::~UdpDestroyCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpDestroyCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpDestroyCommand *>(obj)!=nullptr;
}

const char **UdpDestroyCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpDestroyCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpDestroyCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int UdpDestroyCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *UdpDestroyCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int UdpDestroyCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpDestroyCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **UdpDestroyCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpDestroyCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpDestroyCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpDestroyCommand *pp = (UdpDestroyCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpDestroyCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpDestroyCommand *pp = (UdpDestroyCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpDestroyCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpDestroyCommand *pp = (UdpDestroyCommand *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool UdpDestroyCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpDestroyCommand *pp = (UdpDestroyCommand *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *UdpDestroyCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *UdpDestroyCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpDestroyCommand *pp = (UdpDestroyCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UdpErrorIndication)

UdpErrorIndication::UdpErrorIndication() : ::inet::UdpControlInfo()
{
}

UdpErrorIndication::UdpErrorIndication(const UdpErrorIndication& other) : ::inet::UdpControlInfo(other)
{
    copy(other);
}

UdpErrorIndication::~UdpErrorIndication()
{
}

UdpErrorIndication& UdpErrorIndication::operator=(const UdpErrorIndication& other)
{
    if (this == &other) return *this;
    ::inet::UdpControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UdpErrorIndication::copy(const UdpErrorIndication& other)
{
}

void UdpErrorIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpControlInfo::parsimPack(b);
}

void UdpErrorIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpControlInfo::parsimUnpack(b);
}

class UdpErrorIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    UdpErrorIndicationDescriptor();
    virtual ~UdpErrorIndicationDescriptor();

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

Register_ClassDescriptor(UdpErrorIndicationDescriptor)

UdpErrorIndicationDescriptor::UdpErrorIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpErrorIndication)), "inet::UdpControlInfo")
{
    propertynames = nullptr;
}

UdpErrorIndicationDescriptor::~UdpErrorIndicationDescriptor()
{
    delete[] propertynames;
}

bool UdpErrorIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpErrorIndication *>(obj)!=nullptr;
}

const char **UdpErrorIndicationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpErrorIndicationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpErrorIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int UdpErrorIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *UdpErrorIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int UdpErrorIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpErrorIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **UdpErrorIndicationDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpErrorIndicationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpErrorIndicationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpErrorIndication *pp = (UdpErrorIndication *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpErrorIndicationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpErrorIndication *pp = (UdpErrorIndication *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpErrorIndicationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpErrorIndication *pp = (UdpErrorIndication *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool UdpErrorIndicationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpErrorIndication *pp = (UdpErrorIndication *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *UdpErrorIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *UdpErrorIndicationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpErrorIndication *pp = (UdpErrorIndication *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UdpSetOptionCommand)

UdpSetOptionCommand::UdpSetOptionCommand() : ::inet::UdpControlInfo()
{
}

UdpSetOptionCommand::UdpSetOptionCommand(const UdpSetOptionCommand& other) : ::inet::UdpControlInfo(other)
{
    copy(other);
}

UdpSetOptionCommand::~UdpSetOptionCommand()
{
}

UdpSetOptionCommand& UdpSetOptionCommand::operator=(const UdpSetOptionCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UdpSetOptionCommand::copy(const UdpSetOptionCommand& other)
{
}

void UdpSetOptionCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpControlInfo::parsimPack(b);
}

void UdpSetOptionCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpControlInfo::parsimUnpack(b);
}

class UdpSetOptionCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    UdpSetOptionCommandDescriptor();
    virtual ~UdpSetOptionCommandDescriptor();

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

Register_ClassDescriptor(UdpSetOptionCommandDescriptor)

UdpSetOptionCommandDescriptor::UdpSetOptionCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpSetOptionCommand)), "inet::UdpControlInfo")
{
    propertynames = nullptr;
}

UdpSetOptionCommandDescriptor::~UdpSetOptionCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpSetOptionCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpSetOptionCommand *>(obj)!=nullptr;
}

const char **UdpSetOptionCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpSetOptionCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpSetOptionCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int UdpSetOptionCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *UdpSetOptionCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int UdpSetOptionCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpSetOptionCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **UdpSetOptionCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpSetOptionCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpSetOptionCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpSetOptionCommand *pp = (UdpSetOptionCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpSetOptionCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetOptionCommand *pp = (UdpSetOptionCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpSetOptionCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetOptionCommand *pp = (UdpSetOptionCommand *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool UdpSetOptionCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpSetOptionCommand *pp = (UdpSetOptionCommand *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *UdpSetOptionCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *UdpSetOptionCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpSetOptionCommand *pp = (UdpSetOptionCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UdpSetTimeToLiveCommand)

UdpSetTimeToLiveCommand::UdpSetTimeToLiveCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpSetTimeToLiveCommand::UdpSetTimeToLiveCommand(const UdpSetTimeToLiveCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpSetTimeToLiveCommand::~UdpSetTimeToLiveCommand()
{
}

UdpSetTimeToLiveCommand& UdpSetTimeToLiveCommand::operator=(const UdpSetTimeToLiveCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpSetTimeToLiveCommand::copy(const UdpSetTimeToLiveCommand& other)
{
    this->ttl = other.ttl;
}

void UdpSetTimeToLiveCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->ttl);
}

void UdpSetTimeToLiveCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->ttl);
}

int UdpSetTimeToLiveCommand::getTtl() const
{
    return this->ttl;
}

void UdpSetTimeToLiveCommand::setTtl(int ttl)
{
    this->ttl = ttl;
}

class UdpSetTimeToLiveCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_ttl,
    };
  public:
    UdpSetTimeToLiveCommandDescriptor();
    virtual ~UdpSetTimeToLiveCommandDescriptor();

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

Register_ClassDescriptor(UdpSetTimeToLiveCommandDescriptor)

UdpSetTimeToLiveCommandDescriptor::UdpSetTimeToLiveCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpSetTimeToLiveCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpSetTimeToLiveCommandDescriptor::~UdpSetTimeToLiveCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpSetTimeToLiveCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpSetTimeToLiveCommand *>(obj)!=nullptr;
}

const char **UdpSetTimeToLiveCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpSetTimeToLiveCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpSetTimeToLiveCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UdpSetTimeToLiveCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ttl
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *UdpSetTimeToLiveCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ttl",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int UdpSetTimeToLiveCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "ttl") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpSetTimeToLiveCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ttl
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpSetTimeToLiveCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpSetTimeToLiveCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpSetTimeToLiveCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpSetTimeToLiveCommand *pp = (UdpSetTimeToLiveCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpSetTimeToLiveCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetTimeToLiveCommand *pp = (UdpSetTimeToLiveCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpSetTimeToLiveCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetTimeToLiveCommand *pp = (UdpSetTimeToLiveCommand *)object; (void)pp;
    switch (field) {
        case FIELD_ttl: return long2string(pp->getTtl());
        default: return "";
    }
}

bool UdpSetTimeToLiveCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpSetTimeToLiveCommand *pp = (UdpSetTimeToLiveCommand *)object; (void)pp;
    switch (field) {
        case FIELD_ttl: pp->setTtl(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpSetTimeToLiveCommandDescriptor::getFieldStructName(int field) const
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

void *UdpSetTimeToLiveCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpSetTimeToLiveCommand *pp = (UdpSetTimeToLiveCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UdpSetTypeOfServiceCommand)

UdpSetTypeOfServiceCommand::UdpSetTypeOfServiceCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpSetTypeOfServiceCommand::UdpSetTypeOfServiceCommand(const UdpSetTypeOfServiceCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpSetTypeOfServiceCommand::~UdpSetTypeOfServiceCommand()
{
}

UdpSetTypeOfServiceCommand& UdpSetTypeOfServiceCommand::operator=(const UdpSetTypeOfServiceCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpSetTypeOfServiceCommand::copy(const UdpSetTypeOfServiceCommand& other)
{
    this->tos = other.tos;
}

void UdpSetTypeOfServiceCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->tos);
}

void UdpSetTypeOfServiceCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->tos);
}

char UdpSetTypeOfServiceCommand::getTos() const
{
    return this->tos;
}

void UdpSetTypeOfServiceCommand::setTos(char tos)
{
    this->tos = tos;
}

class UdpSetTypeOfServiceCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_tos,
    };
  public:
    UdpSetTypeOfServiceCommandDescriptor();
    virtual ~UdpSetTypeOfServiceCommandDescriptor();

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

Register_ClassDescriptor(UdpSetTypeOfServiceCommandDescriptor)

UdpSetTypeOfServiceCommandDescriptor::UdpSetTypeOfServiceCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpSetTypeOfServiceCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpSetTypeOfServiceCommandDescriptor::~UdpSetTypeOfServiceCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpSetTypeOfServiceCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpSetTypeOfServiceCommand *>(obj)!=nullptr;
}

const char **UdpSetTypeOfServiceCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpSetTypeOfServiceCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpSetTypeOfServiceCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UdpSetTypeOfServiceCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_tos
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *UdpSetTypeOfServiceCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tos",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int UdpSetTypeOfServiceCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "tos") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpSetTypeOfServiceCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",    // FIELD_tos
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpSetTypeOfServiceCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpSetTypeOfServiceCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpSetTypeOfServiceCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpSetTypeOfServiceCommand *pp = (UdpSetTypeOfServiceCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpSetTypeOfServiceCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetTypeOfServiceCommand *pp = (UdpSetTypeOfServiceCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpSetTypeOfServiceCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetTypeOfServiceCommand *pp = (UdpSetTypeOfServiceCommand *)object; (void)pp;
    switch (field) {
        case FIELD_tos: return long2string(pp->getTos());
        default: return "";
    }
}

bool UdpSetTypeOfServiceCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpSetTypeOfServiceCommand *pp = (UdpSetTypeOfServiceCommand *)object; (void)pp;
    switch (field) {
        case FIELD_tos: pp->setTos(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpSetTypeOfServiceCommandDescriptor::getFieldStructName(int field) const
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

void *UdpSetTypeOfServiceCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpSetTypeOfServiceCommand *pp = (UdpSetTypeOfServiceCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UdpSetBroadcastCommand)

UdpSetBroadcastCommand::UdpSetBroadcastCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpSetBroadcastCommand::UdpSetBroadcastCommand(const UdpSetBroadcastCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpSetBroadcastCommand::~UdpSetBroadcastCommand()
{
}

UdpSetBroadcastCommand& UdpSetBroadcastCommand::operator=(const UdpSetBroadcastCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpSetBroadcastCommand::copy(const UdpSetBroadcastCommand& other)
{
    this->broadcast = other.broadcast;
}

void UdpSetBroadcastCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->broadcast);
}

void UdpSetBroadcastCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->broadcast);
}

bool UdpSetBroadcastCommand::getBroadcast() const
{
    return this->broadcast;
}

void UdpSetBroadcastCommand::setBroadcast(bool broadcast)
{
    this->broadcast = broadcast;
}

class UdpSetBroadcastCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_broadcast,
    };
  public:
    UdpSetBroadcastCommandDescriptor();
    virtual ~UdpSetBroadcastCommandDescriptor();

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

Register_ClassDescriptor(UdpSetBroadcastCommandDescriptor)

UdpSetBroadcastCommandDescriptor::UdpSetBroadcastCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpSetBroadcastCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpSetBroadcastCommandDescriptor::~UdpSetBroadcastCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpSetBroadcastCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpSetBroadcastCommand *>(obj)!=nullptr;
}

const char **UdpSetBroadcastCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpSetBroadcastCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpSetBroadcastCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UdpSetBroadcastCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_broadcast
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *UdpSetBroadcastCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "broadcast",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int UdpSetBroadcastCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "broadcast") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpSetBroadcastCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_broadcast
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpSetBroadcastCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpSetBroadcastCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpSetBroadcastCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpSetBroadcastCommand *pp = (UdpSetBroadcastCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpSetBroadcastCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetBroadcastCommand *pp = (UdpSetBroadcastCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpSetBroadcastCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetBroadcastCommand *pp = (UdpSetBroadcastCommand *)object; (void)pp;
    switch (field) {
        case FIELD_broadcast: return bool2string(pp->getBroadcast());
        default: return "";
    }
}

bool UdpSetBroadcastCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpSetBroadcastCommand *pp = (UdpSetBroadcastCommand *)object; (void)pp;
    switch (field) {
        case FIELD_broadcast: pp->setBroadcast(string2bool(value)); return true;
        default: return false;
    }
}

const char *UdpSetBroadcastCommandDescriptor::getFieldStructName(int field) const
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

void *UdpSetBroadcastCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpSetBroadcastCommand *pp = (UdpSetBroadcastCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UdpSetMulticastInterfaceCommand)

UdpSetMulticastInterfaceCommand::UdpSetMulticastInterfaceCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpSetMulticastInterfaceCommand::UdpSetMulticastInterfaceCommand(const UdpSetMulticastInterfaceCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpSetMulticastInterfaceCommand::~UdpSetMulticastInterfaceCommand()
{
}

UdpSetMulticastInterfaceCommand& UdpSetMulticastInterfaceCommand::operator=(const UdpSetMulticastInterfaceCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpSetMulticastInterfaceCommand::copy(const UdpSetMulticastInterfaceCommand& other)
{
    this->interfaceId = other.interfaceId;
}

void UdpSetMulticastInterfaceCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->interfaceId);
}

void UdpSetMulticastInterfaceCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceId);
}

int UdpSetMulticastInterfaceCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UdpSetMulticastInterfaceCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

class UdpSetMulticastInterfaceCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_interfaceId,
    };
  public:
    UdpSetMulticastInterfaceCommandDescriptor();
    virtual ~UdpSetMulticastInterfaceCommandDescriptor();

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

Register_ClassDescriptor(UdpSetMulticastInterfaceCommandDescriptor)

UdpSetMulticastInterfaceCommandDescriptor::UdpSetMulticastInterfaceCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpSetMulticastInterfaceCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpSetMulticastInterfaceCommandDescriptor::~UdpSetMulticastInterfaceCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpSetMulticastInterfaceCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpSetMulticastInterfaceCommand *>(obj)!=nullptr;
}

const char **UdpSetMulticastInterfaceCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpSetMulticastInterfaceCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpSetMulticastInterfaceCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UdpSetMulticastInterfaceCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_interfaceId
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *UdpSetMulticastInterfaceCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int UdpSetMulticastInterfaceCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interfaceId") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpSetMulticastInterfaceCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_interfaceId
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpSetMulticastInterfaceCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpSetMulticastInterfaceCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpSetMulticastInterfaceCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastInterfaceCommand *pp = (UdpSetMulticastInterfaceCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpSetMulticastInterfaceCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastInterfaceCommand *pp = (UdpSetMulticastInterfaceCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpSetMulticastInterfaceCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastInterfaceCommand *pp = (UdpSetMulticastInterfaceCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: return long2string(pp->getInterfaceId());
        default: return "";
    }
}

bool UdpSetMulticastInterfaceCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastInterfaceCommand *pp = (UdpSetMulticastInterfaceCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpSetMulticastInterfaceCommandDescriptor::getFieldStructName(int field) const
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

void *UdpSetMulticastInterfaceCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastInterfaceCommand *pp = (UdpSetMulticastInterfaceCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UdpSetMulticastLoopCommand)

UdpSetMulticastLoopCommand::UdpSetMulticastLoopCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpSetMulticastLoopCommand::UdpSetMulticastLoopCommand(const UdpSetMulticastLoopCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpSetMulticastLoopCommand::~UdpSetMulticastLoopCommand()
{
}

UdpSetMulticastLoopCommand& UdpSetMulticastLoopCommand::operator=(const UdpSetMulticastLoopCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpSetMulticastLoopCommand::copy(const UdpSetMulticastLoopCommand& other)
{
    this->loop = other.loop;
}

void UdpSetMulticastLoopCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->loop);
}

void UdpSetMulticastLoopCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->loop);
}

bool UdpSetMulticastLoopCommand::getLoop() const
{
    return this->loop;
}

void UdpSetMulticastLoopCommand::setLoop(bool loop)
{
    this->loop = loop;
}

class UdpSetMulticastLoopCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_loop,
    };
  public:
    UdpSetMulticastLoopCommandDescriptor();
    virtual ~UdpSetMulticastLoopCommandDescriptor();

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

Register_ClassDescriptor(UdpSetMulticastLoopCommandDescriptor)

UdpSetMulticastLoopCommandDescriptor::UdpSetMulticastLoopCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpSetMulticastLoopCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpSetMulticastLoopCommandDescriptor::~UdpSetMulticastLoopCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpSetMulticastLoopCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpSetMulticastLoopCommand *>(obj)!=nullptr;
}

const char **UdpSetMulticastLoopCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpSetMulticastLoopCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpSetMulticastLoopCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UdpSetMulticastLoopCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_loop
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *UdpSetMulticastLoopCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "loop",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int UdpSetMulticastLoopCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "loop") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpSetMulticastLoopCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_loop
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpSetMulticastLoopCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpSetMulticastLoopCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpSetMulticastLoopCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastLoopCommand *pp = (UdpSetMulticastLoopCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpSetMulticastLoopCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastLoopCommand *pp = (UdpSetMulticastLoopCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpSetMulticastLoopCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastLoopCommand *pp = (UdpSetMulticastLoopCommand *)object; (void)pp;
    switch (field) {
        case FIELD_loop: return bool2string(pp->getLoop());
        default: return "";
    }
}

bool UdpSetMulticastLoopCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastLoopCommand *pp = (UdpSetMulticastLoopCommand *)object; (void)pp;
    switch (field) {
        case FIELD_loop: pp->setLoop(string2bool(value)); return true;
        default: return false;
    }
}

const char *UdpSetMulticastLoopCommandDescriptor::getFieldStructName(int field) const
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

void *UdpSetMulticastLoopCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastLoopCommand *pp = (UdpSetMulticastLoopCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UdpSetReuseAddressCommand)

UdpSetReuseAddressCommand::UdpSetReuseAddressCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpSetReuseAddressCommand::UdpSetReuseAddressCommand(const UdpSetReuseAddressCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpSetReuseAddressCommand::~UdpSetReuseAddressCommand()
{
}

UdpSetReuseAddressCommand& UdpSetReuseAddressCommand::operator=(const UdpSetReuseAddressCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpSetReuseAddressCommand::copy(const UdpSetReuseAddressCommand& other)
{
    this->reuseAddress = other.reuseAddress;
}

void UdpSetReuseAddressCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->reuseAddress);
}

void UdpSetReuseAddressCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->reuseAddress);
}

bool UdpSetReuseAddressCommand::getReuseAddress() const
{
    return this->reuseAddress;
}

void UdpSetReuseAddressCommand::setReuseAddress(bool reuseAddress)
{
    this->reuseAddress = reuseAddress;
}

class UdpSetReuseAddressCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_reuseAddress,
    };
  public:
    UdpSetReuseAddressCommandDescriptor();
    virtual ~UdpSetReuseAddressCommandDescriptor();

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

Register_ClassDescriptor(UdpSetReuseAddressCommandDescriptor)

UdpSetReuseAddressCommandDescriptor::UdpSetReuseAddressCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpSetReuseAddressCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpSetReuseAddressCommandDescriptor::~UdpSetReuseAddressCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpSetReuseAddressCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpSetReuseAddressCommand *>(obj)!=nullptr;
}

const char **UdpSetReuseAddressCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpSetReuseAddressCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpSetReuseAddressCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UdpSetReuseAddressCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_reuseAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *UdpSetReuseAddressCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reuseAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int UdpSetReuseAddressCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reuseAddress") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpSetReuseAddressCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_reuseAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpSetReuseAddressCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpSetReuseAddressCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpSetReuseAddressCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpSetReuseAddressCommand *pp = (UdpSetReuseAddressCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpSetReuseAddressCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetReuseAddressCommand *pp = (UdpSetReuseAddressCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpSetReuseAddressCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetReuseAddressCommand *pp = (UdpSetReuseAddressCommand *)object; (void)pp;
    switch (field) {
        case FIELD_reuseAddress: return bool2string(pp->getReuseAddress());
        default: return "";
    }
}

bool UdpSetReuseAddressCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpSetReuseAddressCommand *pp = (UdpSetReuseAddressCommand *)object; (void)pp;
    switch (field) {
        case FIELD_reuseAddress: pp->setReuseAddress(string2bool(value)); return true;
        default: return false;
    }
}

const char *UdpSetReuseAddressCommandDescriptor::getFieldStructName(int field) const
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

void *UdpSetReuseAddressCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpSetReuseAddressCommand *pp = (UdpSetReuseAddressCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UdpJoinMulticastGroupsCommand)

UdpJoinMulticastGroupsCommand::UdpJoinMulticastGroupsCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpJoinMulticastGroupsCommand::UdpJoinMulticastGroupsCommand(const UdpJoinMulticastGroupsCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpJoinMulticastGroupsCommand::~UdpJoinMulticastGroupsCommand()
{
    delete [] this->multicastAddr;
    delete [] this->interfaceId;
}

UdpJoinMulticastGroupsCommand& UdpJoinMulticastGroupsCommand::operator=(const UdpJoinMulticastGroupsCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpJoinMulticastGroupsCommand::copy(const UdpJoinMulticastGroupsCommand& other)
{
    delete [] this->multicastAddr;
    this->multicastAddr = (other.multicastAddr_arraysize==0) ? nullptr : new L3Address[other.multicastAddr_arraysize];
    multicastAddr_arraysize = other.multicastAddr_arraysize;
    for (size_t i = 0; i < multicastAddr_arraysize; i++) {
        this->multicastAddr[i] = other.multicastAddr[i];
    }
    delete [] this->interfaceId;
    this->interfaceId = (other.interfaceId_arraysize==0) ? nullptr : new int[other.interfaceId_arraysize];
    interfaceId_arraysize = other.interfaceId_arraysize;
    for (size_t i = 0; i < interfaceId_arraysize; i++) {
        this->interfaceId[i] = other.interfaceId[i];
    }
}

void UdpJoinMulticastGroupsCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    b->pack(multicastAddr_arraysize);
    doParsimArrayPacking(b,this->multicastAddr,multicastAddr_arraysize);
    b->pack(interfaceId_arraysize);
    doParsimArrayPacking(b,this->interfaceId,interfaceId_arraysize);
}

void UdpJoinMulticastGroupsCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    delete [] this->multicastAddr;
    b->unpack(multicastAddr_arraysize);
    if (multicastAddr_arraysize == 0) {
        this->multicastAddr = nullptr;
    } else {
        this->multicastAddr = new L3Address[multicastAddr_arraysize];
        doParsimArrayUnpacking(b,this->multicastAddr,multicastAddr_arraysize);
    }
    delete [] this->interfaceId;
    b->unpack(interfaceId_arraysize);
    if (interfaceId_arraysize == 0) {
        this->interfaceId = nullptr;
    } else {
        this->interfaceId = new int[interfaceId_arraysize];
        doParsimArrayUnpacking(b,this->interfaceId,interfaceId_arraysize);
    }
}

size_t UdpJoinMulticastGroupsCommand::getMulticastAddrArraySize() const
{
    return multicastAddr_arraysize;
}

const L3Address& UdpJoinMulticastGroupsCommand::getMulticastAddr(size_t k) const
{
    if (k >= multicastAddr_arraysize) throw omnetpp::cRuntimeError("Array of size multicastAddr_arraysize indexed by %lu", (unsigned long)k);
    return this->multicastAddr[k];
}

void UdpJoinMulticastGroupsCommand::setMulticastAddrArraySize(size_t newSize)
{
    L3Address *multicastAddr2 = (newSize==0) ? nullptr : new L3Address[newSize];
    size_t minSize = multicastAddr_arraysize < newSize ? multicastAddr_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        multicastAddr2[i] = this->multicastAddr[i];
    delete [] this->multicastAddr;
    this->multicastAddr = multicastAddr2;
    multicastAddr_arraysize = newSize;
}

void UdpJoinMulticastGroupsCommand::setMulticastAddr(size_t k, const L3Address& multicastAddr)
{
    if (k >= multicastAddr_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->multicastAddr[k] = multicastAddr;
}

void UdpJoinMulticastGroupsCommand::insertMulticastAddr(size_t k, const L3Address& multicastAddr)
{
    if (k > multicastAddr_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = multicastAddr_arraysize + 1;
    L3Address *multicastAddr2 = new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        multicastAddr2[i] = this->multicastAddr[i];
    multicastAddr2[k] = multicastAddr;
    for (i = k + 1; i < newSize; i++)
        multicastAddr2[i] = this->multicastAddr[i-1];
    delete [] this->multicastAddr;
    this->multicastAddr = multicastAddr2;
    multicastAddr_arraysize = newSize;
}

void UdpJoinMulticastGroupsCommand::insertMulticastAddr(const L3Address& multicastAddr)
{
    insertMulticastAddr(multicastAddr_arraysize, multicastAddr);
}

void UdpJoinMulticastGroupsCommand::eraseMulticastAddr(size_t k)
{
    if (k >= multicastAddr_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = multicastAddr_arraysize - 1;
    L3Address *multicastAddr2 = (newSize == 0) ? nullptr : new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        multicastAddr2[i] = this->multicastAddr[i];
    for (i = k; i < newSize; i++)
        multicastAddr2[i] = this->multicastAddr[i+1];
    delete [] this->multicastAddr;
    this->multicastAddr = multicastAddr2;
    multicastAddr_arraysize = newSize;
}

size_t UdpJoinMulticastGroupsCommand::getInterfaceIdArraySize() const
{
    return interfaceId_arraysize;
}

int UdpJoinMulticastGroupsCommand::getInterfaceId(size_t k) const
{
    if (k >= interfaceId_arraysize) throw omnetpp::cRuntimeError("Array of size interfaceId_arraysize indexed by %lu", (unsigned long)k);
    return this->interfaceId[k];
}

void UdpJoinMulticastGroupsCommand::setInterfaceIdArraySize(size_t newSize)
{
    int *interfaceId2 = (newSize==0) ? nullptr : new int[newSize];
    size_t minSize = interfaceId_arraysize < newSize ? interfaceId_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        interfaceId2[i] = this->interfaceId[i];
    for (size_t i = minSize; i < newSize; i++)
        interfaceId2[i] = 0;
    delete [] this->interfaceId;
    this->interfaceId = interfaceId2;
    interfaceId_arraysize = newSize;
}

void UdpJoinMulticastGroupsCommand::setInterfaceId(size_t k, int interfaceId)
{
    if (k >= interfaceId_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->interfaceId[k] = interfaceId;
}

void UdpJoinMulticastGroupsCommand::insertInterfaceId(size_t k, int interfaceId)
{
    if (k > interfaceId_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = interfaceId_arraysize + 1;
    int *interfaceId2 = new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        interfaceId2[i] = this->interfaceId[i];
    interfaceId2[k] = interfaceId;
    for (i = k + 1; i < newSize; i++)
        interfaceId2[i] = this->interfaceId[i-1];
    delete [] this->interfaceId;
    this->interfaceId = interfaceId2;
    interfaceId_arraysize = newSize;
}

void UdpJoinMulticastGroupsCommand::insertInterfaceId(int interfaceId)
{
    insertInterfaceId(interfaceId_arraysize, interfaceId);
}

void UdpJoinMulticastGroupsCommand::eraseInterfaceId(size_t k)
{
    if (k >= interfaceId_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = interfaceId_arraysize - 1;
    int *interfaceId2 = (newSize == 0) ? nullptr : new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        interfaceId2[i] = this->interfaceId[i];
    for (i = k; i < newSize; i++)
        interfaceId2[i] = this->interfaceId[i+1];
    delete [] this->interfaceId;
    this->interfaceId = interfaceId2;
    interfaceId_arraysize = newSize;
}

class UdpJoinMulticastGroupsCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_multicastAddr,
        FIELD_interfaceId,
    };
  public:
    UdpJoinMulticastGroupsCommandDescriptor();
    virtual ~UdpJoinMulticastGroupsCommandDescriptor();

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

Register_ClassDescriptor(UdpJoinMulticastGroupsCommandDescriptor)

UdpJoinMulticastGroupsCommandDescriptor::UdpJoinMulticastGroupsCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpJoinMulticastGroupsCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpJoinMulticastGroupsCommandDescriptor::~UdpJoinMulticastGroupsCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpJoinMulticastGroupsCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpJoinMulticastGroupsCommand *>(obj)!=nullptr;
}

const char **UdpJoinMulticastGroupsCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpJoinMulticastGroupsCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpJoinMulticastGroupsCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int UdpJoinMulticastGroupsCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY,    // FIELD_multicastAddr
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_interfaceId
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *UdpJoinMulticastGroupsCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "multicastAddr",
        "interfaceId",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int UdpJoinMulticastGroupsCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "multicastAddr") == 0) return base+0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interfaceId") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpJoinMulticastGroupsCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_multicastAddr
        "int",    // FIELD_interfaceId
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpJoinMulticastGroupsCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpJoinMulticastGroupsCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpJoinMulticastGroupsCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpJoinMulticastGroupsCommand *pp = (UdpJoinMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case FIELD_multicastAddr: return pp->getMulticastAddrArraySize();
        case FIELD_interfaceId: return pp->getInterfaceIdArraySize();
        default: return 0;
    }
}

const char *UdpJoinMulticastGroupsCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpJoinMulticastGroupsCommand *pp = (UdpJoinMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpJoinMulticastGroupsCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpJoinMulticastGroupsCommand *pp = (UdpJoinMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case FIELD_multicastAddr: return pp->getMulticastAddr(i).str();
        case FIELD_interfaceId: return long2string(pp->getInterfaceId(i));
        default: return "";
    }
}

bool UdpJoinMulticastGroupsCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpJoinMulticastGroupsCommand *pp = (UdpJoinMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: pp->setInterfaceId(i,string2long(value)); return true;
        default: return false;
    }
}

const char *UdpJoinMulticastGroupsCommandDescriptor::getFieldStructName(int field) const
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

void *UdpJoinMulticastGroupsCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpJoinMulticastGroupsCommand *pp = (UdpJoinMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case FIELD_multicastAddr: return toVoidPtr(&pp->getMulticastAddr(i)); break;
        default: return nullptr;
    }
}

Register_Class(UdpLeaveMulticastGroupsCommand)

UdpLeaveMulticastGroupsCommand::UdpLeaveMulticastGroupsCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpLeaveMulticastGroupsCommand::UdpLeaveMulticastGroupsCommand(const UdpLeaveMulticastGroupsCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpLeaveMulticastGroupsCommand::~UdpLeaveMulticastGroupsCommand()
{
    delete [] this->multicastAddr;
}

UdpLeaveMulticastGroupsCommand& UdpLeaveMulticastGroupsCommand::operator=(const UdpLeaveMulticastGroupsCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpLeaveMulticastGroupsCommand::copy(const UdpLeaveMulticastGroupsCommand& other)
{
    delete [] this->multicastAddr;
    this->multicastAddr = (other.multicastAddr_arraysize==0) ? nullptr : new L3Address[other.multicastAddr_arraysize];
    multicastAddr_arraysize = other.multicastAddr_arraysize;
    for (size_t i = 0; i < multicastAddr_arraysize; i++) {
        this->multicastAddr[i] = other.multicastAddr[i];
    }
}

void UdpLeaveMulticastGroupsCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    b->pack(multicastAddr_arraysize);
    doParsimArrayPacking(b,this->multicastAddr,multicastAddr_arraysize);
}

void UdpLeaveMulticastGroupsCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    delete [] this->multicastAddr;
    b->unpack(multicastAddr_arraysize);
    if (multicastAddr_arraysize == 0) {
        this->multicastAddr = nullptr;
    } else {
        this->multicastAddr = new L3Address[multicastAddr_arraysize];
        doParsimArrayUnpacking(b,this->multicastAddr,multicastAddr_arraysize);
    }
}

size_t UdpLeaveMulticastGroupsCommand::getMulticastAddrArraySize() const
{
    return multicastAddr_arraysize;
}

const L3Address& UdpLeaveMulticastGroupsCommand::getMulticastAddr(size_t k) const
{
    if (k >= multicastAddr_arraysize) throw omnetpp::cRuntimeError("Array of size multicastAddr_arraysize indexed by %lu", (unsigned long)k);
    return this->multicastAddr[k];
}

void UdpLeaveMulticastGroupsCommand::setMulticastAddrArraySize(size_t newSize)
{
    L3Address *multicastAddr2 = (newSize==0) ? nullptr : new L3Address[newSize];
    size_t minSize = multicastAddr_arraysize < newSize ? multicastAddr_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        multicastAddr2[i] = this->multicastAddr[i];
    delete [] this->multicastAddr;
    this->multicastAddr = multicastAddr2;
    multicastAddr_arraysize = newSize;
}

void UdpLeaveMulticastGroupsCommand::setMulticastAddr(size_t k, const L3Address& multicastAddr)
{
    if (k >= multicastAddr_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->multicastAddr[k] = multicastAddr;
}

void UdpLeaveMulticastGroupsCommand::insertMulticastAddr(size_t k, const L3Address& multicastAddr)
{
    if (k > multicastAddr_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = multicastAddr_arraysize + 1;
    L3Address *multicastAddr2 = new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        multicastAddr2[i] = this->multicastAddr[i];
    multicastAddr2[k] = multicastAddr;
    for (i = k + 1; i < newSize; i++)
        multicastAddr2[i] = this->multicastAddr[i-1];
    delete [] this->multicastAddr;
    this->multicastAddr = multicastAddr2;
    multicastAddr_arraysize = newSize;
}

void UdpLeaveMulticastGroupsCommand::insertMulticastAddr(const L3Address& multicastAddr)
{
    insertMulticastAddr(multicastAddr_arraysize, multicastAddr);
}

void UdpLeaveMulticastGroupsCommand::eraseMulticastAddr(size_t k)
{
    if (k >= multicastAddr_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = multicastAddr_arraysize - 1;
    L3Address *multicastAddr2 = (newSize == 0) ? nullptr : new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        multicastAddr2[i] = this->multicastAddr[i];
    for (i = k; i < newSize; i++)
        multicastAddr2[i] = this->multicastAddr[i+1];
    delete [] this->multicastAddr;
    this->multicastAddr = multicastAddr2;
    multicastAddr_arraysize = newSize;
}

class UdpLeaveMulticastGroupsCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_multicastAddr,
    };
  public:
    UdpLeaveMulticastGroupsCommandDescriptor();
    virtual ~UdpLeaveMulticastGroupsCommandDescriptor();

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

Register_ClassDescriptor(UdpLeaveMulticastGroupsCommandDescriptor)

UdpLeaveMulticastGroupsCommandDescriptor::UdpLeaveMulticastGroupsCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpLeaveMulticastGroupsCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpLeaveMulticastGroupsCommandDescriptor::~UdpLeaveMulticastGroupsCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpLeaveMulticastGroupsCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpLeaveMulticastGroupsCommand *>(obj)!=nullptr;
}

const char **UdpLeaveMulticastGroupsCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpLeaveMulticastGroupsCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpLeaveMulticastGroupsCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UdpLeaveMulticastGroupsCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY,    // FIELD_multicastAddr
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *UdpLeaveMulticastGroupsCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "multicastAddr",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int UdpLeaveMulticastGroupsCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "multicastAddr") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpLeaveMulticastGroupsCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_multicastAddr
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpLeaveMulticastGroupsCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpLeaveMulticastGroupsCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpLeaveMulticastGroupsCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpLeaveMulticastGroupsCommand *pp = (UdpLeaveMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case FIELD_multicastAddr: return pp->getMulticastAddrArraySize();
        default: return 0;
    }
}

const char *UdpLeaveMulticastGroupsCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpLeaveMulticastGroupsCommand *pp = (UdpLeaveMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpLeaveMulticastGroupsCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpLeaveMulticastGroupsCommand *pp = (UdpLeaveMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case FIELD_multicastAddr: return pp->getMulticastAddr(i).str();
        default: return "";
    }
}

bool UdpLeaveMulticastGroupsCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpLeaveMulticastGroupsCommand *pp = (UdpLeaveMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *UdpLeaveMulticastGroupsCommandDescriptor::getFieldStructName(int field) const
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

void *UdpLeaveMulticastGroupsCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpLeaveMulticastGroupsCommand *pp = (UdpLeaveMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case FIELD_multicastAddr: return toVoidPtr(&pp->getMulticastAddr(i)); break;
        default: return nullptr;
    }
}

Register_Class(UdpBlockMulticastSourcesCommand)

UdpBlockMulticastSourcesCommand::UdpBlockMulticastSourcesCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpBlockMulticastSourcesCommand::UdpBlockMulticastSourcesCommand(const UdpBlockMulticastSourcesCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpBlockMulticastSourcesCommand::~UdpBlockMulticastSourcesCommand()
{
    delete [] this->sourceList;
}

UdpBlockMulticastSourcesCommand& UdpBlockMulticastSourcesCommand::operator=(const UdpBlockMulticastSourcesCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpBlockMulticastSourcesCommand::copy(const UdpBlockMulticastSourcesCommand& other)
{
    this->interfaceId = other.interfaceId;
    this->multicastAddr = other.multicastAddr;
    delete [] this->sourceList;
    this->sourceList = (other.sourceList_arraysize==0) ? nullptr : new L3Address[other.sourceList_arraysize];
    sourceList_arraysize = other.sourceList_arraysize;
    for (size_t i = 0; i < sourceList_arraysize; i++) {
        this->sourceList[i] = other.sourceList[i];
    }
}

void UdpBlockMulticastSourcesCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->multicastAddr);
    b->pack(sourceList_arraysize);
    doParsimArrayPacking(b,this->sourceList,sourceList_arraysize);
}

void UdpBlockMulticastSourcesCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->multicastAddr);
    delete [] this->sourceList;
    b->unpack(sourceList_arraysize);
    if (sourceList_arraysize == 0) {
        this->sourceList = nullptr;
    } else {
        this->sourceList = new L3Address[sourceList_arraysize];
        doParsimArrayUnpacking(b,this->sourceList,sourceList_arraysize);
    }
}

int UdpBlockMulticastSourcesCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UdpBlockMulticastSourcesCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

const L3Address& UdpBlockMulticastSourcesCommand::getMulticastAddr() const
{
    return this->multicastAddr;
}

void UdpBlockMulticastSourcesCommand::setMulticastAddr(const L3Address& multicastAddr)
{
    this->multicastAddr = multicastAddr;
}

size_t UdpBlockMulticastSourcesCommand::getSourceListArraySize() const
{
    return sourceList_arraysize;
}

const L3Address& UdpBlockMulticastSourcesCommand::getSourceList(size_t k) const
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size sourceList_arraysize indexed by %lu", (unsigned long)k);
    return this->sourceList[k];
}

void UdpBlockMulticastSourcesCommand::setSourceListArraySize(size_t newSize)
{
    L3Address *sourceList2 = (newSize==0) ? nullptr : new L3Address[newSize];
    size_t minSize = sourceList_arraysize < newSize ? sourceList_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sourceList2[i] = this->sourceList[i];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

void UdpBlockMulticastSourcesCommand::setSourceList(size_t k, const L3Address& sourceList)
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->sourceList[k] = sourceList;
}

void UdpBlockMulticastSourcesCommand::insertSourceList(size_t k, const L3Address& sourceList)
{
    if (k > sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sourceList_arraysize + 1;
    L3Address *sourceList2 = new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceList2[i] = this->sourceList[i];
    sourceList2[k] = sourceList;
    for (i = k + 1; i < newSize; i++)
        sourceList2[i] = this->sourceList[i-1];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

void UdpBlockMulticastSourcesCommand::insertSourceList(const L3Address& sourceList)
{
    insertSourceList(sourceList_arraysize, sourceList);
}

void UdpBlockMulticastSourcesCommand::eraseSourceList(size_t k)
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sourceList_arraysize - 1;
    L3Address *sourceList2 = (newSize == 0) ? nullptr : new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceList2[i] = this->sourceList[i];
    for (i = k; i < newSize; i++)
        sourceList2[i] = this->sourceList[i+1];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

class UdpBlockMulticastSourcesCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_interfaceId,
        FIELD_multicastAddr,
        FIELD_sourceList,
    };
  public:
    UdpBlockMulticastSourcesCommandDescriptor();
    virtual ~UdpBlockMulticastSourcesCommandDescriptor();

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

Register_ClassDescriptor(UdpBlockMulticastSourcesCommandDescriptor)

UdpBlockMulticastSourcesCommandDescriptor::UdpBlockMulticastSourcesCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpBlockMulticastSourcesCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpBlockMulticastSourcesCommandDescriptor::~UdpBlockMulticastSourcesCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpBlockMulticastSourcesCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpBlockMulticastSourcesCommand *>(obj)!=nullptr;
}

const char **UdpBlockMulticastSourcesCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpBlockMulticastSourcesCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpBlockMulticastSourcesCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int UdpBlockMulticastSourcesCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_interfaceId
        0,    // FIELD_multicastAddr
        FD_ISARRAY,    // FIELD_sourceList
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *UdpBlockMulticastSourcesCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
        "multicastAddr",
        "sourceList",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int UdpBlockMulticastSourcesCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interfaceId") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "multicastAddr") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceList") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpBlockMulticastSourcesCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_interfaceId
        "inet::L3Address",    // FIELD_multicastAddr
        "inet::L3Address",    // FIELD_sourceList
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpBlockMulticastSourcesCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpBlockMulticastSourcesCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpBlockMulticastSourcesCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpBlockMulticastSourcesCommand *pp = (UdpBlockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_sourceList: return pp->getSourceListArraySize();
        default: return 0;
    }
}

const char *UdpBlockMulticastSourcesCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpBlockMulticastSourcesCommand *pp = (UdpBlockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpBlockMulticastSourcesCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpBlockMulticastSourcesCommand *pp = (UdpBlockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: return long2string(pp->getInterfaceId());
        case FIELD_multicastAddr: return pp->getMulticastAddr().str();
        case FIELD_sourceList: return pp->getSourceList(i).str();
        default: return "";
    }
}

bool UdpBlockMulticastSourcesCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpBlockMulticastSourcesCommand *pp = (UdpBlockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpBlockMulticastSourcesCommandDescriptor::getFieldStructName(int field) const
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

void *UdpBlockMulticastSourcesCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpBlockMulticastSourcesCommand *pp = (UdpBlockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_multicastAddr: return toVoidPtr(&pp->getMulticastAddr()); break;
        case FIELD_sourceList: return toVoidPtr(&pp->getSourceList(i)); break;
        default: return nullptr;
    }
}

Register_Class(UdpUnblockMulticastSourcesCommand)

UdpUnblockMulticastSourcesCommand::UdpUnblockMulticastSourcesCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpUnblockMulticastSourcesCommand::UdpUnblockMulticastSourcesCommand(const UdpUnblockMulticastSourcesCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpUnblockMulticastSourcesCommand::~UdpUnblockMulticastSourcesCommand()
{
    delete [] this->sourceList;
}

UdpUnblockMulticastSourcesCommand& UdpUnblockMulticastSourcesCommand::operator=(const UdpUnblockMulticastSourcesCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpUnblockMulticastSourcesCommand::copy(const UdpUnblockMulticastSourcesCommand& other)
{
    this->interfaceId = other.interfaceId;
    this->multicastAddr = other.multicastAddr;
    delete [] this->sourceList;
    this->sourceList = (other.sourceList_arraysize==0) ? nullptr : new L3Address[other.sourceList_arraysize];
    sourceList_arraysize = other.sourceList_arraysize;
    for (size_t i = 0; i < sourceList_arraysize; i++) {
        this->sourceList[i] = other.sourceList[i];
    }
}

void UdpUnblockMulticastSourcesCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->multicastAddr);
    b->pack(sourceList_arraysize);
    doParsimArrayPacking(b,this->sourceList,sourceList_arraysize);
}

void UdpUnblockMulticastSourcesCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->multicastAddr);
    delete [] this->sourceList;
    b->unpack(sourceList_arraysize);
    if (sourceList_arraysize == 0) {
        this->sourceList = nullptr;
    } else {
        this->sourceList = new L3Address[sourceList_arraysize];
        doParsimArrayUnpacking(b,this->sourceList,sourceList_arraysize);
    }
}

int UdpUnblockMulticastSourcesCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UdpUnblockMulticastSourcesCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

const L3Address& UdpUnblockMulticastSourcesCommand::getMulticastAddr() const
{
    return this->multicastAddr;
}

void UdpUnblockMulticastSourcesCommand::setMulticastAddr(const L3Address& multicastAddr)
{
    this->multicastAddr = multicastAddr;
}

size_t UdpUnblockMulticastSourcesCommand::getSourceListArraySize() const
{
    return sourceList_arraysize;
}

const L3Address& UdpUnblockMulticastSourcesCommand::getSourceList(size_t k) const
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size sourceList_arraysize indexed by %lu", (unsigned long)k);
    return this->sourceList[k];
}

void UdpUnblockMulticastSourcesCommand::setSourceListArraySize(size_t newSize)
{
    L3Address *sourceList2 = (newSize==0) ? nullptr : new L3Address[newSize];
    size_t minSize = sourceList_arraysize < newSize ? sourceList_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sourceList2[i] = this->sourceList[i];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

void UdpUnblockMulticastSourcesCommand::setSourceList(size_t k, const L3Address& sourceList)
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->sourceList[k] = sourceList;
}

void UdpUnblockMulticastSourcesCommand::insertSourceList(size_t k, const L3Address& sourceList)
{
    if (k > sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sourceList_arraysize + 1;
    L3Address *sourceList2 = new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceList2[i] = this->sourceList[i];
    sourceList2[k] = sourceList;
    for (i = k + 1; i < newSize; i++)
        sourceList2[i] = this->sourceList[i-1];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

void UdpUnblockMulticastSourcesCommand::insertSourceList(const L3Address& sourceList)
{
    insertSourceList(sourceList_arraysize, sourceList);
}

void UdpUnblockMulticastSourcesCommand::eraseSourceList(size_t k)
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sourceList_arraysize - 1;
    L3Address *sourceList2 = (newSize == 0) ? nullptr : new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceList2[i] = this->sourceList[i];
    for (i = k; i < newSize; i++)
        sourceList2[i] = this->sourceList[i+1];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

class UdpUnblockMulticastSourcesCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_interfaceId,
        FIELD_multicastAddr,
        FIELD_sourceList,
    };
  public:
    UdpUnblockMulticastSourcesCommandDescriptor();
    virtual ~UdpUnblockMulticastSourcesCommandDescriptor();

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

Register_ClassDescriptor(UdpUnblockMulticastSourcesCommandDescriptor)

UdpUnblockMulticastSourcesCommandDescriptor::UdpUnblockMulticastSourcesCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpUnblockMulticastSourcesCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpUnblockMulticastSourcesCommandDescriptor::~UdpUnblockMulticastSourcesCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpUnblockMulticastSourcesCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpUnblockMulticastSourcesCommand *>(obj)!=nullptr;
}

const char **UdpUnblockMulticastSourcesCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpUnblockMulticastSourcesCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpUnblockMulticastSourcesCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int UdpUnblockMulticastSourcesCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_interfaceId
        0,    // FIELD_multicastAddr
        FD_ISARRAY,    // FIELD_sourceList
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *UdpUnblockMulticastSourcesCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
        "multicastAddr",
        "sourceList",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int UdpUnblockMulticastSourcesCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interfaceId") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "multicastAddr") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceList") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpUnblockMulticastSourcesCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_interfaceId
        "inet::L3Address",    // FIELD_multicastAddr
        "inet::L3Address",    // FIELD_sourceList
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpUnblockMulticastSourcesCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpUnblockMulticastSourcesCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpUnblockMulticastSourcesCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpUnblockMulticastSourcesCommand *pp = (UdpUnblockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_sourceList: return pp->getSourceListArraySize();
        default: return 0;
    }
}

const char *UdpUnblockMulticastSourcesCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpUnblockMulticastSourcesCommand *pp = (UdpUnblockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpUnblockMulticastSourcesCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpUnblockMulticastSourcesCommand *pp = (UdpUnblockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: return long2string(pp->getInterfaceId());
        case FIELD_multicastAddr: return pp->getMulticastAddr().str();
        case FIELD_sourceList: return pp->getSourceList(i).str();
        default: return "";
    }
}

bool UdpUnblockMulticastSourcesCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpUnblockMulticastSourcesCommand *pp = (UdpUnblockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpUnblockMulticastSourcesCommandDescriptor::getFieldStructName(int field) const
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

void *UdpUnblockMulticastSourcesCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpUnblockMulticastSourcesCommand *pp = (UdpUnblockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_multicastAddr: return toVoidPtr(&pp->getMulticastAddr()); break;
        case FIELD_sourceList: return toVoidPtr(&pp->getSourceList(i)); break;
        default: return nullptr;
    }
}

Register_Class(UdpJoinMulticastSourcesCommand)

UdpJoinMulticastSourcesCommand::UdpJoinMulticastSourcesCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpJoinMulticastSourcesCommand::UdpJoinMulticastSourcesCommand(const UdpJoinMulticastSourcesCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpJoinMulticastSourcesCommand::~UdpJoinMulticastSourcesCommand()
{
    delete [] this->sourceList;
}

UdpJoinMulticastSourcesCommand& UdpJoinMulticastSourcesCommand::operator=(const UdpJoinMulticastSourcesCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpJoinMulticastSourcesCommand::copy(const UdpJoinMulticastSourcesCommand& other)
{
    this->interfaceId = other.interfaceId;
    this->multicastAddr = other.multicastAddr;
    delete [] this->sourceList;
    this->sourceList = (other.sourceList_arraysize==0) ? nullptr : new L3Address[other.sourceList_arraysize];
    sourceList_arraysize = other.sourceList_arraysize;
    for (size_t i = 0; i < sourceList_arraysize; i++) {
        this->sourceList[i] = other.sourceList[i];
    }
}

void UdpJoinMulticastSourcesCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->multicastAddr);
    b->pack(sourceList_arraysize);
    doParsimArrayPacking(b,this->sourceList,sourceList_arraysize);
}

void UdpJoinMulticastSourcesCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->multicastAddr);
    delete [] this->sourceList;
    b->unpack(sourceList_arraysize);
    if (sourceList_arraysize == 0) {
        this->sourceList = nullptr;
    } else {
        this->sourceList = new L3Address[sourceList_arraysize];
        doParsimArrayUnpacking(b,this->sourceList,sourceList_arraysize);
    }
}

int UdpJoinMulticastSourcesCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UdpJoinMulticastSourcesCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

const L3Address& UdpJoinMulticastSourcesCommand::getMulticastAddr() const
{
    return this->multicastAddr;
}

void UdpJoinMulticastSourcesCommand::setMulticastAddr(const L3Address& multicastAddr)
{
    this->multicastAddr = multicastAddr;
}

size_t UdpJoinMulticastSourcesCommand::getSourceListArraySize() const
{
    return sourceList_arraysize;
}

const L3Address& UdpJoinMulticastSourcesCommand::getSourceList(size_t k) const
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size sourceList_arraysize indexed by %lu", (unsigned long)k);
    return this->sourceList[k];
}

void UdpJoinMulticastSourcesCommand::setSourceListArraySize(size_t newSize)
{
    L3Address *sourceList2 = (newSize==0) ? nullptr : new L3Address[newSize];
    size_t minSize = sourceList_arraysize < newSize ? sourceList_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sourceList2[i] = this->sourceList[i];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

void UdpJoinMulticastSourcesCommand::setSourceList(size_t k, const L3Address& sourceList)
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->sourceList[k] = sourceList;
}

void UdpJoinMulticastSourcesCommand::insertSourceList(size_t k, const L3Address& sourceList)
{
    if (k > sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sourceList_arraysize + 1;
    L3Address *sourceList2 = new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceList2[i] = this->sourceList[i];
    sourceList2[k] = sourceList;
    for (i = k + 1; i < newSize; i++)
        sourceList2[i] = this->sourceList[i-1];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

void UdpJoinMulticastSourcesCommand::insertSourceList(const L3Address& sourceList)
{
    insertSourceList(sourceList_arraysize, sourceList);
}

void UdpJoinMulticastSourcesCommand::eraseSourceList(size_t k)
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sourceList_arraysize - 1;
    L3Address *sourceList2 = (newSize == 0) ? nullptr : new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceList2[i] = this->sourceList[i];
    for (i = k; i < newSize; i++)
        sourceList2[i] = this->sourceList[i+1];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

class UdpJoinMulticastSourcesCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_interfaceId,
        FIELD_multicastAddr,
        FIELD_sourceList,
    };
  public:
    UdpJoinMulticastSourcesCommandDescriptor();
    virtual ~UdpJoinMulticastSourcesCommandDescriptor();

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

Register_ClassDescriptor(UdpJoinMulticastSourcesCommandDescriptor)

UdpJoinMulticastSourcesCommandDescriptor::UdpJoinMulticastSourcesCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpJoinMulticastSourcesCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpJoinMulticastSourcesCommandDescriptor::~UdpJoinMulticastSourcesCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpJoinMulticastSourcesCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpJoinMulticastSourcesCommand *>(obj)!=nullptr;
}

const char **UdpJoinMulticastSourcesCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpJoinMulticastSourcesCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpJoinMulticastSourcesCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int UdpJoinMulticastSourcesCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_interfaceId
        0,    // FIELD_multicastAddr
        FD_ISARRAY,    // FIELD_sourceList
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *UdpJoinMulticastSourcesCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
        "multicastAddr",
        "sourceList",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int UdpJoinMulticastSourcesCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interfaceId") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "multicastAddr") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceList") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpJoinMulticastSourcesCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_interfaceId
        "inet::L3Address",    // FIELD_multicastAddr
        "inet::L3Address",    // FIELD_sourceList
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpJoinMulticastSourcesCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpJoinMulticastSourcesCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpJoinMulticastSourcesCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpJoinMulticastSourcesCommand *pp = (UdpJoinMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_sourceList: return pp->getSourceListArraySize();
        default: return 0;
    }
}

const char *UdpJoinMulticastSourcesCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpJoinMulticastSourcesCommand *pp = (UdpJoinMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpJoinMulticastSourcesCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpJoinMulticastSourcesCommand *pp = (UdpJoinMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: return long2string(pp->getInterfaceId());
        case FIELD_multicastAddr: return pp->getMulticastAddr().str();
        case FIELD_sourceList: return pp->getSourceList(i).str();
        default: return "";
    }
}

bool UdpJoinMulticastSourcesCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpJoinMulticastSourcesCommand *pp = (UdpJoinMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpJoinMulticastSourcesCommandDescriptor::getFieldStructName(int field) const
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

void *UdpJoinMulticastSourcesCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpJoinMulticastSourcesCommand *pp = (UdpJoinMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_multicastAddr: return toVoidPtr(&pp->getMulticastAddr()); break;
        case FIELD_sourceList: return toVoidPtr(&pp->getSourceList(i)); break;
        default: return nullptr;
    }
}

Register_Class(UdpLeaveMulticastSourcesCommand)

UdpLeaveMulticastSourcesCommand::UdpLeaveMulticastSourcesCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpLeaveMulticastSourcesCommand::UdpLeaveMulticastSourcesCommand(const UdpLeaveMulticastSourcesCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpLeaveMulticastSourcesCommand::~UdpLeaveMulticastSourcesCommand()
{
    delete [] this->sourceList;
}

UdpLeaveMulticastSourcesCommand& UdpLeaveMulticastSourcesCommand::operator=(const UdpLeaveMulticastSourcesCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpLeaveMulticastSourcesCommand::copy(const UdpLeaveMulticastSourcesCommand& other)
{
    this->interfaceId = other.interfaceId;
    this->multicastAddr = other.multicastAddr;
    delete [] this->sourceList;
    this->sourceList = (other.sourceList_arraysize==0) ? nullptr : new L3Address[other.sourceList_arraysize];
    sourceList_arraysize = other.sourceList_arraysize;
    for (size_t i = 0; i < sourceList_arraysize; i++) {
        this->sourceList[i] = other.sourceList[i];
    }
}

void UdpLeaveMulticastSourcesCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->multicastAddr);
    b->pack(sourceList_arraysize);
    doParsimArrayPacking(b,this->sourceList,sourceList_arraysize);
}

void UdpLeaveMulticastSourcesCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->multicastAddr);
    delete [] this->sourceList;
    b->unpack(sourceList_arraysize);
    if (sourceList_arraysize == 0) {
        this->sourceList = nullptr;
    } else {
        this->sourceList = new L3Address[sourceList_arraysize];
        doParsimArrayUnpacking(b,this->sourceList,sourceList_arraysize);
    }
}

int UdpLeaveMulticastSourcesCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UdpLeaveMulticastSourcesCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

const L3Address& UdpLeaveMulticastSourcesCommand::getMulticastAddr() const
{
    return this->multicastAddr;
}

void UdpLeaveMulticastSourcesCommand::setMulticastAddr(const L3Address& multicastAddr)
{
    this->multicastAddr = multicastAddr;
}

size_t UdpLeaveMulticastSourcesCommand::getSourceListArraySize() const
{
    return sourceList_arraysize;
}

const L3Address& UdpLeaveMulticastSourcesCommand::getSourceList(size_t k) const
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size sourceList_arraysize indexed by %lu", (unsigned long)k);
    return this->sourceList[k];
}

void UdpLeaveMulticastSourcesCommand::setSourceListArraySize(size_t newSize)
{
    L3Address *sourceList2 = (newSize==0) ? nullptr : new L3Address[newSize];
    size_t minSize = sourceList_arraysize < newSize ? sourceList_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sourceList2[i] = this->sourceList[i];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

void UdpLeaveMulticastSourcesCommand::setSourceList(size_t k, const L3Address& sourceList)
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->sourceList[k] = sourceList;
}

void UdpLeaveMulticastSourcesCommand::insertSourceList(size_t k, const L3Address& sourceList)
{
    if (k > sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sourceList_arraysize + 1;
    L3Address *sourceList2 = new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceList2[i] = this->sourceList[i];
    sourceList2[k] = sourceList;
    for (i = k + 1; i < newSize; i++)
        sourceList2[i] = this->sourceList[i-1];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

void UdpLeaveMulticastSourcesCommand::insertSourceList(const L3Address& sourceList)
{
    insertSourceList(sourceList_arraysize, sourceList);
}

void UdpLeaveMulticastSourcesCommand::eraseSourceList(size_t k)
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sourceList_arraysize - 1;
    L3Address *sourceList2 = (newSize == 0) ? nullptr : new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceList2[i] = this->sourceList[i];
    for (i = k; i < newSize; i++)
        sourceList2[i] = this->sourceList[i+1];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

class UdpLeaveMulticastSourcesCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_interfaceId,
        FIELD_multicastAddr,
        FIELD_sourceList,
    };
  public:
    UdpLeaveMulticastSourcesCommandDescriptor();
    virtual ~UdpLeaveMulticastSourcesCommandDescriptor();

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

Register_ClassDescriptor(UdpLeaveMulticastSourcesCommandDescriptor)

UdpLeaveMulticastSourcesCommandDescriptor::UdpLeaveMulticastSourcesCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpLeaveMulticastSourcesCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpLeaveMulticastSourcesCommandDescriptor::~UdpLeaveMulticastSourcesCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpLeaveMulticastSourcesCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpLeaveMulticastSourcesCommand *>(obj)!=nullptr;
}

const char **UdpLeaveMulticastSourcesCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpLeaveMulticastSourcesCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpLeaveMulticastSourcesCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int UdpLeaveMulticastSourcesCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_interfaceId
        0,    // FIELD_multicastAddr
        FD_ISARRAY,    // FIELD_sourceList
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *UdpLeaveMulticastSourcesCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
        "multicastAddr",
        "sourceList",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int UdpLeaveMulticastSourcesCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interfaceId") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "multicastAddr") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceList") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpLeaveMulticastSourcesCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_interfaceId
        "inet::L3Address",    // FIELD_multicastAddr
        "inet::L3Address",    // FIELD_sourceList
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpLeaveMulticastSourcesCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpLeaveMulticastSourcesCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpLeaveMulticastSourcesCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpLeaveMulticastSourcesCommand *pp = (UdpLeaveMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_sourceList: return pp->getSourceListArraySize();
        default: return 0;
    }
}

const char *UdpLeaveMulticastSourcesCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpLeaveMulticastSourcesCommand *pp = (UdpLeaveMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpLeaveMulticastSourcesCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpLeaveMulticastSourcesCommand *pp = (UdpLeaveMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: return long2string(pp->getInterfaceId());
        case FIELD_multicastAddr: return pp->getMulticastAddr().str();
        case FIELD_sourceList: return pp->getSourceList(i).str();
        default: return "";
    }
}

bool UdpLeaveMulticastSourcesCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpLeaveMulticastSourcesCommand *pp = (UdpLeaveMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpLeaveMulticastSourcesCommandDescriptor::getFieldStructName(int field) const
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

void *UdpLeaveMulticastSourcesCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpLeaveMulticastSourcesCommand *pp = (UdpLeaveMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case FIELD_multicastAddr: return toVoidPtr(&pp->getMulticastAddr()); break;
        case FIELD_sourceList: return toVoidPtr(&pp->getSourceList(i)); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::UdpSourceFilterMode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::UdpSourceFilterMode"));
    e->insert(UDP_INCLUDE_MCAST_SOURCES, "UDP_INCLUDE_MCAST_SOURCES");
    e->insert(UDP_EXCLUDE_MCAST_SOURCES, "UDP_EXCLUDE_MCAST_SOURCES");
)

Register_Class(UdpSetMulticastSourceFilterCommand)

UdpSetMulticastSourceFilterCommand::UdpSetMulticastSourceFilterCommand() : ::inet::UdpSetOptionCommand()
{
}

UdpSetMulticastSourceFilterCommand::UdpSetMulticastSourceFilterCommand(const UdpSetMulticastSourceFilterCommand& other) : ::inet::UdpSetOptionCommand(other)
{
    copy(other);
}

UdpSetMulticastSourceFilterCommand::~UdpSetMulticastSourceFilterCommand()
{
    delete [] this->sourceList;
}

UdpSetMulticastSourceFilterCommand& UdpSetMulticastSourceFilterCommand::operator=(const UdpSetMulticastSourceFilterCommand& other)
{
    if (this == &other) return *this;
    ::inet::UdpSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UdpSetMulticastSourceFilterCommand::copy(const UdpSetMulticastSourceFilterCommand& other)
{
    this->interfaceId = other.interfaceId;
    this->multicastAddr = other.multicastAddr;
    this->filterMode = other.filterMode;
    delete [] this->sourceList;
    this->sourceList = (other.sourceList_arraysize==0) ? nullptr : new L3Address[other.sourceList_arraysize];
    sourceList_arraysize = other.sourceList_arraysize;
    for (size_t i = 0; i < sourceList_arraysize; i++) {
        this->sourceList[i] = other.sourceList[i];
    }
}

void UdpSetMulticastSourceFilterCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UdpSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->multicastAddr);
    doParsimPacking(b,this->filterMode);
    b->pack(sourceList_arraysize);
    doParsimArrayPacking(b,this->sourceList,sourceList_arraysize);
}

void UdpSetMulticastSourceFilterCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UdpSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->multicastAddr);
    doParsimUnpacking(b,this->filterMode);
    delete [] this->sourceList;
    b->unpack(sourceList_arraysize);
    if (sourceList_arraysize == 0) {
        this->sourceList = nullptr;
    } else {
        this->sourceList = new L3Address[sourceList_arraysize];
        doParsimArrayUnpacking(b,this->sourceList,sourceList_arraysize);
    }
}

int UdpSetMulticastSourceFilterCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UdpSetMulticastSourceFilterCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

const L3Address& UdpSetMulticastSourceFilterCommand::getMulticastAddr() const
{
    return this->multicastAddr;
}

void UdpSetMulticastSourceFilterCommand::setMulticastAddr(const L3Address& multicastAddr)
{
    this->multicastAddr = multicastAddr;
}

inet::UdpSourceFilterMode UdpSetMulticastSourceFilterCommand::getFilterMode() const
{
    return this->filterMode;
}

void UdpSetMulticastSourceFilterCommand::setFilterMode(inet::UdpSourceFilterMode filterMode)
{
    this->filterMode = filterMode;
}

size_t UdpSetMulticastSourceFilterCommand::getSourceListArraySize() const
{
    return sourceList_arraysize;
}

const L3Address& UdpSetMulticastSourceFilterCommand::getSourceList(size_t k) const
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size sourceList_arraysize indexed by %lu", (unsigned long)k);
    return this->sourceList[k];
}

void UdpSetMulticastSourceFilterCommand::setSourceListArraySize(size_t newSize)
{
    L3Address *sourceList2 = (newSize==0) ? nullptr : new L3Address[newSize];
    size_t minSize = sourceList_arraysize < newSize ? sourceList_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sourceList2[i] = this->sourceList[i];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

void UdpSetMulticastSourceFilterCommand::setSourceList(size_t k, const L3Address& sourceList)
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->sourceList[k] = sourceList;
}

void UdpSetMulticastSourceFilterCommand::insertSourceList(size_t k, const L3Address& sourceList)
{
    if (k > sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sourceList_arraysize + 1;
    L3Address *sourceList2 = new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceList2[i] = this->sourceList[i];
    sourceList2[k] = sourceList;
    for (i = k + 1; i < newSize; i++)
        sourceList2[i] = this->sourceList[i-1];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

void UdpSetMulticastSourceFilterCommand::insertSourceList(const L3Address& sourceList)
{
    insertSourceList(sourceList_arraysize, sourceList);
}

void UdpSetMulticastSourceFilterCommand::eraseSourceList(size_t k)
{
    if (k >= sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = sourceList_arraysize - 1;
    L3Address *sourceList2 = (newSize == 0) ? nullptr : new L3Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sourceList2[i] = this->sourceList[i];
    for (i = k; i < newSize; i++)
        sourceList2[i] = this->sourceList[i+1];
    delete [] this->sourceList;
    this->sourceList = sourceList2;
    sourceList_arraysize = newSize;
}

class UdpSetMulticastSourceFilterCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_interfaceId,
        FIELD_multicastAddr,
        FIELD_filterMode,
        FIELD_sourceList,
    };
  public:
    UdpSetMulticastSourceFilterCommandDescriptor();
    virtual ~UdpSetMulticastSourceFilterCommandDescriptor();

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

Register_ClassDescriptor(UdpSetMulticastSourceFilterCommandDescriptor)

UdpSetMulticastSourceFilterCommandDescriptor::UdpSetMulticastSourceFilterCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpSetMulticastSourceFilterCommand)), "inet::UdpSetOptionCommand")
{
    propertynames = nullptr;
}

UdpSetMulticastSourceFilterCommandDescriptor::~UdpSetMulticastSourceFilterCommandDescriptor()
{
    delete[] propertynames;
}

bool UdpSetMulticastSourceFilterCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpSetMulticastSourceFilterCommand *>(obj)!=nullptr;
}

const char **UdpSetMulticastSourceFilterCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpSetMulticastSourceFilterCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpSetMulticastSourceFilterCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int UdpSetMulticastSourceFilterCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_interfaceId
        0,    // FIELD_multicastAddr
        0,    // FIELD_filterMode
        FD_ISARRAY,    // FIELD_sourceList
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *UdpSetMulticastSourceFilterCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
        "multicastAddr",
        "filterMode",
        "sourceList",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int UdpSetMulticastSourceFilterCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interfaceId") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "multicastAddr") == 0) return base+1;
    if (fieldName[0] == 'f' && strcmp(fieldName, "filterMode") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceList") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpSetMulticastSourceFilterCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_interfaceId
        "inet::L3Address",    // FIELD_multicastAddr
        "inet::UdpSourceFilterMode",    // FIELD_filterMode
        "inet::L3Address",    // FIELD_sourceList
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpSetMulticastSourceFilterCommandDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_filterMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *UdpSetMulticastSourceFilterCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_filterMode:
            if (!strcmp(propertyname, "enum")) return "inet::UdpSourceFilterMode";
            return nullptr;
        default: return nullptr;
    }
}

int UdpSetMulticastSourceFilterCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastSourceFilterCommand *pp = (UdpSetMulticastSourceFilterCommand *)object; (void)pp;
    switch (field) {
        case FIELD_sourceList: return pp->getSourceListArraySize();
        default: return 0;
    }
}

const char *UdpSetMulticastSourceFilterCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastSourceFilterCommand *pp = (UdpSetMulticastSourceFilterCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpSetMulticastSourceFilterCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastSourceFilterCommand *pp = (UdpSetMulticastSourceFilterCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: return long2string(pp->getInterfaceId());
        case FIELD_multicastAddr: return pp->getMulticastAddr().str();
        case FIELD_filterMode: return enum2string(pp->getFilterMode(), "inet::UdpSourceFilterMode");
        case FIELD_sourceList: return pp->getSourceList(i).str();
        default: return "";
    }
}

bool UdpSetMulticastSourceFilterCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastSourceFilterCommand *pp = (UdpSetMulticastSourceFilterCommand *)object; (void)pp;
    switch (field) {
        case FIELD_interfaceId: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpSetMulticastSourceFilterCommandDescriptor::getFieldStructName(int field) const
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

void *UdpSetMulticastSourceFilterCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpSetMulticastSourceFilterCommand *pp = (UdpSetMulticastSourceFilterCommand *)object; (void)pp;
    switch (field) {
        case FIELD_multicastAddr: return toVoidPtr(&pp->getMulticastAddr()); break;
        case FIELD_sourceList: return toVoidPtr(&pp->getSourceList(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

