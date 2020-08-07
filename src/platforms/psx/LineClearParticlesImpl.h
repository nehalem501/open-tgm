/* LineClearParticlesImpl.h - PSX */

#ifndef LINE_CLEAR_PARTICLES_PSX_H
#define LINE_CLEAR_PARTICLES_PSX_H

#include <Position.h>

class LineClearParticlesImpl {
    public:
        void reset(Position& position);
        void update();
        void render() const;
};

#endif
