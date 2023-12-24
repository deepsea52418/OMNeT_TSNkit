package nesting.linklayer.framePreemption;

import inet.linklayer.contract.IEtherMac;
import inet.linklayer.ethernet.EtherMacFullDuplex;


//
// This module extends the INET EtherMacFullDuplex module and adds frame preemption capabilities.
//
simple EtherMACFullDuplexPreemptable extends EtherMacFullDuplex like IEtherMac
{
    parameters:
        @class(EtherMACFullDuplexPreemptable);
        bool enablePreemptingFrames = default(false); // frame preemption off or on
        @signal[preemptCurrentFrameSignal](type=long); // type=unique packet id
        @signal[transmittedExpressFrameSignal](type=long); // type=unique packet id
        @signal[startTransmissionExpressFrameSignal](type=long); // type=unique packet id
        @signal[transmittedPreemptableFrameSignal](type=long); // type=unique packet id
        @signal[transmittedPreemptableFramePartSignal](type=long); // type=unique packet id
        @signal[transmittedPreemptableNonFinalSignal](type=long); // type=unique packet id
        @signal[transmittedPreemptableFinalSignal](type=long); // type=unique packet id
        @signal[transmittedPreemptableFullSignal](type=long); // type=unique packet id
        @signal[expressFrameEnqueuedWhileSendingPreemptableSignal];
        @signal[eMacDelay](type=simtime_t; unit=s);
        @signal[pMacDelay](type=simtime_t; unit=s);
        @signal[receivedExpressFrame](type=long); // type=unique packet id
        @signal[receivedPreemptableFrameFull](type=long); // type=unique packet id
        @signal[receivedExpressFrameFromUpper]; // type=unique packet id
        
        @statistic[txExpressFrame](title="txExpressFrame"; source=transmittedExpressFrameSignal ; record=vector; interpolationmode=none);
        @statistic[txPreemptableFrameFinal](title="txPreemptableFrameFinal"; source=transmittedPreemptableFinalSignal ; record=vector; interpolationmode=none);
        @statistic[txPreemptableFrameFull](title="txPreemptableFrameFull"; source=transmittedPreemptableFullSignal ; record=vector; interpolationmode=none);
        @statistic[receivedPreemptableFrameFull](title="receivedPreemptableFrameFull"; record=vector; interpolationmode=none);
        @statistic[receivedExpressFrame](title="receivedExpressFrame"; record=vector; interpolationmode=none);
        @statistic[startTxExpressFrames](title="startTxExpressFrames"; source=startTransmissionExpressFrameSignal; record=vector; interpolationmode=none);
        @statistic[receivedExpressFrameFromUpper](title="receivedExpressFrameFromUpper";record=vector; interpolationmode=none);
        @statistic[eMacDelay](title="eMacDelay"; record=histogram,vector; interpolationmode=none);
        @statistic[pMacDelay](title="pMacDelay"; record=histogram,vector; interpolationmode=none);
        @statistic[preemptions](title="preemptions"; source=preemptCurrentFrameSignal; record=count; interpolationmode=none);
        @statistic[expressFrames](title="expressFrames"; source=transmittedExpressFrameSignal; record=count; interpolationmode=none);
        @statistic[preemptableFrames](title="preemptableFrames"; source=transmittedPreemptableFrameSignal; record=count; interpolationmode=none);
        @statistic[mPackets](title="mPackets"; source=transmittedPreemptableFramePartSignal; record=count; interpolationmode=none);
        @statistic[mPacketsNonFinal](title="mPackets non-final"; source=transmittedPreemptableNonFinalSignal; record=count; interpolationmode=none);
        @statistic[mPacketsFinal](title="mPackets final"; source=transmittedPreemptableFinalSignal; record=count; interpolationmode=none);
        @statistic[mPacketsFull](title="mpackets full"; source=transmittedPreemptableFullSignal; record=count; interpolationmode=none);
        @statistic[expressFramesEnqueued](title="express frames enqueued"; source=expressFrameEnqueuedWhileSendingPreemptableSignal; record=count; interpolationmode=none);
}

