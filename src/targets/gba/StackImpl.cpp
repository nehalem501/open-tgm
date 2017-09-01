/* StackImpl.cpp - GBA */

#include "StackImpl.h"

void StackImpl::initGraphics() {
}

void StackImpl::updateGraphics() {
}

void StackImpl::draw() const {
    // Draw stack blocks and outline

    for (unsigned int i = 0; i < FILLED_LINES_NB; i++) {
        target.draw(m_part[i]);
    }
}
