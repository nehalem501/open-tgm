/* SettingsImpl.cpp - GBA */

#include "SettingsImpl.h"

void SettingsImpl::init_graphics() {
    m_input_msg.init_graphics();

    for (unsigned int i = 0; i < SettingsState::SETTINGS_NB; i++) {
        m_settings_str[i].init_graphics();
    }

    for (unsigned int i = 0; i < NB_INPUTS; i++) {
        m_inputs_str[i].init_graphics();
        m_input_states_str[i].init_graphics();
    }
}

void SettingsImpl::draw() const {
    switch (m_state) {
        case SettingsState::LIST:
            for (unsigned int i = 0; i < SettingsState::SETTINGS_NB; i++) {
                m_settings_str[i].draw();
            }
            break;

        case SettingsState::INPUT_TEST:
            m_input_msg.draw();
            for (unsigned int i = 0; i < NB_INPUTS; i++) {
                m_inputs_str[i].draw();
                m_input_states_str[i].draw();
            }
            break;
    }
}
