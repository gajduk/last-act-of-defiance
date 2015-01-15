#pragma once
#include "entity.h"

class GameOver : public Entity {	
public:
	int total_score;

	GameOver(void);
	~GameOver(void);

	void draw(CDC *memDC);
};
