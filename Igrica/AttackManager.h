#pragma once
#include "Stats.h"
class AttackManager
{
public:
	static AttackManager* getInstance();
	int attack(Stats* attacker, Stats* defender);
private:
	static AttackManager* instace;
	AttackManager();
	~AttackManager();
};

