/* Input.cpp */

#include <core/Input.h>

Core::Input::Input() : m_start(false),
                 m_settings(false),
                 m_up(false),
                 m_down(false),
                 m_left(false),
                 m_right(false),
                 m_a(false),
                 m_b(false),
                 m_c(false),
                 prev_up(false),
                 prev_down(false),
                 prev_left(false),
                 prev_right(false),
                 prev_a(false),
                 prev_c(false) {
    //cout << "Input constructor" << endl;
}
