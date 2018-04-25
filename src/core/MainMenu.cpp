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
}

void Core::MainMenu::update() {
    input.poll_inputs();

    switch(m_state) {
        case MainMenuState::HOME:
            if (input.settings()) {
                m_state = MainMenuState::SETTINGS;
                background.go_to_options();
                return;
            }
            m_home.update(&m_state);
            break;

        case MainMenuState::CHOOSE_MODE:
            m_choose_mode.update(&m_state, &m_mode);
            break;

        case MainMenuState::START_GAME:
            game.start_p1(m_mode);
            // TODO
            m_state = MainMenuState::INGAME;
            break;

        case MainMenuState::INGAME:
            // Update logic
            game.update(&m_state);

            game.update_graphics();
            //ingame();
            break;

        case MainMenuState::SETTINGS:
            m_settings.update(&m_state);
            break;
    }
}
