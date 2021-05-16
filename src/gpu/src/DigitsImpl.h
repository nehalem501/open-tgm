/* DigitsImpl.h - GPU */

#ifndef DIGITS_GPU_H
#define DIGITS_GPU_H

#include <Position.h>
#include <Text.h>
#include <Glyphs.h>
#include <TargetTypes.h>

/* Forward declarations to avoid dependency hell */
class Digits;

class DigitsImpl {
    public:
        DigitsImpl(Digits &digits);

        void layout(const Position &position);
        void update();
        void render() const;

        #ifdef RESIZABLE
        void resize() { }
        #endif

    private:
        Digits &m_digits;
        Glyphs<MAX_DIGITS_LEN> m_glyphs;
};

#endif
