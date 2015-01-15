#include "StdAfx.h"
#include "Explosion.h"

Explosion::Explosion(void)
{
}

Explosion::~Explosion(void)
{
}

void Explosion::update( ) {
	current_frame++;
	if ( current_frame > total_frames ) {
		destroy = true;	
	}
}


void Explosion::draw(CDC *memDC) {

	if ( current_frame == 1 ) { //first frame 
		CPen pen(PS_SOLID,5,RGB(0,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(255,255,255));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x+22,y+22,x+27,y+27);
	}

	if ( current_frame == 2 ) { //second frame 
		CPen pen(PS_SOLID,5,RGB(0,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(200,200,200));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x+17,y+17,x+32,y+32);
	}
	if ( current_frame == 3 ) { //and so on...
		CPen pen(PS_SOLID,7,RGB(100,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(100,100,0));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x+15,y+15,x+35,y+35);
	}
	if ( current_frame == 4 ) { 
		CPen pen(PS_SOLID,7,RGB(200,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(200,200,0));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x+10,y+10,x+40,y+40);
	}
	if ( current_frame == 5 ) { 
		CPen pen(PS_SOLID,7,RGB(255,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(255,255,0));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x,y,x+50,y+50);
	}
	if ( current_frame == 6 ) { 
		CPen pen(PS_SOLID,7,RGB(255,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(255,255,0));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x-5,y-5,x+60,y+60);
	}
	if ( current_frame == 7 ) { 
		CPen pen(PS_SOLID,7,RGB(255,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(255,255,0));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x,y,x+50,y+50);
	}
	if ( current_frame == 8 ) { 
		CPen pen(PS_SOLID,7,RGB(255,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(255,255,0));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x+10,y+10,x+40,y+40);
	}
	if ( current_frame == 9 ) { 
		CPen pen(PS_SOLID,7,RGB(255,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(255,255,0));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x,y,x+50,y+50);
	}
	if ( current_frame == 10 ) { 
		CPen pen(PS_SOLID,7,RGB(255,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(255,255,0));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x+10,y,x+60,y+50);
		CPen pen1(PS_SOLID,10,RGB(200,50,50));
		memDC->SelectObject(&pen1);
		memDC->MoveTo(x-5,y-5);
		memDC->LineTo(x+60,y);
		memDC->MoveTo(x,y+60);
		memDC->LineTo(x+60,y+60);
	}
	if ( current_frame == 11 ) { 
		CPen pen(PS_SOLID,7,RGB(255,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(255,255,0));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x,y-10,x+50,y+40);
		CPen pen1(PS_SOLID,10,RGB(200,50,50));
		memDC->SelectObject(&pen1);
		memDC->MoveTo(x-5,y-5);
		memDC->LineTo(x,y+60);
		memDC->MoveTo(x+60,y);
		memDC->LineTo(x+60,y+60);
	}
	if ( current_frame == 12 ) { 
		CPen pen(PS_SOLID,7,RGB(255,0,0));
		memDC->SelectObject(&pen);
		CBrush brush(RGB(255,255,0));
		memDC->SelectObject(&brush);
		memDC->Ellipse(x+10,y+10,x+55,y+50);
		CPen pen1(PS_SOLID,10,RGB(200,50,50));
		memDC->SelectObject(&pen1);
		memDC->MoveTo(x,y+15);
		memDC->LineTo(x+70,y);
		memDC->MoveTo(x,y+70);
		memDC->LineTo(x+50,y+50);

	}
	if ( current_frame == 13 ) { 
		CPen pen(PS_SOLID,5,RGB(200,200,200));
		memDC->SelectObject(&pen);
		memDC->Ellipse(x-5,y-10,x+65,y+55);
		CPen pen1(PS_SOLID,10,RGB(200,50,50));
		memDC->SelectObject(&pen1);
		memDC->MoveTo(x,y-10);
		memDC->LineTo(x+65,y+50);
		memDC->MoveTo(x+65,y-10);
		memDC->LineTo(x-10,y+70);
	}
	if ( current_frame == 14 ) { 
		CPen pen(PS_SOLID,5,RGB(200,200,200));
		memDC->SelectObject(&pen);
		memDC->Ellipse(x-5,y+5,x+55,y+60);
		memDC->MoveTo(x-5,y-5);
		memDC->LineTo(x+60,y+60);
		memDC->MoveTo(x+60,y-5);
		memDC->LineTo(x-5,y+60);
	}
	if ( current_frame == 15 ) { 
		CPen pen(PS_SOLID,5,RGB(200,200,200));
		memDC->SelectObject(&pen);
		memDC->Ellipse(x,y,x+50,y+50);
	}
}

bool Explosion::checkBounds( ) {
	return destroy;
}

Explosion::Explosion( int xpos , int ypos ) {
	x = xpos;
	y = ypos;
	current_frame = 0;
	destroy = false;
}
