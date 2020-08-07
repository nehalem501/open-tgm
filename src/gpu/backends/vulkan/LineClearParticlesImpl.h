/* LineClearParticlesImpl.h - Vulkan */

#ifndef LINE_CLEAR_PARTICLES_VULKAN_H
#define LINE_CLEAR_PARTICLES_VULKAN_H

#include <core/LineClearParticles.h>

class LineClearParticlesImpl : public Core::LineClearParticles {
    public:
        void init();
        void draw() const;
};

#endif
