/* AppImpl.cpp - SDL2 */

#include <stdio.h>
#include <SDL.h>
#include <App.h>

void app() {
    SDL_Window *window = NULL;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Quit();
}
