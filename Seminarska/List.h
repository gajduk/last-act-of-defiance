#pragma once
#include "Entry.h"
#include "Entity.h"

class List {
public:
	Entry* start;

	List(void);
	~List(void);

	void addEntry( Entity *to_add);
	void deleteEntry( Entry *to_delete);
	void check();
	void update();
	void draw(CDC *memDC);
	
};
