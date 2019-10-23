#pragma once
#include"Displayble.h"
#include "Ceiling.h"

class Floor : public Displayble
{
public:
	
	Floor();
	~Floor();
	Displayble *placeholder;
	virtual char displayChar() override;
};

