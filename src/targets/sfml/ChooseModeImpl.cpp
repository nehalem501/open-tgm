/* ChooseModeImpl.cpp - SFML */

#include <iostream>
#include <Text.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "ChooseModeImpl.h"

void ChooseModeImpl::initGraphics() {
    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].initGraphics();
    }
}

void ChooseModeImpl::updateSize() {
    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].updateSize();
    }
}

void ChooseModeImpl::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int i = 0; i < NB_MODES; i++) {
        target.draw(m_modes_strings[i]);
    }
}
