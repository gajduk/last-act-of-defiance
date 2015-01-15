#include "StdAfx.h"
#include "Ship.h"
#include "missile.h"

Ship::Ship(void)
{
}

Ship::~Ship(void)
{
}

void Ship::draw(CDC *memDC) {

}

void Ship::update() {

}

bool Ship::checkMissile( Missile &m ) {
	return ( m.x>=x-10 && m.x <= x+50 ) && ( m.y >= y && m.y <= y+40 );
}

void Ship::updateHealth( int damage ) {
	if ( health + damage > INIT_HEALTH ) resetHealth();
	health += damage;
}

void Ship::resetHealth ( ) {
	health = INIT_HEALTH;
}
