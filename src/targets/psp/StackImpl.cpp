/* StackImpl.cpp - PSP */

#include "StackImpl.h"

void StackImpl::initGraphics() {
}

void StackImpl::updateGraphics() {
}

void StackImpl::draw() const {
    // Draw stack blocks and outline

    switch (m_active_particles) {
        case 1:
            m_part0.draw();
            break;

        case 2:
            m_part0.draw();
            m_part1.draw();
            break;

        case 3:
            m_part0.draw();
            m_part1.draw();
            m_part2.draw();
            break;

        case 4:
            m_part0.draw();
            m_part1.draw();
            m_part2.draw();
            m_part3.draw();
            break;
    }
}
