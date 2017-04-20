/* BaseChooseMode.h */

#ifndef BASE_CHOOSE_MODE_H
#define BASE_CHOOSE_MODE_H

#include <stdint.h>

class BaseChooseMode {
    public:
        BaseChooseMode();
        void update(int8_t *state);

    protected:
        int8_t m_mode;
};

#endif
