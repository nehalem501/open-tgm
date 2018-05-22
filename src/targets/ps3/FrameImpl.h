/* FrameImpl.h - PS3 */

#ifndef FRAME_PS3_H
#define FRAME_PS3_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
