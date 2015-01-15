#include "StdAfx.h"
#include "Background.h"
#include "GameClass.h"

Background::Background(void)
{
	x = 0;
	x1 = 1300;
	y = 0;
	xvelocity = -1;
	velocity_mutiplier = 2;
}

Background::~Background(void)
{
}

void Background::draw(CDC *memDC) {
	CBrush brush(RGB(220,220,255));
	memDC->SelectObject(brush);
	CPen pen(0,0,RGB(240,240,235));
	memDC->Rectangle(-10,-10,1200,600);
	CBrush brush1(RGB(240,240,235));
	memDC->SelectObject(&pen);
	memDC->SelectObject(&brush1);
	//cloud1
	memDC->Ellipse(x+100,y+100, x+220, y+170);
	memDC->Ellipse(x+50,y+135, x+200, y+220);
	memDC->Ellipse(x+120,y+130, x+340, y+240);

	//cloud2
	memDC->Ellipse(x+390,y+300, x+800, y+400);
	memDC->Ellipse(x+420,y+285, x+590, y+360);
	memDC->Ellipse(x+520,y+240, x+680, y+340);
	memDC->Ellipse(x+650,y+285, x+780, y+375);
	memDC->Ellipse(x+650,y+350, x+780, y+410);
	memDC->Ellipse(x+420,y+355, x+590, y+400);
	//cloud3
	memDC->Ellipse(x+850,y+160, x+980, y+270);
	memDC->Ellipse(x+920,y+120, x+1000, y+200);
	memDC->Ellipse(x+930,y+150, x+1100, y+260);
	//cloud4
	memDC->Ellipse(x1,y+200, x1+400, y+300);
	memDC->Ellipse(x1+40,y+185, x1+190, y+260);
	memDC->Ellipse(x1+110,y+140, x1+280, y+240);
	memDC->Ellipse(x1+250,y+185, x1+380, y+275);
	memDC->Ellipse(x1+250,y+250, x1+380, y+310);
	memDC->Ellipse(x1+20,y+255, x1+190, y+300);
	//cloud5
	memDC->Ellipse(x1+450,y+360, x1+580, y+470);
	memDC->Ellipse(x1+520,y+320, x1+600, y+400);
	memDC->Ellipse(x1+530,y+350, x1+700, y+460);
	//cloud6
	memDC->Ellipse(x1+850,y+60, x1+980, y+170);
	memDC->Ellipse(x1+920,y+20, x1+1000, y+100);
	memDC->Ellipse(x1+930,y+40, x1+1100, y+160);
	memDC->Ellipse(x1+1030,y+30, x1+1100, y+160);
	memDC->Ellipse(x1+930,y+50, x1+1160, y+160);
	memDC->Ellipse(x1+1030,y+110, x1+1100, y+180);



}

void Background::update() {
	if ( x < -1300 ) x = 1300;
	if ( x1 < -1300 ) x1 = 1300;
	x1 += xvelocity*velocity_mutiplier;
	x += xvelocity*velocity_mutiplier;
}
