/* TimerImpl.h - GPU */

#ifndef TIMER_GPU_H
#define TIMER_GPU_H

#include <Position.h>
#include <TargetTypes.h>
#include <Glyphs.h>
#include <Text.h>

class TimerImpl {
    public:
        TimerImpl() :
            m_str{'0', '0', ':', '0', '0', ':', '0', '0'},
            m_glyphs(
                m_str,
                Position(0, 0),
                Layouts::NONE,
                TextColor::NONE,
                8,
                Fonts::DIGITS_FONT) { }

        void layout(const Position &position);
        void update(const uint8_t m_digits[6]);

        void render() const { m_glyphs.render(); }

        #ifdef RESIZABLE
        void resize(const Position &position) {
            m_glyphs.resize(position, Layouts::NONE);
        }
        #endif

    private:
        char m_str[8];
        Glyphs<8> m_glyphs;
};

#endif
