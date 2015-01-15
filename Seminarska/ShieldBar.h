#pragma once
#include "entity.h"
#ifndef __BAR_H_INCLUDE
	#define __BAR_H_INCLUDE
	#ifndef __BAR_H_DEFINED
		#define __BAR_H_DEFINED
		class ShieldBar;
		#include "UserHUD.h"
	#endif
class ShieldBar : 	public Entity {
public:
	static const int BLINK_TIME = 100;
d
	int shield_strength;
	bool blink_on;
	int blink_counter;
	int shield_duration;

	ShieldBar(int duration);
	~ShieldBar(void);

	void update( int new_value);

	void draw(CDC *memDC);
	void update();
	
	
	
};
#endif
