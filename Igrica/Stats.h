#pragma once
class Stats
{
public:
	Stats();
	~Stats();
	void setHP(int _hp);
	int getHP();
	void setMaxHp(int _maxhp);
	void setAtk(int _atk);
	int getAtk();
	void setDef(int _def);
	int getDef();
	bool isDead();
	void addHP(int num);
	virtual bool checkIfMonster() = 0;
	void demage(int dmg);
	
protected:
	int hp, def, atk, maxhp;
	
};