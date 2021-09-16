#pragma once

#include "Layer.h"
#include "Player.h"
#include "Background.h"

class GameLayer : public Layer
{
public:
	GameLayer(Game* game);
	void init() override;
	void processControls() override;
	void update() override;
	void draw() override;
	Player* player;
	Background* background;
};

