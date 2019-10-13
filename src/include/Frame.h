/* Frame.h */

#ifndef FRAME_H
#define FRAME_H

#include <Position.h>
#include <FrameImpl.h>

class Frame {
    public:
        Frame(const Position& parent);

        void draw();

        //TODO color;

    private:
        const Position& m_parent;
        FrameImpl m_implementation;
};

#endif // FRAME_H
