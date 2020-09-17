/* AppImpl.cpp - dummy_gpu */

#include <Scene.h>
#include <App.h>

Size screen = { 1, 1 };

void app(Scene& scene) {
    // For each frame {
        scene.update();
        scene.draw();
    // }
}
