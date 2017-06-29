/* Home.cpp */

#include <stdint.h>
#include <Global.h>
#include <Input.h>
#include <Menu.h>
#include <core/Home.h>

Core::Home::Home() : m_start_timer(0) {
    //cout << "Home screen constructor" << endl;
}

void Core::Home::update(int *state) {
    m_start_timer += 2;

    if (input.start()) {
        *state = MenuState::CHOOSE_MODE;
    }
}
