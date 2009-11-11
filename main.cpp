#include "filer.h"

int main ()
{
	filer *test;
 	test = new filer();
//get inputs
	int n = test->howManyNumbers();
	int range = test->whatsTheRange();
	string filename = test->askForFileName();
	bool truly_random = test->trulyRandomNumbers();
	//make the file
	test->makefile(n, range, truly_random, filename);
	 return 0;
}
