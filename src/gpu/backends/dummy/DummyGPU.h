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
};

#endif // DUMMY_GPU_DUMMY_GPU_H
