/* LabelsImpl.h - GBA */

#ifndef LABELS_GBA_H
#define LABELS_GBA_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void init_graphics(Stack *stack);
        void draw() const;
};

#endif
