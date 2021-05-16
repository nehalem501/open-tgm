/* GPUImpl.h - OpenGL */

#include <stdio.h>
#include <stdlib.h>
#include <Global.h>
#include <Texture.h>
#include <GPU.h>
#include <GPUImpl.h>

int max_texture_size = 0;

void init_gpu() {
    resize(screen.width, screen.height);

    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);

    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_texture_size); // TODO use

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
    //SDL_GL_SwapBuffers(); // TODO: remove SDL dependency
}

void resize(unsigned int width, unsigned int height) {
    screen.width = width;
    screen.height = height;

    glViewport(0, 0, width, height);

    int new_tile_size = height / 27;
    /*if (height < 243 && height >= 240) {
        new_tile_size = 9; // TODO
    }*/

    if (new_tile_size != tile_size) {
        tile_size = new_tile_size;
        // TODO reload textures for new size
        ;
    }

    // TODO
    //tile_size = 9;

    #ifdef DEBUG
    print(
        "width: %d, height: %d, tile: %d\n",
        (int) screen.width,
        (int) screen.height,
        (int) tile_size);
    #endif

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
