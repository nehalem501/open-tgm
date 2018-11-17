/* MainMenuImpl.cpp - 3DS */

#include <Global.h>
#include <Frame.h>
#include <Home.h>
#include <Background.h>
#include <Game.h>
#include "MainMenuImpl.h"

void MainMenuImpl::init_graphics() {
    m_home.init_graphics();
    m_choose_mode.init_graphics();

    // TODO
    stack1.m_pos_x = (400 / 2) - (stack1.m_width / 2) * 9;
    stack1.m_pos_y = 3 * 9;
}

void MainMenuImpl::draw() const {
    m_background.draw();
    switch(m_state) {
        case MainMenuState::HOME:
            m_home.draw();
            break;

        case MainMenuState::CHOOSE_PLAYER:
            m_frame1.draw();
            //target.draw(dataNotUsed);
            //target.draw(newPlaiyer);
            //target.draw(loadPlayer);
            break;

        case MainMenuState::CHOOSE_MODE:
            m_frame1.draw();
            m_choose_mode.draw();
            break;

        case MainMenuState::START_GAME:
            m_frame1.draw();
            break;

        case MainMenuState::INGAME:
            m_frame1.draw();
            // TODO 2 players
            m_game.draw();
            break;

        case MainMenuState::SETTINGS:
            m_settings.draw();
            break;

        default:
            break;
    }
}
