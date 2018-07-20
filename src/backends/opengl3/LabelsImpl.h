/* LabelsImpl.h - OpenGL3 */

#ifndef LABELS_OPENGL3_H
#define LABELS_OPENGL3_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void init_graphics(Stack *stack);
        void draw() const;
};

#endif
