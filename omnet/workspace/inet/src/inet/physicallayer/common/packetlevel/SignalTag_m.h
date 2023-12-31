//
// Generated file, do not edit! Created by nedtool 5.6 from inet/physicallayer/common/packetlevel/SignalTag.msg.
//

#ifndef __INET_SIGNALTAG_M_H
#define __INET_SIGNALTAG_M_H

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

class SignalTagBase;
class SignalPowerTagBase;
class SignalPowerReq;
class SignalPowerInd;
class SignalBandTagBase;
class SignalBandReq;
class SignalBandInd;
class SignalBitrateTagBase;
class SignalBitrateReq;
class SignalBitrateInd;
class SnirInd;
class ErrorRateInd;
class SignalTimeInd;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase

#include "inet/common/Units_m.h" // import inet.common.Units

// cplusplus {{
#include "inet/physicallayer/base/packetlevel/PhysicalLayerDefs.h"
// }}


namespace inet {

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // This is an abstract base class that should not be directly added as a tag.
 * //
 * class SignalTagBase extends TagBase
 * {
 * }
 * </pre>
 */
class INET_API SignalTagBase : public ::inet::TagBase
{
  protected:

  private:
    void copy(const SignalTagBase& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SignalTagBase&);

  public:
    SignalTagBase();
    SignalTagBase(const SignalTagBase& other);
    virtual ~SignalTagBase();
    SignalTagBase& operator=(const SignalTagBase& other);
    virtual SignalTagBase *dup() const override {return new SignalTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignalTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignalTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:26</tt> by nedtool.
 * <pre>
 * //
 * // This is an abstract base class that should not be directly added as a tag.
 * //
 * class SignalPowerTagBase extends SignalTagBase
 * {
 *     W power = W(NaN); // specifies signal power in Watts
 * }
 * </pre>
 */
class INET_API SignalPowerTagBase : public ::inet::SignalTagBase
{
  protected:
    W power = W(NaN);

  private:
    void copy(const SignalPowerTagBase& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SignalPowerTagBase&);

  public:
    SignalPowerTagBase();
    SignalPowerTagBase(const SignalPowerTagBase& other);
    virtual ~SignalPowerTagBase();
    SignalPowerTagBase& operator=(const SignalPowerTagBase& other);
    virtual SignalPowerTagBase *dup() const override {return new SignalPowerTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual W getPower() const;
    virtual void setPower(W power);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignalPowerTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignalPowerTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:35</tt> by nedtool.
 * <pre>
 * //
 * // This request determines the average analog signal power that should be used to transmit the packet.
 * // It may be present on a packet from the application to the phyisical layer.
 * //
 * class SignalPowerReq extends SignalPowerTagBase
 * {
 * }
 * </pre>
 */
class INET_API SignalPowerReq : public ::inet::SignalPowerTagBase
{
  protected:

  private:
    void copy(const SignalPowerReq& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SignalPowerReq&);

  public:
    SignalPowerReq();
    SignalPowerReq(const SignalPowerReq& other);
    virtual ~SignalPowerReq();
    SignalPowerReq& operator=(const SignalPowerReq& other);
    virtual SignalPowerReq *dup() const override {return new SignalPowerReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignalPowerReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignalPowerReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:43</tt> by nedtool.
 * <pre>
 * //
 * // This indication specifies the average analog signal power that was detected during receiving the packet.
 * // It may be present on a packet from the phyiscal layer to the application.
 * //
 * class SignalPowerInd extends SignalPowerTagBase
 * {
 * }
 * </pre>
 */
class INET_API SignalPowerInd : public ::inet::SignalPowerTagBase
{
  protected:

  private:
    void copy(const SignalPowerInd& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SignalPowerInd&);

  public:
    SignalPowerInd();
    SignalPowerInd(const SignalPowerInd& other);
    virtual ~SignalPowerInd();
    SignalPowerInd& operator=(const SignalPowerInd& other);
    virtual SignalPowerInd *dup() const override {return new SignalPowerInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignalPowerInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignalPowerInd& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:50</tt> by nedtool.
 * <pre>
 * //
 * // This is an abstract base class that should not be directly added as a tag.
 * //
 * class SignalBandTagBase extends SignalTagBase
 * {
 *     Hz carrierFrequency = Hz(NaN); // carrier frequency in the range (0, +infinity) or NaN if not set.
 *     Hz bandwidth = Hz(NaN);        // bandwidth in the rage (0, +infinity) or NaN if not set.
 * }
 * </pre>
 */
class INET_API SignalBandTagBase : public ::inet::SignalTagBase
{
  protected:
    Hz carrierFrequency = Hz(NaN);
    Hz bandwidth = Hz(NaN);

  private:
    void copy(const SignalBandTagBase& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SignalBandTagBase&);

  public:
    SignalBandTagBase();
    SignalBandTagBase(const SignalBandTagBase& other);
    virtual ~SignalBandTagBase();
    SignalBandTagBase& operator=(const SignalBandTagBase& other);
    virtual SignalBandTagBase *dup() const override {return new SignalBandTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual Hz getCarrierFrequency() const;
    virtual void setCarrierFrequency(Hz carrierFrequency);
    virtual Hz getBandwidth() const;
    virtual void setBandwidth(Hz bandwidth);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignalBandTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignalBandTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:60</tt> by nedtool.
 * <pre>
 * //
 * // This request determines the signal band that should be used to transmit the packet.
 * // It may be present on a packet from the application to the phyisical layer.
 * //
 * class SignalBandReq extends SignalBandTagBase
 * {
 * }
 * </pre>
 */
class INET_API SignalBandReq : public ::inet::SignalBandTagBase
{
  protected:

  private:
    void copy(const SignalBandReq& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SignalBandReq&);

  public:
    SignalBandReq();
    SignalBandReq(const SignalBandReq& other);
    virtual ~SignalBandReq();
    SignalBandReq& operator=(const SignalBandReq& other);
    virtual SignalBandReq *dup() const override {return new SignalBandReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignalBandReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignalBandReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:68</tt> by nedtool.
 * <pre>
 * //
 * // This indication specifies the signal band that was used to receive the packet.
 * // It may be present on a packet from the phyiscal layer to the application.
 * //
 * class SignalBandInd extends SignalBandTagBase
 * {
 * }
 * </pre>
 */
class INET_API SignalBandInd : public ::inet::SignalBandTagBase
{
  protected:

  private:
    void copy(const SignalBandInd& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SignalBandInd&);

  public:
    SignalBandInd();
    SignalBandInd(const SignalBandInd& other);
    virtual ~SignalBandInd();
    SignalBandInd& operator=(const SignalBandInd& other);
    virtual SignalBandInd *dup() const override {return new SignalBandInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignalBandInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignalBandInd& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:75</tt> by nedtool.
 * <pre>
 * //
 * // This is an abstract base class that should not be directly added as a tag.
 * //
 * class SignalBitrateTagBase extends SignalTagBase
 * {
 *     bps preambleBitrate = bps(NaN); // preamble bitrate in the range (0, +infinity) or NaN if not set.
 *     bps headerBitrate = bps(NaN);   // header bitrate in the range (0, +infinity) or NaN if not set.
 *     bps dataBitrate = bps(NaN);     // data bitrate in the range (0, +infinity) or NaN if not set.
 * }
 * </pre>
 */
class INET_API SignalBitrateTagBase : public ::inet::SignalTagBase
{
  protected:
    bps preambleBitrate = bps(NaN);
    bps headerBitrate = bps(NaN);
    bps dataBitrate = bps(NaN);

  private:
    void copy(const SignalBitrateTagBase& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SignalBitrateTagBase&);

  public:
    SignalBitrateTagBase();
    SignalBitrateTagBase(const SignalBitrateTagBase& other);
    virtual ~SignalBitrateTagBase();
    SignalBitrateTagBase& operator=(const SignalBitrateTagBase& other);
    virtual SignalBitrateTagBase *dup() const override {return new SignalBitrateTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bps getPreambleBitrate() const;
    virtual void setPreambleBitrate(bps preambleBitrate);
    virtual bps getHeaderBitrate() const;
    virtual void setHeaderBitrate(bps headerBitrate);
    virtual bps getDataBitrate() const;
    virtual void setDataBitrate(bps dataBitrate);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignalBitrateTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignalBitrateTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:86</tt> by nedtool.
 * <pre>
 * //
 * // This request determines the bitrates for various parts of the signal that should be used to transmit the packet.
 * // It may be present on a packet from the application to the phyisical layer.
 * //
 * class SignalBitrateReq extends SignalBitrateTagBase
 * {
 * }
 * </pre>
 */
class INET_API SignalBitrateReq : public ::inet::SignalBitrateTagBase
{
  protected:

  private:
    void copy(const SignalBitrateReq& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SignalBitrateReq&);

  public:
    SignalBitrateReq();
    SignalBitrateReq(const SignalBitrateReq& other);
    virtual ~SignalBitrateReq();
    SignalBitrateReq& operator=(const SignalBitrateReq& other);
    virtual SignalBitrateReq *dup() const override {return new SignalBitrateReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignalBitrateReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignalBitrateReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:94</tt> by nedtool.
 * <pre>
 * //
 * // This indication specifies the bitrates for various parts of the signal that was used to receive the packet.
 * // It may be present on a packet from the phyiscal layer to the application.
 * //
 * class SignalBitrateInd extends SignalBitrateTagBase
 * {
 * }
 * </pre>
 */
class INET_API SignalBitrateInd : public ::inet::SignalBitrateTagBase
{
  protected:

  private:
    void copy(const SignalBitrateInd& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SignalBitrateInd&);

  public:
    SignalBitrateInd();
    SignalBitrateInd(const SignalBitrateInd& other);
    virtual ~SignalBitrateInd();
    SignalBitrateInd& operator=(const SignalBitrateInd& other);
    virtual SignalBitrateInd *dup() const override {return new SignalBitrateInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignalBitrateInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignalBitrateInd& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:102</tt> by nedtool.
 * <pre>
 * //
 * // This indication specifies the signal to noise ratio that was detected during receiving the packet.
 * // It may be present on a packet from the phyiscal layer to the application.
 * //
 * class SnirInd extends SignalTagBase
 * {
 *     double minimumSnir = NaN; // minimum signal to noise plus interference ratio in the range (0, +infinity) or NaN if unknown. 
 *     double maximumSnir = NaN; // maximum signal to noise plus interference ratio in the range (0, +infinity) or NaN if unknown.
 *     double averageSnir = NaN; // average signal to noise plus interference ratio in the range (0, +infinity) or NaN if unknown.
 * }
 * </pre>
 */
class INET_API SnirInd : public ::inet::SignalTagBase
{
  protected:
    double minimumSnir = NaN;
    double maximumSnir = NaN;
    double averageSnir = NaN;

  private:
    void copy(const SnirInd& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SnirInd&);

  public:
    SnirInd();
    SnirInd(const SnirInd& other);
    virtual ~SnirInd();
    SnirInd& operator=(const SnirInd& other);
    virtual SnirInd *dup() const override {return new SnirInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual double getMinimumSnir() const;
    virtual void setMinimumSnir(double minimumSnir);
    virtual double getMaximumSnir() const;
    virtual void setMaximumSnir(double maximumSnir);
    virtual double getAverageSnir() const;
    virtual void setAverageSnir(double averageSnir);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SnirInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SnirInd& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:113</tt> by nedtool.
 * <pre>
 * //
 * // This indication specifies various error rates that was computed during receiving the packet.
 * // It may be present on a packet from the phyiscal layer to the application.
 * //
 * class ErrorRateInd extends SignalTagBase
 * {
 *     double packetErrorRate = NaN; // packet error rate (probability) in the range [0, 1] or NaN if unknown.
 *     double bitErrorRate = NaN;    // bit error rate (probability) in the range [0, 1] or NaN if unknown.
 *     double symbolErrorRate = NaN; // symbol error rate (probability) in the range [0, 1] or NaN if unknown.
 * }
 * </pre>
 */
class INET_API ErrorRateInd : public ::inet::SignalTagBase
{
  protected:
    double packetErrorRate = NaN;
    double bitErrorRate = NaN;
    double symbolErrorRate = NaN;

  private:
    void copy(const ErrorRateInd& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ErrorRateInd&);

  public:
    ErrorRateInd();
    ErrorRateInd(const ErrorRateInd& other);
    virtual ~ErrorRateInd();
    ErrorRateInd& operator=(const ErrorRateInd& other);
    virtual ErrorRateInd *dup() const override {return new ErrorRateInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual double getPacketErrorRate() const;
    virtual void setPacketErrorRate(double packetErrorRate);
    virtual double getBitErrorRate() const;
    virtual void setBitErrorRate(double bitErrorRate);
    virtual double getSymbolErrorRate() const;
    virtual void setSymbolErrorRate(double symbolErrorRate);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ErrorRateInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ErrorRateInd& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/physicallayer/common/packetlevel/SignalTag.msg:124</tt> by nedtool.
 * <pre>
 * //
 * // This indication specifies the timing of the received signal.
 * // It may be present on a packet from the phyiscal layer to the application.
 * //
 * class SignalTimeInd extends SignalTagBase
 * {
 *     simtime_t startTime;
 *     simtime_t endTime;
 * }
 * </pre>
 */
class INET_API SignalTimeInd : public ::inet::SignalTagBase
{
  protected:
    omnetpp::simtime_t startTime = SIMTIME_ZERO;
    omnetpp::simtime_t endTime = SIMTIME_ZERO;

  private:
    void copy(const SignalTimeInd& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SignalTimeInd&);

  public:
    SignalTimeInd();
    SignalTimeInd(const SignalTimeInd& other);
    virtual ~SignalTimeInd();
    SignalTimeInd& operator=(const SignalTimeInd& other);
    virtual SignalTimeInd *dup() const override {return new SignalTimeInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual omnetpp::simtime_t getStartTime() const;
    virtual void setStartTime(omnetpp::simtime_t startTime);
    virtual omnetpp::simtime_t getEndTime() const;
    virtual void setEndTime(omnetpp::simtime_t endTime);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignalTimeInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignalTimeInd& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_SIGNALTAG_M_H

