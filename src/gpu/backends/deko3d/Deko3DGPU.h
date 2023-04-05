/* Deko3DGPU.h - Deko3D */

#ifndef DEKO3D_GPU_DEKO3D_H
#define DEKO3D_GPU_DEKO3D_H

#include <GPU.h>
#include <deko3d.hpp>

class Deko3DGPU : public GPU {
    public:
        Deko3DGPU();
        ~Deko3DGPU();

        void clear();
        void display();

    private:
        dk::UniqueDevice device;
        dk::UniqueQueue queue;

        dk::MemBlock fb_mem_block;
        // dk::MemBlock fb_mem_block;
};

#endif // DEKO3D_GPU_DEKO3D_H
