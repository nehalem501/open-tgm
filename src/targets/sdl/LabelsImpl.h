/* LabelsImpl.h - SDL */

#ifndef LABELS_SDL_H
#define LABELS_SDL_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void init_graphics(Stack *stack);
        void draw() const;
};

#endif
