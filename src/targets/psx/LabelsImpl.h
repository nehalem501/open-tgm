/* LabelsImpl.h - PSX */

#ifndef LABELS_PSX_H
#define LABELS_PSX_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void init_graphics(Stack *stack);
        void draw() const;
};

#endif
