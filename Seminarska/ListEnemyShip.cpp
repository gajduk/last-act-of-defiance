#include "StdAfx.h"
#include "ListEnemyShip.h"
#include "EnemyShip.h"
#include "Missile.h"
#include "Entity.h"
#include "Entry.h"

ListEnemyShip::ListEnemyShip()
{
	count_enemy = 0;
}

ListEnemyShip::~ListEnemyShip(void)
{
}

void ListEnemyShip::addEntry( Entity *to_add) {
	List::addEntry(to_add);
	count_enemy++;
}

void ListEnemyShip::deleteEntry( Entry *to_delete) {
	List::deleteEntry(to_delete);
	count_enemy--;
}


Entry* ListEnemyShip::checkMissile( Missile &m ) {
	Entry* walker;
	walker = start;
	while ( walker ) {
		EnemyShip* temp = dynamic_cast<EnemyShip*> (walker->data);
		if ( temp->checkMissile(m) ) return walker;
		walker = walker->rlink;
	}
	return NULL;
}	

EnemyShip* ListEnemyShip::fireMissile( int index ) {
	Entry* walker;
	walker = start;
	int counter = 0;
	while ( walker ) {
		EnemyShip* temp = dynamic_cast<EnemyShip*> (walker->data);
		if ( counter == index ) return temp;
		walker = walker->rlink;
		counter++;
	}

		
}

bool ListEnemyShip::isEmpty() {
	return !start;

}