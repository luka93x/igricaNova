#include "Game.h"
#include <iostream>
#include "MonsterManager.h"
#include "OutputManager.h"

static void update() {
	auto mapa = Mapa::getInstance();
	auto inputManager = InputManager::getInstance();
	auto movmentManager = MovmentManager::getInstace();
	mapa->printMap();
	OutputManager::getInstance()->outInfo();
	movmentManager->resolveAction(inputManager->returnAction(inputManager->input()));
	MonsterManager::getInstance()->resolveAllMonsters(mapa->getMonsterSlots());
	
};
Game::Game()
{

}

Game* Game::instance = nullptr;

Game* Game::getInstance() {
	if (!instance) {
		instance = new Game();
	}
	return instance;
}

void Game::startGame() {
	Spawner::getinstance()->spawnAll();
	while (true)
	{

		update();
	}

}

