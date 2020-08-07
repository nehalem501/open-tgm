/* DigitsImpl.h - Vulkan */

#ifndef DIGITS_VULKAN_H
#define DIGITS_VULKAN_H

/* Forward declarations to avoid dependency hell */
class StackImpl;
typedef StackImpl Stack;

#include <core/Digits.h>

class DigitsImpl : public Core::Digits {
    public:
        void init_graphics();
        void update_graphics(Stack *stack);
        void draw() const;
};

#endif
