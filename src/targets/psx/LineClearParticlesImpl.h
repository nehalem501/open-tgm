/* LineClearParticlesImpl.h - PSX */

#ifndef LINE_CLEAR_PARTICLES_PSX_H
#define LINE_CLEAR_PARTICLES_PSX_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void init();
        void draw() const;
};

#endif
