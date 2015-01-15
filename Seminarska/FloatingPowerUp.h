#pragma once
#include "entity.h"

class FloatingPowerUp : public Entity {
private:
	CString text;
	int fading_counter;

public:
	static const int FADING_TIME = 40;
	
	FloatingPowerUp(void);
	FloatingPowerUp( int xpos , int ypos , CString power_up );
	~FloatingPowerUp(void);
	
	void draw(CDC *memDC);
	void update();
	bool checkBounds();
	
};
