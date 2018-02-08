/* MenuImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Global.h>
#include <Frame.h>
#include <Home.h>
#include <Background.h>
#include <Game.h>
#include "GlobalSFML.h"
#include "MenuImpl.h"

void MenuImpl::init_graphics() {
    m_home.init_graphics();
    m_chooseMode.init_graphics();
    m_settings.init_graphics();
}

void MenuImpl::resize() {
    tile_size = screen_size.y / TILE_RATIO;

    background.resize();

    m_home.resize();
    m_chooseMode.resize();
    m_settings.resize();
    // TODO check for multiplayer
    game.resize();
    frame1.resize(&stack1);
}

void MenuImpl::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(background);
    switch(m_state) {
        case MenuState::HOME:
            target.draw(m_home);
            break;

        case MenuState::CHOOSE_PLAYER:
            target.draw(frame1);
            //target.draw(dataNotUsed);
            //target.draw(newPlaiyer);
            //target.draw(loadPlayer);
            break;

        case MenuState::CHOOSE_MODE:
            target.draw(frame1);
            target.draw(m_chooseMode);
            break;

        case MenuState::START_GAME:
            target.draw(frame1);
            break;

        case MenuState::INGAME:
            target.draw(frame1);
            // TODO 2 players
            target.draw(game);
            break;

        case MenuState::SETTINGS:
            target.draw(m_settings);
            break;

        default:
            break;
    }
}
