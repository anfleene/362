/*
*Name: Andrew Fleener
*Date: 9/8/09
*Description: This class is a wapper for an int array, instead of creating methods inside the client that will never be used again 
*I created a wrapper that will manage an int array's data. It keeps track of the size and behaves like an array, it also adds a little 
*more funtionality so that it can do basic things like print, delete an element and load its self from a file
*/

#ifndef INTARRAY_H
#define INTARRAY_H

#include <string>

using namespace std;

class intArray
{
public:
	intArray()
	{
		size = 0;
		array = NULL;
	};
	
	intArray(int* a_array, int a_size)
	{
		size = a_size;
		array = a_array;
	};
	
	intArray(int a_size)
	{
		size = a_size;
		array = new int[size];
	};
	//this is never used only created for a better understanding of a copy constructor
	intArray(const intArray &int_array)
	{
		size = int_array.getSize();
		array = new int[size];
		for(int i=0; i < size; i++)
			array[i] = int_array[i];
	};
	
	~intArray();
	void print();
	
	void loadFromFile(string filename);
	
	//this deletes from an index to act like an array
	int deleteAt(int index);
	//this gets the value at the index just like an array would
	int operator [] (int index) const { return array[index]; };
	
	int *getArray() const { return array; };
	
	int getSize() const { return size; };
	
private:
	int *array;
	int size;
};

#endif