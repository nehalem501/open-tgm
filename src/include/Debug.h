/* Debug.h */

#ifndef DEBUG_H
#define DEBUG_H

#include <stddef.h>
#include <stdint.h>
#include <Position.h>

struct base_dout {
    base_dout& operator << (const char* str);
    base_dout& operator << (const bool value);

    base_dout& operator << (const short value);
    base_dout& operator << (const int value);
    base_dout& operator << (const long value);
    //base_dout& operator << (const long long value);

    base_dout& operator << (const unsigned short value);
    base_dout& operator << (const unsigned int value);
    base_dout& operator << (const unsigned long value);
    //base_dout& operator << (const unsigned long long value);

    base_dout& operator << (const Position& position) {
        operator<<("x: ");
        operator<<(position.x);
        operator<<(", y: ");
        operator<<(position.y);
        return *this;
    }
};

extern base_dout dout;

#ifdef DEBUG
#define printd(fmt) dout << fmt << "\n";
#else
#define printd(fmt)
#endif

#endif // DEBUG_H
