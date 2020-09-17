/* PlayerImpl.cpp - GBA */

#include <gba.h>
#include <Shapes.h>
#include <Piece.h>
#include <Player.h>
#include "PlayerImpl.h"

void PlayerImpl::update_piece_type() {

}

void PlayerImpl::update_piece_position() {

}

void PlayerImpl::update_piece_lock_animation(
    unsigned int /*lock*/,
    unsigned int /*max*/) {

}

void PlayerImpl::update_piece_reset_lock() {

}

void PlayerImpl::update_ghost_type() {

}

void PlayerImpl::update_ghost_position() {

}

void PlayerImpl::update_next_type() {

}

void PlayerImpl::render() const {
    u16 *local_screen = (u16*) MAP_BASE_ADR(16) + 10;

    if (m_player.draw_ghost()) {
        // Draw ghost piece
    }

    if (m_player.draw_piece()) {
        // Draw player piece
        const Piece& piece = m_player.piece();
        for (int i = 0; i < PIECE_SIZE; i++) {
            for (int j = 0; j < PIECE_SIZE; j++) {
                local_screen[
                    32 * (piece.position_y() - 3 + i)
                    + (piece.position_x() - 2 + j)] |=
                        piece.tiles()[i + j * PIECE_SIZE];
            }
        }
    }

    // Draw next piece
    local_screen += 6;
    int x = 7;
    int y = 0;
    for (int i = 0; i < PIECE_SIZE; i++) {
        for (int j = 0; j < PIECE_SIZE; j++) {
            local_screen[32 * (y - 1 + i) + (x - 2 + j)] =
                PIECES[m_player.get_next_piece()][0][i + j * PIECE_SIZE];
        }
    }
}
