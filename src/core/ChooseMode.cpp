/* ChooseMode.cpp */

#include <stdint.h>
#include <Global.h>
#include <Menu.h>
#include <Input.h>
#include <Text.h>
#include <core/ChooseMode.h>

//TODO
#include <iostream>

Core::ChooseMode::ChooseMode() : m_selected(false), m_mode(0), m_DASup(0),
                               m_DASdown(0) {
    //std::cout << "Choose mode screen constructor" << std::endl;
}

void Core::ChooseMode::init() {
    // Highlight the first entry
    m_modes_strings[0].update_color(TextColor::YELLOW);

    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].update_pos(16, 7 + i * 2);
        m_modes_strings[i].update_text(modes[i]->name);
        m_modes_strings[i].updateGraphics();
    }
}

void Core::ChooseMode::update(int8_t *state, int8_t *mode) {
    if (m_selected) {
        m_DASup += 4;
        if (m_DASup == 0) {
            *state = MenuState::START_GAME;
            *mode = m_mode;
            return;
        }

        m_DASdown += 32;

        if (m_DASdown > 127) {
            m_modes_strings[m_mode].update_color(TextColor::NONE);
        } else {
            m_modes_strings[m_mode].update_color(TextColor::YELLOW);
        }

        return;
    }

    // Mode selected, play animation before starting game
    if (input.a()) {
        m_DASup = 4;
        m_DASdown = 0;
        m_selected = true;
        return;
    }

    if (input.up()) {
        if (m_DASup == 0) {
            // Revert previous entry to normal color
            m_modes_strings[m_mode].update_color(TextColor::NONE);

            if (m_mode <= 0)
                m_mode = NB_MODES - 1;
            else
                m_mode--;

            // Highlight newly selected entry
            m_modes_strings[m_mode].update_color(TextColor::YELLOW);
        }
        m_DASup += 16;
    } else {
        m_DASup = 0;
    }

    if (input.down()) {
        if (m_DASdown == 0) {
            // Revert previous entry to normal color
            m_modes_strings[m_mode].update_color(TextColor::NONE);

            if (m_mode >= NB_MODES - 1)
                m_mode = 0;
            else
                m_mode++;

            // Highlight newly selected entry
            m_modes_strings[m_mode].update_color(TextColor::YELLOW);
        }
        m_DASdown += 16;
    } else {
        m_DASdown = 0;
    }
}
