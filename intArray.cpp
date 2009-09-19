#include "utility.h"
#include "intArray.h"


//this method just prints out the array
void intArray::print()
{
	cout << "-----------<Array List>-----------" << endl;
	for(int i=0; i < this->size; i++)
	{
		cout << this->array[i];
		if(i != (size-1))
		{
			cout << ", ";
		}
	}
	cout << endl << "-----------</Array List>-----------" << endl;
	
}

//this method builds the array from at file and stores it as the internal array
void intArray::loadFromFile(string filename)
{
	ifstream file;
	file.open( filename.c_str());
	if ( !file )
	{ 
		exit(1);
	}
	for(int i=0; i < this->size; i++)
	{
		file >> this->array[i];
	}
}

//this method deletes at the pased index (for this the first postion would be 0 so passing 1 would delete the second element)
int intArray::deleteAt(int index)
{
	//set a return value before it is removed
	int return_val = this->array[index];
	//change the size
	size -= 1;
	//re build the array starting from the passed index and rewriting over it with the next value
	for(int i=index; i < this->size; i++)
	{
		this->array[i] = this->array[i+1];
	}
	//return the value of deleted element
	return return_val;
}

//destroy the object and its data
intArray::~intArray() {
	delete []this->array;
	size = NULL;
}