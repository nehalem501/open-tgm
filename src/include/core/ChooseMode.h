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
            void update(int *state, int *mode);

        protected:
            bool m_selected;
            int m_mode;
            uint8_t m_DASup, m_DASdown;
            ::Text m_modes_strings[NB_MODES];
    };
}

#endif
