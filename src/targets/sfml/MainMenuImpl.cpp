/* MainMenuImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Global.h>
#include <Frame.h>
#include <Home.h>
#include <Background.h>
#include <Game.h>
#include "GlobalSFML.h"
#include "MainMenuImpl.h"

void MainMenuImpl::init_graphics() {
    m_home.init_graphics();
    m_choose_mode.init_graphics();
    m_settings.init_graphics();
}

void MainMenuImpl::resize() {
    tile_size = screen_size.y / TILE_RATIO;

    m_background.resize();

    // TODO check for multiplayer
    m_game.resize();
    m_frame1.resize(&m_stack1);

    m_home.resize();
    m_choose_mode.resize();
    m_settings.resize();
}

void MainMenuImpl::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(m_background);
    switch(m_state) {
        case MainMenuState::HOME:
            target.draw(m_home);
            break;

        case MainMenuState::CHOOSE_PLAYER:
            target.draw(m_frame1);
            //target.draw(dataNotUsed);
            //target.draw(newPlaiyer);
            //target.draw(loadPlayer);
            break;

        case MainMenuState::CHOOSE_MODE:
            target.draw(m_frame1);
            target.draw(m_choose_mode);
            break;

        case MainMenuState::START_GAME:
            target.draw(m_frame1);
            break;

        case MainMenuState::INGAME:
            target.draw(m_frame1);
            // TODO 2 players
            target.draw(m_game);
            break;

        case MainMenuState::SETTINGS:
            target.draw(m_settings);
            break;

        default:
            break;
    }
}
