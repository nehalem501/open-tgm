/* GPUImpl.h - Deko3D */

#include <deko3d.hpp>
#include <Texture.h>
#include <GPUImpl.h>
#include <Deko3DGPU.h>

// TODO
#define FB_NUM    2
#define FBMEMSIZE (16*1024*1024)

// Define the size of the memory block that will hold code
#define CODEMEMSIZE (64*1024)

// Define the size of the memory block that will hold command lists
#define CMDMEMSIZE (16*1024)


Deko3DGPU::Deko3DGPU() {
    device = dk::DeviceMaker{}.create();
    queue = dk::QueueMaker{device}.setFlags(DkQueueFlags_Graphics).create();

    fb_mem_block = dk::MemBlockMaker{device, FBMEMSIZE}
        .setFlags(DkMemBlockFlags_GpuCached | DkMemBlockFlags_Image)
        .create();
}

Deko3DGPU::~Deko3DGPU() {
    device.destroy();
}

void Deko3DGPU::clear() {
    // TODO
}

void Deko3DGPU::display() {
    // TODO
}
