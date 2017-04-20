/* BaseBackground.cpp */

#include <common/BaseBackground.h>

BaseBackground::BaseBackground() : options(false) {
    //cout << "Background constructor" << endl;
}

void BaseBackground::changeToOptions() {
    options = true;
}

void BaseBackground::changeToBackground() {
    options = false;
}
