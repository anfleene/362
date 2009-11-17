#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "utility.h"

template <class T>
struct HashList{
	int value;
	list<T>* h_list;
	
	HashList(){
		this->value = -1;
		this->h_list = NULL;
	};
	HashList(int i){
		this->value = i; 
		this->h_list = NULL;
	};

};
#endif