/* GlobalImpl.cpp - 3DS */

#include <Global.h>

#ifdef DEBUG
#include <Debug.h>
#include <stdio.h>

base_dout& base_dout::operator << (const char* str) {
    fprintf(stderr, "%s", str);
    return *this;
}

base_dout& base_dout::operator << (const bool value) {
    operator<<(value ? "true" : "false");
    return *this;
}

base_dout& base_dout::operator << (const short value) {
    operator<<((int) value);
    return *this;
}

base_dout& base_dout::operator << (const int value) {
    fprintf(stderr, "%d", value);
    return *this;
}

base_dout& base_dout::operator << (const long value) {
    operator<<((int) value);
    return *this;
}

base_dout& base_dout::operator << (const unsigned short value) {
    operator<<((int) value);
    return *this;
}

base_dout& base_dout::operator << (const unsigned int value) {
    operator<<((int) value);
    return *this;
}

base_dout& base_dout::operator << (const unsigned long value) {
    operator<<((int) value);
    return *this;
}
#endif

void init_random() {
}
