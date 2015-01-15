#include "StdAfx.h"
#include "EnemyMissile.h"
#include "GameClass.h"
#include "PlayerShip.h"

float EnemyMissile::velocity_multiplier = 1;

EnemyMissile::EnemyMissile(void) {
	xvelocity = xINIT_SPEED;
	yvelocity = yINIT_SPEED;
}

EnemyMissile::~EnemyMissile(void) {
}

void EnemyMissile::draw(CDC *memDC) {
		CPen pen(PS_SOLID, 2, RGB(0,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(255,0,0));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x, y, x+10, y+10);
	
}

void EnemyMissile::update() {
	x += xvelocity*EnemyMissile::velocity_multiplier;
	y += yvelocity*EnemyMissile::velocity_multiplier;
	if ( ship->checkMissile(*this) ) {
		ship->updateHealth(DAMAGE);
		destroy = true;
	}

}

bool EnemyMissile::checkBounds() {
	if ( ! destroy ) return x < GameClass::LEFT_BOUND;
	return destroy;
}

EnemyMissile::EnemyMissile( int xpos , int ypos , PlayerShip  *ship1 ) {
	x = xpos;
	y = ypos;
	xvelocity = xINIT_SPEED;
	yvelocity = yINIT_SPEED;
	ship = ship1;
	destroy = false;
}
