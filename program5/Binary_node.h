/*
*Name: Andrew Fleener
*Date: 10/21/09
*Description: This is a binary node struct that contains the data member and pointers to the left and right children of this node
*/


#include "utility.h"
#ifndef BINARY_NODE_H
#define BINARY_NODE_H
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
   ~Binary_node();
   
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

//used to print a node
template <class Entry>
ostream& operator <<(ostream &stream, const Binary_node<Entry> &x){
	stream << x.data << endl;
	return stream;
}