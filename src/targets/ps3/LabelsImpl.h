/* LabelsImpl.h - PS3 */

#ifndef LABELS_PS3_H
#define LABELS_PS3_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void init_graphics(Stack *stack);
        void draw() const;
};

#endif
