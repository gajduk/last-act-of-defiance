#pragma once
#include "ship.h"
#include <time.h>

class PlayerShip : public Ship {
public:
	static const int missile_xoffset = 50;
	static const int missile_yoffset = 22;
	static const int INIT_SHIELD_STRENGTH = 5;
	static const int MIN_SHIELD_DURATION = 300;
	static const int MOVE_BOUND_UP = 10;
	static const int MOVE_BOUND_DOWN = 440;
	static const int MOVE_BOUND_LEFT = 20;
	static const int MOVE_BOUND_RIGHT = 950;

	bool key_pressed_up;
	bool key_pressed_fire;
	bool key_pressed_down;
	bool key_pressed_left;
	bool key_pressed_right;
	bool fire_missile;
	int score_multiplier;
	bool game_over;
	bool shield_on;
	int shield_duration;
	int shield_strength;
	int shield_counter;
	int no_hit_duration;

	PlayerShip();
	~PlayerShip(void);

	void shieldDown();
	void raiseShield();

	void draw(CDC *memDC);
	void update();
	void updateHealth(int damage);

	
	

};
