/* FrameImpl.h - 3DS */

#ifndef FRAME_3DS_H
#define FRAME_3DS_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
