#pragma once
class Karakter;
class Path;
class Potion;
class Stats;
class Gold;
class Npc;
class Stairs;
class Displayble

{
public:
	virtual char displayChar();
	bool isPath();
	Path* toPath();
	Karakter* toKarakter();
	Potion* toPotion();
	bool isPotion();
	bool isNpc();
	Stats* toStats();
	bool isGold();
	Gold* toGold();
	bool isKarakter();
	Npc* toNpc();
	bool isStairs();
	Stairs* toStairs();
protected:
	Displayble(char displayChar);
	virtual ~Displayble();
	
private:
	char dChar;
};

class Ceiling : public Displayble
{
public:
	Ceiling() : Displayble('-') {};
};

class Wall : public Displayble
{
public:
	Wall() : Displayble('|') {};
};

class EmptySpace : public Displayble
{
public:
	EmptySpace() : Displayble(' ') {};
};

