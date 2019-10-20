/* Frame.cpp */

#include <TargetTypes.h>
#include <Frame.h>

Frame::Frame(const Position& parent) : m_parent(parent) {
    #ifdef DEBUG
    print("Frame constructor\n");
    #endif
}

#ifdef MULTIPLAYER
void Frame::set_size(int height, int width) {
    // TODO
    m_height = height;
    m_width = width;
}
#endif

void Frame::draw() {
    //m_implementation;
}
