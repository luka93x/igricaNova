#pragma once
#include "Displayble.h"
#include"Potion.h"
#include <vector>
#include <string>
#include "Stats.h"
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
private:
	Race race;
	float	gold=0.0;
	bool isMonster;
};
