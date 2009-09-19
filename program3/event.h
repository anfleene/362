#ifndef EVENT_H
#define EVENT_H

class event
{
public:
	static const int PKG_ARRIVAL = 0;
	static const int PLANE_ARRIVAL = 1;
	static const int END_OF_SERVICE = 2;
   	static const int CHI = 1;
	static const int MEM = 2;
	event(int, int, int);
	getType();
	getTime();
	getDestination();
private:
	int type;
	int time;
	int destination;
};
#endif