/* GlobalImpl.cpp - PSP */

#include <Global.h>

#ifdef DEBUG
#include <Debug.h>
#include <pspsdk.h>

void printd_str(const char *str) {
    //fputs(str, stderr);
    sceKernelPrintf("%s", str);
}
#endif

void init_random() {
}
