#include "window.h"

SDL_Window* createWindow() {
    SDL_Window* window =  SDL_CreateWindow(
		"SNAKE",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	);

    if (window == NULL) {
       fprintf(stderr, "could not create window: %s\n", SDL_GetError());
	   SDL_Quit();
	   return NULL;
	}

	return window;
}
