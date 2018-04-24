/* LineClearParticles.cpp */

#include <Global.h>
#include <core/LineClearParticles.h>

Core::LineClearParticles::LineClearParticles() : m_active(false), m_line(0) {
    #ifdef DEBUG
    std::cout << "LineClearParticles constructor" << std::endl;
    #endif
}

void Core::LineClearParticles::set_emitter(Core::Stack *stack, unsigned int line) {
    m_active = true;
    m_line = line;
    m_stack = stack;
}

bool Core::LineClearParticles::end() {
    m_active = false;
    return true;
}
