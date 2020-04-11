/* LabelsImpl.h - GBA */

#ifndef LABELS_GBA_H
#define LABELS_GBA_H

#include <Position.h>

class LabelsImpl {
    public:
        void layout(const Position &position);
        void render() const;
};

#endif
