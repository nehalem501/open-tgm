/* FrameImpl.h - SDL2 */

#ifndef FRAME_SDL2_H
#define FRAME_SDL2_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
