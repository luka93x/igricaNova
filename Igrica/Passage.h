#pragma once
#include "Displayble.h"
class Passage : public Displayble
{
public:
	Passage();
	~Passage();
	virtual char displayChar() override;
	Displayble *placeholder;
};

