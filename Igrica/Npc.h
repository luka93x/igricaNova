#pragma once
#include "Stats.h"
#include "Displayble.h"
enum Monster { TROLL, GOBILN, WAREWOLF, VAMPIRE, MERCHANT, PHONIX, DRAGON };
class Npc : public Displayble , public Stats
{
	
public:
	Npc(Monster race);
	~Npc();
	static char getMonsterChar(Monster race);
	bool checkIfMonster();
	Monster getRace();
private:
	Monster race;
	bool isMonster = true;
	
};

