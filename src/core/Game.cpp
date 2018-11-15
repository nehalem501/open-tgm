/* Game.cpp */

#include <TargetTypes.h>
#include <Global.h>
#include <Player.h>
#include <Stack.h>
#include <../modes/modes.h>
#include <core/MainMenu.h>
#include <core/Game.h>

void Core::Game::init(::Stack *stack1,
                      ::Stack *stack2) {
    m_p1.init(stack1);
    m_p1_stack = stack1;

    #ifdef MULTIPLAYER
    m_p2.init(stack2);
    m_p2_stack = stack2;
    #endif
}

void Core::Game::init_graphics() {
    m_p1.init_graphics();
    m_p1_timer.init_graphics();
    m_p1_string.init_graphics();
    m_p1_string.update_stack(m_p1_stack);

    #ifdef MULTIPLAYER
    m_p1.init_graphics();
    m_p2_timer.init_graphics();
    m_p2_string.init_graphics();
    m_p2_string.update_stack(m_p2_stack);
    #endif
}

void Core::Game::start_p1(int mode) {
    // TODO choose mode
    m_p1_stack->start_game(modes[mode]);

    m_p1.init(m_p1_stack, modes[mode]);
    m_p1.init_graphics();

    m_p1_labels.set_mode(modes[mode]);
    m_p1_labels.init_graphics(m_p1_stack);

    m_p1_timer.init();

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
void Core::Game::start_p2(int mode) {
    // TODO
    //m_p2.init(&stack2);
}

void Core::Game::start_doubles() {
    // TODO
    //m_p1.init(&stack1);
    //m_p2.init(&stack1);
}
#endif

void Core::Game::update(int *state) {
    switch(m_p1_state) {
        case GameState::INGAME:
            m_p1_timer.update();
            m_p1.update(&m_p1_state);
            break;

        case GameState::CREDIT_ROLL:
            m_p1.update(&m_p1_state);
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
                m_p1_timer.start();
                m_p1_timer.update();

                m_p1_labels.init_graphics(m_p1_stack);

                // Start game for player 1
                m_p1.start_game();
                m_p1.update(&m_p1_state);

                // Prepare counter for game over animation
                m_p1_counter = m_p1_stack->m_height * 8;

                // First piece to spawn doesn't increase level
                m_p1.reset_level();

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
                m_p1_stack->remove_line(m_p1_counter / 8);
                m_p1_stack->reset_outline();
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
            m_p2.update();
            /*if (m_p2->isGameOver()) {
                m_p2_state = GameState::GAME_OVER;
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
    m_p1.update_graphics();
    m_p1_stack->update_graphics();

    m_p1_timer.update_graphics();

    #ifdef MULTIPLAYER
    m_p2.update_graphics();
    m_p2_stack2->update_graphics();

    m_p2_timer.update_graphics();
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
