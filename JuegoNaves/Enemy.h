#pragma once

#include "Actor.h"
#include "Animation.h" 

class Enemy : public Actor
{
public:
	Enemy(float x, float y, Game* game);
	void draw() override; // Va a sobrescribir
	void update();
	void impacted(); // Recibe impacto y pone animación de morir

	States state = States::MOVING;
	Animation* aDying;
	Animation* aMoving;
	Animation* animation; // Referencia a la animación mostrada

};

