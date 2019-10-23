#include "pch.h"
#include "Door.h"


Door::Door()
{
}


Door::~Door()
{
}

char Door::displayChar()
{
	if (!placeholder) {
		return '+';
	}

	return placeholder->displayChar();

}
