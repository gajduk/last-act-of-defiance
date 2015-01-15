#pragma once
class Entity {
public:
	int x;
	int y;
	int xvelocity;
	int yvelocity;
	bool destroy;

	Entity(void);
	~Entity(void);

	virtual void draw(CDC *memDC);	
	virtual void update();
	virtual bool checkBounds();
};
