/* MainMainMenu.cpp */

#include <Global.h>
#include <Home.h>
#include <Input.h>
#include <Game.h>
#include <Background.h>
#include <core/MainMenu.h>

Core::MainMenu::MainMenu() : m_state(MainMenuState::HOME), m_mode(0) {
    #ifdef DEBUG
    print("MainMenu constructor\n");
    #endif

    m_stack1.init_graphics();
    
    m_frame1.init(&m_stack1);
    m_frame1.init_graphics();

    #ifdef MULTIPLAYER
    m_stack2.init_graphics();

    m_frame2.init(&m_stack2);
    m_frame2.init_graphics();
    #endif

    // TODO multiplayer
    m_choose_mode.init(&m_stack1);

    #ifdef MULTIPLAYER
    m_game.init(&m_stack1, &m_stack2);
    #else
    m_game.init(&m_stack1, NULL);
    #endif

    m_game.init_graphics();

    m_background.init_graphics();
}

void Core::MainMenu::update() {
    input.poll_inputs();

    switch(m_state) {
        case MainMenuState::HOME:
            if (input.settings()) {
                m_state = MainMenuState::SETTINGS;
                m_background.go_to_options();
                return;
            }
            m_home.update(&m_state);
            break;

        case MainMenuState::CHOOSE_MODE:
            m_choose_mode.update(&m_state, &m_mode);
            break;

        case MainMenuState::START_GAME:
            m_game.start_p1(m_mode);
            // TODO
            m_state = MainMenuState::INGAME;
            break;

        case MainMenuState::INGAME:
            // Update logic
            m_game.update(&m_state);

            m_game.update_graphics();
            //ingame();
            break;

        case MainMenuState::SETTINGS:
            m_settings.update(&m_state, &m_background);
            break;
    }
}
