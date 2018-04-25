/* Input.cpp */

#include <stdint.h>
#include <Global.h>
#include <core/Input.h>

/* Is used to check if more than one direction is pressed */
static uint8_t input_lut[] = {
/* 0000 */ 0,
/* 0001 */ 0,
/* 0010 */ 0,
/* 0011 */ 1,
/* 0100 */ 0,
/* 0101 */ 1,
/* 0110 */ 1,
/* 0111 */ 1,
/* 1000 */ 0,
/* 1001 */ 1,
/* 1010 */ 1,
/* 1011 */ 1,
/* 1100 */ 1,
/* 1101 */ 1,
/* 1110 */ 1,
/* 1111 */ 1
};

Core::Input::Input() : m_curr_joystick(0x00),
                 m_prev_joystick(0x00),
                 m_curr_buttons(0x00),
                 m_prev_buttons(0x00),
                 m_autorepeat_up(0),
                 m_autorepeat_down(0) {
    #ifdef DEBUG
    print("Input constructor\n");
    #endif
}

#ifdef DEBUG
static void print_bits(uint8_t byte) {
    if (byte & 0x01)
        print("1");
    else
        print("0");

    if (byte & 0x02)
        print("1");
    else
        print("0");

    if (byte & 0x04)
        print("1");
    else
        print("0");

    if (byte & 0x08)
        print("1");
    else
        print("0");

    if (byte & 0x10)
        print("1");
    else
        print("0");

    if (byte & 0x20)
        print("1");
    else
        print("0");

    if (byte & 0x40)
        print("1");
    else
        print("0");

    if (byte & 0x80)
        print("1");
    else
        print("0");
}
#endif

void Core::Input::process() {
    // If UP and DOWN are pressed
    if ((m_curr_joystick & (UP_BIT | DOWN_BIT)) == (UP_BIT | DOWN_BIT)) {
        if ((m_prev_joystick & (RAW_UP_BIT | RAW_DOWN_BIT)) == (RAW_UP_BIT | RAW_DOWN_BIT)) {
            m_curr_joystick ^= ~(m_prev_joystick) & (UP_BIT | DOWN_BIT);
        } else if (m_prev_joystick & (UP_BIT | DOWN_BIT)) {
            m_curr_joystick ^= m_prev_joystick & (UP_BIT | DOWN_BIT);
    } else {
            m_curr_joystick &= ~(DOWN_BIT);
        }
    }

    // If LEFT and RIGHT are pressed
    if ((m_curr_joystick & (LEFT_BIT | RIGHT_BIT)) == (LEFT_BIT | RIGHT_BIT)) {
        if ((m_prev_joystick & (RAW_LEFT_BIT | RAW_RIGHT_BIT)) == (RAW_LEFT_BIT | RAW_RIGHT_BIT)) {
            m_curr_joystick ^= ~(m_prev_joystick) & (LEFT_BIT | RIGHT_BIT);
        } else if (m_prev_joystick & (LEFT_BIT | RIGHT_BIT)) {
            m_curr_joystick ^= m_prev_joystick & (LEFT_BIT | RIGHT_BIT);
        } else {
            m_curr_joystick &= ~(LEFT_BIT | RIGHT_BIT);
        }
    }

    // Check for diagonals
    if (input_lut[m_curr_joystick & CLEANED_INPUT]) {
        if ((m_curr_joystick & RAW_INPUT) != (m_prev_joystick & RAW_INPUT)) {
            uint8_t diff = (m_curr_joystick ^ m_prev_joystick) & CLEANED_INPUT;
            diff &= m_curr_joystick & CLEANED_INPUT;
            if (input_lut[diff]) {
                // TODO choose best solution
                //m_curr_joystick &= LEFT_BIT | RIGHT_BIT;
                m_curr_joystick &= ~(LEFT_BIT | RIGHT_BIT);
            } else {
                m_curr_joystick &= RAW_INPUT;
                m_curr_joystick |= diff;
            }
        } else {
            m_curr_joystick &= RAW_INPUT;
            m_curr_joystick |= m_prev_joystick & CLEANED_INPUT;
        }
    }

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

bool Core::Input::menu_key_up() {
    if (up()) {
        if (m_autorepeat_up == 0) {
            m_autorepeat_up += MENU_KEY_AUTOREPEAT;
            return true;
        } else {
            m_autorepeat_up += MENU_KEY_AUTOREPEAT;
            return false;
        }
    }

    m_autorepeat_up = 0;
    return false;
}

bool Core::Input::menu_key_down() {
    if (down()) {
        if (m_autorepeat_down == 0) {
            m_autorepeat_down += MENU_KEY_AUTOREPEAT;
            return true;
        } else {
            m_autorepeat_down += MENU_KEY_AUTOREPEAT;
            return false;
        }
    }

    m_autorepeat_down = 0;
    return false;
}

int Core::Input::irs() {
    if ((m_curr_buttons & A_BIT) || (m_curr_buttons & C_BIT)) {
        m_curr_buttons ^= ROT_L_BIT | ROT_R_BIT;
        return 1;
    }

    if (m_curr_buttons & B_BIT) {
        m_curr_buttons ^= ROT_L_BIT | ROT_R_BIT;
        return -1;
    }

    return 0;
}
