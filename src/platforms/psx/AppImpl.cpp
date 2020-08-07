/* AppImpl.cpp - PSX */

#include <MainMenu.h>
#include <App.h>

void app(MainMenu& menu) {
    // For each frame {
        menu.update();
        menu.draw();
    // }
}
