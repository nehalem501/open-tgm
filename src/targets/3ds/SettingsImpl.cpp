/* SettingsImpl.cpp - 3DS */

#include "SettingsImpl.h"

void SettingsImpl::initGraphics() {
    input_msg.initGraphics();

    for (unsigned int i = 0; i < SettingsState::SETTINGS_NB; i++) {
        settings_str[i].initGraphics();
    }

    for (unsigned int i = 0; i < NB_INPUTS; i++) {
        inputs_str[i].initGraphics();
        input_states_str[i].initGraphics();
    }
}

void SettingsImpl::draw() const {
    switch (m_state) {
        case SettingsState::LIST:
            for (unsigned int i = 0; i < SettingsState::SETTINGS_NB; i++) {
                settings_str[i].draw();
            }
            break;

        case SettingsState::INPUT_TEST:
            input_msg.draw();
            for (unsigned int i = 0; i < NB_INPUTS; i++) {
                inputs_str[i].draw();
                input_states_str[i].draw();
            }
            break;
    }
}
