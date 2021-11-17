/* GlobalImpl.cpp - Dummy */

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

base_dout& base_dout::operator << (const int value) {
    printf("%d", value);
    return *this;
}

base_dout& base_dout::operator << (const size_t value) {
    operator<<((int) value);
    return *this;
}

base_dout& base_dout::operator << (const uint32_t value) {
    operator<<((int)  value);
    return *this;
}
#endif

void init_random() {
}

void init_textures() {
}

