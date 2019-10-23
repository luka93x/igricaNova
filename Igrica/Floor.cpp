#include "pch.h"
#include "Floor.h"

Floor::Floor()
{
}
Floor::~Floor()
{
}

char Floor::displayChar()
{
	if (!placeholder) {
		return '.';
	}

	return placeholder->displayChar();

}
