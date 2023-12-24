//
// Generated file, do not edit! Created by nedtool 5.6 from inet/linklayer/lmac/LMacHeader.msg.
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
#include "LMacHeader_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::LMacType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::LMacType"));
    e->insert(LMAC_CONTROL, "LMAC_CONTROL");
    e->insert(LMAC_TIMEOUT, "LMAC_TIMEOUT");
    e->insert(LMAC_WAKEUP, "LMAC_WAKEUP");
    e->insert(LMAC_SEND_DATA, "LMAC_SEND_DATA");
    e->insert(LMAC_SETUP_PHASE_END, "LMAC_SETUP_PHASE_END");
    e->insert(LMAC_CHECK_CHANNEL, "LMAC_CHECK_CHANNEL");
    e->insert(LMAC_SOMEBODY, "LMAC_SOMEBODY");
    e->insert(LMAC_DATA, "LMAC_DATA");
    e->insert(LMAC_START_LMAC, "LMAC_START_LMAC");
    e->insert(LMAC_SEND_CONTROL, "LMAC_SEND_CONTROL");
)

Register_Class(LMacHeader)

LMacHeader::LMacHeader() : ::inet::MacHeaderBase()
{
}

LMacHeader::LMacHeader(const LMacHeader& other) : ::inet::MacHeaderBase(other)
{
    copy(other);
}

LMacHeader::~LMacHeader()
{
    delete [] this->occupiedSlots;
}

LMacHeader& LMacHeader::operator=(const LMacHeader& other)
{
    if (this == &other) return *this;
    ::inet::MacHeaderBase::operator=(other);
    copy(other);
    return *this;
}

void LMacHeader::copy(const LMacHeader& other)
{
    this->type = other.type;
    this->mySlot = other.mySlot;
    delete [] this->occupiedSlots;
    this->occupiedSlots = (other.occupiedSlots_arraysize==0) ? nullptr : new MacAddress[other.occupiedSlots_arraysize];
    occupiedSlots_arraysize = other.occupiedSlots_arraysize;
    for (size_t i = 0; i < occupiedSlots_arraysize; i++) {
        this->occupiedSlots[i] = other.occupiedSlots[i];
    }
}

void LMacHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::MacHeaderBase::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->mySlot);
    b->pack(occupiedSlots_arraysize);
    doParsimArrayPacking(b,this->occupiedSlots,occupiedSlots_arraysize);
}

void LMacHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::MacHeaderBase::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->mySlot);
    delete [] this->occupiedSlots;
    b->unpack(occupiedSlots_arraysize);
    if (occupiedSlots_arraysize == 0) {
        this->occupiedSlots = nullptr;
    } else {
        this->occupiedSlots = new MacAddress[occupiedSlots_arraysize];
        doParsimArrayUnpacking(b,this->occupiedSlots,occupiedSlots_arraysize);
    }
}

inet::LMacType LMacHeader::getType() const
{
    return this->type;
}

void LMacHeader::setType(inet::LMacType type)
{
    handleChange();
    this->type = type;
}

int LMacHeader::getMySlot() const
{
    return this->mySlot;
}

void LMacHeader::setMySlot(int mySlot)
{
    handleChange();
    this->mySlot = mySlot;
}

size_t LMacHeader::getOccupiedSlotsArraySize() const
{
    return occupiedSlots_arraysize;
}

const MacAddress& LMacHeader::getOccupiedSlots(size_t k) const
{
    if (k >= occupiedSlots_arraysize) throw omnetpp::cRuntimeError("Array of size occupiedSlots_arraysize indexed by %lu", (unsigned long)k);
    return this->occupiedSlots[k];
}

void LMacHeader::setOccupiedSlotsArraySize(size_t newSize)
{
    handleChange();
    MacAddress *occupiedSlots2 = (newSize==0) ? nullptr : new MacAddress[newSize];
    size_t minSize = occupiedSlots_arraysize < newSize ? occupiedSlots_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        occupiedSlots2[i] = this->occupiedSlots[i];
    delete [] this->occupiedSlots;
    this->occupiedSlots = occupiedSlots2;
    occupiedSlots_arraysize = newSize;
}

void LMacHeader::setOccupiedSlots(size_t k, const MacAddress& occupiedSlots)
{
    if (k >= occupiedSlots_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->occupiedSlots[k] = occupiedSlots;
}

void LMacHeader::insertOccupiedSlots(size_t k, const MacAddress& occupiedSlots)
{
    handleChange();
    if (k > occupiedSlots_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = occupiedSlots_arraysize + 1;
    MacAddress *occupiedSlots2 = new MacAddress[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        occupiedSlots2[i] = this->occupiedSlots[i];
    occupiedSlots2[k] = occupiedSlots;
    for (i = k + 1; i < newSize; i++)
        occupiedSlots2[i] = this->occupiedSlots[i-1];
    delete [] this->occupiedSlots;
    this->occupiedSlots = occupiedSlots2;
    occupiedSlots_arraysize = newSize;
}

void LMacHeader::insertOccupiedSlots(const MacAddress& occupiedSlots)
{
    insertOccupiedSlots(occupiedSlots_arraysize, occupiedSlots);
}

void LMacHeader::eraseOccupiedSlots(size_t k)
{
    if (k >= occupiedSlots_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = occupiedSlots_arraysize - 1;
    MacAddress *occupiedSlots2 = (newSize == 0) ? nullptr : new MacAddress[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        occupiedSlots2[i] = this->occupiedSlots[i];
    for (i = k; i < newSize; i++)
        occupiedSlots2[i] = this->occupiedSlots[i+1];
    delete [] this->occupiedSlots;
    this->occupiedSlots = occupiedSlots2;
    occupiedSlots_arraysize = newSize;
}

class LMacHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_mySlot,
        FIELD_occupiedSlots,
    };
  public:
    LMacHeaderDescriptor();
    virtual ~LMacHeaderDescriptor();

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

Register_ClassDescriptor(LMacHeaderDescriptor)

LMacHeaderDescriptor::LMacHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::LMacHeader)), "inet::MacHeaderBase")
{
    propertynames = nullptr;
}

LMacHeaderDescriptor::~LMacHeaderDescriptor()
{
    delete[] propertynames;
}

bool LMacHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LMacHeader *>(obj)!=nullptr;
}

const char **LMacHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LMacHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LMacHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int LMacHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_mySlot
        FD_ISARRAY,    // FIELD_occupiedSlots
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *LMacHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "mySlot",
        "occupiedSlots",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int LMacHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "mySlot") == 0) return base+1;
    if (fieldName[0] == 'o' && strcmp(fieldName, "occupiedSlots") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LMacHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::LMacType",    // FIELD_type
        "int",    // FIELD_mySlot
        "inet::MacAddress",    // FIELD_occupiedSlots
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **LMacHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *LMacHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyname, "enum")) return "inet::LMacType";
            return nullptr;
        default: return nullptr;
    }
}

int LMacHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LMacHeader *pp = (LMacHeader *)object; (void)pp;
    switch (field) {
        case FIELD_occupiedSlots: return pp->getOccupiedSlotsArraySize();
        default: return 0;
    }
}

const char *LMacHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LMacHeader *pp = (LMacHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LMacHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LMacHeader *pp = (LMacHeader *)object; (void)pp;
    switch (field) {
        case FIELD_type: return enum2string(pp->getType(), "inet::LMacType");
        case FIELD_mySlot: return long2string(pp->getMySlot());
        case FIELD_occupiedSlots: return pp->getOccupiedSlots(i).str();
        default: return "";
    }
}

bool LMacHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LMacHeader *pp = (LMacHeader *)object; (void)pp;
    switch (field) {
        case FIELD_mySlot: pp->setMySlot(string2long(value)); return true;
        default: return false;
    }
}

const char *LMacHeaderDescriptor::getFieldStructName(int field) const
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

void *LMacHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LMacHeader *pp = (LMacHeader *)object; (void)pp;
    switch (field) {
        case FIELD_occupiedSlots: return toVoidPtr(&pp->getOccupiedSlots(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

