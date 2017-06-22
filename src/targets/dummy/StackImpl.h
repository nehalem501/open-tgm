/* StackImpl.h - Dummy */

#ifndef STACK_DUMMY_H
#define STACK_DUMMY_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
