#include "plane.h"

plane::plane()
{
	destination = package::UNKNOWN;
}
plane::plane(int dest)
{
	setDestination(dest);
}
void plane::setDestination(int dest)
{
	if((dest == package::MEM ) || (dest == package::CHI))
		{
		this->destination = dest; 
	} 
	else
		{
			this->destination = package::UNKNOWN;
		}
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