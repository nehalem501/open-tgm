/* ChooseModeImpl.cpp - PS2 */

#include "ChooseModeImpl.h"

void ChooseModeImpl::init_graphics() {
    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].init_graphics();
    }
}

void ChooseModeImpl::draw() const {
    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].draw();
    }
}
