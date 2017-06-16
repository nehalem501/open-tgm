/* ChooseMode.h */

#ifndef CORE_CHOOSE_MODE_H
#define CORE_CHOOSE_MODE_H

#include <stdint.h>
#include <Text.h>
#include <../modes/modes.h>

namespace Core {
    class ChooseMode {
        public:
            ChooseMode();
            void init();
            void update(int8_t *state, int8_t *mode);

        protected:
            bool m_selected;
            int8_t m_mode;
            uint8_t m_DASup, m_DASdown;
            ::Text m_modes_strings[NB_MODES];
    };
}

#endif
