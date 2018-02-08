/* BaseMenu.cpp */

#include <Global.h>
#include <Home.h>
#include <Input.h>
#include <Game.h>
#include <Background.h>
#include <core/Menu.h>

using namespace std;

Core::Menu::Menu() : m_state(MenuState::HOME), m_mode(0) {
    //cout << "Menu constructor" << endl;
}

void Core::Menu::update() {
    input.poll_inputs();

    switch(m_state) {
        case MenuState::HOME:
            if (input.settings()) {
                m_state = MenuState::SETTINGS;
                background.go_to_options();
                return;
            }
            m_home.update(&m_state);
            break;

        case MenuState::CHOOSE_MODE:
            m_choose_mode.update(&m_state, &m_mode);
            break;

        case MenuState::START_GAME:
            game.start_p1(m_mode);
            // TODO
            m_state = MenuState::INGAME;
            break;

        case MenuState::INGAME:
            // Update logic
            game.update(&m_state);

            game.update_graphics();
            //ingame();
            break;

        case MenuState::SETTINGS:
            m_settings.update(&m_state);
            break;
    }
}
