/* BaseLineClearParticles.h */

#ifndef BASE_LINE_CLEAR_PARTICLES_H
#define BASE_LINE_CLEAR_PARTICLES_H

#include <stdint.h>

class BaseLineClearParticles {
    public:
        BaseLineClearParticles();
        void setEmitter(uint8_t position_x, uint8_t position_y);
        void update();
        void init();
        bool end();
};

#endif
