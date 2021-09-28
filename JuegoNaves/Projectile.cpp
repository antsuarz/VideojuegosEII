#include "Projectile.h"

Projectile::Projectile(float x, float y, Game* game) :
	Actor("res/disparo_jugador2.png", x, y, 10, 10, game) {
	vx = 9;
}

void Projectile::update() {
	x = x + vx;
}
