/* Home.cpp */

#include <TargetTypes.h>
#include <Global.h>
#include <Input.h>
#include <Text.h>
#include <MainMenu.h>
#include <Home.h>

Home::Home() : m_start_timer(0) {
    #ifdef DEBUG
    print("Home screen constructor\n");
    #endif
    // TODO m_start
}

void Home::update(int *state) {
    m_start_timer += 2;

    if (input.start()) {
        *state = MainMenuState::CHOOSE_MODE;
    }
}

void Home::draw() const {
    // TODO
}