#pragma once
#include"Displayble.h"
class Door : public Displayble
{
public:
	Door();
	~Door();
	Displayble *placeholder;
	virtual char displayChar() override;
};

