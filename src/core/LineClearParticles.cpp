/* LineClearParticles.cpp */

#include <Global.h>
#include <Position.h>
#include <Debug.h>
#include <LineClearParticles.h>

LineClearParticles::LineClearParticles() : m_line(0), m_active(false) {
    printd("LineClearParticles constructor");
}

void LineClearParticles::set_emitter(const Position & /*parent*/, int line) {
    m_active = true;
    m_line = line;
    // TODO
}

bool LineClearParticles::end() {
    m_active = false;
    return true;
}

void LineClearParticles::draw() const {
    m_implementation.render();
}

