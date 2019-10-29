#include "MovmentManager.h"
#include "Displayble.h"
#include "Path.h"
#include<iostream>
#include<time.h>
#include "AttackManager.h"
#include "Gold.h"
#include "OutputManager.h"
using namespace std;
MovmentManager::MovmentManager() {
}
MovmentManager* MovmentManager::instace = nullptr;

MovmentManager::~MovmentManager()
{
}

Karakter * MovmentManager::getplayer()
{
	return &player;
}

Path* MovmentManager::returnSlot(Cordinate cor)
{

	Displayble* moveToDisplayable = Mapa::getInstance()->getDisplayable(playerCordinate + cor);

	if (moveToDisplayable->isPath()) {
		Path* moveToPath = moveToDisplayable->toPath();
		return moveToPath;
	}
}

bool MovmentManager::swap2Slots(Path* dis)
{
	Path* currentPos = Mapa::getInstance()->getDisplayable(playerCordinate)->toPath();
	if (!dis->isPath()) {
		return false;
	}
	Path* moveToPath = dis->toPath();
	if (moveToPath->isOccupied()) {

		if (moveToPath->getObjetOnPath()->isGold()) {
			Gold* gold = moveToPath->getObjetOnPath()->toGold();
			player.addGold(gold->getAmmount());
			moveToPath->setObjectOnPath(&player);
			currentPos->setObjectOnPath(nullptr);
			return true;
		}

		return false;
	}
	moveToPath->setObjectOnPath(&player);
	currentPos->setObjectOnPath(nullptr);

	return true;
}

bool MovmentManager::usePotion(Path * p)
{
	if (p->getObjetOnPath()->isPotion()) {
		Potion* potion = p->getObjetOnPath()->toPotion();
		potion->usePotion(&player);
		p->setObjectOnPath(nullptr);;
	}

	return true;
}

bool MovmentManager::useAtk(Path * p)
{
	if (p->getObjetOnPath()->isNpc()) {
		Stats* def = p->getObjetOnPath()->toStats();
		AttackManager::getInstance()->attack(player.toStats(), def);
		OutputManager::getInstance()->outputDmg(p);
		if (def->isDead()) {
			p->setObjectOnPath(new Gold(1));
		}
		return true;
	}
	return false;
}



bool MovmentManager::resolveAction(pair<Action, Cordinate>* pair1)
{
	Path* toMove = returnSlot(pair1->second);
	auto outputManager = OutputManager::getInstance();
	if (pair1->first == Action::MOVE) {

		if (swap2Slots(toMove)) {
			playerCordinate += pair1->second;
			outputManager->outputMovment(pair1->second);
		}

	}
	else if (pair1->first == Action::USE) {
		return usePotion(returnSlot(pair1->second));
	}
	else if (pair1->first == Action::ATTACK) {
		

			return useAtk(toMove);
	}
		return false;


	}


	MovmentManager * MovmentManager::getInstace()
	{
		if (!instace) {
			instace = new MovmentManager();
		}
		return instace;
	}

	void MovmentManager::setPlayerCord(Cordinate cor)
	{
		playerCordinate = cor;
	}

	Cordinate MovmentManager::getPlayerCord()
	{
		return playerCordinate;
	}

