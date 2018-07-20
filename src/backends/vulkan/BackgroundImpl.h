/* BackgroundImpl.h - Vulkan */

#ifndef BACKGROUND_VULKAN_H
#define BACKGROUND_VULKAN_H

#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void init_graphics();
        void draw() const;
};

#endif
