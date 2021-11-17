/* FrameImpl.h - GPU */

#ifndef FRAME_GPU_H
#define FRAME_GPU_H

#include "Rect.h"
#include "Reloadable.h"
#include "VertexArray.h"

/* Forward declarations to avoid dependency hell */
class Frame;

class FrameImpl : public Reloadable {
    public:
        FrameImpl(const Frame& frame);

        void color(int color);
        void resize();
        virtual void refresh() { texcoords(get_texture_data(TexturesID::FRAME)); }

        inline void render() const {
            m_background.render();
            m_vertex_array.render();
        }

    private:
        void texcoords(const TextureData& data);
        const Frame& m_frame;
        Rect m_background;
        VertexArray2D<16> m_vertex_array;
};

#endif // FRAME_GPU_H
