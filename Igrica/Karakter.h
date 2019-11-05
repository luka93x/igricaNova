#pragma once
#include "Displayble.h"
#include <vector>
#include <string>
#include "Stats.h"
#include "PotionType.h"

using namespace std;
enum Race {ELF , ORC, DWARF ,HUMAN };
class Karakter : public Displayble , public Stats
{
public:
	Karakter();
	void setRace(Race _race);
	void addAtk(int x);
	void addDef(int x);
	Race getRace();
	float getGold();
	void addGold(int x);
	string getRacebyString();
	bool checkIfMonster();
	void addTypeofUsedPotion(PotionType ptype);
	bool isPotionTypedUsed(PotionType ptype);
	void setAttackedMerchant(bool seter);
	bool getAttackedMerchant();
private:
	vector<PotionType> usedPotions;
	Race race;
	float	gold=0.0;
	bool isMonster;
	bool attackedMerchant = false;

};

