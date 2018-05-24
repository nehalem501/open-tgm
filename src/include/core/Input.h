/* Input.h */

#ifndef CORE_INPUT_H
#define CORE_INPUT_H

#include <TargetTypes.h>

#define MENU_KEY_AUTOREPEAT 16

#define CLEANED_INPUT 0x0F
#define RAW_INPUT 0xF0

#define UP_BIT 0x01
#define DOWN_BIT 0x02
#define LEFT_BIT 0x04
#define RIGHT_BIT 0x08
#define RAW_UP_BIT 0x10
#define RAW_DOWN_BIT 0x20
#define RAW_LEFT_BIT 0x40
#define RAW_RIGHT_BIT 0x80

#define A_BIT 0x01
#define B_BIT 0x02
#define C_BIT 0x04
#define D_BIT 0x08
#define ROT_R_BIT 0x10
#define ROT_L_BIT 0x20
#define START_BIT 0x40
#define SETTINGS_BIT 0x80

namespace Core {
    class Input {
        protected:
            uint8_t m_curr_joystick;
            uint8_t m_prev_joystick;

            uint8_t m_curr_buttons;
            uint8_t m_prev_buttons;

            // Only for menus
            uint8_t m_autorepeat_up;
            uint8_t m_autorepeat_down;

            void process();

        public:
            Input();

            inline bool start() { return (m_curr_buttons & START_BIT); };
            inline bool settings() { return (m_curr_buttons & SETTINGS_BIT); };

            inline bool up() { return (m_curr_joystick & UP_BIT); };
            inline bool down() { return (m_curr_joystick & DOWN_BIT); };
            inline bool left() { return (m_curr_joystick & LEFT_BIT); };
            inline bool right() { return (m_curr_joystick & RIGHT_BIT); };

            inline bool raw_up() { return (m_curr_joystick & RAW_UP_BIT); };
            inline bool raw_down() { return (m_curr_joystick & RAW_DOWN_BIT); };
            inline bool raw_left() { return (m_curr_joystick & RAW_LEFT_BIT); };
            inline bool raw_right() { return (m_curr_joystick & RAW_RIGHT_BIT); };

            inline bool sonic_drop() { return (m_curr_joystick & UP_BIT); };

            inline bool rotate_right() { return (m_curr_buttons & ROT_R_BIT); };
            inline bool rotate_left() { return (m_curr_buttons & ROT_L_BIT); };

            inline bool a() { return (m_curr_buttons & A_BIT); };
            inline bool b() { return (m_curr_buttons & B_BIT); };
            inline bool c() { return (m_curr_buttons & C_BIT); };

            bool menu_key_up();
            bool menu_key_down();

            int irs();
    };
}

#endif
