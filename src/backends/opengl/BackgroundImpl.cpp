/* BackgroundImpl.cpp - OpenGL */

#include <SDL_opengl.h>
#include "BackgroundImpl.h"

void BackgroundImpl::init_graphics() {
}

void BackgroundImpl::draw() const {
    if (options) {
        // Draw settings background
    } else {
        // Draw game background
    }
    
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(10, 10);
    glColor3f(0, 1, 0);
    glVertex2f(100, 10);
    glColor3f(0, 0, 1);
    glVertex2f(100,  100);
    glColor3f(1, 0, 1);
    glVertex2f(10, 100);
    glEnd();
}
