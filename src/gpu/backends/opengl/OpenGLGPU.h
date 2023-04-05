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

        bool resize(unsigned int width, unsigned int height);

    private:
        int max_texture_size;
};

#endif // OPENGL_GPU_OPENGL_H
