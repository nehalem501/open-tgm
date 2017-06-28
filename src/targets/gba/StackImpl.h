/* StackImpl.h - GBA */

#ifndef STACK_GBA_H
#define STACK_GBA_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
