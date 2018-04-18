/* StackImpl.h - SDL2 */

#ifndef STACK_SDL2_H
#define STACK_SDL2_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
