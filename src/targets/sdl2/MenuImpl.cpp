/* MenuImpl.cpp - SDL2 */

#include <Global.h>
#include <Frame.h>
#include <Home.h>
#include <Background.h>
#include <Game.h>
#include "MenuImpl.h"

void MenuImpl::init_graphics() {
    m_home.init_graphics();
    m_choose_mode.init_graphics();
}

void MenuImpl::draw() const {
    background.draw();
    switch(m_state) {
        case MenuState::HOME:
            m_home.draw();
            break;

        case MenuState::CHOOSE_PLAYER:
            frame1.draw();
            //target.draw(dataNotUsed);
            //target.draw(newPlaiyer);
            //target.draw(loadPlayer);
            break;

        case MenuState::CHOOSE_MODE:
            frame1.draw();
            m_choose_mode.draw();
            break;

        case MenuState::START_GAME:
            frame1.draw();
            break;

        case MenuState::INGAME:
            frame1.draw();
            // TODO 2 players
            game.draw();
            break;

        case MenuState::SETTINGS:
            m_settings.draw();
            break;

        default:
            break;
    }
}
