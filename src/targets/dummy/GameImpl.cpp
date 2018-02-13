/* GameImpl.cpp - Dummy */

#include <Global.h>
#include <Stack.h>
#include <Player.h>
#include "GameImpl.h"

void GameImpl::draw() const {
    #warning "Dummy Game::draw not finished"
    player1.draw();
    stack1.draw();

    m_timer1.draw(); // TODO timer2
    m_labels1.draw();

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
