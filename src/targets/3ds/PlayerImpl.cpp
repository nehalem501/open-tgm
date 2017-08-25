/* PlayerImpl.cpp - 3DS */

#include <3ds.h>
#include <citro3d.h>
#include <Shapes.h>
#include <Stack.h>
#include "Global3DS.h"
#include "PlayerImpl.h"

void PlayerImpl::initGraphics() {
}

void PlayerImpl::updateGraphics() {
}

void PlayerImpl::draw() const {
    int pos_x = m_stack->m_pos_x;
    int pos_y = m_stack->m_pos_y;

    C3D_TexBind(0, &tileset_tex);
    C3D_ImmDrawBegin(GPU_TRIANGLES);

    if (m_drawGhost) {
        // Draw ghost piece
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int tile = PIECES[m_piece.type][m_piece.orientation][j][i];
                if (tile > 0) {
                    tile--;

                    C3D_ImmSendAttrib(pos_x + (m_piece.pos_x - 2 + i) * 9, pos_y + (m_ghost_y - 1 + j) * 9, 0.5f, 0.0f);
                    C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y1, 0.0f, 0.0f);
                    C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 0.3125f);

                    C3D_ImmSendAttrib(pos_x + ((m_piece.pos_x - 2 + i) + 1) * 9, pos_y + ((m_ghost_y - 1 + j) + 1) * 9, 0.5f, 0.0f);
                    C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y2, 0.0f, 0.0f);
                    C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 0.3125f);

                    C3D_ImmSendAttrib(pos_x + ((m_piece.pos_x - 2 + i) + 1) * 9, pos_y + (m_ghost_y - 1 + j) * 9, 0.5f, 0.0f);
                    C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y1, 0.0f, 0.0f);
                    C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 0.3125f);

                    C3D_ImmSendAttrib(pos_x + (m_piece.pos_x - 2 + i) * 9, pos_y + (m_ghost_y - 1 + j) * 9, 0.5f, 0.0f);
                    C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y1, 0.0f, 0.0f);
                    C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 0.3125f);

                    C3D_ImmSendAttrib(pos_x + (m_piece.pos_x - 2 + i) * 9, pos_y + ((m_ghost_y - 1 + j) + 1) * 9, 0.5f, 0.0f);
                    C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y2, 0.0f, 0.0f);
                    C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 0.3125f);

                    C3D_ImmSendAttrib(pos_x + ((m_piece.pos_x - 2 + i) + 1) * 9, pos_y + ((m_ghost_y - 1 + j) + 1) * 9, 0.5f, 0.0f);
                    C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y2, 0.0f, 0.0f);
                    C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 0.3125f);
                }
            }
        }
    }

    if (m_drawPiece) {
        // Draw player piece
        float alpha = 1.0f;
        if (m_lock > 0) {
            if ((float) m_lock >= 2.0 * (float) m_current_mode->getLock(m_level) / 5.0)
                alpha = 0.8203125f;

            if ((float) m_lock >= 3.0 * (float) m_current_mode->getLock(m_level) / 5.0)
                alpha = 0.625f;

            if ((float) m_lock >= 4.0 * (float) m_current_mode->getLock(m_level) / 5.0)
                alpha = 0.5f;

            if (m_lock == m_current_mode->getLock(m_level))
                alpha = 0.375f;
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int tile = PIECES[m_piece.type][m_piece.orientation][j][i];
                if (tile > 0) {
                    tile--;

                    C3D_ImmSendAttrib(pos_x + (m_piece.pos_x - 2 + i) * 9, pos_y + (m_piece.pos_y - 1 + j) * 9, 0.5f, 0.0f);
                    C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y1, 0.0f, 0.0f);
                    C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, alpha);

                    C3D_ImmSendAttrib(pos_x + ((m_piece.pos_x - 2 + i) + 1) * 9, pos_y + ((m_piece.pos_y - 1 + j) + 1) * 9, 0.5f, 0.0f);
                    C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y2, 0.0f, 0.0f);
                    C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, alpha);

                    C3D_ImmSendAttrib(pos_x + ((m_piece.pos_x - 2 + i) + 1) * 9, pos_y + (m_piece.pos_y - 1 + j) * 9, 0.5f, 0.0f);
                    C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y1, 0.0f, 0.0f);
                    C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, alpha);

                    C3D_ImmSendAttrib(pos_x + (m_piece.pos_x - 2 + i) * 9, pos_y + (m_piece.pos_y - 1 + j) * 9, 0.5f, 0.0f);
                    C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y1, 0.0f, 0.0f);
                    C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, alpha);

                    C3D_ImmSendAttrib(pos_x + (m_piece.pos_x - 2 + i) * 9, pos_y + ((m_piece.pos_y - 1 + j) + 1) * 9, 0.5f, 0.0f);
                    C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y2, 0.0f, 0.0f);
                    C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, alpha);

                    C3D_ImmSendAttrib(pos_x + ((m_piece.pos_x - 2 + i) + 1) * 9, pos_y + ((m_piece.pos_y - 1 + j) + 1) * 9, 0.5f, 0.0f);
                    C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y2, 0.0f, 0.0f);
                    C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, alpha);
                }
            }
        }
    }

    // Draw next piece
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int tile = PIECES[m_next][0][j][i];
            if (tile > 0) {
                tile--;

                C3D_ImmSendAttrib(pos_x + (i + 3) * 9, pos_y - 4 + (j - 2) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y1, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

                C3D_ImmSendAttrib(pos_x + (i + 4) * 9, pos_y - 4 + (j - 1) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y2, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

                C3D_ImmSendAttrib(pos_x + (i + 4) * 9, pos_y - 4 + (j - 2) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y1, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

                C3D_ImmSendAttrib(pos_x + (i + 3) * 9, pos_y - 4 + (j - 2) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y1, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

                C3D_ImmSendAttrib(pos_x + (i + 3) * 9, pos_y - 4 + (j - 1) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y2, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

                C3D_ImmSendAttrib(pos_x + (i + 4) * 9, pos_y - 4 + (j - 1) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y2, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);
            }
        }
    }

    C3D_ImmDrawEnd();

    score_display.draw();
    level_display.draw();
    section_display.draw();
}
