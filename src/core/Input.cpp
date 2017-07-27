/* Input.cpp */

#include <core/Input.h>

Core::Input::Input() : m_curr_joystick(0x00),
                 m_prev_joystick(0x00),
                 m_curr_buttons(0x00),
                 m_prev_buttons(0x00) {
    //cout << "Input constructor" << endl;
}

void Core::Input::process() {
    if ((m_curr_joystick & (UP_BIT | DOWN_BIT)) == (UP_BIT | DOWN_BIT)) {
        if ((m_prev_joystick & (RAW_UP_BIT | RAW_DOWN_BIT)) == (RAW_UP_BIT | RAW_DOWN_BIT)) {
            m_curr_joystick ^= ~(m_prev_joystick) & (UP_BIT | DOWN_BIT);
        } else if (m_prev_joystick & (UP_BIT | DOWN_BIT)) {
            m_curr_joystick ^= m_prev_joystick & (UP_BIT | DOWN_BIT);
    } else {
            m_curr_joystick &= ~(DOWN_BIT);
        }
    }

    if ((m_curr_joystick & (LEFT_BIT | RIGHT_BIT)) == (LEFT_BIT | RIGHT_BIT)) {
        if ((m_prev_joystick & (RAW_LEFT_BIT | RAW_RIGHT_BIT)) == (RAW_LEFT_BIT | RAW_RIGHT_BIT)) {
            m_curr_joystick ^= ~(m_prev_joystick) & (LEFT_BIT | RIGHT_BIT);
        } else if (m_prev_joystick & (LEFT_BIT | RIGHT_BIT)) {
            m_curr_joystick ^= m_prev_joystick & (LEFT_BIT | RIGHT_BIT);
        } else {
            m_curr_joystick &= ~(LEFT_BIT | RIGHT_BIT);
        }
    }

    // TODO diagonals

    if ((m_curr_buttons & A_BIT)) {
        if (!(m_prev_buttons & A_BIT))
            m_curr_buttons |= ROT_L_BIT;
    }

    if ((m_curr_buttons & B_BIT)) {
        if (!(m_prev_buttons & B_BIT))
            m_curr_buttons |= ROT_R_BIT;
    }

    if ((m_curr_buttons & C_BIT)) {
        if (!(m_prev_buttons & C_BIT))
            m_curr_buttons |= ROT_L_BIT;
    }

    if ((m_curr_buttons & (ROT_L_BIT | ROT_R_BIT)) == (ROT_L_BIT | ROT_R_BIT)) {
        m_curr_buttons ^= ROT_R_BIT;
    }


    /*if ((m_curr_joystick & 0xF0) != (m_prev_joystick & 0xF0)) {
        uint8_t curr_4way = m_curr_joystick & 0xF0;
        if (curr_4way & (UP_BIT | DOWN_BIT) && curr_4way & (LEFT_BIT | RIGHT_BIT)) {
            m_curr_joystick ^= curr_4way & (m_prev_joystick & 0xF0);
        }

        curr_4way = m_curr_joystick & 0xF0;
        if (curr_4way & (UP_BIT | DOWN_BIT) && curr_4way & (LEFT_BIT | RIGHT_BIT)) {
            m_curr_joystick &= ~(LEFT_BIT | RIGHT_BIT);
        }
    }*/
}

int Core::Input::IRS() {
    if ((m_curr_buttons & A_BIT) || (m_curr_buttons & C_BIT))
        return 1;

    if (m_curr_buttons & B_BIT)
        return -1;

    return 0;
}
