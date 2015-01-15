#include "StdAfx.h"
#include "Entry.h"
#include "Entity.h"

Entry::Entry(void)
{
}

Entry::~Entry(void)
{
}

Entry::Entry( Entity *data1  , Entry *llink1 , Entry *rlink1 ) {
	data = data1;
	llink = llink1;
	rlink = rlink1;
}
