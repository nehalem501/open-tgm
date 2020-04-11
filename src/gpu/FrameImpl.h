/* FrameImpl.h - GPU */

#ifndef FRAME_GPU_H
#define FRAME_GPU_H

/* Forward declarations to avoid dependency hell */
class Frame;

class FrameImpl {
    public:
        FrameImpl(const Frame& /*frame*/) /*: m_frame(frame)*/ { };
        void update();
        void render() const;

    private:
        //const Frame& m_frame;
};

#endif
