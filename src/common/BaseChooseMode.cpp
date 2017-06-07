/* BaseChooseMode.cpp */

#include <stdint.h>
#include <Global.h>
#include <Menu.h>
#include <Input.h>
#include <Text.h>
#include <common/BaseChooseMode.h>
#include <iostream>
BaseChooseMode::BaseChooseMode() : m_mode(0), m_DASup(0), m_DASdown(0) {
    //std::cout << "Choose mode screen constructor" << std::endl;
}

void BaseChooseMode::init() {
    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].update_pos(10, 5 + i);
        m_modes_strings[i].update_text(modes[i]->name);
        m_modes_strings[i].updateGraphics();
    }
}

void BaseChooseMode::update(int8_t *state) {
    if (input.a()) {
        *state = MenuState::START_GAME;
        return;
    }

    if (input.up()) {
        if (m_DASup == 0) {
            if (m_mode <= 0)
                m_mode = NB_MODES - 1;
            else
                m_mode--;
        }
        m_DASup += 8;
    } else {
        m_DASup = 0;
    }

    if (input.down()) {
        if (m_DASdown == 0) {
            if (m_mode >= NB_MODES - 1)
                m_mode = 0;
            else
                m_mode++;
        }
        m_DASdown += 8;
    } else {
        m_DASdown = 0;
    }
}
