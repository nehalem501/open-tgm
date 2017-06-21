/* Settings.h */

#ifndef CORE_SETTINGS_H
#define CORE_SETTINGS_H

#include <stdint.h>
#include <Text.h>

namespace SettingsState {
    enum {
        LIST = 0,
        INPUT_TEST = 1,
        SETTINGS_NB = 2
    };
}

const char INPUT_TEST_STR[] = "INPUT TEST";
const char EXIT_STR[] = "EXIT";

namespace Core {
    class Settings {
        public:
            Settings();
            void init();
            void update(int8_t *menustate);
        protected:
            int8_t m_state;
            int8_t m_selected;

            ::Text input_test_str;
            ::Text exit_str;
    };
}

#endif
