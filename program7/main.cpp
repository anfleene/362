#include "avl_tree.h"

//this is a simple print function to print a key
//only used for testing
template <class T>
void print(Key<T> &k){
	cout << k << " " << endl;
}

//build a vector<key<int>> from a file of ints
void loadVectorFromFile(string filename, vector<Key<int> > &vec)
{
	int size = 500;
	ifstream file;
	vec.resize(size);
	file.open( filename.c_str());
	if ( !file )
	{ 
		exit(1);
	}
	int el;
	for(int i=0; i < size; i++)
	{
		file >> el;
		Key<int> k(el);
		//add a new element at the current position
		vec.at(i) = k;
	}
}

//build an avl tree with 200 elements from a vector of key<int>s 
void buildAvlTree(vector<Key<int> > &vec, AVL_tree<Key<int> > &avl_tree){
	int size = 200;
	for(int i=0; i < size; i++){
		avl_tree.insert(vec.at(i));
	}
}

//build a bst with 200 elements form a vector of key<int>s
void buildSearchTree(vector<Key<int> > &vec, Search_tree<Key<int> > &s_tree){
	int size = 200;
	for(int i=0; i < size; i++){
		if(s_tree.tree_search(vec.at(i)) != success )
			s_tree.insert(vec.at(i));
	}
}

//seach every element in a given vector on a bst/avl tree
void search(vector<Key<int> > &vec, Search_tree<Key<int> > &search_tree){
	for(int i=0; i < vec.size(); i++){
		search_tree.tree_search(vec.at(i));
	}
}

//returns a int vector with 3 elements, the average number of comparisons for bst, average for avl tree, and the percentage of bst/avltree
vector<double> comparisons(vector<Key<int> > &vec){
	//build the avl tree
	AVL_tree<Key<int> > aTree;
	buildAvlTree(vec, aTree);
	//build the bst
	Search_tree<Key<int> > sTree;
	buildSearchTree(vec, sTree);
	//reset comparisions
	Key<int>::comparisons = 0;
	//search the avl tree
	search(vec, aTree);	
	double avl_comps = double (Key<int>::comparisons);
	//reset comparisons
	Key<int>::comparisons = 0;
	//search bst
	search(vec, sTree);
	double bst_comps = double (Key<int>::comparisons);	
	double num_comps = double (vec.size());
	vector<double> comps;
	comps.resize(3);
	//calc the average bst comps
	comps.at(0) = (bst_comps/num_comps);
	//calc the average avl comps
	comps.at(1) = (avl_comps/num_comps);
	//calc the % of bst/avl
	comps.at(2) = (comps.at(0)/ comps.at(1)) * 100;
	return comps;
}

int main ()
{
	//load first file
	vector<Key<int> > vec_a;
	loadVectorFromFile("Lab7a.txt", vec_a);

	//load second file
	vector<Key<int> > vec_b;
	loadVectorFromFile("Lab7b.txt", vec_b);
	
	//load third file
	vector<Key<int> > vec_c;
	loadVectorFromFile("Lab7c.txt", vec_c);
	
	//calc the comparisions for the three files
	vector<double> comp_a = comparisons(vec_a);
	vector<double> comp_b = comparisons(vec_b);
	vector<double> comp_c = comparisons(vec_c);
	
	//prep cout
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	//output table data
	cout << "               " << "Average search compares" << setw(25) << "Average search compares" << setw(20) << "Col. 1 as %" << endl;
	cout << setw(30) << "average tree" << setw(25) << "AVL tree" << setw(27) << "of col. 2" << endl;		
	cout << "Trial 1" << setw(20) << comp_a.at(0) << setw(27) << comp_a.at(1) << setw(26) << comp_a.at(2) << "%" << endl;		
	cout << "Trial 2" << setw(20) << comp_b.at(0) << setw(27) << comp_b.at(1) << setw(26) << comp_b.at(2) << "%" << endl;		
	cout << "Trial 3" << setw(20) << comp_c.at(0) << setw(27) << comp_c.at(1) << setw(26) << comp_c.at(2) << "%" << endl;			

return 0;
}