#pragma once
#include "HealthBar.h"
#include "ScoreMultiplier.h"
#include "BombSlot.h"
//#include "ShieldBar.h"
//#include "Score.h"

#ifndef __FOO_H_INCLUDE
	#define __FOO_H_INCLUDE
	#ifndef __FOO_H_DEFINED
		#define __FOO_H_DEFINED
		class UserHUD;
		#include "ShieldBar.h"
		#include "Score.h"
	#endif

class UserHUD {
public:
	int num_bombs;
	static const int MAX_BOMBS = 3;
	static const int HEALTH_BAR_X = 500;
	static const int HEALTH_BAR_Y = 50;
	static const int SCORE_X = 300;
	static const int SCORE_Y = 450;
	static const int BOMB_SLOT_X = 20;
	static const int BOMB_SLOT_Y = 30;
	static const int BOMB_SLOT_DISTANCE = 60;
	static const int MULTIPLIER_X = 500;
	static const int MULTIPLIER_Y = 450;
	static const int SHIELD_BAR_X = 500;
	static const int SHIELD_BAR_Y = 80;

	int score_multiplier;
	HealthBar *healthbar;
	Score *score;
	ScoreMultiplier *multiplier;
	BombSlot *bombs[3];
	ShieldBar *shieldbar;
	UserHUD(void);
	~UserHUD(void);

	void draw(CDC *memDC);
	void updateHealthBar( int health );
	void updateMultiplier( int new_multiplier );
	void dropBomb();
	void storeBomb();
	void showShieldBar(int duration);
	void updateShieldBar(int new_value);
	void hideShieldBar();
	void addScore( int number );
	
};
#endif