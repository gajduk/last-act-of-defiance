#pragma once
#include "list.h"
#include "EnemyShip.h"
#include "Missile.h"

class ListEnemyShip : public List {
public:
	int count_enemy;

	ListEnemyShip(void);
	~ListEnemyShip(void);

	void addEntry( Entity *to_add);
	void deleteEntry( Entry *to_delete);
	bool isEmpty();
	Entry* checkMissile(Missile &m);
	EnemyShip* fireMissile( int index );
	
};
