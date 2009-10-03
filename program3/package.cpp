#include "package.h"

package::package(int dest)
{
	setDestination(dest);
	setTimeIn(0);
	setTimeOut(0);
	
}

package::package(int dest, int time_in)
{
	setDestination(dest);
	setTimeIn(time_in);
	setTimeOut(0);
	
}
void package::setDestination(int dest)
{
		this->destination = dest; 
}

void package::setTimeIn(int time_a)
{
	this->timeIn = time_a;
}

void package::setTimeOut(int time_a)
{
	this->timeOut = time_a;
}

//returns -1 if it is still in the facility
int package::totalTime()
{
	int total;
	if(this->timeIn != 0 && this->timeOut != 0)
	{
		total = this->timeOut - this->timeIn;
	}
	else
	{
		total = -1;
	}
	return total;
}

//print the package and all of its data members
void package::print()
{
	cout << "<package>" << endl;
	cout << "Destination: " << event::destination_string(this->destination) << endl;
	cout << "Arival Time: " << this->timeIn << endl;
	if(this->timeOut != 0)
	{
		cout << "Departure Time: " << this->timeOut << endl;
		cout << "Time In Building: " << totalTime() << endl;	
	}
	cout << "</package>" << endl << endl;
}