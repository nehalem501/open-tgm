/* Background.cpp */

#include <Global.h>
#include <core/Background.h>

Core::Background::Background() : options(false) {
    #ifdef DEBUG
    std::cout << "Background constructor" << std::endl;
    #endif
}
