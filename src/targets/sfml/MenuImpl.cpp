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

void MenuImpl::initGraphics() {
    m_home.initGraphics();
    m_chooseMode.initGraphics();
    m_settings.initGraphics();
}

void MenuImpl::updateSize() {
    tile_size = screen_size.y / TILE_RATIO;

    background.updateSize();

    m_home.updateSize();
    m_chooseMode.updateSize();
    m_settings.updateSize();
    // TODO check for multiplayer
    game.updateSize();
    frame1.updateSize(&stack1);
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
