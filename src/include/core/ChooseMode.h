/* ChooseMode.h */

#ifndef CORE_CHOOSE_MODE_H
#define CORE_CHOOSE_MODE_H

#include <TargetTypes.h>
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
            uint8_t m_das_up, m_das_down;
            ::Text m_modes_strings[NB_MODES];
    };
}

#endif
