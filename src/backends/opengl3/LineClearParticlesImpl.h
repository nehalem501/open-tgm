/* LineClearParticlesImpl.h - OpenGL3 */

#ifndef LINE_CLEAR_PARTICLES_OPENGL3_H
#define LINE_CLEAR_PARTICLES_OPENGL3_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void init();
        void draw() const;
};

#endif
