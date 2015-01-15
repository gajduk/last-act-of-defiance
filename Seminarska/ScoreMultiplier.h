#pragma once
#include "entity.h"

class ScoreMultiplier : public Entity {
public:
	int multiplier;

	ScoreMultiplier(void);
	~ScoreMultiplier(void);

	void draw(CDC *memDC);
	void updateMultiplier(int number);
};
