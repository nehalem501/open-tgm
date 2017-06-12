/* BaseMenu.cpp */

#include <iostream>
#include <Global.h>
#include <Home.h>
#include <Input.h>
#include <Game.h>
#include <common/BaseMenu.h>

using namespace std;

BaseMenu::BaseMenu() : m_state(MenuState::HOME) {
    //cout << "Menu constructor" << endl;
}

void BaseMenu::update() {
    input.pollInputs();
    int8_t mode;

    switch(m_state) {
        case MenuState::HOME:
            m_home.update(&m_state);
            break;

        case MenuState::CHOOSE_MODE:
            m_chooseMode.update(&m_state, &mode);
            break;

        case MenuState::START_GAME:
            game.startPlayer1(mode);
            // TODO
            m_state = MenuState::INGAME;
            break;

        case MenuState::INGAME:
            game.updateGameLogic();
            game.updateGraphics();
            //ingame();
            break;

        case MenuState::SETTINGS_LIST:
            break;
    }
}
