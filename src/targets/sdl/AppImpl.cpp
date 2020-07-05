/* AppImpl.cpp - SDL */

// TODO
#define GL_SILENCE_DEPRECATION

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "../utils/timing.h"
#include <Scene.h>
#include <GPU.h>
#include <App.h>

Size screen = { 320, 240 };
int tile_size = 9;

void app(Scene& scene) {
    bool fullscreen = false; // TODO load config

    // Init SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    // Create app window
    if (SDL_SetVideoMode(screen.width, screen.height, 0,
                         SDL_OPENGL | SDL_RESIZABLE) == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_EnableUNICODE(SDL_TRUE);

    SDL_WM_SetCaption("Open TGM", NULL);

    // Disable keyboard repeat
    if (SDL_EnableKeyRepeat(0, 0)) {
        printf("Could not disable keyboard repeat: %s\n", SDL_GetError());
        exit(1);
    }

    init_gpu();
	load_textures();

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

                if (event.type == SDL_KEYDOWN) {
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = true;
                            break;

                        #ifdef DEBUG
                        case SDLK_p:
                            frame_by_frame = !frame_by_frame;
                            break;

                        case SDLK_n:
                            do_frame = true;
                            break;
                        #endif

                        case SDLK_F10: // TODO
                            if (fullscreen) {
                                if (SDL_SetVideoMode(screen.width, screen.height,
                                                     0, SDL_OPENGL | SDL_RESIZABLE) == NULL) {
                                    printf("Could not create window: %s\n",
                                            SDL_GetError());
                                    exit(1);
                                }
                                resize(screen.width, screen.height); // TODO
                                scene.resize();
                                fullscreen = false;
                            } else {
                                // Works from  SDL v1.2.10 to get
                                // current resolution
                                if (SDL_SetVideoMode(1366, 768, 0, SDL_OPENGL |
                                                     SDL_RESIZABLE |
                                                     SDL_FULLSCREEN) == NULL) {
                                    printf("Could not create window: %s\n",
                                           SDL_GetError());
                                    exit(1);
                                }
                                const SDL_VideoInfo* info = SDL_GetVideoInfo();
                                resize(info->current_w, info->current_h);
                                scene.resize();
                                fullscreen = true;
                            }

                            break;

                        default:
                            break;
                    }
                }
                if (event.type == SDL_VIDEORESIZE) {
                    if (SDL_SetVideoMode(event.resize.w, event.resize.h,
                                         0, SDL_OPENGL | SDL_RESIZABLE) == NULL) {
                        printf("Could not create window: %s\n",
                                SDL_GetError());
                        exit(1);
                    }
                    resize(event.resize.w, event.resize.h);
                    scene.resize();
                    break;
                }
            }

            SDL_PumpEvents();

            #ifdef DEBUG
            if (frame_by_frame) {
                if (!do_frame) {
                    continue;
                } else {
                    do_frame = false;
                }
            }
            #endif

            scene.update();

            graphics_clear();

            scene.draw();

	        graphics_display();

        //}

        sleep_usecs(1000);
    }

    SDL_Quit();
}
