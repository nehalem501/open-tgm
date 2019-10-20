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

        #ifdef MULTIPLAYER
        void set_size(int height, int width);
        #endif

    private:
        const Position& m_parent;

        #ifdef MULTIPLAYER
        int m_height, m_width;
        #endif

        FrameImpl m_implementation;
};

#endif // FRAME_H
