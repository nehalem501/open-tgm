/* FrameImpl.h - OpenGL3 */

#ifndef FRAME_OPENGL3_H
#define FRAME_OPENGL3_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
