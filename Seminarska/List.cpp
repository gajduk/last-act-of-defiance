#include "StdAfx.h"
#include "List.h"
#include "Entry.h"
#include "Entity.h"

List::List(void)
{
	start = NULL;
}

List::~List(void)
{
	int debug = 5;
	if ( start == NULL ) return;
	Entry* walker = start;
	while ( walker ) {
		Entry* temp = walker;
		walker = walker->rlink;
		deleteEntry(temp);
	}
}

void List::addEntry( Entity *to_add ) {
	Entry* new_entry;
	new_entry = new Entry(to_add,NULL,start);
	if ( start ) 
		start->llink = new_entry;
	start = new_entry;
	int debug = 5;
}
void List::deleteEntry( Entry *to_delete) {
	if ( to_delete ) {
		if ( to_delete == start ) {
			if ( to_delete->llink ) {
				start = to_delete->llink;
			}
			else {
				if ( to_delete->rlink ) {
					start = to_delete->rlink;
				}
				else {
					start = NULL;
				}
			}
		}
		if ( to_delete->llink )	to_delete->llink->rlink = to_delete->rlink;
		if ( to_delete->rlink )  to_delete->rlink->llink = to_delete->llink;
		delete to_delete;
	}
}

void List::check() {
	Entry* walker = start;
	while ( walker ) {
		Entry* temp = walker;
		walker = walker->rlink;
		if ( temp->data->checkBounds() ) deleteEntry(temp);
	}
}
void List::update() {
	Entry* walker = start;
	while ( walker ) {
		walker->data->update();
		walker = walker->rlink;
	}
}

void List::draw(CDC *memDC) {
	Entry* walker = start;
	while ( walker ) {
		walker->data->draw(memDC);
		walker = walker->rlink;
	}
}
