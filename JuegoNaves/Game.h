#pragma once

// Todas las librerias de SDL y otras utilidades
#include <iostream>
#include <string>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Layer.h"



class Layer;
// Valores generales
#define WIDTH 480
#define HEIGHT 320

class Game
{
public:
	Game();
	void loop();
	void scale();
	TTF_Font* font;
	bool scaledToMax = false;
	float scaleLower = 1;
	SDL_Window* window; // ventana
	SDL_Renderer* renderer; // renderizador
	bool loopActive; // Juego activo

	Layer* layer;
	Layer* menuLayer;
	Layer *gameLayer;

	int currentLevel = 0;
	int finalLevel = 2;

	int input;
	int const inputKeyboard = 1;
	int const inputMouse = 2;
	int const inputGamePad = 3;

};

//Se referencia en cualquier lado con clase::enum
enum class States
{
	IDLE,
	MOVING,
	JUMPING,
	DYING,
	SHOOTING,
	DEAD
};

enum class Orientation {
	RIGHT,
	LEFT
};