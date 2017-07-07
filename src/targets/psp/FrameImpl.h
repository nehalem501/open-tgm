/* FrameImpl.h - PSP */

#ifndef FRAME_PSP_H
#define FRAME_PSP_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
