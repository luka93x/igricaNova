#pragma once

#include "Mapa.h"
#include "MovmentManager.h"
#include "Spawner.h"
#include<string>
#include"InputManager.h"
#pragma once
using namespace std;
class Game
{
public:
	static Game* getInstance();
	void startGame();


private:
	Game();
	static Game* instance;
	
};

