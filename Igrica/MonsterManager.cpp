#include "MonsterManager.h"
#include "AttackManager.h"
#include "Stats.h"
#include "Npc.h"
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
	Path* monster;
	for (int x = 0; x < filledSpots.size(); x++) {
		monster = filledSpots[x];
		attackOrMove(monster);
	}
}

MonsterManager::MonsterManager()
{
}


MonsterManager::~MonsterManager()
{
}

void MonsterManager::attackOrMove(Path * monster)
{	
	Cordinate cor = Mapa::getInstance()->getCordinateOfPath(monster);
	vector<Path*>surroundingPaths = pathsAroundMonster(cor);
	if (isKarakterNext(surroundingPaths))
	{
		Stats* karakter = isKarakterNext(surroundingPaths)->getObjetOnPath()->toStats();
		Stats* attacker = monster->getObjetOnPath()->toStats();
		AttackManager::getInstance()->attack(attacker, karakter);
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
	Cordinate addCord;
	vector<Path*>surroundingPaths;
	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			if (x == 0 && y == 0) {

			}
			else {
				addCord = { x,y };
				Displayble* dis = Mapa::getInstance()->getDisplayable(cor + addCord);
				if (dis->isPath())
				{
					Path* p = dis->toPath();
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

