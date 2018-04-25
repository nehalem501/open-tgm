/* LineClearParticlesImpl.h - GBA */

#ifndef LINE_CLEAR_PARTICLES_GBA_H
#define LINE_CLEAR_PARTICLES_GBA_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void init();
        void draw() const;
};

#endif
