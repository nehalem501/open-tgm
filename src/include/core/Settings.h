/* Settings.h */

#ifndef CORE_SETTINGS_H
#define CORE_SETTINGS_H

#include <stdint.h>
#include <Text.h>

namespace SettingsState {
    enum {
        LIST = -1,
        INPUT_TEST = 0,
        EXIT = 1,
        SETTINGS_NB = 2
    };
}

namespace Core {
    class Settings {
        public:
            Settings();
            void init();
            void update(int *menustate);

        protected:
            int m_state, m_selected;
            uint8_t m_DASup, m_DASdown;

            ::Text settings_str[SettingsState::SETTINGS_NB];
            ::Text inputs_str[8];
            ::Text input_states_str[8];
            ::Text input_msg;
    };
}

#endif
