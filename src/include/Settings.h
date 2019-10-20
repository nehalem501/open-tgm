/* Settings.h */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <TargetTypes.h>
#include <Background.h>
#include <Text.h>

namespace SettingsState {
    enum {
        LIST = -1,
        INPUT_TEST = 0,
        EXIT = 1,
        SETTINGS_NB = 2
    };
}

#ifdef DEBUG
#define NB_INPUTS 10
#else
#define NB_INPUTS 8
#endif

class Settings {
    public:
        Settings();

        void draw() const;

        void update(int *menustate, Background *background);

    private:
        int m_state, m_selected;
        uint8_t m_das_up, m_das_down;

        Text m_settings_str[SettingsState::SETTINGS_NB];
        Text m_inputs_str[NB_INPUTS];
        Text m_input_states_str[NB_INPUTS];
        Text m_input_msg;
};

#endif // SETTINGS_H
