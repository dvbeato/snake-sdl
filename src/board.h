#ifndef BOARD_H
#define BOARD_H

#include "window.h"
#include <stdlib.h>

#define SQUARE_SIZE 20

struct Vect2d {
	int x;
	int y;
	int speed;
};

extern Vect2d UP;
extern Vect2d DOWN;
extern Vect2d LEFT;
extern Vect2d RIGHT;

int randomX();
int randomY();
void drawLimits(SDL_Renderer* render);
bool checkColision(SDL_Rect* rect1, SDL_Rect* rect2);
#endif
