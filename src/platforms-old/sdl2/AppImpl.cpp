/* AppImpl.cpp - SDL2 */

#include <stdio.h>
#include <SDL.h>
#include <GL/glew.h>
#include <Global.h>
#include <Scene.h>
#include <App.h>
#include <GPU.h>
#include "../utils/timing.h"

Size screen = { 320, 240 };
int tile_size = 9;

void app(Scene& scene) {
    SDL_Window *window = NULL;
    SDL_GLContext context;
    //bool fullscreen = false; // TODO load config

    // Init SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    // We want OpenGL 3.0 with core profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);

    // Create app window and associated OpenGL context
    window = SDL_CreateWindow("Open TGM", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, screen.width, screen.height,
                              SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        exit(1);
    }

    context = SDL_GL_CreateContext(window);
    if (!context) {
        printf("Could not create OpenGL context: %s\n", SDL_GetError());
        exit(1);
    }

    init_gpu();

    #ifdef DEBUG
    bool frame_by_frame = false;
    bool do_frame = false;
    #endif

    bool quit = false;
    SDL_Event event;

    while(!quit) {
        //while() { TODO timing code
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
                            // TODO resize
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
