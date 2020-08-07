/* PlayerImpl.cpp - PSX */

#include <Player.h>
#include "PlayerImpl.h"

void PlayerImpl::update() {
}

void PlayerImpl::render() const {
    if (m_player.draw_ghost()) {
        // Draw ghost piece
    }

    if (m_player.draw_piece()) {
        // Draw player piece
    }

    // Draw next piece
}
