#include "StdAfx.h"
#include "Entity.h"

Entity::Entity(void)
{
}

void Entity::draw(CDC *memDC) {
	//memDC->Rectangle(x,y,x+50,y+50);
}

Entity::~Entity(void)
{
}

void Entity::update() {

}

bool Entity::checkBounds() {
	return false;
}


