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
    if (m_draw_ghost) {
        // Draw ghost piece
    }

    //if (m_draw_piece) {
        // Draw player piece
        u16 *local_screen = (u16*) MAP_BASE_ADR(16);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //x = pos_x + (m_piece.pos_x() - 2 + i) * tile_size
                //y = pos_y + (m_piece.pos_y() - 1 + j) * tile_size);

                local_screen[32 * (m_piece.pos_y() - 1 + j) + (m_piece.pos_x() - 2 + i)] = 5;
            }
        }
        //for (int i = 0; i < m_height - 2; i++) {
        //    memcpy(local_screen + 32 * i, m_field + m_width * (i + 2), m_width * 2);
        //}
    //}

    // Draw next piece

    m_score_display.draw();
    m_level_display.draw();
    m_section_display.draw();
}
