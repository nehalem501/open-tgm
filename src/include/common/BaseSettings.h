/* BaseSettings.h */

#ifndef BASE_SETTINGS_H
#define BASE_SETTINGS_H

#include <stdint.h>

class BaseSettings {
    public:
        BaseSettings();
        void update(int8_t *menustate);
    protected:
        int8_t m_state;
};

#endif
