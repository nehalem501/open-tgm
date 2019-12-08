/* LineClearParticlesImpl.h - PS2 */

#ifndef LINE_CLEAR_PARTICLES_PS2_H
#define LINE_CLEAR_PARTICLES_PS2_H

#include <Position.h>

class LineClearParticlesImpl {
    public:
        void reset(Position& position);
        void update();
        void render() const;
};

#endif
