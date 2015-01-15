#include "StdAfx.h"
#include "BombSlot.h"

BombSlot::BombSlot(void)
{
}

BombSlot::~BombSlot(void)
{
}

BombSlot::BombSlot( int xpos , int ypos ) {
	x = xpos;
	y = ypos;
	empty = true;
}

void BombSlot::fillSlot() {
	empty = true;
}

void BombSlot::emptySlot() {
	empty = false;
}

void BombSlot::draw(CDC *memDC) {
	if ( empty ) {
		CBrush brush(RGB(0,0,255));
		memDC->SelectObject(&brush);
		CPen pen(PS_SOLID, 2, RGB(0,0,0));
		memDC->SelectObject(&pen);
		memDC->Ellipse(x,y,x+45,y+30);

		CPen pen1(PS_SOLID, 1, RGB(0,0,255));
		memDC->SelectObject(&pen1);
		memDC->MoveTo(x-9, y+2);
		memDC->LineTo(x-9, y+28);
		memDC->MoveTo(x-8, y+3);
		memDC->LineTo(x-8, y+27);
		memDC->MoveTo(x-7, y+4);
		memDC->LineTo(x-7, y+26);
		memDC->MoveTo(x-6, y+5);
		memDC->LineTo(x-6, y+25);
		memDC->MoveTo(x-5, y+6);
		memDC->LineTo(x-5, y+24);
		memDC->MoveTo(x-4, y+7);
		memDC->LineTo(x-4, y+23);
		memDC->MoveTo(x-3, y+8);
		memDC->LineTo(x-3, y+22);
		memDC->MoveTo(x-2, y+9);
		memDC->LineTo(x-2, y+21);
		memDC->MoveTo(x-1, y+10);
		memDC->LineTo(x-1, y+20);
		memDC->MoveTo(x, y+11);
		memDC->LineTo(x, y+19);
		memDC->MoveTo(x+1, y+12);
		memDC->LineTo(x+1, y+18);
		memDC->SelectObject(&pen);
		memDC->MoveTo(x, y+13);
		memDC->LineTo(x-10, y+1);
		memDC->MoveTo(x, y+17);
		memDC->LineTo(x-10, y+29);
		memDC->MoveTo(x-10, y+1);
		memDC->LineTo(x-10, y+29);
		memDC->SetBkMode(0);
		memDC->TextOutW(x+17, y+6, _T("B"), 1);

	}
	else {
		CPen pen(PS_SOLID, 2, RGB(0,0,0));
		memDC->SelectObject(&pen);
		memDC->SelectStockObject(NULL_BRUSH);
		memDC->Ellipse(x,y,x+45,y+30);
		memDC->MoveTo(x, y+13);
		memDC->LineTo(x-10, y+1);
		memDC->MoveTo(x, y+17);
		memDC->LineTo(x-10, y+29);
		memDC->MoveTo(x-10, y+1);
		memDC->LineTo(x-10, y+29);
		memDC->SetBkMode(0);
		memDC->TextOutW(x+17, y+6, _T("B"), 1);
		CPen pen1(PS_SOLID, 4, RGB(255,255,255));
		memDC->SelectObject(&pen1);
		memDC->MoveTo(x-2, y+15);
		memDC->LineTo(x+4, y+15);


	}
}
