#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "key.h"
#include "hashList.h"

template <class T>
class HashTable{
public:
	
	HashTable(T &el){
		insert(el);
	};
	
	HashTable(){};
	
	~HashTable(){
		delete this->the_table;
	};
	
	void insert(T&);
	
	template<class Key>
	int hashIt(Key&);
	
private:
	list<HashList<T>* >* the_table;
	
};
#endif

template <class T>
void HashTable<T>::insert(T &el){
	int hv = hashIt(el);
	list<HashList<T>* >::iterator it;
	Error_code e;
	for(it=this->the_table.begin(); it != this->the_table.end(); it++){
		e = (it->value != hv) ? not_present : success;
		if(e == success)
			it->h_list->push_back(el);
			break;
	}
	if(e == not_present){
		HashList<T>* hl = new HashList<T>(hv);
		hl->h_list->push_back(el);
		this->the_table->push_back(hl);
	}
}

template<class Key>
int hashIt(Key &k){
	return 1;
}