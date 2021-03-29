/* AppImpl.cpp - SDL2 */

#include <stdio.h>
#include <SDL.h>
#include <GL/glew.h>
#include "../utils/timing.h"
#include <Scene.h>
#include <GPU.h>
#include <App.h>

Size screen = { 320, 240 };
int tile_size = 9;

void error(const char *error_message) {
    printf("%s: %s\n", error_message, SDL_GetError());
    exit(1);
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
                              SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI |
                              SDL_RENDERER_PRESENTVSYNC); // TODO
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

    #ifdef DEBUG
    bool frame_by_frame = false;
    bool do_frame = false;
    #endif

    bool quit = false;
    SDL_Event event;

    while(!quit) {
        //while() { TODO timing code
        //61.681773 Hz
        //0.016 212 244 74 secs
        // 16212 usecs
            while (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }

                if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
                    switch (event.key.keysym.sym) {
                        case SDL_SCANCODE_ESCAPE:
                            quit = true;
                            break;

                        #ifdef DEBUG
                        case SDL_SCANCODE_P:
                            frame_by_frame = !frame_by_frame;
                            break;

                        case SDL_SCANCODE_N:
                            do_frame = true;
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

            #ifdef DEBUG
            if (frame_by_frame) {
                if (!do_frame) {
                    continue;
                } else {
                    do_frame = false;
                }
            }
            #endif

            // TODO
            scene.update();

            graphics_clear();
            scene.draw();

	        graphics_display();

            SDL_GL_SwapWindow(window);
        //}

        sleep_usecs(1000); // Sleep for 1 msec
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}
