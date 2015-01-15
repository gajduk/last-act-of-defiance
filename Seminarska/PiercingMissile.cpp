#include "StdAfx.h"
#include "PiercingMissile.h"

int PiercingMissile::damage = 10;

PiercingMissile::PiercingMissile(void)
{
}

PiercingMissile::PiercingMissile( int xpos , int ypos , GameClass *the_game ):PlayerMissile(xpos,ypos,the_game) {
	/*xvelocity = xINIT_SPEED;
	yvelocity = yINIT_SPEED;
	game = the_game;*/
}

void PiercingMissile::update() {
	x += xvelocity;
	y += yvelocity;
	Entry* temp;
	temp = game->enemies->checkMissile(*this);
	if ( temp ) {
			EnemyShip* enemy_hit = dynamic_cast<EnemyShip*> (temp->data);
			if ( enemy_hit->health < PlayerMissile::damage ) {
				game->explodeEnemy(enemy_hit);
				game->enemies->deleteEntry(temp);			
			}
			enemy_hit->updateHealth(-PlayerMissile::damage);
	}
}

PiercingMissile::~PiercingMissile(void)
{
}

void PiercingMissile::draw(CDC *memDC) {
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CBrush brush(RGB(0, 0, 0));
	CPen pen1(PS_SOLID, 4, RGB(0, 0, 0));
	memDC->SelectObject(&brush);
	memDC->SelectObject(&pen);
	memDC->Ellipse(x,y,x+30,y+7);
	memDC->SelectObject(&pen1);
	memDC->MoveTo(x, y+4);
	memDC->LineTo(x-5, y-2);
	memDC->MoveTo(x, y+4);
	memDC->LineTo(x-5, y+9);
	memDC->MoveTo(x, y+4);
	memDC->LineTo(x-3, y+4);
}

bool PiercingMissile::checkBounds() {
	return x > GameClass::RIGHT_BOUND;
}
