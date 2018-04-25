/* LineClearParticlesImpl.h - PSP */

#ifndef LINE_CLEAR_PARTICLES_PSP_H
#define LINE_CLEAR_PARTICLES_PSP_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void init();
        void draw() const;
};

#endif
