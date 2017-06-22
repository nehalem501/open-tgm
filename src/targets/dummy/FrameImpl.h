/* FrameImpl.h - Dummy */

#ifndef FRAME_DUMMY_H
#define FRAME_DUMMY_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
