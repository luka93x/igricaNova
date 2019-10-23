#pragma once
#include "Displayble.h"
#include "Karakter.h"
class Path : public Displayble 
{
protected:
	
private:
	Displayble* objectOnPath = nullptr;

public:
	Path(char def);
	bool isOccupied();
	void setObjectOnPath(Displayble* object);
	char displayChar() override;
	Displayble * getObjetOnPath();
};

