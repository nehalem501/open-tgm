/* ChooseModeImpl.cpp - SFML */

#include <iostream>
#include <Text.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "ChooseModeImpl.h"

void ChooseModeImpl::init_graphics() {
    /*for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].initGraphics();
    }*/
}

void ChooseModeImpl::resize() {
    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].resize();
    }
}

void ChooseModeImpl::draw(sf::RenderTarget& target, sf::RenderStates) const {
    for (int i = 0; i < NB_MODES; i++) {
        target.draw(m_modes_strings[i]);
    }
}
