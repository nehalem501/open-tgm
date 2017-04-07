/* app-dummy.cpp */

#include "../app.h"
#include "../global.h"
#include "../background.h"
#include "../menu.h"


void app() {
    bool run = true;
    while (run) {
        menu.update();
        menu.draw();
    }
}

