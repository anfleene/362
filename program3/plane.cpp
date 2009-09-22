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

bool plane::isNotFull()
{
	bool planeNotFull =  (this->cargo.size() == 25) ? false : true;
	return planeNotFull;
}

void plane::print()
{
	cout << "<plane>" << endl;
	cout << "Destination: " << event::destination_string(this->destination) << endl;
	cout << "# of Packages: " << this->cargo.size() << endl;
	cout << "</plane>" << endl << endl;
	
}