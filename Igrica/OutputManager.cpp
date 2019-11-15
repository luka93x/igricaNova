#include "OutputManager.h"
#include<iostream>
#include "MovmentManager.h"
#include "Npc.h"
#include <stdlib.h>
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
	output(MovmentManager::getInstace()->getplayer());

	if (whatToWrite == SPAWN) {
		cout << "Action: PC just spawned" << endl;
	}
	else cout << outputString << endl;
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
	outputString = "Action: PC moves ";
	outputString += movmentOutput(cor) + ifPotion();
	whatToWrite = OTHER;
}

void OutputManager::outputDmg(Path * p,int dmg)
{
	Npc* monster = p->getObjetOnPath()->toNpc();
	outputString = "Action : PC deals ";
	outputString += to_string(dmg);
	outputString += " to ";
	outputString += monster->displayChar();
	outputString += " (";
	outputString += to_string(monster->getHP());
	outputString += "). ";
	whatToWrite = OTHER;
}

void OutputManager::merchant()
{
	Karakter* player = MovmentManager::getInstace()->getplayer();
	Potion* potion;
	system("CLS");
	cout << "Welcome to the shop u can buy :" << endl;
	cout << "1.Potion of healing 2 gold" << endl;
	cout << "2.Potion of Attack boost 2 gold" << endl;
	cout << "3.Potion of Defense boost 2 gold" << endl;
	cout << "Write the number of item u want to buy  , exit shop on x" << endl;

	char input;
	cin >> input;
	if (player->getGold() < 2) {
		cout << "You dont have enought gold to buy potion";
		}
	else {
		switch (input)
		{
		case '1':
			potion = new Potion("RH");
			player->addGold(-2);
			potion->usePotion(player);
			break;
		case '2':
			potion = new Potion("BA");
			player->addGold(-2);
			potion->usePotion(player);
			break;
		case '3':
			potion = new Potion("BD");
			player->addGold(-2);
			potion->usePotion(player);
			break;
		case 'x':
			break;
		default:
			break;
		}

	}
}

void OutputManager::stairs()
{
	outputString = "Action : PC have climbed the stairs to new floor ";
}

string OutputManager::movmentOutput(Cordinate cor)
{

	switch (cor.x)
	{
	case 1:
		switch (cor.y)
		{
		case 0:
			return   "south";
		case 1:
			return  "southeast";
		case -1:
			return  "soutwest";
		default:
			break;
		}
	case 0:
		switch (cor.y)
		{
		case 0:
			return  "didnt move";
		case 1:
			return  "east";
		case -1:
			return  "west";
		default:
			break;
		}
	case -1:
		switch (cor.y)
		{
		case 0:
			return "north";
		case 1:
			return  "northeast";
		case -1:
			return  "northwest";
		default:
			break;
		}
	default:
		break;
	}
}

string OutputManager::ifPotion() {

	auto mapa = Mapa::getInstance();
	Path* p;
	string outputForPotion = "";
	Cordinate playercor = MovmentManager::getInstace()->getPlayerCord();
	vector<Path*>allPaths = mapa->getPathsAroundByCord(playercor);
	for (int i = 0; i < allPaths.size(); i++) {
		p = allPaths[i];
		if (p->isOccupied()) {
			if (p->getObjetOnPath()->isPotion()) {
			
				outputForPotion = potionOutput(p);
				
			}
		}
	}
	return outputForPotion;
}

OutputManager::OutputManager()
{
}


OutputManager::~OutputManager()
{
}

string OutputManager::potionOutput(Path * p)
{
	Cordinate playercor = MovmentManager::getInstace()->getPlayerCord();
	Cordinate potionCor = Mapa::getInstance()->getCordinateOfPath(p);
	string output;
	Karakter* player = MovmentManager::getInstace()->getplayer();
	Potion* potion = p->getObjetOnPath()->toPotion();
	if (player->isPotionTypedUsed(potion->getPotionType())) {
		output = potion->getPotionTypeByString();
		output += movmentOutput(potionCor - playercor);
	}
	else {
		output = " unknow potion to the ";
		output += movmentOutput(potionCor - playercor);
	}
	return output;
}

