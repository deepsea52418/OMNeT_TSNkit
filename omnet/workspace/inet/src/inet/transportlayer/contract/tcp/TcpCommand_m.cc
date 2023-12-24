//
// Generated file, do not edit! Created by nedtool 5.6 from inet/transportlayer/contract/tcp/TcpCommand.msg.
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
#include "TcpCommand_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::TcpCommandCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::TcpCommandCode"));
    e->insert(TCP_C_OPEN_ACTIVE, "TCP_C_OPEN_ACTIVE");
    e->insert(TCP_C_OPEN_PASSIVE, "TCP_C_OPEN_PASSIVE");
    e->insert(TCP_C_ACCEPT, "TCP_C_ACCEPT");
    e->insert(TCP_C_SEND, "TCP_C_SEND");
    e->insert(TCP_C_CLOSE, "TCP_C_CLOSE");
    e->insert(TCP_C_ABORT, "TCP_C_ABORT");
    e->insert(TCP_C_STATUS, "TCP_C_STATUS");
    e->insert(TCP_C_QUEUE_BYTES_LIMIT, "TCP_C_QUEUE_BYTES_LIMIT");
    e->insert(TCP_C_READ, "TCP_C_READ");
    e->insert(TCP_C_DESTROY, "TCP_C_DESTROY");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::TcpStatusInd");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::TcpStatusInd"));
    e->insert(TCP_I_DATA, "TCP_I_DATA");
    e->insert(TCP_I_URGENT_DATA, "TCP_I_URGENT_DATA");
    e->insert(TCP_I_AVAILABLE, "TCP_I_AVAILABLE");
    e->insert(TCP_I_ESTABLISHED, "TCP_I_ESTABLISHED");
    e->insert(TCP_I_PEER_CLOSED, "TCP_I_PEER_CLOSED");
    e->insert(TCP_I_CLOSED, "TCP_I_CLOSED");
    e->insert(TCP_I_CONNECTION_REFUSED, "TCP_I_CONNECTION_REFUSED");
    e->insert(TCP_I_CONNECTION_RESET, "TCP_I_CONNECTION_RESET");
    e->insert(TCP_I_TIMED_OUT, "TCP_I_TIMED_OUT");
    e->insert(TCP_I_STATUS, "TCP_I_STATUS");
    e->insert(TCP_I_SEND_MSG, "TCP_I_SEND_MSG");
    e->insert(TCP_I_DATA_NOTIFICATION, "TCP_I_DATA_NOTIFICATION");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::TcpErrorCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::TcpErrorCode"));
)

Register_Class(TcpCommand)

TcpCommand::TcpCommand() : ::omnetpp::cObject()
{
}

TcpCommand::TcpCommand(const TcpCommand& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

TcpCommand::~TcpCommand()
{
}

TcpCommand& TcpCommand::operator=(const TcpCommand& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void TcpCommand::copy(const TcpCommand& other)
{
    this->userId = other.userId;
}

void TcpCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->userId);
}

void TcpCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->userId);
}

int TcpCommand::getUserId() const
{
    return this->userId;
}

void TcpCommand::setUserId(int userId)
{
    this->userId = userId;
}

class TcpCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_userId,
    };
  public:
    TcpCommandDescriptor();
    virtual ~TcpCommandDescriptor();

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

Register_ClassDescriptor(TcpCommandDescriptor)

TcpCommandDescriptor::TcpCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TcpCommand)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

TcpCommandDescriptor::~TcpCommandDescriptor()
{
    delete[] propertynames;
}

bool TcpCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpCommand *>(obj)!=nullptr;
}

const char **TcpCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int TcpCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_userId
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *TcpCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "userId",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int TcpCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'u' && strcmp(fieldName, "userId") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_userId
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpCommand *pp = (TcpCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpCommand *pp = (TcpCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpCommand *pp = (TcpCommand *)object; (void)pp;
    switch (field) {
        case FIELD_userId: return long2string(pp->getUserId());
        default: return "";
    }
}

bool TcpCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpCommand *pp = (TcpCommand *)object; (void)pp;
    switch (field) {
        case FIELD_userId: pp->setUserId(string2long(value)); return true;
        default: return false;
    }
}

const char *TcpCommandDescriptor::getFieldStructName(int field) const
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

void *TcpCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpCommand *pp = (TcpCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TcpErrorInfo)

TcpErrorInfo::TcpErrorInfo() : ::inet::TcpCommand()
{
}

TcpErrorInfo::TcpErrorInfo(const TcpErrorInfo& other) : ::inet::TcpCommand(other)
{
    copy(other);
}

TcpErrorInfo::~TcpErrorInfo()
{
}

TcpErrorInfo& TcpErrorInfo::operator=(const TcpErrorInfo& other)
{
    if (this == &other) return *this;
    ::inet::TcpCommand::operator=(other);
    copy(other);
    return *this;
}

void TcpErrorInfo::copy(const TcpErrorInfo& other)
{
    this->errorCode = other.errorCode;
    this->messageText = other.messageText;
}

void TcpErrorInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TcpCommand::parsimPack(b);
    doParsimPacking(b,this->errorCode);
    doParsimPacking(b,this->messageText);
}

void TcpErrorInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TcpCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->errorCode);
    doParsimUnpacking(b,this->messageText);
}

inet::TcpErrorCode TcpErrorInfo::getErrorCode() const
{
    return this->errorCode;
}

void TcpErrorInfo::setErrorCode(inet::TcpErrorCode errorCode)
{
    this->errorCode = errorCode;
}

const char * TcpErrorInfo::getMessageText() const
{
    return this->messageText.c_str();
}

void TcpErrorInfo::setMessageText(const char * messageText)
{
    this->messageText = messageText;
}

class TcpErrorInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_errorCode,
        FIELD_messageText,
    };
  public:
    TcpErrorInfoDescriptor();
    virtual ~TcpErrorInfoDescriptor();

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

Register_ClassDescriptor(TcpErrorInfoDescriptor)

TcpErrorInfoDescriptor::TcpErrorInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TcpErrorInfo)), "inet::TcpCommand")
{
    propertynames = nullptr;
}

TcpErrorInfoDescriptor::~TcpErrorInfoDescriptor()
{
    delete[] propertynames;
}

bool TcpErrorInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpErrorInfo *>(obj)!=nullptr;
}

const char **TcpErrorInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpErrorInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpErrorInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int TcpErrorInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_errorCode
        FD_ISEDITABLE,    // FIELD_messageText
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *TcpErrorInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "errorCode",
        "messageText",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int TcpErrorInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'e' && strcmp(fieldName, "errorCode") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "messageText") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpErrorInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::TcpErrorCode",    // FIELD_errorCode
        "string",    // FIELD_messageText
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpErrorInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_errorCode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *TcpErrorInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_errorCode:
            if (!strcmp(propertyname, "enum")) return "inet::TcpErrorCode";
            return nullptr;
        default: return nullptr;
    }
}

int TcpErrorInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpErrorInfo *pp = (TcpErrorInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpErrorInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpErrorInfo *pp = (TcpErrorInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpErrorInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpErrorInfo *pp = (TcpErrorInfo *)object; (void)pp;
    switch (field) {
        case FIELD_errorCode: return enum2string(pp->getErrorCode(), "inet::TcpErrorCode");
        case FIELD_messageText: return oppstring2string(pp->getMessageText());
        default: return "";
    }
}

bool TcpErrorInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpErrorInfo *pp = (TcpErrorInfo *)object; (void)pp;
    switch (field) {
        case FIELD_messageText: pp->setMessageText((value)); return true;
        default: return false;
    }
}

const char *TcpErrorInfoDescriptor::getFieldStructName(int field) const
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

void *TcpErrorInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpErrorInfo *pp = (TcpErrorInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TcpOpenCommand)

TcpOpenCommand::TcpOpenCommand() : ::inet::TcpCommand()
{
}

TcpOpenCommand::TcpOpenCommand(const TcpOpenCommand& other) : ::inet::TcpCommand(other)
{
    copy(other);
}

TcpOpenCommand::~TcpOpenCommand()
{
}

TcpOpenCommand& TcpOpenCommand::operator=(const TcpOpenCommand& other)
{
    if (this == &other) return *this;
    ::inet::TcpCommand::operator=(other);
    copy(other);
    return *this;
}

void TcpOpenCommand::copy(const TcpOpenCommand& other)
{
    this->localAddr = other.localAddr;
    this->remoteAddr = other.remoteAddr;
    this->localPort = other.localPort;
    this->remotePort = other.remotePort;
    this->fork = other.fork;
    this->tcpAlgorithmClass = other.tcpAlgorithmClass;
}

void TcpOpenCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TcpCommand::parsimPack(b);
    doParsimPacking(b,this->localAddr);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->localPort);
    doParsimPacking(b,this->remotePort);
    doParsimPacking(b,this->fork);
    doParsimPacking(b,this->tcpAlgorithmClass);
}

void TcpOpenCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TcpCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->localAddr);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->localPort);
    doParsimUnpacking(b,this->remotePort);
    doParsimUnpacking(b,this->fork);
    doParsimUnpacking(b,this->tcpAlgorithmClass);
}

const L3Address& TcpOpenCommand::getLocalAddr() const
{
    return this->localAddr;
}

void TcpOpenCommand::setLocalAddr(const L3Address& localAddr)
{
    this->localAddr = localAddr;
}

const L3Address& TcpOpenCommand::getRemoteAddr() const
{
    return this->remoteAddr;
}

void TcpOpenCommand::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

int TcpOpenCommand::getLocalPort() const
{
    return this->localPort;
}

void TcpOpenCommand::setLocalPort(int localPort)
{
    this->localPort = localPort;
}

int TcpOpenCommand::getRemotePort() const
{
    return this->remotePort;
}

void TcpOpenCommand::setRemotePort(int remotePort)
{
    this->remotePort = remotePort;
}

bool TcpOpenCommand::getFork() const
{
    return this->fork;
}

void TcpOpenCommand::setFork(bool fork)
{
    this->fork = fork;
}

const char * TcpOpenCommand::getTcpAlgorithmClass() const
{
    return this->tcpAlgorithmClass.c_str();
}

void TcpOpenCommand::setTcpAlgorithmClass(const char * tcpAlgorithmClass)
{
    this->tcpAlgorithmClass = tcpAlgorithmClass;
}

class TcpOpenCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_localAddr,
        FIELD_remoteAddr,
        FIELD_localPort,
        FIELD_remotePort,
        FIELD_fork,
        FIELD_tcpAlgorithmClass,
    };
  public:
    TcpOpenCommandDescriptor();
    virtual ~TcpOpenCommandDescriptor();

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

Register_ClassDescriptor(TcpOpenCommandDescriptor)

TcpOpenCommandDescriptor::TcpOpenCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TcpOpenCommand)), "inet::TcpCommand")
{
    propertynames = nullptr;
}

TcpOpenCommandDescriptor::~TcpOpenCommandDescriptor()
{
    delete[] propertynames;
}

bool TcpOpenCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpOpenCommand *>(obj)!=nullptr;
}

const char **TcpOpenCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpOpenCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpOpenCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int TcpOpenCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_localAddr
        0,    // FIELD_remoteAddr
        FD_ISEDITABLE,    // FIELD_localPort
        FD_ISEDITABLE,    // FIELD_remotePort
        FD_ISEDITABLE,    // FIELD_fork
        FD_ISEDITABLE,    // FIELD_tcpAlgorithmClass
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *TcpOpenCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "localAddr",
        "remoteAddr",
        "localPort",
        "remotePort",
        "fork",
        "tcpAlgorithmClass",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int TcpOpenCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localAddr") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddr") == 0) return base+1;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localPort") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remotePort") == 0) return base+3;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fork") == 0) return base+4;
    if (fieldName[0] == 't' && strcmp(fieldName, "tcpAlgorithmClass") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpOpenCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_localAddr
        "inet::L3Address",    // FIELD_remoteAddr
        "int",    // FIELD_localPort
        "int",    // FIELD_remotePort
        "bool",    // FIELD_fork
        "string",    // FIELD_tcpAlgorithmClass
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpOpenCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpOpenCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpOpenCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpOpenCommand *pp = (TcpOpenCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpOpenCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpOpenCommand *pp = (TcpOpenCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpOpenCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpOpenCommand *pp = (TcpOpenCommand *)object; (void)pp;
    switch (field) {
        case FIELD_localAddr: return pp->getLocalAddr().str();
        case FIELD_remoteAddr: return pp->getRemoteAddr().str();
        case FIELD_localPort: return long2string(pp->getLocalPort());
        case FIELD_remotePort: return long2string(pp->getRemotePort());
        case FIELD_fork: return bool2string(pp->getFork());
        case FIELD_tcpAlgorithmClass: return oppstring2string(pp->getTcpAlgorithmClass());
        default: return "";
    }
}

bool TcpOpenCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpOpenCommand *pp = (TcpOpenCommand *)object; (void)pp;
    switch (field) {
        case FIELD_localPort: pp->setLocalPort(string2long(value)); return true;
        case FIELD_remotePort: pp->setRemotePort(string2long(value)); return true;
        case FIELD_fork: pp->setFork(string2bool(value)); return true;
        case FIELD_tcpAlgorithmClass: pp->setTcpAlgorithmClass((value)); return true;
        default: return false;
    }
}

const char *TcpOpenCommandDescriptor::getFieldStructName(int field) const
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

void *TcpOpenCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpOpenCommand *pp = (TcpOpenCommand *)object; (void)pp;
    switch (field) {
        case FIELD_localAddr: return toVoidPtr(&pp->getLocalAddr()); break;
        case FIELD_remoteAddr: return toVoidPtr(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(TcpAcceptCommand)

TcpAcceptCommand::TcpAcceptCommand() : ::inet::TcpCommand()
{
}

TcpAcceptCommand::TcpAcceptCommand(const TcpAcceptCommand& other) : ::inet::TcpCommand(other)
{
    copy(other);
}

TcpAcceptCommand::~TcpAcceptCommand()
{
}

TcpAcceptCommand& TcpAcceptCommand::operator=(const TcpAcceptCommand& other)
{
    if (this == &other) return *this;
    ::inet::TcpCommand::operator=(other);
    copy(other);
    return *this;
}

void TcpAcceptCommand::copy(const TcpAcceptCommand& other)
{
}

void TcpAcceptCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TcpCommand::parsimPack(b);
}

void TcpAcceptCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TcpCommand::parsimUnpack(b);
}

class TcpAcceptCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    TcpAcceptCommandDescriptor();
    virtual ~TcpAcceptCommandDescriptor();

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

Register_ClassDescriptor(TcpAcceptCommandDescriptor)

TcpAcceptCommandDescriptor::TcpAcceptCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TcpAcceptCommand)), "inet::TcpCommand")
{
    propertynames = nullptr;
}

TcpAcceptCommandDescriptor::~TcpAcceptCommandDescriptor()
{
    delete[] propertynames;
}

bool TcpAcceptCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpAcceptCommand *>(obj)!=nullptr;
}

const char **TcpAcceptCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpAcceptCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpAcceptCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int TcpAcceptCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *TcpAcceptCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int TcpAcceptCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpAcceptCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **TcpAcceptCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpAcceptCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpAcceptCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpAcceptCommand *pp = (TcpAcceptCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpAcceptCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpAcceptCommand *pp = (TcpAcceptCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpAcceptCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpAcceptCommand *pp = (TcpAcceptCommand *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool TcpAcceptCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpAcceptCommand *pp = (TcpAcceptCommand *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TcpAcceptCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *TcpAcceptCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpAcceptCommand *pp = (TcpAcceptCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TcpAvailableInfo)

TcpAvailableInfo::TcpAvailableInfo() : ::inet::TcpCommand()
{
}

TcpAvailableInfo::TcpAvailableInfo(const TcpAvailableInfo& other) : ::inet::TcpCommand(other)
{
    copy(other);
}

TcpAvailableInfo::~TcpAvailableInfo()
{
}

TcpAvailableInfo& TcpAvailableInfo::operator=(const TcpAvailableInfo& other)
{
    if (this == &other) return *this;
    ::inet::TcpCommand::operator=(other);
    copy(other);
    return *this;
}

void TcpAvailableInfo::copy(const TcpAvailableInfo& other)
{
    this->localAddr = other.localAddr;
    this->remoteAddr = other.remoteAddr;
    this->localPort = other.localPort;
    this->remotePort = other.remotePort;
    this->newSocketId = other.newSocketId;
}

void TcpAvailableInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TcpCommand::parsimPack(b);
    doParsimPacking(b,this->localAddr);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->localPort);
    doParsimPacking(b,this->remotePort);
    doParsimPacking(b,this->newSocketId);
}

void TcpAvailableInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TcpCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->localAddr);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->localPort);
    doParsimUnpacking(b,this->remotePort);
    doParsimUnpacking(b,this->newSocketId);
}

const L3Address& TcpAvailableInfo::getLocalAddr() const
{
    return this->localAddr;
}

void TcpAvailableInfo::setLocalAddr(const L3Address& localAddr)
{
    this->localAddr = localAddr;
}

const L3Address& TcpAvailableInfo::getRemoteAddr() const
{
    return this->remoteAddr;
}

void TcpAvailableInfo::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

int TcpAvailableInfo::getLocalPort() const
{
    return this->localPort;
}

void TcpAvailableInfo::setLocalPort(int localPort)
{
    this->localPort = localPort;
}

int TcpAvailableInfo::getRemotePort() const
{
    return this->remotePort;
}

void TcpAvailableInfo::setRemotePort(int remotePort)
{
    this->remotePort = remotePort;
}

int TcpAvailableInfo::getNewSocketId() const
{
    return this->newSocketId;
}

void TcpAvailableInfo::setNewSocketId(int newSocketId)
{
    this->newSocketId = newSocketId;
}

class TcpAvailableInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_localAddr,
        FIELD_remoteAddr,
        FIELD_localPort,
        FIELD_remotePort,
        FIELD_newSocketId,
    };
  public:
    TcpAvailableInfoDescriptor();
    virtual ~TcpAvailableInfoDescriptor();

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

Register_ClassDescriptor(TcpAvailableInfoDescriptor)

TcpAvailableInfoDescriptor::TcpAvailableInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TcpAvailableInfo)), "inet::TcpCommand")
{
    propertynames = nullptr;
}

TcpAvailableInfoDescriptor::~TcpAvailableInfoDescriptor()
{
    delete[] propertynames;
}

bool TcpAvailableInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpAvailableInfo *>(obj)!=nullptr;
}

const char **TcpAvailableInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpAvailableInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpAvailableInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int TcpAvailableInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_localAddr
        0,    // FIELD_remoteAddr
        FD_ISEDITABLE,    // FIELD_localPort
        FD_ISEDITABLE,    // FIELD_remotePort
        FD_ISEDITABLE,    // FIELD_newSocketId
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *TcpAvailableInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "localAddr",
        "remoteAddr",
        "localPort",
        "remotePort",
        "newSocketId",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int TcpAvailableInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localAddr") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddr") == 0) return base+1;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localPort") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remotePort") == 0) return base+3;
    if (fieldName[0] == 'n' && strcmp(fieldName, "newSocketId") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpAvailableInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_localAddr
        "inet::L3Address",    // FIELD_remoteAddr
        "int",    // FIELD_localPort
        "int",    // FIELD_remotePort
        "int",    // FIELD_newSocketId
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpAvailableInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpAvailableInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpAvailableInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpAvailableInfo *pp = (TcpAvailableInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpAvailableInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpAvailableInfo *pp = (TcpAvailableInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpAvailableInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpAvailableInfo *pp = (TcpAvailableInfo *)object; (void)pp;
    switch (field) {
        case FIELD_localAddr: return pp->getLocalAddr().str();
        case FIELD_remoteAddr: return pp->getRemoteAddr().str();
        case FIELD_localPort: return long2string(pp->getLocalPort());
        case FIELD_remotePort: return long2string(pp->getRemotePort());
        case FIELD_newSocketId: return long2string(pp->getNewSocketId());
        default: return "";
    }
}

bool TcpAvailableInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpAvailableInfo *pp = (TcpAvailableInfo *)object; (void)pp;
    switch (field) {
        case FIELD_localPort: pp->setLocalPort(string2long(value)); return true;
        case FIELD_remotePort: pp->setRemotePort(string2long(value)); return true;
        case FIELD_newSocketId: pp->setNewSocketId(string2long(value)); return true;
        default: return false;
    }
}

const char *TcpAvailableInfoDescriptor::getFieldStructName(int field) const
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

void *TcpAvailableInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpAvailableInfo *pp = (TcpAvailableInfo *)object; (void)pp;
    switch (field) {
        case FIELD_localAddr: return toVoidPtr(&pp->getLocalAddr()); break;
        case FIELD_remoteAddr: return toVoidPtr(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(TcpConnectInfo)

TcpConnectInfo::TcpConnectInfo() : ::inet::TcpCommand()
{
}

TcpConnectInfo::TcpConnectInfo(const TcpConnectInfo& other) : ::inet::TcpCommand(other)
{
    copy(other);
}

TcpConnectInfo::~TcpConnectInfo()
{
}

TcpConnectInfo& TcpConnectInfo::operator=(const TcpConnectInfo& other)
{
    if (this == &other) return *this;
    ::inet::TcpCommand::operator=(other);
    copy(other);
    return *this;
}

void TcpConnectInfo::copy(const TcpConnectInfo& other)
{
    this->localAddr = other.localAddr;
    this->remoteAddr = other.remoteAddr;
    this->localPort = other.localPort;
    this->remotePort = other.remotePort;
}

void TcpConnectInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TcpCommand::parsimPack(b);
    doParsimPacking(b,this->localAddr);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->localPort);
    doParsimPacking(b,this->remotePort);
}

void TcpConnectInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TcpCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->localAddr);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->localPort);
    doParsimUnpacking(b,this->remotePort);
}

const L3Address& TcpConnectInfo::getLocalAddr() const
{
    return this->localAddr;
}

void TcpConnectInfo::setLocalAddr(const L3Address& localAddr)
{
    this->localAddr = localAddr;
}

const L3Address& TcpConnectInfo::getRemoteAddr() const
{
    return this->remoteAddr;
}

void TcpConnectInfo::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

int TcpConnectInfo::getLocalPort() const
{
    return this->localPort;
}

void TcpConnectInfo::setLocalPort(int localPort)
{
    this->localPort = localPort;
}

int TcpConnectInfo::getRemotePort() const
{
    return this->remotePort;
}

void TcpConnectInfo::setRemotePort(int remotePort)
{
    this->remotePort = remotePort;
}

class TcpConnectInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_localAddr,
        FIELD_remoteAddr,
        FIELD_localPort,
        FIELD_remotePort,
    };
  public:
    TcpConnectInfoDescriptor();
    virtual ~TcpConnectInfoDescriptor();

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

Register_ClassDescriptor(TcpConnectInfoDescriptor)

TcpConnectInfoDescriptor::TcpConnectInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TcpConnectInfo)), "inet::TcpCommand")
{
    propertynames = nullptr;
}

TcpConnectInfoDescriptor::~TcpConnectInfoDescriptor()
{
    delete[] propertynames;
}

bool TcpConnectInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpConnectInfo *>(obj)!=nullptr;
}

const char **TcpConnectInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpConnectInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpConnectInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int TcpConnectInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_localAddr
        0,    // FIELD_remoteAddr
        FD_ISEDITABLE,    // FIELD_localPort
        FD_ISEDITABLE,    // FIELD_remotePort
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *TcpConnectInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "localAddr",
        "remoteAddr",
        "localPort",
        "remotePort",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int TcpConnectInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localAddr") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddr") == 0) return base+1;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localPort") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remotePort") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpConnectInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_localAddr
        "inet::L3Address",    // FIELD_remoteAddr
        "int",    // FIELD_localPort
        "int",    // FIELD_remotePort
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpConnectInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpConnectInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpConnectInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpConnectInfo *pp = (TcpConnectInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpConnectInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpConnectInfo *pp = (TcpConnectInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpConnectInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpConnectInfo *pp = (TcpConnectInfo *)object; (void)pp;
    switch (field) {
        case FIELD_localAddr: return pp->getLocalAddr().str();
        case FIELD_remoteAddr: return pp->getRemoteAddr().str();
        case FIELD_localPort: return long2string(pp->getLocalPort());
        case FIELD_remotePort: return long2string(pp->getRemotePort());
        default: return "";
    }
}

bool TcpConnectInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpConnectInfo *pp = (TcpConnectInfo *)object; (void)pp;
    switch (field) {
        case FIELD_localPort: pp->setLocalPort(string2long(value)); return true;
        case FIELD_remotePort: pp->setRemotePort(string2long(value)); return true;
        default: return false;
    }
}

const char *TcpConnectInfoDescriptor::getFieldStructName(int field) const
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

void *TcpConnectInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpConnectInfo *pp = (TcpConnectInfo *)object; (void)pp;
    switch (field) {
        case FIELD_localAddr: return toVoidPtr(&pp->getLocalAddr()); break;
        case FIELD_remoteAddr: return toVoidPtr(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(TcpStatusInfo)

TcpStatusInfo::TcpStatusInfo() : ::inet::TcpCommand()
{
}

TcpStatusInfo::TcpStatusInfo(const TcpStatusInfo& other) : ::inet::TcpCommand(other)
{
    copy(other);
}

TcpStatusInfo::~TcpStatusInfo()
{
}

TcpStatusInfo& TcpStatusInfo::operator=(const TcpStatusInfo& other)
{
    if (this == &other) return *this;
    ::inet::TcpCommand::operator=(other);
    copy(other);
    return *this;
}

void TcpStatusInfo::copy(const TcpStatusInfo& other)
{
    this->state = other.state;
    this->stateName = other.stateName;
    this->localAddr = other.localAddr;
    this->remoteAddr = other.remoteAddr;
    this->localPort = other.localPort;
    this->remotePort = other.remotePort;
    this->snd_mss = other.snd_mss;
    this->snd_una = other.snd_una;
    this->snd_nxt = other.snd_nxt;
    this->snd_max = other.snd_max;
    this->snd_wnd = other.snd_wnd;
    this->snd_up = other.snd_up;
    this->snd_wl1 = other.snd_wl1;
    this->snd_wl2 = other.snd_wl2;
    this->iss = other.iss;
    this->rcv_nxt = other.rcv_nxt;
    this->rcv_wnd = other.rcv_wnd;
    this->rcv_up = other.rcv_up;
    this->irs = other.irs;
    this->fin_ack_rcvd = other.fin_ack_rcvd;
}

void TcpStatusInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TcpCommand::parsimPack(b);
    doParsimPacking(b,this->state);
    doParsimPacking(b,this->stateName);
    doParsimPacking(b,this->localAddr);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->localPort);
    doParsimPacking(b,this->remotePort);
    doParsimPacking(b,this->snd_mss);
    doParsimPacking(b,this->snd_una);
    doParsimPacking(b,this->snd_nxt);
    doParsimPacking(b,this->snd_max);
    doParsimPacking(b,this->snd_wnd);
    doParsimPacking(b,this->snd_up);
    doParsimPacking(b,this->snd_wl1);
    doParsimPacking(b,this->snd_wl2);
    doParsimPacking(b,this->iss);
    doParsimPacking(b,this->rcv_nxt);
    doParsimPacking(b,this->rcv_wnd);
    doParsimPacking(b,this->rcv_up);
    doParsimPacking(b,this->irs);
    doParsimPacking(b,this->fin_ack_rcvd);
}

void TcpStatusInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TcpCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->state);
    doParsimUnpacking(b,this->stateName);
    doParsimUnpacking(b,this->localAddr);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->localPort);
    doParsimUnpacking(b,this->remotePort);
    doParsimUnpacking(b,this->snd_mss);
    doParsimUnpacking(b,this->snd_una);
    doParsimUnpacking(b,this->snd_nxt);
    doParsimUnpacking(b,this->snd_max);
    doParsimUnpacking(b,this->snd_wnd);
    doParsimUnpacking(b,this->snd_up);
    doParsimUnpacking(b,this->snd_wl1);
    doParsimUnpacking(b,this->snd_wl2);
    doParsimUnpacking(b,this->iss);
    doParsimUnpacking(b,this->rcv_nxt);
    doParsimUnpacking(b,this->rcv_wnd);
    doParsimUnpacking(b,this->rcv_up);
    doParsimUnpacking(b,this->irs);
    doParsimUnpacking(b,this->fin_ack_rcvd);
}

int TcpStatusInfo::getState() const
{
    return this->state;
}

void TcpStatusInfo::setState(int state)
{
    this->state = state;
}

const char * TcpStatusInfo::getStateName() const
{
    return this->stateName.c_str();
}

void TcpStatusInfo::setStateName(const char * stateName)
{
    this->stateName = stateName;
}

const L3Address& TcpStatusInfo::getLocalAddr() const
{
    return this->localAddr;
}

void TcpStatusInfo::setLocalAddr(const L3Address& localAddr)
{
    this->localAddr = localAddr;
}

const L3Address& TcpStatusInfo::getRemoteAddr() const
{
    return this->remoteAddr;
}

void TcpStatusInfo::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

int TcpStatusInfo::getLocalPort() const
{
    return this->localPort;
}

void TcpStatusInfo::setLocalPort(int localPort)
{
    this->localPort = localPort;
}

int TcpStatusInfo::getRemotePort() const
{
    return this->remotePort;
}

void TcpStatusInfo::setRemotePort(int remotePort)
{
    this->remotePort = remotePort;
}

unsigned int TcpStatusInfo::getSnd_mss() const
{
    return this->snd_mss;
}

void TcpStatusInfo::setSnd_mss(unsigned int snd_mss)
{
    this->snd_mss = snd_mss;
}

unsigned int TcpStatusInfo::getSnd_una() const
{
    return this->snd_una;
}

void TcpStatusInfo::setSnd_una(unsigned int snd_una)
{
    this->snd_una = snd_una;
}

unsigned int TcpStatusInfo::getSnd_nxt() const
{
    return this->snd_nxt;
}

void TcpStatusInfo::setSnd_nxt(unsigned int snd_nxt)
{
    this->snd_nxt = snd_nxt;
}

unsigned int TcpStatusInfo::getSnd_max() const
{
    return this->snd_max;
}

void TcpStatusInfo::setSnd_max(unsigned int snd_max)
{
    this->snd_max = snd_max;
}

unsigned int TcpStatusInfo::getSnd_wnd() const
{
    return this->snd_wnd;
}

void TcpStatusInfo::setSnd_wnd(unsigned int snd_wnd)
{
    this->snd_wnd = snd_wnd;
}

unsigned int TcpStatusInfo::getSnd_up() const
{
    return this->snd_up;
}

void TcpStatusInfo::setSnd_up(unsigned int snd_up)
{
    this->snd_up = snd_up;
}

unsigned int TcpStatusInfo::getSnd_wl1() const
{
    return this->snd_wl1;
}

void TcpStatusInfo::setSnd_wl1(unsigned int snd_wl1)
{
    this->snd_wl1 = snd_wl1;
}

unsigned int TcpStatusInfo::getSnd_wl2() const
{
    return this->snd_wl2;
}

void TcpStatusInfo::setSnd_wl2(unsigned int snd_wl2)
{
    this->snd_wl2 = snd_wl2;
}

unsigned int TcpStatusInfo::getIss() const
{
    return this->iss;
}

void TcpStatusInfo::setIss(unsigned int iss)
{
    this->iss = iss;
}

unsigned int TcpStatusInfo::getRcv_nxt() const
{
    return this->rcv_nxt;
}

void TcpStatusInfo::setRcv_nxt(unsigned int rcv_nxt)
{
    this->rcv_nxt = rcv_nxt;
}

unsigned int TcpStatusInfo::getRcv_wnd() const
{
    return this->rcv_wnd;
}

void TcpStatusInfo::setRcv_wnd(unsigned int rcv_wnd)
{
    this->rcv_wnd = rcv_wnd;
}

unsigned int TcpStatusInfo::getRcv_up() const
{
    return this->rcv_up;
}

void TcpStatusInfo::setRcv_up(unsigned int rcv_up)
{
    this->rcv_up = rcv_up;
}

unsigned int TcpStatusInfo::getIrs() const
{
    return this->irs;
}

void TcpStatusInfo::setIrs(unsigned int irs)
{
    this->irs = irs;
}

bool TcpStatusInfo::getFin_ack_rcvd() const
{
    return this->fin_ack_rcvd;
}

void TcpStatusInfo::setFin_ack_rcvd(bool fin_ack_rcvd)
{
    this->fin_ack_rcvd = fin_ack_rcvd;
}

class TcpStatusInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_state,
        FIELD_stateName,
        FIELD_localAddr,
        FIELD_remoteAddr,
        FIELD_localPort,
        FIELD_remotePort,
        FIELD_snd_mss,
        FIELD_snd_una,
        FIELD_snd_nxt,
        FIELD_snd_max,
        FIELD_snd_wnd,
        FIELD_snd_up,
        FIELD_snd_wl1,
        FIELD_snd_wl2,
        FIELD_iss,
        FIELD_rcv_nxt,
        FIELD_rcv_wnd,
        FIELD_rcv_up,
        FIELD_irs,
        FIELD_fin_ack_rcvd,
    };
  public:
    TcpStatusInfoDescriptor();
    virtual ~TcpStatusInfoDescriptor();

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

Register_ClassDescriptor(TcpStatusInfoDescriptor)

TcpStatusInfoDescriptor::TcpStatusInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TcpStatusInfo)), "inet::TcpCommand")
{
    propertynames = nullptr;
}

TcpStatusInfoDescriptor::~TcpStatusInfoDescriptor()
{
    delete[] propertynames;
}

bool TcpStatusInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpStatusInfo *>(obj)!=nullptr;
}

const char **TcpStatusInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpStatusInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpStatusInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 20+basedesc->getFieldCount() : 20;
}

unsigned int TcpStatusInfoDescriptor::getFieldTypeFlags(int field) const
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
        0,    // FIELD_localAddr
        0,    // FIELD_remoteAddr
        FD_ISEDITABLE,    // FIELD_localPort
        FD_ISEDITABLE,    // FIELD_remotePort
        FD_ISEDITABLE,    // FIELD_snd_mss
        FD_ISEDITABLE,    // FIELD_snd_una
        FD_ISEDITABLE,    // FIELD_snd_nxt
        FD_ISEDITABLE,    // FIELD_snd_max
        FD_ISEDITABLE,    // FIELD_snd_wnd
        FD_ISEDITABLE,    // FIELD_snd_up
        FD_ISEDITABLE,    // FIELD_snd_wl1
        FD_ISEDITABLE,    // FIELD_snd_wl2
        FD_ISEDITABLE,    // FIELD_iss
        FD_ISEDITABLE,    // FIELD_rcv_nxt
        FD_ISEDITABLE,    // FIELD_rcv_wnd
        FD_ISEDITABLE,    // FIELD_rcv_up
        FD_ISEDITABLE,    // FIELD_irs
        FD_ISEDITABLE,    // FIELD_fin_ack_rcvd
    };
    return (field >= 0 && field < 20) ? fieldTypeFlags[field] : 0;
}

const char *TcpStatusInfoDescriptor::getFieldName(int field) const
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
        "localAddr",
        "remoteAddr",
        "localPort",
        "remotePort",
        "snd_mss",
        "snd_una",
        "snd_nxt",
        "snd_max",
        "snd_wnd",
        "snd_up",
        "snd_wl1",
        "snd_wl2",
        "iss",
        "rcv_nxt",
        "rcv_wnd",
        "rcv_up",
        "irs",
        "fin_ack_rcvd",
    };
    return (field >= 0 && field < 20) ? fieldNames[field] : nullptr;
}

int TcpStatusInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "state") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "stateName") == 0) return base+1;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localAddr") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddr") == 0) return base+3;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localPort") == 0) return base+4;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remotePort") == 0) return base+5;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_mss") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_una") == 0) return base+7;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_nxt") == 0) return base+8;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_max") == 0) return base+9;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_wnd") == 0) return base+10;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_up") == 0) return base+11;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_wl1") == 0) return base+12;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_wl2") == 0) return base+13;
    if (fieldName[0] == 'i' && strcmp(fieldName, "iss") == 0) return base+14;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_nxt") == 0) return base+15;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_wnd") == 0) return base+16;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_up") == 0) return base+17;
    if (fieldName[0] == 'i' && strcmp(fieldName, "irs") == 0) return base+18;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fin_ack_rcvd") == 0) return base+19;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpStatusInfoDescriptor::getFieldTypeString(int field) const
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
        "inet::L3Address",    // FIELD_localAddr
        "inet::L3Address",    // FIELD_remoteAddr
        "int",    // FIELD_localPort
        "int",    // FIELD_remotePort
        "unsigned int",    // FIELD_snd_mss
        "unsigned int",    // FIELD_snd_una
        "unsigned int",    // FIELD_snd_nxt
        "unsigned int",    // FIELD_snd_max
        "unsigned int",    // FIELD_snd_wnd
        "unsigned int",    // FIELD_snd_up
        "unsigned int",    // FIELD_snd_wl1
        "unsigned int",    // FIELD_snd_wl2
        "unsigned int",    // FIELD_iss
        "unsigned int",    // FIELD_rcv_nxt
        "unsigned int",    // FIELD_rcv_wnd
        "unsigned int",    // FIELD_rcv_up
        "unsigned int",    // FIELD_irs
        "bool",    // FIELD_fin_ack_rcvd
    };
    return (field >= 0 && field < 20) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpStatusInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpStatusInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpStatusInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpStatusInfo *pp = (TcpStatusInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpStatusInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpStatusInfo *pp = (TcpStatusInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpStatusInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpStatusInfo *pp = (TcpStatusInfo *)object; (void)pp;
    switch (field) {
        case FIELD_state: return long2string(pp->getState());
        case FIELD_stateName: return oppstring2string(pp->getStateName());
        case FIELD_localAddr: return pp->getLocalAddr().str();
        case FIELD_remoteAddr: return pp->getRemoteAddr().str();
        case FIELD_localPort: return long2string(pp->getLocalPort());
        case FIELD_remotePort: return long2string(pp->getRemotePort());
        case FIELD_snd_mss: return ulong2string(pp->getSnd_mss());
        case FIELD_snd_una: return ulong2string(pp->getSnd_una());
        case FIELD_snd_nxt: return ulong2string(pp->getSnd_nxt());
        case FIELD_snd_max: return ulong2string(pp->getSnd_max());
        case FIELD_snd_wnd: return ulong2string(pp->getSnd_wnd());
        case FIELD_snd_up: return ulong2string(pp->getSnd_up());
        case FIELD_snd_wl1: return ulong2string(pp->getSnd_wl1());
        case FIELD_snd_wl2: return ulong2string(pp->getSnd_wl2());
        case FIELD_iss: return ulong2string(pp->getIss());
        case FIELD_rcv_nxt: return ulong2string(pp->getRcv_nxt());
        case FIELD_rcv_wnd: return ulong2string(pp->getRcv_wnd());
        case FIELD_rcv_up: return ulong2string(pp->getRcv_up());
        case FIELD_irs: return ulong2string(pp->getIrs());
        case FIELD_fin_ack_rcvd: return bool2string(pp->getFin_ack_rcvd());
        default: return "";
    }
}

bool TcpStatusInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpStatusInfo *pp = (TcpStatusInfo *)object; (void)pp;
    switch (field) {
        case FIELD_state: pp->setState(string2long(value)); return true;
        case FIELD_stateName: pp->setStateName((value)); return true;
        case FIELD_localPort: pp->setLocalPort(string2long(value)); return true;
        case FIELD_remotePort: pp->setRemotePort(string2long(value)); return true;
        case FIELD_snd_mss: pp->setSnd_mss(string2ulong(value)); return true;
        case FIELD_snd_una: pp->setSnd_una(string2ulong(value)); return true;
        case FIELD_snd_nxt: pp->setSnd_nxt(string2ulong(value)); return true;
        case FIELD_snd_max: pp->setSnd_max(string2ulong(value)); return true;
        case FIELD_snd_wnd: pp->setSnd_wnd(string2ulong(value)); return true;
        case FIELD_snd_up: pp->setSnd_up(string2ulong(value)); return true;
        case FIELD_snd_wl1: pp->setSnd_wl1(string2ulong(value)); return true;
        case FIELD_snd_wl2: pp->setSnd_wl2(string2ulong(value)); return true;
        case FIELD_iss: pp->setIss(string2ulong(value)); return true;
        case FIELD_rcv_nxt: pp->setRcv_nxt(string2ulong(value)); return true;
        case FIELD_rcv_wnd: pp->setRcv_wnd(string2ulong(value)); return true;
        case FIELD_rcv_up: pp->setRcv_up(string2ulong(value)); return true;
        case FIELD_irs: pp->setIrs(string2ulong(value)); return true;
        case FIELD_fin_ack_rcvd: pp->setFin_ack_rcvd(string2bool(value)); return true;
        default: return false;
    }
}

const char *TcpStatusInfoDescriptor::getFieldStructName(int field) const
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

void *TcpStatusInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpStatusInfo *pp = (TcpStatusInfo *)object; (void)pp;
    switch (field) {
        case FIELD_localAddr: return toVoidPtr(&pp->getLocalAddr()); break;
        case FIELD_remoteAddr: return toVoidPtr(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

} // namespace inet

