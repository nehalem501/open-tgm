/* Background.cpp */

#include <core/Background.h>

Core::Background::Background() : options(false) {
    //cout << "Background constructor" << endl;
}

void Core::Background::changeToOptions() {
    options = true;
}

void Core::Background::changeToBackground() {
    options = false;
}
