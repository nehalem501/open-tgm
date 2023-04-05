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
};

#endif // SCEGU_GPU_SCEGU_H
