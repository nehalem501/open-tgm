/* Home.cpp */

#include <stdint.h>
#include <Global.h>
#include <Input.h>
#include <MainMenu.h>
#include <core/Home.h>

Core::Home::Home() : m_start_timer(0) {
    #ifdef DEBUG
    print("Home screen constructor\n");
    #endif
}

void Core::Home::update(int *state) {
    m_start_timer += 2;

    if (input.start()) {
        *state = MainMenuState::CHOOSE_MODE;
    }
}
