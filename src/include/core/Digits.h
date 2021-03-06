/* Digits.h */

#ifndef CORE_DIGITS_H
#define CORE_DIGITS_H

#include <TargetTypes.h>

namespace Core {
    class Digits {
        public:
            Digits();

            void init(int pos_x, int pos_y);
            void update(uint32_t number);

        protected:
            uint32_t m_value;
            int m_pos_x, m_pos_y;
            bool m_has_changed;
    };
}

#endif
