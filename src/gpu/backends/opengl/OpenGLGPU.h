/* OpenGLGPU.h - OpenGL */

#ifndef OPENGL_GPU_OPENGL_H
#define OPENGL_GPU_OPENGL_H

#include <GPU.h>

class OpenGLGPU : public GPU {
    public:
        OpenGLGPU();
        ~OpenGLGPU();

        void clear();
        void display();

        void resize(unsigned int width, unsigned int height, unsigned int new_tile_size);

        void alloc_texture(Texture& texture, const uint8_t* data, const size_t data_size);
        void free_texture(Texture& texture);

    private:
        int max_texture_size;
};

#endif // OPENGL_GPU_OPENGL_H
