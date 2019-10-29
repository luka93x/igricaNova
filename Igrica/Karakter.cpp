#include "Karakter.h"


Karakter::Karakter():Displayble('@')
{
	

}

void Karakter::setRace(Race _race)
{
	
	switch (_race)
	{
	case ELF:
		setMaxHp(140);
		setHP(140);
		setAtk(30);
		setDef(10);
		race = ELF;
		isMonster = false;
		break;
	case ORC:
		setMaxHp(180);
		setHP(180);
		setAtk(30);
		setDef(25);
		race = ORC;
		isMonster = false;
		break;
	case DWARF:
		setMaxHp(100);
		setHP(100);
		setAtk(20);
		setDef(30);
		race = DWARF;
		isMonster = false;
		break;
	default:
		setMaxHp(140);
		setHP(140);
		setAtk(20);
		setDef(20);
		race = HUMAN;
		isMonster = false;
		break;
	}
}



void Karakter::addAtk(int x)
{
	atk += x;
	if (atk < 0) {
		atk = 0;
	}
}

void Karakter::addDef(int x)
{
	def += x;
	if (def < 0) {
		def = 0;
	}
}

Race Karakter::getRace()
{
	return race;
}

float Karakter::getGold()
{
	return gold;
}

void Karakter::addGold(int x)
{
	switch (race)
	{
	case ORC:
		gold += (x / 2);
		break;
	case DWARF:
		gold += (x * 2);
		break;
	default:
		gold += x;
		break;
	}
}

string Karakter::getRacebyString()
{
	string s;
	switch (race)
	{
	case ELF:
		s = "Elf";
		break;
	case ORC:
		s = "Orc";
		break;
	case DWARF:
		s = "Dwarf";
		break;
	default:
		s = "Human";
		break;
	}
	return s;
}

bool Karakter::checkIfMonster()
{
	return isMonster;
}

void Karakter::addTypeofUsedPotion(PotionType ptype)
{
	usedPotions.push_back(ptype);
}

bool Karakter::isPotionTypedUsed(PotionType ptype)
{
	for (int i = 0; i < usedPotions.size(); i++) {
		if (usedPotions[i] == ptype) {
			return true;
		}
	}
	return false;
}





