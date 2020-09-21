#include "game.h"

GameState gameInit() {
	GameState gs = {};
	gs.running = true;
	gs.snake = initSnake();
	gs.apple = initApple();
	return gs;
}

void gameUpdate(GameState* gs) {
	SDL_Event event;

	while (SDL_PollEvent(&event) && gs->running) {
		switch (event.type) {
		case SDL_QUIT:
			gs->running = false;
			return;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_w:
			case SDLK_UP:
				gs->snake.direction = UP;
				break;
			case SDLK_s:
			case SDLK_DOWN:
				gs->snake.direction = DOWN;
				break;
			case SDLK_LEFT:
			case SDLK_a:
				gs->snake.direction = LEFT;
				break;
			case SDLK_RIGHT:
			case SDLK_d:
				gs->snake.direction = RIGHT;
				break;
			default:
				break;
			}
		default:
			break;
		}
	}

	updateSnake(&gs->snake);

	if (checkColision(&gs->snake.shapes.front(), &gs->apple.shape)) {
		updateApple(&gs->apple);
		increaseSnake(&gs->snake);
	}
}

void gameRender(SDL_Renderer* render, GameState* gs) {
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	SDL_RenderClear(render);
	drawLimits(render);
	drawApple(render, &gs->apple);
	drawSnake(render, &gs->snake);
	SDL_RenderPresent(render);
}
