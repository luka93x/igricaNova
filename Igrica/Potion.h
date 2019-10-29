#pragma once
#include"Displayble.h"
#include<string>
#include "Karakter.h"
using namespace std;
enum PotionType {
	RH, BA, BD, PH, WA, WD ,NF
};
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
