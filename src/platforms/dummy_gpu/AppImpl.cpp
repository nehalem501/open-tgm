/* AppImpl.cpp - dummy_gpu */

#include <Scene.h>
#include <App.h>
#include <GPU.h>

Size screen = { 1, 1 };

void app(Scene& scene) {
    // For each frame {
        scene.update();
        graphics_clear();
        scene.draw();
        graphics_display();
    // }
}
