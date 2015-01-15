#pragma once
#include "entity.h"

class HealthBar : 	public Entity {
public:
	const static int MAX_VALUE = 100;

	int value;

	HealthBar(void);
	~HealthBar(void);

	void draw(CDC *memDC);
	
	void updateValue( int new_value );
	
};
