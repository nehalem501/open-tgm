/* StackImpl.h - PSP */

#ifndef STACK_PSP_H
#define STACK_PSP_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
