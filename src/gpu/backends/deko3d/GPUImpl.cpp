/* GPUImpl.h - Deko3D */

#include <deko3d.hpp>
#include <Texture.h>
#include <GPUImpl.h>

// TODO
#define FB_NUM    2
#define FBMEMSIZE (16*1024*1024)

// Define the size of the memory block that will hold code
#define CODEMEMSIZE (64*1024)

// Define the size of the memory block that will hold command lists
#define CMDMEMSIZE (16*1024)

static dk::UniqueDevice device;
static dk::UniqueQueue queue;

static dk::MemBlock fb_mem_block;
static dk::MemBlock fb_mem_block;

void init_gpu() {
    device = dk::DeviceMaker{}.create();
    queue = dk::QueueMaker{device}.setFlags(DkQueueFlags_Graphics).create();

    fb_mem_block = dk::MemBlockMaker{device, FBMEMSIZE}
        .setFlags(DkMemBlockFlags_GpuCached | DkMemBlockFlags_Image)
        .create();
}

void free_gpu() {
    device.destroy();
}

void graphics_clear() {
    // TODO
}

void graphics_display() {
    // TODO
}
