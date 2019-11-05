#pragma once
#include<string>
#include "Karakter.h"
#include "PotionType.h"
using namespace std;

class Potion : public Displayble
{
public:
	Potion();
	Potion(string);
	void setPotionType(string);
	void usePotion(Karakter*);
	PotionType getPotionType();
	string getPotionTypeByString();
private:
	 PotionType type;
};
