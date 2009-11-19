#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "key.h"
//struct that holds the hash key and the list of elements for that key
template <class Entry>
struct HashList{
	int value;
	list<Entry>* h_list;
	
	HashList(){
		this->value = -1;
		this->h_list = new list<Entry>();
	};
	HashList(int i){
		this->value = i; 
		this->h_list = new list<Entry>();
	};
	
	~HashList(){ delete this->h_list; };
	//is the element in this list
	bool include(Entry &el){
		bool inc = false;
		typename list<Entry>::iterator current;
		for(current=this->h_list->begin(); current != this->h_list->end(); current++){
			if(*current == el){
				inc = true;
				break;
			}
		}		
		return inc;
	}
	//how big is the list
	int size(){ return this->h_list->size();};

};

template <class T>
class HashTable{
public:
	//used to mod against hash key
	static int HASH_SIZE;
	//construct hashtable
	HashTable(T &el){
		this->the_table = new list<HashList<T>* > ();
		insert(el);
	};
	
	HashTable(){
		this->the_table = new list<HashList<T>* > ();
	};
	//destruct hashtable
	~HashTable(){
		delete this->the_table;
	};
	//insert into the hashtable
	Error_code insert(T&);
	//output the hashtable
	friend ostream& operator <<(ostream &stream, const HashTable<T> &ht){
		typename list<HashList<T>* >::iterator it;
		for(it=ht.the_table->begin(); it != ht.the_table->end(); it++){
			stream << *(*it) << endl;
		}
		return stream;
	}
	//search the hashtable
	Error_code search(T&);
	
	int size(){
		typename list<HashList<T>* >::iterator it;
		int size = 0;
		for(it=this->the_table->begin(); it != this->the_table->end(); it++){
			size += (*it)->size();
		}
		return size;
	};
	
private:
	//the list of keys
	list<HashList<T>* >* the_table;
	//hash the element value
	int hashIt(T&);
	//convert a string to an int
	int stringToInt(string&);
	//convert an int to a string
	string intToString(int);

};
#endif

template <class T>
//set the default table size
int HashTable<T>::HASH_SIZE  = 97;

template <class T>
Error_code HashTable<T>::insert(T &el){
	//generate the hash key
	int hv = hashIt(el);
	typename list<HashList<T>* >::iterator it;
	Error_code inserted = success;
	Error_code found = not_present;
	//search for key
	for(it=this->the_table->begin(); it != this->the_table->end(); it++){
		found = ((*it)->value != hv) ? not_present : success;
		if(found == success){
			//found
			if((*it)->include(el))
			//this is a dup dont insert it
				inserted = duplicate_error;
			else
			//insert it into this key's list
				(*it)->h_list->push_front(el);
			break;
		}	
	}
	if(found == not_present){
		//if not found create a new hash key
		HashList<T>* hl = new HashList<T>(hv);
		//insert the element into the new list
		hl->h_list->push_front(el);
		this->the_table->push_front(hl);
	}
	return inserted;
}

template <class T>
Error_code HashTable<T>::search(T &el){
	//get the hashkey value
	int hv = hashIt(el);
	typename list<HashList<T>* >::iterator it;
	Error_code found = not_present;
	for(it=this->the_table->begin(); it != this->the_table->end(); it++){
		if((*it)->value == hv){
			//found matching hash key
			if((*it)->include(el))
				//the el is in the list
				found = success;
			//break out of the loop the result was found
			break;
		}
	}
	return found;
}

//this func is unused
template <class T>
int HashTable<T>::hashIt(T &t){
	exit(1);
	return 0;
}

//generates a hash key for the Key class
template<>
int HashTable<Key>::hashIt(Key &k){
	int kv = k.the_key();
	//convert to string
	string key_str = this->intToString(kv);
	int padding = 4-key_str.length();
	for(int i=0; i < padding; i++){
		//pad string with leading 0's
		key_str.insert(0, "0");
	} 
	string hash_str = "";
	//rearange string
	hash_str.push_back(key_str[2]);
	hash_str.push_back(key_str[3]);
	hash_str.push_back(key_str[0]);
	hash_str.push_back(key_str[1]);
	//convert back to an int and mod it by the table size
	return (this->stringToInt(hash_str) % HASH_SIZE);	
}

template <class T>
string HashTable<T>::intToString(int i){
	char char_int [4];
	int n = sprintf (char_int, "%d",i);
	return string(char_int);
}

template <class T>
int HashTable<T>::stringToInt(string &s){
  int i;
 	sscanf (s.c_str(),"%d",&i);
  return i;
}

//overload for hashlist struct output
template <class T>
ostream& operator <<(ostream &stream, const HashList<T> &hl){
	stream << "Hash Key: " << hl.value << " Values: ";
	typename list<T>::iterator it;
	for(it=hl.h_list->begin(); it != hl.h_list->end(); it++){
		stream << " " << *it;
	}
	return stream;
}
