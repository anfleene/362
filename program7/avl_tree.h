#include "search_tree.h"

#ifndef AVL_TREE_H
#define AVL_TREE_H

template <class Record>
class AVL_tree: public Search_tree<Record> {
public:
	AVL_tree();
   Error_code insert(const Record &new_data);
   Error_code remove(const Record &old_data);
 private: //  Add auxiliary function prototypes here.
	Error_code avl_insert(Binary_node<Record> *&, const Record &, bool &);
	Error_code avl_remove(Binary_node<Record> *&, const Record &, bool &);
	void rotate_left(Binary_node<Record> *&);
	void rotate_right(Binary_node<Record> *&);
	void right_balance(Binary_node<Record> *&);
	void left_balance(Binary_node<Record> *&);
};
#endif

template <class Record>
AVL_tree<Record>::AVL_tree():Search_tree<Record>(){};

template <class Record>
Error_code AVL_tree<Record>::insert(const Record &new_data)
/*
Post: If the key of new_data is already in the AVL_tree, a code
      of duplicate_error is returned.
      Otherwise, a code of success is returned and the Record new_data
      is inserted into the tree in such a way that the properties of
      an AVL tree are preserved.
Uses: avl_insert.
*/
{
   bool taller;
   return avl_insert(this->root, new_data, taller);
}

template <class Record>
Error_code AVL_tree<Record>::avl_insert(Binary_node<Record> *&sub_root,
           const Record &new_data, bool &taller)
/*
Pre:  sub_root is either NULL or points to a subtree of the AVL_tree
Post: If the key of new_data is already in the subtree, a
      code of duplicate_error is returned.
      Otherwise, a code of success is returned and the Record new_data
      is inserted into the subtree in such a way that the
      properties of an AVL tree have been preserved.
      If the subtree is increased in height, the parameter taller is set to
      true; otherwise it is set to false.
Uses: Methods of struct AVL_node; functions avl_insert
      recursively, left_balance, and right_balance.
*/
{
   Error_code result = success;
   if (sub_root == NULL) {
      sub_root = new AVL_node<Record>(new_data);
      taller = true;
   }
   else if (new_data == sub_root->data) {
      result = duplicate_error;
      taller = false;
   }
   else if (new_data < sub_root->data) {         //  Insert in left subtree.
      result = avl_insert(sub_root->left, new_data, taller);
      if (taller == true)
         switch (sub_root->get_balance()) {//  Change balance factors.
         case left_higher:
            left_balance(sub_root);
            taller = false;        //  Rebalancing always shortens the tree.
            break;
         case equal_height:
            sub_root->set_balance(left_higher);
            break;
         case right_higher:
            sub_root->set_balance(equal_height);
            taller = false;
            break;
         }
   }
   else {                                       //  Insert in right subtree.
      result = avl_insert(sub_root->right, new_data, taller);
      if (taller == true)
         switch (sub_root->get_balance()) {
         case left_higher:
            sub_root->set_balance(equal_height);
            taller = false;
            break;
         case equal_height:
            sub_root->set_balance(right_higher);
            break;
         case right_higher:
            right_balance(sub_root);
            taller = false;        //  Rebalancing always shortens the tree.
            break;
         }
   }
   return result;
}

template <class Record>
Error_code AVL_tree<Record>::remove(const Record &remove_data)
/*
Post: If the key of new_data is already in the AVL_tree, a code
      of duplicate_error is returned.
      Otherwise, a code of success is returned and the Record new_data
      is inserted into the tree in such a way that the properties of
      an AVL tree are preserved.
Uses: avl_insert.
*/
{
   bool shorter;
   return avl_remove(this->root, remove_data, shorter);
}


template <class Record>
Error_code AVL_tree<Record>::avl_remove(Binary_node<Record> *&sub_root,
           const Record &remove_data, bool &shorter)
/*
Pre:  sub_root is either NULL or points to a subtree of the AVL_tree
Post: If the key of new_data is already in the subtree, a
      code of duplicate_error is returned.
      Otherwise, a code of success is returned and the Record new_data
      is inserted into the subtree in such a way that the
      properties of an AVL tree have been preserved.
      If the subtree is increased in height, the parameter taller is set to
      true; otherwise it is set to false.
Uses: Methods of struct AVL_node; functions avl_insert
      recursively, left_balance, and right_balance.
*/
{
	Error_code result = not_present;
   if (sub_root == NULL || sub_root->data == remove_data){
      result = remove_root(sub_root);
			shorter = true;
   }else if (remove_data < sub_root->data){
			result = avl_remove(sub_root->left, remove_data, shorter);
			if(result == success){
      	switch (sub_root->get_balance()) {//  Change balance factors.
					case right_higher:
						sub_root->set_balance(equal_height);
						shorter = false;
						break;
					case equal_height:
						sub_root->set_balance(left_higher);
						break;
					case left_higher:
						right_balance(sub_root);
						shorter = false;
						break;
        }
			}
		}else{
			result = avl_remove(sub_root->right, remove_data, shorter);
			if( result == success){
	     switch (sub_root->get_balance()) {//  Change balance factors.
	     case left_higher:
				sub_root->set_balance(equal_height);
        shorter = false;        //  Rebalancing always shortens the tree.
        break;
	     case equal_height:
        sub_root->set_balance(right_higher);
        break;
	     case right_higher:
        left_balance(sub_root);
        shorter = false;
        break;
	     }
			}
		}
		return result;
}
			
template <class Record>
void AVL_tree<Record>::rotate_left(Binary_node<Record> *&sub_root)
/*
Pre:  sub_root points to a subtree of the AVL_tree.
      This subtree has a nonempty right subtree.
Post: sub_root is reset to point to its former right child, and the former
      sub_root node is the left child of the new sub_root node.
*/
{
   if (sub_root == NULL || sub_root->right == NULL)     //  impossible cases
      cout << "WARNING: program error detected in rotate_left" << endl;
   else {
      Binary_node<Record> *right_tree = sub_root->right;
      sub_root->right = right_tree->left;
      right_tree->left = sub_root;
      sub_root = right_tree;
   }
}

template <class Record>
void AVL_tree<Record>::rotate_right(Binary_node<Record> *&sub_root)
/*
Pre:  sub_root points to a subtree of the AVL_tree.
      This subtree has a nonempty right subtree.
Post: sub_root is reset to point to its former left child, and the former
      sub_root node is the right child of the new sub_root node.
*/
{
   if (sub_root == NULL || sub_root->left == NULL)     //  impossible cases
      cout << "WARNING: program error detected in rotate_left" << endl;
   else {
      Binary_node<Record> *left_tree = sub_root->left;
      sub_root->left = left_tree->right;
      left_tree->right = sub_root;
      sub_root = left_tree;
   }
}

template <class Record>
void AVL_tree<Record>::right_balance(Binary_node<Record> *&sub_root)
/*
Pre:  sub_root points to a subtree of an AVL_tree that
      is doubly unbalanced on the right.
Post: The AVL properties have been restored to the subtree.
Uses: Methods of struct AVL_node;
      functions  rotate_right and rotate_left.
*/
{
   Binary_node<Record> *&right_tree = sub_root->right;
   switch (right_tree->get_balance()) {
   case right_higher:                            //  single rotation left
      sub_root->set_balance(equal_height);
      right_tree->set_balance(equal_height);
      rotate_left(sub_root);
      break;
   case equal_height:  //  impossible case
      cout << "WARNING: program error detected in right_balance" << endl;
   case left_higher:                            //  double rotation left
      Binary_node<Record> *sub_tree = right_tree->left;
      switch (sub_tree->get_balance()) {
      case equal_height:
         sub_root->set_balance(equal_height);
         right_tree->set_balance(equal_height);
         break;
      case left_higher:
         sub_root->set_balance(equal_height);
         right_tree->set_balance(right_higher);
         break;
      case right_higher:
         sub_root->set_balance(left_higher);
         right_tree->set_balance(equal_height);
         break;
      }
      sub_tree->set_balance(equal_height);
      rotate_right(right_tree);
      rotate_left(sub_root);
      break;
   }
}


template <class Record>
void AVL_tree<Record>::left_balance(Binary_node<Record> *&sub_root)
/*
Pre:  sub_root points to a subtree of an AVL_tree that
      is doubly unbalanced on the left.
Post: The AVL properties have been restored to the subtree.
Uses: Methods of struct AVL_node;
      functions  rotate_right and rotate_left.
*/
{
   Binary_node<Record> *&left_tree = sub_root->left;
   switch (left_tree->get_balance()) {
   case left_higher:                            //  single rotation left
      sub_root->set_balance(equal_height);
      left_tree->set_balance(equal_height);
      rotate_right(sub_root);
      break;
   case equal_height:  //  impossible case
      cout << "WARNING: program error detected in left_balance" << endl;
   case right_higher:                            //  double rotation left
      Binary_node<Record> *sub_tree = left_tree->right;
      switch (sub_tree->get_balance()) {
      case equal_height:
         sub_root->set_balance(equal_height);
         left_tree->set_balance(equal_height);
         break;
      case right_higher:
         sub_root->set_balance(equal_height);
         left_tree->set_balance(left_higher);
         break;
      case left_higher:
         sub_root->set_balance(right_higher);
         left_tree->set_balance(equal_height);
         break;
      }
      sub_tree->set_balance(equal_height);
      rotate_left(left_tree);
      rotate_right(sub_root);
      break;
   }
}
