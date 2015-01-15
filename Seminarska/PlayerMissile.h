#pragma once
#include "missile.h"
#include "GameClass.h"

class PlayerMissile: public Missile {
public:
	static const int xINIT_SPEED = 10;
	static const int yINIT_SPEED = 0;

	static int damage;

	GameClass* game;

	PlayerMissile(void);
	PlayerMissile( int xpos , int ypos , GameClass* the_game );
	~PlayerMissile(void);

	bool checkBounds();
	void draw(CDC *memDC);
	void update();
	
};
