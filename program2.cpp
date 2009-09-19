/*
*Name: Andrew Fleener
*Date: 9/8/09
*Description: This client program builds three different data structures(array, vector, and linked list) from a single file
*it then asks the user to input a postion in these data structures to delete, then it informs the user of the value in each to be 
*deleted and removes them from the sturcture and reprints the data. The array structure in the client is an Array wrapper class for
*integers, to self manage its data better than a normal array. I also modified the linked list class to act more like a real linked list
*
*/



#include "utility.h"
#include "intArray.h"
#include "intSLLst.h"
/*--------------------------------------Vector Functions--------------------------------------*/
/*
This method just prints the vector
*/
void printVector(vector<int> &list)
{
	cout << "-----------<Vector>-----------" << endl;
	for(int j=0; j < list.size(); j++)
	{
			cout << list.at(j); 
			if(j != (list.size() - 1))
				cout << ", ";
	}
	cout << endl << "-----------</Vector>-----------" << endl;
	
}

/*
This method loads a vector from a file and pases the value by reference (the calling list is modified)
*/
void loadVectorFromFile(int size, string filename, vector<int> &vec)
{
	ifstream file;
	vec.resize(size);
	file.open( filename.c_str());
	if ( !file )
	{ 
		exit(1);
	}
	int el;
	for(int i=0; i < size; i++)
	{
		file >> el;
		//add a new element at the current position
		vec.at(i) = el;
	}
}

int deleteAtPos(int pos, vector<int> &vec)
{
	int el = vec[pos-1];
	vec.erase(vec.begin() + (pos-1));
	return el;	
}

/*--------------------------------------/Vector Functions--------------------------------------*/

/*--------------------------------------Linked List Functions--------------------------------------*/
/*
This method loads a linked list from a file and pases the value by reference (the calling list is modified)
*/
void loadListFromFile(int size, string filename, IntSLList &list)
{
	ifstream file;
	file.open( filename.c_str());
	if ( !file )
	{ 
		exit(1);
	}
	int el;
	for(int i=0; i < size; i++)
	{
		file >> el;
		//add an element onto the end of the list
		list.addToTail(el);
	}
}
/*--------------------------------------/Linked List Functions--------------------------------------*/
/* 
This method is data structure agnostic it determines how many ints are in the file
*/
int numLines(string filename){
	ifstream file;

	file.open( filename.c_str() );
	if ( !file ) 
     	return 0;
	int numLines = 0;
	string line;
   	while ( !file.eof() )
   	{
       	getline(file, line);
       	numLines++;
   	}
	return numLines-1;//it adds an extra empty line
}

int main ()
{
	//create basic information
	string filename = "data.txt";
	int size = numLines(filename);
	
	//create an empty intArray object initialized to the size needed 
	intArray array = intArray(size);
	//load the array from the file and print
	array.loadFromFile(filename);
	array.print();
	
	//create an empty linked list
	IntSLList list; 
	//load the values into the linked list form the file and print
	loadListFromFile(size, filename, list);
	list.printAll();
	
	//create an empty vector
	vector<int> vec_list;
	//load values into the vector form the file and print
	loadVectorFromFile(size, filename, vec_list);
	printVector(vec_list);

	//ask for user input: on the position of the element to be deleted
	cout << "Please input a postion to be selected and delted from each structure"<< endl;
	int pos;
	//record the position
	cin >> pos;	
	
	//out put the value of the element to be deleted (and delete it)
	cout << "This is the value at " << pos << " for the array that will be deleted: " << array.deleteAt((pos-1)) << endl;//this is pos-1 because its the index not the position
	cout << "This is the value at " << pos << " for the linked list that will be deleted: " << list.deleteNodeAt(pos) << endl;//this is based on position
	cout << "This is the value at " << pos << " for the vector that will be deleted: " << deleteAtPos(pos, vec_list) << endl;//this is based on position
	
	//print all the data structures that are now free of the element that was selected
	array.print();
	list.printAll();
	printVector(vec_list);
	
return 0;
}