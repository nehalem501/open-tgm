/* StackImpl.h - OpenGL */

#ifndef STACK_OPENGL_H
#define STACK_OPENGL_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
