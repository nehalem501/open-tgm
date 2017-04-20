/* FrameImpl.h - Dummy */

#ifndef FRAME_DUMMY_H
#define FRAME_DUMMY_H

#include <common/BaseFrame.h>

class FrameImpl : public BaseFrame {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
