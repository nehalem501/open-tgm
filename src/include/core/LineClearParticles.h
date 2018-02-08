/* LineClearParticles.h */

#ifndef CORE_LINE_CLEAR_PARTICLES_H
#define CORE_LINE_CLEAR_PARTICLES_H

namespace Core {
    class LineClearParticles {
        public:
            LineClearParticles();
            void set_emitter(int position_x, int position_y);
            void update();
            void init();
            bool end();
            bool is_active();

        private:
            bool m_active;
    };
}

#endif
