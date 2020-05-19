/* StackImpl.cpp - GPU */

#include <Global.h>
#include <Stack.h>
#include "StackImpl.h"

StackImpl::StackImpl(const Stack& stack) :
        m_stack(stack),
        m_field_tilemap(
            stack.position(),
            stack.field(),
            ColorRGBA(0.8f, 0.8f, 0.8f, 1.0f),
            stack.width(),
            stack.height(),
            64, 64,
            7,
            TexturesID::BLOCKS),
        m_outline_tilemap(
            stack.position(),
            stack.outline(),
            ColorRGBA(1.0f, 1.0f, 1.0f, 0.6f),
            stack.width(),
            stack.height(),
            64, 64,
            4,
            TexturesID::OUTLINE) {
    #ifdef DEBUG
    print("StackImpl constructor\n");
    #endif

    update_field();
    update_outline();
}

void StackImpl::update_field() {
    // TODO update within needed bounds
    m_field_tilemap.update(m_stack.field());
}

void StackImpl::update_outline() {
    // TODO update within needed bounds
    m_outline_tilemap.update(m_stack.outline());            
}
