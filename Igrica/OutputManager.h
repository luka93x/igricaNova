#pragma once
#include "Karakter.h"
#include "Mapa.h"
#include <string>
#include "Path.h"
using namespace std;
enum out{SPAWN,OTHER};
class OutputManager
{
public:
	static OutputManager* getInstance();
	void outInfo();
	void output(Karakter* player);
	void outputMovment(Cordinate cor);
	void outputDmg(Path* p,int dmg);
	void merchant();
	void stairs();
private:
	string movmentOutput(Cordinate cor);
	static OutputManager* instance;
	string ifPotion();
	OutputManager();
	~OutputManager();
	out whatToWrite = SPAWN;
	string outputString;
	string potionOutput(Path* p);
};

