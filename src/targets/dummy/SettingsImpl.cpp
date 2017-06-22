/* SettingsImpl.cpp - Dummy */

#include "SettingsImpl.h"

void SettingsImpl::initGraphics() {
    input_test_str.initGraphics();
    exit_str.initGraphics();
}

void SettingsImpl::draw() const {
    switch (m_state) {
        case SettingsState::LIST:
            input_test_str.draw();
            exit_str.draw();
            break;

        case SettingsState::INPUT_TEST:
            break;
    }
}
