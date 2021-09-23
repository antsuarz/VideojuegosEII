#pragma once

#include "Actor.h"
#include "Projectile.h" 
#include "Animation.h" 

class Player : public Actor
{
public:
	Player(float x, float y, Game* game);
	void update();
	void moveX(float axis);
	void moveY(float axis);
	Projectile* shoot();
	int shootCadence = 30;
	int shootTime = 0;

	void draw() override; // Va a sobrescribir
	Animation* aIdleRight;
	Animation* animation; // Referencia a la animación mostrada
};

