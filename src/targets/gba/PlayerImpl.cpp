/* PlayerImpl.cpp - GBA */

#include <gba.h>
#include <Shapes.h>
#include <Piece.h>
#include "PlayerImpl.h"

void PlayerImpl::init_graphics() {
}

void PlayerImpl::update_graphics() {
}

void PlayerImpl::draw() const {
    u16 *local_screen = (u16*) MAP_BASE_ADR(16) + 10;

    if (m_draw_ghost) {
        // Draw ghost piece
    }

    if (m_draw_piece) {
        // Draw player piece
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                local_screen[32 * (m_piece.pos_y() - 1 + i) + (m_piece.pos_x() - 2 + j)] |= PIECES[m_piece.type()][m_piece.orientation()][i][j];
            }
        }
    }

    // Draw next piece
    local_screen -= 10;
    int x = 7;
    int y = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            local_screen[32 * (y - 1 + i) + (x - 2 + j)] = PIECES[m_next][0][i][j];
        }
    }

    m_score_display.draw();
    m_level_display.draw();
    m_section_display.draw();
}
