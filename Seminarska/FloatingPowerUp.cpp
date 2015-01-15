#include "StdAfx.h"
#include "FloatingPowerUp.h"

FloatingPowerUp::FloatingPowerUp(void)
{
}

FloatingPowerUp::~FloatingPowerUp(void)
{
}


FloatingPowerUp::FloatingPowerUp( int xpos , int ypos , CString power_up ) {
	x = xpos;
	y = ypos;
	yvelocity = -1;
	text = power_up;
	destroy = false;
	fading_counter = 0;
}

int countDigits2( int number ) {
	int num_digits = 0;
	while ( number > 0 ) {
		number /= 10;
		num_digits++;
	}
	return num_digits;
}

void FloatingPowerUp::draw(CDC *memDC) {
	memDC->SetTextColor(RGB(255/FADING_TIME*fading_counter,255/FADING_TIME*fading_counter,255/FADING_TIME*fading_counter));
	memDC->SetBkColor(RGB(220,220,255));
	memDC->TextOutW(x,y,text,text.GetLength());
	memDC->SetTextColor(RGB(0,0,0));
}

void FloatingPowerUp::update() {
	y += yvelocity;
	fading_counter++;
	if ( fading_counter > FADING_TIME ) {
		destroy = true;
	}
}

bool FloatingPowerUp::checkBounds() {
	return destroy;
}
