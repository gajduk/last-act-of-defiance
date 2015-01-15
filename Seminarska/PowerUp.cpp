#include "StdAfx.h"
#include "PowerUp.h"
#include "GameClass.h"
#include "PlayerShip.h"

PowerUp::PowerUp(void)
{
}

PowerUp::~PowerUp(void)
{
}

bool PowerUp::checkBounds() {
	return destroy;
}

PowerUp::PowerUp( int xpos , int ypos , PlayerShip* player_ship , GameClass *the_game) {
	x = xpos;
	y = ypos;
	ship = player_ship;
	fading_counter = true;
	blink = false;
	destroy = false;
    game = the_game;
}

void PowerUp::draw(CDC *memDC) {
	if ( blink ) {
		if ( ((fading_counter/BLINK_RATE) % 2) == 0 ) {
			CPen pen(PS_SOLID, 2, RGB(50,200,50));
			CBrush brush(RGB(250,250,0));
			memDC->SelectObject(&pen);
			memDC->SelectObject(&brush);
			memDC->Ellipse(x,y,x+30,y+30);
			memDC->SetBkMode(0);
			memDC->TextOutW(x+10, y+10, _T("?"), 1);
			memDC->SelectStockObject(NULL_BRUSH);
			memDC->Ellipse(x+18,y+5,x+21, y+8);
		}
	}
	else {
			CPen pen(PS_SOLID, 2, RGB(50,200,50));
			CBrush brush(RGB(250,250,0));
			memDC->SelectObject(&pen);
			memDC->SelectObject(&brush);
			memDC->Ellipse(x,y,x+30,y+30);
			memDC->SetBkMode(0);
			memDC->TextOutW(x+10, y+10, _T("?"), 1);
			memDC->SelectStockObject(NULL_BRUSH);
			memDC->Ellipse(x+18,y+5,x+21, y+8);
	}
}

void PowerUp::update() {
		if ( fading_counter > FADE_DURATION ) destroy = true;
		if ( fading_counter > BLINK_TIME ) {
			blink = true;
		}
		fading_counter++;
		if ( hitTest() ) {
			destroy = true;
			game->powerUp();
		}
}

bool PowerUp::hitTest() {
	return (x+15  >  ship->x) && (x+15  <  ship->x + 80) && (y+15  >  ship->y) && (x+15  <  ship->x + 80);
}
