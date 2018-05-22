/* FrameImpl.h - PS2 */

#ifndef FRAME_PS2_H
#define FRAME_PS2_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
