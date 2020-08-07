/* AppImpl.cpp - PS2 */

#include <MainMenu.h>
#include <App.h>

void app(MainMenu& menu) {
    // For each frame {
        menu.update();
        menu.draw();
    // }
}
