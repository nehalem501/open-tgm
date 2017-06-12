/* BaseGame.cpp */

#include <stdint.h>
#include <Global.h>
#include <Player.h>
#include <Stack.h>
#include <../modes/modes.h>
#include <common/BaseGame.h>

void BaseGame::initGraphics() {
    timer1.initGraphics();
    //labels1.initGraphics();
#ifdef MULTIPLAYER
    timer2.initGraphics();
    //labels2.initGraphics();
#endif
}

void BaseGame::startPlayer1(int8_t mode) {
    // TODO choose mode
    stack1.startGame(modes[mode]);

    player1.init(&stack1, modes[mode]);
    player1.initGraphics();

    labels1.setMode(modes[mode]);
    labels1.initGraphics(&stack1);

    m_player1_state = GameState::INGAME;
}

#ifdef MULTIPLAYER
void BaseGame::startPlayer2(int8_t mode) {
    // TODO
    //player2.init(&stack2);
}

void BaseGame::startDoubles() {
    // TODO
    //player1.init(&stack1);
    //player2.init(&stack1);
}
#endif

void BaseGame::updateGameLogic() {
    switch(m_player1_state) {
        case GameState::INGAME:
            player1.update();
            /*if (player1.isGameOver()) {
              m_player1_state = GameState::GAME_OVER;
              }*/
            break;

        case GameState::READY_GO:
            // TODO
            break;

        case GameState::GAME_OVER:
            // TODO
            break;
    }

#ifdef MULTIPLAYER
    switch(m_player2_state) {
        case GameState::INGAME:
            player2.update();
            /*if (player2.isGameOver()) {
              m_player2_state = GameState::GAME_OVER;
              }*/
            break;

        case GameState::READY_GO:
            break;

        case GameState::GAME_OVER:
            break;
    }
#endif
}

void BaseGame::updateGraphics() {
    player1.updateGraphics();
    stack1.updateGraphics();

    timer1.updateGraphics();

#ifdef MULTIPLAYER
    player2.updateGraphics();
    stack2.updateGraphics();

    timer2.updateGraphics();
    level_display2.updateGraphics(&stack2);
    level_target_display2.updateGraphics(&stack2);
#endif
}

bool BaseGame::hasPlayer1Finished() {
    if (m_player1_state == GameState::FINISHED) {
        return true;
    } else {
        return false;
    }
}

#ifdef MULTIPLAYER
bool BaseGame::hasPlayer2Finished() {
    if (m_player2_state == GameState::FINISHED) {
        return true;
    } else {
        return false;
    }
}
#endif
