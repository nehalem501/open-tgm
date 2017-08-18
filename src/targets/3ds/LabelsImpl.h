/* LabelsImpl.h - 3DS */

#ifndef LABELS_3DS_H
#define LABELS_3DS_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void initGraphics(Stack *stack);
        void draw() const;
};

#endif
