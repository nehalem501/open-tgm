/* StackImpl.cpp - GPU */

#include <Global.h>
#include <Debug.h>
#include <Stack.h>
#include "TilemapEnums.h"
#include "StackImpl.h"

StackImpl::StackImpl(const Stack& stack) :
        m_stack(stack),
        m_field_tilemap(
            stack.position(),
            ColorRGBA(0.8f, 0.8f, 0.8f, 1.0f),
            stack.field().width(),
            stack.field().height(),
            TilemapID::BLOCKS),
        m_outline_tilemap(
            stack.position(),
            ColorRGBA(1.0f, 1.0f, 1.0f, 0.6f),
            stack.field().width(),
            stack.field().height(),
            TilemapID::OUTLINE) {
    printd(DebugCategory::STACK, "StackImpl constructor");

    update_field();
    update_outline();
}

void StackImpl::update_field() {
    // TODO update within needed bounds
    m_field_tilemap.update_blocks(m_stack.field());
}

void StackImpl::update_outline() {
    // TODO update within needed bounds
    m_outline_tilemap.update_outline(m_stack.field());
}
