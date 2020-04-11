/* Labels.h */

#ifndef LABELS_H
#define LABELS_H

#include <Position.h>
#include <LabelsImpl.h>

/* Forward declarations to avoid dependency hell */
class Mode;

class Labels {
    public:
        Labels();

        void layout(const Position &parent);
        void draw() const;

        inline void set_mode(Mode *new_mode) { m_mode = new_mode; };

    private:
        Mode *m_mode;
        LabelsImpl m_implementation;
};

#endif // LABELS_H
