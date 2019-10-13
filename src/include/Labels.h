/* Labels.h */

#ifndef LABELS_H
#define LABELS_H

#include <Position.h>
#include <LabelsImpl.h>

/* Forward declarations to avoid dependency hell */
class Mode;

class Labels {
    public:
        Labels(const Position& parent);

        void draw();

        inline void set_mode(Mode *new_mode) { m_mode = new_mode; };

    private:
        Mode *m_mode;
        const Position& m_parent;

        LabelsImpl m_implementation;
};

#endif // LABELS_H
