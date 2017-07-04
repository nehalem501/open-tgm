/* Game.cpp */

#include <stdint.h>
#include <Global.h>
#include <Player.h>
#include <Stack.h>
#include <../modes/modes.h>
#include <core/Menu.h>
#include <core/Game.h>

void Core::Game::initGraphics() {
    timer1.initGraphics();
    m_p1_string.initGraphics();
#ifdef MULTIPLAYER
    timer2.initGraphics();
    m_p2_string.initGraphics();
#endif
}

void Core::Game::startPlayer1(int mode) {
    // TODO choose mode
    stack1.startGame(modes[mode]);

    player1.init(&stack1, modes[mode]);
    player1.initGraphics();

    labels1.setMode(modes[mode]);
    labels1.initGraphics(&stack1);

    timer1.init();

    p1_ready_go();
}

void Core::Game::p1_ready_go() {
    m_player1_state = GameState::READY_GO;
    m_p1_counter = 0;
    // Display 'READY'
    m_p1_string.update_text(READY_STR);
    m_p1_string.update_pos(18, 14);
    m_p1_string.updateGraphics();
}

#ifdef MULTIPLAYER
void Core::Game::startPlayer2(int8_t mode) {
    // TODO
    //player2.init(&stack2);
}

void Core::Game::startDoubles() {
    // TODO
    //player1.init(&stack1);
    //player2.init(&stack1);
}
#endif

void Core::Game::update(int *state) {
    switch(m_player1_state) {
        case GameState::INGAME:
            timer1.update();
            player1.update(&m_player1_state);
            break;

        case GameState::CREDIT_ROLL:
            player1.update(&m_player1_state);
            break;

        case GameState::READY_GO:
            // TODO
            m_p1_counter++;

            // Display 'GO'
            if (m_p1_counter > 60) {
                m_p1_string.update_text(GO_STR);
                m_p1_string.update_pos(19, 14);
                m_p1_string.updateGraphics();
            }

            // Start game
            if (m_p1_counter == 120) {
                // Start timer and count current frame
                timer1.start();
                timer1.update();

                labels1.initGraphics(&stack1);

                // Start game for player 1
                player1.startGame();
                player1.update(&m_player1_state);

                // Prepare counter for game over animation
                m_p1_counter = stack1.m_height * 8;

                // First piece to spawn doesn't increase level
                player1.reset_level();

                // Change state to Ingame
                m_player1_state = GameState::INGAME;
                return;
            }
            break;

        case GameState::GAME_OVER_ANIM:
            m_p1_counter--;

            // Animation finished, display 'GAME OVER'
            if (m_p1_counter == 0) {
                m_p1_counter = 0;
                m_p1_string.update_text(GAME_OVER_STR);
                m_p1_string.update_pos(16, 14);
                m_p1_string.updateGraphics();
                m_player1_state = GameState::GAME_OVER_TEXT;
                return;
            }

            // Remove next line
            if (m_p1_counter % 8 == 0)
                stack1.removeLine(m_p1_counter / 8);

            break;

        case GameState::GAME_OVER_TEXT:
            m_p1_counter++;

            if (m_p1_counter == 160) {
                m_p1_counter = 0;
                *state = MenuState::HOME;
            }

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

        case GameState::GAME_OVER_ANIM:
            // TODO
            break;

        case GameState::GAME_OVER_TEXT:
            // TODO
            break;
    }
#endif
}

void Core::Game::updateGraphics() {
    player1.updateGraphics();
    stack1.updateGraphics();

    timer1.updateGraphics();

#ifdef MULTIPLAYER
    player2.updateGraphics();
    stack2.updateGraphics();

    timer2.updateGraphics();
#endif
}

bool Core::Game::hasPlayer1Finished() {
    if (m_player1_state == GameState::FINISHED) {
        return true;
    } else {
        return false;
    }
}

#ifdef MULTIPLAYER
bool Core::Game::hasPlayer2Finished() {
    if (m_player2_state == GameState::FINISHED) {
        return true;
    } else {
        return false;
    }
}
#endif
