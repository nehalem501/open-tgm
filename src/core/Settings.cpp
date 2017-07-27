/* Settings.cpp */

#include <stdint.h>
#include <Global.h>
#include <Input.h>
#include <Menu.h>
#include <Text.h>
#include <Background.h>
#include <Utils.h>
#include <core/Settings.h>

const char INPUT_TEST_STR[] = "INPUT TEST";
const char EXIT_STR[] = "EXIT";

const char *SETTINGS_STR[] = {
    INPUT_TEST_STR,
    EXIT_STR
};

const char A_STR[] = "A";
const char B_STR[] = "B";
const char C_STR[] = "C";
const char UP_STR[] = "UP";
const char DOWN_STR[] = "DOWN";
const char RIGHT_STR[] = "RIGHT";
const char LEFT_STR[] = "LEFT";
const char START_STR[] = "START";

#ifdef DEBUG

const char ROT_L_STR[] = "ROT L";
const char ROT_R_STR[] = "ROT R";

const char *INPUTS_STR[NB_INPUTS] = {
    START_STR,
    UP_STR,
    DOWN_STR,
    LEFT_STR,
    RIGHT_STR,
    A_STR,
    B_STR,
    C_STR,
    ROT_L_STR,
    ROT_R_STR
};

#else

const char *INPUTS_STR[NB_INPUTS] = {
    START_STR,
    UP_STR,
    DOWN_STR,
    LEFT_STR,
    RIGHT_STR,
    A_STR,
    B_STR,
    C_STR
};

#endif //DEBUG

void set(bool state, Text *text) {
    if (state) {
        text->update_text("ON");
        text->updateGraphics();
        text->update_color(TextColor::YELLOW);
    } else {
        text->update_text("OFF");
        text->updateGraphics();
        text->update_color(TextColor::TRANSPARENT);
    }
}

Core::Settings::Settings() : m_state(-1), m_selected(0), m_DASup(0),
                             m_DASdown(0) {
    //cout << "Settings screen constructor" << endl;

    edit_text(&input_msg, 9, 23, TextColor::WHITE, "EXIT: RIGHT AND START");

    for (unsigned int i = 0; i < SettingsState::SETTINGS_NB; i++) {
        edit_text(&settings_str[i], 5, 7 + i * 2, TextColor::TRANSPARENT,
                  SETTINGS_STR[i]);
    }

    settings_str[0].update_color(TextColor::WHITE);

    // Init input test display
    for (unsigned int i = 0; i < NB_INPUTS; i++) {
        edit_text(&inputs_str[i], 5, 6 + i * 2, TextColor::WHITE,
                  INPUTS_STR[i]);
        edit_text(&input_states_str[i], 11, 6 + i * 2, TextColor::TRANSPARENT,
                  "OFF");
    }
}

void Core::Settings::init() {
    m_state = -1;
    m_selected = 0;
    m_DASup = 0;
    m_DASdown = 0;

    // Text color
}

void Core::Settings::update(int *menustate) {
    switch (m_state) {
        case SettingsState::LIST:
            if (input.up()) {
                if (m_DASup == 0) {
                    settings_str[m_selected].update_color(TextColor::TRANSPARENT);

                    if (m_selected <= 0)
                        m_selected = SettingsState::SETTINGS_NB - 1;
                    else
                        m_selected--;

                    settings_str[m_selected].update_color(TextColor::WHITE);
                }
                m_DASup += 16;
            } else {
                m_DASup = 0;
            }

            if (input.down()) {
                if (m_DASdown == 0) {
                    settings_str[m_selected].update_color(TextColor::TRANSPARENT);

                    if (m_selected >= SettingsState::SETTINGS_NB - 1)
                        m_selected = 0;
                    else
                        m_selected++;

                    settings_str[m_selected].update_color(TextColor::WHITE);
                }
                m_DASdown += 16;
            } else {
                m_DASdown = 0;
            }

            if (input.a()) {
                if (m_selected == SettingsState::EXIT) {
                    *menustate = MenuState::HOME;
                    background.changeToBackground();
                    return;
                }

                m_state = m_selected;
                m_DASup = 0;
                m_DASdown = 0;
            }

            break;

        case SettingsState::INPUT_TEST:
            set(input.start(), &input_states_str[0]);
            set(input.up(), &input_states_str[1]);
            set(input.down(), &input_states_str[2]);
            set(input.left(), &input_states_str[3]);
            set(input.right(), &input_states_str[4]);
            set(input.a(), &input_states_str[5]);
            set(input.b(), &input_states_str[6]);
            set(input.c(), &input_states_str[7]);

            #ifdef DEBUG
            set(input.rotate_left(), &input_states_str[8]);
            set(input.rotate_right(), &input_states_str[9]);
            #endif

            // Exit
            if (input.right() && input.start()) {
                m_state = SettingsState::LIST;
            }
            break;
    }
}
