/* AppImpl.cpp - SDL */

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
//#include <SDL_opengl.h>
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
    bool fullscreen = false; // TODO load config

    // Init SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        error("Could not initialize SDL");
    }

    // Create app window
    if (SDL_SetVideoMode(screen.width, screen.height, 0,
                         SDL_OPENGL | SDL_RESIZABLE) == NULL) {
        // TODO remove SDL_OPENGL for future D3D backend
        error("Could not create window");
    }

    SDL_EnableUNICODE(SDL_TRUE);
    SDL_WM_SetCaption("Open TGM", NULL);

    // Disable keyboard repeat
    if (SDL_EnableKeyRepeat(0, 0)) {
        error("Could not disable keyboard repeat");
    }

    init_gpu();
	load_textures();

    #ifdef DEBUG
    bool frame_by_frame = false;
    bool do_frame = false;
    #endif

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        //while() { TODO timing code
        //61.681773 Hz
        //0.016 212 244 74 secs
        // 16212 usecs
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
                                    error("Could not create window");
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
                                    error("Could not create window");
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
                        error("Could not create window");
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
                    sleep_usecs(1000);
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
            SDL_GL_SwapBuffers();
        }

        sleep_usecs(1000);
    //}

    SDL_Quit();
}
