/*
*Name: Andrew Fleener
*Date: 9/22/09
*Description: This is the plane object, it is mostly a data container. It has a few interesting methods. It can load a package, and tell
*if it is full or not. It contains a stack of packages that is it's cargo
*/
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
	void loadPkg(package*);
	bool isNotFull();
	int getDestination() const{ return destination; };
	stack<package>* getCargo(){ return this->cargo; };
	void print();
private:
	void print_cargo();
	int destination;
	stack<package>* cargo;
};
#endif