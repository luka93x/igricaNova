#include "Spawner.h"
#include<time.h>
#include "MovmentManager.h"
#include<iostream>
#include "Stairs.h"

using namespace std;


Spawner::Spawner()
{
}
Spawner* Spawner::instance = nullptr;
int Spawner::radnomGeneretor(int number)
{
	int randomIndex = rand() % number;
	return randomIndex;

}
void Spawner::spawnPotion() {
	{

		vector<Path*> slots;
		string s;
		for (int x = 0; x < 10; x++) {
			slots = Mapa::getInstance()->getEmptySlots();
			int randomIndex = radnomGeneretor(slots.size());
			int whichToSpawn = radnomGeneretor(6);
			if (whichToSpawn == 0) {
				s = "RH";
			}
			else if (whichToSpawn == 1) {
				s = "PH";
			}
			else if (whichToSpawn == 2) {
				s = "BA";
			}
			else if (whichToSpawn == 3) {
				s = "BD";
			}
			else if (whichToSpawn == 4) {
				s = "WA";
			}
			else if (whichToSpawn == 5) {
				s = "WD";
			}
			slots[randomIndex]->setObjectOnPath(new Potion(s));
		}
	}

}

void Spawner::spawnNpc()
{
	Npc* npc;
	auto map = Mapa::getInstance();
	for (int x = 0; x < 10; x++) {
		auto slot = map->getEmptySlots();
		int randomPath = radnomGeneretor(slot.size());
		int randomNpc = radnomGeneretor(100);
		npc = choseWhichNpc(randomNpc);
	 	slot[randomPath]->setObjectOnPath(npc);
	}
}

Npc * Spawner::choseWhichNpc(int x)
{
	Npc* n;
	if (x < 11) {
		n = new Npc(Monster::TROLL);
	}
	else if (x < 33) {
		n = new Npc(Monster::WAREWOLF);
	}
	else if (x < 44) {
		n = new Npc(Monster::PHONIX);
	}
	else if (x < 55) {
		n = new Npc(Monster::MERCHANT);
	}
	else if (x < 72) {
		n = new Npc(Monster::VAMPIRE);
	}
	else n = new Npc(Monster::GOBILN);

	return n;
}

void Spawner::spawnStairs()
{
	bool sameFloor= true;
	vector<Path*>emptySlot = Mapa::getInstance()->getEmptySlots();
	int randomPath=0;
	while (sameFloor) {
	 randomPath = radnomGeneretor(emptySlot.size());
	sameFloor = isStairsInSameRoom(emptySlot[randomPath]);
	
	
	}
	emptySlot[randomPath]->setObjectOnPath(new Stairs());
}

bool Spawner::isStairsInSameRoom(Path* stairs)
{
	for(set<Path*>::iterator it = floor.begin();it !=floor.end();it++){
	
		if (stairs == *it) {
			return true;
		}
	}
	return false;
}

Spawner * Spawner::getinstance()
{

	if (!instance) {
		instance = new Spawner();
	}
	return instance;
}

void Spawner::spawnAll()
{
	auto moveMan = MovmentManager::getInstace();
	cout << "Izaberite rasu otkucajuci njeno prvo slovo : Orc(o),Dwarf(d),Elf(e) ili Human(h)" << endl;
	Cordinate cor = spawnKarakter(moveMan->getplayer());
	moveMan->setPlayerCord(cor);
	spawnPotion();
	spawnNpc();
	spawnStairs();
}

void Spawner::spawnFloor()
{
	auto map = Mapa::getInstance();
	auto player = MovmentManager::getInstace()->getplayer();

	auto slot = map->getEmptySlots();
	int randomindex = radnomGeneretor(slot.size());
	slot[randomindex]->setObjectOnPath(player);
	spawnPotion();
	spawnNpc();
	spawnStairs();
}

Cordinate Spawner::spawnKarakter(Karakter* player)
{
	srand(time(0));
	auto inputMenager = InputManager::getInstance();
	auto map = Mapa::getInstance();
	auto slot = map->getEmptySlots();
	int randomindex = radnomGeneretor(slot.size());
	slot[randomindex]->setObjectOnPath(player);
	player->setRace(inputMenager->getRacefromChar(inputMenager->charForRace()));
	 Cordinate cor =	map->getCordinateOfPath(slot[randomindex]);
	 map->getInstance()->getFloor(slot[randomindex], floor);
	 return cor;
	
}
