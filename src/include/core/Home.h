/* Home.h */

#ifndef CORE_HOME_H
#define CORE_HOME_H

#include <stdint.h>

namespace Core {
    class Home {
        public:
            Home();
            void update(int *state);

        protected:
            int8_t m_start_timer;
    };
}

#endif
