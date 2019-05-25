/* StackImpl.cpp - 3DS */

#include <Shapes.h>
#include "Global3DS.h"
#include "StackImpl.h"

#define T_SZ (9.0f / 64.0f)

struct tex_coord tileset_coord[] = {
    {0.0f * T_SZ, 0.0f * T_SZ, 1.0f * T_SZ, 1.0f * T_SZ},
    {1.0f * T_SZ, 0.0f * T_SZ, 2.0f * T_SZ, 1.0f * T_SZ},
    {2.0f * T_SZ, 0.0f * T_SZ, 3.0f * T_SZ, 1.0f * T_SZ},
    {3.0f * T_SZ, 0.0f * T_SZ, 4.0f * T_SZ, 1.0f * T_SZ},
    {4.0f * T_SZ, 0.0f * T_SZ, 5.0f * T_SZ, 1.0f * T_SZ},
    {5.0f * T_SZ, 0.0f * T_SZ, 6.0f * T_SZ, 1.0f * T_SZ},
    {6.0f * T_SZ, 0.0f * T_SZ, 7.0f * T_SZ, 1.0f * T_SZ},

    {0.0f * T_SZ, 1.0f * T_SZ, 1.0f * T_SZ, 2.0f * T_SZ},
    {1.0f * T_SZ, 1.0f * T_SZ, 2.0f * T_SZ, 2.0f * T_SZ},
    {2.0f * T_SZ, 1.0f * T_SZ, 3.0f * T_SZ, 2.0f * T_SZ},
    {3.0f * T_SZ, 1.0f * T_SZ, 4.0f * T_SZ, 2.0f * T_SZ},
    {4.0f * T_SZ, 1.0f * T_SZ, 5.0f * T_SZ, 2.0f * T_SZ},
    {5.0f * T_SZ, 1.0f * T_SZ, 6.0f * T_SZ, 2.0f * T_SZ},
    {6.0f * T_SZ, 1.0f * T_SZ, 7.0f * T_SZ, 2.0f * T_SZ},

    {0.0f * T_SZ, 2.0f * T_SZ, 1.0f * T_SZ, 3.0f * T_SZ},
    {1.0f * T_SZ, 2.0f * T_SZ, 2.0f * T_SZ, 3.0f * T_SZ},
    {2.0f * T_SZ, 2.0f * T_SZ, 3.0f * T_SZ, 3.0f * T_SZ},
    {3.0f * T_SZ, 2.0f * T_SZ, 4.0f * T_SZ, 3.0f * T_SZ},
    {4.0f * T_SZ, 2.0f * T_SZ, 5.0f * T_SZ, 3.0f * T_SZ},
    {5.0f * T_SZ, 2.0f * T_SZ, 6.0f * T_SZ, 3.0f * T_SZ},
    {6.0f * T_SZ, 2.0f * T_SZ, 7.0f * T_SZ, 3.0f * T_SZ},

    {0.0f * T_SZ, 3.0f * T_SZ, 1.0f * T_SZ, 4.0f * T_SZ},
    {1.0f * T_SZ, 3.0f * T_SZ, 2.0f * T_SZ, 4.0f * T_SZ},
    {2.0f * T_SZ, 3.0f * T_SZ, 3.0f * T_SZ, 4.0f * T_SZ},
    {3.0f * T_SZ, 3.0f * T_SZ, 4.0f * T_SZ, 4.0f * T_SZ},
    {4.0f * T_SZ, 3.0f * T_SZ, 5.0f * T_SZ, 4.0f * T_SZ},
    {5.0f * T_SZ, 3.0f * T_SZ, 6.0f * T_SZ, 4.0f * T_SZ},
    {6.0f * T_SZ, 3.0f * T_SZ, 7.0f * T_SZ, 4.0f * T_SZ},

    {0.0f * T_SZ, 4.0f * T_SZ, 1.0f * T_SZ, 5.0f * T_SZ},
    {1.0f * T_SZ, 4.0f * T_SZ, 2.0f * T_SZ, 5.0f * T_SZ},
    {2.0f * T_SZ, 4.0f * T_SZ, 3.0f * T_SZ, 5.0f * T_SZ},
    {3.0f * T_SZ, 4.0f * T_SZ, 4.0f * T_SZ, 5.0f * T_SZ},
};
struct tex_coord outline_coord[] = {
    {0.0f, 0.0f, T_SZ, T_SZ},
    {T_SZ, 0.0f, 2.0f * T_SZ, T_SZ},
    {2.0f * T_SZ, 0.0f, 3.0f * T_SZ, T_SZ},
    {3.0f * T_SZ, 0.0f, 4.0f * T_SZ, T_SZ},

    {0.0f, T_SZ, T_SZ, 2.0f * T_SZ},
    {T_SZ, T_SZ, 2.0f * T_SZ, 2.0f * T_SZ},
    {2.0f * T_SZ, T_SZ, 3.0f * T_SZ, 2.0f * T_SZ},
    {3.0f * T_SZ, T_SZ, 4.0f * T_SZ, 2.0f * T_SZ},

    {0.0f, 2.0f * T_SZ, T_SZ, 3.0f * T_SZ},
    {T_SZ, 2.0f * T_SZ, 2.0f * T_SZ, 3.0f * T_SZ},
    {2.0f * T_SZ, 2.0f * T_SZ, 3.0f * T_SZ, 3.0f * T_SZ},
    {3.0f * T_SZ, 2.0f * T_SZ, 4.0f * T_SZ, 3.0f * T_SZ},

    {0.0f, 3.0f * T_SZ, T_SZ, 4.0f * T_SZ},
    {T_SZ, 3.0f * T_SZ, 2.0f * T_SZ, 4.0f * T_SZ},
    {2.0f * T_SZ, 3.0f * T_SZ, 3.0f * T_SZ, 4.0f * T_SZ},
    {3.0f * T_SZ, 3.0f * T_SZ, 4.0f * T_SZ, 4.0f * T_SZ},
};

void StackImpl::init_graphics() {
}

void StackImpl::update_graphics() {
}

void StackImpl::draw() const {
    // Draw stack blocks
    C3D_TexBind(0, &tileset_tex);
    C3D_ImmDrawBegin(GPU_TRIANGLES);
    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_height; ++j) {
            int tile = m_field[i + j * m_width];
            if (tile & Block::BLINK_BIT) {
                tile = Block::BLINK;
                C3D_ImmSendAttrib(m_pos_x + i * 9, m_pos_y + j * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y1, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

                C3D_ImmSendAttrib(m_pos_x + (i + 1) * 9, m_pos_y + (j + 1) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y2, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

                C3D_ImmSendAttrib(m_pos_x + (i + 1) * 9, m_pos_y + j * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y1, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

                C3D_ImmSendAttrib(m_pos_x + i * 9, m_pos_y + j * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y1, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

                C3D_ImmSendAttrib(m_pos_x + i * 9, m_pos_y + (j + 1) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y2, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);

                C3D_ImmSendAttrib(m_pos_x + (i + 1) * 9, m_pos_y + (j + 1) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y2, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 1.0f);
            } else {
                C3D_ImmSendAttrib(m_pos_x + i * 9, m_pos_y + j * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y1, 0.0f, 0.0f);
                C3D_ImmSendAttrib(0.78125f, 0.78125f, 0.78125f, 1.0f);

                C3D_ImmSendAttrib(m_pos_x + (i + 1) * 9, m_pos_y + (j + 1) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y2, 0.0f, 0.0f);
                C3D_ImmSendAttrib(0.78125f, 0.78125f, 0.78125f, 1.0f);

                C3D_ImmSendAttrib(m_pos_x + (i + 1) * 9, m_pos_y + j * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y1, 0.0f, 0.0f);
                C3D_ImmSendAttrib(0.78125f, 0.78125f, 0.78125f, 1.0f);

                C3D_ImmSendAttrib(m_pos_x + i * 9, m_pos_y + j * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y1, 0.0f, 0.0f);
                C3D_ImmSendAttrib(0.78125f, 0.78125f, 0.78125f, 1.0f);

                C3D_ImmSendAttrib(m_pos_x + i * 9, m_pos_y + (j + 1) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x1, tileset_coord[tile].y2, 0.0f, 0.0f);
                C3D_ImmSendAttrib(0.78125f, 0.78125f, 0.78125f, 1.0f);

                C3D_ImmSendAttrib(m_pos_x + (i + 1) * 9, m_pos_y + (j + 1) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(tileset_coord[tile].x2, tileset_coord[tile].y2, 0.0f, 0.0f);
                C3D_ImmSendAttrib(0.78125f, 0.78125f, 0.78125f, 1.0f);
            }
        }
    }
    C3D_ImmDrawEnd();

    // Draw outline
    C3D_TexBind(0, &outline_tex);
    C3D_ImmDrawBegin(GPU_TRIANGLES);
    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_height; ++j) {
            int tile = m_outline[i + j * m_width];
            if (tile > 0) {
                C3D_ImmSendAttrib(m_pos_x + i * 9, m_pos_y + j * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(outline_coord[tile].x1, outline_coord[tile].y1, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 0.5625f);

                C3D_ImmSendAttrib(m_pos_x + (i + 1) * 9, m_pos_y + (j + 1) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(outline_coord[tile].x2, outline_coord[tile].y2, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 0.5625f);

                C3D_ImmSendAttrib(m_pos_x + (i + 1) * 9, m_pos_y + j * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(outline_coord[tile].x2, outline_coord[tile].y1, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 0.5625f);

                C3D_ImmSendAttrib(m_pos_x + i * 9, m_pos_y + j * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(outline_coord[tile].x1, outline_coord[tile].y1, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 0.5625f);

                C3D_ImmSendAttrib(m_pos_x + i * 9, m_pos_y + (j + 1) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(outline_coord[tile].x1, outline_coord[tile].y2, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 0.5625f);

                C3D_ImmSendAttrib(m_pos_x + (i + 1) * 9, m_pos_y + (j + 1) * 9, 0.5f, 0.0f);
                C3D_ImmSendAttrib(outline_coord[tile].x2, outline_coord[tile].y2, 0.0f, 0.0f);
                C3D_ImmSendAttrib(1.0f, 1.0f, 1.0f, 0.5625f);
            }
        }
    }
    C3D_ImmDrawEnd();

    for (unsigned int i = 0; i < FILLED_LINES_NB; i++) {
        m_part[i].draw();
    }
}
