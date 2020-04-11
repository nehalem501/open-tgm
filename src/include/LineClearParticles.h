/* LineClearParticles.h */

#ifndef LINE_CLEAR_PARTICLES_H
#define LINE_CLEAR_PARTICLES_H

#include <Position.h>
#include <LineClearParticlesImpl.h>

class LineClearParticles {
    public:
        LineClearParticles();

        void draw() const;

        void set_emitter(const Position &parent, int line);
        bool end();

        inline bool is_active() { return m_active; };

    private:
        int m_line;
        bool m_active;

        LineClearParticlesImpl m_implementation;
};

#endif // LINE_CLEAR_PARTICLES_H
