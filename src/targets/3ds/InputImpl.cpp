/* InputImpl.cpp - 3DS */

#include <3ds.h>
#include "InputImpl.h"

void InputImpl::init() {
}

void InputImpl::pollInputs() {
    // Read and store inputs

    m_prev_joystick = m_curr_joystick;
    m_prev_buttons = m_curr_buttons;

    m_curr_joystick = 0x00;
    m_curr_buttons = 0x00;

    u32 keys = hidKeysHeld();

    // Joystick
    if (keys & KEY_DUP)
        m_curr_joystick |= UP_BIT | RAW_UP_BIT;
    if (keys & KEY_DDOWN)
        m_curr_joystick |= DOWN_BIT | RAW_DOWN_BIT;
    if (keys & KEY_DLEFT)
        m_curr_joystick |= LEFT_BIT | RAW_LEFT_BIT;
    if (keys & KEY_DRIGHT)
        m_curr_joystick |= RIGHT_BIT | RAW_RIGHT_BIT;

    // Buttons
    if (keys & KEY_Y)
        m_curr_buttons |= A_BIT;
    if (keys & KEY_X || keys & KEY_B)
        m_curr_buttons |= B_BIT;
    if (keys & KEY_A)
        m_curr_buttons |= C_BIT;
    if (keys & KEY_START)
        m_curr_buttons |= START_BIT;
    if (keys & KEY_SELECT)
        m_curr_buttons |= SETTINGS_BIT;

    process();
}
