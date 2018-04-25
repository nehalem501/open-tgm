/* Game.cpp */

#include <stdint.h>
#include <Global.h>
#include <Player.h>
#include <Stack.h>
#include <../modes/modes.h>
#include <core/MainMenu.h>
#include <core/Game.h>

void Core::Game::init_graphics() {
    m_timer1.init_graphics();
    m_p1_string.init_graphics();
    m_p1_string.update_stack(&stack1);

    #ifdef MULTIPLAYER
    m_timer2.init_graphics();
    m_p2_string.init_graphics();
    #endif
}

void Core::Game::start_p1(int mode) {
    // TODO choose mode
    stack1.start_game(modes[mode]);

    player1.init(&stack1, modes[mode]);
    player1.init_graphics();

    m_labels1.set_mode(modes[mode]);
    m_labels1.init_graphics(&stack1);

    m_timer1.init();

    p1_ready_go();
}

void Core::Game::p1_ready_go() {
    m_p1_state = GameState::READY_GO;
    m_p1_counter = 0;

    // Display 'READY'
    m_p1_string.update_text(READY_STR);
    m_p1_string.update_pos(3, 11);
    m_p1_string.update_graphics();
}

#ifdef MULTIPLAYER
void Core::Game::start_p2(int8_t mode) {
    // TODO
    //player2.init(&stack2);
}

void Core::Game::start_doubles() {
    // TODO
    //player1.init(&stack1);
    //player2.init(&stack1);
}
#endif

void Core::Game::update(int *state) {
    switch(m_p1_state) {
        case GameState::INGAME:
            m_timer1.update();
            player1.update(&m_p1_state);
            break;

        case GameState::CREDIT_ROLL:
            player1.update(&m_p1_state);
            break;

        case GameState::READY_GO:
            // TODO
            m_p1_counter++;

            #ifdef DEBUG
            print("p1_counter (ready & go): %d\n", (int) m_p1_counter);
            #endif

            // Display 'GO'
            if (m_p1_counter > 60) {
                m_p1_string.update_text(GO_STR);
                m_p1_string.update_pos(4, 11);
                m_p1_string.update_graphics();
            }

            // Start game
            if (m_p1_counter == 120) {
                // Start timer and count current frame
                m_timer1.start();
                m_timer1.update();

                m_labels1.init_graphics(&stack1);

                // Start game for player 1
                player1.start_game();
                player1.update(&m_p1_state);

                // Prepare counter for game over animation
                m_p1_counter = stack1.m_height * 8;

                // First piece to spawn doesn't increase level
                player1.reset_level();

                // Change state to Ingame
                m_p1_state = GameState::INGAME;
                return;
            }
            break;

        case GameState::GAME_OVER_ANIM:
            m_p1_counter--;

            // Animation finished, display 'GAME OVER'
            if (m_p1_counter == 0) {
                m_p1_counter = 0;
                m_p1_string.update_text(GAME_OVER_STR);
                m_p1_string.update_pos(1, 11);
                m_p1_string.update_graphics();
                m_p1_state = GameState::GAME_OVER_TEXT;
                return;
            }

            // Remove next line
            if (m_p1_counter % 8 == 0) {
                stack1.remove_line(m_p1_counter / 8);
                stack1.reset_outline();
            }

            break;

        case GameState::GAME_OVER_TEXT:
            m_p1_counter++;

            if (m_p1_counter == 160) {
                m_p1_counter = 0;
                *state = MainMenuState::HOME;
            }

            break;
    }

#ifdef MULTIPLAYER
    switch(m_p2_state) {
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

void Core::Game::update_graphics() {
    player1.update_graphics();
    stack1.update_graphics();

    m_timer1.update_graphics();

    #ifdef MULTIPLAYER
    player2.update_graphics();
    stack2.update_graphics();

    m_timer2.update_graphics();
    #endif
}

bool Core::Game::has_p1_finished() {
    if (m_p1_state == GameState::FINISHED) {
        return true;
    } else {
        return false;
    }
}

#ifdef MULTIPLAYER
bool Core::Game::has_p2_finished() {
    if (m_p2_state == GameState::FINISHED) {
        return true;
    } else {
        return false;
    }
}
#endif
