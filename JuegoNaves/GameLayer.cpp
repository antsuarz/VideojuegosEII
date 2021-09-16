#include "GameLayer.h"

GameLayer::GameLayer(Game* game)
	: Layer(game) {
	//llama al constructor del padre : Layer(renderer)
	init();
}

void GameLayer::init() {
	player = new Player(50, 50, game);
}

void GameLayer::processControls() {
}

void GameLayer::update() {
	cout << "update GameLayer" << endl;
}

void GameLayer::draw() {
	player->draw();
	
	SDL_RenderPresent(game->renderer); // Renderiza
}
