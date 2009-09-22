#ifndef PLANE_H
#define PLANE_H

#include "package.h"

class plane
{
public:

   	static const int CHI = 1;
   	static const int MEM = 2;
   	static const int PROCESS_TIME = 25;
	static const int MAX_PACKAGES = 25;


	plane(int dest);
	void setDestination(int dest);
	void loadPkg(package&);
	bool isNotFull();
	int getDestination() const{ return destination; };
	void print();
private:
	int destination;
	stack<package> cargo;
};
#endif