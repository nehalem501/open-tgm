/* GPU.h - GPU */

#ifndef GPU_HEADER_H
#define GPU_HEADER_H

class GPU {
    public:
        virtual ~GPU() = 0;

        virtual void clear() = 0;
        virtual void display() = 0;

        #ifdef RESIZABLE
        virtual bool resize(unsigned int width, unsigned int height) = 0;
        #endif
};

#endif // GPU_HEADER_H
