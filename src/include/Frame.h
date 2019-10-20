/* Frame.h */

#ifndef FRAME_H
#define FRAME_H

#include <Position.h>
#include <FrameImpl.h>

class Frame {
    public:
        Frame(const Position& parent);

        void draw() const;

        //TODO color;

        #ifdef MULTIPLAYER
        void set_size(int height, int width);
        #endif

        inline const Position& position() { return m_parent; };

    private:
        const Position& m_parent;

        #ifdef MULTIPLAYER
        int m_height, m_width;
        #endif

        FrameImpl m_implementation;
};

#endif // FRAME_H
