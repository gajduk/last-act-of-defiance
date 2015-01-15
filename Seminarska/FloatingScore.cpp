#include "StdAfx.h"
#include "FloatingScore.h"

FloatingScore::FloatingScore(void)
{
}

FloatingScore::~FloatingScore(void)
{
}

FloatingScore::FloatingScore( int xpos , int ypos , int init_value ) {
	x = xpos;
	y = ypos;
	yvelocity = -1;
	value = init_value;
	destroy = false;
	fading_counter = 0;
}

int countDigits1( int number ) {
	int num_digits = 0;
	while ( number > 0 ) {
		number /= 10;
		num_digits++;
	}
	return num_digits;
}

void FloatingScore::draw(CDC *memDC) {
	CString score_print;
	score_print.Format(_T("+ %d"),value);
	memDC->SetBkColor(RGB(220,220,255));
	memDC->SetTextColor(RGB(255/FADING_TIME*fading_counter,255/FADING_TIME*fading_counter,255/FADING_TIME*fading_counter));
	memDC->TextOutW(x,y,score_print,3+countDigits1(value));
	memDC->SetTextColor(RGB(0,0,0));
}

void FloatingScore::update() {
	y += yvelocity;
	fading_counter++;
	if ( fading_counter > FADING_TIME ) {
		destroy = true;
	}
}

bool FloatingScore::checkBounds() {
	return destroy;
}
