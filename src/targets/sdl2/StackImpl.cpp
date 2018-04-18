/* StackImpl.cpp - SDL2 */

#include "StackImpl.h"

void StackImpl::init_graphics() {
}

void StackImpl::update_graphics() {
}

void StackImpl::draw() const {
    // Draw stack blocks and outline

    for (unsigned int i = 0; i < FILLED_LINES_NB; i++) {
        m_part[i].draw();
    }
}
