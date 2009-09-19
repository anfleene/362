#ifndef PLANE_H
#define PLANE_H

#include "package.h"

class plane
{
public:

	static const int UNKNOWN = 0;
   	static const int CHI = 1;
   	static const int MEM = 2;
	static const int CHI_ARRIVAL_TIME = 150;
	static const int MEM_ARRIVAL_TIME = 180;
   	static const int PROCESS_TIME = 25;
	static const int MAX_PACKAGES = 25;


	plane();
	plane(int dest);
	void setDestination(int dest);
	void loadPkg(package&);
	bool isPlaneFull();
	int getDestination() const{ return destination; };
private:
	int destination;
	stack<package> cargo;
};
#endif