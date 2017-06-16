/* Settings.h */

#ifndef CORE_SETTINGS_H
#define CORE_SETTINGS_H

#include <stdint.h>

namespace Core {
    class Settings {
        public:
            Settings();
            void update(int8_t *menustate);
        protected:
            int8_t m_state;
    };
}

#endif
