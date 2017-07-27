/* SettingsImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GlobalSFML.h"
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
