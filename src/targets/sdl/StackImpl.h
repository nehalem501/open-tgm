/* StackImpl.h - SDL */

#ifndef STACK_SDL_H
#define STACK_SDL_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
