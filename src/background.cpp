/* background.cpp */

#include "background.h"

#include <iostream>
using namespace std;

Background::Background() : options(false) {
    //cout << "Background constructor" << endl;
}

void Background::changeToOptions() {
    options = true;
}

void Background::changeToBackground() {
    options = false;
}
