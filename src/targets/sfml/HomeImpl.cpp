/* HomeImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GlobalSFML.h"
#include "HomeImpl.h"

void HomeImpl::initGraphics() {
    if (!m_logo_tex.loadFromFile("resources/open-tgm-logo.png")) {
        std::cout << "ERROR loading Open TGM logo texture" << std::endl;
    }
    m_logo_tex.setSmooth(true);
    m_logo.setTexture(m_logo_tex);
    m_logo.setOrigin(m_logo_tex.getSize().x / 2.0f, 0);

    if (!m_start_tex.loadFromFile("resources/start-button.png")) {
        std::cout << "ERROR loading start button texture" << std::endl;
    }
    m_start_tex.setSmooth(true);
    m_start.setTexture(m_start_tex);
    m_start.setOrigin(m_start_tex.getSize().x / 2.0f, 0);
}

void HomeImpl::updateSize() {
    m_logo.setPosition(screen_size.x / 2, (float) screen_size.y / 8.0f);
    float scale = ((float) screen_size.y / (float) m_logo_tex.getSize().y) / 2.2f;
    m_logo.setScale(scale, scale);

    m_start.setPosition(screen_size.x / 2, 7.0f * ((float) screen_size.y / 12.0f));
    scale = ((float) screen_size.y / (float) m_start_tex.getSize().y) / 6.0f;
    m_start.setScale(scale, scale);
}

void HomeImpl::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (m_start_timer > -20) {
        target.draw(m_start);
    }
    target.draw(m_logo);
}
