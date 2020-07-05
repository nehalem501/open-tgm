/* GPU.h - GPU */

#ifndef GPU_HEADER_H
#define GPU_HEADER_H

void init_gpu();
void free_gpu();

#ifdef RESIZABLE
void resize(unsigned int width, unsigned int height);
#endif

void graphics_clear();
void graphics_display();

#endif // GPU_HEADER_H
