/* PlayerImpl.cpp - Dummy */

#include <Player.h>
#include "PlayerImpl.h"

void PlayerImpl::update(const Player& player) {
}

void PlayerImpl::render() const {
    if (m_draw_ghost) {
        // Draw ghost piece
    }

    if (m_draw_piece) {
        // Draw player piece
    }

    // Draw next piece
}
