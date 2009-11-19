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
	
	Key(){};
	
	Key(int x){
		this->key = x;
	};
	//constructor 
	//default is to set the integer value key to 0

	int the_key() const{ return this->key; };
	//accessor function - to inspect key value
	
	friend bool operator ==(const Key &x, const Key &y){
		Key::comparisons++;
		return (x.the_key() == y.the_key());
	}
	friend bool operator > (const Key &x, const Key &y){
		Key::comparisons++;	
		return (x.the_key() > y.the_key());	
	}
	friend bool operator < (const Key &x, const Key &y){
		Key::comparisons++;
		return (x.the_key() < y.the_key());
	}
	friend bool operator >=(const Key &x, const Key &y){
		Key::comparisons++;
		return (x.the_key() >= y.the_key());
	}
	friend bool operator <=(const Key &x, const Key &y){
		Key::comparisons++;
		return (x.the_key() <= y.the_key());
	}
	friend bool operator !=(const Key &x, const Key &y){
		Key::comparisons++;
		return (x.the_key() != y.the_key());
	}
	//overload of the write operator to print a key
	friend ostream& operator <<(ostream &stream, const Key &k){
		stream << k.the_key();
		return stream;
	}

private:
	int key;
};
#endif //KEY_H
//overload relational operators for type Key
//each also increments the comparisons counter variable

double Key::comparisons = 0;