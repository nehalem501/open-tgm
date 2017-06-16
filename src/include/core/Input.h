/* Input.h */

#ifndef CORE_INPUT_H
#define CORE_INPUT_H

namespace Core {
    class Input {
        protected:
            bool m_start, m_settings, m_up, m_down, m_left, m_right;
            bool m_a, m_b, m_c;
            bool prev_up, prev_down, prev_left, prev_right, prev_a, prev_c;

        public:
            Input();

            inline bool start() { return m_start; };
            inline bool settings() { return m_settings; };

            inline bool up() { return m_up; };
            inline bool down() { return m_down; };
            inline bool left() { return m_left; };
            inline bool right() { return m_right; };

            inline bool drop() { return m_up; };

            inline bool rotateRight() { return m_b; };
            inline bool rotateLeft() { return m_a; }; //TODO m_c

            inline bool a() { return m_a; };
            inline bool b() { return m_b; };
            inline bool c() { return m_c; };
    };
}

#endif
