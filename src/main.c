#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "player.h"

#define NAME    "SDL_Game"
#define VERSION 1.0f

#define WIDTH   800
#define HEIGHT  600

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

static void handleEvents(Uint8 *);
static void update(void);
static void render(void);

int main(int argc, char *argv[]) {

    Uint8 close = 0;

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        perror("error initializing SDL!");
        exit(1);
    }

    window = SDL_CreateWindow (NAME, // window name
                               SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,   // position
                               WIDTH, HEIGHT,   // dimensions
                               0);  // flags

    if(window == NULL) {
        perror("window creation failed!");
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,   // window for the renderer
                                  -1,   // driver to use (-1 for default)
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);   // flags

    if(renderer == NULL) {
        perror("renderer creation failed!");
        SDL_Quit();
        exit(1);
    }

    /* Game Loop */
    while (!close) {
        handleEvents(&close);
        update();
        render();
    }

    SDL_Quit();

    return 0;
}

static void handleEvents(Uint8 *closeFlag) {
    SDL_Event event;

    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            *closeFlag = 1;
    }
}

static void update(void) {
}

static void render(void) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
