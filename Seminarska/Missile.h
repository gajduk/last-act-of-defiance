#pragma once
#include "entity.h"

class Missile : public Entity {
public:
	Missile(void);
	Missile( int xpos , int ypos );
	~Missile(void);

	void draw(CDC *memDC);
	void update();
};
