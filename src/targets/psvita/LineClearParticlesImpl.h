/* LineClearParticlesImpl.h - PSVita */

#ifndef LINE_CLEAR_PARTICLES_PSVITA_H
#define LINE_CLEAR_PARTICLES_PSVITA_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void init();
        void draw() const;
};

#endif
