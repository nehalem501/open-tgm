/* LineClearParticlesImpl.h - 3DS */

#ifndef LINE_CLEAR_PARTICLES_3DS_H
#define LINE_CLEAR_PARTICLES_3DS_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void init();
        void draw() const;
};

#endif
