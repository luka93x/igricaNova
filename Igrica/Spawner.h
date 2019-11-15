#pragma once
#include"Displayble.h"
#include"Potion.h"
#include"Mapa.h"
#include"Path.h"
#include "Npc.h"
class Spawner
{
public:
	static int radnomGeneretor(int number);
	static Spawner* getinstance();
	void spawnAll();
	set<Path*>floor;
	void spawnFloor();
private:
	static 	Spawner* instance;
	Spawner();
	Cordinate spawnKarakter(Karakter* player);
	void spawnPotion();
	void spawnNpc();
	Npc* choseWhichNpc(int x);
	void spawnStairs();
	bool isStairsInSameRoom(Path* stairs);
	
};

