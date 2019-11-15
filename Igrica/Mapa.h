#pragma once

#include "Displayble.h";
#include <vector>
#include"Path.h"
#include<set>

using namespace std;

struct Cordinate
{
	int x, y;
	Cordinate operator+(Cordinate const& rhs) {
		return { x + rhs.x, y + rhs.y };
	};
	Cordinate operator+=(Cordinate const& rhs) {
		return { x = x + rhs.x,y = y + rhs.y };
	};
	Cordinate operator-(Cordinate const& rhs) {
		return { x - rhs.x, y - rhs.y };
	};
};



class Mapa 
{
private:
	Displayble* mapa[25][80];
	void fillMap();
	Mapa();
	static Mapa* instance;
	
public:
	static Mapa* getInstance();
	void printMap();
	Displayble * getDisplayable(Cordinate cord);
	vector<Path*> getEmptySlots();
	Cordinate getCordinateOfPath(Path* p);
	vector<Path*> getMonsterSlots();
	vector<Path*> getPathsAroundByCord(Cordinate startingCor);
	vector<Path*> getAllPath();
	vector<Path*> getFilledSlots();
	void getFloor(Path* startingPath, set<Path*>& allreadyBeen);
	void resetObjectsOnPath();
};
	
	
