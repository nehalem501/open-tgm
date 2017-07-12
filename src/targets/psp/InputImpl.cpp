/* InputImpl.cpp - PSP */

#include "InputImpl.h"

void InputImpl::init() {
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
}

void InputImpl::pollInputs() {
    sceCtrlReadBufferPositive(&m_pad, 1);

    // TODO Read analog stick
    //m_pad.Lx
    //m_pad.Ly

    m_up = m_pad.Buttons & PSP_CTRL_UP;
    m_down = m_pad.Buttons & PSP_CTRL_DOWN;
    m_left = m_pad.Buttons & PSP_CTRL_LEFT;
    m_right = m_pad.Buttons & PSP_CTRL_RIGHT;

    m_a = (m_pad.Buttons & PSP_CTRL_SQUARE)
          || (m_pad.Buttons & PSP_CTRL_LTRIGGER);
    m_b = (m_pad.Buttons & PSP_CTRL_TRIANGLE)
          || (m_pad.Buttons & PSP_CTRL_CROSS)
          || (m_pad.Buttons & PSP_CTRL_RTRIGGER);
    m_c = m_pad.Buttons & PSP_CTRL_CIRCLE;

    m_start = m_pad.Buttons & PSP_CTRL_START;
    m_settings = m_pad.Buttons & PSP_CTRL_SELECT;
}
