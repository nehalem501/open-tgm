/* DigitsImpl.h - Dummy */

#ifndef DIGITS_DUMMY_H
#define DIGITS_DUMMY_H

#include <common/BaseDigits.h>

class DigitsImpl : public BaseDigits {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
