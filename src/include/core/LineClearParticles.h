/* LineClearParticles.h */

#ifndef CORE_LINE_CLEAR_PARTICLES_H
#define CORE_LINE_CLEAR_PARTICLES_H

namespace Core {
    /* Forward declaration to avoid dependency hell */
    class Stack;

    class LineClearParticles {
        public:
            LineClearParticles();
            void set_emitter(Core::Stack *stack, unsigned int line);
            bool end();
            inline bool is_active() { return m_active; };

        protected:
            bool m_active;
            int m_line;
            Core::Stack *m_stack;
    };
}

#endif
