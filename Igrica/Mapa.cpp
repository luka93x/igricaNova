#include "Mapa.h"
#include <iostream>
#include "Path.h"
#include"Karakter.h"
#include"Npc.h"
#include <algorithm>
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
	vector<Path*>allPath = getAllPath();
	vector<Path*>emptySlots;
	Path *p;
	for (int i = 0; i < allPath.size(); i++) {
		p = allPath[i];
		if (p->displayChar() == '.')
			if (!p->isOccupied()) {
				emptySlots.push_back(p);
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
	vector<Path*>allPath = getAllPath();
	vector<Path*>filledSlots;
	Path *p;
	for (int i = 0; i < allPath.size(); i++) {
		p = allPath[i];
		if (p->isOccupied()) {
			if (p->getObjetOnPath()->isNpc()) {
				filledSlots.push_back(p);
			}
		}
	}
	return filledSlots;
}

vector<Path*> Mapa::getPathsAroundByCord(Cordinate startingCor)
{
	Cordinate addCord;
	vector<Path*>surroundingPaths;
	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			if (x != 0 || y != 0) {
				addCord = { x,y };
				Displayble* dis = Mapa::getInstance()->getDisplayable(startingCor + addCord);
				if (dis->isPath())
				{
					Path* p = dis->toPath();
					surroundingPaths.push_back(p);
				}
			}
		}

	}
	return surroundingPaths;
}
vector<Path*> Mapa::getAllPath()
{
	vector<Path*>allPaths;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			Displayble * dis = mapa[i][j];
			if (dis->isPath()) {
				Path*	p = dis->toPath();
				allPaths.push_back(p);
			}

		}
	}
	return allPaths;
}
void Mapa::getFloor(Path * startingPath, vector<Path*>& allreadyBeen)
{
	vector<Path*> pathsAround = getPathsAroundByCord(getCordinateOfPath(startingPath));
	allreadyBeen.push_back(startingPath);
	for (int i = 0; i < pathsAround.size(); i++) {
		Path* p = pathsAround[i];
		if (find(allreadyBeen.begin(), allreadyBeen.end(),p) == allreadyBeen.end()) {
			getFloor(p, allreadyBeen);
		}
		

	}
}

