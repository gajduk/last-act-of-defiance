#pragma once
#include "entity.h"
#include "PlayerShip.h"
#include "GameClass.h"

class PowerUp : public Entity {
private:
	int fading_counter;
	int blinking_counter;
	bool blink;
public:
	static const int FADE_DURATION = 120;
	static const int BLINK_RATE = 5;
	static const int BLINK_TIME = 60;

	PlayerShip *ship;
	GameClass *game;

	PowerUp(void);
	PowerUp( int xpos , int ypos , PlayerShip* player_ship , GameClass *the_game);
	~PowerUp(void);

	bool hitTest();
	
	void draw(CDC *memDC);
	bool checkBounds();
	void update();

};
