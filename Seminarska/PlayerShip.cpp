#include "StdAfx.h"
#include "PlayerShip.h"
#include "GameClass.h"
#include "math.h"


PlayerShip::PlayerShip( )
{
	shield_on = false;
	xvelocity = 5;
	yvelocity = 5;
	x = 200;
	y = 100;
	key_pressed_up = false;
	key_pressed_down = false;
	key_pressed_left = false;
	key_pressed_right = false;
	key_pressed_fire = false;
	fire_missile = false;
	fire_rate = 10;
	missile_counter = 10;
	health = INIT_HEALTH;
	game_over = false;
	no_hit_duration = 0;
	score_multiplier = 1;
}

PlayerShip::~PlayerShip(void)
{
}

void PlayerShip::updateHealth( int damage ) {
	if ( shield_on ) {
		if ( damage < 0 )
			shield_strength--;
		if ( shield_strength < 0 ) shieldDown();
	}
	else {
		if ( damage < 0 ) {
			no_hit_duration = 0;
			score_multiplier = 1;
		}
		Ship::updateHealth(damage);
		if ( health < 0 ) {
			game_over = true;
		}
	}

}

void PlayerShip::draw( CDC *memDC ) {
		
	
	if ( shield_on ) {
		CPen pen(PS_SOLID, 1, RGB(30,144,255));
		CBrush brush(RGB(30,144,255));
		memDC->SelectObject(&pen);
		memDC->SelectObject(&brush);
		memDC->Ellipse(x,y,x+90,y+55);
		memDC->MoveTo(x+30,y+2);
		for(int j=0; j<25; j++){
			memDC->LineTo(x+j-20,y+j+2);
			memDC->MoveTo(x+30,y+j+2);
		}
		memDC->MoveTo(x+40,y+53);
		for(int j=0; j<25; j++){
			memDC->LineTo(x+j-20,y-j+53);
			memDC->MoveTo(x+40,y-j+53);
		}
		CPen pen1(PS_SOLID,1, RGB(255,255,255));
		memDC->SelectObject(&pen1);
		for(float i=1; i<20; i++) {
			memDC->MoveTo(x+50,y+3+i);
			float a=asin((float)(20-i)/20.0);
			memDC->LineTo(x-tan(a)*(20-i)*0.73+84,y+3+i);
		}
		CPen pen2(PS_DOT, 3, RGB(0,200,0));
		memDC->SelectStockObject(NULL_BRUSH);
		memDC->SelectObject(&pen2);
		memDC->Ellipse(x-50,y-25,x+115,y+80);
	}
	else {
		CPen pen(PS_SOLID, 1, RGB(30,144,255));
		CBrush brush(RGB(30,144,255));
		memDC->SelectObject(&pen);
		memDC->SelectObject(&brush);
		memDC->Ellipse(x,y,x+90,y+55);
		memDC->MoveTo(x+30,y+2);
		for(int j=0; j<25; j++){
			memDC->LineTo(x+j-20,y+j+2);
			memDC->MoveTo(x+30,y+j+2);
		}
		memDC->MoveTo(x+40,y+53);
		for(int j=0; j<25; j++){
			memDC->LineTo(x+j-20,y-j+53);
			memDC->MoveTo(x+40,y-j+53);
		}
		CPen pen1(PS_SOLID,1, RGB(255,255,255));
		memDC->SelectObject(&pen1);
		for(float i=1; i<20; i++) {
			memDC->MoveTo(x+50,y+3+i);
			float a=asin((float)(20-i)/20.0);
			memDC->LineTo(x-tan(a)*(20-i)*0.73+84,y+3+i);
		}
	}
}

void PlayerShip::update() {
	no_hit_duration++;
	if ( no_hit_duration > 200 ) {
		score_multiplier++;
		no_hit_duration = 1;
	}
	if ( key_pressed_up ) {
		if ( y > MOVE_BOUND_UP ) y -= yvelocity;
	}
	if ( key_pressed_down ) {
		if ( y < MOVE_BOUND_DOWN ) y += yvelocity;
	}
	if ( key_pressed_left ) {
		if ( x > MOVE_BOUND_LEFT ) x -= xvelocity;
	}
	if ( key_pressed_right ) {
		if ( x < MOVE_BOUND_RIGHT ) x += xvelocity;
	}
	if ( missile_counter > fire_rate ) {
		if ( key_pressed_fire ) {
			fire_missile = true;
			missile_counter = 0;
		}
	}
	else {
			missile_counter++;
	}
	if ( shield_on ) {
		if ( shield_duration < shield_counter ) {
			shieldDown();
		}
		else {
			shield_counter++;
		}
	}
}

void PlayerShip::raiseShield() {
	shield_on = true;
	srand(time(NULL));
	shield_counter = 0;
	shield_duration = MIN_SHIELD_DURATION+rand()%700;
	shield_strength = INIT_SHIELD_STRENGTH;
}

void PlayerShip::shieldDown() {
	shield_on = false;
}

