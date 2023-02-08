/* AppImpl.cpp - SDL2 */

#include <stdio.h>
#include <SDL.h>
#include <GL/glew.h>
#include "../utils/timing.h"
#include <Scene.h>
#include <GPU.h>
#include <App.h>

//Size screen = { 320, 240 };
Size screen = { 160, 108 };
int tile_size = 9;

struct AppState {
    bool frame_by_frame;
    bool do_frame;
    bool quit;
};

void error(const char *error_message) {
    printf("%s: %s\n", error_message, SDL_GetError());
    exit(1);
}

static void run_game_frame(Scene& scene, SDL_Window* window) {
    scene.update();

    graphics_clear();
    scene.draw();

    graphics_display();

    SDL_GL_SwapWindow(window);
}

static void process_sdl_events(Scene& scene, AppState& state, SDL_Window* window) {
    SDL_Event event;

    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            state.quit = true;
        }

        if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_ESCAPE:
                    state.quit = true;
                    printd(DebugCategory::INPUT, "Pressed ESCAPE");
                    break;

                #ifdef DEBUG
                case SDL_SCANCODE_P:
                    state.frame_by_frame = !state.frame_by_frame;
                    printd(DebugCategory::INPUT, "Pressed P");
                    printd(DebugCategory::INPUT, "state.frame_by_frame: ", state.frame_by_frame);
                    break;

                case SDL_SCANCODE_N:
                    state.do_frame = true;
                    printd(DebugCategory::INPUT, "Pressed N");
                    break;
                #endif

                case SDL_SCANCODE_F11:
                    // TODO fullscreen
                    break;

                default:
                    break;
            }
        }

        if (event.type == SDL_WINDOWEVENT) {
            switch (event.window.event) {
                case SDL_WINDOWEVENT_RESIZED:
                    SDL_GL_GetDrawableSize(window, &screen.width, &screen.height);
                    resize(screen.width, screen.height);
                    scene.resize();
                    break;
            }
        }
    }
}

void app(Scene& scene) {
    SDL_Window *window = NULL;
    SDL_GLContext context;
    //bool fullscreen = false; // TODO load config

    // Init SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        error("Could not initialize SDL");
    }

    // We want OpenGL 3.0 with core profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1 /*3*/);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1 /*2*/);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_COMPATIBILITY /*SDL_GL_CONTEXT_PROFILE_CORE*/);

    // Create app window and associated OpenGL context
    window = SDL_CreateWindow("Open TGM", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, screen.width, screen.height,
                              SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI); // TODO
    if (window == NULL) {
        error("Could not create window");
    }

    SDL_GL_GetDrawableSize(window, &screen.width, &screen.height);

    context = SDL_GL_CreateContext(window);
    if (!context) {
        error("Could not create OpenGL context");
    }

    init_gpu();
	load_textures();
    scene.resize();

    AppState state {
        .frame_by_frame = false,
        .do_frame = false,
        .quit = false
    };

    // TODO: timing code
    // 61.681773 Hz
    // 0.016 212 244 74 secs
    // 16212 usecs

    //printd(DebugCategory::REFRESH_RATE, "start_time initial: ", start_time);

    const uint64_t time_per_frame = 16667; // TODO
    uint64_t adjusted_frame_time = time_per_frame;
    uint64_t previous_frame_time = get_time_usecs();

    while (!state.quit) {
        process_sdl_events(scene, state, window);

        if (state.frame_by_frame) {
            if (state.do_frame) {
                state.do_frame = false;
                run_game_frame(scene, window);
            }
        } else {
            uint64_t now = get_time_usecs();
            uint64_t time_since_last_update = now - previous_frame_time;
            printd(DebugCategory::REFRESH_RATE, "time: ", time_since_last_update);

            if (time_since_last_update >= adjusted_frame_time) {
                //adjusted_frame_time = time_per_frame - (time_since_last_update - time_per_frame); // TODO
                previous_frame_time = now;
                printd(DebugCategory::REFRESH_RATE, "frame duration: ", time_since_last_update);

                run_game_frame(scene, window);
            }
        }

        sleep_usecs(1000); // Sleep for 1 msec
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}
