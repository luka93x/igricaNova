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

void OutputManager::outputDmg(Path * p)
{
	Npc* monster = p->getObjetOnPath()->toNpc();
	outputString = "Action : PC deals ";
	outputString += to_string(monster->getDmg());
	outputString += " to ";
	outputString += monster->displayChar();
	outputString += " (";
	outputString += to_string(monster->getHP());
	outputString += "). ";
	whatToWrite = OTHER;
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

/*
Tacka pocetna;
Set tackeKojeSamObisao;

obidjiTacke(Tacka dataTacka, set& tackeKojeSamObisao) {
	vector<Tacka> okolneTacke = dajOkolne(dataTacka);
	tackeKojeSamObisao.add(dataTacka);
	for (tacka : okolneTacke) {
		if (!tackeKojeSamObisao.contains(tacka)) {
			obidjiTacke(tacka);
		}
	}
}*/