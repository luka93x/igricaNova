#include "Path.h"

Path::Path(char def):Displayble(def)
{
	objectOnPath = nullptr;
}

bool Path::isOccupied()
{ 
	return objectOnPath!=nullptr;
}

void Path::setObjectOnPath(Displayble* object) {
	objectOnPath = object;
}

char Path::displayChar() {
	if (isOccupied()) {
		return objectOnPath->displayChar();
	}
	return  Displayble::displayChar();
}

Displayble * Path::getObjetOnPath()
{
	return objectOnPath;
}


