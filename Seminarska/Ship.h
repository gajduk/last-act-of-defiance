#pragma once
#include "entity.h"
#include "missile.h"

class Ship : public Entity {
public:
	static const int height = 50;
	static const int width = 70;
	static const int INIT_HEALTH = 500;

	int health;
	int missile_counter;
	int fire_rate;

	Ship(void);
	~Ship(void);

	virtual void updateHealth( int damage );

	void resetHealth ();
	virtual bool checkMissile( Missile &m );

	void draw(CDC *memDC);
	void update();
	

};
