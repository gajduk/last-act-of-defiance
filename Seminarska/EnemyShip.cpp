#include "StdAfx.h"
#include "EnemyShip.h"
#include <time.h>
#include "GameClass.h"
#include "ship.h"

float EnemyShip::velocity_multiplier = 1;

EnemyShip::EnemyShip(void)
{	

}

bool EnemyShip::checkMissile( Missile &m ) {
	return ( m.x >= x-20 && m.x <= x+50 ) && ( m.y >= y-40 && m.y <= y+height );
}

EnemyShip::EnemyShip( int xpos , int ypos  ) {
	explode = false;
	health = 100*(GameClass::DIFFICULTY/2);
	destroy = false;
	x = xpos;
	y = ypos;
	srand ( time(NULL) );
	xvelocity = -((rand()%MAX_VELOCITY-1)+2);
	yvelocity = rand()%MAX_VELOCITY;
}

EnemyShip::~EnemyShip(void)
{
}


void EnemyShip::draw(CDC *memDC) {
	CPen pen(PS_SOLID, 4, RGB(0,0,0));
	memDC->SelectObject(&pen);
	memDC->MoveTo(x, y);
	memDC->AngleArc(x,y,20,0,180);
	CPen pen1(PS_SOLID, 2, RGB(0,0,0));
	memDC->SelectObject(&pen1);
	memDC->MoveTo(x,y);
	memDC->LineTo(x+30,y);
	memDC->AngleArc(x,y,30,180,180);
	memDC->AngleArc(x,y,28,180,180);
	memDC->AngleArc(x,y,26,180,180);
	memDC->AngleArc(x,y,24,180,180);
	memDC->AngleArc(x,y,22,180,180);
	memDC->AngleArc(x,y,20,180,180);
	memDC->AngleArc(x,y,18,180,180);
	memDC->AngleArc(x,y,16,180,180);
	memDC->AngleArc(x,y,14,180,180);
	memDC->AngleArc(x,y,12,180,180);
	memDC->AngleArc(x,y,10,180,180);
	memDC->AngleArc(x,y,8,180,180);
	memDC->AngleArc(x,y,6,180,180);
	memDC->AngleArc(x,y,4,180,180);
	memDC->AngleArc(x,y,2,180,180);
	memDC->MoveTo(x-10,y-30);
	memDC->LineTo(x-15,y-40);
	memDC->MoveTo(x+10,y-30);
	memDC->LineTo(x+15,y-40);
	memDC->SelectObject(&pen);
	memDC->MoveTo(x-15,y+25);
	memDC->LineTo(x-25,y+40);
	memDC->MoveTo(x+15,y+25);
	memDC->LineTo(x+25,y+40);
}

void EnemyShip::update() {
	x += xvelocity*EnemyShip::velocity_multiplier;
	y += yvelocity*EnemyShip::velocity_multiplier;
	if ( y < GameClass::ENEMY_BOTTOM_BOUND ) {
		yvelocity *= -1;
	}
	if ( y > GameClass::ENEMY_TOP_BOUND ) {
		yvelocity *= -1;
	}
}

bool EnemyShip::checkBounds() {
	if ( ! destroy ) return x < GameClass::LEFT_BOUND;
	return destroy;
}

void EnemyShip::updateHealth( int damage ) {
	Ship::updateHealth(damage);
	if ( health <= 0 ) {
		destroy = true;
		explode = true;
	}
}
