/* SettingsImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Utils.h>
#include <Global.h>
#include <MainMenu.h>
#include <Input.h>
#include <Background.h>
#include "GlobalSFML.h"
#include "SettingsImpl.h"

void SettingsImpl::init() {

}

void SettingsImpl::update(int *menustate) {
    switch (m_state) {
        case SettingsState::LIST:
            if (input.up()) {
                if (m_das_up == 0) {
                    m_settings_str[m_selected].update_color(TextColor::TRANSPARENT);

                    if (m_selected <= 0)
                        m_selected = SettingsState::SETTINGS_NB - 1;
                    else
                        m_selected--;

                    m_settings_str[m_selected].update_color(TextColor::WHITE);
                }
                m_das_up += 16;
            } else {
                m_das_up = 0;
            }

            if (input.down()) {
                if (m_das_down == 0) {
                    m_settings_str[m_selected].update_color(TextColor::TRANSPARENT);

                    if (m_selected >= SettingsState::SETTINGS_NB - 1)
                        m_selected = 0;
                    else
                        m_selected++;

                    m_settings_str[m_selected].update_color(TextColor::WHITE);
                }
                m_das_down += 16;
            } else {
                m_das_down = 0;
            }

            if (input.a()) {
                if (m_selected == SettingsState::EXIT) {
                    *menustate = MainMenuState::HOME;
                    background.go_to_background();
                    return;
                }

                m_state = m_selected;
                m_das_up = 0;
                m_das_down = 0;
            }

            break;

        case SettingsState::INPUT_TEST:
            set(input.start(), &m_input_states_str[0]);
            set(input.up(), &m_input_states_str[1]);
            set(input.down(), &m_input_states_str[2]);
            set(input.left(), &m_input_states_str[3]);
            set(input.right(), &m_input_states_str[4]);
            set(input.a(), &m_input_states_str[5]);
            set(input.b(), &m_input_states_str[6]);
            set(input.c(), &m_input_states_str[7]);

            #ifdef DEBUG
            set(input.rotate_left(), &m_input_states_str[8]);
            set(input.rotate_right(), &m_input_states_str[9]);
            #endif

            // Exit
            if (input.right() && input.start()) {
                m_state = SettingsState::LIST;
            }
            break;
    }
}

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

void SettingsImpl::resize() {
    m_input_msg.resize();

    for (unsigned int i = 0; i < SettingsState::SETTINGS_NB; i++) {
        m_settings_str[i].resize();
    }

    for (unsigned int i = 0; i < NB_INPUTS; i++) {
        m_inputs_str[i].resize();
        m_input_states_str[i].resize();
    }
}

void SettingsImpl::draw(sf::RenderTarget& target, sf::RenderStates) const {
    switch (m_state) {
        case SettingsState::LIST:
            for (unsigned int i = 0; i < SettingsState::SETTINGS_NB; i++) {
                target.draw(m_settings_str[i]);
            }
            break;

        case SettingsState::INPUT_TEST:
            target.draw(m_input_msg);
            for (unsigned int i = 0; i < NB_INPUTS; i++) {
                target.draw(m_inputs_str[i]);
                target.draw(m_input_states_str[i]);
            }
            break;
    }
}
