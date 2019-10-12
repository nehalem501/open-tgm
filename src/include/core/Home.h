/* Home.h */

#ifndef CORE_HOME_H
#define CORE_HOME_H

#include <TargetTypes.h>
#include <Text.h>

namespace Core {
    class Home {
        public:
            Home();
            void update(int *state);

        protected:
            ::Text m_start;
            int8_t m_start_timer;
    };
}

#endif
