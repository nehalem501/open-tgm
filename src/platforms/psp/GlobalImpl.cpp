/* globalImpl.cpp - PSP */

#include <Global.h>

#ifdef DEBUG
#include <Debug.h>
#include <pspsdk.h>

base_dout& base_dout::operator << (const char* str) {
    sceKernelPrintf("%s", str);
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
    sceKernelPrintf("%d", value);
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
