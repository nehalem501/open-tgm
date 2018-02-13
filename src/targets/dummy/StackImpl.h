/* StackImpl.h - Dummy */

#ifndef STACK_DUMMY_H
#define STACK_DUMMY_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
