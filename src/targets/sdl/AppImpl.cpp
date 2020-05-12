/* AppImpl.cpp - SDL */

// TODO
#define GL_SILENCE_DEPRECATION

#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "../utils/timing.h"
#include <Global.h>
#include <Background.h>
#include <Scene.h>
#include <App.h>

Size screen = { 320, 240 };

void init_graphics_context(int width, int height) {
    // Init OpenGL
    //glViewport(0, 0, win_width, win_height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("Could not initialize OpenGL: %s\n", gluErrorString(error));
        exit(1);
    }
}

void graphics_clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void graphics_display() {
    SDL_GL_SwapBuffers();
}

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

    init_graphics_context(screen.width, screen.height);

    SDL_WM_SetCaption("Open TGM", NULL);

    // Disable keyboard repeat
    if (SDL_EnableKeyRepeat(0, 0)) {
        printf("Could not disable keyboard repeat: %s\n", SDL_GetError());
        exit(1);
    }

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
                                init_graphics_context(screen.width, screen.height);
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
                                printf("%dx%d\n", info->current_w, info->current_h);
                                init_graphics_context(info->current_w, info->current_h);
                                fullscreen = true;
                            }

                            break;

                        default:
                            break;
                    }
                }
                if (event.type == SDL_VIDEORESIZE) {
                    // TODO resize
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

            /*glBegin(GL_QUADS);
            glColor3f(1, 0, 0);
            glVertex2f(10, 10);
            glColor3f(0, 1, 0);
            glVertex2f(100, 10);
            glColor3f(0, 0, 1);
            glVertex2f(100,  100);
            glColor3f(1, 0, 1);
            glVertex2f(10, 100);
            glEnd();*/
            
	        graphics_display();

        //}

        sleep_usecs(1000);
    }

    SDL_Quit();
}
