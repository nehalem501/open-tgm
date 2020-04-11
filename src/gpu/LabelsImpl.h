/* LabelsImpl.h - GPU */

#ifndef LABELS_GPU_H
#define LABELS_GPU_H

#include <Position.h>

class LabelsImpl {
    public:
        void layout(const Position &position);
        void render() const;
};

#endif
