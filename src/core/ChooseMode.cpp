/* ChooseMode.cpp */

#include <TargetTypes.h>
#include <Global.h>
#include <Input.h>
#include <Text.h>
#include <../modes/modes.h>
#include <Game.h>

ChooseMode::ChooseMode() :
        m_mode(0),
        m_selected(false) {
    #ifdef DEBUG
    print("Choose mode screen constructor\n");
    #endif

    for (int i = 0; i < NB_MODES; i++) {
        //m_modes_strings[i].init_graphics();
        m_modes_strings[i].position(Position(1, 7 + i * 2));
        m_modes_strings[i].text(modes[i]->name());
        // TODO use stack depending on player
        //m_modes_strings[i].update_stack(stack);
        //m_modes_strings[i].update_graphics();
    }

    // Highlight the first entry
    m_modes_strings[0].color(TextColor::YELLOW);
    //m_modes_strings[0].update_graphics();
}

bool ChooseMode::update(int *mode) {
    // TODO: remove, just to keep compiler happy
      *mode = m_mode;

    // Mode selected, play animation before starting game
    if (input.a()) {
        //m_das_up = 4;
        //m_das_down = 0;
        m_selected = true;
        return false;
    }

    // Playing animation
    if (m_selected) {
        /*m_das_up += 4;
        if (m_das_up == 0) {
            m_selected = false;
            m_das_up = 0;
            m_das_down = 0;
            *state = MainMenuState::START_GAME;
            *mode = m_mode;
            m_mode = 0;
            m_modes_strings[0].color(TextColor::YELLOW);
            //m_modes_strings[0].update_graphics();
            return true;
        }*/

        //m_das_down += 32;

        /*if (m_das_down > 127) {
            m_modes_strings[m_mode].color(TextColor::NONE);
        } else {
            m_modes_strings[m_mode].color(TextColor::YELLOW);
        }*/

        return false;
    }

    if (input.menu_key_up()) {
        // Revert previous entry to normal color
        m_modes_strings[m_mode].color(TextColor::NONE);

        if (m_mode <= 0)
            m_mode = NB_MODES - 1;
        else
            m_mode--;

        // Highlight newly selected entry
        m_modes_strings[m_mode].color(TextColor::YELLOW);
    }

    if (input.menu_key_down()) {
        // Revert previous entry to normal color
        m_modes_strings[m_mode].color(TextColor::NONE);

        if (m_mode >= NB_MODES - 1)
            m_mode = 0;
        else
            m_mode++;

        // Highlight newly selected entry
        m_modes_strings[m_mode].color(TextColor::YELLOW);
    }

    return false;
}

void ChooseMode::draw() const {
    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].draw();
    }
}
