/* ChooseMode.cpp */

#include <stdint.h>
#include <Global.h>
#include <Menu.h>
#include <Input.h>
#include <Text.h>
#include <core/ChooseMode.h>

Core::ChooseMode::ChooseMode() : m_selected(false), m_mode(0), m_das_up(0),
                                 m_das_down(0) {
    //std::cout << "Choose mode screen constructor" << std::endl;
}

void Core::ChooseMode::init() {
    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].init_graphics();
        m_modes_strings[i].update_pos(16, 7 + i * 2);
        m_modes_strings[i].update_text(modes[i]->name());
        m_modes_strings[i].update_graphics();
    }

    // Highlight the first entry
    m_modes_strings[0].update_color(TextColor::YELLOW);
    m_modes_strings[0].update_graphics();
}

void Core::ChooseMode::update(int *state, int *mode) {
    if (m_selected) {
        m_das_up += 4;
        if (m_das_up == 0) {
            m_selected = false;
            m_das_up = 0;
            m_das_down = 0;
            *state = MenuState::START_GAME;
            *mode = m_mode;
            m_mode = 0;
            m_modes_strings[0].update_color(TextColor::YELLOW);
            m_modes_strings[0].update_graphics();
            return;
        }

        m_das_down += 32;

        if (m_das_down > 127) {
            m_modes_strings[m_mode].update_color(TextColor::NONE);
        } else {
            m_modes_strings[m_mode].update_color(TextColor::YELLOW);
        }

        return;
    }

    // Mode selected, play animation before starting game
    if (input.a()) {
        m_das_up = 4;
        m_das_down = 0;
        m_selected = true;
        return;
    }

    if (input.up()) {
        if (m_das_up == 0) {
            // Revert previous entry to normal color
            m_modes_strings[m_mode].update_color(TextColor::NONE);

            if (m_mode <= 0)
                m_mode = NB_MODES - 1;
            else
                m_mode--;

            // Highlight newly selected entry
            m_modes_strings[m_mode].update_color(TextColor::YELLOW);
        }
        m_das_up += 16;
    } else {
        m_das_up = 0;
    }

    if (input.down()) {
        if (m_das_down == 0) {
            // Revert previous entry to normal color
            m_modes_strings[m_mode].update_color(TextColor::NONE);

            if (m_mode >= NB_MODES - 1)
                m_mode = 0;
            else
                m_mode++;

            // Highlight newly selected entry
            m_modes_strings[m_mode].update_color(TextColor::YELLOW);
        }
        m_das_down += 16;
    } else {
        m_das_down = 0;
    }
}
