#ifndef PACKAGE_H
#define PACKAGE_H

#include "utility.h"

class package
{
public:

   	static const int   CHI = 1;
   	static const int   MEM = 2;
   	static const int   PROCESS_TIME = 8;

	package(int dest);
	void setDestination(int dest);
	int getDestination() { return this->destination; };
private:
	int destination;
	
};
#endif