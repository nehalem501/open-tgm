/* FrameImpl.h - PS2 */

#ifndef FRAME_PS2_H
#define FRAME_PS2_H

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
