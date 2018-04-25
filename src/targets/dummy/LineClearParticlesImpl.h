/* LineClearParticlesImpl.h - Dummy */

#ifndef LINE_CLEAR_PARTICLES_DUMMY_H
#define LINE_CLEAR_PARTICLES_DUMMY_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void init();
        void draw() const;
};

#endif
