/* BaseLabels.h */

#ifndef BASE_LABELS_H
#define BASE_LABELS_H

#include <Mode.h>

class BaseLabels {
    public:
        inline void setMode(Mode *new_mode) { mode = new_mode; };
    private:
        Mode *mode;
};

#endif
