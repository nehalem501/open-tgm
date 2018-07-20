/* ChooseModeImpl.h - Vulkan */

#ifndef CHOOSE_MODE_VULKAN_H
#define CHOOSE_MODE_VULKAN_H

#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode {
    public:
        void init_graphics();
        void draw() const;
};

#endif
