#include "StdAfx.h"
#include "PlayerMissile.h"
#include "GameClass.h"
#include "EnemyShip.h"
#include "Entry.h"

int PlayerMissile::damage = 20;

PlayerMissile::PlayerMissile(void)
{
}

PlayerMissile::PlayerMissile( int xpos , int ypos , GameClass *the_game ):Missile(xpos,ypos) {
	xvelocity = xINIT_SPEED;
	yvelocity = yINIT_SPEED;
	game = the_game;
	destroy = false;
}

PlayerMissile::~PlayerMissile(void)
{
}

void PlayerMissile::draw(CDC *memDC) {
	CPen pen(PS_SOLID, 4, RGB(0, 0, 0));
	CBrush brush(RGB(0,0,0));
	memDC->SelectObject(&pen);
	memDC->SelectObject(&brush);
	memDC->Rectangle(x,y,x+15,y+10);
	memDC->MoveTo(x+15, y);
	memDC->LineTo(x+18, y+4);
	memDC->MoveTo(x+18, y+4);
	memDC->LineTo(x+15, y+8);
}

void PlayerMissile::update() {
	x += xvelocity;
	y += yvelocity;
	Entry* temp;
	temp = game->enemies->checkMissile(*this);
	if ( temp ) {
			EnemyShip* enemy_hit = dynamic_cast<EnemyShip*> (temp->data);
			if ( enemy_hit->health <= PlayerMissile::damage ) {
				game->explodeEnemy(enemy_hit);
				game->enemies->deleteEntry(temp);			
			}
			enemy_hit->updateHealth(-PlayerMissile::damage);
			destroy = true;
	}
}

bool PlayerMissile::checkBounds() {
	if ( ! destroy ) return  x > GameClass::RIGHT_BOUND;
	return destroy;
}

