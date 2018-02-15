/* StackImpl.h - PSP */

#ifndef STACK_PSP_H
#define STACK_PSP_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
