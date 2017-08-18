/* FrameImpl.h - 3DS */

#ifndef FRAME_3DS_H
#define FRAME_3DS_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
