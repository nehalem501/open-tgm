/* OpenGLGPU.cpp - OpenGL */

#include <stdio.h>
#include <stdlib.h>
#include <Global.h>
#include <Texture.h>
#include <Debug.h>
#include <GPU.h>
#include "OpenGLGPU.h"

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

    if (new_tile_size != Global::tile_size) {
        Global::tile_size = new_tile_size;
        //reload_textures(); // TODO
        resized = true;
    }

    // TODO
    //tile_size = 9;

    printd(DebugCategory::GPU, "width: ", screen.width, ", height: ", screen.height, ", tile: ", Global::tile_size);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    return resized;
}

void OpenGLGPU::alloc_texture(Texture& texture, const uint8_t* data, const size_t /*data_size*/) {
    glGenTextures(1, texture.handle_ptr_mut());
    glBindTexture(GL_TEXTURE_2D, texture.handle());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // TODO handle formats
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA8, // TODO: format
        texture.width(),
        texture.height(),
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        data);
}

void OpenGLGPU::free_texture(Texture& texture) {
    glDeleteTextures(1, texture.handle_ptr());
}
