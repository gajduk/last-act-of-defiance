#pragma once
#include "missile.h"
#include "PlayerShip.h"

class EnemyMissile : public Missile {
private:
	PlayerShip *ship;
public:
	static const int xINIT_SPEED = -10;
	static const int yINIT_SPEED = 0;
	static const int DAMAGE = -20;

	static float velocity_multiplier;
	
	EnemyMissile(void);
	EnemyMissile( int xpos , int ypos , PlayerShip  *ship1 );
	~EnemyMissile(void);

	bool checkBounds();
	void draw(CDC *memDC);
	void update();
	
};
