/* StackImpl.cpp - PSP */

#include <glib2d.h>
#include "GlobalPSP.h"
#include "StackImpl.h"

void StackImpl::initGraphics() {
}

void StackImpl::updateGraphics() {
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

    switch (m_active_particles) {
        case 1:
            m_part0.draw();
            break;

        case 2:
            m_part0.draw();
            m_part1.draw();
            break;

        case 3:
            m_part0.draw();
            m_part1.draw();
            m_part2.draw();
            break;

        case 4:
            m_part0.draw();
            m_part1.draw();
            m_part2.draw();
            m_part3.draw();
            break;
    }
}
