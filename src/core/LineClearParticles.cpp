/* LineClearParticles.cpp */

#include <Global.h>
#include <LineClearParticles.h>

LineClearParticles::LineClearParticles() : m_line(0), m_active(false) {
    #ifdef DEBUG
    print("LineClearParticles constructor\n");
    #endif
}

LineClearParticles::LineClearParticles(Position *parent) :
        m_parent(parent),
        m_line(0),
        m_active(false) {
    #ifdef DEBUG
    print("LineClearParticles constructor\n");
    #endif
}

void LineClearParticles::set_emitter( unsigned int line) {
    m_active = true;
    m_line = line;
}

bool LineClearParticles::end() {
    m_active = false;
    return true;
}

void LineClearParticles::draw() const {
    m_implementation.render();
}