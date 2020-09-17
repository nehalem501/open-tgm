/* FrameImpl.cpp - PSP */

#include <stdlib.h>
//#include <glib2d.h>
#include <GlobalPSP.h>
#include "FrameImpl.h"

void FrameImpl::init_graphics() {
}

void FrameImpl::update_graphics() {
}

void Frame::draw() const {
    // Draw stack frame
    //g2dBeginQuads(frame_tex);
    //g2dSetColor(0xFFFFE0D7);

    // Right
    /*g2dSetCropXY(0, 30);
    g2dSetCropWH(10, -30);
    g2dSetCoordXY(m_stack->m_pos_x + m_stack->m_width * 10,
                  m_stack->m_pos_y + 10 * 2);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x + (m_stack->m_width + 1) * 10,
                  m_stack->m_pos_y + 10);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x + (m_stack->m_width + 1) * 10,
                  m_stack->m_pos_y + (m_stack->m_height + 1) * 10);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x + m_stack->m_width * 10,
                  m_stack->m_pos_y + m_stack->m_height * 10);
    g2dAdd();*/

    // Top
    /*g2dSetCropXY(0, 0);
    g2dSetCropWH(10, 10);
    g2dSetCoordXY(m_stack->m_pos_x,
                  m_stack->m_pos_y + 2 * 10);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x - 10,
                  m_stack->m_pos_y + 10);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x + (m_stack->m_width + 1) * 10,
                  m_stack->m_pos_y + 10);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x + m_stack->m_width * 10,
                  m_stack->m_pos_y + 2 * 10);
    g2dAdd();*/

    // Bottom
    /*g2dSetCropXY(0, 0);
    g2dSetCropWH(10, 10);
    g2dSetCoordXY(m_stack->m_pos_x + m_stack->m_width * 10,
                  m_stack->m_pos_y + m_stack->m_height * 10);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x + (m_stack->m_width + 1) * 10,
                  m_stack->m_pos_y + (m_stack->m_height + 1) * 10);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x - 10,
                  m_stack->m_pos_y + (m_stack->m_height + 1) * 10);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x,
                  m_stack->m_pos_y + m_stack->m_height * 10);
    g2dAdd();*/

    // Left
    /*g2dSetCropXY(0, 0);
    g2dSetCropWH(10, 30);
    g2dSetCoordXY(m_stack->m_pos_x - 10,
                  m_stack->m_pos_y + 10);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x,
                  m_stack->m_pos_y + 2 * 10);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x,
                  m_stack->m_pos_y + m_stack->m_height * 10);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x - 10,
                  m_stack->m_pos_y + (m_stack->m_height + 1) * 10);
    g2dAdd();*/

    //g2dEnd();

    // Draw stack background
    /*g2dBeginQuads(NULL);
    g2dSetColor(0xDD000000);
    g2dSetCoordXY(m_stack->m_pos_x,
                  m_stack->m_pos_y + 20);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x + 10 * m_stack->m_width,
                  m_stack->m_pos_y + 20);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x + 10 * m_stack->m_width,
                  m_stack->m_pos_y + 10 * m_stack->m_height);
    g2dAdd();
    g2dSetCoordXY(m_stack->m_pos_x,
                  m_stack->m_pos_y + 10 * m_stack->m_height);
    g2dAdd();
    g2dEnd();*/
}
