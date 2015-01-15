#pragma once
#include "ship.h"

class EnemyShip : public Ship {
	
public:
	static const int MISSILE_XOFFSET = 0;
	static const int MISSILE_YOFFSET = 22;
	static const int MAX_VELOCITY = 3;

	static float velocity_multiplier;

	bool explode;

	EnemyShip(void);
	EnemyShip( int xpos , int ypos  );
	~EnemyShip(void);

	
	void draw(CDC *memDC);
	void update();
	bool checkBounds();
	
	void updateHealth( int damage );
	bool checkMissile( Missile &m );
};
