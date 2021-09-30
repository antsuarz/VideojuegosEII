#include "Enemy.h"

Enemy::Enemy(float x, float y, Game* game)
	: Actor("res/enemigo.png", x, y, 36, 40, game) {
	vx = 0;
	//Animacion del enemigo

	state = States::MOVING;

	aDying = new Animation("res/enemigo_morir.png", width, height,
		280, 40, 6, 8, false, game);

	aMoving = new Animation("res/enemigo_movimiento.png", width, height,
		108, 40, 6, 3, true, game);
	animation = aMoving;

}

void Enemy::update() {
	// Actualizar la animación
	bool endAnimation = animation->update();

	// Acabo la animación, no sabemos cual
	if (endAnimation) {
		// Estaba muriendo
		if (state == States::DYING) {
			state = States::DEAD;
		}
	}

	if (state == States::MOVING) {
		animation = aMoving;
	}
	if (state == States::DYING) {
		animation = aDying;
		vx = 0;
	}

	if (state != States::DYING) {
		vx = -1; 
	}

}

void Enemy::draw(float scrollX) {
	animation->draw(x - scrollX, y);
}

void Enemy::impacted() {
	if (state != States::DYING) {
		state = States::DYING;
	}
}

