/* StackImpl.cpp - GPU */

#include <Global.h>
#include <Debug.h>
#include <Stack.h>
#include "TilemapEnums.h"
#include "StackImpl.h"

StackImpl::StackImpl(const Stack& stack) :
        //m_stack(stack),
        m_field_tilemap(
            stack.position(),
            NULL, // TODO: stack.field(),
            ColorRGBA(0.8f, 0.8f, 0.8f, 1.0f),
            stack.field().width(),
            stack.field().height(),
            TilemapID::BLOCKS),
        m_outline_tilemap(
            stack.position(),
            NULL, // TODO: stack.outline(),
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
    //m_field_tilemap.update(m_stack.field());
}

void StackImpl::update_outline() {
    // TODO update within needed bounds
    //m_outline_tilemap.update(m_stack.outline());
}
