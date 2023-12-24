//
// Generated file, do not edit! Created by nedtool 5.6 from inet/physicallayer/ieee80211/packetlevel/Ieee80211ControlInfo.msg.
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
#include "Ieee80211ControlInfo_m.h"

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

Register_Class(Ieee80211ConfigureRadioCommand)

Ieee80211ConfigureRadioCommand::Ieee80211ConfigureRadioCommand() : ::inet::physicallayer::ConfigureRadioCommand()
{
}

Ieee80211ConfigureRadioCommand::Ieee80211ConfigureRadioCommand(const Ieee80211ConfigureRadioCommand& other) : ::inet::physicallayer::ConfigureRadioCommand(other)
{
    copy(other);
}

Ieee80211ConfigureRadioCommand::~Ieee80211ConfigureRadioCommand()
{
}

Ieee80211ConfigureRadioCommand& Ieee80211ConfigureRadioCommand::operator=(const Ieee80211ConfigureRadioCommand& other)
{
    if (this == &other) return *this;
    ::inet::physicallayer::ConfigureRadioCommand::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ConfigureRadioCommand::copy(const Ieee80211ConfigureRadioCommand& other)
{
    this->opMode = other.opMode;
    this->modeSet = other.modeSet;
    this->mode = other.mode;
    this->band = other.band;
    this->channel = other.channel;
    this->channelNumber = other.channelNumber;
}

void Ieee80211ConfigureRadioCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::physicallayer::ConfigureRadioCommand::parsimPack(b);
    doParsimPacking(b,this->opMode);
    doParsimPacking(b,this->modeSet);
    doParsimPacking(b,this->mode);
    doParsimPacking(b,this->band);
    doParsimPacking(b,this->channel);
    doParsimPacking(b,this->channelNumber);
}

void Ieee80211ConfigureRadioCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::physicallayer::ConfigureRadioCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->opMode);
    doParsimUnpacking(b,this->modeSet);
    doParsimUnpacking(b,this->mode);
    doParsimUnpacking(b,this->band);
    doParsimUnpacking(b,this->channel);
    doParsimUnpacking(b,this->channelNumber);
}

const char * Ieee80211ConfigureRadioCommand::getOpMode() const
{
    return this->opMode.c_str();
}

void Ieee80211ConfigureRadioCommand::setOpMode(const char * opMode)
{
    this->opMode = opMode;
}

const Ieee80211ModeSet * Ieee80211ConfigureRadioCommand::getModeSet() const
{
    return this->modeSet;
}

void Ieee80211ConfigureRadioCommand::setModeSet(const Ieee80211ModeSet * modeSet)
{
    this->modeSet = modeSet;
}

const IIeee80211Mode * Ieee80211ConfigureRadioCommand::getMode() const
{
    return this->mode;
}

void Ieee80211ConfigureRadioCommand::setMode(const IIeee80211Mode * mode)
{
    this->mode = mode;
}

const IIeee80211Band * Ieee80211ConfigureRadioCommand::getBand() const
{
    return this->band;
}

void Ieee80211ConfigureRadioCommand::setBand(IIeee80211Band * band)
{
    this->band = band;
}

const Ieee80211Channel * Ieee80211ConfigureRadioCommand::getChannel() const
{
    return this->channel;
}

void Ieee80211ConfigureRadioCommand::setChannel(Ieee80211Channel * channel)
{
    this->channel = channel;
}

int Ieee80211ConfigureRadioCommand::getChannelNumber() const
{
    return this->channelNumber;
}

void Ieee80211ConfigureRadioCommand::setChannelNumber(int channelNumber)
{
    this->channelNumber = channelNumber;
}

class Ieee80211ConfigureRadioCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_opMode,
        FIELD_modeSet,
        FIELD_mode,
        FIELD_band,
        FIELD_channel,
        FIELD_channelNumber,
    };
  public:
    Ieee80211ConfigureRadioCommandDescriptor();
    virtual ~Ieee80211ConfigureRadioCommandDescriptor();

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

Register_ClassDescriptor(Ieee80211ConfigureRadioCommandDescriptor)

Ieee80211ConfigureRadioCommandDescriptor::Ieee80211ConfigureRadioCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::physicallayer::Ieee80211ConfigureRadioCommand)), "inet::physicallayer::ConfigureRadioCommand")
{
    propertynames = nullptr;
}

Ieee80211ConfigureRadioCommandDescriptor::~Ieee80211ConfigureRadioCommandDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ConfigureRadioCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ConfigureRadioCommand *>(obj)!=nullptr;
}

const char **Ieee80211ConfigureRadioCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ConfigureRadioCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ConfigureRadioCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int Ieee80211ConfigureRadioCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_opMode
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_modeSet
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,    // FIELD_mode
        FD_ISCOMPOUND | FD_ISPOINTER,    // FIELD_band
        FD_ISCOMPOUND | FD_ISPOINTER,    // FIELD_channel
        FD_ISEDITABLE,    // FIELD_channelNumber
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211ConfigureRadioCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "opMode",
        "modeSet",
        "mode",
        "band",
        "channel",
        "channelNumber",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int Ieee80211ConfigureRadioCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "opMode") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "modeSet") == 0) return base+1;
    if (fieldName[0] == 'm' && strcmp(fieldName, "mode") == 0) return base+2;
    if (fieldName[0] == 'b' && strcmp(fieldName, "band") == 0) return base+3;
    if (fieldName[0] == 'c' && strcmp(fieldName, "channel") == 0) return base+4;
    if (fieldName[0] == 'c' && strcmp(fieldName, "channelNumber") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ConfigureRadioCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_opMode
        "inet::physicallayer::Ieee80211ModeSet",    // FIELD_modeSet
        "inet::physicallayer::IIeee80211Mode",    // FIELD_mode
        "inet::physicallayer::IIeee80211Band",    // FIELD_band
        "inet::physicallayer::Ieee80211Channel",    // FIELD_channel
        "int",    // FIELD_channelNumber
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ConfigureRadioCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ConfigureRadioCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ConfigureRadioCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ConfigureRadioCommand *pp = (Ieee80211ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ConfigureRadioCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ConfigureRadioCommand *pp = (Ieee80211ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case FIELD_modeSet: { const Ieee80211ModeSet * value = pp->getModeSet(); return omnetpp::opp_typename(typeid(*const_cast<Ieee80211ModeSet *>(value))); }
        case FIELD_mode: { const IIeee80211Mode * value = pp->getMode(); return omnetpp::opp_typename(typeid(*const_cast<IIeee80211Mode *>(value))); }
        case FIELD_band: { const IIeee80211Band * value = pp->getBand(); return omnetpp::opp_typename(typeid(*value)); }
        case FIELD_channel: { const Ieee80211Channel * value = pp->getChannel(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string Ieee80211ConfigureRadioCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ConfigureRadioCommand *pp = (Ieee80211ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case FIELD_opMode: return oppstring2string(pp->getOpMode());
        case FIELD_modeSet: {std::stringstream out; out << pp->getModeSet(); return out.str();}
        case FIELD_mode: {std::stringstream out; out << pp->getMode(); return out.str();}
        case FIELD_band: {std::stringstream out; out << pp->getBand(); return out.str();}
        case FIELD_channel: {std::stringstream out; out << pp->getChannel(); return out.str();}
        case FIELD_channelNumber: return long2string(pp->getChannelNumber());
        default: return "";
    }
}

bool Ieee80211ConfigureRadioCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ConfigureRadioCommand *pp = (Ieee80211ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case FIELD_opMode: pp->setOpMode((value)); return true;
        case FIELD_channelNumber: pp->setChannelNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211ConfigureRadioCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_modeSet: return omnetpp::opp_typename(typeid(Ieee80211ModeSet));
        case FIELD_mode: return omnetpp::opp_typename(typeid(IIeee80211Mode));
        case FIELD_band: return omnetpp::opp_typename(typeid(IIeee80211Band));
        case FIELD_channel: return omnetpp::opp_typename(typeid(Ieee80211Channel));
        default: return nullptr;
    };
}

void *Ieee80211ConfigureRadioCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ConfigureRadioCommand *pp = (Ieee80211ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case FIELD_modeSet: return toVoidPtr(pp->getModeSet()); break;
        case FIELD_mode: return toVoidPtr(pp->getMode()); break;
        case FIELD_band: return toVoidPtr(pp->getBand()); break;
        case FIELD_channel: return toVoidPtr(pp->getChannel()); break;
        default: return nullptr;
    }
}

} // namespace physicallayer
} // namespace inet

