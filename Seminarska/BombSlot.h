#pragma once
#include "entity.h"

class BombSlot : public Entity {
public:
	bool empty;

	BombSlot(void);
	BombSlot( int xpos , int ypos );
	~BombSlot(void);
	
	void fillSlot();
	void emptySlot();

	void draw( CDC *memDC );
};
