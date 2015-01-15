#include "StdAfx.h"
#include "GameOver.h"
#include "entity.h"

GameOver::GameOver(void)
{
	total_score = 0;
}

GameOver::~GameOver(void)
{
}

int countDigits7( int number ) {
	int num_digits = 0;
	while ( number > 0 ) {
		number /= 10;
		num_digits++;
	}
	return num_digits;
}

void GameOver::draw(CDC *memDC) { 
	memDC->TextOutW(500,200,_T("GAME OVER"),10);
	CString temp;
	temp.Format(_T("Total Score: %d"),total_score);
	memDC->TextOutW(500,250,temp,14+countDigits7(total_score));
}
