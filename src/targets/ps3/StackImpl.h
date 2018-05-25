/* StackImpl.h - PS3 */

#ifndef STACK_PS3_H
#define STACK_PS3_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif