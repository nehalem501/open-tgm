/* LineClearParticlesImpl.h - GBA */

#ifndef LINE_CLEAR_PARTICLES_GBA_H
#define LINE_CLEAR_PARTICLES_GBA_H

#include <Position.h>

class LineClearParticlesImpl {
    public:
        void reset(Position& position);
        void update();
        void render() const;
};

#endif
