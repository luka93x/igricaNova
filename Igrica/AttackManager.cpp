#include "AttackManager.h"
#include <stdlib.h>
using namespace std;
AttackManager* AttackManager::instace = nullptr;

AttackManager * AttackManager::getInstance()
{
	if (!instace) {
		instace = new AttackManager();
	}

	return instace;
}

int AttackManager::attack(Stats * attacker, Stats * defender)
{
	int dmg = 0;
	if (attacker->checkIfMonster()) {
		int x = rand() % 2;
		if (x == 0) {
			dmg = 0;
		}
		else dmg = (100.0 / (100.0 + defender->getDef()))* attacker->getAtk();
	}
	else	dmg = (100.0 / (100.0 + defender->getDef()))* attacker->getAtk();
	defender->demage(dmg);
	return dmg;
}

AttackManager::AttackManager()
{
}


AttackManager::~AttackManager()
{
}
