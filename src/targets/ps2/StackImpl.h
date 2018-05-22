/* StackImpl.h - PS2 */

#ifndef STACK_PS2_H
#define STACK_PS2_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
