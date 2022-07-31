/* Frame.h */

#ifndef FRAME_H
#define FRAME_H

#include <Position.h>
#include <Debug.h>
#include <FrameImpl.h>

namespace FrameColors {
    enum {
        NORMAL = 0,
        LIGHT_BLUE,
        RED
    };
}

class Frame {
    public:
        Frame(const Position& parent) :
                m_parent(parent),
                m_color(FrameColors::NORMAL),
                m_implementation(*this) {
            printd(DebugCategory::FRAME, "Frame constructor");
        }

        inline void color(int color) {
            if (color != m_color) {
                printd(DebugCategory::FRAME, "Frame::update_color: old=", m_color, " new=", color);

                m_color = color;
                m_implementation.color(color);
            }
        }

        inline const Position& position() const { return m_parent; };

        void draw() const { m_implementation.render(); }

        #ifdef RESIZABLE
        void resize() { m_implementation.resize(); }
        #endif

        #ifdef MULTIPLAYER
        void set_size(int height, int width);
        int width() const { return m_width; }
        int height() const { return m_height; }
        #endif

    private:
        const Position& m_parent;
        int m_color;

        #ifdef MULTIPLAYER
        int m_height, m_width;
        #endif

        FrameImpl m_implementation;
};

#endif // FRAME_H
