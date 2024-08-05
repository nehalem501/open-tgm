/* DummyGPU.h - dummy_gpu */

#ifndef DUMMY_GPU_DUMMY_GPU_H
#define DUMMY_GPU_DUMMY_GPU_H

#include <GPU.h>

class DummyGPU : public GPU {
    public:
        DummyGPU();
        ~DummyGPU();

        void clear();
        void display();

        void alloc_texture(Texture& texture, const uint8_t* data, const size_t data_size);
        void free_texture(Texture& texture);
};

#endif // DUMMY_GPU_DUMMY_GPU_H
