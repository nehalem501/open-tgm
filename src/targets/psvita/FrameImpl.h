/* FrameImpl.h - PSVita */

#ifndef FRAME_PSVITA_H
#define FRAME_PSVITA_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
