/* BaseChooseMode.h */

#ifndef BASE_CHOOSE_MODE_H
#define BASE_CHOOSE_MODE_H

#include <stdint.h>

class BaseChooseMode {
    public:
        BaseChooseMode();
        
        void initGraphics();
        void update(int8_t *state);
        
    private:
        int8_t m_mode;
};

#endif

