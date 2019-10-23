#include "Gold.h"



Gold::Gold(int x) : Displayble('g')
{
	if (x < 0) {
		x = 0;
	}
	else if (x > 3) {
		x = 3;
	}

	ammount = x;
}


Gold::~Gold()
{
}

int Gold::getAmmount()
{
	return ammount;
}
