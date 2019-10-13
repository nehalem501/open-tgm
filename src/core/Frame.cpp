/* Frame.cpp */

#include <Frame.h>

Frame::Frame(const Position& parent) : m_parent(parent) {
    #ifdef DEBUG
    print("Frame constructor\n");
    #endif
}

void Frame::draw() {
    //m_implementation;
}
