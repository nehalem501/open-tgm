/* LineClearParticlesImpl.h - PS2 */

#ifndef LINE_CLEAR_PARTICLES_PS2_H
#define LINE_CLEAR_PARTICLES_PS2_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void init();
        void draw() const;
};

#endif
