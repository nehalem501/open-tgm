/* SettingsImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GlobalSFML.h"
#include "SettingsImpl.h"

void SettingsImpl::initGraphics() {
    input_test_str.initGraphics();
    exit_str.initGraphics();
}

void SettingsImpl::updateSize() {
    input_test_str.updateSize();
    exit_str.updateSize();
}

void SettingsImpl::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    switch (m_state) {
        case SettingsState::LIST:
            target.draw(input_test_str);
            target.draw(exit_str);
            break;

        case SettingsState::INPUT_TEST:
            break;
    }
}
