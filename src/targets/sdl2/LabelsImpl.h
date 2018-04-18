/* LabelsImpl.h - SDL2 */

#ifndef LABELS_SDL2_H
#define LABELS_SDL2_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void init_graphics(Stack *stack);
        void draw() const;
};

#endif
