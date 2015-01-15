#pragma once
#include "entity.h"
//#include "UserHUD.h"

#ifndef __Score_H_INCLUDE
#define __Score_H_INCLUDE
#ifndef __Score_H_DEFINED
#define __Score_H_DEFINED
class Score;
#include "UserHUD.h"
#endif

class Score : public Entity {
public:
	int score;

	Score(void);
	~Score(void);

	void addScore(int number);

	void draw(CDC *memDC);
	
};
#endif