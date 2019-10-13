/* LineClearParticles.h */

#ifndef LINE_CLEAR_PARTICLES_H
#define LINE_CLEAR_PARTICLES_H

#include <Position.h>
#include <LineClearParticlesImpl.h>

class LineClearParticles {
    public:
        LineClearParticles(const Position& parent);

        void draw();

        void set_emitter(unsigned int line);
        bool end();

        inline bool is_active() { return m_active; };

    private:
        int m_line;
        bool m_active;
        const Position& m_parent;

        LineClearParticlesImpl m_implementation;
};

#endif // LINE_CLEAR_PARTICLES_H
