/* LineClearParticlesImpl.h - PS3 */

#ifndef LINE_CLEAR_PARTICLES_PS3_H
#define LINE_CLEAR_PARTICLES_PS3_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void init();
        void draw() const;
};

#endif
