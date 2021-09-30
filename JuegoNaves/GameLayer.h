#pragma once

#include "Layer.h"
#include "Player.h"
#include "Audio.h" 
#include "Background.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Text.h"
#include "Tile.h"

#include <list>

#include <fstream> // Leer ficheros
#include <sstream> // Leer líneas / String



class GameLayer : public Layer
{
public:
	GameLayer(Game* game);
	void init() override;
	void processControls() override;
	void update() override;
	void draw() override;
	void keysToControls(SDL_Event event);
	int newEnemyTime = 0;
	void loadMap(string name);
	void loadMapObject(char character, float x, float y);
	int mapWidth;
	list<Tile*> tiles;
	void calculateScroll();
	float scrollX;

	Audio* audioBackground;

	Text* textPoints;
	int points;


	Player* player;
	Background* background;
	Actor* backgroundPoints;
	bool controlShoot = false;
	int controlMoveY = 0;
	int controlMoveX = 0;

	list<Enemy*> enemies;
	list<Projectile*> projectiles;

};

