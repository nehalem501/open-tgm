/* LabelsImpl.h - PS2 */

#ifndef LABELS_PS2_H
#define LABELS_PS2_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void init_graphics(Stack *stack);
        void draw() const;
};

#endif
