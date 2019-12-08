/* LineClearParticlesImpl.h - PS3 */

#ifndef LINE_CLEAR_PARTICLES_PS3_H
#define LINE_CLEAR_PARTICLES_PS3_H

#include <Position.h>

class LineClearParticlesImpl {
    public:
        void reset(Position& position);
        void update();
        void render() const;
};

#endif
