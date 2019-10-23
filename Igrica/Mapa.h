#pragma once

#include "Displayble.h";
#include <vector>
#include"Path.h"

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
	vector<Path*> getFilledSlots();
	vector<Path*>getRoom1();
	vector<Path*>getRoom2();
	vector<Path*>getRoom3();
};
	
	
