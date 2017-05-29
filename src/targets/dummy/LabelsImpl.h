/* LabelsImpl.h - Dummy */

#ifndef LABELS_DUMMY_H
#define LABELS_DUMMY_H

#include <Stack.h>
#include <common/BaseLabels.h>

class LabelsImpl : public BaseLabels {
    public:
        void initGraphics(Stack *stack);
        void draw() const;
};

#endif
