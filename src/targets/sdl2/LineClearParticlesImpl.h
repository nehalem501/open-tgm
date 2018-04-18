/* LineClearParticlesImpl.h - SDL2 */

#ifndef LINE_CLEAR_PARTICLES_SDL2_H
#define LINE_CLEAR_PARTICLES_SDL2_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void draw() const;
};

#endif
