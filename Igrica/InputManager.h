#pragma once
#include<string>
#include"Mapa.h"
#include "Karakter.h"
using namespace std;
enum Direction
{
	UP, DOWN, LEFT, RIGHT, UR, UL, DR, DL, NONE
};
enum Action {
	USE,ATTACK,MOVE
};
class InputManager
{
public:
	pair<Action,Cordinate>* returnAction(string input);
	Direction returnDirection(string input);
	static InputManager* getInstance();
	string input();
	char charForRace();
	Race getRacefromChar(char c);
	
private:
	pair<Action, Cordinate> pair1;
	InputManager();
	static InputManager* instance;
};

;