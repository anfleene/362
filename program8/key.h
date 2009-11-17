#ifndef KEY_H
#define KEY_H

#include "utility.h"
//header file for class Key.  Keys are
//just integers with overloaded comparison
//operators to count compares.

class Key
{
public:
	//static variable to count the number of
	//times a comparison is made against a Key object
	static double comparisons;
	
	Key (int x = 0);
	//constructor 
	//default is to set the integer value key to 0

	int the_key() const;
	//accessor function - to inspect key value

private:
	int key;
};
#endif //KEY_H
//overload relational operators for type Key
//each also increments the comparisons counter variable
bool operator ==(const Key &x, const Key &y);
bool operator > (const Key &x, const Key &y);
bool operator < (const Key &x, const Key &y);
bool operator >=(const Key &x, const Key &y);
bool operator <=(const Key &x, const Key &y);
bool operator !=(const Key &x, const Key &y);
ostream& operator <<(ostream &stream, const Key &k);




