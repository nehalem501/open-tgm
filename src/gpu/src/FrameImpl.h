/* FrameImpl.h - GPU */

#ifndef FRAME_GPU_H
#define FRAME_GPU_H

#include "VertexArray.h"

/* Forward declarations to avoid dependency hell */
class Frame;

class FrameImpl {
    public:
        FrameImpl(const Frame& frame);
        void color(int color);
        inline void render() const { m_vertex_array.render(); }

        void resize();

    private:
        void texcoords(const TextureData& data);
        const Frame& m_frame;
        VertexArray2D<16> m_vertex_array;
};

#endif // FRAME_GPU_H
