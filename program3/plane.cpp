#include "plane.h"

plane::plane(int dest)
{
	setDestination(dest);
}
void plane::setDestination(int dest)
{
	this->destination = dest; 
}

void plane::loadPkg(package &pkg)
{
	this->cargo.push(pkg);
}

bool plane::isPlaneFull()
{
	bool planeFull =  (this->cargo.size() == 25) ? true : false;
	return planeFull;
}