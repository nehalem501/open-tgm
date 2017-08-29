/* SettingsImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Utils.h>
#include <Global.h>
#include <Menu.h>
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

void SettingsImpl::updateSize() {
    input_msg.updateSize();

    for (unsigned int i = 0; i < SettingsState::SETTINGS_NB; i++) {
        settings_str[i].updateSize();
    }

    for (unsigned int i = 0; i < NB_INPUTS; i++) {
        inputs_str[i].updateSize();
        input_states_str[i].updateSize();
    }
}

void SettingsImpl::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    switch (m_state) {
        case SettingsState::LIST:
            for (unsigned int i = 0; i < SettingsState::SETTINGS_NB; i++) {
                target.draw(settings_str[i]);
            }
            break;

        case SettingsState::INPUT_TEST:
            target.draw(input_msg);
            for (unsigned int i = 0; i < NB_INPUTS; i++) {
                target.draw(inputs_str[i]);
                target.draw(input_states_str[i]);
            }
            break;
    }
}
