/* MenuImpl.cpp - 3DS */

#include <Global.h>
#include <Frame.h>
#include <Home.h>
#include <Background.h>
#include <Game.h>
#include "MenuImpl.h"

void MenuImpl::init_graphics() {
    m_home.init_graphics();
    m_choose_mode.init_graphics();

    // TODO
    stack1.m_pos_x = (400 / 2) - (stack1.m_width / 2) * 9;
    stack1.m_pos_y = 3 * 9;
}

void MenuImpl::draw() const {
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
