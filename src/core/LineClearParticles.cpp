/* LineClearParticles.cpp */

#include <stdint.h>
#include <core/LineClearParticles.h>

Core::LineClearParticles::LineClearParticles() {
    //#warning "LineClearParticle constructor not unimplemented"
    m_active = false;
}

void Core::LineClearParticles::set_emitter(int position_x, int position_y) {
    //#warning "LineClearParticle::setEmitter not unimplemented"
    m_active = true;
}

void Core::LineClearParticles::update() {
    //#warning "LineClearParticle::update not unimplemented"
}

void Core::LineClearParticles::init() {
    //#warning "LineClearParticle::init not unimplemented"
}

bool Core::LineClearParticles::end() {
    //#warning "LineClearParticle::end not unimplemented"
    m_active = false;
    return true;
}

bool Core::LineClearParticles::is_active() {
    return m_active;
}
