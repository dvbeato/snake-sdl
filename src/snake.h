#ifndef SNAKE_H
#define SNAKE_H

#include <SDL.h>
#include "board.h"
#include <list>
#include <iterator>

struct Snake {
	Vect2d direction;
	std::list<SDL_Rect> shapes;
};

Snake initSnake();
void increaseSnake(Snake* snake);
void drawSnake(SDL_Renderer* render, Snake* snake);
void updateSnake(Snake* snake);

#endif
