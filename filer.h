#ifndef FILER_H
#define FILER_H
 
#include <string>

using namespace std;

/**
**NAME: Andrew Fleener
**Course: CSCI 362
**Assignment: Program 1
**Class: filer
**Description: This is the interface for the filer class
**/
//header file FILER.H for class filer
//a class object can create a file of a specified
//number of random integers in a specified range

class filer
{
public:
	void makefile(int n, int range, bool truly_random, string file_name);
	//precondition: n, range, truly_random, and file_name have 
	//been set; truly_random is type bool, and determines whether 
	//the numbers are truly random, or pseudorandom
	//postcondition: n random integers in the range 0-range,
	//inclusive, have been written to a file named file_name,
	//one per line;
	
	string askForFileName();
	//this will ask the user to input a name for the file
	
	int howManyNumbers();
	//this will ask the user how many random number to generate

	int whatsTheRange();
	//this will ask the user for the range

	bool trulyRandomNumbers();
	//this will ask the user for if they want truly random numbers

private:
	int next_number(int range);
	//precondition:  range has been set to a nonnegative value
	//postcondition:  returns a random integer in the range
	//0-range, inclusive

};

#endif //FILER_H




