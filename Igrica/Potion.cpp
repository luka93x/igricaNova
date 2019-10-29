#include "Potion.h"
#include"Displayble.h"



Potion::Potion() :Displayble('p')
{

}

Potion::Potion(string s) : Displayble('p')
{
	if (s == "RH") {
		type = PotionType::RH;
	}
	else if (s == "BA") {
		type = PotionType::BA;
	}
	else if (s == "BD") {
		type = PotionType::BD;
	}
	else if (s == "PH") {
		type = PotionType::PH;
	}
	else if (s == "WA") {
		type = PotionType::WA;
	}
	else if (s == "WD") {
		type = PotionType::WD;
	}
	else
		type = PotionType::NF;

}

void Potion::setPotionType(string s)
{
	if (s == "rh") {
		type = PotionType::RH;
	}
	else if (s == "BA") {
		type = PotionType::BA;
	}
	else if (s == "BD") {
		type = PotionType::BD;
	}
	else if (s == "PH") {
		type = PotionType::PH;
	}
	else if (s == "WA") {
		type = PotionType::WA;
	}
	else if (s == "WD") {
		type = PotionType::WD;
	}
	else
		type = PotionType::NF;

}

void Potion::usePotion(Karakter* player)
{
	int x = 5;
	int y = -5;
	if (player->getRace() == Race::ELF) {
		y = x;
	}
		if (type == PotionType::RH) {
			player->addHP(2 * x);
		}
		else if (type == PotionType::PH) {
			player->addHP(2 * y);
		}
		else if (type == PotionType::BA) {
			player->addAtk(x);
			player->addTypeofUsedPotion(RH);
		}
		else if (type == PotionType::BD) {
			player->addDef(x);
		}
		else if (type == PotionType::WA) {
			player->addAtk(y);
		}
		else if (type == PotionType::WD) {
			player->addDef(y);
		}

		player->addTypeofUsedPotion(type);
}

PotionType Potion::getPotionType()
{
	return type;
}

string Potion::getPotionTypeByString()
{
	switch (type)
	{
	case RH:
		return "RH";
		break;
	case BA:
		return "BA";
		break;
	case BD:
		return "BD";
		break;
	case PH:
		return "PH";
		break;
	case WA:
		return "WA";
		break;
	case WD:
		return "WD";
		break;
	case NF:
		return "No effect";
		break;
	default:
		break;
	}
}






