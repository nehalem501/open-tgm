/* FrameImpl.h - SDL */

#ifndef FRAME_SDL_H
#define FRAME_SDL_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
