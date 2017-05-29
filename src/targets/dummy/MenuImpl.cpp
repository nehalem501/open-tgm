/* MenuImpl.cpp - Dummy */

#include <Global.h>
#include <Frame.h>
#include <Home.h>
#include <Background.h>
#include <Game.h>
#include "MenuImpl.h"

void MenuImpl::initGraphics() {
    m_home.initGraphics();
    m_chooseMode.initGraphics();
}

void MenuImpl::draw() const {
    background.draw();
    switch(m_state) {
        case MenuState::HOME:
            m_home.draw();
            break;

        case MenuState::CHOOSE_PLAYER:
            frame1.draw();
            break;

        case MenuState::CHOOSE_MODE:
            frame1.draw();/*
                               for (unsigned int i = 0; i < modesText.size(); i++) {
                               target.draw(modesText[i]);
                               }*/
            m_chooseMode.draw();
            break;

        case MenuState::START_GAME:
            frame1.draw();
            break;

        case MenuState::INGAME:
            frame1.draw();
            // TODO 2 players
            game.draw();
            break;

        default:
            break;
}

}
