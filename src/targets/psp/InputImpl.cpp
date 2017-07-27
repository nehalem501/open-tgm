/* InputImpl.cpp - PSP */

#include <pspctrl.h>
#include "InputImpl.h"

void InputImpl::init() {
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
}

void InputImpl::pollInputs() {
    sceCtrlReadBufferPositive(&m_pad, 1);

    m_prev_joystick = m_curr_joystick;
    m_prev_buttons = m_curr_buttons;

    m_curr_joystick = 0x00;
    m_curr_buttons = 0x00;

    // TODO Read analog stick
    //m_pad.Lx
    //m_pad.Ly

    // Joystick
    if (m_pad.Buttons & PSP_CTRL_UP)
        m_curr_joystick |= UP_BIT | RAW_UP_BIT;
    if (m_pad.Buttons & PSP_CTRL_DOWN)
        m_curr_joystick |= DOWN_BIT | RAW_DOWN_BIT;
    if (m_pad.Buttons & PSP_CTRL_LEFT)
        m_curr_joystick |= LEFT_BIT | RAW_LEFT_BIT;
    if (m_pad.Buttons & PSP_CTRL_RIGHT)
        m_curr_joystick |= RIGHT_BIT | RAW_RIGHT_BIT;

    // Buttons
    if (m_pad.Buttons & PSP_CTRL_SQUARE) || (m_pad.Buttons & PSP_CTRL_LTRIGGER)
        m_curr_buttons |= A_BIT;
    if (m_pad.Buttons & PSP_CTRL_TRIANGLE) || (m_pad.Buttons & PSP_CTRL_CROSS) || (m_pad.Buttons & PSP_CTRL_RTRIGGER)
        m_curr_buttons |= B_BIT;
    if (m_pad.Buttons & PSP_CTRL_CIRCLE)
        m_curr_buttons |= C_BIT;
    if (m_pad.Buttons & PSP_CTRL_START)
        m_curr_buttons |= START_BIT;
    if (m_pad.Buttons & PSP_CTRL_SELECT)
        m_curr_buttons |= SETTINGS_BIT;

    process();
}
