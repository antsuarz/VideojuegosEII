#pragma once

#include "Actor.h"
#include "Projectile.h" 
#include "Animation.h" 
#include "Audio.h"

class Player : public Actor
{
public:
	Player(float x, float y, Game* game);
	void update();
	void moveX(float axis);
	void moveY(float axis);
	void loseLife();
	int lifes = 3;
	int invulTime = 0;
	Projectile* shoot();
	int shootCadence = 30;
	int shootTime = 0;
	void jump();
	bool onAir;
	void draw(float scrollX = 0) override; // Va a sobrescribir
	Animation* aIdleRight;
	Animation* aIdleLeft;
	Animation* aRunningRight;
	Animation* aRunningLeft;
	Animation* aShootingRight;
	Animation* aShootingLeft;
	Animation* aJumpingRight;
	Animation* aJumpingLeft;
	Animation* animation; // Referencia a la animación mostrada
	
	Audio* audioShoot;

	Orientation orientation = Orientation::RIGHT;
	States state = States::IDLE;
};

