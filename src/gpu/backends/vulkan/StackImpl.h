/* StackImpl.h - Vulkan */

#ifndef STACK_VULKAN_H
#define STACK_VULKAN_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
