/* Labels.h */

#ifndef CORE_LABELS_H
#define CORE_LABELS_H

#include <Mode.h>

namespace Core {
    class Labels {
        public:
            inline void setMode(Mode *new_mode) { m_mode = new_mode; };
        protected:
            Mode *m_mode;
    };
}

#endif
