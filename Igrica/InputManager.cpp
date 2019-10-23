#include "InputManager.h"
#include <iostream>
using namespace std;
InputManager* InputManager::instance = nullptr;

Direction InputManager::returnDirection(string input)
{
	Direction dir;
	if (input == "no") {
		return dir = Direction::UP;
	}
	else if (input == "so") {
		return dir = Direction::DOWN;
	}
	else if (input == "we") {
		return dir = Direction::LEFT;
	}
	else if (input == "ea") {
		return dir = Direction::RIGHT;
	}
	else if (input == "nw") {
		return	dir = Direction::UL;
	}
	else if (input == "ne") {
		return dir = Direction::UR;
	}
	else if (input == "se" ) {
		return	dir = Direction::DR;
	}
	else if (input == "sw" ) {
		return	dir = Direction::DL;
	}
	else
	return dir = Direction::NONE;

}

InputManager * InputManager::getInstance()
{
	if (!instance) {
		instance = new InputManager();
	}
	return instance;
}

string InputManager::input()
{
	string s;
	cin >> s;
	return s;
}

char InputManager::charForRace()
{
	char c;
	cin >> c;
	return c;
}

Race InputManager::getRacefromChar(char c)
{
	Race race;
	
	if (c == 'o' || c== 'O') {
		race = ORC;
	}
	else if (c == 'e' || c== 'E') {
		race = ELF;
	}
	else if (c == 'd' || c == 'D') {
		race = DWARF;
	}
	else race = HUMAN;

	return race;
}
	
static Cordinate resolveDirection(Direction direction) {
	switch (direction)
	{
	case UP:
		return{ -1,0 };
	case DOWN:
		return{ 1,0 };
	case LEFT:
		return { 0, -1 };
	case RIGHT:
		return { 0, 1 };
	case UR:
		return{ -1,1 };
	case UL:
		return{ -1,-1 };
	case DR:
		return{ 1,1 };
	case DL:
		return { 1,-1 };
	case NONE:
		return { 0,0 };
	default:
		return{ 0,0 };
	}
}

	
pair<Action, Cordinate>* InputManager::returnAction(string input)
{

	Action act;
	if (input.at(0) == 'u') {
		pair1.first = Action::USE;
		string direction = input.substr(1, 2);
		pair1.second = resolveDirection(returnDirection(direction));
	}
	else if (input.at(0) == 'a') {
		pair1.first = Action::ATTACK;
		string direction = input.substr(1, 2);
		pair1.second = resolveDirection(returnDirection(direction));
	}
	else {
		pair1.first = Action::MOVE;
		pair1.second = resolveDirection(returnDirection(input));
	}
	return &pair1;
}
	
InputManager::InputManager()
{
}


