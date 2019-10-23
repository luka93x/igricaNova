#pragma once
#include "Path.h"
#include <vector>
#include "Mapa.h"
using namespace std;
class MonsterManager
{
public:
	static MonsterManager* getInstance();
	void resolveAllMonsters(vector<Path*> filledSpots);
	
private:
	MonsterManager();
	~MonsterManager();
	static MonsterManager* instance;
	void attackOrMove(Path* monster);
	vector<Path*> pathsAroundMonster(Cordinate cor);
	Path* isKarakterNext(vector<Path*> paths);
	
};

