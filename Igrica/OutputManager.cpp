#include "OutputManager.h"
#include<iostream>
#include "MovmentManager.h"
#include "Npc.h"

using namespace std;
OutputManager* OutputManager::instance = nullptr;


OutputManager * OutputManager::getInstance()
{
	if (!instance) {
		instance = new OutputManager();
	}
	return instance;
}

void OutputManager::outInfo()
{
	if (whatToWrite == MOVMENT) {
		output(MovmentManager::getInstace()->getplayer());
		cout << s << endl;
	}
	else if (whatToWrite == Demage) {
		output(MovmentManager::getInstace()->getplayer());
		cout << s << endl;
	}
	else {
		output(MovmentManager::getInstace()->getplayer());
		cout << "Action: PC just spawned" << endl;
	}
}

void OutputManager::output(Karakter * player)
{
	cout << "Race: " << player->getRacebyString() << " Gold: " << player->getGold() << endl;
	cout << "HP: " << player->getHP() << endl;
	cout << "Atk: " << player->getAtk() << endl;
	cout << "Def: " << player->getDef() << endl;
}

void OutputManager::outputMovment(Cordinate cor)
{
	 s = "Action: PC moves ";
	s+= movmentOutput(cor ) + ifPotion();
	whatToWrite = MOVMENT;
}

void OutputManager::outputDmg(Path * p)
{
	Npc* monster = p->getObjetOnPath()->toNpc();
	s = "Action : PC deals ";
	s += to_string(monster->getDmg());
	s += " to ";
	s += monster->displayChar();
	s += " (";
	s += to_string(monster->getHP());
	s += "). ";
	whatToWrite = Demage;
}

string OutputManager::movmentOutput(Cordinate cor)
{
	string s;
	switch (cor.x)
	{
	case 1:
		switch (cor.y)
		{
		case 0:
			return s = "south";
		case 1:
			return s = "southeast";
		case -1:
			return s = "soutwest";
		default:
			break;
		}
	case 0:
		switch (cor.y)
		{
		case 0:
			return s = "didnt move";
		case 1:
			return s = "east";
		case -1:
			return s = "west";
		default:
			break;
		}
	case -1:
		switch (cor.y)
		{
		case 0:
			return s = "north";
		case 1:
			return s = "northeast";
		case -1:
			return s = "northwest";
		default:
			break;
		}
	default:
		break;
	}
}

string OutputManager::ifPotion()
{
	Cordinate addCord;
	string potion = "";
	Cordinate playercor = MovmentManager::getInstace()->getPlayerCord();
	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			if (x == 0 && y == 0) {

			}
			else {
				addCord = { x,y };
				Displayble* dis = Mapa::getInstance()->getDisplayable(playercor + addCord);
				if (dis->isPath())
				{
					Path* p = dis->toPath();
					if (p->isOccupied()) {
						if (p->getObjetOnPath()->isPotion()) {
							potion = " unknow potion to the ";
							potion += movmentOutput(addCord);

						}
					}
				}
			}
		}
	}


	return potion;
}

OutputManager::OutputManager()
{
}


OutputManager::~OutputManager()
{
}
