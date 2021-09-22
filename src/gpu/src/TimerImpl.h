/* TimerImpl.h - GPU */

#ifndef TIMER_GPU_H
#define TIMER_GPU_H

#include <Position.h>
#include <TargetTypes.h>
#include <Glyphs.h>
#include <Text.h>

class TimerImpl {
    public:
        TimerImpl() : m_glyphs(
            "00:00:00",
            Position(10, 10),
            Layouts::NONE,
            TextColor::NONE,
            8,
            Fonts::DIGITS_FONT) { }

        void layout(const Position &position);
        void update(const uint8_t m_digits[6]);
        void render() const;

        #ifdef RESIZABLE
        void resize() { }
        #endif

    private:
        Glyphs<8> m_glyphs;
};

#endif
