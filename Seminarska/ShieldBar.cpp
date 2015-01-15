#include "StdAfx.h"
#include "ShieldBar.h"
#include "UserHUD.h"
#include "PlayerShip.h"

ShieldBar::ShieldBar(int duration) {
	shield_duration = duration;
	blink_counter = 0;
	x = UserHUD::SHIELD_BAR_X;
	y = UserHUD::SHIELD_BAR_Y;
	shield_strength = PlayerShip::INIT_SHIELD_STRENGTH;
	blink_on = false;
}

ShieldBar::~ShieldBar(void) {
}

void ShieldBar::update( int new_value) {
	shield_strength = new_value;
}

void ShieldBar::draw(CDC *memDC) {
	if ( blink_counter < shield_duration ) {
		if ( blink_on ) {
			if ( (blink_counter/5)%2 == 0 ) {
				memDC->SetBkMode(0);
				memDC->TextOutW(x,y,_T("Shield"),6);
				int distance = 20;
				CPen pen(PS_SOLID,10,RGB(50,200,50));
				memDC->SelectObject(&pen);
				int xoffset = 70;
				for ( int i = 0 ; i < shield_strength ; i++ ) {
					memDC->MoveTo(x+xoffset+i*distance,y);
					memDC->LineTo(x+xoffset+i*distance,y+20);
				}
			}
			
		}
		else {
				if ( blink_counter > shield_duration*0.8 ) {
					blink_on = true;
				}
				memDC->SetBkMode(0);
				memDC->TextOutW(x,y,_T("Shield"),6);
				int distance = 20;
				CPen pen(PS_SOLID,10,RGB(50,200,50));
				memDC->SelectObject(&pen);
				int xoffset = 70;
				for ( int i = 0 ; i < shield_strength ; i++ ) {
					memDC->MoveTo(x+xoffset+i*distance,y);
					memDC->LineTo(x+xoffset+i*distance,y+20);
				}
		}
		
		blink_counter++;	
	}
}

void ShieldBar::update() {


}
