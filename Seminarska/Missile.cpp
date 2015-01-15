#include "StdAfx.h"
#include "Missile.h"

Missile::Missile( int xpos , int ypos )
{
	destroy= false;
	x = xpos;
	y = ypos;
}

Missile::Missile( )
{
}

Missile::~Missile(void)
{
}

void Missile::draw(CDC *memDC) {

}
void Missile::update() {

}

