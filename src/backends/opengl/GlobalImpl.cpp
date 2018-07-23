/* globalImpl.cpp - OpenGL */

#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <Global.h>

void init_textures() {
}

void init_graphics_context(int width, int height) {
    // Init OpenGL
    //glViewport(0, 0, win_width, win_height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("Could not initialize OpenGL: %s\n", gluErrorString(error));
        exit(1);
    }
}

void graphics_clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void graphics_display() {
    SDL_GL_SwapBuffers();
}
