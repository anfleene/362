/*
*Name: Andrew Fleener
*Date: 10/21/09
*Description: This class is a binary tree structure that contains traversal insertion and removal methods for that tre
*this is a template class so any form of data can be used on this tree
*/


#include "Binary_node.h"

#ifndef BINARY_TREE_H
#define BINARY_TREE_H
//Binary_tree class interface
template <class Entry>
class Binary_tree {
public:
   Binary_tree();  //constructor
   //Post: An empty binary tree has been created.

   bool empty() const;
   //Post: A result of true is returned if the binary tree is empty.
   //Otherwise, false is returned.

   void preorder(void (*visit)(Entry &));
   //Post: The tree has been traversed in preorder sequence.
   //Uses: The function recursive_preorder

   void inorder(void (*visit)(Entry &));
   //Post: The tree has been traversed in inorder sequence.
   //Uses: The function recursive_inorder

   void postorder(void (*visit)(Entry &));
   //Post: The tree has been traversed in postorder sequence.
   //Uses: The function recursive_postorder

   void level_order(void (*visit) (Entry &));
   //Post: The tree has been traversed in level order sequence.
   //Uses: STL queue class

   int size() const;
   //Post: Returns the number of nodes in the tree
   //Uses: The function recursive_size

   void clear();
   //Post: All nodes of tree have been deleted, root set to NULL
   //Uses:  The function recursive_clear

   int height() const;
   //Post: Returns the height of the tree,
	 //where empty tree has height 0, one-node
	 //tree has height 1, etc.
   //Uses: The function recursive_height

   void insert(const Entry &);
   //Pre:  Data of type Entry has been passed for insertion -
   //note that the prototype need not include parameter names,
   //only data types
   //Post: Parameter has been inserted into the shortest
   //subtree or into the left subtree if equal height 
   //Uses: The function recursive_insert

   Binary_tree (const Binary_tree<Entry> &original);
   //copy constructor
   //Post: creates a deep copy of tree original 
   //Uses:  The function recursive_copy

   Binary_tree & operator =(const Binary_tree<Entry> &original);
   // overloaded assignment operator
   //Post: The calling tree is reset as a deep copy of tree pointed to by original
   //Uses:  The function recursive_copy

   ~Binary_tree();   //destructor
   //Single member variable 
protected:

   //Auxiliary function prototypes - MORE NEED TO BE ADDED
   void recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));


   void recursive_inorder(Binary_node<Entry> *sub_root,	void (*visit)(Entry &));

   void recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));

   void recursive_level_order(queue<Entry>*, Binary_node<Entry> *sub_root, int level);

   Binary_node<Entry>* recursive_copy(Binary_node<Entry>* sub_root);
   //Pre: sub_root is NULL or pointernts to a subtree of the Binary_tree
   //Post: returns a pointer to a deep copy of tree pointed to by sub_root 

	int recursive_size(Binary_node<Entry> *sub_root) const;

	int recursive_height(Binary_node<Entry> * const &sub_root) const;
	
	void recursive_insert(Binary_node<Entry> *&sub_root, const Entry &);
	
	void recursive_clear(Binary_node<Entry> *sub_root);
   Binary_node<Entry> *root;

};
#endif

//default constructor
template <class Entry>
Binary_tree<Entry>::Binary_tree(){
	this->root = NULL;
}

//true if size = 0
template <class Entry>
bool Binary_tree<Entry>::empty() const{
	return (this->size() != 0);
}

//calls recursive size on root and then adds one for the root node
//if root is null returns 0
template <class Entry>
int Binary_tree<Entry>::size() const{
	if(sub_root == NULL)
		return 0;
	int s =	this->recursive_size(this->root);
	return s + 1;
}

//recursively calls to find the size of the tree
template <class Entry>
int Binary_tree<Entry>::recursive_size(Binary_node<Entry> *sub_root) const{
	if(sub_root == NULL)
		return 0;
		
	int s = 0;
	if(sub_root->left != NULL){
		s += this->recursive_size(sub_root->left) + 1;
	}
	if(sub_root->right != NULL){
		s += this->recursive_size(sub_root->right) + 1;
	}
	return s;
}

//preforms visit in preorder on the tree
template <class Entry>
void Binary_tree<Entry>::preorder(void (*visit)(Entry &)){
	recursive_preorder(this->root, visit);
}

//preforms a recursive preorder traversal with visit
template <class Entry>
void Binary_tree<Entry>::recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)){
	if(sub_root != NULL){
		visit(sub_root->data);
		recursive_preorder(sub_root->left, visit);		
		recursive_preorder(sub_root->right, visit);
	}
}

//preforms visit in order on the tree
template <class Entry>
void Binary_tree<Entry>::inorder(void (*visit)(Entry &)){
	recursive_inorder(this->root, visit);	
}

//preforms a recursive inorder traversal with visit
template <class Entry>
void Binary_tree<Entry>::recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)){
	if(sub_root != NULL){
		recursive_preorder(sub_root->left, visit);		
		visit(sub_root->data);
		recursive_preorder(sub_root->right, visit);
	}
}

//preforms visit in postorder on the tree
template <class Entry>
void Binary_tree<Entry>::postorder(void (*visit)(Entry &)){
	recursive_postorder(this->root, visit);	
}

//preforms a recursive postorder traversal with visit
template <class Entry>
void Binary_tree<Entry>::recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)){
	if(sub_root != NULL){
		recursive_preorder(sub_root->left, visit);		
		recursive_preorder(sub_root->right, visit);
		visit(sub_root->data);		
	}
}

//preforms visit in level order on the tree
template <class Entry>
void Binary_tree<Entry>::level_order(void (*visit) (Entry &)){
	queue<Entry>* que = new queue<Entry>();
	if(this->root != NULL){
		for(int i=this->height(); i > 0; i--){
			recursive_level_order(que, this->root, i);
		}
		while(!que->empty()){
			visit (que->front());
			que->pop();
		}
	}
}

//preforms a recursive level order traversal with visit
template <class Entry>
void Binary_tree<Entry>::recursive_level_order(queue<Entry> *q, Binary_node<Entry> *sub_root, int level){
	if(sub_root == NULL){
		return;
	}
	if(level == 1){
		q->push(sub_root->data);
	}else{
		level--;
		recursive_level_order(q, sub_root->left, level);
		recursive_level_order(q, sub_root->right, level);
	}
}

//emptys the tree
template <class Entry>
void Binary_tree<Entry>::clear(){
	if(this->root != NULL)
		recursive_clear(this->root);	
}

//recursivly calls to delete each node
template <class Entry>
void Binary_tree<Entry>::recursive_clear(Binary_node<Entry> *sub_root){
	if(sub_root->left != NULL)
		recursive_clear(sub_root->left);
	if(sub_root->right != NULL)
		recursive_clear(this->root->right);
	delete sub_root;
}

//returns the height of the tree
template <class Entry>
int Binary_tree<Entry>::height() const{
	return recursive_height(this->root);
}

//recursivly finds the tallest hight of the right and left nodes
template <class Entry>
int Binary_tree<Entry>::recursive_height(Binary_node<Entry> * const &sub_root) const{
	if(sub_root == NULL)
		return 0;	
	int left = recursive_height(sub_root->left);
	int right = recursive_height(sub_root->right);
	int h;
	if (left > right){
		h = left;
	}else{
		h = right;
	}
	return h +1;
}

//insert an entry into the list
template <class Entry>
void Binary_tree<Entry>::insert(const Entry &e){
	this->recursive_insert(this->root, e);
}

//recursivly searches for the best place to insert the node
template <class Entry>
void Binary_tree<Entry>::recursive_insert(Binary_node<Entry> *&sub_root, const Entry &e){
	//root is NULL
	if(sub_root == NULL){
		sub_root = new Binary_node<Entry>(e);
	}else{
		int left = recursive_height(sub_root->left);
		int right = recursive_height(sub_root->right);
		//tree is balanced
		if(left <= right){
			if(sub_root->left == NULL){
				sub_root->left = new Binary_node<Entry>(e);
			}else{
				recursive_insert(sub_root->left, e);
			}
			
		}else{
			if(sub_root->right == NULL){
				sub_root->right = new Binary_node<Entry>(e);
			}else{
				recursive_insert(sub_root->right, e);
			}
		}
	}
}

//preforms a deep copy of the tree, traverses the tree copying each node it comes across
template <class Entry>
Binary_node<Entry>* Binary_tree<Entry>::recursive_copy(Binary_node<Entry>* sub_root){
	if (sub_root == NULL){
		return NULL;
	}else{
		Binary_node<Entry>* bn = new Binary_node<Entry>(sub_root->data);
		bn->left = recursive_copy(sub_root->left);
		bn->right = recursive_copy(sub_root->right);
		return bn;
	}
}

//preforms a deep copy with copy constructor
template <class Entry>
Binary_tree<Entry>::Binary_tree (const Binary_tree<Entry> &original){
	this->root = recursive_copy(original.root);
}

//eql operator preforms a deep copy 
template <class Entry>
Binary_tree<Entry>& Binary_tree<Entry>::operator =(const Binary_tree<Entry> &original){
	Binary_tree<Entry> bt(original);
	return bt;
}

//destructor calls clear to delete every node in the tree
template <class Entry>
Binary_tree<Entry>::~Binary_tree(){
	this->clear();
}
