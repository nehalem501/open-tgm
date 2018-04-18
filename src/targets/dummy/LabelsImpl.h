/* LabelsImpl.h - Dummy */

#ifndef LABELS_DUMMY_H
#define LABELS_DUMMY_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void init_graphics(Stack *stack);
        void draw() const;
};

#endif
