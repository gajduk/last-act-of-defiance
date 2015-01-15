#include "StdAfx.h"
#include "Score.h"
#include "UserHUD.h"

Score::Score(void)
{
	x = UserHUD::SCORE_X;
	y = UserHUD::SCORE_Y;
	score = 0;
}
int countDigits ( int number ) {
	int num_digits = 0;
	while ( number > 0 ) {
		number /= 10;
		num_digits++;
	}
	return num_digits;
}

void Score::draw(CDC *memDC) {
	CString score_print;
	score_print.Format(_T("Score: %d"),score);
	memDC->SetBkColor(RGB(220,220,255));
	memDC->TextOutW(x,y,score_print,8+countDigits(score));

}


Score::~Score(void)
{
}

void Score::addScore( int number )  {
	score += number;
}

