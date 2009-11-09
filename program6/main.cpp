/*
*Name: Andrew Fleener
*Date: 10/21/09
*Description: This is a client for the binary search tree class, it will allow a user to create a new int bst or char bst and preform
*operations on that tree, ie. search, remove, insert.
*/

#include "avl_tree.h"

//this is an entry print to be used on traversals
template <class Entry>
void print(Entry &e){
	cout << e << " ";
}

template <class Entry>
void tree_print(AVL_tree<Entry>* stree){
	vector<Entry> *v = stree->inorder();
	int level = 1;
	for(int i=0; i < v->size(); i++){
		if(i == 0){
			cout.width(23);
		}else if(i > 0 && i < 3){
			cout.width(14);
		}else if(i >= 3 && i < 7){
			cout.width(10);
		}else if(i >= 7 && i < 15){
			cout.width(4);
		}
		cout << v->at(i);
		if(i == 0 || i == 2 || i == 6 || i == 14)
			cout << endl;
	}
		

}

//displays the menu for the tree_loop
int tree_menu(){
	// •	insert one or several items into the tree, such items to be entered by the user at the keyboard
	cout << "1.insert one or several items into the tree" << endl;
	// •	do a tree traversal and write out the nodes as they are visited - user's choice of in-order, pre-order,  post-order, or level order
	cout << "2.do a tree traversal" << endl;
	// •	search the tree for a given item
	cout << "3.search the tree for a given item" << endl;
	// •	remove an item from the tree
	cout << "4.remove an item from the tree" << endl;
	// •	find the height of the tree
	cout << "5.find the height of the tree" << endl;
	// •	find the size of the tree
	cout << "6.find the size of the tree" << endl;
	//print the tree
	cout << "7.Print the tree structure" << endl;
	// •	quit this tree
	cout << "0.quit this tree" << endl;
	int choice = -1;
	cin >> choice;
	while(choice < 0 || choice > 7){
		cout << "Error: Invalid INPUT Try again" << endl;
		cin >> choice;
	}
	return choice;
}

//this is the outter loop's menu
int start_tree(){
	cout << "Would You like a 1:Character Tree or 2:Integer Tree (1/2, -1 to Quit)" << endl;;
	int choice = -1;
	while(!(cin >> choice)){
		cin.clear();
		cout << "Error: Invalid INPUT Try again" << endl;
		cin >> choice;
	}
	return choice;
}

//this loop does most of the work based on input preforms each options
template <class Entry>
void tree_loop(AVL_tree<Entry>* stree){
	int choice = tree_menu();
	while(choice != 0){
		cout << choice << endl;
		switch(choice){
			case 1:
				insert(stree);
				break;
			case 2:
				traversal(stree);
				break;
			case 3:
				search(stree);
				break;
			case 4:
				remove(stree);
				break;
			case 5:
				cout << "Height: " << stree->height() << endl;
				break;
			case 6:
				cout << "Size: " << stree->size() << endl;
				break;
			case 7:
				tree_print(stree);
				break;
			default:
				cout << "Error: Invalid INPUT" << endl;
				exit(1);
		}
		choice = tree_menu();
	}
}

//outter loop choices are for which type of tree and to exit the program
void loop(){
	int tree;
	do{
		tree = start_tree();
		if(tree == 1){
			AVL_tree<char>* stree = new AVL_tree<char>();
			tree_loop(stree);
		}else if(tree == 2){
			AVL_tree<int>* stree = new AVL_tree<int>();
			tree_loop(stree);
		}else{
			cout << "Bye Now" << endl;
			exit(1);
		}
	}while(true);
}

//traverse menu(displays the traversal choices)
int trav_menu(){
	cout << "Chose which way to print out the elements in the tree" << endl;
	cout << "1.In Order" << endl;
	cout << "2.Pre Order" << endl;
	cout << "3.Post Order" << endl;
	cout << "4.Level Order" << endl;
	int choice = -1;
	cin >> choice;
	while(choice < 0 || choice > 4){
		cout << "Error: Invalid INPUT Try again" << endl;
		cin >> choice;
	}
	return choice;
}

//traverse the tree by the inputed method
template <class Entry>
void traversal(AVL_tree<Entry>* stree){
	int choice = trav_menu();
	switch(choice){
		case 1:
			stree->inorder(print);
			break;
		case 2:
			stree->preorder(print);
			break;
		case 3:
		stree->postorder(print);
			break;
		case 4:
		stree->level_order(print);
			break;
		default:
			cout << "Error: Invalid INPUT" << endl;
			exit(1);
	}
	cout << endl;
}

//search the input term if it exisits display success or failure
template <class Entry>
void search(AVL_tree<Entry>* stree){
	Entry search;
	cout << "Enter A Search Term" << endl;
	while(!(cin >> search)){
		cin.clear();
		cout << "Error: Invalid INPUT Try again" << endl;
		cin >> search;
	}
	Error_code e = stree->tree_search(search);
	if(e == not_present){
		cout << "Search Term Was Not Found" << endl;
	}else{
		cout << "Search Term Was Found" << endl;
	}
}

//remove the input term if it exisits display success or failure
template <class Entry>
void remove(AVL_tree<Entry>* stree){
	Entry remove;
	cout << "Enter A Term to Remove" << endl;
	while(!(cin >> remove)){
		cin.clear();
		cout << "Error: Invalid INPUT Try again" << endl;
		cin >> remove;
	}
	Error_code e = stree->remove(remove);
	if(e == not_present){
		cout << "Removal Was Not Completed" << endl;
	}else{
		cout << "Removal Completed" << endl;
	}
}
//insert ints into a search tree
void insert(AVL_tree<int>* stree){
	cout << "Insert New Nodes(-1 to exit)" << endl;
	int e;
	Error_code error = success;
 	while(cin >> e && e != -1){
		e = stree->insert(e);
		if(error == duplicate_error){
			cout << "Failed to insert" << e << "it was already in the tree" << endl;
		}
	}
}
//insert a chars into search tree
void insert(AVL_tree<char>*& stree){
	cout << "Insert New Nodes(Q to exit)" << endl;
	char e;
	char exit = *"Q";
 	while(cin >> e && e != exit){
		stree->insert(e);
	}
}
int main ()
{
	loop();
return 0;
}