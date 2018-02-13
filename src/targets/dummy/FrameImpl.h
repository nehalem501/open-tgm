/* FrameImpl.h - Dummy */

#ifndef FRAME_DUMMY_H
#define FRAME_DUMMY_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
