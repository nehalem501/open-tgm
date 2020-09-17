/* PlayerImpl.cpp - PSP */

//#include <glib2d.h>
#include <Shapes.h>
#include <Stack.h>
#include "GlobalPSP.h"
#include "PlayerImpl.h"

void PlayerImpl::init_graphics() {
}

void PlayerImpl::update_graphics() {
}

void PlayerImpl::draw() const {
    int pos_x = m_stack->m_pos_x;
    int pos_y = m_stack->m_pos_y;

    //g2dBeginQuads(tileset_tex);
    //g2dSetCropWH(10, 10);

    if (m_draw_ghost) {
        // Draw ghost piece
        //g2dSetAlpha(80);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int tile = PIECES[m_piece.type()][m_piece.orientation()][j][i];
                if (tile > 0) {
                    set_tile_piece(tile);

                    /*g2dSetCoordXY(pos_x + (m_piece.pos_x() - 2 + i) * 10, pos_y + (m_ghost_y - 1 + j) * 10);
                    g2dAdd();
                    g2dSetCoordXY(pos_x + ((m_piece.pos_x() - 2 + i) + 1) * 10, pos_y + (m_ghost_y - 1 + j) * 10);
                    g2dAdd();
                    g2dSetCoordXY(pos_x + ((m_piece.pos_x() - 2 + i) + 1) * 10, pos_y + ((m_ghost_y - 1 + j) + 1) * 10);
                    g2dAdd();
                    g2dSetCoordXY(pos_x + (m_piece.pos_x() - 2 + i) * 10, pos_y + ((m_ghost_y - 1 + j) + 1) * 10);
                    g2dAdd();*/
                }
            }
        }
    }

    if (m_draw_piece) {
        // Draw player piece

        int alpha = 255;
        if (m_lock > 0) {
            if ((float) m_lock >= 2.0 * (float) m_current_mode->lock(m_level) / 5.0)
                alpha = 210;

            if ((float) m_lock >= 3.0 * (float) m_current_mode->lock(m_level) / 5.0)
                alpha = 160;

            if ((float) m_lock >= 4.0 * (float) m_current_mode->lock(m_level) / 5.0)
                alpha = 128;

            if (m_lock == m_current_mode->lock(m_level))
                alpha = 96;
        }

        //g2dSetAlpha(alpha);

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int tile = PIECES[m_piece.type()][m_piece.orientation()][j][i];
                if (tile > 0) {
                    set_tile_piece(tile);

                    /*g2dSetCoordXY(pos_x + (m_piece.pos_x() - 2 + i) * 10, pos_y + (m_piece.pos_y() - 1 + j) * 10);
                    g2dAdd();
                    g2dSetCoordXY(pos_x + ((m_piece.pos_x() - 2 + i) + 1) * 10, pos_y + (m_piece.pos_y() - 1 + j) * 10);
                    g2dAdd();
                    g2dSetCoordXY(pos_x + ((m_piece.pos_x() - 2 + i) + 1) * 10, pos_y + ((m_piece.pos_y() - 1 + j) + 1) * 10);
                    g2dAdd();
                    g2dSetCoordXY(pos_x + (m_piece.pos_x() - 2 + i) * 10, pos_y + ((m_piece.pos_y() - 1 + j) + 1) * 10);
                    g2dAdd();*/
                }
            }
        }
    }

    // Draw next piece
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int tile = PIECES[m_next][0][j][i];
            if (tile > 0) {
                set_tile_piece(tile);

                /*g2dSetCoordXY(pos_x + (i + 3) * 10, pos_y - 5+ (j - 2) * 10);
                g2dAdd();
                g2dSetCoordXY(pos_x + (i + 4) * 10, pos_y - 5 + (j - 2) * 10);
                g2dAdd();
                g2dSetCoordXY(pos_x + (i + 4) * 10, pos_y - 5 + (j - 1) * 10);
                g2dAdd();
                g2dSetCoordXY(pos_x + (i + 3) * 10, pos_y - 5 + (j - 1) * 10);
                g2dAdd();*/
            }
        }
    }

    //g2dEnd();

    m_score_display.draw();
    m_level_display.draw();
    m_section_display.draw();
}
