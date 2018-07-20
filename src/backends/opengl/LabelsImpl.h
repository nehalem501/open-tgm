/* LabelsImpl.h - OpenGL */

#ifndef LABELS_OPENGL_H
#define LABELS_OPENGL_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void init_graphics(Stack *stack);
        void draw() const;
};

#endif
