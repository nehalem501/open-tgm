/* StackImpl.cpp - GPU */

#include <Stack.h>
#include "StackImpl.h"

void StackImpl::update() {
    m_stack.block(0, 0); // TODO
}

void StackImpl::render() const {
    // Draw stack blocks and outline
}
