/* BaseLabels.h */

#ifndef BASE_LABELS_H
#define BASE_LABELS_H

#include <Mode.h>

class BaseLabels {
    public:
        inline void setMode(Mode *new_mode) { m_mode = new_mode; };
    protected:
        Mode *m_mode;
};

#endif
