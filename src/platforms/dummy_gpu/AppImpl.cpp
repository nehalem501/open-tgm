/* AppImpl.cpp - dummy_gpu */

#include <Scene.h>
#include <App.h>

void app(Scene& scene) {
    // For each frame {
        scene.update();
        scene.draw();
    // }
}
