#include "Actor.h"

Actor::Actor(string filename, float x, float y, int width, int height, Game* game) {

	//Movidas pal rat�n
	clicked = false;
	//-------------
	this->game = game;
	SDL_Surface* surface = IMG_Load(filename.c_str());
	texture = SDL_CreateTextureFromSurface(game->renderer, surface);
	this->x = x;
	this->y = y;
	// lo que mide el fichero
	this->fileWidth = width;
	this->fileHeight = height;
	// lo que va a medir en el juego
	this->width = width;
	this->height = height;
}

void Actor::draw(float scrollX) {
	// Recorte en el fichero de la imagen
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = fileWidth; // texture.width;
	source.h = fileHeight; // texture.height;

	// Donde se va a pegar en el renderizador
	SDL_Rect destination;
	destination.x = x - width / 2 - scrollX;
	destination.y = y - height / 2;
	destination.w = width;
	destination.h = height;
	// Modificar para que la referencia sea el punto central

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, 0, NULL, SDL_FLIP_NONE);
}

bool Actor::isOverlap(Actor* actor) {
	bool overlap = false;
	//Calcular las esquinas de las imagenes para saber si se superpone con otra
	if (actor->x - actor->width / 2 <= x + width / 2
		&& actor->x + actor->width / 2 >= x - width / 2
		&& actor->y + actor->height / 2 >= y - height / 2
		&& actor->y - actor->height / 2 <= y + height / 2) {

		overlap = true;
	}
	return overlap;
}

bool Actor::isInRender(float scrollX) {
	if ((x - scrollX) - width / 2 <= WIDTH && (x - scrollX) + width / 2 >= 0 &&
		y - height / 2 <= HEIGHT && y + height / 2 >= 0) {
		return true;
	}
	return false;
}


//Movidas pal rat�n
bool Actor::containsPoint(int pointX, int pointY) {
	if (pointY >= y - height / 2 &&
		pointY <= y + height / 2 &&
		pointX <= x + width / 2 &&
		pointX >= x - width / 2) {
		return true;
	}
	return false;
}



