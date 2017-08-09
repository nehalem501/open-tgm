/* PlayerImpl.cpp - PSP */

#include "PlayerImpl.h"

void PlayerImpl::initGraphics() {
}

void PlayerImpl::updateGraphics() {
}

void PlayerImpl::draw() const {
    if (m_drawGhost) {
        // Draw ghost piece
    }

    if (m_drawPiece) {
        // Draw player piece
    }

    // Draw next piece

    score_display.draw();
    level_display.draw();
    section_display.draw();
}
