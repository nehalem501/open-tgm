/* AppImpl.cpp - Dummy */

#include <Scene.h>
#include <App.h>

void app(Scene& scene) {
    // For each frame {
        scene.update();
        scene.draw();
    // }
}
