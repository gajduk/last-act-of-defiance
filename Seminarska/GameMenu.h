#pragma once
#include "entity.h"

class GameMenu : public Entity {
private:
	bool visible;

public:
	GameMenu(void);
	~GameMenu(void);
	
	void show();
	void hide();

	void draw(CDC *memDC);
	
};
