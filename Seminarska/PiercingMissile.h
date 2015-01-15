#pragma once
#include "playermissile.h"

class PiercingMissile : public PlayerMissile {
public:
	static int damage;
	
	PiercingMissile(void);
	PiercingMissile( int xpos , int ypos , GameClass* the_game );
	~PiercingMissile(void);

	bool checkBounds();
	void draw(CDC *memDC);
	void update();
};
