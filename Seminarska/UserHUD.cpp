#include "StdAfx.h"
#include "UserHUD.h"
#include "GameClass.h"
#include "HealthBar.h"
#include "Ship.h"
#include "Score.h"
#include "ScoreMultiplier.h"
#include "BombSlot.h"
#include "ShieldBar.h"

UserHUD::UserHUD(void)
{
	healthbar = new HealthBar();
	score = new Score();
	score_multiplier = 1;
	multiplier = new ScoreMultiplier();
	num_bombs = MAX_BOMBS;
	shieldbar = NULL;
	for ( int i = 0 ; i < num_bombs ; i++ ) {
		bombs[i] = new BombSlot(BOMB_SLOT_X+BOMB_SLOT_DISTANCE*i,BOMB_SLOT_Y);
	}
}

void UserHUD::updateShieldBar(int new_value) {
	if ( shieldbar ) shieldbar->update(new_value);
}


UserHUD::~UserHUD(void) {
	delete healthbar;
	delete score;
	delete multiplier;
	for ( int i = 0 ; i < MAX_BOMBS ; i++ ) {
		delete bombs[i];
	}
}

void UserHUD::addScore( int number ) {
	score->addScore(number*score_multiplier);
}

void UserHUD::updateMultiplier( int new_multiplier ) {
	score_multiplier = new_multiplier;
	multiplier->updateMultiplier(new_multiplier);
}


void UserHUD::draw(CDC *memDC) {
	if ( shieldbar ) {
		shieldbar->draw(memDC);
	}
	healthbar->draw(memDC);
	score->draw(memDC);
	multiplier->draw(memDC);
	for ( int i = 0 ; i < MAX_BOMBS ; i++ ) {
		bombs[i]->draw(memDC);
	}
}

void UserHUD::updateHealthBar( int health ) {
	healthbar->updateValue(health*100/Ship::INIT_HEALTH);
}

void UserHUD::dropBomb() {
	bombs[--num_bombs]->emptySlot();
}

void UserHUD::storeBomb() {
	if ( MAX_BOMBS > num_bombs ) {
		bombs[num_bombs++]->fillSlot();
	}
}


void UserHUD::showShieldBar( int duration )  {
	if ( shieldbar ) {
		hideShieldBar();
	}
	shieldbar = new ShieldBar(duration);
}

void UserHUD::hideShieldBar()  {
	shieldbar->~ShieldBar();
	delete shieldbar;
}
