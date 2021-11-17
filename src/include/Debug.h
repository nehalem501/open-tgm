/* Debug.h */

#ifndef DEBUG_H
#define DEBUG_H

#include <stddef.h>
#include <stdint.h>

struct base_dout {
    base_dout& operator << (const char* str);
    base_dout& operator << (const bool value);
    base_dout& operator << (const int value);
    //base_dout& operator << (const unsigned int value);
    base_dout& operator << (const size_t value);
    base_dout& operator << (const uint32_t value);
};
extern base_dout dout;

#ifdef DEBUG
#define printd(fmt) dout << fmt << "\n";
#else
#define printd(fmt)
#endif

#endif // DEBUG_H
