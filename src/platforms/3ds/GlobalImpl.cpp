/* GlobalImpl.cpp - 3DS */

#include <Global.h>

#ifdef DEBUG
#include <Debug.h>
#include <stdio.h>

void printd_str(const char *str) {
    fputs(str, stderr);
}
#endif

void init_random() {
}
