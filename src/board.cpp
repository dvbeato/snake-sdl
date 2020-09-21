#include "board.h"

Vect2d UP = { 0, -SQUARE_SIZE, 0 };
Vect2d DOWN = { 0, SQUARE_SIZE, 0 };
Vect2d LEFT = { -SQUARE_SIZE, 0, 0 };
Vect2d RIGHT = { SQUARE_SIZE, 0, 0 };

int randomX() {
	int randMax = (SCREEN_WIDTH - (2 * SQUARE_SIZE));
	int randX = rand() % randMax + SQUARE_SIZE;
	int randXSquare = (randX / SQUARE_SIZE) * SQUARE_SIZE;
	return randXSquare;
}

int randomY() {
	int randMax = (SCREEN_HEIGHT - (2 * SQUARE_SIZE));
	int randY = rand() % randMax + SQUARE_SIZE;
	int randYSquare = (randY / SQUARE_SIZE) * SQUARE_SIZE;
	return randYSquare;
}

void drawLimits(SDL_Renderer* render) {
	SDL_Rect top = {0, 0, SCREEN_WIDTH, SQUARE_SIZE};
	SDL_Rect bottom = {0, (SCREEN_HEIGHT-SQUARE_SIZE), SCREEN_WIDTH, SQUARE_SIZE};
	SDL_Rect right = {(SCREEN_WIDTH-SQUARE_SIZE), 0, SQUARE_SIZE, SCREEN_HEIGHT };
	SDL_Rect left = {0, 0, SQUARE_SIZE, SCREEN_HEIGHT};
	SDL_SetRenderDrawColor(render, 128, 0, 0, 0);
	SDL_RenderFillRect(render, &top);
	SDL_RenderFillRect(render, &bottom);
	SDL_RenderFillRect(render, &right);
	SDL_RenderFillRect(render, &left);
}

bool checkColision(SDL_Rect* head, SDL_Rect* apple) {
	return (head->x == apple->x && head->y == apple->y);
}
