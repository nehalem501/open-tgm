/* AppImpl.cpp - PS3 */

#include <Scene.h>
#include <App.h>

Size screen = { 400, 240 }; // TODO

void app(Scene& scene) {
    // For each frame {
        scene.update();
        scene.draw();
    // }
}
