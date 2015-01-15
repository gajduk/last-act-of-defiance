#include "StdAfx.h"
#include "GameMenu.h"

GameMenu::GameMenu(void)
{
	visible = false;
	x = 100;
	y = 100;
}

void GameMenu::draw(CDC *memDC) {
	if ( visible ) {
		memDC->TextOutW(x,y,_T("press p to resume the game"),26);
		memDC->TextOutW(x,y+20,_T("press q to quit to main menu"),29);
		memDC->TextOutW(x,y+40,_T("press x to exit the game"),28);
	}
}

GameMenu::~GameMenu(void)
{
}

void GameMenu::show() {
	visible = true;
}

void GameMenu::hide() {
	visible = false;
}
