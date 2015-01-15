#pragma once
#include "entity.h"

class Background :	public Entity {
public:
	Background(void);
	~Background(void);

	int x1;
	int velocity_mutiplier;

	void draw(CDC *memDC);
	void update();
};
