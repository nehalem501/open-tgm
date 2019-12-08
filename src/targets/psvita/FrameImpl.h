/* FrameImpl.h - PSVita */

#ifndef FRAME_PSVITA_H
#define FRAME_PSVITA_H

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
