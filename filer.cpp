/**
**NAME: Andrew Fleener
**Course: CSCI 362
**Assignment: Program 1
**Class: filer
**Description: This class will create a file that is contains random number, the number of numbers, the range of the numbers
**the file name, and whether the numbers are truly random or not is determined by user input
**/



#include "utility.h"
#include "filer.h"

void filer::makefile(int n, int range, bool truly_random, bool odd,string file_name)
{
	//set truly random
	if(truly_random)
	{
		srand ( time(NULL) );
	}
	
	//open a file called *the value of file_name*
	ofstream myfile;
	myfile.open (file_name.c_str());
	
	//loop next_number n number of times
	for(int i=1; i <= n; i++)
	{
		myfile << next_number(abs(range), odd);
		if(i != n)
		{
			myfile << endl;
		}	
	}

	//close the file
	myfile.close();
}

int filer::next_number(int range, int odd)
{
	//returns a random number between 0 and the range
	int ran;
	if(odd){
		ran = 2 * rand() + 1;
	}else{
		ran = 2 * rand();
	}
	int num = ran % range;
	return abs(num);
}

string filer::askForFileName()
{
	//asks for a filename and returns it
	string inputfname;
	cout << "Name a the file please"<< endl;
	cin >> inputfname;
	string filename = inputfname + ".txt";
	return filename;
}

int filer::howManyNumbers()
{
	//asks for how many numbers you need and returns the int
	int howMany;
	cout << "How Many Numbers Would You like?"<< endl;
	cin >> howMany;
	return howMany;
}

int filer::whatsTheRange()
{
	//ask for the range and returns it
	int theRange;
	bool redo = true;
	cout << "What would you like the upper limit of the random numbers to be?(the lower limit is 0)"<< endl;
	cin >> theRange;
	return theRange;
}

bool filer::trulyRandomNumbers()
{
	//ask if you want truly random numbers and returns true or false
	bool random;
	string yesNo;
	cout << "Do you want truly random numbers?(y/n) "<< endl;
	cin >> yesNo;
	if(yesNo == "y" || yesNo == "Y")
	{
		random = true;
	}
	else
	{
		random = false;
	}
	return random;
}

bool filer::oddOrEven()
{
	//ask if you want odd or even numbers and returns true or false
	bool odd;
	string oddEven;
	cout << "Do you want odd or even numbers?(o/e) "<< endl;
	cin >> oddEven;
	if(oddEven == "O" || oddEven == "o")
	{
		odd = true;
	}
	else
	{
		odd = false;
	}
	return odd;
}