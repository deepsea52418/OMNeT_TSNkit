//
// Generated file, do not edit! Created by nedtool 5.6 from inet/linklayer/bmac/BMacHeader.msg.
//

#ifndef __INET_BMACHEADER_M_H
#define __INET_BMACHEADER_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {

class BMacHeader;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/linklayer/base/MacHeaderBase_m.h" // import inet.linklayer.base.MacHeaderBase


namespace inet {

/**
 * Enum generated from <tt>inet/linklayer/bmac/BMacHeader.msg:25</tt> by nedtool.
 * <pre>
 * // \@brief Types of messages (self messages and packets) the node can process
 * //TODO split to 2 enums: for packets / for self messages
 * enum BMacType
 * {
 *     // packet types
 *     BMAC_PREAMBLE = 191;
 *     BMAC_DATA = 192;
 *     BMAC_ACK = 193;
 *     // self message types
 *     BMAC_RESEND_DATA = 194;
 *     BMAC_ACK_TIMEOUT = 195;
 *     BMAC_START_BMAC = 196;
 *     BMAC_WAKE_UP = 197;
 *     BMAC_SEND_ACK = 198;
 *     BMAC_CCA_TIMEOUT = 199;
 *     BMAC_ACK_TX_OVER = 200;
 *     BMAC_SEND_PREAMBLE = 201;
 *     BMAC_STOP_PREAMBLES = 202;
 *     BMAC_DATA_TX_OVER = 203;
 *     BMAC_DATA_TIMEOUT = 204;
 * }
 * </pre>
 */
enum BMacType {
    BMAC_PREAMBLE = 191,
    BMAC_DATA = 192,
    BMAC_ACK = 193,
    BMAC_RESEND_DATA = 194,
    BMAC_ACK_TIMEOUT = 195,
    BMAC_START_BMAC = 196,
    BMAC_WAKE_UP = 197,
    BMAC_SEND_ACK = 198,
    BMAC_CCA_TIMEOUT = 199,
    BMAC_ACK_TX_OVER = 200,
    BMAC_SEND_PREAMBLE = 201,
    BMAC_STOP_PREAMBLES = 202,
    BMAC_DATA_TX_OVER = 203,
    BMAC_DATA_TIMEOUT = 204
};

/**
 * Class generated from <tt>inet/linklayer/bmac/BMacHeader.msg:46</tt> by nedtool.
 * <pre>
 * class BMacHeader extends MacHeaderBase
 * {
 *     BMacType type;
 * }
 * </pre>
 */
class INET_API BMacHeader : public ::inet::MacHeaderBase
{
  protected:
    inet::BMacType type = static_cast<inet::BMacType>(-1);

  private:
    void copy(const BMacHeader& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BMacHeader&);

  public:
    BMacHeader();
    BMacHeader(const BMacHeader& other);
    virtual ~BMacHeader();
    BMacHeader& operator=(const BMacHeader& other);
    virtual BMacHeader *dup() const override {return new BMacHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual inet::BMacType getType() const;
    virtual void setType(inet::BMacType type);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BMacHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BMacHeader& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_BMACHEADER_M_H

