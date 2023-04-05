/* AppImpl.cpp - dummy_gpu */

#include <Scene.h>
#include <App.h>
#include <GPU.h>
#include <DummyGPU.h>

Size screen = { 1, 1 };

void app(Scene& scene) {
    DummyGPU dummy_gpu;
    GPU& gpu = dummy_gpu;

    // For each frame {
        scene.update();
        gpu.clear();
        scene.draw();
        gpu.display();
    // }
}
