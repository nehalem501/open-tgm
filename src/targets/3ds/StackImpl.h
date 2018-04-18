/* StackImpl.h - 3DS */

#ifndef STACK_3DS_H
#define STACK_3DS_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
