#include "GameLayer.h"

GameLayer::GameLayer(Game* game)
	: Layer(game) {
	//llama al constructor del padre : Layer(renderer)
	init();
}

void GameLayer::init() {
	player = new Player(50, 50, game);
	background = new Background("res/fondo.png", WIDTH * 0.5, HEIGHT * 0.5, game);
}

void GameLayer::processControls() {
}

void GameLayer::update() {
	cout << "update GameLayer" << endl;
}

void GameLayer::draw() {
	background->draw();
	player->draw();
	
	SDL_RenderPresent(game->renderer); // Renderiza
}
