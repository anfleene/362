#include "event.h"

event::event(int type_a, int time_a, int dest)
{	
	this->type = type_a;
	this->time = time_a;
	this->destination = dest;
}

event event::pkg(int time_a)
{
	int dest = rand() % 2 + 1;
	event e = event(event::PKG_ARRIVAL, time_a, dest);
	return e;
}

event event::plane(int time_a, int dest){
	event e = event(event::PLANE_ARRIVAL, time_a, dest);
	return e;
}

event event::eos(int time_a)
{
	event e = event(event::END_OF_SERVICE, time_a, event::UNDEFINED);
	return e;
}

bool event::operator<(event &e)
{
  return (this->getTime() < e.getTime());
}

string event::destination_string(int dest)
{
	string s;
	if (dest == event::CHI)
	{
		s = "Chicago";
	}
	else if(dest == event::MEM)
	{
		s = "Memphis";
	}
	else
	{
		s = "Undefined";
	}
	return s;
}

string event::destination_string()
{
	return event::destination_string(this->destination);
}

string event::type_string()
{
	string s;
	if (this->type == event::PKG_ARRIVAL)
	{
		s = "Package Arrival";
	}
	else  if (this->type == event::PLANE_ARRIVAL)
	{
		s = "Plane Arrival";
	}
	else
	{
		s = "End of Service";
	}
	return s;
}

void event::print()
{
	cout << "<event>" << endl;
	cout << "Type: " << this->type_string() << endl;
	cout << "Destination: " << this->destination_string() << endl;
	cout << "Time: " << this->getTime() << endl;
	cout << "</event>" << endl << endl;
}
