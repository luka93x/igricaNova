#pragma once
#include "Displayble.h"
class Gold :public Displayble
{
public:
	Gold(int x);
	~Gold();
	int getAmmount();
private:
	int ammount;
};

