/* AppImpl.cpp - dummy_gpu */

#include <Scene.h>
#include <App.h>
#include <GPU.h>
#include <DummyGPU.h>

Size screen = { 1, 1 };

App::App() {
    static DummyGPU gpu;
    GPU::set_current(&gpu);
}

void App::run(Scene& scene) {
    GPU& gpu = GPU::get_current_mut();
    // For each frame {
        scene.update();
        gpu.clear();
        scene.draw();
        gpu.display();
    // }
}
