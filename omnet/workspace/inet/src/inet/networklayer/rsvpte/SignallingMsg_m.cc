//
// Generated file, do not edit! Created by nedtool 5.6 from inet/networklayer/rsvpte/SignallingMsg.msg.
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
#include "SignallingMsg_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::SignallingConstants");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::SignallingConstants"));
    e->insert(MSG_PSB_TIMER, "MSG_PSB_TIMER");
    e->insert(MSG_PSB_TIMEOUT, "MSG_PSB_TIMEOUT");
    e->insert(MSG_RSB_REFRESH_TIMER, "MSG_RSB_REFRESH_TIMER");
    e->insert(MSG_RSB_COMMIT_TIMER, "MSG_RSB_COMMIT_TIMER");
    e->insert(MSG_RSB_TIMEOUT, "MSG_RSB_TIMEOUT");
    e->insert(MSG_HELLO_TIMER, "MSG_HELLO_TIMER");
    e->insert(MSG_HELLO_TIMEOUT, "MSG_HELLO_TIMEOUT");
    e->insert(MSG_PATH_NOTIFY, "MSG_PATH_NOTIFY");
    e->insert(PATH_CREATED, "PATH_CREATED");
    e->insert(PATH_UNFEASIBLE, "PATH_UNFEASIBLE");
    e->insert(PATH_FAILED, "PATH_FAILED");
    e->insert(PATH_PREEMPTED, "PATH_PREEMPTED");
    e->insert(PATH_RETRY, "PATH_RETRY");
)

Register_Class(SignallingMsg)

SignallingMsg::SignallingMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

SignallingMsg::SignallingMsg(const SignallingMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

SignallingMsg::~SignallingMsg()
{
}

SignallingMsg& SignallingMsg::operator=(const SignallingMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void SignallingMsg::copy(const SignallingMsg& other)
{
    this->command = other.command;
}

void SignallingMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->command);
}

void SignallingMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->command);
}

int SignallingMsg::getCommand() const
{
    return this->command;
}

void SignallingMsg::setCommand(int command)
{
    this->command = command;
}

class SignallingMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_command,
    };
  public:
    SignallingMsgDescriptor();
    virtual ~SignallingMsgDescriptor();

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

Register_ClassDescriptor(SignallingMsgDescriptor)

SignallingMsgDescriptor::SignallingMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SignallingMsg)), "omnetpp::cMessage")
{
    propertynames = nullptr;
}

SignallingMsgDescriptor::~SignallingMsgDescriptor()
{
    delete[] propertynames;
}

bool SignallingMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SignallingMsg *>(obj)!=nullptr;
}

const char **SignallingMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SignallingMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SignallingMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SignallingMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_command
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *SignallingMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "command",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int SignallingMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "command") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SignallingMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_command
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **SignallingMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *SignallingMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SignallingMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SignallingMsg *pp = (SignallingMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SignallingMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignallingMsg *pp = (SignallingMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SignallingMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SignallingMsg *pp = (SignallingMsg *)object; (void)pp;
    switch (field) {
        case FIELD_command: return long2string(pp->getCommand());
        default: return "";
    }
}

bool SignallingMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SignallingMsg *pp = (SignallingMsg *)object; (void)pp;
    switch (field) {
        case FIELD_command: pp->setCommand(string2long(value)); return true;
        default: return false;
    }
}

const char *SignallingMsgDescriptor::getFieldStructName(int field) const
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

void *SignallingMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SignallingMsg *pp = (SignallingMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(PsbTimerMsg)

PsbTimerMsg::PsbTimerMsg(const char *name, short kind) : ::inet::SignallingMsg(name, kind)
{
    this->setCommand(MSG_PSB_TIMER);

}

PsbTimerMsg::PsbTimerMsg(const PsbTimerMsg& other) : ::inet::SignallingMsg(other)
{
    copy(other);
}

PsbTimerMsg::~PsbTimerMsg()
{
}

PsbTimerMsg& PsbTimerMsg::operator=(const PsbTimerMsg& other)
{
    if (this == &other) return *this;
    ::inet::SignallingMsg::operator=(other);
    copy(other);
    return *this;
}

void PsbTimerMsg::copy(const PsbTimerMsg& other)
{
    this->id = other.id;
}

void PsbTimerMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignallingMsg::parsimPack(b);
    doParsimPacking(b,this->id);
}

void PsbTimerMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignallingMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->id);
}

int PsbTimerMsg::getId() const
{
    return this->id;
}

void PsbTimerMsg::setId(int id)
{
    this->id = id;
}

class PsbTimerMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_id,
    };
  public:
    PsbTimerMsgDescriptor();
    virtual ~PsbTimerMsgDescriptor();

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

Register_ClassDescriptor(PsbTimerMsgDescriptor)

PsbTimerMsgDescriptor::PsbTimerMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PsbTimerMsg)), "inet::SignallingMsg")
{
    propertynames = nullptr;
}

PsbTimerMsgDescriptor::~PsbTimerMsgDescriptor()
{
    delete[] propertynames;
}

bool PsbTimerMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PsbTimerMsg *>(obj)!=nullptr;
}

const char **PsbTimerMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PsbTimerMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PsbTimerMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int PsbTimerMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_id
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *PsbTimerMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "id",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int PsbTimerMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "id") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PsbTimerMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_id
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PsbTimerMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *PsbTimerMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PsbTimerMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PsbTimerMsg *pp = (PsbTimerMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PsbTimerMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PsbTimerMsg *pp = (PsbTimerMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PsbTimerMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PsbTimerMsg *pp = (PsbTimerMsg *)object; (void)pp;
    switch (field) {
        case FIELD_id: return long2string(pp->getId());
        default: return "";
    }
}

bool PsbTimerMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PsbTimerMsg *pp = (PsbTimerMsg *)object; (void)pp;
    switch (field) {
        case FIELD_id: pp->setId(string2long(value)); return true;
        default: return false;
    }
}

const char *PsbTimerMsgDescriptor::getFieldStructName(int field) const
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

void *PsbTimerMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PsbTimerMsg *pp = (PsbTimerMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(PsbTimeoutMsg)

PsbTimeoutMsg::PsbTimeoutMsg(const char *name, short kind) : ::inet::SignallingMsg(name, kind)
{
    this->setCommand(MSG_PSB_TIMEOUT);

}

PsbTimeoutMsg::PsbTimeoutMsg(const PsbTimeoutMsg& other) : ::inet::SignallingMsg(other)
{
    copy(other);
}

PsbTimeoutMsg::~PsbTimeoutMsg()
{
}

PsbTimeoutMsg& PsbTimeoutMsg::operator=(const PsbTimeoutMsg& other)
{
    if (this == &other) return *this;
    ::inet::SignallingMsg::operator=(other);
    copy(other);
    return *this;
}

void PsbTimeoutMsg::copy(const PsbTimeoutMsg& other)
{
    this->id = other.id;
}

void PsbTimeoutMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignallingMsg::parsimPack(b);
    doParsimPacking(b,this->id);
}

void PsbTimeoutMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignallingMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->id);
}

int PsbTimeoutMsg::getId() const
{
    return this->id;
}

void PsbTimeoutMsg::setId(int id)
{
    this->id = id;
}

class PsbTimeoutMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_id,
    };
  public:
    PsbTimeoutMsgDescriptor();
    virtual ~PsbTimeoutMsgDescriptor();

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

Register_ClassDescriptor(PsbTimeoutMsgDescriptor)

PsbTimeoutMsgDescriptor::PsbTimeoutMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PsbTimeoutMsg)), "inet::SignallingMsg")
{
    propertynames = nullptr;
}

PsbTimeoutMsgDescriptor::~PsbTimeoutMsgDescriptor()
{
    delete[] propertynames;
}

bool PsbTimeoutMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PsbTimeoutMsg *>(obj)!=nullptr;
}

const char **PsbTimeoutMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PsbTimeoutMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PsbTimeoutMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int PsbTimeoutMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_id
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *PsbTimeoutMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "id",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int PsbTimeoutMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "id") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PsbTimeoutMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_id
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PsbTimeoutMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *PsbTimeoutMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PsbTimeoutMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PsbTimeoutMsg *pp = (PsbTimeoutMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PsbTimeoutMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PsbTimeoutMsg *pp = (PsbTimeoutMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PsbTimeoutMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PsbTimeoutMsg *pp = (PsbTimeoutMsg *)object; (void)pp;
    switch (field) {
        case FIELD_id: return long2string(pp->getId());
        default: return "";
    }
}

bool PsbTimeoutMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PsbTimeoutMsg *pp = (PsbTimeoutMsg *)object; (void)pp;
    switch (field) {
        case FIELD_id: pp->setId(string2long(value)); return true;
        default: return false;
    }
}

const char *PsbTimeoutMsgDescriptor::getFieldStructName(int field) const
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

void *PsbTimeoutMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PsbTimeoutMsg *pp = (PsbTimeoutMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RsbRefreshTimerMsg)

RsbRefreshTimerMsg::RsbRefreshTimerMsg(const char *name, short kind) : ::inet::SignallingMsg(name, kind)
{
    this->setCommand(MSG_RSB_REFRESH_TIMER);

}

RsbRefreshTimerMsg::RsbRefreshTimerMsg(const RsbRefreshTimerMsg& other) : ::inet::SignallingMsg(other)
{
    copy(other);
}

RsbRefreshTimerMsg::~RsbRefreshTimerMsg()
{
}

RsbRefreshTimerMsg& RsbRefreshTimerMsg::operator=(const RsbRefreshTimerMsg& other)
{
    if (this == &other) return *this;
    ::inet::SignallingMsg::operator=(other);
    copy(other);
    return *this;
}

void RsbRefreshTimerMsg::copy(const RsbRefreshTimerMsg& other)
{
    this->id = other.id;
}

void RsbRefreshTimerMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignallingMsg::parsimPack(b);
    doParsimPacking(b,this->id);
}

void RsbRefreshTimerMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignallingMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->id);
}

int RsbRefreshTimerMsg::getId() const
{
    return this->id;
}

void RsbRefreshTimerMsg::setId(int id)
{
    this->id = id;
}

class RsbRefreshTimerMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_id,
    };
  public:
    RsbRefreshTimerMsgDescriptor();
    virtual ~RsbRefreshTimerMsgDescriptor();

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

Register_ClassDescriptor(RsbRefreshTimerMsgDescriptor)

RsbRefreshTimerMsgDescriptor::RsbRefreshTimerMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::RsbRefreshTimerMsg)), "inet::SignallingMsg")
{
    propertynames = nullptr;
}

RsbRefreshTimerMsgDescriptor::~RsbRefreshTimerMsgDescriptor()
{
    delete[] propertynames;
}

bool RsbRefreshTimerMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RsbRefreshTimerMsg *>(obj)!=nullptr;
}

const char **RsbRefreshTimerMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RsbRefreshTimerMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RsbRefreshTimerMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RsbRefreshTimerMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_id
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *RsbRefreshTimerMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "id",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int RsbRefreshTimerMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "id") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RsbRefreshTimerMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_id
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **RsbRefreshTimerMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *RsbRefreshTimerMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RsbRefreshTimerMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RsbRefreshTimerMsg *pp = (RsbRefreshTimerMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RsbRefreshTimerMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RsbRefreshTimerMsg *pp = (RsbRefreshTimerMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RsbRefreshTimerMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RsbRefreshTimerMsg *pp = (RsbRefreshTimerMsg *)object; (void)pp;
    switch (field) {
        case FIELD_id: return long2string(pp->getId());
        default: return "";
    }
}

bool RsbRefreshTimerMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RsbRefreshTimerMsg *pp = (RsbRefreshTimerMsg *)object; (void)pp;
    switch (field) {
        case FIELD_id: pp->setId(string2long(value)); return true;
        default: return false;
    }
}

const char *RsbRefreshTimerMsgDescriptor::getFieldStructName(int field) const
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

void *RsbRefreshTimerMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RsbRefreshTimerMsg *pp = (RsbRefreshTimerMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RsbCommitTimerMsg)

RsbCommitTimerMsg::RsbCommitTimerMsg(const char *name, short kind) : ::inet::SignallingMsg(name, kind)
{
    this->setCommand(MSG_RSB_COMMIT_TIMER);

}

RsbCommitTimerMsg::RsbCommitTimerMsg(const RsbCommitTimerMsg& other) : ::inet::SignallingMsg(other)
{
    copy(other);
}

RsbCommitTimerMsg::~RsbCommitTimerMsg()
{
}

RsbCommitTimerMsg& RsbCommitTimerMsg::operator=(const RsbCommitTimerMsg& other)
{
    if (this == &other) return *this;
    ::inet::SignallingMsg::operator=(other);
    copy(other);
    return *this;
}

void RsbCommitTimerMsg::copy(const RsbCommitTimerMsg& other)
{
    this->id = other.id;
}

void RsbCommitTimerMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignallingMsg::parsimPack(b);
    doParsimPacking(b,this->id);
}

void RsbCommitTimerMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignallingMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->id);
}

int RsbCommitTimerMsg::getId() const
{
    return this->id;
}

void RsbCommitTimerMsg::setId(int id)
{
    this->id = id;
}

class RsbCommitTimerMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_id,
    };
  public:
    RsbCommitTimerMsgDescriptor();
    virtual ~RsbCommitTimerMsgDescriptor();

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

Register_ClassDescriptor(RsbCommitTimerMsgDescriptor)

RsbCommitTimerMsgDescriptor::RsbCommitTimerMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::RsbCommitTimerMsg)), "inet::SignallingMsg")
{
    propertynames = nullptr;
}

RsbCommitTimerMsgDescriptor::~RsbCommitTimerMsgDescriptor()
{
    delete[] propertynames;
}

bool RsbCommitTimerMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RsbCommitTimerMsg *>(obj)!=nullptr;
}

const char **RsbCommitTimerMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RsbCommitTimerMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RsbCommitTimerMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RsbCommitTimerMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_id
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *RsbCommitTimerMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "id",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int RsbCommitTimerMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "id") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RsbCommitTimerMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_id
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **RsbCommitTimerMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *RsbCommitTimerMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RsbCommitTimerMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RsbCommitTimerMsg *pp = (RsbCommitTimerMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RsbCommitTimerMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RsbCommitTimerMsg *pp = (RsbCommitTimerMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RsbCommitTimerMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RsbCommitTimerMsg *pp = (RsbCommitTimerMsg *)object; (void)pp;
    switch (field) {
        case FIELD_id: return long2string(pp->getId());
        default: return "";
    }
}

bool RsbCommitTimerMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RsbCommitTimerMsg *pp = (RsbCommitTimerMsg *)object; (void)pp;
    switch (field) {
        case FIELD_id: pp->setId(string2long(value)); return true;
        default: return false;
    }
}

const char *RsbCommitTimerMsgDescriptor::getFieldStructName(int field) const
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

void *RsbCommitTimerMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RsbCommitTimerMsg *pp = (RsbCommitTimerMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RsbTimeoutMsg)

RsbTimeoutMsg::RsbTimeoutMsg(const char *name, short kind) : ::inet::SignallingMsg(name, kind)
{
    this->setCommand(MSG_RSB_TIMEOUT);

}

RsbTimeoutMsg::RsbTimeoutMsg(const RsbTimeoutMsg& other) : ::inet::SignallingMsg(other)
{
    copy(other);
}

RsbTimeoutMsg::~RsbTimeoutMsg()
{
}

RsbTimeoutMsg& RsbTimeoutMsg::operator=(const RsbTimeoutMsg& other)
{
    if (this == &other) return *this;
    ::inet::SignallingMsg::operator=(other);
    copy(other);
    return *this;
}

void RsbTimeoutMsg::copy(const RsbTimeoutMsg& other)
{
    this->id = other.id;
}

void RsbTimeoutMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignallingMsg::parsimPack(b);
    doParsimPacking(b,this->id);
}

void RsbTimeoutMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignallingMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->id);
}

int RsbTimeoutMsg::getId() const
{
    return this->id;
}

void RsbTimeoutMsg::setId(int id)
{
    this->id = id;
}

class RsbTimeoutMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_id,
    };
  public:
    RsbTimeoutMsgDescriptor();
    virtual ~RsbTimeoutMsgDescriptor();

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

Register_ClassDescriptor(RsbTimeoutMsgDescriptor)

RsbTimeoutMsgDescriptor::RsbTimeoutMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::RsbTimeoutMsg)), "inet::SignallingMsg")
{
    propertynames = nullptr;
}

RsbTimeoutMsgDescriptor::~RsbTimeoutMsgDescriptor()
{
    delete[] propertynames;
}

bool RsbTimeoutMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RsbTimeoutMsg *>(obj)!=nullptr;
}

const char **RsbTimeoutMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RsbTimeoutMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RsbTimeoutMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RsbTimeoutMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_id
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *RsbTimeoutMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "id",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int RsbTimeoutMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "id") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RsbTimeoutMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_id
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **RsbTimeoutMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *RsbTimeoutMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RsbTimeoutMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RsbTimeoutMsg *pp = (RsbTimeoutMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RsbTimeoutMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RsbTimeoutMsg *pp = (RsbTimeoutMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RsbTimeoutMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RsbTimeoutMsg *pp = (RsbTimeoutMsg *)object; (void)pp;
    switch (field) {
        case FIELD_id: return long2string(pp->getId());
        default: return "";
    }
}

bool RsbTimeoutMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RsbTimeoutMsg *pp = (RsbTimeoutMsg *)object; (void)pp;
    switch (field) {
        case FIELD_id: pp->setId(string2long(value)); return true;
        default: return false;
    }
}

const char *RsbTimeoutMsgDescriptor::getFieldStructName(int field) const
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

void *RsbTimeoutMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RsbTimeoutMsg *pp = (RsbTimeoutMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(HelloTimerMsg)

HelloTimerMsg::HelloTimerMsg(const char *name, short kind) : ::inet::SignallingMsg(name, kind)
{
    this->setCommand(MSG_HELLO_TIMER);

}

HelloTimerMsg::HelloTimerMsg(const HelloTimerMsg& other) : ::inet::SignallingMsg(other)
{
    copy(other);
}

HelloTimerMsg::~HelloTimerMsg()
{
}

HelloTimerMsg& HelloTimerMsg::operator=(const HelloTimerMsg& other)
{
    if (this == &other) return *this;
    ::inet::SignallingMsg::operator=(other);
    copy(other);
    return *this;
}

void HelloTimerMsg::copy(const HelloTimerMsg& other)
{
    this->peer = other.peer;
}

void HelloTimerMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignallingMsg::parsimPack(b);
    doParsimPacking(b,this->peer);
}

void HelloTimerMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignallingMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->peer);
}

const Ipv4Address& HelloTimerMsg::getPeer() const
{
    return this->peer;
}

void HelloTimerMsg::setPeer(const Ipv4Address& peer)
{
    this->peer = peer;
}

class HelloTimerMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_peer,
    };
  public:
    HelloTimerMsgDescriptor();
    virtual ~HelloTimerMsgDescriptor();

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

Register_ClassDescriptor(HelloTimerMsgDescriptor)

HelloTimerMsgDescriptor::HelloTimerMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::HelloTimerMsg)), "inet::SignallingMsg")
{
    propertynames = nullptr;
}

HelloTimerMsgDescriptor::~HelloTimerMsgDescriptor()
{
    delete[] propertynames;
}

bool HelloTimerMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HelloTimerMsg *>(obj)!=nullptr;
}

const char **HelloTimerMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HelloTimerMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HelloTimerMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int HelloTimerMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_peer
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *HelloTimerMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "peer",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int HelloTimerMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "peer") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HelloTimerMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_peer
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **HelloTimerMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *HelloTimerMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int HelloTimerMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    HelloTimerMsg *pp = (HelloTimerMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *HelloTimerMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HelloTimerMsg *pp = (HelloTimerMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HelloTimerMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HelloTimerMsg *pp = (HelloTimerMsg *)object; (void)pp;
    switch (field) {
        case FIELD_peer: return pp->getPeer().str();
        default: return "";
    }
}

bool HelloTimerMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    HelloTimerMsg *pp = (HelloTimerMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *HelloTimerMsgDescriptor::getFieldStructName(int field) const
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

void *HelloTimerMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    HelloTimerMsg *pp = (HelloTimerMsg *)object; (void)pp;
    switch (field) {
        case FIELD_peer: return toVoidPtr(&pp->getPeer()); break;
        default: return nullptr;
    }
}

Register_Class(HelloTimeoutMsg)

HelloTimeoutMsg::HelloTimeoutMsg(const char *name, short kind) : ::inet::SignallingMsg(name, kind)
{
    this->setCommand(MSG_HELLO_TIMEOUT);

}

HelloTimeoutMsg::HelloTimeoutMsg(const HelloTimeoutMsg& other) : ::inet::SignallingMsg(other)
{
    copy(other);
}

HelloTimeoutMsg::~HelloTimeoutMsg()
{
}

HelloTimeoutMsg& HelloTimeoutMsg::operator=(const HelloTimeoutMsg& other)
{
    if (this == &other) return *this;
    ::inet::SignallingMsg::operator=(other);
    copy(other);
    return *this;
}

void HelloTimeoutMsg::copy(const HelloTimeoutMsg& other)
{
    this->peer = other.peer;
}

void HelloTimeoutMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignallingMsg::parsimPack(b);
    doParsimPacking(b,this->peer);
}

void HelloTimeoutMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignallingMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->peer);
}

const Ipv4Address& HelloTimeoutMsg::getPeer() const
{
    return this->peer;
}

void HelloTimeoutMsg::setPeer(const Ipv4Address& peer)
{
    this->peer = peer;
}

class HelloTimeoutMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_peer,
    };
  public:
    HelloTimeoutMsgDescriptor();
    virtual ~HelloTimeoutMsgDescriptor();

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

Register_ClassDescriptor(HelloTimeoutMsgDescriptor)

HelloTimeoutMsgDescriptor::HelloTimeoutMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::HelloTimeoutMsg)), "inet::SignallingMsg")
{
    propertynames = nullptr;
}

HelloTimeoutMsgDescriptor::~HelloTimeoutMsgDescriptor()
{
    delete[] propertynames;
}

bool HelloTimeoutMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HelloTimeoutMsg *>(obj)!=nullptr;
}

const char **HelloTimeoutMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HelloTimeoutMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HelloTimeoutMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int HelloTimeoutMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_peer
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *HelloTimeoutMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "peer",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int HelloTimeoutMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "peer") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HelloTimeoutMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_peer
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **HelloTimeoutMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *HelloTimeoutMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int HelloTimeoutMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    HelloTimeoutMsg *pp = (HelloTimeoutMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *HelloTimeoutMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HelloTimeoutMsg *pp = (HelloTimeoutMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HelloTimeoutMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HelloTimeoutMsg *pp = (HelloTimeoutMsg *)object; (void)pp;
    switch (field) {
        case FIELD_peer: return pp->getPeer().str();
        default: return "";
    }
}

bool HelloTimeoutMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    HelloTimeoutMsg *pp = (HelloTimeoutMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *HelloTimeoutMsgDescriptor::getFieldStructName(int field) const
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

void *HelloTimeoutMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    HelloTimeoutMsg *pp = (HelloTimeoutMsg *)object; (void)pp;
    switch (field) {
        case FIELD_peer: return toVoidPtr(&pp->getPeer()); break;
        default: return nullptr;
    }
}

Register_Class(PathNotifyMsg)

PathNotifyMsg::PathNotifyMsg(const char *name, short kind) : ::inet::SignallingMsg(name, kind)
{
    this->setCommand(MSG_PATH_NOTIFY);

}

PathNotifyMsg::PathNotifyMsg(const PathNotifyMsg& other) : ::inet::SignallingMsg(other)
{
    copy(other);
}

PathNotifyMsg::~PathNotifyMsg()
{
}

PathNotifyMsg& PathNotifyMsg::operator=(const PathNotifyMsg& other)
{
    if (this == &other) return *this;
    ::inet::SignallingMsg::operator=(other);
    copy(other);
    return *this;
}

void PathNotifyMsg::copy(const PathNotifyMsg& other)
{
    this->session = other.session;
    this->sender = other.sender;
    this->status = other.status;
}

void PathNotifyMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SignallingMsg::parsimPack(b);
    doParsimPacking(b,this->session);
    doParsimPacking(b,this->sender);
    doParsimPacking(b,this->status);
}

void PathNotifyMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SignallingMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->session);
    doParsimUnpacking(b,this->sender);
    doParsimUnpacking(b,this->status);
}

const SessionObj& PathNotifyMsg::getSession() const
{
    return this->session;
}

void PathNotifyMsg::setSession(const SessionObj& session)
{
    this->session = session;
}

const SenderTemplateObj& PathNotifyMsg::getSender() const
{
    return this->sender;
}

void PathNotifyMsg::setSender(const SenderTemplateObj& sender)
{
    this->sender = sender;
}

int PathNotifyMsg::getStatus() const
{
    return this->status;
}

void PathNotifyMsg::setStatus(int status)
{
    this->status = status;
}

class PathNotifyMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_session,
        FIELD_sender,
        FIELD_status,
    };
  public:
    PathNotifyMsgDescriptor();
    virtual ~PathNotifyMsgDescriptor();

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

Register_ClassDescriptor(PathNotifyMsgDescriptor)

PathNotifyMsgDescriptor::PathNotifyMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::PathNotifyMsg)), "inet::SignallingMsg")
{
    propertynames = nullptr;
}

PathNotifyMsgDescriptor::~PathNotifyMsgDescriptor()
{
    delete[] propertynames;
}

bool PathNotifyMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PathNotifyMsg *>(obj)!=nullptr;
}

const char **PathNotifyMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PathNotifyMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PathNotifyMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int PathNotifyMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_session
        FD_ISCOMPOUND,    // FIELD_sender
        FD_ISEDITABLE,    // FIELD_status
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *PathNotifyMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "session",
        "sender",
        "status",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int PathNotifyMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "session") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sender") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "status") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PathNotifyMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::SessionObj",    // FIELD_session
        "inet::SenderTemplateObj",    // FIELD_sender
        "int",    // FIELD_status
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **PathNotifyMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *PathNotifyMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PathNotifyMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PathNotifyMsg *pp = (PathNotifyMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PathNotifyMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PathNotifyMsg *pp = (PathNotifyMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PathNotifyMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PathNotifyMsg *pp = (PathNotifyMsg *)object; (void)pp;
    switch (field) {
        case FIELD_session: {std::stringstream out; out << pp->getSession(); return out.str();}
        case FIELD_sender: {std::stringstream out; out << pp->getSender(); return out.str();}
        case FIELD_status: return long2string(pp->getStatus());
        default: return "";
    }
}

bool PathNotifyMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PathNotifyMsg *pp = (PathNotifyMsg *)object; (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(string2long(value)); return true;
        default: return false;
    }
}

const char *PathNotifyMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_session: return omnetpp::opp_typename(typeid(SessionObj));
        case FIELD_sender: return omnetpp::opp_typename(typeid(SenderTemplateObj));
        default: return nullptr;
    };
}

void *PathNotifyMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PathNotifyMsg *pp = (PathNotifyMsg *)object; (void)pp;
    switch (field) {
        case FIELD_session: return toVoidPtr(&pp->getSession()); break;
        case FIELD_sender: return toVoidPtr(&pp->getSender()); break;
        default: return nullptr;
    }
}

} // namespace inet

