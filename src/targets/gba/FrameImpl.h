/* FrameImpl.h - GBA */

#ifndef FRAME_GBA_H
#define FRAME_GBA_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
