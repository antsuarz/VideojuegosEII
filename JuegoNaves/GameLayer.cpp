#include "GameLayer.h"

GameLayer::GameLayer(Game* game)
	: Layer(game) {
	//llama al constructor del padre : Layer(renderer)
	init();
}

void GameLayer::init() {
}

void GameLayer::processControls() {
}

void GameLayer::update() {
	cout << "update GameLayer" << endl;
}

void GameLayer::draw() {
	SDL_RenderPresent(game->renderer); // Renderiza
}
