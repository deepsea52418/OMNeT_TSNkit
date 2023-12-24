//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef NESTING_IEEE8021Q_QUEUE_FRAMEPREEMPTION_PREEMPTEDFRAME_H_
#define NESTING_IEEE8021Q_QUEUE_FRAMEPREEMPTION_PREEMPTEDFRAME_H_

#include <omnetpp.h>

#include "nesting/linklayer/framePreemption/PreemptedFrame_m.h"

using namespace omnetpp;
namespace nesting {

/**
 * This class extends the auto-generated base class for preempted packets and
 * adds correct ownership handling.
 */
class PreemptedFrame: public PreemptedFrame_Base {
private:
    void copy(const PreemptedFrame& other);
    virtual void setCorrectName();
protected:
    PreemptedFrame& operator=(const PreemptedFrame& other);
public:
    PreemptedFrame(const cFramePointer& completeFrame);
    PreemptedFrame(const PreemptedFrame& other);
    virtual ~PreemptedFrame();
    virtual void setCompleteFrame(const cFramePointer& completeFrame) override;
    virtual cFramePointer removeCompleteFrame();
    virtual PreemptedFrame* dup() const override;
    virtual void setBytesSent(unsigned int bytesSent) override;
    virtual void setBytesTotal(unsigned int bytesTotal) override;
    virtual void setBytesInThisPart(unsigned int bytesInThisPart) override;
};

} /* namespace nesting */

#endif /* NESTING_IEEE8021Q_QUEUE_FRAMEPREEMPTION_PREEMPTEDFRAME_H_ */
