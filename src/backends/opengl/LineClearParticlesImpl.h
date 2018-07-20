/* LineClearParticlesImpl.h - OpenGL */

#ifndef LINE_CLEAR_PARTICLES_OPENGL_H
#define LINE_CLEAR_PARTICLES_OPENGL_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void init();
        void draw() const;
};

#endif
