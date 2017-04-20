/* LabelsImpl.h - Dummy */

#ifndef LABELS_DUMMY_H
#define LABELS_DUMMY_H

#include <common/BaseLabels.h>

class LabelsImpl : public BaseLabels {
    public:
        void initGraphics();
        void init();
        void draw() const;
};

#endif
