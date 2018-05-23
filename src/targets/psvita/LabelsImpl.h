/* LabelsImpl.h - PSVita */

#ifndef LABELS_PSVITA_H
#define LABELS_PSVITA_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void init_graphics(Stack *stack);
        void draw() const;
};

#endif
