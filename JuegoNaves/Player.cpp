#include "Player.h"

Player::Player(float x, float y, Game* game)
	: Actor("res/jugador.png", x, y, 35, 35, game) {

	audioShoot = new Audio("res/efecto_disparo.wav", false);

	aShootingRight = new Animation("res/jugador_disparando_derecha.png",
		width, height, 160, 40, 6, 4, false, game);
	aShootingLeft = new Animation("res/jugador_disparando_izquierda.png",
		width, height, 160, 40, 6, 4, false, game);

	aIdleRight = new Animation("res/jugador_idle_derecha.png", width, height,
		320, 40, 6, 8, true, game);
	aIdleLeft = new Animation("res/jugador_idle_izquierda.png", width, height,
		320, 40, 6, 8, true, game);
	aRunningRight = new Animation("res/jugador_corriendo_derecha.png", width, height,
		320, 40, 6, 8, true, game);
	aRunningLeft = new Animation("res/jugador_corriendo_izquierda.png", width, height,
		320, 40, 6, 8, true, game);
	animation = aIdleRight;
	orientation = Orientation::RIGHT;
}

void Player::update() {
	if (vx > 0) {
		orientation = Orientation::RIGHT;
	}
	if (vx < 0) {
		orientation = Orientation::LEFT;
	}

	if (collisionDown == true) {
		onAir = false;
	}
	else {
		onAir = true;
	}

	bool hasAnimationEnded = animation->update();
	if (hasAnimationEnded) {
		// Estaba disparando
		if (state == States::SHOOTING) {
			state = States::MOVING;
		}
	}

	// Selección de animación basada en estados
	if (state == States::SHOOTING) {
		if (orientation ==Orientation::RIGHT) {
			animation = aShootingRight;
		}
		if (orientation == Orientation::LEFT) {
			animation = aShootingLeft;
		}
	}
	
	if (state == States::MOVING || state == States::IDLE) {
		if (vx != 0) {
			if (orientation == Orientation::RIGHT) {
				animation = aRunningRight;
			}
			if (orientation == Orientation::LEFT) {
				animation = aRunningLeft;
			}
		}
		if (vx == 0) {
			if (orientation == Orientation::RIGHT) {
				animation = aIdleRight;
			}
			if (orientation == Orientation::LEFT) {
				animation = aIdleLeft;
			}
		}
	}


	if (shootTime > 0) {
		shootTime--;
	}
}

void Player::jump() {
	if (!onAir) {
		vy = -16;
		onAir = true;
	}

}


void Player::moveX(float axis) {
	vx = axis * 3;
}

void Player::moveY(float axis) {
	vy = axis * 3;
}

Projectile* Player::shoot() {
	if (shootTime == 0) {
		audioShoot->play();
		state = States::SHOOTING;
		shootTime = shootCadence;
		auto proyectile = new Projectile(x, y, game);
		if (orientation == Orientation::LEFT) {
			proyectile->vx *= -1;
		}
		return proyectile;
	}
	else {
		return NULL;
	}

}

void Player::draw(float scrollX) {
	animation->draw(x - scrollX, y);
}

