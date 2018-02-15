/* StackImpl.cpp - PSP */

#include <glib2d.h>
#include "GlobalPSP.h"
#include "StackImpl.h"

void StackImpl::init_graphics() {
}

void StackImpl::update_graphics() {
}

void StackImpl::draw() const {
    // Draw stack blocks
    g2dBeginQuads(tileset_tex);
    g2dSetCropWH(10, 10);
    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_height; ++j) {
            int tile = m_field[i + j * m_width];
            if (tile > 0) {
                set_tile_piece(tile);
                if (tile == 8) {
                    g2dSetColor(0xFFFFFFFF);
                } else {
                    g2dSetColor(0xFFC8C8C8);
                }

                g2dSetCoordXY(m_pos_x + i * 10, m_pos_y + j * 10);
                g2dAdd();
                g2dSetCoordXY(m_pos_x + (i + 1) * 10, m_pos_y + j * 10);
                g2dAdd();
                g2dSetCoordXY(m_pos_x + (i + 1) * 10, m_pos_y + (j + 1) * 10);
                g2dAdd();
                g2dSetCoordXY(m_pos_x + i * 10, m_pos_y + (j + 1) * 10);
                g2dAdd();
            }
        }
    }
    g2dEnd();

    // Draw outline
    g2dBeginQuads(outline_tex);
    g2dSetCropWH(10, 10);
    g2dSetColor(0x90FFFFFF);
    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_height; ++j) {
            int tile = m_outline[i + j * m_width];
            if (tile > 0) {
                set_tile_outline(tile);

                g2dSetCoordXY(m_pos_x + i * 10, m_pos_y + j * 10);
                g2dAdd();
                g2dSetCoordXY(m_pos_x + (i + 1) * 10, m_pos_y + j * 10);
                g2dAdd();
                g2dSetCoordXY(m_pos_x + (i + 1) * 10, m_pos_y + (j + 1) * 10);
                g2dAdd();
                g2dSetCoordXY(m_pos_x + i * 10, m_pos_y + (j + 1) * 10);
                g2dAdd();
            }
        }
    }
    g2dEnd();

    for (unsigned int i = 0; i < FILLED_LINES_NB; i++) {
        m_part[i].draw();
    }
}
