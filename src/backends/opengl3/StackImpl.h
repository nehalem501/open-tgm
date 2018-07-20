/* StackImpl.h - OpenGL3 */

#ifndef STACK_OPENGL3_H
#define STACK_OPENGL3_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
