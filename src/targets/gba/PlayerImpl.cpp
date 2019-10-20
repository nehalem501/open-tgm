/* PlayerImpl.cpp - GBA */

#include <gba.h>
#include <Shapes.h>
#include <Piece.h>
#include <Player.h>
#include "PlayerImpl.h"

void PlayerImpl::update() {
}

void PlayerImpl::render() const {
    u16 *local_screen = (u16*) MAP_BASE_ADR(16) + 10;

    if (m_player.draw_ghost()) {
        // Draw ghost piece
    }

    if (m_player.draw_piece()) {
        // Draw player piece
        const Piece& piece = m_player.piece();
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                local_screen[
                    32 * (piece.position_y() - 3 + i)
                    + (piece.position_x() - 2 + j)] |=
                        PIECES[piece.type()][piece.orientation()][i][j];
            }
        }
    }

    // Draw next piece
    local_screen += 6;
    int x = 7;
    int y = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            local_screen[32 * (y - 1 + i) + (x - 2 + j)] =
                PIECES[m_player.get_next_piece()][0][i][j];
        }
    }
}
