/* GlobalImpl.cpp - SDL2 */

#include <Global.h>

#ifdef DEBUG
#include <Debug.h>
#include <stdio.h>

void printd_str(const char *str) {
    fputs(str, stdout);
}

#endif

void init_random() {
}

