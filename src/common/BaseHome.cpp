/* BaseHome.cpp */

#include <stdint.h>
#include <Global.h>
#include <Input.h>
#include <Menu.h>
#include <common/BaseHome.h>

BaseHome::BaseHome() : m_start_timer(0) {
    //cout << "Home screen constructor" << endl;
}

void BaseHome::update(int8_t *state) {
    m_start_timer += 2;

    if (input.start()) {
        *state = MenuState::CHOOSE_MODE;
    }
}
