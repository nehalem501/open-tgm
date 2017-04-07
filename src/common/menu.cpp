/* menu.cpp */

#include <iostream>
#include "menu.h"
#include "global.h"
#include "home.h"


using namespace std;

Menu::Menu() : m_state(MenuState::HOME) {
    //cout << "Menu constructor" << endl;
}

void Menu::update() {
    input.pollInputs();
    
    switch(m_state) {
        case MenuState::HOME:
            m_home.update(&m_state);
            break;

        case MenuState::CHOOSE_MODE:
            //chooseMode();
            //m_chooseMode.update(&m_state);
            m_state = MenuState::START_GAME;
            break;

        case MenuState::START_GAME:
            game.startPlayer1();
            // TODO
            m_state = MenuState::INGAME;
            break;

        case MenuState::INGAME:
            game.updateGameLogic();
            game.updateGraphics();
            //ingame();
            break;
    }
}
