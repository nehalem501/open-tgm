/* FrameImpl.cpp - PSP */

#include <stdlib.h>
#include <glib2d.h>
#include "FrameImpl.h"

void FrameImpl::initGraphics() {
}

void FrameImpl::updateGraphics() {
}

void Frame::draw() const {
    g2dBeginQuads(NULL);
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
    g2dEnd();
}
