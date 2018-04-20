/* MainMenuImpl.cpp - PSP */

#include <glib2d.h>
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
    stack1.m_pos_x = (G2D_SCR_W / 2) - (stack1.m_width / 2) * 10;
    stack1.m_pos_y = 3 * 10;
}

void MainMenuImpl::draw() const {
    switch(m_state) {
        case MainMenuState::HOME:
            m_home.draw();
            break;

        case MainMenuState::CHOOSE_PLAYER:
            frame1.draw();
            //target.draw(dataNotUsed);
            //target.draw(newPlaiyer);
            //target.draw(loadPlayer);
            break;

        case MainMenuState::CHOOSE_MODE:
            frame1.draw();
            m_choose_mode.draw();
            break;

        case MainMenuState::START_GAME:
            frame1.draw();
            break;

        case MainMenuState::INGAME:
            frame1.draw();
            // TODO 2 players
            game.draw();
            break;

        case MainMenuState::SETTINGS:
            m_settings.draw();
            break;

        default:
            break;
    }
}
