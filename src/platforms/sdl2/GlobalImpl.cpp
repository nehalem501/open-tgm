/* GlobalImpl.cpp - SDL2 */

#include <Global.h>

#ifdef DEBUG
#include <Debug.h>
#include <stdio.h>

base_dout& base_dout::operator << (const char* str) {
    printf("%s", str);
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
    // TODO check if UNIX
    printf("\033[1;93m%d\033[0m", value);
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

