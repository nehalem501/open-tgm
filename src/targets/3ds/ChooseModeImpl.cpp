/* ChooseModeImpl.cpp - 3DS */

#include "ChooseModeImpl.h"

void ChooseModeImpl::init_graphics() {
    /*for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].init_raphics();
    }*/
}

void ChooseModeImpl::draw() const {
    for (int i = 0; i < NB_MODES; i++) {
        m_modes_strings[i].draw();
    }
}
