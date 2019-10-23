#pragma once
#include "Path.h"
#include "Mapa.h"
#include"Potion.h"
#include"InputManager.h"


class MovmentManager
{
private:
	Karakter  player;
	Cordinate playerCordinate;
	static MovmentManager* instace;
	MovmentManager();
	~MovmentManager();
	Path* returnSlot(Cordinate cor);
	bool swap2Slots(Path* dis);
	bool usePotion(Path* p);
	bool useAtk(Path* p);

public:
	Karakter* getplayer();
	bool resolveAction(pair< Action,Cordinate>*);
	static MovmentManager* getInstace();
	void setPlayerCord(Cordinate cor);
	Cordinate getPlayerCord();
};

