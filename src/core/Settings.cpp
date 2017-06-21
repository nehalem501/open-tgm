/* Settings.cpp */

#include <stdint.h>
#include <Global.h>
#include <Input.h>
#include <Menu.h>
#include <Text.h>
#include <core/Settings.h>

Core::Settings::Settings() : m_state(0), m_selected(0) {
    //cout << "Settings screen constructor" << endl;

    input_test_str.update_text(INPUT_TEST_STR);
    input_test_str.update_pos(5, 7);
    input_test_str.updateGraphics();
    input_test_str.update_color(TextColor::TRANSPARENT);

    exit_str.update_text(EXIT_STR);
    exit_str.update_pos(5, 9);
    exit_str.updateGraphics();
    exit_str.update_color(TextColor::TRANSPARENT);
}

void Core::Settings::init() {
    m_state = 0;
    m_selected = 0;

    // Text color
}

void Core::Settings::update(int8_t *menustate) {
    switch (m_state) {
        case SettingsState::LIST:
            if (input.up()) {
                if (m_selected <= 0)
                    m_selected = SettingsState::SETTINGS_NB - 1;
                else
                    m_selected--;
            }

            if (input.down()) {
                if (m_selected >= SettingsState::SETTINGS_NB - 1)
                    m_selected = 0;
                else
                    m_selected++;
            }

            if (input.a()) {
                switch (m_selected) {
                    // TODO replace Settings list Texts with array
                }
            }

            break;

        case SettingsState::INPUT_TEST:
            if (input.right() && input.a()) {
                m_state = SettingsState::LIST;
            }
            break;
    }
}
