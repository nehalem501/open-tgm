/* Background.cpp */

#include <Global.h>
#include <core/Background.h>

Core::Background::Background() : options(false) {
    #ifdef DEBUG
    print("Background constructor\n");
    #endif
}
