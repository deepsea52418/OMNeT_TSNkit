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

#include "nesting/linklayer/framePreemption/PreemptedFrame.h"

namespace nesting {
PreemptedFrame::PreemptedFrame(const cFramePointer& completeFrame) {
    this->completeFrame = nullptr;
    setCompleteFrame(completeFrame);
    this->bytesSent = 0;
    this->bytesTotal = completeFrame->getByteLength();
    setCorrectName();
}

PreemptedFrame::PreemptedFrame(const PreemptedFrame& other) :
        PreemptedFrame_Base(other) {
    copy(other);
}

PreemptedFrame::~PreemptedFrame() {
    if (completeFrame) {
        drop (completeFrame);
        delete completeFrame;
    }
}

void PreemptedFrame::setCorrectName() {
    std::ostringstream oss;
    oss << completeFrame->getName() << " " << bytesInThisPart << "B "
            << bytesSent << "/" << bytesTotal << "B";
    setName(oss.str().c_str());
}
void PreemptedFrame::copy(const PreemptedFrame& other) {
    this->bytesSent = other.bytesSent;
    this->completeFrame = other.completeFrame->dup();
    take(this->completeFrame);
}

PreemptedFrame& PreemptedFrame::operator=(const PreemptedFrame& other) {
    if (this == &other)
        return *this;
    PreemptedFrame::operator=(other);
    copy(other);
    return *this;
}

void PreemptedFrame::setCompleteFrame(const cFramePointer& completeFrame) {
    if (this->completeFrame) {
        throw cRuntimeError(this,
                "setCompleteFrame(): Another complete packet is already set.");
    }
    if (completeFrame) {
        if (completeFrame->getOwner()
                != getSimulation()->getContextSimpleModule()) {
            throw cRuntimeError(this,
                    "setCompleteFrame(): Not owner of message (%s)%s, owner is (%s)%s",
                    completeFrame->getClassName(), completeFrame->getFullName(),
                    completeFrame->getOwner()->getClassName(),
                    completeFrame->getOwner()->getFullPath().c_str());
        }
        this->completeFrame = completeFrame;
        take(completeFrame);
    }
}

cFramePointer PreemptedFrame::removeCompleteFrame() {
    cFramePointer packet = completeFrame;
    completeFrame = nullptr;
    drop(packet);
    return packet;
}

PreemptedFrame* PreemptedFrame::dup() const {
    return new PreemptedFrame(*this);
}
void PreemptedFrame::setBytesSent(unsigned int bytesSent) {
    PreemptedFrame_Base::setBytesSent(bytesSent);
    setCorrectName();
}
void PreemptedFrame::setBytesTotal(unsigned int bytesTotal) {
    PreemptedFrame_Base::setBytesTotal(bytesTotal);
    setCorrectName();
}
void PreemptedFrame::setBytesInThisPart(unsigned int bytesInThisPart) {
    PreemptedFrame_Base::setBytesInThisPart(bytesInThisPart);
    setCorrectName();
}

} /* namespace nesting */
