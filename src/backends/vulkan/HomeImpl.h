/* HomeImpl.h - Vulkan */

#ifndef HOME_VULKAN_H
#define HOME_VULKAN_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void init_graphics();
        void draw() const;
};

#endif
