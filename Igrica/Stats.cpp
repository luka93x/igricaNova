#include "Stats.h"

Stats::Stats()
{
}
void Stats::addHP(int num)
{
	hp +=num;
	if (hp > maxhp) {
		hp = maxhp;
	}
	else  if (hp < 0) {
		hp = 0;
	}

}

void Stats::demage(int dmg)
{
	
	hp -= dmg;
	if (hp > maxhp) {
		hp = maxhp;
	}
	else  if (hp < 0) {
		hp = 0;
	}
}

Stats::~Stats()
{
}

void Stats::setHP(int _hp)
{
	if (_hp < 0) {
		hp = 0;
	}
	else if (_hp > maxhp) {
		hp = maxhp;
	}
	else hp = _hp;
}

int Stats::getHP()
{
	return hp;
}

void Stats::setMaxHp(int _maxhp)
{
	maxhp = _maxhp;
}

void Stats::setAtk(int _atk)
{
	atk = _atk;
}

int Stats::getAtk()
{
	return atk;
}

void Stats::setDef(int _def)
{
	def = _def;
}

int Stats::getDef()
{
	return def;
}

bool Stats::isDead()
{
	return this->getHP() <= 0;
}
