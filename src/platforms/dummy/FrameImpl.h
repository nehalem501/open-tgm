/* FrameImpl.h - Dummy */

#ifndef FRAME_DUMMY_H
#define FRAME_DUMMY_H

/* Forward declarations to avoid dependency hell */
class Frame;

class FrameImpl {
    public:
        FrameImpl(const Frame& /*frame*/) /*: m_frame(frame)*/ { }; // TODO
        void color(int color);
        void render() const;

    private:
        //const Frame& m_frame;
};

#endif
