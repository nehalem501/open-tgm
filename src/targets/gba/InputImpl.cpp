/* InputImpl.cpp - GBA */

#include <gba.h>
#include "InputImpl.h"

void InputImpl::init() {
}

void InputImpl::poll_inputs() {
    m_prev_joystick = m_curr_joystick;
    m_prev_buttons = m_curr_buttons;

    m_curr_joystick = 0x00;
    m_curr_buttons = 0x00;

    // Joystick
    if (~(REG_KEYINPUT) & KEY_UP)
        m_curr_joystick |= UP_BIT | RAW_UP_BIT;
    if (~(REG_KEYINPUT) & KEY_DOWN)
        m_curr_joystick |= DOWN_BIT | RAW_DOWN_BIT;
    if (~(REG_KEYINPUT) & KEY_LEFT)
        m_curr_joystick |= LEFT_BIT | RAW_LEFT_BIT;
    if (~(REG_KEYINPUT) & KEY_RIGHT)
        m_curr_joystick |= RIGHT_BIT | RAW_RIGHT_BIT;

    // Buttons
    if (~(REG_KEYINPUT) & KEY_B)
        m_curr_buttons |= A_BIT;
    if (~(REG_KEYINPUT) & KEY_A)
        m_curr_buttons |= B_BIT;
    if (~(REG_KEYINPUT) & KEY_R)
        m_curr_buttons |= C_BIT;
    if (~(REG_KEYINPUT) & KEY_START)
        m_curr_buttons |= START_BIT;
    if (~(REG_KEYINPUT) & KEY_SELECT)
        m_curr_buttons |= SETTINGS_BIT;

    process();
}
