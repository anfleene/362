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