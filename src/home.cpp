/* home.cpp */

#include <stdint.h>

#include "menu.h"
#include "home.h"


Home::Home() : m_start_timer(0) {
    //cout << "Home screen constructor" << endl;
}

void Home::update(int8_t *state) {
    m_start_timer += 2;
    
    if (input.start()) {
        *state = MenuState::CHOOSE_MODE;
    }
}

