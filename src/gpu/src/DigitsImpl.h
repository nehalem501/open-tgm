/* DigitsImpl.h - GPU */

#ifndef DIGITS_GPU_H
#define DIGITS_GPU_H

#include <Position.h>
#include <TargetTypes.h>
#include <Glyphs.h>
#include <Text.h>

/* Forward declarations to avoid dependency hell */
class Digits;

#define MAX_DIGITS_LEN 10 // TODO unique header

class DigitsImpl {
    public:
        DigitsImpl(Digits &digits);

        void layout(const Position &position);
        void update();

        void render() const { m_glyphs.render(); }

        #ifdef RESIZABLE
        void resize() { }
        #endif

    private:
        Digits &m_digits;
        Glyphs<MAX_DIGITS_LEN> m_glyphs;
};

#endif
