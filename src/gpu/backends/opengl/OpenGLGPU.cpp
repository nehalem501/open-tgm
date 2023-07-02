/* OpenGLGPU.cpp - OpenGL */

#include <stdio.h>
#include <stdlib.h>
#include <Global.h>
#include <Texture.h>
#include <Debug.h>
#include <GPU.h>
#include <OpenGLGPU.h>

OpenGLGPU::OpenGLGPU() : max_texture_size(0) {
    resize(screen.width, screen.height);

    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);

    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_texture_size); // TODO use

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        // TODO use printd
        printf("Could not initialize OpenGL: %s\n", gluErrorString(error));
        exit(1);
    }
}

OpenGLGPU::~OpenGLGPU() {

}

void OpenGLGPU::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLGPU::display() {
    //SDL_GL_SwapBuffers(); // TODO: remove SDL dependency
}

bool OpenGLGPU::resize(unsigned int width, unsigned int height) {
    screen.width = width;
    screen.height = height;

    glViewport(0, 0, width, height);

    int new_tile_size = height / 27;
    /*if (height < 243 && height >= 240) {
        new_tile_size = 9; // TODO
    }*/

    bool resized = false;

    if (new_tile_size != tile_size) {
        tile_size = new_tile_size;
        reload_textures();
        resized = true;
    }

    // TODO
    //tile_size = 9;

    printd(DebugCategory::GPU, "width: ", screen.width, ", height: ", screen.height, ", tile: ", tile_size);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    return resized;
}