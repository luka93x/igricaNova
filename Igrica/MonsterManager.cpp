#include "MonsterManager.h"
#include "AttackManager.h"
#include "Stats.h"
#include "Npc.h"
#include "MovmentManager.h"
MonsterManager* MonsterManager::instance = nullptr;

MonsterManager * MonsterManager::getInstance()
{
	if (!instance) {
		instance = new MonsterManager();
	}
	return instance;
}

void MonsterManager::resolveAllMonsters(vector<Path*> filledSpots)
{
	for (int x = 0; x < filledSpots.size(); x++) {
		Path* monster = filledSpots[x];
		attackOrMove(monster);
	}
}

MonsterManager::MonsterManager()
{
}


MonsterManager::~MonsterManager()
{
}

void MonsterManager::attackOrMove(Path* monster)
{
	Cordinate cor = Mapa::getInstance()->getCordinateOfPath(monster);
	vector<Path*>surroundingPaths = pathsAroundMonster(cor);
	auto karakterSlot = isKarakterNext(surroundingPaths);
	if (karakterSlot)
	{
		Npc* npc = monster->getObjetOnPath()->toNpc();
		if (npc->getRace() == MERCHANT) {
			if (MovmentManager::getInstace()->getplayer()->getAttackedMerchant()) {
				Stats* karakter = karakterSlot->getObjetOnPath()->toStats();
				Stats* attacker = monster->getObjetOnPath()->toStats();
				AttackManager::getInstance()->attack(attacker, karakter);
			}
		}
		else {
			Stats* karakter = karakterSlot->getObjetOnPath()->toStats();
			Stats* attacker = monster->getObjetOnPath()->toStats();
			AttackManager::getInstance()->attack(attacker, karakter);
		}
	}
	else {
		int randomIndex = rand() % surroundingPaths.size();
		Path* toMove = surroundingPaths[randomIndex];
		Npc* n = monster->getObjetOnPath()->toNpc();
		toMove->setObjectOnPath(n);
		monster->setObjectOnPath(nullptr);
	}
}

vector<Path*> MonsterManager::pathsAroundMonster(Cordinate cor)
{
	vector<Path*> surroundingPaths;
	vector <Path*> pathsAroud = Mapa::getInstance()->getPathsAroundByCord(cor);
	for (int i = 0; i < pathsAroud.size(); i++) {
		Path* p = pathsAroud[i];
		if (p->isOccupied()) {
			if (p->getObjetOnPath()->isKarakter()) {
				surroundingPaths.push_back(p);
			}
		}
		else if (!p->isOccupied())
		{
			if (p->displayChar() == '.') {
				surroundingPaths.push_back(p);
			}

		}
	}
	return surroundingPaths;
}

Path* MonsterManager::isKarakterNext(vector<Path*> paths)
{

	for (int x = 0; x < paths.size(); x++) {
		Path* p = paths[x];
		if (p->getObjetOnPath()->isKarakter()) {
			return p;
		}
	}
	return nullptr;
}

