/*
*Name: Andrew Fleener
*Date: 9/22/09
*Description: event is an object that contains a destination, event type, and a time for the event to happen
* The event class also contains some static functions and constants
* The functions create different types of events based on their names for example event::pkg creates a package event at a given time
* with a random destination assigned to it. the constants are integers that either portray a type of event or a destination
* I have also overloaded the < operator so that events can be compared based on time
*/
#ifndef EVENT_H
#define EVENT_H

#include "package.h"

class event
{
public:
	static const int PKG_ARRIVAL = 0;
	static const int PLANE_ARRIVAL = 1;
	static const int END_OF_SERVICE = 2;
   	static const int CHI = 1;
	static const int MEM = 2;
	static const int UNDEFINED = 0;
	event(int, int, int);
	static string destination_string(int);
	static event pkg(int time_a);
	static event plane(int time_a, int dest);
	static event eos(int time_a);
	int getType(){ return this->type; };
	int getTime(){ return this->time; };
	int getDestination(){ return this->destination; };
	bool operator<(event &);
	void print();
private:
	string destination_string();
	string type_string();
	int type;
	int time;
	int destination;
};
#endif