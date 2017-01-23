/* game.cpp */

#include "game.h"
#include "player.h"
#include "modes.h"

void Game::initGraphics() {
    timer1.initGraphics();
    labels1.initGraphics();
    level_display1.initGraphics();
    level_target_display1.initGraphics();
#ifdef MULTIPLAYER
    timer2.initGraphics();
    labels2.initGraphics();
    level_display2.initGraphics();
    level_target_display2.initGraphics();
#endif
}

void Game::startPlayer1() {
    // TODO choose mode
    stack1.startGame(&modes[Modes::TGM]);
    player1.init(&stack1, &modes[Modes::TGM]);
    m_player1_state = GameState::INGAME;
}

#ifdef MULTIPLAYER
void Game::startPlayer2() {
    // TODO
    //player2.init(&stack2);
}

void Game::startDoubles() {
    // TODO
    //player1.init(&stack1);
    //player2.init(&stack1);
}
#endif

void Game::updateGameLogic() {
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

void Game::updateGraphics() {
    player1.updateGraphics();
    stack1.updateGraphics();
    
    timer1.updateGraphics();
    level_display1.updateGraphics();
    level_target_display1.updateGraphics();
    
#ifdef MULTIPLAYER
    player2.updateGraphics();
    stack2.updateGraphics();
    
    timer2.updateGraphics();
    level_display2.updateGraphics();
    level_target_display2.updateGraphics();
#endif
}

bool Game::hasPlayer1Finished() {
    if (m_player1_state == GameState::FINISHED) {
        return true;
    } else {
        return false;
    }
}

#ifdef MULTIPLAYER
bool Game::hasPlayer2Finished() {
    if (m_player2_state == GameState::FINISHED) {
        return true;
    } else {
        return false;
    }
}
#endif



