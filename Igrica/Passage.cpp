#include "pch.h"
#include "Passage.h"


Passage::Passage()
{
}


Passage::~Passage()
{
}

char Passage::displayChar()
{
	if (!placeholder){
		return  '#';
	}
	return placeholder->displayChar();
}
