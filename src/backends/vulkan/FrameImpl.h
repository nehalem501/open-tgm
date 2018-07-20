/* FrameImpl.h - Vulkan */

#ifndef FRAME_VULKAN_H
#define FRAME_VULKAN_H

#include <core/Frame.h>

class FrameImpl : public Core::Frame {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
