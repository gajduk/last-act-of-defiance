#pragma once
#include "entity.h"

class FloatingScore : public Entity {
private:
	int value;
	int fading_counter;

public:
	static const int FADING_TIME = 40;

	FloatingScore(void);
	FloatingScore( int xpos , int ypos , int value );
	~FloatingScore(void);

	void draw(CDC *memDC);
	void update();
	bool checkBounds();
};
