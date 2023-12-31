//
// Generated file, do not edit! Created by nedtool 5.6 from inet/transportlayer/rtp/profiles/avprofile/RtpMpegPacket.msg.
//

#ifndef __INET__RTP_RTPMPEGPACKET_M_H
#define __INET__RTP_RTPMPEGPACKET_M_H

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
namespace rtp {

class RtpMpegHeader;
} // namespace rtp
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk


namespace inet {
namespace rtp {

/**
 * Class generated from <tt>inet/transportlayer/rtp/profiles/avprofile/RtpMpegPacket.msg:39</tt> by nedtool.
 * <pre>
 * class RtpMpegHeader extends FieldsChunk
 * {
 *     chunkLength = B(4);
 *     int headerLength = 4;
 *     int payloadLength; // size of the mpeg data
 *     int pictureType;   // picture type of the frame the data in this packet belongs to.
 * 
 *     // currenrtly unused fields:
 *     //int mzb;
 *     //int two;
 *     //int temporalReference;
 *     //int activeN;
 *     //int newPictureHeader;
 *     //int sequenceHeaderPresent;
 *     //int beginningOfSlice;
 *     //int endOfSlice;
 *     //int fbv;
 *     //int bfc;
 *     //int ffv;
 *     //int ffc;
 * }
 * </pre>
 */
class INET_API RtpMpegHeader : public ::inet::FieldsChunk
{
  protected:
    int headerLength = 4;
    int payloadLength = 0;
    int pictureType = 0;

  private:
    void copy(const RtpMpegHeader& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RtpMpegHeader&);

  public:
    RtpMpegHeader();
    RtpMpegHeader(const RtpMpegHeader& other);
    virtual ~RtpMpegHeader();
    RtpMpegHeader& operator=(const RtpMpegHeader& other);
    virtual RtpMpegHeader *dup() const override {return new RtpMpegHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getHeaderLength() const;
    virtual void setHeaderLength(int headerLength);
    virtual int getPayloadLength() const;
    virtual void setPayloadLength(int payloadLength);
    virtual int getPictureType() const;
    virtual void setPictureType(int pictureType);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RtpMpegHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RtpMpegHeader& obj) {obj.parsimUnpack(b);}

} // namespace rtp
} // namespace inet

#endif // ifndef __INET__RTP_RTPMPEGPACKET_M_H

