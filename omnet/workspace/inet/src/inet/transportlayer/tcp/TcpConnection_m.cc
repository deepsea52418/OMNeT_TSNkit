//
// Generated file, do not edit! Created by nedtool 5.6 from inet/transportlayer/tcp/TcpConnection.msg.
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
#include "TcpConnection_m.h"

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
namespace tcp {

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

class TcpSackRexmitQueueDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    TcpSackRexmitQueueDescriptor();
    virtual ~TcpSackRexmitQueueDescriptor();

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

Register_ClassDescriptor(TcpSackRexmitQueueDescriptor)

TcpSackRexmitQueueDescriptor::TcpSackRexmitQueueDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::tcp::TcpSackRexmitQueue)), "")
{
    propertynames = nullptr;
}

TcpSackRexmitQueueDescriptor::~TcpSackRexmitQueueDescriptor()
{
    delete[] propertynames;
}

bool TcpSackRexmitQueueDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpSackRexmitQueue *>(obj)!=nullptr;
}

const char **TcpSackRexmitQueueDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpSackRexmitQueueDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpSackRexmitQueueDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int TcpSackRexmitQueueDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *TcpSackRexmitQueueDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int TcpSackRexmitQueueDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpSackRexmitQueueDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **TcpSackRexmitQueueDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpSackRexmitQueueDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpSackRexmitQueueDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpSackRexmitQueue *pp = (TcpSackRexmitQueue *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpSackRexmitQueueDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpSackRexmitQueue *pp = (TcpSackRexmitQueue *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpSackRexmitQueueDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpSackRexmitQueue *pp = (TcpSackRexmitQueue *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool TcpSackRexmitQueueDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpSackRexmitQueue *pp = (TcpSackRexmitQueue *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TcpSackRexmitQueueDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *TcpSackRexmitQueueDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpSackRexmitQueue *pp = (TcpSackRexmitQueue *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class TcpAlgorithmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
    };
  public:
    TcpAlgorithmDescriptor();
    virtual ~TcpAlgorithmDescriptor();

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

Register_ClassDescriptor(TcpAlgorithmDescriptor)

TcpAlgorithmDescriptor::TcpAlgorithmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::tcp::TcpAlgorithm)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

TcpAlgorithmDescriptor::~TcpAlgorithmDescriptor()
{
    delete[] propertynames;
}

bool TcpAlgorithmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpAlgorithm *>(obj)!=nullptr;
}

const char **TcpAlgorithmDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpAlgorithmDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpAlgorithmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int TcpAlgorithmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *TcpAlgorithmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int TcpAlgorithmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpAlgorithmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **TcpAlgorithmDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpAlgorithmDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpAlgorithmDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpAlgorithm *pp = (TcpAlgorithm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpAlgorithmDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpAlgorithm *pp = (TcpAlgorithm *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpAlgorithmDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpAlgorithm *pp = (TcpAlgorithm *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool TcpAlgorithmDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpAlgorithm *pp = (TcpAlgorithm *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TcpAlgorithmDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *TcpAlgorithmDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpAlgorithm *pp = (TcpAlgorithm *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class TcpStateVariablesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_active,
        FIELD_fork,
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
        FIELD_rcv_adv,
        FIELD_syn_rexmit_count,
        FIELD_syn_rexmit_timeout,
        FIELD_fin_ack_rcvd,
        FIELD_send_fin,
        FIELD_snd_fin_seq,
        FIELD_fin_rcvd,
        FIELD_rcv_fin_seq,
        FIELD_sentBytes,
        FIELD_nagle_enabled,
        FIELD_delayed_acks_enabled,
        FIELD_limited_transmit_enabled,
        FIELD_increased_IW_enabled,
        FIELD_full_sized_segment_counter,
        FIELD_ack_now,
        FIELD_afterRto,
        FIELD_ws_support,
        FIELD_ws_enabled,
        FIELD_ws_manual_scale,
        FIELD_snd_ws,
        FIELD_rcv_ws,
        FIELD_rcv_wnd_scale,
        FIELD_snd_wnd_scale,
        FIELD_ts_support,
        FIELD_ts_enabled,
        FIELD_snd_initial_ts,
        FIELD_rcv_initial_ts,
        FIELD_ts_recent,
        FIELD_last_ack_sent,
        FIELD_time_last_data_sent,
        FIELD_sack_support,
        FIELD_sack_enabled,
        FIELD_snd_sack_perm,
        FIELD_rcv_sack_perm,
        FIELD_start_seqno,
        FIELD_end_seqno,
        FIELD_snd_sack,
        FIELD_snd_dsack,
        FIELD_highRxt,
        FIELD_pipe,
        FIELD_recoveryPoint,
        FIELD_sackedBytes,
        FIELD_sackedBytes_old,
        FIELD_lossRecovery,
        FIELD_sendQueueLimit,
        FIELD_queueUpdate,
        FIELD_dupacks,
        FIELD_snd_sacks,
        FIELD_rcv_sacks,
        FIELD_rcv_oooseg,
        FIELD_rcv_naseg,
        FIELD_maxRcvBuffer,
        FIELD_usedRcvBuffer,
        FIELD_freeRcvBuffer,
        FIELD_tcpRcvQueueDrops,
    };
  public:
    TcpStateVariablesDescriptor();
    virtual ~TcpStateVariablesDescriptor();

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

Register_ClassDescriptor(TcpStateVariablesDescriptor)

TcpStateVariablesDescriptor::TcpStateVariablesDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::tcp::TcpStateVariables)), "")
{
    propertynames = nullptr;
}

TcpStateVariablesDescriptor::~TcpStateVariablesDescriptor()
{
    delete[] propertynames;
}

bool TcpStateVariablesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpStateVariables *>(obj)!=nullptr;
}

const char **TcpStateVariablesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpStateVariablesDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpStateVariablesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 70+basedesc->getFieldCount() : 70;
}

unsigned int TcpStateVariablesDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_active
        0,    // FIELD_fork
        0,    // FIELD_snd_mss
        0,    // FIELD_snd_una
        0,    // FIELD_snd_nxt
        0,    // FIELD_snd_max
        0,    // FIELD_snd_wnd
        0,    // FIELD_snd_up
        0,    // FIELD_snd_wl1
        0,    // FIELD_snd_wl2
        0,    // FIELD_iss
        0,    // FIELD_rcv_nxt
        0,    // FIELD_rcv_wnd
        0,    // FIELD_rcv_up
        0,    // FIELD_irs
        0,    // FIELD_rcv_adv
        0,    // FIELD_syn_rexmit_count
        0,    // FIELD_syn_rexmit_timeout
        0,    // FIELD_fin_ack_rcvd
        0,    // FIELD_send_fin
        0,    // FIELD_snd_fin_seq
        0,    // FIELD_fin_rcvd
        0,    // FIELD_rcv_fin_seq
        0,    // FIELD_sentBytes
        0,    // FIELD_nagle_enabled
        0,    // FIELD_delayed_acks_enabled
        0,    // FIELD_limited_transmit_enabled
        0,    // FIELD_increased_IW_enabled
        0,    // FIELD_full_sized_segment_counter
        0,    // FIELD_ack_now
        0,    // FIELD_afterRto
        0,    // FIELD_ws_support
        0,    // FIELD_ws_enabled
        0,    // FIELD_ws_manual_scale
        0,    // FIELD_snd_ws
        0,    // FIELD_rcv_ws
        0,    // FIELD_rcv_wnd_scale
        0,    // FIELD_snd_wnd_scale
        0,    // FIELD_ts_support
        0,    // FIELD_ts_enabled
        0,    // FIELD_snd_initial_ts
        0,    // FIELD_rcv_initial_ts
        0,    // FIELD_ts_recent
        0,    // FIELD_last_ack_sent
        0,    // FIELD_time_last_data_sent
        0,    // FIELD_sack_support
        0,    // FIELD_sack_enabled
        0,    // FIELD_snd_sack_perm
        0,    // FIELD_rcv_sack_perm
        0,    // FIELD_start_seqno
        0,    // FIELD_end_seqno
        0,    // FIELD_snd_sack
        0,    // FIELD_snd_dsack
        0,    // FIELD_highRxt
        0,    // FIELD_pipe
        0,    // FIELD_recoveryPoint
        0,    // FIELD_sackedBytes
        0,    // FIELD_sackedBytes_old
        0,    // FIELD_lossRecovery
        0,    // FIELD_sendQueueLimit
        0,    // FIELD_queueUpdate
        0,    // FIELD_dupacks
        0,    // FIELD_snd_sacks
        0,    // FIELD_rcv_sacks
        0,    // FIELD_rcv_oooseg
        0,    // FIELD_rcv_naseg
        0,    // FIELD_maxRcvBuffer
        0,    // FIELD_usedRcvBuffer
        0,    // FIELD_freeRcvBuffer
        0,    // FIELD_tcpRcvQueueDrops
    };
    return (field >= 0 && field < 70) ? fieldTypeFlags[field] : 0;
}

const char *TcpStateVariablesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "active",
        "fork",
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
        "rcv_adv",
        "syn_rexmit_count",
        "syn_rexmit_timeout",
        "fin_ack_rcvd",
        "send_fin",
        "snd_fin_seq",
        "fin_rcvd",
        "rcv_fin_seq",
        "sentBytes",
        "nagle_enabled",
        "delayed_acks_enabled",
        "limited_transmit_enabled",
        "increased_IW_enabled",
        "full_sized_segment_counter",
        "ack_now",
        "afterRto",
        "ws_support",
        "ws_enabled",
        "ws_manual_scale",
        "snd_ws",
        "rcv_ws",
        "rcv_wnd_scale",
        "snd_wnd_scale",
        "ts_support",
        "ts_enabled",
        "snd_initial_ts",
        "rcv_initial_ts",
        "ts_recent",
        "last_ack_sent",
        "time_last_data_sent",
        "sack_support",
        "sack_enabled",
        "snd_sack_perm",
        "rcv_sack_perm",
        "start_seqno",
        "end_seqno",
        "snd_sack",
        "snd_dsack",
        "highRxt",
        "pipe",
        "recoveryPoint",
        "sackedBytes",
        "sackedBytes_old",
        "lossRecovery",
        "sendQueueLimit",
        "queueUpdate",
        "dupacks",
        "snd_sacks",
        "rcv_sacks",
        "rcv_oooseg",
        "rcv_naseg",
        "maxRcvBuffer",
        "usedRcvBuffer",
        "freeRcvBuffer",
        "tcpRcvQueueDrops",
    };
    return (field >= 0 && field < 70) ? fieldNames[field] : nullptr;
}

int TcpStateVariablesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "active") == 0) return base+0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fork") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_mss") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_una") == 0) return base+3;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_nxt") == 0) return base+4;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_max") == 0) return base+5;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_wnd") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_up") == 0) return base+7;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_wl1") == 0) return base+8;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_wl2") == 0) return base+9;
    if (fieldName[0] == 'i' && strcmp(fieldName, "iss") == 0) return base+10;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_nxt") == 0) return base+11;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_wnd") == 0) return base+12;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_up") == 0) return base+13;
    if (fieldName[0] == 'i' && strcmp(fieldName, "irs") == 0) return base+14;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_adv") == 0) return base+15;
    if (fieldName[0] == 's' && strcmp(fieldName, "syn_rexmit_count") == 0) return base+16;
    if (fieldName[0] == 's' && strcmp(fieldName, "syn_rexmit_timeout") == 0) return base+17;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fin_ack_rcvd") == 0) return base+18;
    if (fieldName[0] == 's' && strcmp(fieldName, "send_fin") == 0) return base+19;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_fin_seq") == 0) return base+20;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fin_rcvd") == 0) return base+21;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_fin_seq") == 0) return base+22;
    if (fieldName[0] == 's' && strcmp(fieldName, "sentBytes") == 0) return base+23;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nagle_enabled") == 0) return base+24;
    if (fieldName[0] == 'd' && strcmp(fieldName, "delayed_acks_enabled") == 0) return base+25;
    if (fieldName[0] == 'l' && strcmp(fieldName, "limited_transmit_enabled") == 0) return base+26;
    if (fieldName[0] == 'i' && strcmp(fieldName, "increased_IW_enabled") == 0) return base+27;
    if (fieldName[0] == 'f' && strcmp(fieldName, "full_sized_segment_counter") == 0) return base+28;
    if (fieldName[0] == 'a' && strcmp(fieldName, "ack_now") == 0) return base+29;
    if (fieldName[0] == 'a' && strcmp(fieldName, "afterRto") == 0) return base+30;
    if (fieldName[0] == 'w' && strcmp(fieldName, "ws_support") == 0) return base+31;
    if (fieldName[0] == 'w' && strcmp(fieldName, "ws_enabled") == 0) return base+32;
    if (fieldName[0] == 'w' && strcmp(fieldName, "ws_manual_scale") == 0) return base+33;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_ws") == 0) return base+34;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_ws") == 0) return base+35;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_wnd_scale") == 0) return base+36;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_wnd_scale") == 0) return base+37;
    if (fieldName[0] == 't' && strcmp(fieldName, "ts_support") == 0) return base+38;
    if (fieldName[0] == 't' && strcmp(fieldName, "ts_enabled") == 0) return base+39;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_initial_ts") == 0) return base+40;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_initial_ts") == 0) return base+41;
    if (fieldName[0] == 't' && strcmp(fieldName, "ts_recent") == 0) return base+42;
    if (fieldName[0] == 'l' && strcmp(fieldName, "last_ack_sent") == 0) return base+43;
    if (fieldName[0] == 't' && strcmp(fieldName, "time_last_data_sent") == 0) return base+44;
    if (fieldName[0] == 's' && strcmp(fieldName, "sack_support") == 0) return base+45;
    if (fieldName[0] == 's' && strcmp(fieldName, "sack_enabled") == 0) return base+46;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_sack_perm") == 0) return base+47;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_sack_perm") == 0) return base+48;
    if (fieldName[0] == 's' && strcmp(fieldName, "start_seqno") == 0) return base+49;
    if (fieldName[0] == 'e' && strcmp(fieldName, "end_seqno") == 0) return base+50;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_sack") == 0) return base+51;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_dsack") == 0) return base+52;
    if (fieldName[0] == 'h' && strcmp(fieldName, "highRxt") == 0) return base+53;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pipe") == 0) return base+54;
    if (fieldName[0] == 'r' && strcmp(fieldName, "recoveryPoint") == 0) return base+55;
    if (fieldName[0] == 's' && strcmp(fieldName, "sackedBytes") == 0) return base+56;
    if (fieldName[0] == 's' && strcmp(fieldName, "sackedBytes_old") == 0) return base+57;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lossRecovery") == 0) return base+58;
    if (fieldName[0] == 's' && strcmp(fieldName, "sendQueueLimit") == 0) return base+59;
    if (fieldName[0] == 'q' && strcmp(fieldName, "queueUpdate") == 0) return base+60;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dupacks") == 0) return base+61;
    if (fieldName[0] == 's' && strcmp(fieldName, "snd_sacks") == 0) return base+62;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_sacks") == 0) return base+63;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_oooseg") == 0) return base+64;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rcv_naseg") == 0) return base+65;
    if (fieldName[0] == 'm' && strcmp(fieldName, "maxRcvBuffer") == 0) return base+66;
    if (fieldName[0] == 'u' && strcmp(fieldName, "usedRcvBuffer") == 0) return base+67;
    if (fieldName[0] == 'f' && strcmp(fieldName, "freeRcvBuffer") == 0) return base+68;
    if (fieldName[0] == 't' && strcmp(fieldName, "tcpRcvQueueDrops") == 0) return base+69;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpStateVariablesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_active
        "bool",    // FIELD_fork
        "uint32_t",    // FIELD_snd_mss
        "uint32_t",    // FIELD_snd_una
        "uint32_t",    // FIELD_snd_nxt
        "uint32_t",    // FIELD_snd_max
        "uint32_t",    // FIELD_snd_wnd
        "uint32_t",    // FIELD_snd_up
        "uint32_t",    // FIELD_snd_wl1
        "uint32_t",    // FIELD_snd_wl2
        "uint32_t",    // FIELD_iss
        "uint32_t",    // FIELD_rcv_nxt
        "uint32_t",    // FIELD_rcv_wnd
        "uint32_t",    // FIELD_rcv_up
        "uint32_t",    // FIELD_irs
        "uint32_t",    // FIELD_rcv_adv
        "int",    // FIELD_syn_rexmit_count
        "omnetpp::simtime_t",    // FIELD_syn_rexmit_timeout
        "bool",    // FIELD_fin_ack_rcvd
        "bool",    // FIELD_send_fin
        "uint32_t",    // FIELD_snd_fin_seq
        "bool",    // FIELD_fin_rcvd
        "uint32_t",    // FIELD_rcv_fin_seq
        "uint32_t",    // FIELD_sentBytes
        "bool",    // FIELD_nagle_enabled
        "bool",    // FIELD_delayed_acks_enabled
        "bool",    // FIELD_limited_transmit_enabled
        "bool",    // FIELD_increased_IW_enabled
        "uint32_t",    // FIELD_full_sized_segment_counter
        "bool",    // FIELD_ack_now
        "bool",    // FIELD_afterRto
        "bool",    // FIELD_ws_support
        "bool",    // FIELD_ws_enabled
        "int",    // FIELD_ws_manual_scale
        "bool",    // FIELD_snd_ws
        "bool",    // FIELD_rcv_ws
        "unsigned int",    // FIELD_rcv_wnd_scale
        "unsigned int",    // FIELD_snd_wnd_scale
        "bool",    // FIELD_ts_support
        "bool",    // FIELD_ts_enabled
        "bool",    // FIELD_snd_initial_ts
        "bool",    // FIELD_rcv_initial_ts
        "uint32_t",    // FIELD_ts_recent
        "uint32_t",    // FIELD_last_ack_sent
        "omnetpp::simtime_t",    // FIELD_time_last_data_sent
        "bool",    // FIELD_sack_support
        "bool",    // FIELD_sack_enabled
        "bool",    // FIELD_snd_sack_perm
        "bool",    // FIELD_rcv_sack_perm
        "uint32_t",    // FIELD_start_seqno
        "uint32_t",    // FIELD_end_seqno
        "bool",    // FIELD_snd_sack
        "bool",    // FIELD_snd_dsack
        "uint32_t",    // FIELD_highRxt
        "uint32_t",    // FIELD_pipe
        "uint32_t",    // FIELD_recoveryPoint
        "uint32_t",    // FIELD_sackedBytes
        "uint32_t",    // FIELD_sackedBytes_old
        "bool",    // FIELD_lossRecovery
        "uint32_t",    // FIELD_sendQueueLimit
        "bool",    // FIELD_queueUpdate
        "uint32_t",    // FIELD_dupacks
        "uint32_t",    // FIELD_snd_sacks
        "uint32_t",    // FIELD_rcv_sacks
        "uint32_t",    // FIELD_rcv_oooseg
        "uint32_t",    // FIELD_rcv_naseg
        "uint32_t",    // FIELD_maxRcvBuffer
        "uint32_t",    // FIELD_usedRcvBuffer
        "uint32_t",    // FIELD_freeRcvBuffer
        "uint32_t",    // FIELD_tcpRcvQueueDrops
    };
    return (field >= 0 && field < 70) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpStateVariablesDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpStateVariablesDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpStateVariablesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpStateVariables *pp = (TcpStateVariables *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpStateVariablesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpStateVariables *pp = (TcpStateVariables *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpStateVariablesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpStateVariables *pp = (TcpStateVariables *)object; (void)pp;
    switch (field) {
        case FIELD_active: return bool2string(pp->active);
        case FIELD_fork: return bool2string(pp->fork);
        case FIELD_snd_mss: return ulong2string(pp->snd_mss);
        case FIELD_snd_una: return ulong2string(pp->snd_una);
        case FIELD_snd_nxt: return ulong2string(pp->snd_nxt);
        case FIELD_snd_max: return ulong2string(pp->snd_max);
        case FIELD_snd_wnd: return ulong2string(pp->snd_wnd);
        case FIELD_snd_up: return ulong2string(pp->snd_up);
        case FIELD_snd_wl1: return ulong2string(pp->snd_wl1);
        case FIELD_snd_wl2: return ulong2string(pp->snd_wl2);
        case FIELD_iss: return ulong2string(pp->iss);
        case FIELD_rcv_nxt: return ulong2string(pp->rcv_nxt);
        case FIELD_rcv_wnd: return ulong2string(pp->rcv_wnd);
        case FIELD_rcv_up: return ulong2string(pp->rcv_up);
        case FIELD_irs: return ulong2string(pp->irs);
        case FIELD_rcv_adv: return ulong2string(pp->rcv_adv);
        case FIELD_syn_rexmit_count: return long2string(pp->syn_rexmit_count);
        case FIELD_syn_rexmit_timeout: return simtime2string(pp->syn_rexmit_timeout);
        case FIELD_fin_ack_rcvd: return bool2string(pp->fin_ack_rcvd);
        case FIELD_send_fin: return bool2string(pp->send_fin);
        case FIELD_snd_fin_seq: return ulong2string(pp->snd_fin_seq);
        case FIELD_fin_rcvd: return bool2string(pp->fin_rcvd);
        case FIELD_rcv_fin_seq: return ulong2string(pp->rcv_fin_seq);
        case FIELD_sentBytes: return ulong2string(pp->sentBytes);
        case FIELD_nagle_enabled: return bool2string(pp->nagle_enabled);
        case FIELD_delayed_acks_enabled: return bool2string(pp->delayed_acks_enabled);
        case FIELD_limited_transmit_enabled: return bool2string(pp->limited_transmit_enabled);
        case FIELD_increased_IW_enabled: return bool2string(pp->increased_IW_enabled);
        case FIELD_full_sized_segment_counter: return ulong2string(pp->full_sized_segment_counter);
        case FIELD_ack_now: return bool2string(pp->ack_now);
        case FIELD_afterRto: return bool2string(pp->afterRto);
        case FIELD_ws_support: return bool2string(pp->ws_support);
        case FIELD_ws_enabled: return bool2string(pp->ws_enabled);
        case FIELD_ws_manual_scale: return long2string(pp->ws_manual_scale);
        case FIELD_snd_ws: return bool2string(pp->snd_ws);
        case FIELD_rcv_ws: return bool2string(pp->rcv_ws);
        case FIELD_rcv_wnd_scale: return ulong2string(pp->rcv_wnd_scale);
        case FIELD_snd_wnd_scale: return ulong2string(pp->snd_wnd_scale);
        case FIELD_ts_support: return bool2string(pp->ts_support);
        case FIELD_ts_enabled: return bool2string(pp->ts_enabled);
        case FIELD_snd_initial_ts: return bool2string(pp->snd_initial_ts);
        case FIELD_rcv_initial_ts: return bool2string(pp->rcv_initial_ts);
        case FIELD_ts_recent: return ulong2string(pp->ts_recent);
        case FIELD_last_ack_sent: return ulong2string(pp->last_ack_sent);
        case FIELD_time_last_data_sent: return simtime2string(pp->time_last_data_sent);
        case FIELD_sack_support: return bool2string(pp->sack_support);
        case FIELD_sack_enabled: return bool2string(pp->sack_enabled);
        case FIELD_snd_sack_perm: return bool2string(pp->snd_sack_perm);
        case FIELD_rcv_sack_perm: return bool2string(pp->rcv_sack_perm);
        case FIELD_start_seqno: return ulong2string(pp->start_seqno);
        case FIELD_end_seqno: return ulong2string(pp->end_seqno);
        case FIELD_snd_sack: return bool2string(pp->snd_sack);
        case FIELD_snd_dsack: return bool2string(pp->snd_dsack);
        case FIELD_highRxt: return ulong2string(pp->highRxt);
        case FIELD_pipe: return ulong2string(pp->pipe);
        case FIELD_recoveryPoint: return ulong2string(pp->recoveryPoint);
        case FIELD_sackedBytes: return ulong2string(pp->sackedBytes);
        case FIELD_sackedBytes_old: return ulong2string(pp->sackedBytes_old);
        case FIELD_lossRecovery: return bool2string(pp->lossRecovery);
        case FIELD_sendQueueLimit: return ulong2string(pp->sendQueueLimit);
        case FIELD_queueUpdate: return bool2string(pp->queueUpdate);
        case FIELD_dupacks: return ulong2string(pp->dupacks);
        case FIELD_snd_sacks: return ulong2string(pp->snd_sacks);
        case FIELD_rcv_sacks: return ulong2string(pp->rcv_sacks);
        case FIELD_rcv_oooseg: return ulong2string(pp->rcv_oooseg);
        case FIELD_rcv_naseg: return ulong2string(pp->rcv_naseg);
        case FIELD_maxRcvBuffer: return ulong2string(pp->maxRcvBuffer);
        case FIELD_usedRcvBuffer: return ulong2string(pp->usedRcvBuffer);
        case FIELD_freeRcvBuffer: return ulong2string(pp->freeRcvBuffer);
        case FIELD_tcpRcvQueueDrops: return ulong2string(pp->tcpRcvQueueDrops);
        default: return "";
    }
}

bool TcpStateVariablesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpStateVariables *pp = (TcpStateVariables *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TcpStateVariablesDescriptor::getFieldStructName(int field) const
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

void *TcpStateVariablesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpStateVariables *pp = (TcpStateVariables *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class TcpSendQueueDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_dataBuffer,
    };
  public:
    TcpSendQueueDescriptor();
    virtual ~TcpSendQueueDescriptor();

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

Register_ClassDescriptor(TcpSendQueueDescriptor)

TcpSendQueueDescriptor::TcpSendQueueDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::tcp::TcpSendQueue)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

TcpSendQueueDescriptor::~TcpSendQueueDescriptor()
{
    delete[] propertynames;
}

bool TcpSendQueueDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpSendQueue *>(obj)!=nullptr;
}

const char **TcpSendQueueDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpSendQueueDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpSendQueueDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int TcpSendQueueDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_dataBuffer
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *TcpSendQueueDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "dataBuffer",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int TcpSendQueueDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dataBuffer") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpSendQueueDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ChunkQueue",    // FIELD_dataBuffer
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpSendQueueDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpSendQueueDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpSendQueueDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpSendQueue *pp = (TcpSendQueue *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpSendQueueDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpSendQueue *pp = (TcpSendQueue *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpSendQueueDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpSendQueue *pp = (TcpSendQueue *)object; (void)pp;
    switch (field) {
        case FIELD_dataBuffer: {std::stringstream out; out << pp->getDataBuffer(); return out.str();}
        default: return "";
    }
}

bool TcpSendQueueDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpSendQueue *pp = (TcpSendQueue *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TcpSendQueueDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_dataBuffer: return omnetpp::opp_typename(typeid(ChunkQueue));
        default: return nullptr;
    };
}

void *TcpSendQueueDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpSendQueue *pp = (TcpSendQueue *)object; (void)pp;
    switch (field) {
        case FIELD_dataBuffer: return toVoidPtr(&pp->getDataBuffer()); break;
        default: return nullptr;
    }
}

class TcpReceiveQueueDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_reorderBuffer,
    };
  public:
    TcpReceiveQueueDescriptor();
    virtual ~TcpReceiveQueueDescriptor();

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

Register_ClassDescriptor(TcpReceiveQueueDescriptor)

TcpReceiveQueueDescriptor::TcpReceiveQueueDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::tcp::TcpReceiveQueue)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

TcpReceiveQueueDescriptor::~TcpReceiveQueueDescriptor()
{
    delete[] propertynames;
}

bool TcpReceiveQueueDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpReceiveQueue *>(obj)!=nullptr;
}

const char **TcpReceiveQueueDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpReceiveQueueDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpReceiveQueueDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int TcpReceiveQueueDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_reorderBuffer
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *TcpReceiveQueueDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reorderBuffer",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int TcpReceiveQueueDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reorderBuffer") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpReceiveQueueDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ReorderBuffer",    // FIELD_reorderBuffer
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpReceiveQueueDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpReceiveQueueDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpReceiveQueueDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpReceiveQueue *pp = (TcpReceiveQueue *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpReceiveQueueDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpReceiveQueue *pp = (TcpReceiveQueue *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpReceiveQueueDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpReceiveQueue *pp = (TcpReceiveQueue *)object; (void)pp;
    switch (field) {
        case FIELD_reorderBuffer: {std::stringstream out; out << pp->getReorderBuffer(); return out.str();}
        default: return "";
    }
}

bool TcpReceiveQueueDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpReceiveQueue *pp = (TcpReceiveQueue *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TcpReceiveQueueDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_reorderBuffer: return omnetpp::opp_typename(typeid(ReorderBuffer));
        default: return nullptr;
    };
}

void *TcpReceiveQueueDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpReceiveQueue *pp = (TcpReceiveQueue *)object; (void)pp;
    switch (field) {
        case FIELD_reorderBuffer: return toVoidPtr(&pp->getReorderBuffer()); break;
        default: return nullptr;
    }
}

class TcpConnectionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_socketId,
        FIELD_listeningSocketId,
        FIELD_localAddr,
        FIELD_remoteAddr,
        FIELD_localPort,
        FIELD_remotePort,
        FIELD_state,
        FIELD_sendQueue,
        FIELD_receiveQueue,
        FIELD_rexmitQueue,
        FIELD_tcpAlgorithm,
        FIELD_fsmState,
    };
  public:
    TcpConnectionDescriptor();
    virtual ~TcpConnectionDescriptor();

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

Register_ClassDescriptor(TcpConnectionDescriptor)

TcpConnectionDescriptor::TcpConnectionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::tcp::TcpConnection)), "omnetpp::cObject")
{
    propertynames = nullptr;
}

TcpConnectionDescriptor::~TcpConnectionDescriptor()
{
    delete[] propertynames;
}

bool TcpConnectionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpConnection *>(obj)!=nullptr;
}

const char **TcpConnectionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass", "descriptor",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpConnectionDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname, "existingClass")) return "";
    if (!strcmp(propertyname, "descriptor")) return "readonly";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpConnectionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int TcpConnectionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_socketId
        0,    // FIELD_listeningSocketId
        0,    // FIELD_localAddr
        0,    // FIELD_remoteAddr
        0,    // FIELD_localPort
        0,    // FIELD_remotePort
        FD_ISCOMPOUND | FD_ISPOINTER,    // FIELD_state
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_sendQueue
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_receiveQueue
        FD_ISCOMPOUND | FD_ISPOINTER,    // FIELD_rexmitQueue
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_tcpAlgorithm
        0,    // FIELD_fsmState
    };
    return (field >= 0 && field < 12) ? fieldTypeFlags[field] : 0;
}

const char *TcpConnectionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "socketId",
        "listeningSocketId",
        "localAddr",
        "remoteAddr",
        "localPort",
        "remotePort",
        "state",
        "sendQueue",
        "receiveQueue",
        "rexmitQueue",
        "tcpAlgorithm",
        "fsmState",
    };
    return (field >= 0 && field < 12) ? fieldNames[field] : nullptr;
}

int TcpConnectionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "socketId") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "listeningSocketId") == 0) return base+1;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localAddr") == 0) return base+2;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remoteAddr") == 0) return base+3;
    if (fieldName[0] == 'l' && strcmp(fieldName, "localPort") == 0) return base+4;
    if (fieldName[0] == 'r' && strcmp(fieldName, "remotePort") == 0) return base+5;
    if (fieldName[0] == 's' && strcmp(fieldName, "state") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "sendQueue") == 0) return base+7;
    if (fieldName[0] == 'r' && strcmp(fieldName, "receiveQueue") == 0) return base+8;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rexmitQueue") == 0) return base+9;
    if (fieldName[0] == 't' && strcmp(fieldName, "tcpAlgorithm") == 0) return base+10;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fsmState") == 0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpConnectionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_socketId
        "int",    // FIELD_listeningSocketId
        "inet::L3Address",    // FIELD_localAddr
        "inet::L3Address",    // FIELD_remoteAddr
        "int",    // FIELD_localPort
        "int",    // FIELD_remotePort
        "inet::tcp::TcpStateVariables",    // FIELD_state
        "inet::tcp::TcpSendQueue",    // FIELD_sendQueue
        "inet::tcp::TcpReceiveQueue",    // FIELD_receiveQueue
        "inet::tcp::TcpSackRexmitQueue",    // FIELD_rexmitQueue
        "inet::tcp::TcpAlgorithm",    // FIELD_tcpAlgorithm
        "int",    // FIELD_fsmState
    };
    return (field >= 0 && field < 12) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpConnectionDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpConnectionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpConnectionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpConnection *pp = (TcpConnection *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpConnectionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpConnection *pp = (TcpConnection *)object; (void)pp;
    switch (field) {
        case FIELD_state: { const TcpStateVariables * value = pp->getState(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_sendQueue: { const TcpSendQueue * value = pp->getSendQueue(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_receiveQueue: { const TcpReceiveQueue * value = pp->getReceiveQueue(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_rexmitQueue: { const TcpSackRexmitQueue * value = pp->getRexmitQueue(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_tcpAlgorithm: { const TcpAlgorithm * value = pp->getTcpAlgorithm(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string TcpConnectionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpConnection *pp = (TcpConnection *)object; (void)pp;
    switch (field) {
        case FIELD_socketId: return long2string(pp->getSocketId());
        case FIELD_listeningSocketId: return long2string(pp->getListeningSocketId());
        case FIELD_localAddr: return pp->getLocalAddr().str();
        case FIELD_remoteAddr: return pp->getRemoteAddr().str();
        case FIELD_localPort: return long2string(pp->getLocalPort());
        case FIELD_remotePort: return long2string(pp->getRemotePort());
        case FIELD_state: {std::stringstream out; out << pp->getState(); return out.str();}
        case FIELD_sendQueue: {std::stringstream out; out << pp->getSendQueue(); return out.str();}
        case FIELD_receiveQueue: {std::stringstream out; out << pp->getReceiveQueue(); return out.str();}
        case FIELD_rexmitQueue: {std::stringstream out; out << pp->getRexmitQueue(); return out.str();}
        case FIELD_tcpAlgorithm: {std::stringstream out; out << pp->getTcpAlgorithm(); return out.str();}
        case FIELD_fsmState: return long2string(pp->getFsmState());
        default: return "";
    }
}

bool TcpConnectionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpConnection *pp = (TcpConnection *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TcpConnectionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_state: return omnetpp::opp_typename(typeid(TcpStateVariables));
        case FIELD_sendQueue: return omnetpp::opp_typename(typeid(TcpSendQueue));
        case FIELD_receiveQueue: return omnetpp::opp_typename(typeid(TcpReceiveQueue));
        case FIELD_rexmitQueue: return omnetpp::opp_typename(typeid(TcpSackRexmitQueue));
        case FIELD_tcpAlgorithm: return omnetpp::opp_typename(typeid(TcpAlgorithm));
        default: return nullptr;
    };
}

void *TcpConnectionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpConnection *pp = (TcpConnection *)object; (void)pp;
    switch (field) {
        case FIELD_localAddr: return toVoidPtr(&pp->getLocalAddr()); break;
        case FIELD_remoteAddr: return toVoidPtr(&pp->getRemoteAddr()); break;
        case FIELD_state: return toVoidPtr(pp->getState()); break;
        case FIELD_sendQueue: return toVoidPtr(pp->getSendQueue()); break;
        case FIELD_receiveQueue: return toVoidPtr(pp->getReceiveQueue()); break;
        case FIELD_rexmitQueue: return toVoidPtr(pp->getRexmitQueue()); break;
        case FIELD_tcpAlgorithm: return toVoidPtr(pp->getTcpAlgorithm()); break;
        default: return nullptr;
    }
}

} // namespace tcp
} // namespace inet

