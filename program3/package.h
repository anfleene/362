/*
*Name: Andrew Fleener
*Date: 9/22/09
*Description: This class is a package object, it is mostly just a data container. It contains one insteresting method that calculates
*the total amount of time the package took to while it was in the facility
*/
#ifndef PACKAGE_H
#define PACKAGE_H

#include "utility.h"
#include "event.h"

class package
{
public:

   	static const int   CHI = 1;
   	static const int   MEM = 2;
   	static const int   PROCESS_TIME = 8;

	package(int dest);
	package(int dest, int time_in);
	void setDestination(int dest);
	void setTimeIn(int);
	void setTimeOut(int);
	int totalTime();
	int getDestination() { return this->destination; };
	void print();
private:
	int destination;
	int timeIn;
	int timeOut;
	
};
#endif