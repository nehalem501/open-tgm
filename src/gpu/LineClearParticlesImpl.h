/* LineClearParticlesImpl.h - GPU */

#ifndef LINE_CLEAR_PARTICLES_GPU_H
#define LINE_CLEAR_PARTICLES_GPU_H

#include <Position.h>

class LineClearParticlesImpl {
    public:
        void reset(Position& position);
        void update();
        void render() const;
};

#endif
