#include "StdAfx.h"
#include "ScoreMultiplier.h"
#include "UserHUD.h"

ScoreMultiplier::ScoreMultiplier(void)
{
	x = UserHUD::MULTIPLIER_X;
	y = UserHUD::MULTIPLIER_Y;
	multiplier = 1;
}

ScoreMultiplier::~ScoreMultiplier(void)
{
}
int countDigits3 ( int number ) {
	int num_digits = 0;
	while ( number > 0 ) {
		number /= 10;
		num_digits++;
	}
	return num_digits;
}

void ScoreMultiplier::draw(CDC *memDC) {
	CString multiplier_print;
	multiplier_print.Format(_T("x%d"),multiplier);
	memDC->SetBkColor(RGB(220,220,255));
	memDC->TextOutW(x,y,multiplier_print,2+countDigits3(multiplier));
}



void ScoreMultiplier::updateMultiplier(int number) {
	multiplier = number;
}
