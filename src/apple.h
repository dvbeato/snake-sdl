#ifndef APPLE_H
#define APPLE_H

#include <SDL.h>
#include "board.h"

struct Apple {
	SDL_Rect shape;
};

Apple initApple();
void drawApple(SDL_Renderer* render, Apple* apple);
void updateApple(Apple* apple);

#endif