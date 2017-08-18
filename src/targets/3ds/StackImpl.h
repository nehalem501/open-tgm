/* StackImpl.h - 3DS */

#ifndef STACK_3DS_H
#define STACK_3DS_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
