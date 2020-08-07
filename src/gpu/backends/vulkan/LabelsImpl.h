/* LabelsImpl.h - Vulkan */

#ifndef LABELS_VULKAN_H
#define LABELS_VULKAN_H

#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels {
    public:
        void init_graphics(Stack *stack);
        void draw() const;
};

#endif
