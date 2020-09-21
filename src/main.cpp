#include <SDL.h>
#include <stdio.h>
#include <ctime>
#include "window.h"
#include "game.h"

int main(int argc, char* args[]) {
	srand((unsigned) time(0));

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
		fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window* window = createWindow();
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

	GameState gs = gameInit();

	while (gs.running) {
		gameUpdate(&gs);
		gameRender(render, &gs);

		SDL_Delay(400);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
