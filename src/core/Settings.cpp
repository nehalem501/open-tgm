/* Settings.cpp */

#include <stdint.h>
#include <Global.h>
#include <Input.h>
#include <Menu.h>
#include <Text.h>
#include <Background.h>
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

const char *INPUTS_STR[8] = {
    START_STR,
    UP_STR,
    DOWN_STR,
    LEFT_STR,
    RIGHT_STR,
    A_STR,
    B_STR,
    C_STR
};

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

    input_msg.update_text("EXIT: RIGHT AND START");
    input_msg.update_pos(9, 23);
    input_msg.updateGraphics();
    input_msg.update_color(TextColor::WHITE);

    for (unsigned int i = 0; i < SettingsState::SETTINGS_NB; i++) {
        settings_str[i].update_text(SETTINGS_STR[i]);
        settings_str[i].update_pos(5, 7 + i * 2);
        settings_str[i].updateGraphics();
        settings_str[i].update_color(TextColor::TRANSPARENT);
    }

    settings_str[0].update_color(TextColor::WHITE);

    // Init input test display
    for (unsigned int i = 0; i < 8; i++) {
        inputs_str[i].update_text(INPUTS_STR[i]);
        inputs_str[i].update_pos(5, 6 + i * 2);
        inputs_str[i].updateGraphics();
        inputs_str[i].update_color(TextColor::WHITE);

        input_states_str[i].update_text("OFF");
        input_states_str[i].update_pos(11, 6 + i * 2);
        input_states_str[i].updateGraphics();
        input_states_str[i].update_color(TextColor::TRANSPARENT);
    }
}

void Core::Settings::init() {
    m_state = -1;
    m_selected = 0;
    m_DASup = 0;
    m_DASdown = 0;

    // Text color
}

void Core::Settings::update(int8_t *menustate) {
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

            // Exit
            if (input.right() && input.start()) {
                m_state = SettingsState::LIST;
            }
            break;
    }
}
