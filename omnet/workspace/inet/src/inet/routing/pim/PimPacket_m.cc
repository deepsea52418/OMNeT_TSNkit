//
// Generated file, do not edit! Created by nedtool 5.6 from inet/routing/pim/PimPacket.msg.
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
#include "PimPacket_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::PimPacketType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::PimPacketType"));
    e->insert(Hello, "Hello");
    e->insert(Register, "Register");
    e->insert(RegisterStop, "RegisterStop");
    e->insert(JoinPrune, "JoinPrune");
    e->insert(Bootstrap, "Bootstrap");
    e->insert(Assert, "Assert");
    e->insert(Graft, "Graft");
    e->insert(GraftAck, "GraftAck");
    e->insert(CandidateRPAdvertisement, "CandidateRPAdvertisement");
    e->insert(StateRefresh, "StateRefresh");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::PimHelloOptionType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::PimHelloOptionType"));
    e->insert(Holdtime, "Holdtime");
    e->insert(LANPruneDelay, "LANPruneDelay");
    e->insert(DRPriority, "DRPriority");
    e->insert(GenerationID, "GenerationID");
    e->insert(StateRefreshCapable, "StateRefreshCapable");
    e->insert(AddressList, "AddressList");
)

Register_Class(HelloOption)

HelloOption::HelloOption() : ::omnetpp::cObject()
{
}

HelloOption::HelloOption(const HelloOption& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

HelloOption::~HelloOption()
{
}

HelloOption& HelloOption::operator=(const HelloOption& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void HelloOption::copy(const HelloOption& other)
{
    this->type = other.type;
}

void HelloOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->type);
}

void HelloOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->type);
}

inet::PimHelloOptionType HelloOption::getType() const
{
    return this->type;
}

void HelloOption::setType(inet::PimHelloOptionType type)
{
    this->type = type;
}

class HelloOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
    };
  public:
    HelloOptionDescriptor();
    virtual ~HelloOptionDescriptor();

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

Register_ClassDescriptor(HelloOptionDescriptor)

HelloOptionDescriptor::HelloOptionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::HelloOption)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

HelloOptionDescriptor::~HelloOptionDescriptor()
{
    delete[] propertynames;
}

bool HelloOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HelloOption *>(obj)!=nullptr;
}

const char **HelloOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HelloOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HelloOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int HelloOptionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *HelloOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int HelloOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HelloOptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::PimHelloOptionType",    // FIELD_type
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **HelloOptionDescriptor::getFieldPropertyNames(int field) const
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

const char *HelloOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::PimHelloOptionType";
            return nullptr;
        default: return nullptr;
    }
}

int HelloOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    HelloOption *pp = (HelloOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *HelloOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HelloOption *pp = (HelloOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HelloOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HelloOption *pp = (HelloOption *)object; (void)pp;
    switch (field) {
        case FIELD_type: return enum2string(pp->getType(), "inet::PimHelloOptionType");
        default: return "";
    }
}

bool HelloOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    HelloOption *pp = (HelloOption *)object; (void)pp;
    switch (field) {
        case FIELD_type: pp->setType((inet::PimHelloOptionType)string2enum(value, "inet::PimHelloOptionType")); return true;
        default: return false;
    }
}

const char *HelloOptionDescriptor::getFieldStructName(int field) const
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

void *HelloOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    HelloOption *pp = (HelloOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(HoldtimeOption)

HoldtimeOption::HoldtimeOption() : ::inet::HelloOption()
{
    this->setType(Holdtime);

}

HoldtimeOption::HoldtimeOption(const HoldtimeOption& other) : ::inet::HelloOption(other)
{
    copy(other);
}

HoldtimeOption::~HoldtimeOption()
{
}

HoldtimeOption& HoldtimeOption::operator=(const HoldtimeOption& other)
{
    if (this == &other) return *this;
    ::inet::HelloOption::operator=(other);
    copy(other);
    return *this;
}

void HoldtimeOption::copy(const HoldtimeOption& other)
{
    this->holdTime = other.holdTime;
}

void HoldtimeOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::HelloOption::parsimPack(b);
    doParsimPacking(b,this->holdTime);
}

void HoldtimeOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::HelloOption::parsimUnpack(b);
    doParsimUnpacking(b,this->holdTime);
}

uint16_t HoldtimeOption::getHoldTime() const
{
    return this->holdTime;
}

void HoldtimeOption::setHoldTime(uint16_t holdTime)
{
    this->holdTime = holdTime;
}

class HoldtimeOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_holdTime,
    };
  public:
    HoldtimeOptionDescriptor();
    virtual ~HoldtimeOptionDescriptor();

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

Register_ClassDescriptor(HoldtimeOptionDescriptor)

HoldtimeOptionDescriptor::HoldtimeOptionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::HoldtimeOption)), "inet::HelloOption")
{
    propertynames = nullptr;
}

HoldtimeOptionDescriptor::~HoldtimeOptionDescriptor()
{
    delete[] propertynames;
}

bool HoldtimeOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HoldtimeOption *>(obj)!=nullptr;
}

const char **HoldtimeOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HoldtimeOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HoldtimeOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int HoldtimeOptionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_holdTime
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *HoldtimeOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "holdTime",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int HoldtimeOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "holdTime") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HoldtimeOptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_holdTime
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **HoldtimeOptionDescriptor::getFieldPropertyNames(int field) const
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

const char *HoldtimeOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int HoldtimeOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    HoldtimeOption *pp = (HoldtimeOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *HoldtimeOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HoldtimeOption *pp = (HoldtimeOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HoldtimeOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HoldtimeOption *pp = (HoldtimeOption *)object; (void)pp;
    switch (field) {
        case FIELD_holdTime: return ulong2string(pp->getHoldTime());
        default: return "";
    }
}

bool HoldtimeOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    HoldtimeOption *pp = (HoldtimeOption *)object; (void)pp;
    switch (field) {
        case FIELD_holdTime: pp->setHoldTime(string2ulong(value)); return true;
        default: return false;
    }
}

const char *HoldtimeOptionDescriptor::getFieldStructName(int field) const
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

void *HoldtimeOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    HoldtimeOption *pp = (HoldtimeOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(LanPruneDelayOption)

LanPruneDelayOption::LanPruneDelayOption() : ::inet::HelloOption()
{
    this->setType(LANPruneDelay);

}

LanPruneDelayOption::LanPruneDelayOption(const LanPruneDelayOption& other) : ::inet::HelloOption(other)
{
    copy(other);
}

LanPruneDelayOption::~LanPruneDelayOption()
{
}

LanPruneDelayOption& LanPruneDelayOption::operator=(const LanPruneDelayOption& other)
{
    if (this == &other) return *this;
    ::inet::HelloOption::operator=(other);
    copy(other);
    return *this;
}

void LanPruneDelayOption::copy(const LanPruneDelayOption& other)
{
    this->propagationDelay = other.propagationDelay;
    this->overrideInterval = other.overrideInterval;
}

void LanPruneDelayOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::HelloOption::parsimPack(b);
    doParsimPacking(b,this->propagationDelay);
    doParsimPacking(b,this->overrideInterval);
}

void LanPruneDelayOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::HelloOption::parsimUnpack(b);
    doParsimUnpacking(b,this->propagationDelay);
    doParsimUnpacking(b,this->overrideInterval);
}

uint16_t LanPruneDelayOption::getPropagationDelay() const
{
    return this->propagationDelay;
}

void LanPruneDelayOption::setPropagationDelay(uint16_t propagationDelay)
{
    this->propagationDelay = propagationDelay;
}

uint16_t LanPruneDelayOption::getOverrideInterval() const
{
    return this->overrideInterval;
}

void LanPruneDelayOption::setOverrideInterval(uint16_t overrideInterval)
{
    this->overrideInterval = overrideInterval;
}

class LanPruneDelayOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_propagationDelay,
        FIELD_overrideInterval,
    };
  public:
    LanPruneDelayOptionDescriptor();
    virtual ~LanPruneDelayOptionDescriptor();

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

Register_ClassDescriptor(LanPruneDelayOptionDescriptor)

LanPruneDelayOptionDescriptor::LanPruneDelayOptionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::LanPruneDelayOption)), "inet::HelloOption")
{
    propertynames = nullptr;
}

LanPruneDelayOptionDescriptor::~LanPruneDelayOptionDescriptor()
{
    delete[] propertynames;
}

bool LanPruneDelayOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LanPruneDelayOption *>(obj)!=nullptr;
}

const char **LanPruneDelayOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LanPruneDelayOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LanPruneDelayOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int LanPruneDelayOptionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_propagationDelay
        FD_ISEDITABLE,    // FIELD_overrideInterval
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *LanPruneDelayOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "propagationDelay",
        "overrideInterval",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int LanPruneDelayOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "propagationDelay") == 0) return base+0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "overrideInterval") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LanPruneDelayOptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_propagationDelay
        "uint16_t",    // FIELD_overrideInterval
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **LanPruneDelayOptionDescriptor::getFieldPropertyNames(int field) const
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

const char *LanPruneDelayOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LanPruneDelayOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LanPruneDelayOption *pp = (LanPruneDelayOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LanPruneDelayOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LanPruneDelayOption *pp = (LanPruneDelayOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LanPruneDelayOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LanPruneDelayOption *pp = (LanPruneDelayOption *)object; (void)pp;
    switch (field) {
        case FIELD_propagationDelay: return ulong2string(pp->getPropagationDelay());
        case FIELD_overrideInterval: return ulong2string(pp->getOverrideInterval());
        default: return "";
    }
}

bool LanPruneDelayOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LanPruneDelayOption *pp = (LanPruneDelayOption *)object; (void)pp;
    switch (field) {
        case FIELD_propagationDelay: pp->setPropagationDelay(string2ulong(value)); return true;
        case FIELD_overrideInterval: pp->setOverrideInterval(string2ulong(value)); return true;
        default: return false;
    }
}

const char *LanPruneDelayOptionDescriptor::getFieldStructName(int field) const
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

void *LanPruneDelayOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LanPruneDelayOption *pp = (LanPruneDelayOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(DrPriorityOption)

DrPriorityOption::DrPriorityOption() : ::inet::HelloOption()
{
    this->setType(DRPriority);

}

DrPriorityOption::DrPriorityOption(const DrPriorityOption& other) : ::inet::HelloOption(other)
{
    copy(other);
}

DrPriorityOption::~DrPriorityOption()
{
}

DrPriorityOption& DrPriorityOption::operator=(const DrPriorityOption& other)
{
    if (this == &other) return *this;
    ::inet::HelloOption::operator=(other);
    copy(other);
    return *this;
}

void DrPriorityOption::copy(const DrPriorityOption& other)
{
    this->priority = other.priority;
}

void DrPriorityOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::HelloOption::parsimPack(b);
    doParsimPacking(b,this->priority);
}

void DrPriorityOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::HelloOption::parsimUnpack(b);
    doParsimUnpacking(b,this->priority);
}

uint32_t DrPriorityOption::getPriority() const
{
    return this->priority;
}

void DrPriorityOption::setPriority(uint32_t priority)
{
    this->priority = priority;
}

class DrPriorityOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_priority,
    };
  public:
    DrPriorityOptionDescriptor();
    virtual ~DrPriorityOptionDescriptor();

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

Register_ClassDescriptor(DrPriorityOptionDescriptor)

DrPriorityOptionDescriptor::DrPriorityOptionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::DrPriorityOption)), "inet::HelloOption")
{
    propertynames = nullptr;
}

DrPriorityOptionDescriptor::~DrPriorityOptionDescriptor()
{
    delete[] propertynames;
}

bool DrPriorityOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DrPriorityOption *>(obj)!=nullptr;
}

const char **DrPriorityOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DrPriorityOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DrPriorityOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int DrPriorityOptionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_priority
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *DrPriorityOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "priority",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int DrPriorityOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "priority") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DrPriorityOptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_priority
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **DrPriorityOptionDescriptor::getFieldPropertyNames(int field) const
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

const char *DrPriorityOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int DrPriorityOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DrPriorityOption *pp = (DrPriorityOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *DrPriorityOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DrPriorityOption *pp = (DrPriorityOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DrPriorityOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DrPriorityOption *pp = (DrPriorityOption *)object; (void)pp;
    switch (field) {
        case FIELD_priority: return ulong2string(pp->getPriority());
        default: return "";
    }
}

bool DrPriorityOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DrPriorityOption *pp = (DrPriorityOption *)object; (void)pp;
    switch (field) {
        case FIELD_priority: pp->setPriority(string2ulong(value)); return true;
        default: return false;
    }
}

const char *DrPriorityOptionDescriptor::getFieldStructName(int field) const
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

void *DrPriorityOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DrPriorityOption *pp = (DrPriorityOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(GenerationIdOption)

GenerationIdOption::GenerationIdOption() : ::inet::HelloOption()
{
    this->setType(GenerationID);

}

GenerationIdOption::GenerationIdOption(const GenerationIdOption& other) : ::inet::HelloOption(other)
{
    copy(other);
}

GenerationIdOption::~GenerationIdOption()
{
}

GenerationIdOption& GenerationIdOption::operator=(const GenerationIdOption& other)
{
    if (this == &other) return *this;
    ::inet::HelloOption::operator=(other);
    copy(other);
    return *this;
}

void GenerationIdOption::copy(const GenerationIdOption& other)
{
    this->generationID = other.generationID;
}

void GenerationIdOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::HelloOption::parsimPack(b);
    doParsimPacking(b,this->generationID);
}

void GenerationIdOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::HelloOption::parsimUnpack(b);
    doParsimUnpacking(b,this->generationID);
}

uint32_t GenerationIdOption::getGenerationID() const
{
    return this->generationID;
}

void GenerationIdOption::setGenerationID(uint32_t generationID)
{
    this->generationID = generationID;
}

class GenerationIdOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_generationID,
    };
  public:
    GenerationIdOptionDescriptor();
    virtual ~GenerationIdOptionDescriptor();

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

Register_ClassDescriptor(GenerationIdOptionDescriptor)

GenerationIdOptionDescriptor::GenerationIdOptionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::GenerationIdOption)), "inet::HelloOption")
{
    propertynames = nullptr;
}

GenerationIdOptionDescriptor::~GenerationIdOptionDescriptor()
{
    delete[] propertynames;
}

bool GenerationIdOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<GenerationIdOption *>(obj)!=nullptr;
}

const char **GenerationIdOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *GenerationIdOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int GenerationIdOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int GenerationIdOptionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_generationID
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *GenerationIdOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "generationID",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int GenerationIdOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "generationID") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *GenerationIdOptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_generationID
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **GenerationIdOptionDescriptor::getFieldPropertyNames(int field) const
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

const char *GenerationIdOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int GenerationIdOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    GenerationIdOption *pp = (GenerationIdOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *GenerationIdOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    GenerationIdOption *pp = (GenerationIdOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string GenerationIdOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    GenerationIdOption *pp = (GenerationIdOption *)object; (void)pp;
    switch (field) {
        case FIELD_generationID: return ulong2string(pp->getGenerationID());
        default: return "";
    }
}

bool GenerationIdOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    GenerationIdOption *pp = (GenerationIdOption *)object; (void)pp;
    switch (field) {
        case FIELD_generationID: pp->setGenerationID(string2ulong(value)); return true;
        default: return false;
    }
}

const char *GenerationIdOptionDescriptor::getFieldStructName(int field) const
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

void *GenerationIdOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    GenerationIdOption *pp = (GenerationIdOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

EncodedAddress::EncodedAddress()
{
    this->S = false;
    this->W = false;
    this->R = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const EncodedAddress& a)
{
    doParsimPacking(b,a.IPaddress);
    doParsimPacking(b,a.S);
    doParsimPacking(b,a.W);
    doParsimPacking(b,a.R);
}

void __doUnpacking(omnetpp::cCommBuffer *b, EncodedAddress& a)
{
    doParsimUnpacking(b,a.IPaddress);
    doParsimUnpacking(b,a.S);
    doParsimUnpacking(b,a.W);
    doParsimUnpacking(b,a.R);
}

class EncodedAddressDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_IPaddress,
        FIELD_S,
        FIELD_W,
        FIELD_R,
    };
  public:
    EncodedAddressDescriptor();
    virtual ~EncodedAddressDescriptor();

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

Register_ClassDescriptor(EncodedAddressDescriptor)

EncodedAddressDescriptor::EncodedAddressDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EncodedAddress)), "")
{
    propertynames = nullptr;
}

EncodedAddressDescriptor::~EncodedAddressDescriptor()
{
    delete[] propertynames;
}

bool EncodedAddressDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EncodedAddress *>(obj)!=nullptr;
}

const char **EncodedAddressDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EncodedAddressDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EncodedAddressDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int EncodedAddressDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_IPaddress
        FD_ISEDITABLE,    // FIELD_S
        FD_ISEDITABLE,    // FIELD_W
        FD_ISEDITABLE,    // FIELD_R
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *EncodedAddressDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "IPaddress",
        "S",
        "W",
        "R",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int EncodedAddressDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'I' && strcmp(fieldName, "IPaddress") == 0) return base+0;
    if (fieldName[0] == 'S' && strcmp(fieldName, "S") == 0) return base+1;
    if (fieldName[0] == 'W' && strcmp(fieldName, "W") == 0) return base+2;
    if (fieldName[0] == 'R' && strcmp(fieldName, "R") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EncodedAddressDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_IPaddress
        "bool",    // FIELD_S
        "bool",    // FIELD_W
        "bool",    // FIELD_R
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **EncodedAddressDescriptor::getFieldPropertyNames(int field) const
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

const char *EncodedAddressDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EncodedAddressDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EncodedAddress *pp = (EncodedAddress *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *EncodedAddressDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EncodedAddress *pp = (EncodedAddress *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EncodedAddressDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EncodedAddress *pp = (EncodedAddress *)object; (void)pp;
    switch (field) {
        case FIELD_IPaddress: return pp->IPaddress.str();
        case FIELD_S: return bool2string(pp->S);
        case FIELD_W: return bool2string(pp->W);
        case FIELD_R: return bool2string(pp->R);
        default: return "";
    }
}

bool EncodedAddressDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EncodedAddress *pp = (EncodedAddress *)object; (void)pp;
    switch (field) {
        case FIELD_S: pp->S = string2bool(value); return true;
        case FIELD_W: pp->W = string2bool(value); return true;
        case FIELD_R: pp->R = string2bool(value); return true;
        default: return false;
    }
}

const char *EncodedAddressDescriptor::getFieldStructName(int field) const
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

void *EncodedAddressDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EncodedAddress *pp = (EncodedAddress *)object; (void)pp;
    switch (field) {
        case FIELD_IPaddress: return toVoidPtr(&pp->IPaddress); break;
        default: return nullptr;
    }
}

Register_Class(JoinPruneGroup)

JoinPruneGroup::JoinPruneGroup() : ::omnetpp::cObject()
{
}

JoinPruneGroup::JoinPruneGroup(const JoinPruneGroup& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

JoinPruneGroup::~JoinPruneGroup()
{
    delete [] this->joinedSourceAddress;
    delete [] this->prunedSourceAddress;
}

JoinPruneGroup& JoinPruneGroup::operator=(const JoinPruneGroup& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void JoinPruneGroup::copy(const JoinPruneGroup& other)
{
    this->groupAddress = other.groupAddress;
    delete [] this->joinedSourceAddress;
    this->joinedSourceAddress = (other.joinedSourceAddress_arraysize==0) ? nullptr : new EncodedAddress[other.joinedSourceAddress_arraysize];
    joinedSourceAddress_arraysize = other.joinedSourceAddress_arraysize;
    for (size_t i = 0; i < joinedSourceAddress_arraysize; i++) {
        this->joinedSourceAddress[i] = other.joinedSourceAddress[i];
    }
    delete [] this->prunedSourceAddress;
    this->prunedSourceAddress = (other.prunedSourceAddress_arraysize==0) ? nullptr : new EncodedAddress[other.prunedSourceAddress_arraysize];
    prunedSourceAddress_arraysize = other.prunedSourceAddress_arraysize;
    for (size_t i = 0; i < prunedSourceAddress_arraysize; i++) {
        this->prunedSourceAddress[i] = other.prunedSourceAddress[i];
    }
}

void JoinPruneGroup::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->groupAddress);
    b->pack(joinedSourceAddress_arraysize);
    doParsimArrayPacking(b,this->joinedSourceAddress,joinedSourceAddress_arraysize);
    b->pack(prunedSourceAddress_arraysize);
    doParsimArrayPacking(b,this->prunedSourceAddress,prunedSourceAddress_arraysize);
}

void JoinPruneGroup::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->groupAddress);
    delete [] this->joinedSourceAddress;
    b->unpack(joinedSourceAddress_arraysize);
    if (joinedSourceAddress_arraysize == 0) {
        this->joinedSourceAddress = nullptr;
    } else {
        this->joinedSourceAddress = new EncodedAddress[joinedSourceAddress_arraysize];
        doParsimArrayUnpacking(b,this->joinedSourceAddress,joinedSourceAddress_arraysize);
    }
    delete [] this->prunedSourceAddress;
    b->unpack(prunedSourceAddress_arraysize);
    if (prunedSourceAddress_arraysize == 0) {
        this->prunedSourceAddress = nullptr;
    } else {
        this->prunedSourceAddress = new EncodedAddress[prunedSourceAddress_arraysize];
        doParsimArrayUnpacking(b,this->prunedSourceAddress,prunedSourceAddress_arraysize);
    }
}

const Ipv4Address& JoinPruneGroup::getGroupAddress() const
{
    return this->groupAddress;
}

void JoinPruneGroup::setGroupAddress(const Ipv4Address& groupAddress)
{
    this->groupAddress = groupAddress;
}

size_t JoinPruneGroup::getJoinedSourceAddressArraySize() const
{
    return joinedSourceAddress_arraysize;
}

const EncodedAddress& JoinPruneGroup::getJoinedSourceAddress(size_t k) const
{
    if (k >= joinedSourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size joinedSourceAddress_arraysize indexed by %lu", (unsigned long)k);
    return this->joinedSourceAddress[k];
}

void JoinPruneGroup::setJoinedSourceAddressArraySize(size_t newSize)
{
    EncodedAddress *joinedSourceAddress2 = (newSize==0) ? nullptr : new EncodedAddress[newSize];
    size_t minSize = joinedSourceAddress_arraysize < newSize ? joinedSourceAddress_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        joinedSourceAddress2[i] = this->joinedSourceAddress[i];
    delete [] this->joinedSourceAddress;
    this->joinedSourceAddress = joinedSourceAddress2;
    joinedSourceAddress_arraysize = newSize;
}

void JoinPruneGroup::setJoinedSourceAddress(size_t k, const EncodedAddress& joinedSourceAddress)
{
    if (k >= joinedSourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->joinedSourceAddress[k] = joinedSourceAddress;
}

void JoinPruneGroup::insertJoinedSourceAddress(size_t k, const EncodedAddress& joinedSourceAddress)
{
    if (k > joinedSourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = joinedSourceAddress_arraysize + 1;
    EncodedAddress *joinedSourceAddress2 = new EncodedAddress[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        joinedSourceAddress2[i] = this->joinedSourceAddress[i];
    joinedSourceAddress2[k] = joinedSourceAddress;
    for (i = k + 1; i < newSize; i++)
        joinedSourceAddress2[i] = this->joinedSourceAddress[i-1];
    delete [] this->joinedSourceAddress;
    this->joinedSourceAddress = joinedSourceAddress2;
    joinedSourceAddress_arraysize = newSize;
}

void JoinPruneGroup::insertJoinedSourceAddress(const EncodedAddress& joinedSourceAddress)
{
    insertJoinedSourceAddress(joinedSourceAddress_arraysize, joinedSourceAddress);
}

void JoinPruneGroup::eraseJoinedSourceAddress(size_t k)
{
    if (k >= joinedSourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = joinedSourceAddress_arraysize - 1;
    EncodedAddress *joinedSourceAddress2 = (newSize == 0) ? nullptr : new EncodedAddress[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        joinedSourceAddress2[i] = this->joinedSourceAddress[i];
    for (i = k; i < newSize; i++)
        joinedSourceAddress2[i] = this->joinedSourceAddress[i+1];
    delete [] this->joinedSourceAddress;
    this->joinedSourceAddress = joinedSourceAddress2;
    joinedSourceAddress_arraysize = newSize;
}

size_t JoinPruneGroup::getPrunedSourceAddressArraySize() const
{
    return prunedSourceAddress_arraysize;
}

const EncodedAddress& JoinPruneGroup::getPrunedSourceAddress(size_t k) const
{
    if (k >= prunedSourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size prunedSourceAddress_arraysize indexed by %lu", (unsigned long)k);
    return this->prunedSourceAddress[k];
}

void JoinPruneGroup::setPrunedSourceAddressArraySize(size_t newSize)
{
    EncodedAddress *prunedSourceAddress2 = (newSize==0) ? nullptr : new EncodedAddress[newSize];
    size_t minSize = prunedSourceAddress_arraysize < newSize ? prunedSourceAddress_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        prunedSourceAddress2[i] = this->prunedSourceAddress[i];
    delete [] this->prunedSourceAddress;
    this->prunedSourceAddress = prunedSourceAddress2;
    prunedSourceAddress_arraysize = newSize;
}

void JoinPruneGroup::setPrunedSourceAddress(size_t k, const EncodedAddress& prunedSourceAddress)
{
    if (k >= prunedSourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->prunedSourceAddress[k] = prunedSourceAddress;
}

void JoinPruneGroup::insertPrunedSourceAddress(size_t k, const EncodedAddress& prunedSourceAddress)
{
    if (k > prunedSourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = prunedSourceAddress_arraysize + 1;
    EncodedAddress *prunedSourceAddress2 = new EncodedAddress[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        prunedSourceAddress2[i] = this->prunedSourceAddress[i];
    prunedSourceAddress2[k] = prunedSourceAddress;
    for (i = k + 1; i < newSize; i++)
        prunedSourceAddress2[i] = this->prunedSourceAddress[i-1];
    delete [] this->prunedSourceAddress;
    this->prunedSourceAddress = prunedSourceAddress2;
    prunedSourceAddress_arraysize = newSize;
}

void JoinPruneGroup::insertPrunedSourceAddress(const EncodedAddress& prunedSourceAddress)
{
    insertPrunedSourceAddress(prunedSourceAddress_arraysize, prunedSourceAddress);
}

void JoinPruneGroup::erasePrunedSourceAddress(size_t k)
{
    if (k >= prunedSourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = prunedSourceAddress_arraysize - 1;
    EncodedAddress *prunedSourceAddress2 = (newSize == 0) ? nullptr : new EncodedAddress[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        prunedSourceAddress2[i] = this->prunedSourceAddress[i];
    for (i = k; i < newSize; i++)
        prunedSourceAddress2[i] = this->prunedSourceAddress[i+1];
    delete [] this->prunedSourceAddress;
    this->prunedSourceAddress = prunedSourceAddress2;
    prunedSourceAddress_arraysize = newSize;
}

class JoinPruneGroupDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_groupAddress,
        FIELD_joinedSourceAddress,
        FIELD_prunedSourceAddress,
    };
  public:
    JoinPruneGroupDescriptor();
    virtual ~JoinPruneGroupDescriptor();

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

Register_ClassDescriptor(JoinPruneGroupDescriptor)

JoinPruneGroupDescriptor::JoinPruneGroupDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::JoinPruneGroup)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

JoinPruneGroupDescriptor::~JoinPruneGroupDescriptor()
{
    delete[] propertynames;
}

bool JoinPruneGroupDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<JoinPruneGroup *>(obj)!=nullptr;
}

const char **JoinPruneGroupDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *JoinPruneGroupDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int JoinPruneGroupDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int JoinPruneGroupDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_groupAddress
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_joinedSourceAddress
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_prunedSourceAddress
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *JoinPruneGroupDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
        "joinedSourceAddress",
        "prunedSourceAddress",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int JoinPruneGroupDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "groupAddress") == 0) return base+0;
    if (fieldName[0] == 'j' && strcmp(fieldName, "joinedSourceAddress") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "prunedSourceAddress") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *JoinPruneGroupDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_groupAddress
        "inet::EncodedAddress",    // FIELD_joinedSourceAddress
        "inet::EncodedAddress",    // FIELD_prunedSourceAddress
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **JoinPruneGroupDescriptor::getFieldPropertyNames(int field) const
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

const char *JoinPruneGroupDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int JoinPruneGroupDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    JoinPruneGroup *pp = (JoinPruneGroup *)object; (void)pp;
    switch (field) {
        case FIELD_joinedSourceAddress: return pp->getJoinedSourceAddressArraySize();
        case FIELD_prunedSourceAddress: return pp->getPrunedSourceAddressArraySize();
        default: return 0;
    }
}

const char *JoinPruneGroupDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    JoinPruneGroup *pp = (JoinPruneGroup *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string JoinPruneGroupDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    JoinPruneGroup *pp = (JoinPruneGroup *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return pp->getGroupAddress().str();
        case FIELD_joinedSourceAddress: {std::stringstream out; out << pp->getJoinedSourceAddress(i); return out.str();}
        case FIELD_prunedSourceAddress: {std::stringstream out; out << pp->getPrunedSourceAddress(i); return out.str();}
        default: return "";
    }
}

bool JoinPruneGroupDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    JoinPruneGroup *pp = (JoinPruneGroup *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *JoinPruneGroupDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_joinedSourceAddress: return omnetpp::opp_typename(typeid(EncodedAddress));
        case FIELD_prunedSourceAddress: return omnetpp::opp_typename(typeid(EncodedAddress));
        default: return nullptr;
    };
}

void *JoinPruneGroupDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    JoinPruneGroup *pp = (JoinPruneGroup *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return toVoidPtr(&pp->getGroupAddress()); break;
        case FIELD_joinedSourceAddress: return toVoidPtr(&pp->getJoinedSourceAddress(i)); break;
        case FIELD_prunedSourceAddress: return toVoidPtr(&pp->getPrunedSourceAddress(i)); break;
        default: return nullptr;
    }
}

Register_Class(PimPacket)

PimPacket::PimPacket() : ::inet::FieldsChunk()
{
}

PimPacket::PimPacket(const PimPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

PimPacket::~PimPacket()
{
}

PimPacket& PimPacket::operator=(const PimPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void PimPacket::copy(const PimPacket& other)
{
    this->version = other.version;
    this->type = other.type;
}

void PimPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->type);
}

void PimPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->type);
}

short PimPacket::getVersion() const
{
    return this->version;
}

void PimPacket::setVersion(short version)
{
    handleChange();
    this->version = version;
}

inet::PimPacketType PimPacket::getType() const
{
    return this->type;
}

void PimPacket::setType(inet::PimPacketType type)
{
    handleChange();
    this->type = type;
}

class PimPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_version,
        FIELD_type,
    };
  public:
    PimPacketDescriptor();
    virtual ~PimPacketDescriptor();

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

Register_ClassDescriptor(PimPacketDescriptor)

PimPacketDescriptor::PimPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PimPacket)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

PimPacketDescriptor::~PimPacketDescriptor()
{
    delete[] propertynames;
}

bool PimPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PimPacket *>(obj)!=nullptr;
}

const char **PimPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PimPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PimPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int PimPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_version
        FD_ISEDITABLE,    // FIELD_type
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *PimPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "type",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int PimPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "version") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PimPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_version
        "inet::PimPacketType",    // FIELD_type
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **PimPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *PimPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::PimPacketType";
            return nullptr;
        default: return nullptr;
    }
}

int PimPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PimPacket *pp = (PimPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PimPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimPacket *pp = (PimPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PimPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimPacket *pp = (PimPacket *)object; (void)pp;
    switch (field) {
        case FIELD_version: return long2string(pp->getVersion());
        case FIELD_type: return enum2string(pp->getType(), "inet::PimPacketType");
        default: return "";
    }
}

bool PimPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PimPacket *pp = (PimPacket *)object; (void)pp;
    switch (field) {
        case FIELD_version: pp->setVersion(string2long(value)); return true;
        case FIELD_type: pp->setType((inet::PimPacketType)string2enum(value, "inet::PimPacketType")); return true;
        default: return false;
    }
}

const char *PimPacketDescriptor::getFieldStructName(int field) const
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

void *PimPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PimPacket *pp = (PimPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(PimHello)

PimHello::PimHello() : ::inet::PimPacket()
{
    this->setType(Hello);

}

PimHello::PimHello(const PimHello& other) : ::inet::PimPacket(other)
{
    copy(other);
}

PimHello::~PimHello()
{
    for (size_t i = 0; i < options_arraysize; i++)
        delete this->options[i];
    delete [] this->options;
}

PimHello& PimHello::operator=(const PimHello& other)
{
    if (this == &other) return *this;
    ::inet::PimPacket::operator=(other);
    copy(other);
    return *this;
}

void PimHello::copy(const PimHello& other)
{
    for (size_t i = 0; i < options_arraysize; i++)
        delete this->options[i];
    delete [] this->options;
    this->options = (other.options_arraysize==0) ? nullptr : new HelloOption *[other.options_arraysize];
    options_arraysize = other.options_arraysize;
    for (size_t i = 0; i < options_arraysize; i++) {
        this->options[i] = other.options[i];
        if (this->options[i] != nullptr) {
            this->options[i] = this->options[i]->dup();
        }
    }
}

void PimHello::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PimPacket::parsimPack(b);
    b->pack(options_arraysize);
    doParsimArrayPacking(b,this->options,options_arraysize);
}

void PimHello::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PimPacket::parsimUnpack(b);
    delete [] this->options;
    b->unpack(options_arraysize);
    if (options_arraysize == 0) {
        this->options = nullptr;
    } else {
        this->options = new HelloOption *[options_arraysize];
        doParsimArrayUnpacking(b,this->options,options_arraysize);
    }
}

size_t PimHello::getOptionsArraySize() const
{
    return options_arraysize;
}

const HelloOption * PimHello::getOptions(size_t k) const
{
    if (k >= options_arraysize) throw omnetpp::cRuntimeError("Array of size options_arraysize indexed by %lu", (unsigned long)k);
    return this->options[k];
}

void PimHello::setOptionsArraySize(size_t newSize)
{
    handleChange();
    HelloOption * *options2 = (newSize==0) ? nullptr : new HelloOption *[newSize];
    size_t minSize = options_arraysize < newSize ? options_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        options2[i] = this->options[i];
    for (size_t i = minSize; i < newSize; i++)
        options2[i] = nullptr;
    for (size_t i = newSize; i < options_arraysize; i++)
        delete options[i];
    delete [] this->options;
    this->options = options2;
    options_arraysize = newSize;
}

void PimHello::setOptions(size_t k, HelloOption * options)
{
    if (k >= options_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    delete this->options[k];
    this->options[k] = options;
}

HelloOption * PimHello::dropOptions(size_t k)
{
    if (k >= options_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    HelloOption * retval = this->options[k];
    this->options[k] = nullptr;
    return retval;
}

void PimHello::insertOptions(size_t k, HelloOption * options)
{
    handleChange();
    if (k > options_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = options_arraysize + 1;
    HelloOption * *options2 = new HelloOption *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        options2[i] = this->options[i];
    options2[k] = options;
    for (i = k + 1; i < newSize; i++)
        options2[i] = this->options[i-1];
    delete [] this->options;
    this->options = options2;
    options_arraysize = newSize;
}

void PimHello::insertOptions(HelloOption * options)
{
    insertOptions(options_arraysize, options);
}

void PimHello::eraseOptions(size_t k)
{
    if (k >= options_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = options_arraysize - 1;
    HelloOption * *options2 = (newSize == 0) ? nullptr : new HelloOption *[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        options2[i] = this->options[i];
    for (i = k; i < newSize; i++)
        options2[i] = this->options[i+1];
    delete this->options[k];
    delete [] this->options;
    this->options = options2;
    options_arraysize = newSize;
}

class PimHelloDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_options,
    };
  public:
    PimHelloDescriptor();
    virtual ~PimHelloDescriptor();

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

Register_ClassDescriptor(PimHelloDescriptor)

PimHelloDescriptor::PimHelloDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PimHello)), "inet::PimPacket")
{
    propertynames = nullptr;
}

PimHelloDescriptor::~PimHelloDescriptor()
{
    delete[] propertynames;
}

bool PimHelloDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PimHello *>(obj)!=nullptr;
}

const char **PimHelloDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PimHelloDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PimHelloDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int PimHelloDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_options
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *PimHelloDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "options",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int PimHelloDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "options") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PimHelloDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::HelloOption",    // FIELD_options
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PimHelloDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options: {
            static const char *names[] = { "owned", "allowReplace",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *PimHelloDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options:
            if (!strcmp(propertyname, "owned")) return "";
            if (!strcmp(propertyname, "allowReplace")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int PimHelloDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PimHello *pp = (PimHello *)object; (void)pp;
    switch (field) {
        case FIELD_options: return pp->getOptionsArraySize();
        default: return 0;
    }
}

const char *PimHelloDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimHello *pp = (PimHello *)object; (void)pp;
    switch (field) {
        case FIELD_options: { const HelloOption * value = pp->getOptions(i); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string PimHelloDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimHello *pp = (PimHello *)object; (void)pp;
    switch (field) {
        case FIELD_options: {std::stringstream out; out << pp->getOptions(i); return out.str();}
        default: return "";
    }
}

bool PimHelloDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PimHello *pp = (PimHello *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *PimHelloDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_options: return omnetpp::opp_typename(typeid(HelloOption));
        default: return nullptr;
    };
}

void *PimHelloDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PimHello *pp = (PimHello *)object; (void)pp;
    switch (field) {
        case FIELD_options: return toVoidPtr(pp->getOptions(i)); break;
        default: return nullptr;
    }
}

Register_Class(PimJoinPrune)

PimJoinPrune::PimJoinPrune() : ::inet::PimPacket()
{
    this->setType(JoinPrune);

}

PimJoinPrune::PimJoinPrune(const PimJoinPrune& other) : ::inet::PimPacket(other)
{
    copy(other);
}

PimJoinPrune::~PimJoinPrune()
{
    delete [] this->joinPruneGroups;
}

PimJoinPrune& PimJoinPrune::operator=(const PimJoinPrune& other)
{
    if (this == &other) return *this;
    ::inet::PimPacket::operator=(other);
    copy(other);
    return *this;
}

void PimJoinPrune::copy(const PimJoinPrune& other)
{
    this->upstreamNeighborAddress = other.upstreamNeighborAddress;
    this->holdTime = other.holdTime;
    delete [] this->joinPruneGroups;
    this->joinPruneGroups = (other.joinPruneGroups_arraysize==0) ? nullptr : new JoinPruneGroup[other.joinPruneGroups_arraysize];
    joinPruneGroups_arraysize = other.joinPruneGroups_arraysize;
    for (size_t i = 0; i < joinPruneGroups_arraysize; i++) {
        this->joinPruneGroups[i] = other.joinPruneGroups[i];
    }
}

void PimJoinPrune::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PimPacket::parsimPack(b);
    doParsimPacking(b,this->upstreamNeighborAddress);
    doParsimPacking(b,this->holdTime);
    b->pack(joinPruneGroups_arraysize);
    doParsimArrayPacking(b,this->joinPruneGroups,joinPruneGroups_arraysize);
}

void PimJoinPrune::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PimPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->upstreamNeighborAddress);
    doParsimUnpacking(b,this->holdTime);
    delete [] this->joinPruneGroups;
    b->unpack(joinPruneGroups_arraysize);
    if (joinPruneGroups_arraysize == 0) {
        this->joinPruneGroups = nullptr;
    } else {
        this->joinPruneGroups = new JoinPruneGroup[joinPruneGroups_arraysize];
        doParsimArrayUnpacking(b,this->joinPruneGroups,joinPruneGroups_arraysize);
    }
}

const Ipv4Address& PimJoinPrune::getUpstreamNeighborAddress() const
{
    return this->upstreamNeighborAddress;
}

void PimJoinPrune::setUpstreamNeighborAddress(const Ipv4Address& upstreamNeighborAddress)
{
    handleChange();
    this->upstreamNeighborAddress = upstreamNeighborAddress;
}

int PimJoinPrune::getHoldTime() const
{
    return this->holdTime;
}

void PimJoinPrune::setHoldTime(int holdTime)
{
    handleChange();
    this->holdTime = holdTime;
}

size_t PimJoinPrune::getJoinPruneGroupsArraySize() const
{
    return joinPruneGroups_arraysize;
}

const JoinPruneGroup& PimJoinPrune::getJoinPruneGroups(size_t k) const
{
    if (k >= joinPruneGroups_arraysize) throw omnetpp::cRuntimeError("Array of size joinPruneGroups_arraysize indexed by %lu", (unsigned long)k);
    return this->joinPruneGroups[k];
}

void PimJoinPrune::setJoinPruneGroupsArraySize(size_t newSize)
{
    handleChange();
    JoinPruneGroup *joinPruneGroups2 = (newSize==0) ? nullptr : new JoinPruneGroup[newSize];
    size_t minSize = joinPruneGroups_arraysize < newSize ? joinPruneGroups_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        joinPruneGroups2[i] = this->joinPruneGroups[i];
    delete [] this->joinPruneGroups;
    this->joinPruneGroups = joinPruneGroups2;
    joinPruneGroups_arraysize = newSize;
}

void PimJoinPrune::setJoinPruneGroups(size_t k, const JoinPruneGroup& joinPruneGroups)
{
    if (k >= joinPruneGroups_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->joinPruneGroups[k] = joinPruneGroups;
}

void PimJoinPrune::insertJoinPruneGroups(size_t k, const JoinPruneGroup& joinPruneGroups)
{
    handleChange();
    if (k > joinPruneGroups_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = joinPruneGroups_arraysize + 1;
    JoinPruneGroup *joinPruneGroups2 = new JoinPruneGroup[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        joinPruneGroups2[i] = this->joinPruneGroups[i];
    joinPruneGroups2[k] = joinPruneGroups;
    for (i = k + 1; i < newSize; i++)
        joinPruneGroups2[i] = this->joinPruneGroups[i-1];
    delete [] this->joinPruneGroups;
    this->joinPruneGroups = joinPruneGroups2;
    joinPruneGroups_arraysize = newSize;
}

void PimJoinPrune::insertJoinPruneGroups(const JoinPruneGroup& joinPruneGroups)
{
    insertJoinPruneGroups(joinPruneGroups_arraysize, joinPruneGroups);
}

void PimJoinPrune::eraseJoinPruneGroups(size_t k)
{
    if (k >= joinPruneGroups_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = joinPruneGroups_arraysize - 1;
    JoinPruneGroup *joinPruneGroups2 = (newSize == 0) ? nullptr : new JoinPruneGroup[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        joinPruneGroups2[i] = this->joinPruneGroups[i];
    for (i = k; i < newSize; i++)
        joinPruneGroups2[i] = this->joinPruneGroups[i+1];
    delete [] this->joinPruneGroups;
    this->joinPruneGroups = joinPruneGroups2;
    joinPruneGroups_arraysize = newSize;
}

class PimJoinPruneDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_upstreamNeighborAddress,
        FIELD_holdTime,
        FIELD_joinPruneGroups,
    };
  public:
    PimJoinPruneDescriptor();
    virtual ~PimJoinPruneDescriptor();

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

Register_ClassDescriptor(PimJoinPruneDescriptor)

PimJoinPruneDescriptor::PimJoinPruneDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PimJoinPrune)), "inet::PimPacket")
{
    propertynames = nullptr;
}

PimJoinPruneDescriptor::~PimJoinPruneDescriptor()
{
    delete[] propertynames;
}

bool PimJoinPruneDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PimJoinPrune *>(obj)!=nullptr;
}

const char **PimJoinPruneDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PimJoinPruneDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PimJoinPruneDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int PimJoinPruneDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_upstreamNeighborAddress
        FD_ISEDITABLE,    // FIELD_holdTime
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_joinPruneGroups
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *PimJoinPruneDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "upstreamNeighborAddress",
        "holdTime",
        "joinPruneGroups",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int PimJoinPruneDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'u' && strcmp(fieldName, "upstreamNeighborAddress") == 0) return base+0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "holdTime") == 0) return base+1;
    if (fieldName[0] == 'j' && strcmp(fieldName, "joinPruneGroups") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PimJoinPruneDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_upstreamNeighborAddress
        "int",    // FIELD_holdTime
        "inet::JoinPruneGroup",    // FIELD_joinPruneGroups
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **PimJoinPruneDescriptor::getFieldPropertyNames(int field) const
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

const char *PimJoinPruneDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PimJoinPruneDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PimJoinPrune *pp = (PimJoinPrune *)object; (void)pp;
    switch (field) {
        case FIELD_joinPruneGroups: return pp->getJoinPruneGroupsArraySize();
        default: return 0;
    }
}

const char *PimJoinPruneDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimJoinPrune *pp = (PimJoinPrune *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PimJoinPruneDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimJoinPrune *pp = (PimJoinPrune *)object; (void)pp;
    switch (field) {
        case FIELD_upstreamNeighborAddress: return pp->getUpstreamNeighborAddress().str();
        case FIELD_holdTime: return long2string(pp->getHoldTime());
        case FIELD_joinPruneGroups: {std::stringstream out; out << pp->getJoinPruneGroups(i); return out.str();}
        default: return "";
    }
}

bool PimJoinPruneDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PimJoinPrune *pp = (PimJoinPrune *)object; (void)pp;
    switch (field) {
        case FIELD_holdTime: pp->setHoldTime(string2long(value)); return true;
        default: return false;
    }
}

const char *PimJoinPruneDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_joinPruneGroups: return omnetpp::opp_typename(typeid(JoinPruneGroup));
        default: return nullptr;
    };
}

void *PimJoinPruneDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PimJoinPrune *pp = (PimJoinPrune *)object; (void)pp;
    switch (field) {
        case FIELD_upstreamNeighborAddress: return toVoidPtr(&pp->getUpstreamNeighborAddress()); break;
        case FIELD_joinPruneGroups: return toVoidPtr(&pp->getJoinPruneGroups(i)); break;
        default: return nullptr;
    }
}

Register_Class(PimAssert)

PimAssert::PimAssert() : ::inet::PimPacket()
{
    this->setType(Assert);

}

PimAssert::PimAssert(const PimAssert& other) : ::inet::PimPacket(other)
{
    copy(other);
}

PimAssert::~PimAssert()
{
}

PimAssert& PimAssert::operator=(const PimAssert& other)
{
    if (this == &other) return *this;
    ::inet::PimPacket::operator=(other);
    copy(other);
    return *this;
}

void PimAssert::copy(const PimAssert& other)
{
    this->groupAddress = other.groupAddress;
    this->sourceAddress = other.sourceAddress;
    this->R = other.R;
    this->metric = other.metric;
    this->metricPreference = other.metricPreference;
}

void PimAssert::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PimPacket::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->R);
    doParsimPacking(b,this->metric);
    doParsimPacking(b,this->metricPreference);
}

void PimAssert::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PimPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->R);
    doParsimUnpacking(b,this->metric);
    doParsimUnpacking(b,this->metricPreference);
}

const Ipv4Address& PimAssert::getGroupAddress() const
{
    return this->groupAddress;
}

void PimAssert::setGroupAddress(const Ipv4Address& groupAddress)
{
    handleChange();
    this->groupAddress = groupAddress;
}

const Ipv4Address& PimAssert::getSourceAddress() const
{
    return this->sourceAddress;
}

void PimAssert::setSourceAddress(const Ipv4Address& sourceAddress)
{
    handleChange();
    this->sourceAddress = sourceAddress;
}

bool PimAssert::getR() const
{
    return this->R;
}

void PimAssert::setR(bool R)
{
    handleChange();
    this->R = R;
}

int PimAssert::getMetric() const
{
    return this->metric;
}

void PimAssert::setMetric(int metric)
{
    handleChange();
    this->metric = metric;
}

int PimAssert::getMetricPreference() const
{
    return this->metricPreference;
}

void PimAssert::setMetricPreference(int metricPreference)
{
    handleChange();
    this->metricPreference = metricPreference;
}

class PimAssertDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_groupAddress,
        FIELD_sourceAddress,
        FIELD_R,
        FIELD_metric,
        FIELD_metricPreference,
    };
  public:
    PimAssertDescriptor();
    virtual ~PimAssertDescriptor();

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

Register_ClassDescriptor(PimAssertDescriptor)

PimAssertDescriptor::PimAssertDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PimAssert)), "inet::PimPacket")
{
    propertynames = nullptr;
}

PimAssertDescriptor::~PimAssertDescriptor()
{
    delete[] propertynames;
}

bool PimAssertDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PimAssert *>(obj)!=nullptr;
}

const char **PimAssertDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PimAssertDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PimAssertDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int PimAssertDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_groupAddress
        0,    // FIELD_sourceAddress
        FD_ISEDITABLE,    // FIELD_R
        FD_ISEDITABLE,    // FIELD_metric
        FD_ISEDITABLE,    // FIELD_metricPreference
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *PimAssertDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
        "sourceAddress",
        "R",
        "metric",
        "metricPreference",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int PimAssertDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "groupAddress") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceAddress") == 0) return base+1;
    if (fieldName[0] == 'R' && strcmp(fieldName, "R") == 0) return base+2;
    if (fieldName[0] == 'm' && strcmp(fieldName, "metric") == 0) return base+3;
    if (fieldName[0] == 'm' && strcmp(fieldName, "metricPreference") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PimAssertDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_groupAddress
        "inet::Ipv4Address",    // FIELD_sourceAddress
        "bool",    // FIELD_R
        "int",    // FIELD_metric
        "int",    // FIELD_metricPreference
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **PimAssertDescriptor::getFieldPropertyNames(int field) const
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

const char *PimAssertDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PimAssertDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PimAssert *pp = (PimAssert *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PimAssertDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimAssert *pp = (PimAssert *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PimAssertDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimAssert *pp = (PimAssert *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return pp->getGroupAddress().str();
        case FIELD_sourceAddress: return pp->getSourceAddress().str();
        case FIELD_R: return bool2string(pp->getR());
        case FIELD_metric: return long2string(pp->getMetric());
        case FIELD_metricPreference: return long2string(pp->getMetricPreference());
        default: return "";
    }
}

bool PimAssertDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PimAssert *pp = (PimAssert *)object; (void)pp;
    switch (field) {
        case FIELD_R: pp->setR(string2bool(value)); return true;
        case FIELD_metric: pp->setMetric(string2long(value)); return true;
        case FIELD_metricPreference: pp->setMetricPreference(string2long(value)); return true;
        default: return false;
    }
}

const char *PimAssertDescriptor::getFieldStructName(int field) const
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

void *PimAssertDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PimAssert *pp = (PimAssert *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return toVoidPtr(&pp->getGroupAddress()); break;
        case FIELD_sourceAddress: return toVoidPtr(&pp->getSourceAddress()); break;
        default: return nullptr;
    }
}

Register_Class(PimGraft)

PimGraft::PimGraft() : ::inet::PimJoinPrune()
{
    this->setType(Graft);
    this->setHoldTime(0);
}

PimGraft::PimGraft(const PimGraft& other) : ::inet::PimJoinPrune(other)
{
    copy(other);
}

PimGraft::~PimGraft()
{
}

PimGraft& PimGraft::operator=(const PimGraft& other)
{
    if (this == &other) return *this;
    ::inet::PimJoinPrune::operator=(other);
    copy(other);
    return *this;
}

void PimGraft::copy(const PimGraft& other)
{
}

void PimGraft::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PimJoinPrune::parsimPack(b);
}

void PimGraft::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PimJoinPrune::parsimUnpack(b);
}

class PimGraftDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    PimGraftDescriptor();
    virtual ~PimGraftDescriptor();

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

Register_ClassDescriptor(PimGraftDescriptor)

PimGraftDescriptor::PimGraftDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PimGraft)), "inet::PimJoinPrune")
{
    propertynames = nullptr;
}

PimGraftDescriptor::~PimGraftDescriptor()
{
    delete[] propertynames;
}

bool PimGraftDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PimGraft *>(obj)!=nullptr;
}

const char **PimGraftDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PimGraftDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PimGraftDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int PimGraftDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *PimGraftDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int PimGraftDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PimGraftDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **PimGraftDescriptor::getFieldPropertyNames(int field) const
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

const char *PimGraftDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PimGraftDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PimGraft *pp = (PimGraft *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PimGraftDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimGraft *pp = (PimGraft *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PimGraftDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimGraft *pp = (PimGraft *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool PimGraftDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PimGraft *pp = (PimGraft *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *PimGraftDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *PimGraftDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PimGraft *pp = (PimGraft *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(PimStateRefresh)

PimStateRefresh::PimStateRefresh() : ::inet::PimPacket()
{
    this->setType(StateRefresh);

}

PimStateRefresh::PimStateRefresh(const PimStateRefresh& other) : ::inet::PimPacket(other)
{
    copy(other);
}

PimStateRefresh::~PimStateRefresh()
{
}

PimStateRefresh& PimStateRefresh::operator=(const PimStateRefresh& other)
{
    if (this == &other) return *this;
    ::inet::PimPacket::operator=(other);
    copy(other);
    return *this;
}

void PimStateRefresh::copy(const PimStateRefresh& other)
{
    this->groupAddress = other.groupAddress;
    this->sourceAddress = other.sourceAddress;
    this->originatorAddress = other.originatorAddress;
    this->metric = other.metric;
    this->metricPreference = other.metricPreference;
    this->maskLen = other.maskLen;
    this->ttl = other.ttl;
    this->P = other.P;
    this->interval = other.interval;
}

void PimStateRefresh::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PimPacket::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->originatorAddress);
    doParsimPacking(b,this->metric);
    doParsimPacking(b,this->metricPreference);
    doParsimPacking(b,this->maskLen);
    doParsimPacking(b,this->ttl);
    doParsimPacking(b,this->P);
    doParsimPacking(b,this->interval);
}

void PimStateRefresh::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PimPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->originatorAddress);
    doParsimUnpacking(b,this->metric);
    doParsimUnpacking(b,this->metricPreference);
    doParsimUnpacking(b,this->maskLen);
    doParsimUnpacking(b,this->ttl);
    doParsimUnpacking(b,this->P);
    doParsimUnpacking(b,this->interval);
}

const Ipv4Address& PimStateRefresh::getGroupAddress() const
{
    return this->groupAddress;
}

void PimStateRefresh::setGroupAddress(const Ipv4Address& groupAddress)
{
    handleChange();
    this->groupAddress = groupAddress;
}

const Ipv4Address& PimStateRefresh::getSourceAddress() const
{
    return this->sourceAddress;
}

void PimStateRefresh::setSourceAddress(const Ipv4Address& sourceAddress)
{
    handleChange();
    this->sourceAddress = sourceAddress;
}

const Ipv4Address& PimStateRefresh::getOriginatorAddress() const
{
    return this->originatorAddress;
}

void PimStateRefresh::setOriginatorAddress(const Ipv4Address& originatorAddress)
{
    handleChange();
    this->originatorAddress = originatorAddress;
}

int PimStateRefresh::getMetric() const
{
    return this->metric;
}

void PimStateRefresh::setMetric(int metric)
{
    handleChange();
    this->metric = metric;
}

int PimStateRefresh::getMetricPreference() const
{
    return this->metricPreference;
}

void PimStateRefresh::setMetricPreference(int metricPreference)
{
    handleChange();
    this->metricPreference = metricPreference;
}

short PimStateRefresh::getMaskLen() const
{
    return this->maskLen;
}

void PimStateRefresh::setMaskLen(short maskLen)
{
    handleChange();
    this->maskLen = maskLen;
}

short PimStateRefresh::getTtl() const
{
    return this->ttl;
}

void PimStateRefresh::setTtl(short ttl)
{
    handleChange();
    this->ttl = ttl;
}

bool PimStateRefresh::getP() const
{
    return this->P;
}

void PimStateRefresh::setP(bool P)
{
    handleChange();
    this->P = P;
}

int PimStateRefresh::getInterval() const
{
    return this->interval;
}

void PimStateRefresh::setInterval(int interval)
{
    handleChange();
    this->interval = interval;
}

class PimStateRefreshDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_groupAddress,
        FIELD_sourceAddress,
        FIELD_originatorAddress,
        FIELD_metric,
        FIELD_metricPreference,
        FIELD_maskLen,
        FIELD_ttl,
        FIELD_P,
        FIELD_interval,
    };
  public:
    PimStateRefreshDescriptor();
    virtual ~PimStateRefreshDescriptor();

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

Register_ClassDescriptor(PimStateRefreshDescriptor)

PimStateRefreshDescriptor::PimStateRefreshDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PimStateRefresh)), "inet::PimPacket")
{
    propertynames = nullptr;
}

PimStateRefreshDescriptor::~PimStateRefreshDescriptor()
{
    delete[] propertynames;
}

bool PimStateRefreshDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PimStateRefresh *>(obj)!=nullptr;
}

const char **PimStateRefreshDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PimStateRefreshDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PimStateRefreshDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int PimStateRefreshDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_groupAddress
        0,    // FIELD_sourceAddress
        0,    // FIELD_originatorAddress
        FD_ISEDITABLE,    // FIELD_metric
        FD_ISEDITABLE,    // FIELD_metricPreference
        FD_ISEDITABLE,    // FIELD_maskLen
        FD_ISEDITABLE,    // FIELD_ttl
        FD_ISEDITABLE,    // FIELD_P
        FD_ISEDITABLE,    // FIELD_interval
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *PimStateRefreshDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
        "sourceAddress",
        "originatorAddress",
        "metric",
        "metricPreference",
        "maskLen",
        "ttl",
        "P",
        "interval",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int PimStateRefreshDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "groupAddress") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceAddress") == 0) return base+1;
    if (fieldName[0] == 'o' && strcmp(fieldName, "originatorAddress") == 0) return base+2;
    if (fieldName[0] == 'm' && strcmp(fieldName, "metric") == 0) return base+3;
    if (fieldName[0] == 'm' && strcmp(fieldName, "metricPreference") == 0) return base+4;
    if (fieldName[0] == 'm' && strcmp(fieldName, "maskLen") == 0) return base+5;
    if (fieldName[0] == 't' && strcmp(fieldName, "ttl") == 0) return base+6;
    if (fieldName[0] == 'P' && strcmp(fieldName, "P") == 0) return base+7;
    if (fieldName[0] == 'i' && strcmp(fieldName, "interval") == 0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PimStateRefreshDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_groupAddress
        "inet::Ipv4Address",    // FIELD_sourceAddress
        "inet::Ipv4Address",    // FIELD_originatorAddress
        "int",    // FIELD_metric
        "int",    // FIELD_metricPreference
        "short",    // FIELD_maskLen
        "short",    // FIELD_ttl
        "bool",    // FIELD_P
        "int",    // FIELD_interval
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **PimStateRefreshDescriptor::getFieldPropertyNames(int field) const
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

const char *PimStateRefreshDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PimStateRefreshDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PimStateRefresh *pp = (PimStateRefresh *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PimStateRefreshDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimStateRefresh *pp = (PimStateRefresh *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PimStateRefreshDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimStateRefresh *pp = (PimStateRefresh *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return pp->getGroupAddress().str();
        case FIELD_sourceAddress: return pp->getSourceAddress().str();
        case FIELD_originatorAddress: return pp->getOriginatorAddress().str();
        case FIELD_metric: return long2string(pp->getMetric());
        case FIELD_metricPreference: return long2string(pp->getMetricPreference());
        case FIELD_maskLen: return long2string(pp->getMaskLen());
        case FIELD_ttl: return long2string(pp->getTtl());
        case FIELD_P: return bool2string(pp->getP());
        case FIELD_interval: return long2string(pp->getInterval());
        default: return "";
    }
}

bool PimStateRefreshDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PimStateRefresh *pp = (PimStateRefresh *)object; (void)pp;
    switch (field) {
        case FIELD_metric: pp->setMetric(string2long(value)); return true;
        case FIELD_metricPreference: pp->setMetricPreference(string2long(value)); return true;
        case FIELD_maskLen: pp->setMaskLen(string2long(value)); return true;
        case FIELD_ttl: pp->setTtl(string2long(value)); return true;
        case FIELD_P: pp->setP(string2bool(value)); return true;
        case FIELD_interval: pp->setInterval(string2long(value)); return true;
        default: return false;
    }
}

const char *PimStateRefreshDescriptor::getFieldStructName(int field) const
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

void *PimStateRefreshDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PimStateRefresh *pp = (PimStateRefresh *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return toVoidPtr(&pp->getGroupAddress()); break;
        case FIELD_sourceAddress: return toVoidPtr(&pp->getSourceAddress()); break;
        case FIELD_originatorAddress: return toVoidPtr(&pp->getOriginatorAddress()); break;
        default: return nullptr;
    }
}

Register_Class(PimRegister)

PimRegister::PimRegister() : ::inet::PimPacket()
{
    this->setType(Register);

}

PimRegister::PimRegister(const PimRegister& other) : ::inet::PimPacket(other)
{
    copy(other);
}

PimRegister::~PimRegister()
{
}

PimRegister& PimRegister::operator=(const PimRegister& other)
{
    if (this == &other) return *this;
    ::inet::PimPacket::operator=(other);
    copy(other);
    return *this;
}

void PimRegister::copy(const PimRegister& other)
{
    this->B = other.B;
    this->N = other.N;
}

void PimRegister::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PimPacket::parsimPack(b);
    doParsimPacking(b,this->B);
    doParsimPacking(b,this->N);
}

void PimRegister::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PimPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->B);
    doParsimUnpacking(b,this->N);
}

bool PimRegister::getB() const
{
    return this->B;
}

void PimRegister::setB(bool B)
{
    handleChange();
    this->B = B;
}

bool PimRegister::getN() const
{
    return this->N;
}

void PimRegister::setN(bool N)
{
    handleChange();
    this->N = N;
}

class PimRegisterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_B,
        FIELD_N,
    };
  public:
    PimRegisterDescriptor();
    virtual ~PimRegisterDescriptor();

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

Register_ClassDescriptor(PimRegisterDescriptor)

PimRegisterDescriptor::PimRegisterDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PimRegister)), "inet::PimPacket")
{
    propertynames = nullptr;
}

PimRegisterDescriptor::~PimRegisterDescriptor()
{
    delete[] propertynames;
}

bool PimRegisterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PimRegister *>(obj)!=nullptr;
}

const char **PimRegisterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PimRegisterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PimRegisterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int PimRegisterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_B
        FD_ISEDITABLE,    // FIELD_N
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *PimRegisterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "B",
        "N",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int PimRegisterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'B' && strcmp(fieldName, "B") == 0) return base+0;
    if (fieldName[0] == 'N' && strcmp(fieldName, "N") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PimRegisterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_B
        "bool",    // FIELD_N
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **PimRegisterDescriptor::getFieldPropertyNames(int field) const
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

const char *PimRegisterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PimRegisterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PimRegister *pp = (PimRegister *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PimRegisterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimRegister *pp = (PimRegister *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PimRegisterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimRegister *pp = (PimRegister *)object; (void)pp;
    switch (field) {
        case FIELD_B: return bool2string(pp->getB());
        case FIELD_N: return bool2string(pp->getN());
        default: return "";
    }
}

bool PimRegisterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PimRegister *pp = (PimRegister *)object; (void)pp;
    switch (field) {
        case FIELD_B: pp->setB(string2bool(value)); return true;
        case FIELD_N: pp->setN(string2bool(value)); return true;
        default: return false;
    }
}

const char *PimRegisterDescriptor::getFieldStructName(int field) const
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

void *PimRegisterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PimRegister *pp = (PimRegister *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(PimRegisterStop)

PimRegisterStop::PimRegisterStop() : ::inet::PimPacket()
{
    this->setType(RegisterStop);

}

PimRegisterStop::PimRegisterStop(const PimRegisterStop& other) : ::inet::PimPacket(other)
{
    copy(other);
}

PimRegisterStop::~PimRegisterStop()
{
}

PimRegisterStop& PimRegisterStop::operator=(const PimRegisterStop& other)
{
    if (this == &other) return *this;
    ::inet::PimPacket::operator=(other);
    copy(other);
    return *this;
}

void PimRegisterStop::copy(const PimRegisterStop& other)
{
    this->groupAddress = other.groupAddress;
    this->sourceAddress = other.sourceAddress;
}

void PimRegisterStop::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PimPacket::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
    doParsimPacking(b,this->sourceAddress);
}

void PimRegisterStop::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PimPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
    doParsimUnpacking(b,this->sourceAddress);
}

const Ipv4Address& PimRegisterStop::getGroupAddress() const
{
    return this->groupAddress;
}

void PimRegisterStop::setGroupAddress(const Ipv4Address& groupAddress)
{
    handleChange();
    this->groupAddress = groupAddress;
}

const Ipv4Address& PimRegisterStop::getSourceAddress() const
{
    return this->sourceAddress;
}

void PimRegisterStop::setSourceAddress(const Ipv4Address& sourceAddress)
{
    handleChange();
    this->sourceAddress = sourceAddress;
}

class PimRegisterStopDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_groupAddress,
        FIELD_sourceAddress,
    };
  public:
    PimRegisterStopDescriptor();
    virtual ~PimRegisterStopDescriptor();

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

Register_ClassDescriptor(PimRegisterStopDescriptor)

PimRegisterStopDescriptor::PimRegisterStopDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PimRegisterStop)), "inet::PimPacket")
{
    propertynames = nullptr;
}

PimRegisterStopDescriptor::~PimRegisterStopDescriptor()
{
    delete[] propertynames;
}

bool PimRegisterStopDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PimRegisterStop *>(obj)!=nullptr;
}

const char **PimRegisterStopDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PimRegisterStopDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PimRegisterStopDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int PimRegisterStopDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_groupAddress
        0,    // FIELD_sourceAddress
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *PimRegisterStopDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
        "sourceAddress",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int PimRegisterStopDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'g' && strcmp(fieldName, "groupAddress") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceAddress") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PimRegisterStopDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_groupAddress
        "inet::Ipv4Address",    // FIELD_sourceAddress
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **PimRegisterStopDescriptor::getFieldPropertyNames(int field) const
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

const char *PimRegisterStopDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PimRegisterStopDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PimRegisterStop *pp = (PimRegisterStop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PimRegisterStopDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimRegisterStop *pp = (PimRegisterStop *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PimRegisterStopDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PimRegisterStop *pp = (PimRegisterStop *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return pp->getGroupAddress().str();
        case FIELD_sourceAddress: return pp->getSourceAddress().str();
        default: return "";
    }
}

bool PimRegisterStopDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PimRegisterStop *pp = (PimRegisterStop *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *PimRegisterStopDescriptor::getFieldStructName(int field) const
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

void *PimRegisterStopDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PimRegisterStop *pp = (PimRegisterStop *)object; (void)pp;
    switch (field) {
        case FIELD_groupAddress: return toVoidPtr(&pp->getGroupAddress()); break;
        case FIELD_sourceAddress: return toVoidPtr(&pp->getSourceAddress()); break;
        default: return nullptr;
    }
}

} // namespace inet

