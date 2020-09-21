#include "apple.h"

void drawApple(SDL_Renderer* render, Apple* apple) {
	SDL_SetRenderDrawColor(render, 128, 0, 0, 0);
	SDL_RenderFillRect(render, &apple->shape);
}

void updateApple(Apple* apple) {
	apple->shape.x = randomX();
	apple->shape.y = randomY();
}

Apple initApple() {
	SDL_Rect shape = { 0,0,SQUARE_SIZE,SQUARE_SIZE};
	Apple apple = { shape };
	updateApple(&apple);
	return apple;
}
