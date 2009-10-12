/*
*Name: Andrew Fleener
*Date: 10/6/09
*Description: This is the implementation of the Key class it includes two member functions a constructor and a getter
* the other functions are operator overloads that are used in comparisons and for outputing the key
*/

#include "key.h"
//initialize comparisons
double Key::comparisons = 0;

//basic constructor defaults x to 0
Key::Key(int x){
	this->key = x;
}
//getter for the integer contained in Key
int Key::the_key() const{
	return this->key;
}
//operator over loads:
//adds one to comparison and compares the data member of two keys
bool operator ==(const Key &x, const Key &y){
	Key::comparisons++;
	return (x.the_key() == y.the_key());
}
bool operator > (const Key &x, const Key &y){
	Key::comparisons++;	
	return (x.the_key() > y.the_key());	
}
bool operator < (const Key &x, const Key &y){
	Key::comparisons++;
	return (x.the_key() < y.the_key());
}
bool operator >=(const Key &x, const Key &y){
	Key::comparisons++;
	return (x.the_key() >= y.the_key());
}
bool operator <=(const Key &x, const Key &y){
	Key::comparisons++;
	return (x.the_key() <= y.the_key());
}
bool operator !=(const Key &x, const Key &y){
	Key::comparisons++;
	return (x.the_key() != y.the_key());
}
//overload of the write operator to print a key
ostream& operator <<(ostream &stream, const Key &k){
	stream << k.the_key();
	return stream;
}