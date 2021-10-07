#pragma once
#include "Game.h"

class Actor
{
public:
	Actor(string filename, float x, float y, int width, int height, Game* game);
	virtual void draw(float scrollX = 0);
	bool isInRender(float scrollX = 0);
	bool isOverlap(Actor* actor);
	bool collisionDown;
	SDL_Texture* texture;
	int x;
	int y;
	float vx;
	float vy;
	int width;
	int height;
	int fileWidth;
	int fileHeight;
	Game* game; // referencia al juego

	//Movidas pa controlar por rat�n
	bool containsPoint(int pointX, int pointY); // contiene punto
	bool clicked; // Est� pulsado
};