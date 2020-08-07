/* HomeImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GlobalSFML.h"
#include "HomeImpl.h"

void HomeImpl::init_graphics() {
    if (!m_logo_tex.loadFromFile("resources/any/open-tgm-logo.png")) {
        std::cout << "ERROR loading Open TGM logo texture" << std::endl;
    }
    m_logo_tex.setSmooth(true);
    m_logo.setTexture(m_logo_tex);
    m_logo.setOrigin(m_logo_tex.getSize().x / 2.0f, 0);

    m_start.init_graphics();
    m_start.update_text("PRESS START");
    m_start.update_pos(16, 17);
    m_start.update_graphics();
}

void HomeImpl::resize() {
    m_logo.setPosition(screen_size.x / 2, (float) screen_size.y / 8.0f);
    float scale = ((float) screen_size.y / (float) m_logo_tex.getSize().y) / 2.2f;
    m_logo.setScale(scale, scale);

    m_start.resize();
}

void HomeImpl::draw(sf::RenderTarget& target, sf::RenderStates) const {
    if (m_start_timer > -20) {
        target.draw(m_start);
    }
    target.draw(m_logo);
}
