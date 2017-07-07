/* LabelsImpl.h - PSP */

#ifndef LABELS_PSP_H
#define LABELS_PSP_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void initGraphics(Stack *stack);
        void draw() const;
};

#endif
