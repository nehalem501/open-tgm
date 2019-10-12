/* Home.cpp */

#include <TargetTypes.h>
#include <Global.h>
#include <Input.h>
#include <Text.h>
#include <MainMenu.h>
#include <core/Home.h>

Core::Home::Home() : m_start_timer(0) {
    #ifdef DEBUG
    print("Home screen constructor\n");
    #endif
    // TODO m_start
}

void Core::Home::update(int *state) {
    m_start_timer += 2;

    if (input.start()) {
        *state = MainMenuState::CHOOSE_MODE;
    }
}
