/* FrameImpl.h - GBA */

#ifndef FRAME_GBA_H
#define FRAME_GBA_H

/* Forward declarations to avoid dependency hell */
class Frame;

class FrameImpl {
    public:
        FrameImpl(const Frame& frame) : m_frame(frame) { };
        void color(int color);
        void render() const;

    private:
        const Frame& m_frame;
};

#endif
