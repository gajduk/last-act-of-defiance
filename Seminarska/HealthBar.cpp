#include "StdAfx.h"
#include "HealthBar.h"
#include "UserHUD.h"

HealthBar::HealthBar(void)
{
	x = UserHUD::HEALTH_BAR_X;
	y = UserHUD::HEALTH_BAR_Y;
	value = 100;
}

void HealthBar::draw(CDC *memDC) {
	int maxHP = MAX_VALUE/5;
	int curHP = (value-1)/5 + 1;
	CPen pen(PS_SOLID,2,RGB(0,0,0));
	memDC->SelectObject(&pen);
	CBrush brush1(RGB(100,200,100));
	memDC->SelectObject(&brush1);
	const int distance=10;
	if ( value < 5 ) curHP = 1;
	if ( value == 0 ) curHP = 0;
	for(int i=0; i<curHP; i++) {
		memDC->Rectangle(x+i*distance,y,x+(i+1)*distance,y+20);
	}
	CBrush brush(RGB(100,100,100));
	memDC->SelectObject(&brush);
	for(int i=curHP; i<maxHP; i++) {
		memDC->Rectangle(x+i*distance,y,x+(i+1)*distance,y+20);
	}
}

void HealthBar::updateValue( int new_value ) {
	value = new_value;
}



HealthBar::~HealthBar(void)
{
}
