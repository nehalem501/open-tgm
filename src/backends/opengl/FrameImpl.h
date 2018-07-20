/* FrameImpl.h - OpenGL */

#ifndef FRAME_OPENGL_H
#define FRAME_OPENGL_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
