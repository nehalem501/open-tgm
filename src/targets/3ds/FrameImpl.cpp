/* FrameImpl.cpp - 3DS */

#include <3ds.h>
#include <citro3d.h>
#include "Global3DS.h"
#include "FrameImpl.h"

void FrameImpl::initGraphics() {
}

void FrameImpl::updateGraphics() {
}

void Frame::draw() const {
    // Draw stack frame
    C3D_TexBind(0, &frame_tex);
    C3D_ImmDrawBegin(GPU_TRIANGLES);

    float col_r = 0.83984375f;
    float col_g = 0.875f;
    float col_b = 1.0f;
    float col_a = 1.0f;

    // Right
    C3D_ImmSendAttrib(m_stack->m_pos_x + m_stack->m_width * 9, m_stack->m_pos_y + 9 * 2, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.25f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x + (m_stack->m_width + 1) * 9, m_stack->m_pos_y + (m_stack->m_height + 1) * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(9.0f / 64.0f, 1.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x + (m_stack->m_width + 1) * 9, m_stack->m_pos_y + 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(9.0f / 64.0f, 0.25f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x + m_stack->m_width * 9, m_stack->m_pos_y + 9 * 2, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.25f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x + m_stack->m_width * 9, m_stack->m_pos_y + m_stack->m_height * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 1.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x + (m_stack->m_width + 1) * 9, m_stack->m_pos_y + (m_stack->m_height + 1) * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(9.0f / 64.0f, 1.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    // Top
    C3D_ImmSendAttrib(m_stack->m_pos_x, m_stack->m_pos_y + 2 * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(9.0f / 64.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x + (m_stack->m_width + 1) * 9, m_stack->m_pos_y + 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.25f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x - 9, m_stack->m_pos_y + 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x, m_stack->m_pos_y + 2 * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(9.0f / 64.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x + m_stack->m_width * 9, m_stack->m_pos_y + 2 * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(9.0f / 64.0f, 0.25f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x + (m_stack->m_width + 1) * 9, m_stack->m_pos_y + 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.25f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    // Bottom
    C3D_ImmSendAttrib(m_stack->m_pos_x + m_stack->m_width * 9, m_stack->m_pos_y + m_stack->m_height * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(9.0f / 64.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x - 9, m_stack->m_pos_y + (m_stack->m_height + 1) * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.25f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(1 + m_stack->m_pos_x + (m_stack->m_width + 1) * 9, m_stack->m_pos_y + (m_stack->m_height + 1) * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x + m_stack->m_width * 9, m_stack->m_pos_y + m_stack->m_height * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(9.0f / 64.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x, m_stack->m_pos_y + m_stack->m_height * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(9.0f / 64.0f, 0.25f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x - 9, m_stack->m_pos_y + (m_stack->m_height + 1) * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.25f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    // Left
    C3D_ImmSendAttrib(m_stack->m_pos_x - 9, m_stack->m_pos_y + 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x, m_stack->m_pos_y + m_stack->m_height * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(9.0f / 64.0f, 0.75f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x, m_stack->m_pos_y + 2 * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(9.0f / 64.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x - 9, m_stack->m_pos_y + 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x - 9, m_stack->m_pos_y + (m_stack->m_height + 1) * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.75f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmSendAttrib(m_stack->m_pos_x, m_stack->m_pos_y + m_stack->m_height * 9, 0.5f, 0.0f);
    C3D_ImmSendAttrib(9.0f / 64.0f, 0.75f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(col_r, col_g, col_b, col_a);

    C3D_ImmDrawEnd();

    // Draw stack background
    C3D_TexBind(0, &empty_tex);
    C3D_ImmDrawBegin(GPU_TRIANGLE_STRIP);

    C3D_ImmSendAttrib(m_stack->m_pos_x, m_stack->m_pos_y + 18, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.86328125f);

    C3D_ImmSendAttrib(m_stack->m_pos_x, m_stack->m_pos_y + 9 * m_stack->m_height, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.86328125f);

    C3D_ImmSendAttrib(m_stack->m_pos_x + 9 * m_stack->m_width, m_stack->m_pos_y + 18, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.86328125f);

    C3D_ImmSendAttrib(m_stack->m_pos_x + 9 * m_stack->m_width, m_stack->m_pos_y + 9 * m_stack->m_height, 0.5f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.0f);
    C3D_ImmSendAttrib(0.0f, 0.0f, 0.0f, 0.86328125f);

    C3D_ImmDrawEnd();
}
