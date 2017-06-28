/* FrameImpl.h - GBA */

#ifndef FRAME_GBA_H
#define FRAME_GBA_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
