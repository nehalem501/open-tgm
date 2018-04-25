/* LineClearParticlesImpl.h - SDL */

#ifndef LINE_CLEAR_PARTICLES_SDL_H
#define LINE_CLEAR_PARTICLES_SDL_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void init();
        void draw() const;
};

#endif
