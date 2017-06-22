/* ChooseModeImpl.cpp - Dummy */

#include "ChooseModeImpl.h"

void ChooseModeImpl::initGraphics() {
    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].initGraphics();
    }
}

void ChooseModeImpl::draw() const {
    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].draw();
    }
}
