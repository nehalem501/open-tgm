/* InputImpl.cpp - PSX */

#include "InputImpl.h"

void InputImpl::init() {
}

void InputImpl::poll_inputs() {
    // Read and store inputs

    m_prev_joystick = m_curr_joystick;
    m_prev_buttons = m_curr_buttons;

    m_curr_joystick = 0x00;
    m_curr_buttons = 0x00;

    // Joystick
    /*if (up)
        m_curr_joystick |= UP_BIT | RAW_UP_BIT;
    if (down)
        m_curr_joystick |= DOWN_BIT | RAW_DOWN_BIT;
    if (left)
        m_curr_joystick |= LEFT_BIT | RAW_LEFT_BIT;
    if (right)
        m_curr_joystick |= RIGHT_BIT | RAW_RIGHT_BIT;*/

    // Buttons
    /*if (a)
        m_curr_buttons |= A_BIT;
    if (b)
        m_curr_buttons |= B_BIT;
    if (c)
        m_curr_buttons |= C_BIT;
    if (start)
        m_curr_buttons |= START_BIT;
    if (settings)
        m_curr_buttons |= SETTINGS_BIT;*/

    process();
}
