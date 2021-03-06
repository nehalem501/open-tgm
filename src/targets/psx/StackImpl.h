/* StackImpl.h - PSX */

#ifndef STACK_PSX_H
#define STACK_PSX_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
