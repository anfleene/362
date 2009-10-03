#include "plane.h"

plane::plane(int dest)
{
	setDestination(dest);
	this->cargo = new stack<package>;
}

void plane::setDestination(int dest)
{
	this->destination = dest; 
}

//add a package into the cargo stack
void plane::loadPkg(package* pkg)
{
	this->cargo->push(*pkg);
}

//returns true unless cargo is eql to 25
bool plane::isNotFull()
{
	bool planeNotFull =  (this->cargo->size() == 25) ? false : true;
	return planeNotFull;
}

//prints out the plane and it's data members
void plane::print()
{
	cout << "<plane>" << endl;
	cout << "Destination: " << event::destination_string(this->destination) << endl;
	cout << "# of Packages: " << this->cargo->size() << endl;
	cout << "Cargo Content: " << endl;
	print_cargo();
	cout << "</plane>" << endl << endl;
	
}

//loops through the cargo packages and prints them out
void plane::print_cargo()
{
	stack<package> temp = *this->cargo;
	int i=1;
	while(temp.size() != 0)
	{
		cout << "Package #: " << i << endl;
		temp.top().print();
		temp.pop();
		i++;		
	}

	
}