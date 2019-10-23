#include "Npc.h"



Npc::Npc(Monster monster) : Displayble(getMonsterChar(monster))
{
	switch (monster)
	{
	case TROLL:
		setMaxHp(120);
		setHP(120);
		setAtk(25);
		setDef(15);
		race = TROLL;
		break;
	case GOBILN:
		setMaxHp(70);
		setHP(70);
		setAtk(5);
		setDef(10);
		race = GOBILN;
		break;
	case WAREWOLF:
		setMaxHp(120);
		setHP(120);
		setAtk(30);
		setDef(5);
		race = WAREWOLF;
		break;
	case VAMPIRE:
		setMaxHp(50);
		setHP(50);
		setAtk(25);
		setDef(25);
		race = VAMPIRE;
		break;
	case MERCHANT:
		setMaxHp(30);
		setHP(30);
		setAtk(70);
		setDef(5);
		race = MERCHANT;
		break;
	case PHONIX:
		setMaxHp(50);
		setHP(50);
		setAtk(35);
		setDef(20);
		race = PHONIX;
		break;
	case DRAGON:
		setMaxHp(150);
		setHP(150);
		setAtk(20);
		setDef(20);
		race = DRAGON;
		break;
	default:
		break;
	}
}


Npc::~Npc()
{
}

char Npc::getMonsterChar(Monster race)
{

	switch (race)
	{
	case Monster::TROLL:
		return 'T';
		break;
	case Monster::GOBILN:
		return 'G';
		break;
	case Monster::WAREWOLF:
		return 'W';
		break;
	case Monster::VAMPIRE:
		return 'V';
		break;
	case Monster::MERCHANT:
		return 'M';
		break;
	case Monster::PHONIX:
		return 'X';
		break;
	case Monster::DRAGON:
		return 'D';
		break;
	default:
		break;
	}
}

bool Npc::checkIfMonster()
{
	return isMonster;
}
