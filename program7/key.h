#ifndef KEY_H
#define KEY_H

#include "utility.h"
//header file for class Key.  Keys are
//just integers with overloaded comparison
//operators to count compares.

template <class T>
class Key
{
public:
	//static variable to count the number of
	//times a comparison is made against a Key object
	static double comparisons;
	
	Key (T);
	//constructor 
	//default is to set the integer value key to 0
	Key (){};
	
	~Key(){};

	T the_key() const;
	//accessor function - to inspect key value
		
private:
	T key;
};
#endif //KEY_H

//constructor
template <class T>
Key<T>::Key(T k){
	this->key = k;
}

//getter for the integer contained in Key
template <class T>
T Key<T>::the_key() const{
	return this->key;
}

//initialize comparisons to 0
template <class T>
double Key<T>::comparisons = 0;

//over load of the == operator
template <class T>
bool operator == (const Key<T> &x, const Key<T> &y){
	Key<T>::comparisons++;
	return (x.the_key() == y.the_key());
}

//over load of the > operator
template <class T>
bool operator > (const Key<T> &x, const Key<T> &y){
	Key<T>::comparisons++;	
	return (x.the_key() > y.the_key());	
}

//over load of the < operator
template <class T>
bool operator < (const Key<T> &x, const Key<T> &y){
	Key<T>::comparisons++;
	return (x.the_key() < y.the_key());
}

//over load of the >= operator
template <class T>
bool operator >= (const Key<T> &x, const Key<T> &y){
	Key<T>::comparisons++;
	return (x.the_key() >= y.the_key());
}

//over load of the <= operator
template <class T>
bool operator <= (const Key<T> &x, const Key<T> &y){
	Key<T>::comparisons++;
	return (x.the_key() <= y.the_key());
}

//over load of the != operator
template <class T>
bool operator != (const Key<T> &x, const Key<T> &y){
	Key<T>::comparisons++;
	return (x.the_key() != y.the_key());
}

template <class T>
//overload of the write operator to print a key
ostream& operator << (ostream &stream, const Key<T> &k){
	stream << k.the_key();
	return stream;
}