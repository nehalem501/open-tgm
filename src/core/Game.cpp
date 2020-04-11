/* Game.cpp */

#include <TargetTypes.h>
#include <Player.h>
#include <Stack.h>
#include <../modes/modes.h>
#include <Scene.h>
#include <Game.h>

Game::Game(Position &position) :
        m_position(position),
        m_frame(m_position),
        m_labels(),
        m_state(GameState::CHOOSE_MODE) {
    #ifdef DEBUG
    print("Game constructor\n");
    #endif
}

void Game::start(int mode) {
    m_stack.start_game(modes[mode]);
    m_player.init(&m_position, modes[mode]);
    m_labels.set_mode(modes[mode]);
    m_timer.start();

    ready_go();
}

void Game::ready_go() {
    m_state = GameState::READY_GO;
    m_counter = 0;

    // Display 'READY'
    m_string.text(READY_STR);
    // TODO
    m_string.position(Position(3, 11));
}

// TODO change how Scene is notified
void Game::update(int *scene_state) {
    switch(m_state) {
        case GameState::CHOOSE_MODE:
            int mode;
            if (m_choose_mode.update(&mode)) {
                start(mode);
            }
            break;

        case GameState::INGAME:
            m_timer.update();
            m_player.update(&m_stack, &m_state);
            break;

        case GameState::CREDIT_ROLL:
            m_player.update(&m_stack, &m_state);
            break;

        case GameState::READY_GO:
            // TODO
            m_counter++;

            #ifdef DEBUG
            print("player_counter (ready & go): %d\n", (int) m_counter);
            #endif

            // Display 'GO'
            if (m_counter > 60) {
                m_string.text(GO_STR);
                m_string.position(Position(4, 11));
            }

            // Start game
            if (m_counter == 120) {
                // Start timer and count current frame
                m_timer.start();
                m_timer.update();

                //m_p1_labels.init_graphics(m_p1_stack);

                // Start game for player 1
                m_player.start_game();
                m_player.update(&m_stack, &m_state);

                // Prepare counter for game over animation
                m_counter = m_stack.height() * 8;

                // First piece to spawn doesn't increase level
                m_player.reset_level();

                // Change state to Ingame
                m_state = GameState::INGAME;
                return;
            } else {
                // When we wait, we can still charge DAS
                m_player.update(&m_stack, &m_state);
            }
            break;

        case GameState::GAME_OVER_ANIM:
            m_counter--;

            // Animation finished, display 'GAME OVER'
            if (m_counter == 0) {
                m_counter = 0;
                m_string.text(GAME_OVER_STR);
                m_string.position(Position(1, 11));
                m_state = GameState::GAME_OVER_TEXT;
                return;
            }

            // Remove next line
            if (m_counter % 8 == 0) {
                m_stack.remove_line(m_counter / 8);
                m_stack.reset_outline();
            }

            break;

        case GameState::GAME_OVER_TEXT:
            m_counter++;

            if (m_counter == 160) {
                m_counter = 0;
                *scene_state = SceneState::HOME;
            }

            break;
    }
}

bool Game::has_ended() {
    if (m_state == GameState::FINISHED) {
        return true;
    } else {
        return false;
    }
}

void Game::draw() const {
    m_stack.draw();
    m_player.draw();

    m_timer.draw();
    m_labels.draw();

    switch (m_state) {
        case GameState::CHOOSE_MODE:
            m_choose_mode.draw();
            break;
        
        case GameState::READY_GO:
            m_string.draw();
            break;

        case GameState::GAME_OVER_ANIM:
            break;

        case GameState::GAME_OVER_TEXT:
            m_string.draw();
            break;
    }
}
