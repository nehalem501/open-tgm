/* SceGuGPU.h - SCEGU */

#ifndef SCEGU_GPU_SCEGU_H
#define SCEGU_GPU_SCEGU_H

#include <Size.h>
#include <GPU.h>

class SceGuGPU : public GPU {
    public:
        SceGuGPU();
        ~SceGuGPU();

        void clear();
        void display();

        void alloc_texture(Texture& texture, const uint8_t* data, const size_t data_size);
        void free_texture(Texture& texture);
};

#endif // SCEGU_GPU_SCEGU_H
