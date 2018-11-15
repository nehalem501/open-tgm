/* GameImpl.cpp - PSVita */

#include <Global.h>
#include <Stack.h>
#include <Player.h>
#include "GameImpl.h"

void GameImpl::draw() const {
    #warning "PSVita Game::draw not finished"
    m_p1->draw();
    m_p1_stack->draw();

    m_p1_timer.draw(); // TODO timer2
    m_p1_labels.draw();

    switch (m_p1_state) {
        case GameState::READY_GO:
            m_p1_string.draw();
            break;

        case GameState::GAME_OVER_ANIM:
            break;

        case GameState::GAME_OVER_TEXT:
            m_p1_string.draw();
            break;
    }
}
