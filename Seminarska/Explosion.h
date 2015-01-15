#pragma once
#include "entity.h"

class Explosion : public Entity {
private:
	int current_frame;
public:
	static const int total_frames = 12;

	Explosion(void);
	Explosion( int xpos , int ypos );
	~Explosion(void);

	void update();
	bool checkBounds();
	void draw(CDC *memDC);
	
};
