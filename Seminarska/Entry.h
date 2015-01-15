#pragma once
#include "Entity.h"

class Entry {
public:
	Entity *data;
	Entry *llink,*rlink;

	Entry(void);
	Entry( Entity *data1  , Entry *llink1 , Entry *rlink1 );
	~Entry(void);
};
