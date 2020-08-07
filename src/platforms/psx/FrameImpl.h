/* FrameImpl.h - PSX */

#ifndef FRAME_PSX_H
#define FRAME_PSX_H

/* Forward declarations to avoid dependency hell */
class Frame;

class FrameImpl {
    public:
        FrameImpl(Frame& frame) : m_frame(frame) { };
        void update();
        void render() const;

    private:
        Frame& m_frame;
};

#endif
