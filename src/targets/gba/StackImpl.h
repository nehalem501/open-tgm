/* StackImpl.h - GBA */

#ifndef STACK_GBA_H
#define STACK_GBA_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
