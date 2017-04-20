/* BaseHome.h */

#ifndef BASE_HOME_H
#define BASE_HOME_H

#include <stdint.h>

class BaseHome {
    public:
        BaseHome();
        void update(int8_t *state);

    protected:
        int8_t m_start_timer;
};

#endif
