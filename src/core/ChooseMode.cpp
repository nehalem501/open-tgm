/* ChooseMode.cpp */

#include <TargetTypes.h>
#include <Global.h>
#include <MainMenu.h>
#include <Input.h>
#include <Text.h>
#include <ChooseMode.h>

Core::ChooseMode::ChooseMode() : m_selected(false),
                                 m_mode(0) {
    #ifdef DEBUG
    print("Choose mode screen constructor\n");
    #endif
}

void Core::ChooseMode::init(::Stack *stack) {
    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].init_graphics();
        m_modes_strings[i].update_pos(1, 7 + i * 2);
        m_modes_strings[i].update_text(modes[i]->name());
        // TODO use stack depending on player
        m_modes_strings[i].update_stack(stack);
        m_modes_strings[i].update_graphics();
    }

    // Highlight the first entry
    m_modes_strings[0].update_color(TextColor::YELLOW);
    m_modes_strings[0].update_graphics();
}

void Core::ChooseMode::update(int *state, int *mode) {
    // Mode selected, play animation before starting game
    if (input.a()) {
        //m_das_up = 4;
        //m_das_down = 0;
        m_selected = true;
        return;
    }

    // Playing animation
    if (m_selected) {
        m_das_up += 4;
        if (m_das_up == 0) {
            m_selected = false;
            m_das_up = 0;
            m_das_down = 0;
            *state = MainMenuState::START_GAME;
            *mode = m_mode;
            m_mode = 0;
            m_modes_strings[0].update_color(TextColor::YELLOW);
            m_modes_strings[0].update_graphics();
            return;
        }

        //m_das_down += 32;

        if (m_das_down > 127) {
            m_modes_strings[m_mode].update_color(TextColor::NONE);
        } else {
            m_modes_strings[m_mode].update_color(TextColor::YELLOW);
        }

        return;
    }

    if (input.menu_key_up()) {
        // Revert previous entry to normal color
        m_modes_strings[m_mode].update_color(TextColor::NONE);

        if (m_mode <= 0)
            m_mode = NB_MODES - 1;
        else
            m_mode--;

        // Highlight newly selected entry
        m_modes_strings[m_mode].update_color(TextColor::YELLOW);
    }

    if (input.menu_key_down()) {
        // Revert previous entry to normal color
        m_modes_strings[m_mode].update_color(TextColor::NONE);

        if (m_mode >= NB_MODES - 1)
            m_mode = 0;
        else
            m_mode++;

        // Highlight newly selected entry
        m_modes_strings[m_mode].update_color(TextColor::YELLOW);
    }
}
