/* FrameImpl.h - PSX */

#ifndef FRAME_PSX_H
#define FRAME_PSX_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
