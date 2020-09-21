#ifndef GAME_H
#define GAME_H

#include "apple.h"
#include "snake.h"

struct GameState {
	bool running;
	Snake snake;
	Apple apple;
};

GameState gameInit();
void gameUpdate(GameState* gs);
void gameRender(SDL_Renderer* render, GameState* gs);

#endif