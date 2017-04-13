/* BaseHome.h */

#ifndef BASE_HOME_H
#define BASE_HOME_H

#include <stdint.h>

class BaseHome {
    public:
        BaseHome();
        
        void initGraphics();
        void update(int8_t *state);
        
    private:
        int8_t m_start_timer;
};

#endif

