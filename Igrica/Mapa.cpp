#include "Mapa.h"
#include <iostream>
#include "Path.h"
#include"Karakter.h"
#include"Npc.h"
using namespace std;

Mapa::Mapa()
{
	fillMap();
}

static Displayble* getDisplaybleByChar(char c) {
	Displayble* objekat = nullptr;
	if (c == '.' || c == '#' || c == '+') {
		objekat = new Path(c);
	}
	else if (c == '|') {
		objekat = new Wall();
	}
	else if (c == '-') {
		objekat = new Ceiling();
	}
	else {
		objekat = new EmptySpace();
	}
	return objekat;
}
Mapa* Mapa::instance = nullptr;
void Mapa::fillMap() {
	static char matrix[25][80] = {
	"|-----------------------------------------------------------------------------|",
	"|                                                                             |",
	"| |--------------------------|        |-----------------------|               |",
	"| |..........................|        |.......................|               |",
	"| |..........................+########+.......................|-------|       |",
	"| |..........................|   #    |...............................|--|    |",
	"| |..........................|   #    |..................................|--| |",
	"| |----------+---------------|   #    |----+----------------|...............| |",
	"|            #                 #############                |...............| |",
	"|            #                 #     |-----+------|         |...............| |",
	"|            #                 #     |............|         |...............| |",
	"|            ###################     |............|   ######+...............| |",
	"|            #                 #     |............|   #     |...............| |",
	"|            #                 #     |-----+------|   #     |--------+------| |",
	"| |----------+----------|      #           #          #              #        |",
	"| |.....................|      #           #          #         |----+------| |",
	"| |.....................|      ########################         |...........| |",
	"| |.....................|      #           #                    |...........| |",
	"| |.....................|      #    |------+--------------------|...........| |",
	"| |.....................|      #    |.......................................| |",
	"| |.....................+###########+.......................................| |",
	"| |.....................|           |.......................................| |",
	"| |---------------------|           |---------------------------------------| |",
	"|                                                                             |",
	"|-----------------------------------------------------------------------------|"
	};
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			mapa[i][j] = getDisplaybleByChar(matrix[i][j]);
		}
	}
}

Mapa * Mapa::getInstance()
{
	if (!instance) {
		instance = new Mapa();
	}
	return instance;
}

void Mapa::printMap() {
	for (size_t i = 0; i < 100; i++)
	{
		cout << endl;
	}
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {

			cout << mapa[i][j]->displayChar();

		}
		cout << endl;
	}
}

Displayble* Mapa::getDisplayable(Cordinate cord) {
	return mapa[cord.x][cord.y];
}

vector<Path*> Mapa::getEmptySlots()
{
	vector<Path*>emptySlots;
	Path *p;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			Displayble * dis = mapa[i][j];
			if (dis->isPath()) {
				p = dis->toPath();
				if (p->displayChar() == '.')
					if (!p->isOccupied()) {
						emptySlots.push_back(p);
					}
			}

		}

	}
	return emptySlots;
}

Cordinate Mapa::getCordinateOfPath(Path * p)
{
	Cordinate playercord;
	Displayble* dis;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			dis = mapa[i][j];
			if (dis->toPath() == p) {
				playercord = { i,j };
			}
		}
	}
	return playercord;
}

vector<Path*> Mapa::getFilledSlots()
{
	
	vector<Path*>filledSlots;
	Path *p;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			Displayble * dis = mapa[i][j];
			if (dis->isPath()) {
				p = dis->toPath();
				if (p->isOccupied()) {
					if (p->getObjetOnPath()->isNpc()) {
						filledSlots.push_back(p);
					}
				}
			}

		}

	}
	return filledSlots;
}

vector<Path*> Mapa::getRoom1()
{
	vector<Path*>floor;
	for (int x = 3; x < 8; x++) {
		for(int y = 3; y < 30; y++) {
			Displayble* ids = mapa[x][y];
			if (ids->isPath()) {
				Path* p = ids->toPath();
				if (p->displayChar() == '.') {
					floor.push_back(p);
				}
			}
		}
	}
	return floor;
}

vector<Path*> Mapa::getRoom2()
{
	vector<Path*>floor;
	for (int x = 10; x < 25; x++) {
		for (int y = 3; y < 30; y++) {
			Displayble* ids = mapa[x][y];
			if (ids->isPath()) {
				Path* p = ids->toPath();
				if (p->displayChar() == '.') {
					floor.push_back(p);
				}
			}
		}
	}
	
	return floor;
}


