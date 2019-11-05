
#include "Displayble.h"
#include "Path.h"
#include "Npc.h"
#include "Gold.h"
#include "Potion.h"

Displayble::Displayble(char displayChar)
{
	dChar = displayChar;
}

bool Displayble::isPath() {
	return dynamic_cast<Path*>(this) != nullptr;
}

Path* Displayble::toPath() {
	return dynamic_cast<Path*>(this);
}
Karakter * Displayble::toKarakter()
{
	return dynamic_cast<Karakter*>(this);
}
Potion * Displayble::toPotion()
{
	{
		return dynamic_cast<Potion*>(this);
	}
}
bool Displayble::isPotion()
{
	return dynamic_cast<Potion*>(this) != nullptr;
}
bool Displayble::isNpc()
{
	return dynamic_cast<Npc*>(this) != nullptr;
}
Stats * Displayble::toStats()
{
	return dynamic_cast<Stats*>(this);
}
bool Displayble::isGold()
{
	return dynamic_cast<Gold*>(this) != nullptr;
}
Gold * Displayble::toGold()
{
	return dynamic_cast<Gold*>(this);
}
bool Displayble::isKarakter()
{
	return dynamic_cast<Karakter*>(this) != nullptr;
}
Npc * Displayble::toNpc()
{
	return dynamic_cast<Npc*>(this);
}
char Displayble::displayChar() {
	return dChar;
}

Displayble::~Displayble()
{
}
