/* LineClearParticles.h */

#ifndef LINE_CLEAR_PARTICLES_H
#define LINE_CLEAR_PARTICLES_H

#include <Position.h>
#include <LineClearParticlesImpl.h>

class LineClearParticles {
    public:
        LineClearParticles();
        LineClearParticles(Position *parent);

        void draw();

        void set_emitter(unsigned int line);
        bool end();

        inline bool is_active() { return m_active; };

    private:
        Position *m_parent;
        int m_line;
        bool m_active;

        LineClearParticlesImpl m_implementation;
};

#endif // LINE_CLEAR_PARTICLES_H
