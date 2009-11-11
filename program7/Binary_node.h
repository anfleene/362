/*
*Name: Andrew Fleener
*Date: 10/21/09
*Description: This is a binary node struct that contains the data member and pointers to the left and right children of this node
*/

#include "key.h"
#ifndef BINARY_NODE_H
#define BINARY_NODE_H

enum Balance_factor { left_higher, equal_height, right_higher };

//Binary_node struct interface
template <class Entry>
struct Binary_node {
//data members:

//Note that the default access in a
//struct is public, so these member
//variables are public.  However,
//only private or protected member 
//variables of trees will point to nodes.

   Entry data;
   Binary_node<Entry> *left;
   Binary_node<Entry> *right;

//constructors:
   Binary_node();
   Binary_node(const Entry &x);
   virtual ~Binary_node();

//virtual methods:
	virtual void set_balance(Balance_factor b);
	virtual Balance_factor get_balance() const;

};

#endif

//destry the node
template <class Entry>
Binary_node<Entry>::~Binary_node(){
	this->data = NULL;
	this->left = NULL;
	this->right = NULL;
}

//contruct a new node
template <class Entry>
Binary_node<Entry>::Binary_node(const Entry &x){
		this->data = x;
		this->left = NULL;
		this->right = NULL;
}

template <class Entry>
void Binary_node<Entry>::set_balance(Balance_factor b)
{//virtual unused
}

template <class Entry>
Balance_factor Binary_node<Entry>::get_balance() const
{//always return equal to keep things happy
   return equal_height;
}

//used to print a node
template <class Entry>
ostream& operator <<(ostream &stream, const Binary_node<Entry> &x){
	stream << x.data << endl;
	return stream;
}