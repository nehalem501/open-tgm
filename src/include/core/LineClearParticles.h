/* LineClearParticles.h */

#ifndef CORE_LINE_CLEAR_PARTICLES_H
#define CORE_LINE_CLEAR_PARTICLES_H

#include <stdint.h>

namespace Core {
    class LineClearParticles {
        public:
            LineClearParticles();
            void setEmitter(uint8_t position_x, uint8_t position_y);
            void update();
            void init();
            bool end();
    };
}

#endif
