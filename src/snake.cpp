#include "snake.h"

void updateSnake(Snake* snake) {
	SDL_Rect head = snake->shapes.front();

	head.x += snake->direction.x;
	head.y += snake->direction.y;

	snake->shapes.push_front(head);
	snake->shapes.pop_back();
}

void increaseSnake(Snake* snake) {
	SDL_Rect head = snake->shapes.front();
	snake->shapes.push_front({ head.x, head.y, SQUARE_SIZE, SQUARE_SIZE });
}

void drawSnake(SDL_Renderer* render, Snake* snake) {
	SDL_SetRenderDrawColor(render, 0, 0, 0, 0);

	std::list<SDL_Rect> :: iterator it;

	for (it = snake->shapes.begin(); it != snake->shapes.end(); it++) {
		SDL_RenderFillRect(render, &*it);
	}
}

Snake initSnake() {
	std::list <SDL_Rect> shapes;
    
	int initial_x = randomX();
	int initial_y = randomY();
    
	shapes.push_back({ initial_x , initial_y, SQUARE_SIZE, SQUARE_SIZE });
	shapes.push_back({ initial_x, initial_y - 20, SQUARE_SIZE, SQUARE_SIZE });
	shapes.push_back({ initial_x, initial_y - 40, SQUARE_SIZE, SQUARE_SIZE });
	
	Vect2d direction = DOWN;
	return { direction, shapes};
}
